#include"stdint.h"
#include"tm4c123gh6pm.h"
#include"DIO.h"
#include"stdio.h"
int main()
{
  DIO_INIT(PORTF, 1, OUT);
  DIO_INIT(PORTF, 2, OUT);
  DIO_INIT(PORTF, 3, OUT);
  

  while(1)
  {
    write_pin(PORTF, 1, 1);
    int counter = 0;
    while(counter < 1000000)
    {
        counter++;
    }
    write_pin(PORTF, 1, 0);
    counter = 0;
    while(counter < 1000000)
    {
        counter++;
    }
    
     write_pin(PORTF, 2, 1);
    counter = 0;
    while(counter < 1000000)
    {
        counter++;
    }
    write_pin(PORTF, 2, 0);
    counter = 0;
    while(counter < 1000000)
    {
        counter++;
    }
    
     write_pin(PORTF, 3, 1);
    counter = 0;
    while(counter < 1000000)
    {
        counter++;
    }
    write_pin(PORTF, 3, 0);
    counter = 0;
    while(counter < 1000000)
    {
        counter++;
    }
  }
    
    

  
  
}



/*


  SYSCTL_RCGCGPIO_R |= 0x00000020; 
  while((SYSCTL_PRGPIO_R & 0x00000020) == 0){}; 00100000 
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_DIR_R = 0x0E;
  GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTF_DEN_R = 0x1F;
  GPIO_PORTF_DATA_R =0X0E; 

*/