#include"stdint.h"
#include"tm4c123gh6pm.h"
#include"DIO.h"
#include"stdio.h"

# define SYSTEM_CLOC_FREQUENCY  80000000
#define DELAY_DEBOUNCE SYSTEM_CLOC_FREQUENCY/100
void Delay(unsigned long counter)
{
	unsigned long i = 0;
	for(i = 0; i<counter; i++);	
}

int tiny_calc();
void state_machine_ep();
void state_machine();
int main()
{

  
   //state_machine_ep();
   //state_machine();	
  
   // Tiny calculator using keypad 
  
  keypad_Init();   
  int value_of_calculator = tiny_calc();
  while(1);
  
}
  
  

void state_machine_ep()
{
  DIO_INIT(PORTF, 0, IN);
  DIO_INIT(PORTF, 1, OUT);
  DIO_INIT(PORTF, 2, OUT);
  DIO_INIT(PORTF, 3, OUT);
  DIO_INIT(PORTF, 4, IN);
  int flag = 0;
  int flag_1 = 0;
  int both = 0;
  int_8 state = 0;   
  // State machine end-point // Lab4_report Task2
  while(1)
  {
		switch(state)
		{ 
			case 0: 
				write_pin(PORTF, 2, 1);
				write_pin(PORTF, 1, 1);
				write_pin(PORTF, 3, 1);
			   	if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
			   	{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
						state = 0;
			   	}
			  	else if(DIO_ReadPin(PORTF, 0) == 0)
			  	{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 1 && DIO_ReadPin(PORTF, 0) == 0)
						state = 1;
			  	}
			  	else if(DIO_ReadPin(PORTF, 4) == 0)
			  	{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 0 && DIO_ReadPin(PORTF, 0) == 1)
						state = 3;
			  	}		
				break;
			case 1: 
				write_pin(PORTF, 2, 0);
				write_pin(PORTF, 3, 0);
				write_pin(PORTF, 1, 1);
				
				if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
				{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
						state = 0;
				}
			   	else if(DIO_ReadPin(PORTF, 0) == 0)
			   	{
					Delay(DELAY_DEBOUNCE);
					if (DIO_ReadPin(PORTF, 4) == 1 && DIO_ReadPin(PORTF, 0) == 0)
						state = 2;
			   	}
			   	else if(DIO_ReadPin(PORTF, 4) == 0)
			   	{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 0 && DIO_ReadPin(PORTF, 0) == 1)
						state = 0;
			   	}
				break;
			case 2: 
				write_pin(PORTF, 1, 0);
				write_pin(PORTF, 2, 0);
				write_pin(PORTF, 3, 1);
				
				if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
				{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
						state = 0;
				}
				else if(DIO_ReadPin(PORTF, 0) == 0)
				{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 1 && DIO_ReadPin(PORTF, 0) == 0)
						state = 3;
				}
			   	else if(DIO_ReadPin(PORTF, 4) == 0)
			   	{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 0 && DIO_ReadPin(PORTF, 0) == 1)
						state = 1;
			   	}
				break;
			case 3: 
				write_pin(PORTF, 1, 0);
				write_pin(PORTF, 3, 0);
				write_pin(PORTF, 2, 1);

				if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
				{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 0) == 0 && DIO_ReadPin(PORTF, 4) == 0)
						state = 0;
				}
				else if(DIO_ReadPin(PORTF, 0) == 0)
				{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 1 && DIO_ReadPin(PORTF, 0) == 0)
						state = 0;
				}
			   else if(DIO_ReadPin(PORTF, 4) == 0)
			   	{
					Delay(DELAY_DEBOUNCE);
					if(DIO_ReadPin(PORTF, 4) == 0 && DIO_ReadPin(PORTF, 0) == 1)
						state = 2;
			   	}
				break;
			default: state = 0; break; 
			}
	  }
}   


