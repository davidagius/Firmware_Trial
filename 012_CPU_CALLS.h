#ifdef NODE
void dpa_pm2()
{
  	 char 
		set;	
	

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
		set=set|OSB_7; //BIT 7 - OSC32K	 1 -> RC, 0 -> XTAL
	CLKCON = set;

	//THIS PROCEDURE IS ONLY VALID FOR WOREVT < VALUE SET IN INIT
	// VALUE SET IN INIT IS 65535

	//WORCTL MANTISSA SET TO 11(15) IN INIT
	
	
	WORCTL |= 0x04; // Reset Sleep Timer
	

	set = WORTIME0;
	while(set == WORTIME0); // Wait until a positive 32 kHz edge
	set = WORTIME0;
	while(set == WORTIME0); // Wait until a positive 32 kHz edge

	WOREVT1 = 0x0E;
	WOREVT0 = 0x10;  
					
//	SLEEP = (SLEEP & 0xFC) | 0x01;	  //ENTER PM1


//	//=============
//	// SLEEP - 0xBE
//	//==============
	set=SLEEP;
		set=set|OSB_0; //BIT 0 - MODE 0
//	//	set=set|OSB_1; //BIT 1 - MODE 1
//	//	set=set|OSB_2; //BIT 2 - OSC_PD
//	//	set=set|OSB_3; //BIT 3 - RST0
//	//	set=set|OSB_4; //BIT 4 - RST1
//	//	set=set|OSB_5; //BIT 5 - HFRC_STB
//	//	set=set|OSB_6; //BIT 6 - XOSC_STB
//	//	set=set|OSB_7; //BIT 7 - USB_EN
	SLEEP = set;


	_nop_ ();
	_nop_ ();
	_nop_ ();
	if (SLEEP  & 0x03)
	{
		PCON |= 0x01;
		_nop_ ();
	}


} 
#endif