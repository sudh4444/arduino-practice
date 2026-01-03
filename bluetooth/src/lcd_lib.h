
#include <util/delay.h>
#include <avr/io.h>

class LCD {
public:
void lcd_pulse_enable() ;
void lcd_send_nibble(uint8_t nibble) ;
void lcd_command(uint8_t cmd) ;
void lcd_data(uint8_t data) ;
void lcd_clear();
void lcd_print(const char* str);
void lcd_set_cursor(uint8_t row, uint8_t col) ;
void lcd_init() ;
};