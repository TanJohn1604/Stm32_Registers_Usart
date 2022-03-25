/*
 * config.c
 *
 *  Created on: Mar 10, 2022
 *      Author: ad
 */
#include "config.h"

void config(void){
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY) );
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while(!(RCC->CFGR & RCC_CFGR_SWS_HSE));
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
	RCC->CFGR|= RCC_CFGR_PPRE2_DIV1;

	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	GPIOC->CRH &=~ GPIO_CRH_CNF13;

	GPIOC->CRH |= GPIO_CRH_MODE13;

	TIM1->ARR =0xffff-1;
	TIM1->PSC =8-1;





	TIM1->CR1 |=TIM_CR1_CEN;

	while(! (TIM1->SR & TIM_SR_UIF ));



}
void delay_us(uint16_t us ){
	TIM1->CNT=0;
	while(TIM1->CNT <us);

}
void delay_ms(uint16_t ms){

	for (uint16_t i=0; i<ms ;i++){
		delay_us(1000);
	}
}
