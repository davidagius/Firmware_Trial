void dpa_isr00 (void) interrupt 9 //TIMER X
{
	//flag cleared by HW - CHECK PG 64
	// called each 100us


	// -----------------------------------------------------
	// PWM

	#ifdef DEBUG
	// -----------------------------------------------------
	// PWM
	pwm_count_glob += 1;	
	if (pwm_count_glob==pwm_duty_cycle_glob) 
	{	
		pwm_output_lo();
	}
	
	if (pwm_count_glob>=pwm_base_glob) 
	{	
		pwm_output_hi();
		pwm_count_glob = 0;				
	}
	#endif


	// -----------------------------------------------------	
	//5000 * 100us = 500ms
	if (latch00_rfrx_synth==0) 
	{
		latch00_count -= 1;
		if (latch00_count==0) latch00_rfrx_synth = 1;
	}


	// -----------------------------------------------------	
	//5000 * 100us = 500ms
	if (latch01_generic==0) 
	{
		latch01_count -= 1;
		if (latch01_count==0) latch01_generic = 1;
	}


	// -----------------------------------------------------		
	if (latch02_sdi==0) //dedicated to SDI
	{		
		//self resetting counter
		latch02_count += 1;	//SDI timing base, 1 = 100us
	  	sdi_write();
		sdi_read();
	}

	// -----------------------------------------------------	
	//5000 * 100us = 500ms
	if (latch03_sensor_delay==0) 
	{
		latch03_count -= 1;
		if (latch03_count==0) latch03_sensor_delay = 1;	
	}
	
	// -----------------------------------------------------	
	//5000 * 100us = 500ms
	if (latch05_sensor_rfrx_timeout==0) 
	{
		latch05_count2 -= 1;

		if (latch05_count2==0) 
		{
			latch05_count2 = TIMER_MULT;
			latch05_count -= 1;
			if (latch05_count==0) 
			{
				latch05_sensor_rfrx_timeout = 1;	
			}
		}
	}

	// -----------------------------------------------------	
	if (latch06_rainfall_check==0) 
	{
		latch06_count -= 1;
		if (latch06_count==0) latch06_rainfall_check = 1;	
	}	
}


void dpa_isrxx (void) interrupt 5 //sleep timer
{
//	char
//		set;
//	//////////////////////////////////////////////
//	// IRCON
//	//////////////////////////////////////////////
//	set=IRCON;
//	//	set=set|OSB_0; //BIT 0 - DMA complete interrupt flag.
//	//	set=set|OSB_1; //BIT 1 - Timer 1 interrupt flag. Set to 1 when Timer 1 interrupt occurs and cleared when CPU
//						//		vectors to the interrupt service routine.
//	//	set=set|OSB_2; //BIT 2 - Timer 2 interrupt flag. Set to 1 when Timer 2 interrupt occurs and cleared when CPU
//					//			vectors to the interrupt service routine.
//	//	set=set|OSB_3; //BIT 3 - Timer 3 interrupt flag. Set to 1 when Timer 3 interrupt occurs and cleared when CPU
//						//		vectors to the interrupt service routine.
//	//	set=set|OSB_4; //BIT 4 - Timer 4 interrupt flag. Set to 1 when Timer 4 interrupt occurs and cleared when CPU
//					//			vectors to the interrupt service routine.
//	//	set=set|OSB_5; //BIT 5 - Port 0 interrupt flag
//	//	set=set|OSB_6; //BIT 6 - Reserved. Must always be set to 0. Failure to do so will lead to ISR toggling
//		set=set|OSB_7; //BIT 7 - STIF
//	STIF = 0;

	
//  	WORIRQ &= 0xFE;
//  	SLEEP &= 0xFC;
}
