void dpa_init_sfr_03_timer_1()
{
	unsigned char 
		set;	
	//////////////////////////////////////////////
	// TIMER - 1
	//////////////////////////////////////////////

	//=============
	// T1 Counters - x
	//=============
	T1CNTH = 0;
	T1CNTL = 0;

	//=============
	// T1CTL - x
	//=============
	set=T1CTL;	
	//	set=set|OSB_0; //BIT 0 - Timer 1 mode select. BIT 0
		set=set|OSB_1; //BIT 1 - Timer 1 mode select. BIT 1
	
						//Timer 1 mode select. The timer operating mode is selected as follows:
						//00 Operation is suspended
						//01 Free-running, repeatedly count from 0x0000 to 0xFFFF
						//10 Modulo, repeatedly count from 0x0000 to T1CC0
						//11 Up/down, repeatedly count from 0x0000 to T1CC0 and from T1CC0 down to
	
	//	set=set|OSB_2; //BIT 2 - Prescaler divider value. BIT 0
	//	set=set|OSB_3; //BIT 3 - Prescaler divider value. BIT 1
	//	set=set|OSB_4; //BIT 4 - Timer 1 counter overflow interrupt flag.
	//	set=set|OSB_5; //BIT 5 - Timer 1 channel 0 interrupt flag
	//	set=set|OSB_6; //BIT 6 - Timer 1 channel 1 interrupt flag
	//	set=set|OSB_7; //BIT 7 - Timer 1 channel 2 interrupt flag
	T1CTL = set;

	//========================================	
	// T1CCTL0 - x
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - Channel 0 capture mode select. BIT 0
	//	set=set|OSB_1; //BIT 1 - Channel 0 capture mode select. BIT 1
	//	set=set|OSB_2; //BIT 2 - Mode. Select Timer 1 channel 0 capture or compare mode
	//	set=set|OSB_3; //BIT 3 - Channel 0 compare mode select. BIT 0 Selects action on output when timer 
					  //		value equals compare value in T1CC0
	//	set=set|OSB_4; //BIT 4 - Channel 0 compare mode select. BIT 1 
	//	set=set|OSB_5; //BIT 5 - Channel 0 compare mode select. BIT 2
		set=set|OSB_6; //BIT 6 - Channel 0 interrupt mask
	//	set=set|OSB_7; //BIT 7 - Timer 1 channel 0 capture select
	T1CCTL0 = set;

	//=============
	// T1 - Channel 0 Capture/Compare - x
	//=============
	T1CC0H = 127;
	T1CC0L = 255;
	//========================================

	//========================================	
	// T1CCTL1 - x
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T1CCTL1 = set;

	//=============
	// T1 - Channel 1 Capture/Compare - x
	//=============
	T1CC1H = 0;
	T1CC1L = 0;
	//========================================

	//========================================
	// T1CCTL2 - x
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T1CCTL2 = set;

	//=============
	// T1 - Channel 2 Capture/Compare - x
	//=============
	T1CC2H = 0;
	T1CC2L = 0;
	//========================================
 }
 void dpa_init_sfr_03_timer_2()
{
	unsigned char 
		set;	

	//////////////////////////////////////////////
	// TIMER - 2
	//////////////////////////////////////////////

	//========================================
	// T2CTL
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T2CTL = set;

	//=============
	// T2 - Timer 2 Count
	//=============
	T2CT = 0;

	//=============
	// T2 - Timer 2 Prescaler
	//=============
	T2PR = 0;
}

