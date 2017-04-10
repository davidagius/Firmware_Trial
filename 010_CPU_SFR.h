void dpa_init_sfr_01a_pclocks()
{
	unsigned char
		set;

	//////////////////////////////////////////////
	// Power and Clocks- 12.1
	//////////////////////////////////////////////

	//=============
	// PCON - 0x87
	//==============
//	set=PCON;
	//	set=set|OSB_0; //BIT 0 - IDLE
	//	set=set|OSB_1; //BIT 1 - Reserved
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
		set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
//	PCON = set;

	//=============
	// SLEEP - 0xBE
	//==============
//	set=SLEEP;
	//	set=set|OSB_0; //BIT 0 - MODE 0
	//	set=set|OSB_1; //BIT 1 - MODE 1
	//	set=set|OSB_2; //BIT 2 - OSC_PD
	//	set=set|OSB_3; //BIT 3 - RST0
	//	set=set|OSB_4; //BIT 4 - RST1
	//	set=set|OSB_5; //BIT 5 - HFRC_STB
	//	set=set|OSB_6; //BIT 6 - XOSC_STB
	//	set=set|OSB_7; //BIT 7 - USB_EN
//	SLEEP = set;



	//=============
	// CLKCON
	//==============
	set = 0x00;
	//	set=set|OSB_0; //BIT 0 - CLKSPD BIT 0
	//	set=set|OSB_1; //BIT 1 - CLKSPD BIT 1
	//	set=set|OSB_2; //BIT 2 - CLKSPD BIT 2
	//	set=set|OSB_3; //BIT 3 - TICKSPD BIT 0
	//	set=set|OSB_4; //BIT 4 - TICKSPD BIT 1
	//	set=set|OSB_5; //BIT 5 - TICKSPD BIT 2
	//	set=set|OSB_6; //BIT 6 - OSC
	//	set=set|OSB_7; //BIT 7 - OSC32K
	CLKCON = set;

	//WAIT FOR XTAL OSC TO BE STABLE
	set = SLEEP;
	while ((set&OSB_6)!=OSB_6)
	{
		set = SLEEP;
	}

}

