#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"

/* LCD control pins */
#define RS PB0
#define E  PB1

/* Enable pulse */
void LCD::lcd_pulse_enable() {
    PORTB |= (1 << E);
    _delay_us(10);
    PORTB &= ~(1 << E);
    _delay_ms(2);
}

/* Send 4-bit nibble */
void LCD::lcd_send_nibble(uint8_t nibble) {
    PORTD &= 0x0F;              // clear PD4–PD7
    PORTD |= (nibble << 4);     // put nibble on PD4–PD7
    lcd_pulse_enable();
}

/* Send full command */
void LCD::lcd_command(uint8_t cmd) {
    PORTB &= ~(1 << RS);        // RS = 0 (command)
    lcd_send_nibble(cmd >> 4);  // high nibble
    lcd_send_nibble(cmd & 0x0F);// low nibble
}

/* Send data (character) */
void LCD::lcd_data(uint8_t data) {
    PORTB |= (1 << RS);         // RS = 1 (data)
    lcd_send_nibble(data >> 4);
    lcd_send_nibble(data & 0x0F);
}

void LCD::lcd_clear(){
    lcd_command(0x01);          // clear display
    _delay_ms(5);
}

void LCD::lcd_print(const char* str){
    while(*str){
        lcd_data(*str++);
    }
}

void LCD::lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t row_offsets[] = {0x00, 0x40};
    lcd_command(0x80 | (row_offsets[row] + col));
}

/* LCD initialization (HD44780 4-bit mode) */
void LCD::lcd_init() {
    /* Set pin directions */
    DDRB |= (1 << RS) | (1 << E);   // RS, E as output
    DDRD |= 0xF0;                   // PD4–PD7 as output

    _delay_ms(50);              // power-up delay

    PORTB &= ~(1 << RS);        // RS = 0

    // Force LCD into 4-bit mode
    lcd_send_nibble(0x03);
    _delay_ms(5);
    lcd_send_nibble(0x03);
    _delay_ms(5);
    lcd_send_nibble(0x03);
    _delay_ms(5);
    lcd_send_nibble(0x02);      // 4-bit mode

    lcd_command(0x28);          // 4-bit, 2-line, 5x8 font
    lcd_command(0x0C);          // display ON, cursor OFF
    lcd_command(0x06);          // entry mode
    lcd_command(0x01);          // clear display
    _delay_ms(5);
}