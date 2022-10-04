#include <c8051f120.h>

void port_Init(void);       // port_Init() function declaration
void oscillator_Init(void); // oscillator_Init() void function declaration
void delay();               // delay() function declaration

unsigned int i, j, x = 0;
sbit key = P4 ^ 4;
sbit led = P5 ^ 0;
void main(void)
{
    WDTCN = 0xDE; // watchdog timer disable
    WDTCN = 0xAD;
    Oscillator_Init();
    port_Init();
    while (1)
    {
        SFRPAGE = CONFIG_PAGE;
        if (x == 0)
        {
            if (key == 0) // when a key is pressed
                x++;      // increment value of x
        }
        else if (x == 1)
        {
            if (key == 1) // if key is released in between due to fault ofswitch
                x = 0;    // do not proceed further
            else
                x++; // else increment value of x
        }
        else if (x == 2)
        {
            if (key == 0)   // if key is still pressed
                led = ~led; // proceed and toggle the led
        }
    }
}
void port_Init(void)
{
    char SFRPAGE_SAVE = SFRPAGE; // save current SFRPAGE value
    SFRPAGE = CONFIG_PAGE;       // switch SFRPAGE to CONFIG_PAGE XBR0=0x00;
    XBR1 = 0x00;
    XBR2 = 0x00;
    P5MDOUT = 0xff;         // converting port 5 as an outputport
    P5 = 0x00;              // converting port 5 as an outputport
    P4MDOUT = 0x00;         // converting port 4 as an inputport
    P4 = 0xff;              // converting port 4 as an inputport
    SFRPAGE = SFRPAGE_SAVE; // switch back SFRPAGE value to the saved page value (SFRPAGE_SAVE)
}
void oscillator_Init(void)
{
    char SFRPAGE_SAVE = SFRPAGE; // save current SFRPAGE value
    SFRPAGE = CONFIG_PAGE;       // switch SFRPAGE to CONFIG_PAGE
    OSCICN = 0x03;               // disabled internal oscillator
    SFRPAGE = SFRPAGE_SAVE;      // switch back SFRPAGE value to the saved page value (SFRPAGE_SAVE)
}
void delay()
{
    for (i = 0; i < 1000; i++) // generate some random delay
        for (j = 0; j < 1000; j++)
            ;
}