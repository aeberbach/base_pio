#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "base.pio.h"

int main() {
    static const uint led_pin = 25;
    static const float pio_freq = 2000; // Hz

    PIO pio = pio0;
    uint sm = pio_claim_unused_sm(pio, true);
    uint offset = pio_add_program(pio, &base_program);

    uint in_pin = 0;
    uint in_pin_count = 0;
    uint out_pin = led_pin;
    uint out_pin_count = 1;
    uint frequency = pio_freq;
    
    base_program_init(
        /* PIO */           pio,
        /* sm */            sm,
        /* offset */        offset, 
        /* input base */    in_pin, 
        /* inpout count */  in_pin_count, 
        /* output base */   out_pin, 
        /* output count */  out_pin_count, 
        /* frequency */     frequency);  

    while(true) {
        sleep_ms(1000);
    }
}