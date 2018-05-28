#include <stdint.h>

#define I2C_M_START 	I2C0->C1 |= I2C_C1_MST_MASK
#define I2C_M_STOP  	I2C0->C1 &= ~I2C_C1_MST_MASK
#define I2C_M_RSTART 	I2C0->C1 |= I2C_C1_RSTA_MASK

#define I2C_TRAN			I2C0->C1 |= I2C_C1_TX_MASK
#define I2C_REC				I2C0->C1 &= ~I2C_C1_TX_MASK

#define BUSY_ACK 	    while(I2C0->S & 0x01)
#define TRANS_COMP		while(!(I2C0->S & 0x80))

#define NACK 	        I2C0->C1 |= I2C_C1_TXAK_MASK
#define ACK           I2C0->C1 &= ~I2C_C1_TXAK_MASK

extern volatile uint8_t  
								transfer_complete,
								new_data,
								ready_to_transmit,
								Prog_flow;
extern uint8_t Mode_block, Mode_FSM_Poll, Mode_ISR;

void i2c_init(void);
int i2c_read_bytes(uint8_t dev_adx, uint8_t reg_adx, uint8_t * data, uint8_t data_count);
int i2c_write_bytes(uint8_t dev_adx, uint8_t reg_adx, uint8_t * data, uint8_t data_count);
int i2c_read_bytes_ISR(uint8_t dev_adx, uint8_t reg_adx, uint8_t * data, uint8_t data_count);
void i2c_wait( void );

int i2c_read_bytes_fsm(uint8_t dev_adx, uint8_t reg_adx, uint8_t * data, uint8_t data_count);