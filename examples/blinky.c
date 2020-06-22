#define __IO volatile

typedef unsigned int uint32_t;

typedef struct {
    __IO uint32_t CR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t AHBRSTR;
    __IO uint32_t CFGR2;
} RCC_TypeDef;

typedef struct {
    __IO uint32_t CRL;
    __IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
} GPIO_TypeDef;

#define RCC ((RCC_TypeDef *) 0x40021000)
#define GPIOC ((GPIO_TypeDef *) 0x40011000)

#define IOPCEN ((uint32_t) 0x00000010)
#define ODR13 ((uint32_t) 0x00002000)

#define  GPIO_CRH_MODE13_0 ((uint32_t)0x00100000)

#define  GPIO_CRH_CNF13 ((uint32_t)0x00C00000)

int main(void)
{
    RCC->APB2ENR |= IOPCEN;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;
    GPIOC->CRH |= GPIO_CRH_MODE13_0;

    uint32_t i;

    while (1) {
        GPIOC->ODR ^= ODR13;
        for (i = 0; i < 500000; i++);
    }
}
