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

#define _XTAL_FREQ 4000000UL  // Frequência de operação: 4 MHz
#define LEDs PORTD

// Configurações de FUSES
#pragma config PLLDIV = 5				// PLL para 20MHz	
#pragma config CPUDIV = OSC1_PLL2		// PLL desligado
#pragma config FOSC = INTOSCIO_EC		// Oscilador interno com pinos de E/S
#pragma config WDT = OFF				// Watchdog desativado
#pragma config PBADEN = OFF			// Pinos do PORTB como digitais
#pragma config LVP = OFF				// Desabilita gravação em baixa tensão
#pragma config XINST = OFF			

void main(void)
{
	// declaração de variáveis
	unsigned char i;

	// Configuração dos portais
	TRISD = 0x00;		// PORTD como saída

	// Configuração do oscilador interno
	OSCCON = 0b01010000;	// Oscilador interno a 4MHz

	// Configuração das interrupções
	RCONbits.IPEN = 1;		// Habilita prioridade
	INTCON3bits.INT2IF = 0;	// Zera flag da INT2
	INTCON3bits.INT1IF = 0;	// Zera flag da INT1
	INTCON3bits.INT2IP = 0;	// INT2 com baixa prioridade
	INTCON3bits.INT1IP = 1;	// INT1 com alta prioridade
	INTCON3bits.INT2IE = 1;	// Habilita INT2
	INTCON3bits.INT1IE = 1;	// Habilita INT1
	INTCONbits.GIEL = 1;	// Habilita interrupções de baixa prioridade
	INTCONbits.GIEH = 1;	// Habilita interrupções de alta prioridade

	// Loop principal: pisca-pisca 2 Hz (0,5s ligado, 0,5s desligado)
	for(;;)
	{
		LEDs = 0x00;
		__delay_ms(500);
		LEDs = 0xFF;
		__delay_ms(500);
	}
}