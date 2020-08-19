//Disclaimer- For reference only
//Akshat Raj Baranwal

#include"c8051f340.h"
#define lcd P4
//using the sbit directive to assign labels to pin numbers so that we dont have to remember afterwards
sbit relay=P0^0;
sbit ir_sensor1=P2^0;
sbit ir_sensor2=P2^1;
sbit lcd_RS=P1^5;
sbit lcd_RW=P1^6;
sbit lcd_EN=P1^7;
//Forward declaration of the functions
void Write_Command_Lcd(unsigned char Command);
void Write_Data_Lcd(unsigned char Character);
void DelayMs(unsigned int Ms)
int count=0;
unsigned int n,i;

void main (void){
  char LCD_data1[]={“Automated Room Ligthing”};
  char LCD_data2[]={“People are present in Room”};
  char LCD_data3[]={“Room is empty”};

  XBR1    = 0x40; 	             	       
  P0MDOUT = 0xFF; 	              
  P1MDOUT = 0xE0;                      
  P2MDIN = 0x03;		              
  P4MDOUT = 0xFF;                      

  Write_Command_Lcd(0x38);        // 2 Lines and 5x7 matix
  DelayMs(50);		                     
  Write_Command_Lcd(0x01);         // Clear Display Screen
  DelayMs(50);
  Write_Command_Lcd(0X0C);        // Display ON, Cursor OFF
  DelayMs(50);
  Write_Command_Lcd(0X80);        // Force cursor to beginning of 1st line
  DelayMs(50);

          for (i = 0; i != NULL; i++)   
              {
              	Write_Data_Lcd(LCD_data1[i]);
              	 DelayMs(50);
               }
  //Main Code Execution

	while(1) 					             
	{
	if (ir_sensor1 == 0 && ir_sensor2 == 1 ) 
		{
          			count=count+1;
          		}

       else if(ir_sensor1 == 1 && ir_sensor2 == 0)
          {
          if(count>0)
          count=count-1;
          }

        else if(count>=1)
        {
  	relay=0;
         for (i = 0; i != NULL; i++)        		
             {
               Write_Data_Lcd(LCD_data2[i]);
                DelayMs(50);
              }
         }

  	else if(count==0)
        {
  	 relay=1;
         for (i = 0; i != NULL; i++)        
             {
               Write_Data_Lcd(LCD_data3[i]);
                DelayMs(50);
              }
	}
}	
}	  
void DelayMs(unsigned int Ms) //Classic delay function that gives the delay of Ms milliseconds wherever it is called
{
	for (n=0; n < Ms; n++)
	{
		for (i=0; i < 65; i++);
	}
}

void Write_Command_Lcd(unsigned char Command) //function to send the commands to the LCD
{
    LCD_RS = 0;               
    LCD_RW = 0;
    P4 = Command;
    LCD_EN = 1;       // EN pin high->low to be latched in lcd        
    DelayMs(15);
    LCD_EN = 0;
}
void Write_Data_Lcd(unsigned char Character) //function for making the LCD understand that data is being given to it
{
    LCD_RS = 1;               
    LCD_RW = 0;
    P4 = Character;
    LCD_EN = 1; 	            
    DelayMs(15);
    LCD_EN = 0;
}
