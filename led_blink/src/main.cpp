#include <avr/io.h>
#include <util/delay.h>


#define LED_PIN PB5

int main(void){
    // Set LED_PIN as output
    DDRB |= (1 << LED_PIN);

    while (1){
        // Turn the LED on
        PORTB |= (1 << LED_PIN);
        _delay_ms(5000); // Wait for 500 milliseconds

        // Turn the LED off
        PORTB &= ~(1 << LED_PIN);
        _delay_ms(1000); // Wait for 500 milliseconds
    }

    return 0;
}
