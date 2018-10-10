#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"


#define PWM_FREQUENCY 55

int main(void)
{
    volatile uint32_t ui32Load;
    volatile uint32_t ui32PWMClock;
    volatile uint32_t ui8AdjustRed;   // Adjust variable for Red LED
    volatile uint32_t ui8AdjustBlue;  // Adjust variable for Blue LED
    volatile uint32_t ui8AdjustGreen; // Adjust variable for Blue LED

    // Default 10% duty cycle
    ui8AdjustRed   = 100;
    ui8AdjustBlue  = 100;
    ui8AdjustGreen = 100;

    ROM_SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Setting pins PF1, PF2 and PF3 to PWM
    ROM_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    // Configuring pins for module 1 pwm outputs 5,6 and 7
    ROM_GPIOPinConfigure(GPIO_PF1_M1PWM5);
    ROM_GPIOPinConfigure(GPIO_PF2_M1PWM6);
    ROM_GPIOPinConfigure(GPIO_PF3_M1PWM7);

    // For switch 1 unlock
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
    ROM_GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
    ROM_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    // setting pwm load for duty cycle configuration
    ui32PWMClock = SysCtlClockGet() / 64;
    ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;

    // Configuring PWM generator 2 for pwm5 and generator 3 for pwm6 and pwm7
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2 , PWM_GEN_MODE_DOWN);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3 , PWM_GEN_MODE_DOWN);

    // setting period for generators 2 and 3 on PWM module 1
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2 , ui32Load);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3 , ui32Load);

    // Setting default duty cycles
    ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, ui8AdjustRed * ui32Load / 1000);
    ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, ui8AdjustBlue * ui32Load / 1000);
    ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, ui8AdjustGreen * ui32Load / 1000);


    // Enabling PWM outputs 5,6 and 7
    ROM_PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, true);

    // Enables Generator 2 which connects to pwm5
    ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_2);
    // Enables Generator 3 which connects to pwm6 and pwm7
    ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_3);


    while(1)
    {
        // Nested loops driving all 3 LEDs with 5% duty cycle increments
        for(ui8AdjustRed=100; ui8AdjustRed<900; ui8AdjustRed++)
        {
            ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, ui8AdjustRed * ui32Load / 1000);
            ROM_SysCtlDelay(100000);

              for(ui8AdjustBlue=100; ui8AdjustBlue<=10; ui8AdjustBlue++)
              {
                  ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, ui8AdjustBlue * ui32Load / 1000);
                  ROM_SysCtlDelay(100000);

                    for(ui8AdjustGreen=100; ui8AdjustGreen<=900; ui8AdjustGreen++)
                    {
                            ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, ui8AdjustGreen * ui32Load / 1000);
                            ROM_SysCtlDelay(100000);
                            ui8AdjustGreen =  (ui8AdjustGreen+50)-1;
                    }
                    ui8AdjustBlue= (ui8AdjustBlue+50)-1;
               }
              ui8AdjustRed= (ui8AdjustRed+50)-1;
         }

       for(ui8AdjustGreen=100; ui8AdjustGreen<900; ui8AdjustGreen++)
        {
            ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, ui8AdjustGreen * ui32Load / 1000);
            ROM_SysCtlDelay(10000);

              for(ui8AdjustBlue=100; ui8AdjustBlue<900; ui8AdjustBlue++)
              {
                  ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, ui8AdjustBlue * ui32Load / 1000);
                  ROM_SysCtlDelay(10000);

                  for(ui8AdjustRed=100; ui8AdjustRed<900; ui8AdjustRed++)
                    {
                            ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, ui8AdjustRed * ui32Load / 1000);
                            ROM_SysCtlDelay(10000);
                            ui8AdjustRed= (ui8AdjustRed+50)-1;
                    }
                  ui8AdjustBlue= (ui8AdjustBlue+50)-1;
               }
              ui8AdjustGreen =  (ui8AdjustGreen+50)-1;
         }
    }
}
