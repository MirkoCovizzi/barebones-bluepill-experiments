#include "main.h"

void TIM4_IRQHandler(void) {
    // Check status bit
    if (TIM4->SR & TIM_SR_UIF) {
        // Clear status bit
        TIM4->SR &= ~TIM_SR_UIF;
        GPIOC->ODR ^= ODR13;
    }
}

void enable_led_timer(void) {
    // Activate LED
    RCC->APB2ENR |= IOPCEN;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;
    GPIOC->CRH |= GPIO_CRH_MODE13_0;
    GPIOC->ODR ^= ODR13;

    // Enable TIMER4 clock
    RCC->APB1ENR |= TIM4EN;
    TIM4->PSC = 36000;
    TIM4->ARR = 250;
    TIM4->CCR1 = 2;
    TIM4->DIER = TIM_DIER_UIE;
    // Enable Auto Preload
    TIM4->CR1 |= TIM_CR1_ARPE;
    // Enable TIMER4 Interrupt
    NVIC->ISER[0] = (uint32_t) 1 << 30;
    // Enable timer counter
    TIM4->CR1 |= TIM_CR1_CEN;
}

void enable_pwm(void) {
    // Enable GPIOB clock
    RCC->APB2ENR |= IOPBEN;

    // Enable TIMER3 clock
    RCC->APB1ENR |= TIM3EN;

    // Setting alternate function output push-pull
    GPIOB->CRL |= GPIO_CRL_CNF1_1;
    GPIOB->CRL &= ~GPIO_CRL_CNF1_0;

    // Setting output mode at max speed (50MHz)
    GPIOB->CRL |= GPIO_CRL_MODE1;

    TIM3->ARR = 65535;
    // Change to modulate rate
    TIM3->PSC = 32;
    // Change to modulate intensity
    TIM3->CCR4 = 4096;

    // PWM Mode 1
    TIM3->CCMR2 |= (1 << 14 | 1 << 13);
    TIM3->CCMR2 &= ~(1 << 12);

    // CC4 output polarity and enable
    TIM3->CCER &= ~(1 << 13);
    TIM3->CCER |= 1 << 12;

    // Enable Output compare 4 preload
    TIM3->CCMR2 |= 1 << 11;

    // Enable Auto Preload
    TIM3->CR1 |= TIM_CR1_ARPE;
    // Enable timer counter
    TIM3->CR1 |= TIM_CR1_CEN;
}

int main(void)
{
    enable_led_timer();
    enable_pwm();

    while (1) {}
}
