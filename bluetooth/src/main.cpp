#include "lcd_lib.h"
#include <util/delay.h>
#include <avr/io.h>
#include <Arduino.h>

#define BAUD 9600
#define MY_UBRR ((F_CPU/(16UL * BAUD)) - 1)
#define BT_BUFFER_SIZE 32

char bt_buffer[BT_BUFFER_SIZE];
uint8_t bt_index = 0;

void uart_init(){
    UBRR0H = (MY_UBRR >> 8);
    UBRR0L = MY_UBRR;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Enable receiver and transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit
}

char uart_receive(){
    while (!(UCSR0A & (1 << RXC0))); // Wait for data to be received
    return UDR0; // Get and return received data from buffer
}

void uart_transmit(char data){
    while (!(UCSR0A & (1 << UDRE0))); // Wait for empty transmit buffer
    UDR0 = data; // Put data into buffer, sends the data
}

void uart_print(const char* str){
    while(*str){
        uart_transmit(*str++);
    }
}

bool bluetooth_read_line(){
    char c = uart_receive();

    if(c == '.' || c == '!'){
        bt_buffer[bt_index] = '\0'; // Null-terminate the string
        bt_index = 0; // Reset index for next line
        return true; // Line complete
    }
    if(bt_index < BT_BUFFER_SIZE - 1){
        bt_buffer[bt_index++] = c; // Store character in buffer
    }
    return false; // Line not complete
}

int main() {
    LCD lcd;
    lcd.lcd_init();
    lcd.lcd_clear();
    uart_init();

    lcd.lcd_print("Waiting for");
    uart_print("BT LCD Initialized\n");
    lcd.lcd_set_cursor(1, 0);
    lcd.lcd_print("BT Data...");

    uart_print("Ready to receive Bluetooth data\n");
    while (1) {
        if(bluetooth_read_line()){

            uart_print(bt_buffer); // For debugging via serial monitor
            lcd.lcd_clear();
            lcd.lcd_print("Received:");
            _delay_ms(1000);
            lcd.lcd_set_cursor(1, 0);
            lcd.lcd_print(bt_buffer);
        }
    }

    return 0;
}