void state_machine()
{
	DIO_INIT(PORTF, 0, IN);
	DIO_INIT(PORTF, 1, OUT);
	DIO_INIT(PORTF, 2, OUT);
	DIO_INIT(PORTF, 3, OUT);
	DIO_INIT(PORTF, 4, IN);
	int flag = 0;
	int flag_1 = 0;
	int both = 0;
	int_8 state = 0;   
    // State machine lab4_A_Progress
   	while(1)
	{
		switch(state)
		{
			case 0: 
				write_pin(PORTF, 1, 1);
				write_pin(PORTF, 2, 1);
				write_pin(PORTF, 3, 1);
				if(DIO_ReadPin(PORTF, 0) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 0) == 0))
						state = 1;
				if(DIO_ReadPin(PORTF, 4) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 4) == 0))
						state = 3;
				break;
		   case 1: 
				write_pin(PORTF, 2, 0);
				write_pin(PORTF, 3, 0);
				write_pin(PORTF, 1, 1);

				if(DIO_ReadPin(PORTF, 0) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 0) == 0))
						state = 2;
				if(DIO_ReadPin(PORTF, 4) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 4) == 0))
						state = 0;
				break;
		   case 2: 
				write_pin(PORTF, 1, 0);
				write_pin(PORTF, 2, 0);
				write_pin(PORTF, 3, 1);
				if(DIO_ReadPin(PORTF, 0) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 0) == 0))
						state = 3;
				if(DIO_ReadPin(PORTF, 4) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 4) == 0))
						state = 1;
				break;
		   case 3: 
				write_pin(PORTF, 1, 0);
				write_pin(PORTF, 3, 0);
				write_pin(PORTF, 2, 1);

				if(DIO_ReadPin(PORTF, 0) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 0) == 0))
						state = 0;
			   if(DIO_ReadPin(PORTF, 4) == 0)
					Delay(DELAY_DEBOUNCE);
					if((DIO_ReadPin(PORTF, 4) == 0))
						state = 2;
			   break;
		default: state = 0; break; 
		 
		}
	}
}
int tiny_calc()
{
  int_16 v1= 1, e = 1; 
  int_16 cal = 0;
  int_8 var1[10]={0}, op='0', var2[10]={0};
  int_8 i = 0, j = 0;
  int_8 vv, vw, vx; 
  int_8 key; 

  while(e)
  {  
      do
      {
        key = keypad_read(); 
        delay_ms(0.2);
      }
      while(keypad_read() != key || key == 'x');
        
      if ((key == '1' || key == '2' || key == '3' || 
            key == '4' || key == '5' || key == '6' ||
            key == '7' || key == '8' || key == '9'
                || key == '0') && v1)
      {
        var1[i] =key;
        GPIO_PORTF_DATA_R = 0x02;
        vv = key;
        i++;
      }
      else if (key == '+' || key== '-'  || key == '*'  || key == '/')
      {
          v1 = 0;
          i = 0; 
          op = key;
          GPIO_PORTF_DATA_R = 0x04;
          vw = key;
      }
     else if(key == '1' || key == '2' || key == '3' || 
             key == '4' || key == '5' || key == '6' ||
             key == '7' || key == '8' || key == '9' || key == '0')
        {
        var2[j] =key;
        j++;
        GPIO_PORTF_DATA_R = 0x08;
        vx = key;
        }
     else if (key == '=')
        e = 0;
     do
      {
         while(keypad_read() != 'x');
         delay_ms(0.2);
      }while (keypad_read() != 'x');
     
  }
  GPIO_PORTF_DATA_R = 0x1E;
  switch(op)
    {
    case '+':
        cal = atoi(var1) + atoi(var2);
        break;
    case '-':
        cal = atoi(var1) - atoi(var2);
        break;
    case '*':
        cal = atoi(var1) * atoi(var2);
        break;
    case '/':
        cal = atoi(var1) / atoi(var2);
        break;
    default: 
        break;
    }
   return cal;
}
