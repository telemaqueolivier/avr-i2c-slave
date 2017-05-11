/* I2C Echo Example */
#include <avr/io.h>
#include "I2CSlave.h"

#define I2C_ADDR 0x08

volatile uint8_t data, is_data_received = 0;

void I2C_received(uint8_t received_data)
{
  data = received_data;
  is_data_received = 1;
}

void I2C_requested()
{
  // I2C_transmitByte(data);
}

void setup()
{
  // set received/requested callbacks
  I2C_setCallbacks(I2C_received, I2C_requested);

  // init I2C
  I2C_init(I2C_ADDR);
}

int main()
{
  setup();

  // Main program loop
  while (1){
    if (is_data_received){
      PORTC = PORTC ^ (1 << PORTC2);
      is_data_received = 0;      
    }
  }
}
