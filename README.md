# WS2812B

[TOC]

## 简介

一款支持 poll 和 dma 两种模式控制 ws2812b 的组件， poll 模式能够在资源极少的微控制器中使用，降低 ws2812b 控制成本，dma 模式优化了传输方法，每12Byte 空间就能存储一个 LED 的控制数据，而非 24Byte，使 dma 模式所需的 buffer 大小减少一半，且降低了 spi 的时钟速度，让控灯更方便。



## 工作原理

为了刷 ws2812b 的灯效，则需要足够大的 ram 来暂存 ws2812b 的数据，这对资源有限的微控制器而言是及其困难的，为了解决 ws2812b 需要大 ram 的问题，该组件使用实时解算的方法来解决 ram 问题。



该组件在发送下一颗 WS2812B 的颜色数据之前，会先调用注册的 fx() 函数，获取下一颗 ws2812b 的颜色值，然后通过查表法解算为 WS2812B 能够识别到颜色数据，再进行发送。

由于发送的数据是实时解算出来的，因此不需要使用额外的 ram 空间暂存颜色数据，省下了 ram 空间。

但这种方法仍然具有一定的局限性，在以下场景会影响ws2812b 的通信时序，因此不宜使用：

- 执行 fx() 函数需要花费较多的时间
- 执行 ws2812b_flush_polling() 函数期间，出现中断或其它打断执行的操作



该组件仍然提供了 dma 的方法控制 led 灯效，相比较于传统的一字节spi数据模拟 ws2812b 的一比特数据，该组件采用一字节数据模拟 ws2812b 的两比特数据，节省了一半的存储空间，也减少了 spi 接口的性能指标，执行更加高效。



## 使用方法

### polling 用法

声明接口：

~~~c
ws2812b_if_t ws2812b_if = 
{
    .led_num = led_num, /* the number of leds. */
    .hw_init = hw_init, /* init spi hardware, 4MHz, MSB, no dma. */
    .hw_send = hw_send, /* send a 8bit data. */
};
~~~



初始化：

~~~c
ws2812b_t ws2812b;

ws2812b_init(&ws2812b, &ws2812b_if);
ws2812b_set_fx(&ws2812b, ws2812b_fx, &param);
~~~



执行：

~~~c
ws2812b_poll(&ws2812b);
~~~



### dma 用法

声明接口：

~~~c
ws2812b_if_t ws2812b_if = 
{
    .led_num = led_num, /* the number of leds. */
    .dma_buf = dma_buf, /* the dma buffer, size = 12 * led_num Byte. */
    .hw_init = hw_init, /* init spi hardware, 4MHz, MSB, with dma. */
    .hw_dma  = hw_dma,  /* sart dma xfer, send dma_buf data by spi. */
};
~~~



初始化：

~~~c
ws2812b_t ws2812b;

ws2812b_init(&ws2812b, &ws2812b_if);
ws2812b_set_fx(&ws2812b, ws2812b_fx, &param);
~~~



执行：

~~~c
ws2812b_dma(&ws2812b);
~~~



## 注意事项

- poll 和 dma 不提供判断数据是否发完的接口，在第二次调用 ws2812b_flush_dma() 之前，需保证上一次 dma 传输已经完成
- 该组件不提供 ws2812b 的复位功能，因此需保证下一次传输灯效数据前，上一次的传输已经完成且超过 50us
- 如果希望 dma 能够提供复位 ws2812b 的操作，则可以让 dma 发送有效数据前，提前发送25字节以上的 0x00，由此可以实现 50us 以上的低电平复位信号
- 如果希望dma能够提供发送完成的判断，可在适配层实现判断函数，上层直接调用适配层的判断函数即可。
- 为什么不实现复位信号和dma发送完成判断接口？一般来说，两次改变 ws2812b 的时间间隔足够完成ws2812b 的复位和传输，增加复位信号浪费ram空间和执行时间，因此不再添加复位信号的功能，且不再判断是否传输完成。



## 样例介绍

以下样例基于 MM32F0160 微控制器实现，使用片内时钟，使用 PB5 引脚作为 ws2812b 的信号引脚：

- breath_poll：呼吸灯的 poll 模式样例，ws2812b 按照红绿蓝顺序排列，逐渐点亮后再逐渐熄灭，由此往复。
- rand_dma：用 dma 模式让每一颗 LED 随机亮出不同颜色
