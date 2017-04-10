void dpa_init_sfr_02a_p0()
{
	unsigned char 
		set;

#ifdef NODE
	//////////////////////////////////////////////
	// IO's	- P0;  PxSEL; PxDIR; PxINP; PxIFG;
	//////////////////////////////////////////////
	
	//Function Select: 0: General purpose I/O;  1: Peripheral function
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_1; //BIT 1 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_2; //BIT 2 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_3; //BIT 3 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_4; //BIT 4 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_5; //BIT 5 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_6; //BIT 6 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_7; //BIT 7 - 0: General purpose I/O;  1: Peripheral function
	P0SEL = set;

	//Direction Select
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - 0-> INPUT, 1-> Output
		set=set|OSB_1; //BIT 1 - 0-> INPUT, 1-> Output
	//	set=set|OSB_2; //BIT 2 - 0-> INPUT, 1-> Output
	//	set=set|OSB_3; //BIT 3 - 0-> INPUT, 1-> Output
	//	set=set|OSB_4; //BIT 4 - 0-> INPUT, 1-> Output
	//	set=set|OSB_5; //BIT 5 - 0-> INPUT, 1-> Output
	//	set=set|OSB_6; //BIT 6 - 0-> INPUT, 1-> Output
	//	set=set|OSB_7; //BIT 7 - 0-> INPUT, 1-> Output
	P0DIR = set;

	//Pull UP Mode	
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_1; //BIT 1 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_2; //BIT 2 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_3; //BIT 3  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_4; //BIT 4  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_5; //BIT 5  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_6; //BIT 6  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_7; //BIT 7  - 0: Pull-up / pull-down;  1: Tristate
	P0INP = set;

	//Interrupt Status Flag:
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_1; //BIT 1 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_2; //BIT 2 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_3; //BIT 3 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_4; //BIT 4 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_5; //BIT 5 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_6; //BIT 6 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_7; //BIT 7 - 0: No interrupt pending;  1: Interrupt pending
	 P0IFG = set;
#endif

#ifdef MOTBO
	//////////////////////////////////////////////
	// IO's	- P0;  PxSEL; PxDIR; PxINP; PxIFG;
	//////////////////////////////////////////////
	
	//Function Select: 0: General purpose I/O;  1: Peripheral function
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: General purpose I/O;  1: Peripheral function
		set=set|OSB_1; //BIT 1 - 0: General purpose I/O;  1: Peripheral function
		set=set|OSB_2; //BIT 2 - 0: General purpose I/O;  1: Peripheral function
		set=set|OSB_3; //BIT 3 - 0: General purpose I/O;  1: Peripheral function
		set=set|OSB_4; //BIT 4 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_5; //BIT 5 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_6; //BIT 6 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_7; //BIT 7 - 0: General purpose I/O;  1: Peripheral function
	P0SEL = set;

	//Direction Select
	set=0x00;	
		set=set|OSB_0; //BIT 0 - 0-> INPUT, 1-> Output
		set=set|OSB_1; //BIT 1 - 0-> INPUT, 1-> Output
		set=set|OSB_2; //BIT 2 - 0-> INPUT, 1-> Output
		set=set|OSB_3; //BIT 3 - 0-> INPUT, 1-> Output
		set=set|OSB_4; //BIT 4 - 0-> INPUT, 1-> Output
		set=set|OSB_5; //BIT 5 - 0-> INPUT, 1-> Output
		set=set|OSB_6; //BIT 6 - 0-> INPUT, 1-> Output
		set=set|OSB_7; //BIT 7 - 0-> INPUT, 1-> Output
	P0DIR = set;

	//Pull UP Mode	
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_1; //BIT 1 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_2; //BIT 2 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_3; //BIT 3  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_4; //BIT 4  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_5; //BIT 5  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_6; //BIT 6  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_7; //BIT 7  - 0: Pull-up / pull-down;  1: Tristate
	P0INP = set;

	//Interrupt Status Flag:
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_1; //BIT 1 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_2; //BIT 2 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_3; //BIT 3 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_4; //BIT 4 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_5; //BIT 5 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_6; //BIT 6 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_7; //BIT 7 - 0: No interrupt pending;  1: Interrupt pending
	 P0IFG = set;
#endif

}

