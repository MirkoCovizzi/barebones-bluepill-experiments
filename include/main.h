#define __IO volatile

typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

// Cortex-M3 uses only array registers 0-2
// Alignment can be found at page 128 of Cortex-M3 Programming Manual
typedef struct {
    __IO uint32_t ISER[8U];
    uint32_t RESERVED0[24U];
    __IO uint32_t ICER[8U];
    uint32_t RSERVED1[24U];
    __IO uint32_t ISPR[8U];
    uint32_t RESERVED2[24U];
    __IO uint32_t ICPR[8U];
    uint32_t RESERVED3[24U];
    __IO uint32_t IABR[8U];
    uint32_t RESERVED4[56U];
    __IO uint8_t IP[240U];
    uint32_t RESERVED5[644U];
    __IO uint32_t STIR;
} NVIC_Type;

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

typedef struct {
    __IO uint16_t CR1;
    uint16_t RESERVED0;
    __IO uint16_t CR2;
    uint16_t RESERVED1;
    __IO uint16_t SMCR;
    uint16_t RESERVED2;
    __IO uint16_t DIER;
    uint16_t RESERVED3;
    __IO uint16_t SR;
    uint16_t RESERVED4;
    __IO uint16_t EGR;
    uint16_t RESERVED5;
    __IO uint16_t CCMR1;
    uint16_t RESERVED6;
    __IO uint16_t CCMR2;
    uint16_t RESERVED7;
    __IO uint16_t CCER;
    uint16_t RESERVED8;
    __IO uint16_t CNT;
    uint16_t RESERVED9;
    __IO uint16_t PSC;
    uint16_t RESERVED10;
    __IO uint16_t ARR;
    uint16_t RESERVED11;
    __IO uint16_t RCR;
    uint16_t RESERVED12;
    __IO uint16_t CCR1;
    uint16_t RESERVED13;
    __IO uint16_t CCR2;
    uint16_t RESERVED14;
    __IO uint16_t CCR3;
    uint16_t RESERVED15;
    __IO uint16_t CCR4;
    uint16_t RESERVED16;
    __IO uint16_t BDTR;
    uint16_t RESERVED17;
    __IO uint16_t DCR;
    uint16_t RESERVED18;
    __IO uint16_t DMAR;
    uint16_t RESERVED19;
} TIM_TypeDef;

// Memory mapping can be found at page 128 of Cortex-M3 Programming Manual
#define NVIC ((NVIC_Type *) 0xE000E100)

#define RCC ((RCC_TypeDef *) 0x40021000)

#define GPIOB ((GPIO_TypeDef *) 0x40010C00)
#define GPIOC ((GPIO_TypeDef *) 0x40011000)

#define TIM3EN ((uint32_t) 1 << 1)
#define TIM4EN ((uint32_t) 1 << 2)

#define IOPBEN ((uint32_t) 1 << 3)
#define IOPCEN ((uint32_t) 1 << 4)

#define GPIO_CRL_MODE1 ((uint32_t) 1 << 5 | 1 << 4)
#define GPIO_CRL_CNF1_0 ((uint32_t) 1 << 6)
#define GPIO_CRL_CNF1_1 ((uint32_t) 1 << 7)

#define GPIO_CRH_MODE13_0 ((uint32_t) 1 << 20)
#define GPIO_CRH_CNF13 ((uint32_t) 1 << 23 | 1 << 22)
#define ODR13 ((uint32_t) 1 << 13)

#define TIM3 ((TIM_TypeDef *) 0x40000400)
#define TIM4 ((TIM_TypeDef *) 0x40000800)

#define TIM_CR1_ARPE ((uint16_t) 1 << 7)
#define TIM_CR1_CEN ((uint16_t) 1)
#define TIM_DIER_UIE ((uint16_t) 1)
#define TIM_SR_UIF ((uint16_t) 1)


