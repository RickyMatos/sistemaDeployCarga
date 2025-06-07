//=====================================================================
//								UFSC - MICROCONTROLADORES
//=====================================================================
//
//										RODRIGO PEREIRA
//										pereira.rodrigo@ufsc.br
//										(c) baseado em
//										2009 Exsto Tecnologia
//=====================================================================

#include <xc.h>
#include <PIC18F4550.h>

#define _XTAL_FREQ 4000000UL  // Frequ�ncia de opera��o: 4 MHz
#define LEDs PORTD

// Configura��es de FUSES
#pragma config PLLDIV = 5				// PLL para 20MHz	
#pragma config CPUDIV = OSC1_PLL2		// PLL desligado
#pragma config FOSC = INTOSCIO_EC		// Oscilador interno com pinos de E/S
#pragma config WDT = OFF				// Watchdog desativado
#pragma config PBADEN = OFF			// Pinos do PORTB como digitais
#pragma config LVP = OFF				// Desabilita grava��o em baixa tens�o
#pragma config XINST = OFF			

void main(void)
{
	// declara��o de vari�veis
	unsigned char i;

	// Configura��o dos portais
	TRISD = 0x00;		// PORTD como sa�da

	// Configura��o do oscilador interno
	OSCCON = 0b01010000;	// Oscilador interno a 4MHz

	// Configura��o das interrup��es
	RCONbits.IPEN = 1;		// Habilita prioridade
	INTCON3bits.INT2IF = 0;	// Zera flag da INT2
	INTCON3bits.INT1IF = 0;	// Zera flag da INT1
	INTCON3bits.INT2IP = 0;	// INT2 com baixa prioridade
	INTCON3bits.INT1IP = 1;	// INT1 com alta prioridade
	INTCON3bits.INT2IE = 1;	// Habilita INT2
	INTCON3bits.INT1IE = 1;	// Habilita INT1
	INTCONbits.GIEL = 1;	// Habilita interrup��es de baixa prioridade
	INTCONbits.GIEH = 1;	// Habilita interrup��es de alta prioridade

	// Loop principal: pisca-pisca 2 Hz (0,5s ligado, 0,5s desligado)
	for(;;)
	{
		LEDs = 0x00;
		__delay_ms(500);
		LEDs = 0xFF;
		__delay_ms(500);
	}
}