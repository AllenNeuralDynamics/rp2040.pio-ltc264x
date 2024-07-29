#include <pico/stdlib.h> // for uart printing
#include <pio_ltc264x.h>
#include <cstdio> // for printf

// These can be any pins, and they need not be adjacent.
#define PICO_PIN (10)
#define SCK_PIN (11)
#define CS_PIN (12)

// Create device instance.
PIO_LTC264x dac(pio0, SCK_PIN, PICO_PIN); // CS pin is <SCK pin> + 1


// Core0 main.
int main()
{
    stdio_usb_init();
    dac.start();
    uint16_t value = 0;
    while(true)
    {
        dac.write_value(value);
        printf("Writing: %d\r\n", value);
        sleep_ms(16);
        ++value;
    }
}
