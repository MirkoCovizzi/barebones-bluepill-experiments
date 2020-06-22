#include "main.h"

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
    TIM3->PSC = 16;
    TIM3->CCR4 = 32;
    TIM3->CCMR2 &= ~(TIM3_CC4S_1 | TIM3_CC4S_0);

    TIM3->EGR |= 1;

    // PWM Mode 1
    TIM3->CCMR2 |= (1 << 14 | 1 << 13);
    TIM3->CCMR2 &= ~(1 << 12);

    // CC4 output polarity and enable
    TIM3->CCER &= ~(1 << 13);
    TIM3->CCER |= 1 << 12;

    // Enable Output compare 4 preload
    TIM3->CCMR2 |= 1 << 11;

    // Enable Auto Preload
    TIM3->CR1 |= 1 << 7;
    // Enable timer counter
    TIM3->CR1 |= 1;
}

int main(void)
{
    enable_pwm();

    while (1) {}
}
