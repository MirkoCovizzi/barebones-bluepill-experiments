#define __IO volatile

typedef unsigned short int uint16_t;
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

typedef struct
{
    __IO uint16_t CR1;
    uint16_t  RESERVED0;
    __IO uint16_t CR2;
    uint16_t  RESERVED1;
    __IO uint16_t SMCR;
    uint16_t  RESERVED2;
    __IO uint16_t DIER;
    uint16_t  RESERVED3;
    __IO uint16_t SR;
    uint16_t  RESERVED4;
    __IO uint16_t EGR;
    uint16_t  RESERVED5;
    __IO uint16_t CCMR1;
    uint16_t  RESERVED6;
    __IO uint16_t CCMR2;
    uint16_t  RESERVED7;
    __IO uint16_t CCER;
    uint16_t  RESERVED8;
    __IO uint16_t CNT;
    uint16_t  RESERVED9;
    __IO uint16_t PSC;
    uint16_t  RESERVED10;
    __IO uint16_t ARR;
    uint16_t  RESERVED11;
    __IO uint16_t RCR;
    uint16_t  RESERVED12;
    __IO uint16_t CCR1;
    uint16_t  RESERVED13;
    __IO uint16_t CCR2;
    uint16_t  RESERVED14;
    __IO uint16_t CCR3;
    uint16_t  RESERVED15;
    __IO uint16_t CCR4;
    uint16_t  RESERVED16;
    __IO uint16_t BDTR;
    uint16_t  RESERVED17;
    __IO uint16_t DCR;
    uint16_t  RESERVED18;
    __IO uint16_t DMAR;
    uint16_t  RESERVED19;
} TIM_TypeDef;

#define RCC ((RCC_TypeDef *) 0x40021000)

#define GPIOB ((GPIO_TypeDef *) 0x40010C00)

#define TIM3EN ((uint32_t) 1 << 1)
#define IOPBEN ((uint32_t) 1 << 3)

#define GPIO_CRL_MODE1 ((uint32_t) 1 << 5 | 1 << 4)
#define GPIO_CRL_CNF1_0 ((uint32_t) 1 << 6)
#define GPIO_CRL_CNF1_1 ((uint32_t) 1 << 7)

#define TIM3 ((TIM_TypeDef *) 0x40000400)