void dpa_init_sfr_02b_p1()
{
	unsigned char 
		set;
	
	//////////////////////////////////////////////
	// IO's	- P1;  PxSEL; PxDIR; PxINP; PxIFG;
	//////////////////////////////////////////////
	
	//Function Select: 0 - General purpose I/O;  1 - Peripheral function
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_1; //BIT 1 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_2; //BIT 2 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_3; //BIT 3 - 0: General purpose I/O;  1: Peripheral function
		set=set|OSB_4; //BIT 4 - 0: General purpose I/O;  1: Peripheral function
		set=set|OSB_5; //BIT 5 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_6; //BIT 6 - 0: General purpose I/O;  1: Peripheral function
	//	set=set|OSB_7; //BIT 7 - 0: General purpose I/O;  1: Peripheral function
	P1SEL = set;

	//Direction Select: 0 - General purpose I/O;  1 - Peripheral function
	set=0x00;	
		set=set|OSB_0; //BIT 0 - 0-> INPUT, 1-> Output
		set=set|OSB_1; //BIT 1 - 0-> INPUT, 1-> Output
		set=set|OSB_2; //BIT 2 - 0-> INPUT, 1-> Output
		set=set|OSB_3; //BIT 3 - 0-> INPUT, 1-> Output
		set=set|OSB_4; //BIT 4 - 0-> INPUT, 1-> Output
		set=set|OSB_5; //BIT 5 - 0-> INPUT, 1-> Output
	//	set=set|OSB_6; //BIT 6 - 0-> INPUT, 1-> Output
		set=set|OSB_7; //BIT 7 - 0-> INPUT, 1-> Output
	P1DIR = set;

	//Pull UP Mode
	//note that P1_1 and P1_0 do not have pull capability
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA 
	//	set=set|OSB_2; //BIT 2 	- 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_3; //BIT 3  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_4; //BIT 4  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_5; //BIT 5  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_6; //BIT 6  - 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_7; //BIT 7  - 0: Pull-up / pull-down;  1: Tristate
	P1INP = set;

	//Interrupt Status Flag: 0 - No interrupt pending;  1 - Interrupt pending
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_1; //BIT 1 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_2; //BIT 2 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_3; //BIT 3 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_4; //BIT 4 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_5; //BIT 5 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_6; //BIT 6 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_7; //BIT 7 - 0: No interrupt pending;  1: Interrupt pending
	P1IFG = set;
}

