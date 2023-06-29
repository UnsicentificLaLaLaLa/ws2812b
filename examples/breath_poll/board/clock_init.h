
#ifndef __CLOCK_INIT_H__
#define __CLOCK_INIT_H__

#define CLOCK_SYS_FREQ         72000000u
#define CLOCK_SYSTICK_FREQ     (CLOCK_SYS_FREQ/8u)
#define CLOCK_AHB_FREQ         72000000u
#define CLOCK_APB1_FREQ        36000000u
#define CLOCK_APB2_FREQ        36000000u

void BOARD_InitBootClocks(void);

#endif /* __CLOCK_INIT_H__ */

