//=====================================================================
//								UFSC - MICROCONTROLADORES
//=====================================================================
//
//										RODRIGO PEREIRA
//										pereira.rodrigo@ufsc.br
//										(c) baseado em
//										2009 Exsto Tecnologia
//=====================================================================
#include<PIC18F4550.h>
#include<xc.h>

#define _XTAL_FREQ 20000000
// Configurções
#pragma config	PLLDIV = 5				// PLL para 20MHz	
#pragma config	CPUDIV = OSC1_PLL2		// PLL desligado
#pragma config	FOSC = HS				// Fosc = 20MHz		Tcy = 200ns
#pragma config	WDT = OFF				// Watchdog desativado
#pragma config	PBADEN = OFF			// Pinos do PORTB começam como digitais
#pragma config	LVP = OFF				// Desabilita gravação em baixa tensão
#pragma config	XINST = OFF

// Definições de hardware
#define INC		PORTBbits.RB0		
#define DEC		PORTBbits.RB1		

#define DISP4	PORTAbits.RA5		// DISP4
#define DISP3	PORTAbits.RA2		// DISP3
#define DISP2	PORTEbits.RE0		// DISP2
#define DISP1	PORTEbits.RE2		// DISP1

#define DISPLAY	PORTD				// Segmentos do display ligados em PORTD

void main(void){
	int i = 0;

	// tabela de dígitos do display
	char table[] = {0b00111111,	// 0
					0b00000110,	// 1
					0b01011011, // 2
					0b01001111,	// 3
					0b01100110,	// 4
					0b01101101,	// 5
					0b01111100,	// 6
					0b00000111,	// 7
					0b01111111,	// 8
					0b01100111,	// 9
					0b01110111,	// A
					0b01111100,	// B
					0b01011000,	// C
					0b01011110,	// D
					0b01111001,	// E
					0b01110001	// F
	};

	// *** Inicialização
	ADCON1 = 0x0F;

	TRISD = 0x00;	
    TRISA = 0x00;
	TRISE = 0x00;
    
   
    // configura port D como saída
	TRISAbits.TRISA0 = 0;	// DISP4 é saída
	TRISAbits.TRISA2 = 0;	// DISP3 é saída
	TRISEbits.TRISE0 = 0;	// DISP2 é saída
	TRISEbits.TRISE2 = 0;	// DISP1 é saída

	DISP1 = 1;		
	DISP2 = 0;		
	DISP3 = 0;		
	DISP4 = 0;		

    
   
	INTCON2bits.RBPU = 0;	// ativa pul-ups
	
	for(;;){
		DISPLAY = table[i];
       __delay_ms(150);
       
		if(!INC){				// incremento
			if(i < 0x0F) i++;
			while(!INC);
		}
		if(!DEC){				// decremento
			if(i > 0) i--;
		while(!DEC);
		}
	}
}