void dpa_init_sfr_03_timer_3()
{
	unsigned char 
		set;	

	//////////////////////////////////////////////
	// TIMER - 3
	//////////////////////////////////////////////
	
	//=============
	// T3 - Timer 3 Counter - x
	//=============
	T3CNT = 0;

	//=============
	// T3CTL - Timer 3 Control
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T3CTL = set;

	//========================================
	// T3CCTL0 - Timer 3 Channel 0 Compare Control
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T3CCTL0 = set;

	//=============
	// T3 - Timer 3 Ch 0 Compare
	//=============
	T3CC0 = 0;
	//========================================

	//========================================
	// T3CCTL1 - Timer 3 Channel 1 Compare Control
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T3CCTL1 = set;

	//=============
	// T3 - Timer 3 Ch 1 Compare
	//=============
	T3CC1 = 0;
	//========================================
}
void dpa_init_sfr_03_timer_4()
{
	unsigned char 
		set;	

	//////////////////////////////////////////////
	// TIMER - 4
	//////////////////////////////////////////////
	
	//=============
	// T4 - Timer 4 counter
	//=============
	T4CNT = 0;

	//=============
	// T4CTL - Timer 4 Control
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T4CTL = set;

	//========================================
	// T4CCTL0 - Timer 4 Channel 0 Compare Control
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T4CCTL0 = set;
	
	//=============
	// T4 - Timer 4 Channel 0 Compare Value
	//=============
	T4CC0 = 0;
	//========================================
	
	//========================================
	// T4CCTL1 - Timer 4 Channel 0 Compare Control
	//=============
	set=0x00;	
	//	set=set|OSB_0; //BIT 0 - NA
	//	set=set|OSB_1; //BIT 1 - NA
	//	set=set|OSB_2; //BIT 2 - NA
	//	set=set|OSB_3; //BIT 3 - NA
	//	set=set|OSB_4; //BIT 4 - NA
	//	set=set|OSB_5; //BIT 5 - NA
	//	set=set|OSB_6; //BIT 6 - NA
	//	set=set|OSB_7; //BIT 7 - NA
	T4CCTL1 = set;
	
	//=============
	// T4 - Timer 4 Channel 0 Compare Value
	//=============
	T4CC1 = 0;
	//========================================
}

void dpa_init_sfr_03_timer_all()
{
	unsigned char 
		set;	
	
	//////////////////////////////////////////////
	// TIMIF
	//////////////////////////////////////////////
	set=TIMIF;	
	//	set=set|OSB_0; //T3OVFIF BIT 0 - Timer 3 overflow interrupt flag. Writing a 1 has no effect
	//	set=set|OSB_1; //T3CH0IF BIT 1 - Timer 3 channel 0 interrupt flag. Writing a 1 has no effect
	//	set=set|OSB_2; //T3CH1IF BIT 2 - Timer 3 channel 1 interrupt flag. Writing a 1 has no effect
	//	set=set|OSB_3; //T4OVFIF BIT 3 - Timer 4 overflow interrupt flag. Writing a 1 has no effect
	//	set=set|OSB_4; //T4CH0IF BIT 4 - Timer 4 channel 0 interrupt flag. Writing a 1 has no effect
	//	set=set|OSB_5; //T4CH1IF BIT 5 - Timer 4 channel 1 interrupt flag. Writing a 1 has no effect
		set=set|OSB_6; //OVFIM BIT 6 - Timer 1 overflow interrupt mask
	//	set=set|OSB_7; //BIT 7 - NA
	TIMIF = set;

} 
#ifdef NODE	
void dpa_init_sfr_03_timer_sleep_wake_up()
{
	unsigned char 
		set;	
	
	//////////////////////////////////////////////
	// 
	//////////////////////////////////////////////

	WOREVT1 = 25;
	WOREVT0 = 12; // 10 MINS ON T-RC

	//////////////////////////////////////////////
	// WORCTL
	//////////////////////////////////////////////
	set=0x00;	
		set=set|OSB_0; //	[1:0]	Sleep Timer resolution
		set=set|OSB_1; //
	//	set=set|OSB_2; // 	Reset timer. The timer will be reset to 4.
	//	set=set|OSB_3; // 	Not used
	//	set=set|OSB_4; //	[6:4] Reserved. Always write 000
	//	set=set|OSB_5; //
	//	set=set|OSB_6; //
	//	set=set|OSB_7; //	Not used
	WORCTL = set;


	//////////////////////////////////////////////
	// WORIRQ
	//////////////////////////////////////////////
//	set=WORIRQ;	
//	//	set=set|OSB_0; //  EVENT0_FLAG
//	//	set=set|OSB_1; //
//	//	set=set|OSB_2; //
//	//	set=set|OSB_3; //
//		set=set|OSB_4; //  EVENT0_MASK
//	//	set=set|OSB_5; //  Reserved. Always write 0
//	//	set=set|OSB_6; //
//	//	set=set|OSB_7; //
	WORIRQ |= OSB_4;

} 
#endif

void dpa_init_sfr_03_timer_watchdog()
{
	unsigned char 
		set;	
	
	
	//////////////////////////////////////////////
	// WDCTL
	//////////////////////////////////////////////
	set=0x00;	
	//	set=set|OSB_0; 	//INT[1:0]
	//	set=set|OSB_1; 	
	//	set=set|OSB_2; 	//MODE
		set=set|OSB_3; 	//EN
	//	set=set|OSB_4; 	//CLR[3:0]
	//	set=set|OSB_5; 
	//	set=set|OSB_6; 
	//	set=set|OSB_7; 
	WDCTL = set;	 

} 
	