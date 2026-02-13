
/* Memory regions for flash and ram */

MEMORY
{
    RAM  (rw)     : ORIGIN = 0x20000000, LENGTH = 128K
    FLASH  (rx)    : ORIGIN = 0x08000000, LENGTH = 512K
}

/* Include section declarations */


ENTRY(_start);

SECTIONS
{
	.start_of_flash_program : {
		__flash_program_begin = . ;
	} > FLASH
	.vectors : {
		*(boot)                 /* Boot values for PC, SP */
        *(interrupt_vector)     /* Interrupt Vector */
		. = ALIGN(0x04);
    } >FLASH
    .text . : {
        *main.o(.text)		/* Main user functions */
		*(.init)
		*(.fini)
        *(.text .text.*)    /* Program code */
		. = ALIGN(0x04);
	} >FLASH
    .ARM.exidx . : {
 		__exidx_start = . ;
		*(.ARM.exidx* .gnu.linkonce.armexidx.*) /* exception handling */
		__exidx_end   = . ;
		. = ALIGN(0x04);
	} >FLASH
	.rodata . : {
        *(.rodata .rodata.*)    /* Read-only data */
 		*(.ARM.extab* .gnu.linkonce.armextab.*) /* exception handling */
		*(.eh_frame*) 		/* exception handling tables */
		*(.eh_frame_hdr*)	/* exception handling tables (headers) */
		. = ALIGN(0x04);
    } >FLASH
    .data : {
		__data_start__ = . ;

   		__preinit_array_start = . ;
 		*(.preinit_array*) 	/* Pointers to preinit code */
		__preinit_array_end   = . ;
		__init_array_start = . ;
 	 	*(.init_array*)     /* Pointers to global constructors */
 	 	*(.ctors*)          /* Pointers to global constructors */
		__init_array_end   = . ;
		__fini_array_start = . ;
 		*(.fini_array*)      /* Pointers to global destructors */
 		*(.dtors*)           /* Pointers to global destructors */
		__fini_array_end   = . ;
	 	*(.jcr*)
		. = ALIGN(0x04);

		*(.data .data.*)  /* Read-Write Data (copied to RAM at boot) */
        . = ALIGN(0x04);
        
		__data_end__ = . ;
	} >RAM AT >FLASH
    .bss (NOLOAD) : {
		__bss_start__  = . ;
        *(.bss .bss.*)    /* 0-initialized memory */
		*(COMMON)
        	. = ALIGN(0x04);
		__bss_end__  = . ;
    } >RAM AT >RAM
    .start_of_unused_ram : {
    	__heap_bottom = . ;
    } > RAM
	.end_of_flash_program : {
		__flash_program_end = . ;
	} > FLASH
   	.crc_info : {
		*(crc_info)
       	. = ALIGN(0x04);
    } > FLASH
 }

__stack = ORIGIN(RAM)+LENGTH(RAM); /* used to initialise SP */

__data_load__ = LOADADDR(.data) ;

/* Constant device-specific values */

Package_data	= 0x1FFF7BF0;
TS_CAL2		= 0x1FFF7A2E;
TS_CAL1		= 0x1FFF7A2C;
VREFIN_CAL	= 0x1FFF7A2A;
Flash_size	= 0x1FFF7A22;
U_ID		= 0x1FFF7A10;


/* Core Devices base addresses */

DBG		= 0xE0042000;

FPU		= 0xE000EF30;
NVIC_STIR	= 0xE000EF00;
MPU		= 0xE000ED90;
FPU_CPACR	= 0xE000ED88;
SCB		= 0xE000ED00;
NVIC		= 0xE000E100;
SysTick		= 0xE000E010;

/* Devices base addresses */

/* FMC     	= 0xA0000000;  not available on LQFP64 package */
QUADSPI 	= 0xA0001000;

DCMI    	= 0x50050000;
USB_OTG_FS	= 0x50000000;

USB_OTG_HS	= 0x40040000;
DMA2		= 0x40026400;
DMA1		= 0x40026000;
BKPSRAM		= 0x40024000;
FLASH		= 0x40023C00;
RCC		= 0x40023800;
CRC		= 0x40023000;
GPIOH		= 0x40021C00;
GPIOG		= 0x40021800;
GPIOF		= 0x40021400;
GPIOE		= 0x40021000;
GPIOD		= 0x40020C00;
GPIOC		= 0x40020800;
GPIOB		= 0x40020400;
GPIOA		= 0x40020000;

SAI2		= 0x40015C00;
SAI1		= 0x40015800;

TIM11		= 0x40014800;
TIM10		= 0x40014400;
TIM9		= 0x40014000;
EXTI		= 0x40013C00;
SYSCFG		= 0x40013800;
SPI4		= 0x40013400;
SPI1		= 0x40013000;
SDMMC		= 0x40012C00;
ADC_common	= 0x40012300;
ADC3		= 0x40012200;
ADC2		= 0x40012100;
ADC1		= 0x40012000;
USART6		= 0x40011400;
USART1		= 0x40011000;
TIM8		= 0x40010400;
TIM1		= 0x40010000;

DAC		= 0x40007400;
PWR		= 0x40007000;
HDMI_CEC	= 0x40006C00;
CAN2		= 0x40006800;
CAN1		= 0x40006400;
I2C3		= 0x40005C00;
I2C2		= 0x40005800;
I2C1		= 0x40005400;
UART5		= 0x40005000;
UART4		= 0x40004c00;
USART3		= 0x40004800;
USART2		= 0x40004400;
SPDIF_RX	= 0x40004000;
SPI3_I2S3	= 0x40003C00;
SPI2_I2S2	= 0x40003800;
IWDG		= 0x40003000;
WWDG		= 0x40002C00;
RTC_BKP		= 0x40002800;
TIM14		= 0x40002000;
TIM13		= 0x40001C00;
TIM12		= 0x40001800;
TIM7		= 0x40001400;
TIM6		= 0x40001000;
TIM5		= 0x40000C00;
TIM4		= 0x40000800;
TIM3		= 0x40000400;
TIM2		= 0x40000000;
















