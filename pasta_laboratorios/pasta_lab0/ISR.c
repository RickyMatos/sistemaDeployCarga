#include <xc.h>
#include "ISR.h"

#define _XTAL_FREQ 4000000UL

void __interrupt(high_priority) ISR_high(void) {
    if (INTCON3bits.INT1IF && INTCON3bits.INT1IE) {
        INTCON3bits.INT1IF = 0;

        for (unsigned char i = 3; i > 0; i--) {
            PORTD = 0x55;
            __delay_ms(500);
            PORTD = 0xAA;
            __delay_ms(500);
        }
    }
}

void __interrupt(low_priority) ISR_low(void) {
    if (INTCON3bits.INT2IF && INTCON3bits.INT2IE) {
        INTCON3bits.INT2IF = 0;

        unsigned char Desloc = 0x01;
        for (unsigned char i = 3; i > 0; i--) {
            for (unsigned char j = 0; j < 7; j++) {
                PORTD = ~Desloc;
                __delay_ms(250);
                Desloc <<= 1;
            }
            for (unsigned char j = 0; j < 7; j++) {
                PORTD = ~Desloc;
                __delay_ms(250);
                Desloc >>= 1;
            }
        }
    }
}
