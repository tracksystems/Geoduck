/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using ADC_0 to generate waveform.
 */
void ADC_0_example(void)
{
	uint8_t buffer[2];

	adc_sync_enable_channel(&ADC_0, 0);

	while (1) {
		adc_sync_read_channel(&ADC_0, 0, buffer, 2);
	}
}

static void button_on_PB02_pressed(void)
{
}

/**
 * Example of using EXTERNAL_IRQ_0
 */
void EXTERNAL_IRQ_0_example(void)
{

	ext_irq_register(PIN_PB02, button_on_PB02_pressed);
}

/**
 * Example of using USART_0 to write "Hello World" using the IO abstraction.
 */
void USART_0_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_0, &io);
	usart_sync_enable(&USART_0);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

void I2C_0_example(void)
{
	struct io_descriptor *I2C_0_io;

	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x12, I2C_M_SEVEN);
	io_write(I2C_0_io, (uint8_t *)"Hello World!", 12);
}

void I2C_1_example(void)
{
	struct io_descriptor *I2C_1_io;

	i2c_m_sync_get_io_descriptor(&I2C_1, &I2C_1_io);
	i2c_m_sync_enable(&I2C_1);
	i2c_m_sync_set_slaveaddr(&I2C_1, 0x12, I2C_M_SEVEN);
	io_write(I2C_1_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using SPI_1 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_1[12] = "Hello World!";

void SPI_1_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_1, &io);

	spi_m_sync_enable(&SPI_1);
	io_write(io, example_SPI_1, 12);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_0[12] = "Hello World!";

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_0, &io);

	spi_m_sync_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
}

void delay_example(void)
{
	delay_ms(5000);
}

static struct timer_task TIMER_0_task1;
/**
 * Example of using TIMER_0.
 */
static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
}

void TIMER_0_example(void)
{
	TIMER_0_task1.interval = 100;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_start(&TIMER_0);
}

/**
 * Example of using PWM_SERVO.
 */
void PWM_SERVO_example(void)
{
	pwm_set_parameters(&PWM_SERVO, 10000, 5000);
	pwm_enable(&PWM_SERVO);
}
