#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"



void timer1A_delaymSec( int ttime);


int main(void)
{

        SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);

        GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
        GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

        GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);


        GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
        GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_INT_PIN_4, GPIO_RISING_EDGE);


        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);

        IntEnable(INT_GPIOF);

      //  TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);


        while(1)
        {

        }
}


void PortFPin4IntHandler(void)
{
    // Clear the GPIO interrupt
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
    // Read the current state of the GPIO pin and
    // write back the opposite state
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);

    timer1A_delaymSec( 1500 );

    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);

}


void timer1A_delaymSec( int ttime)
{

    int i;

    SYSCTL_RCGCTIMER_R |=2;
    TIMER1_CTL_R = 0;
    TIMER1_CFG_R = 0x04;
    TIMER1_TAMR_R = 0x02;
    TIMER1_TAILR_R = 640 - 1;
    TIMER1_TAPR_R = 275 - 1;
    TIMER1_ICR_R = 0x1;
    TIMER1_CTL_R |= 0x01;

    for(i=0; i < ttime; i++)
    {
        while ((TIMER1_RIS_R & 0x1) == 0)
            ;
        TIMER1_ICR_R = 0x1;

    }

}
