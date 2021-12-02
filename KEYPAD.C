#include "KEYBAD.h"

void keypad_Init()
{
  
  // rows
  DIO_INIT(PORTE, 3, 1);
  DIO_INIT(PORTE, 2, 1);
  DIO_INIT(PORTE, 1, 1);
  DIO_INIT(PORTE, 0, 1);
  DIO_INIT(PORTF, 1, 1);
  DIO_INIT(PORTF, 2, 1);
  DIO_INIT(PORTF, 3, 1);
  SET_BIT(GPIO_PORTE_ODR_R, 3);
  SET_BIT(GPIO_PORTE_ODR_R, 2);
  SET_BIT(GPIO_PORTE_ODR_R, 1);
  SET_BIT(GPIO_PORTE_ODR_R, 0);

  // cols 
  DIO_INIT(PORTC, 7, 0);
  DIO_INIT(PORTC, 6, 0);
  DIO_INIT(PORTC, 5, 0);
  DIO_INIT(PORTC, 4, 0); // 7 6 5 4 IN 
}

int_8 keypad_read()
{
  int_8 lookup_table[4][4] = {{'1', '2', '3', '+'},
                                 {'4', '5', '6', '-'},
                                 {'7', '8', '9', '*'},
                                 {'=', '0', '#', '/'}};
  int col = 0, rw = 0;
  for (int i = 0; i < 4; i++)
  {
    if (!GET_BIT(GPIO_PORTC_DATA_R, i+4)) 
    { 
       GPIO_PORTE_DATA_R = 0xf; // Why do we need delay here ?!!
       delay_us(0.5);
       for ( int j = 0; j < 4; j++)  
       {
       TOGGLE_BIT(GPIO_PORTE_DATA_R, j);
       if (!GET_BIT(GPIO_PORTC_DATA_R, i+4))
       {
          col = i; 
          rw = j;
          GPIO_PORTE_DATA_R = 0x0;
          return lookup_table[j][i];
       }
        TOGGLE_BIT(GPIO_PORTE_DATA_R, j);
       }
    }   
  }
  GPIO_PORTE_DATA_R = 0x0;
  return  'x';
}
