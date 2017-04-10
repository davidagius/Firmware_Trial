void dpa_int2ascii(int data_in)
{	
	dpa_payload_clear();

	if (data_in>=0)
		glob_data[0] = 0x2B; //+
	else
	{		
		glob_data[0] = 0x2D; //-
		data_in = data_in * -1;
	}

	glob_data[1] = (unsigned short int) data_in/1000;
	data_in -= glob_data[1] * 1000;
	glob_data[1] += 0x30;

	glob_data[2] = (unsigned short int) data_in/100;
	data_in -= glob_data[2] * 100;
	glob_data[2] += 0x30;

	glob_data[3] = (unsigned short int) data_in/10;
	data_in -= glob_data[3] * 10;
	glob_data[3] += 0x30;

	glob_data[4] = (unsigned short int) data_in;
	glob_data[4] += 0x30;

}

#ifdef MOTBO
void dpa_float2ascii(float data_in)
{	
	//only good for total 4 digit output including decimal point
	// ie 99.9 max
	dpa_payload_clear();

	if (data_in>=0)
		glob_data[0] = 0x2B; //+
	else
	{		
		glob_data[0] = 0x2D; //-
		data_in = data_in * -1;
	}



	glob_data[1] = (unsigned short int) data_in/10;
	data_in -= glob_data[1] * 10;
	glob_data[1] += 0x30;

	glob_data[2] = (unsigned short int) data_in;
	data_in -= glob_data[2];
	glob_data[2] += 0x30;

	glob_data[3] = 0x2E;

	glob_data[4] = (unsigned short int) ((float)(data_in*10));
	glob_data[4] += 0x30;

}
#endif
void dpa_pm2();
void dpa_init_sfr_03_timer_watchdog();

#ifdef NODE
void dpa_invoke_sleep_and_reset()
{

	dpa_pm2();
	dpa_init_sfr_03_timer_watchdog(); //WHEN WAKEUP ENABLE WDT AND GO INFINITE LOOP

//	//////////////////////////////////////////////
//	// WDCTL
//	//////////////////////////////////////////////
//	set=0x00;	
//		set=set|OSB_0; 	//INT[1:0]
//	//	set=set|OSB_1; 	
//	//	set=set|OSB_2; 	//MODE
//		set=set|OSB_3; 	//EN
//	//	set=set|OSB_4; 	//CLR[3:0]
//	//	set=set|OSB_5; 
//	//	set=set|OSB_6; 
//	//	set=set|OSB_7; 
//	WDCTL = set;

	while (1) {}
}

void check_button_press_change_CMD_STATUS()
{
	bit
		bit02;
	
	bit02 = P0_0;
 
 	if (bit02)
	{
		if (PAIR_IN_PROG==0)
		{
			debounce_counter++;
	
			if (debounce_counter>1000)
			{
				current_command = CMD_RFTX_SEND_DATA_PAIR;
				debounce_counter = 0;
				PAIR_IN_PROG = 1;
				time_before_sleep_counter = 0;
			}
		}
	}
	else
	{
		debounce_counter = 0;
	}
	bit02 = 0;

}


#endif