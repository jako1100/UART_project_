 /*************************************/
 /******* APP layer  API's ************/
 /*************************************/
 
 void increment_by_one(void);
 void decrement_by_one(void);
 
 /*************************************/
 /*************************************/
 /*************************************/
 
 /*************************************/
 /*********** ECUAL  API's ************/
 /*************************************/
 
 /*KEYPAD*/
 
 uint8 KeyPad_getPressedKey(void);
void get_keyPadInput(uint8 arr[],uint8 number_of_digits);
uint16 convertToNum(uint8 arr[],uint8 number_of_digits);

/*LCD*/

void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);


/*SWITCH*/
uint8_t getSwitchState(uint8_t switch_id,uint8_t * result);


 /*************************************/
 /*********** MCAL  API's *************/
 /*************************************/
 
 
 /*TIMER*/
 
 void timer1_ctc_init(uint16_t compare);
 
 /*UART*/
 
 void UART_init(void);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str);

/*DIO*/

uint8_t DIO_init (void);

uint8_t DIO_write (uint8_t port,uint8_t pin,uint8_t val);

uint8_t DIO_read (uint8_t port,uint8_t pin,uint8_t * Pval);

/*************************************************************/
/********************   Assumptions  **************************/
/*
1- UART polling
2- TIMER CTC mode
3-EXT INT2
/*************************************************************/


