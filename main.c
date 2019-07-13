#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#define LED_PORT		GPIOF
#define LED_PIN			GPIO_Pin_6
const uint32_t second = 9000000;
uint32_t ticks;
GPIO_InitTypeDef	GPIO_InitStruct;
void us_delay( uint32_t value );
void ms_delay(uint32_t value);
int main() 
{
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOF | RCC_APB2Periph_AFIO , ENABLE );
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = LED_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init( LED_PORT , &GPIO_InitStruct );
	SysTick_Config( second );
	while( 1 );
}
void SysTick_Handler( void ) {
	static int hadi = 0;
	hadi ++ ;
	if( hadi > 7 ) 
	{
		GPIO_WriteBit( LED_PORT , LED_PIN , !(GPIO_ReadInputDataBit( LED_PORT , LED_PIN )));
		hadi = 0;
	}
	SysTick_Config( second );
}
