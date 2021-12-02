#include"types.h"
#include"tm4c123gh6pm.h"
#include"stdint.h"

#define SET_BIT(REG,PIN) {REG|=(1<<PIN);}
#define CLEAR_BIT(REG,PIN) {REG&= ~(1<<PIN);}
#define TOGGLE_BIT(REG,PIN) {REG^= (1<<PIN);}
#define GET_BIT(REG,PIN) (((1<<PIN)&REG)>>PIN)
#define IN 0
#define OUT 1
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5


void keypad_Init();
int_8 keypad_read();