void dpa_init_sfr_02c_p2()
{
	unsigned char 
		set;

#ifdef NODE	
	//////////////////////////////////////////////
	// IO's	- P2; PxSEL; PxDIR; PxINP; PxIFG;
	//////////////////////////////////////////////
	
	//Function Select
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - P2_0: 0-> General purpose I/O, 1-> Peripheral function
	//	set=set|OSB_1; //BIT 1 - P2_1: 0-> General purpose I/O, 1-> Peripheral function
	//	set=set|OSB_2; //BIT 2 - P2_2: 0-> General purpose I/O, 1-> Peripheral function
	//	set=set|OSB_3; //BIT 3 - 0 USART0 has priority; 1 Timer 1 has priority
	//	set=set|OSB_4; //BIT 4 - 0 Timer 1 has priority; 1 Timer 4 has priority
	//	set=set|OSB_5; //BIT 5 - 0 USART1 has priority; 1 Timer 3 has priority
	//	set=set|OSB_6; //BIT 6 - 0 USART0 has priority; 1 USART1 has priority
	//	set=set|OSB_7; //BIT 7 - NA
	P2SEL = set;

	//Direction Select
	set=0x00;	
		set=set|OSB_0; //BIT 0 - 0-> INPUT, 1-> Output
		set=set|OSB_1; //BIT 1 - 0-> INPUT, 1-> Output
	//	set=set|OSB_2; //BIT 2 - 0-> INPUT, 1-> Output
	//	set=set|OSB_3; //BIT 3 - 0-> INPUT, 1-> Output
	//	set=set|OSB_4; //BIT 4 - 0-> INPUT, 1-> Output
	//	set=set|OSB_5; //NA
	//	set=set|OSB_6; 	//		[7:6] - Port 0 peripheral priority contro
	//	set=set|OSB_7; 	//		00 	USART0 - USART1
	P2DIR = set;		//		01 	USART1 - USART0
			            //		10 	Timer 1 channels 0 and 1 - USART1
						//		11 	Timer 1 channel 2 - USART0

	//Pull UP Mode
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 	- P2_0 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_1; //BIT 1 	- P2_1 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_2; //BIT 2 	- P2_2 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_3; //BIT 3  - P2_3 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_4; //BIT 4  - P2_4 -> 0: Pull-up / pull-down;  1: Tristate
		set=set|OSB_5; //BIT 5  - Port 0 pull-up/down select; 0: Pull-up; 1: Pull-down
	//	set=set|OSB_6; //BIT 6  - Port 1 pull-up/down select; 0: Pull-up; 1: Pull-down
	//	set=set|OSB_7; //BIT 7  - Port 2 pull-up/down select; 0: Pull-up; 1: Pull-down
	P2INP = set;

	//Interrupt Status Flag: 0 - No interrupt pending;  1 - Interrupt pending
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_1; //BIT 1 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_2; //BIT 2 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_3; //BIT 3 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_4; //BIT 4 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	P2IFG = set;
#endif

#ifdef MOTBO
	//////////////////////////////////////////////
	// IO's	- P2; PxSEL; PxDIR; PxINP; PxIFG;
	//////////////////////////////////////////////
	
	//Function Select
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - P2_0: 0-> General purpose I/O, 1-> Peripheral function
	//	set=set|OSB_1; //BIT 1 - P2_1: 0-> General purpose I/O, 1-> Peripheral function
	//	set=set|OSB_2; //BIT 2 - P2_2: 0-> General purpose I/O, 1-> Peripheral function
	//	set=set|OSB_3; //BIT 3 - 0 USART0 has priority; 1 Timer 1 has priority
	//	set=set|OSB_4; //BIT 4 - 0 Timer 1 has priority; 1 Timer 4 has priority
	//	set=set|OSB_5; //BIT 5 - 0 USART1 has priority; 1 Timer 3 has priority
	//	set=set|OSB_6; //BIT 6 - 0 USART0 has priority; 1 USART1 has priority
	//	set=set|OSB_7; //BIT 7 - NA
	P2SEL = set;

	//Direction Select
	set=0x00;	
		set=set|OSB_0; //BIT 0 - 0-> INPUT, 1-> Output
		set=set|OSB_1; //BIT 1 - 0-> INPUT, 1-> Output
	//	set=set|OSB_2; //BIT 2 - 0-> INPUT, 1-> Output
	//	set=set|OSB_3; //BIT 3 - 0-> INPUT, 1-> Output
	//	set=set|OSB_4; //BIT 4 - 0-> INPUT, 1-> Output
	//	set=set|OSB_5; //NA
	//	set=set|OSB_6; 	//		[7:6] - Port 0 peripheral priority contro
	//	set=set|OSB_7; 	//		00 	USART0 - USART1
	P2DIR = set;		//		01 	USART1 - USART0
			            //		10 	Timer 1 channels 0 and 1 - USART1
						//		11 	Timer 1 channel 2 - USART0

	//Pull UP Mode
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 	- P2_0 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_1; //BIT 1 	- P2_1 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_2; //BIT 2 	- P2_2 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_3; //BIT 3  - P2_3 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_4; //BIT 4  - P2_4 -> 0: Pull-up / pull-down;  1: Tristate
	//	set=set|OSB_5; //BIT 5  - Port 0 pull-up/down select; 0: Pull-up; 1: Pull-down
	//	set=set|OSB_6; //BIT 6  - Port 1 pull-up/down select; 0: Pull-up; 1: Pull-down
		set=set|OSB_7; //BIT 7  - Port 2 pull-up/down select; 0: Pull-up; 1: Pull-down
	P2INP = set;

	//Interrupt Status Flag: 0 - No interrupt pending;  1 - Interrupt pending
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_1; //BIT 1 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_2; //BIT 2 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_3; //BIT 3 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_4; //BIT 4 - 0: No interrupt pending;  1: Interrupt pending
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	P2IFG = set;

#endif

}

