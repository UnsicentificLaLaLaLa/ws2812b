
#include "board_init.h"
#include "clock_init.h"
#include "pin_init.h"

/*
 * Macros.
 */

/*
 * Variables.
 */

static volatile uint32_t systime = 0;

/*
* Declerations.
*/

/*
* Functions.
*/

void BOARD_Init(void)
{
    BOARD_InitBootClocks();
    BOARD_InitPins();
    SysTick_Config(CLOCK_SYS_FREQ / 1000);
}

uint32_t BOARD_GetRunTimeMs(void)
{
    return systime;
}

void SysTick_Handler(void)
{
    systime++;
}

/* EOF. */
