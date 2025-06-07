#ifndef ISR_H
#define ISR_H

void __interrupt(high_priority) ISR_high(void);
void __interrupt(low_priority) ISR_low(void);

#endif