void dpa_init_sfr_02d_port_generic()
{
	unsigned char 
		set;
#ifdef NODE	
	//////////////////////////////////////////////
	// IO's	- PERCFG; ADCCFG; P1CTL; P1IEN;
	//////////////////////////////////////////////
	
	//LOCATION SELECT
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - USART0 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_1; //BIT 1 - USART1 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - TIMER4 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_5; //BIT 5 - TIMER3 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_6; //BIT 6 - TIMER1 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_7; //BIT 7 - NA
	PERCFG = set;


	//ADC Input Configuration
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_1; //BIT 1 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_2; //BIT 2 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_3; //BIT 3 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_4; //BIT 4 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_5; //BIT 5 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_6; //BIT 6 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_7; //BIT 7 - 0: ADC input disabled; 1: ADC input enabled
	ADCCFG = set;

	// Port Interrupt Control  (SEE PG 100)
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 
	//	set=set|OSB_1; //BIT 1 - 
	//	set=set|OSB_2; //BIT 2 - 
	//	set=set|OSB_3; //BIT 3 - 
	//	set=set|OSB_4; //BIT 4 - 
	//	set=set|OSB_5; //BIT 5 - 
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	PICTL = set;

	// Port 1 Interrupt Mask
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_1; //BIT 1 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_2; //BIT 2 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_3; //BIT 3 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_4; //BIT 4 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_5; //BIT 5 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_6; //BIT 6 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_7; //BIT 7 - 0: Interrupts are disabled; 1: Interrupts are enabled
	P1IEN = set;

#endif

#ifdef MOTBO
	//////////////////////////////////////////////
	// IO's	- PERCFG; ADCCFG; P1CTL; P1IEN;
	//////////////////////////////////////////////
	
	//LOCATION SELECT
	set = 0x00;	
		set=set|OSB_0; //BIT 0 - USART0 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_1; //BIT 1 - USART1 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - TIMER4 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_5; //BIT 5 - TIMER3 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_6; //BIT 6 - TIMER1 location - 0: loc 1; 1: loc 2; 									
	//	set=set|OSB_7; //BIT 7 - NA
	PERCFG = set;


	//ADC Input Configuration
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: ADC input disabled; 1: ADC input enabled
		set=set|OSB_1; //BIT 1 - 0: ADC input disabled; 1: ADC input enabled
		set=set|OSB_2; //BIT 2 - 0: ADC input disabled; 1: ADC input enabled
		set=set|OSB_3; //BIT 3 - 0: ADC input disabled; 1: ADC input enabled
		set=set|OSB_4; //BIT 4 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_5; //BIT 5 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_6; //BIT 6 - 0: ADC input disabled; 1: ADC input enabled
	//	set=set|OSB_7; //BIT 7 - 0: ADC input disabled; 1: ADC input enabled
	ADCCFG = set;

	// Port Interrupt Control  (SEE PG 100)
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 
	//	set=set|OSB_1; //BIT 1 - 
	//	set=set|OSB_2; //BIT 2 - 
	//	set=set|OSB_3; //BIT 3 - 
	//	set=set|OSB_4; //BIT 4 - 
	//	set=set|OSB_5; //BIT 5 - 
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	PICTL = set;

	// Port 1 Interrupt Mask
	set = 0x00;	
	//	set=set|OSB_0; //BIT 0 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_1; //BIT 1 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_2; //BIT 2 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_3; //BIT 3 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_4; //BIT 4 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_5; //BIT 5 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_6; //BIT 6 - 0: Interrupts are disabled; 1: Interrupts are enabled
	//	set=set|OSB_7; //BIT 7 - 0: Interrupts are disabled; 1: Interrupts are enabled
	P1IEN = set;

#endif

}