void dpa_init_sfr_01b_interrupts()
{
	unsigned char
		set;

	//////////////////////////////////////////////
	// IEN0
	//////////////////////////////////////////////
	set=0x00;
		set=set|OSB_0; //BIT 0 - RF TX/RX done interrupt enable
	//	set=set|OSB_1; //BIT 1 - ADC interrupt enable
		set=set|OSB_2; //BIT 2 - USART0 RX interrupt enable
	//	set=set|OSB_3; //BIT 3 - USART1 RX interrupt enable / I2S RX interrupt enable
	//	set=set|OSB_4; //BIT 4 - AES encryption/decryption interrupt enable
		set=set|OSB_5; //BIT 5 - Sleep Timer interrupt enable
	//	set=set|OSB_6; //BIT 6 - NA
		set=set|OSB_7; //BIT 7 - EA
	IEN0 = set;

	//////////////////////////////////////////////
	// IEN1
	//////////////////////////////////////////////
	set=IEN1;
	//	set=set|OSB_0; //BIT 0 - DMA transfer interrupt enable
		set=set|OSB_1; //BIT 1 - Timer 1 interrupt enable
	//	set=set|OSB_2; //BIT 2 - Timer 2 interrupt enable
	//	set=set|OSB_3; //BIT 3 - Timer 3 interrupt enable
	//	set=set|OSB_4; //BIT 4 - Timer 4 interrupt enable
	//	set=set|OSB_5; //BIT 5 - Port 0 interrupt enable
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	IEN1 = set;


	//////////////////////////////////////////////
	// IEN2
	//////////////////////////////////////////////
	set=IEN2;
		set=set|OSB_0; //BIT 0 - RF general interrupt enable
	//	set=set|OSB_1; //BIT 1 - Port 2 interrupt enable (Also used for USB interrupt enable on CC1111Fx)
		set=set|OSB_2; //BIT 2 - USART0 TX interrupt enable
	//	set=set|OSB_3; //BIT 3 - USART1 TX interrupt enable / I2S TX interrupt enable
	//	set=set|OSB_4; //BIT 4 - Port 1 interrupt enable
	//	set=set|OSB_5; //BIT 5 - Watchdog timer interrupt enable
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	IEN2 = set;


	//////////////////////////////////////////////
	// TCON
	//////////////////////////////////////////////
	set=TCON;
	//	set=set|OSB_0; //BIT 0 - Reserved. Must always be set to 1.
	//	set=set|OSB_1; //BIT 1 - RF TX/RX complete interrupt flag. Set to 1 when RFTXRX interrupt occurs and
					  //		cleared when CPU vectors to the interrupt service routine.
	//	set=set|OSB_2; //BIT 2 - Reserved. Must always be set to 1.
	//	set=set|OSB_3; //BIT 3 - USART0 RX interrupt flag. Set to 1 when USART0 interrupt occurs and cleared
					  //		when CPU vectors to the interrupt service routine.

	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - ADC interrupt flag. Set to 1 when ADC interrupt occurs and cleared when CPU
					  // 		vectors to the interrupt service routine.
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - USART1 RX interrupt flag / I2S RX interrupt flag
					  //		Set to 1 when USART1 RX int
	TCON = set;

	//////////////////////////////////////////////
	// S0CON
	//////////////////////////////////////////////
	set=S0CON;
	//	set=set|OSB_0; //BIT 0 - ENCIF
	//	set=set|OSB_1; //BIT 1 - ENCIF_1
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	S0CON = set;


	//////////////////////////////////////////////
	// S1CON
	//////////////////////////////////////////////
	set=S1CON;
	//	set=set|OSB_0; //BIT 0 - RFIF_0
	//	set=set|OSB_1; //BIT 1 - RFIF_1
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	S1CON = set;

	//////////////////////////////////////////////
	// IRCON
	//////////////////////////////////////////////
	set=IRCON;
	//	set=set|OSB_0; //BIT 0 - DMA complete interrupt flag.
	//	set=set|OSB_1; //BIT 1 - Timer 1 interrupt flag. Set to 1 when Timer 1 interrupt occurs and cleared when CPU
						//		vectors to the interrupt service routine.
	//	set=set|OSB_2; //BIT 2 - Timer 2 interrupt flag. Set to 1 when Timer 2 interrupt occurs and cleared when CPU
					//			vectors to the interrupt service routine.
	//	set=set|OSB_3; //BIT 3 - Timer 3 interrupt flag. Set to 1 when Timer 3 interrupt occurs and cleared when CPU
						//		vectors to the interrupt service routine.
	//	set=set|OSB_4; //BIT 4 - Timer 4 interrupt flag. Set to 1 when Timer 4 interrupt occurs and cleared when CPU
					//			vectors to the interrupt service routine.
	//	set=set|OSB_5; //BIT 5 - Port 0 interrupt flag
	//	set=set|OSB_6; //BIT 6 - Reserved. Must always be set to 0. Failure to do so will lead to ISR toggling
	//	set=set|OSB_7; //BIT 7 - STIF
	IRCON = set;

	//////////////////////////////////////////////
	// IRCON 2
	//////////////////////////////////////////////
	set=IRCON2;
	//	set=set|OSB_0; //BIT 0 - P2IF / 	USBIF
	//	set=set|OSB_1; //BIT 1 - UTX0IF
	//	set=set|OSB_2; //BIT 2 - UTX1IF	/I2STXIF
	//	set=set|OSB_3; //BIT 3 - P1IF
	//	set=set|OSB_4; //BIT 4 - WDTIF
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	IRCON2 = set;

	//////////////////////////////////////////////
	// IP1 - Interrupt Priority 1
	//////////////////////////////////////////////
	set=0x00;
		set=set|OSB_0; //BIT 0 - IP1_IPG0
	//	set=set|OSB_1; //BIT 1 - IP1_IPG1
	//	set=set|OSB_2; //BIT 2 - IP1_IPG2
	//	set=set|OSB_3; //BIT 3 - IP1_IPG3
	//	set=set|OSB_4; //BIT 4 - IP1_IPG4
	//	set=set|OSB_5; //BIT 5 - IP1_IPG5
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	IP1 = set;


	//////////////////////////////////////////////
	// IP0 - Interrupt Priority 1
	//////////////////////////////////////////////
	set=0x00;
		set=set|OSB_0; //BIT 0 - IP0_IPG0
	//	set=set|OSB_1; //BIT 1 - IP0_IPG1
	//	set=set|OSB_2; //BIT 2 - IP0_IPG2
	//	set=set|OSB_3; //BIT 3 - IP0_IPG3
	//	set=set|OSB_4; //BIT 4 - IP0_IPG4
	//	set=set|OSB_5; //BIT 5 - IP0_IPG5
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	IP0 = set;

}


