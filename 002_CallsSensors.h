#ifdef NODE
void decagon_5te_send_meas_req()
{

	//send measurement request

//	sdi_data_sz_out = 2;
//	sdi_data_sz_in_max = 3;
//	sdi_data_sz_in_actual = 0;
//	glob_data[0] = 0x3F; // ?
//	glob_data[1] = 0x21; // !

	dpa_payload_clear ();
	glob_data_pos = 0;
	sdi_eol_reached = 0;

	sdi_data_sz_out = 3;
	sdi_data_sz_in_max = 7;
	sdi_data_sz_in_actual = 0;
	glob_data[0] = 0x30; // 0
	glob_data[1] = 0x4D; // M
	glob_data[2] = 0x21; // !

	//initiate SDI comms
	latch02_sdi = 0;
	while(latch02_sdi==0);

	glob_data_pos = 0;
}

void decagon_5te_get_data()
{

	dpa_payload_clear();

	//SDI COMMAND: read SDI data
	glob_data[0] = 0x30; // 0
	glob_data[1] = 0x44; // D
	glob_data[2] = 0x30; // 0
	glob_data[3] = 0x21; // !

	glob_data_pos = 0;
	sdi_eol_reached = 0;
	sdi_data_sz_out = 4;
	sdi_data_sz_in_max = 19;
	sdi_data_sz_in_actual = 0;

	//initiate SDI comms
	latch02_sdi = 0;
	while(latch02_sdi==0);

}
int return_adc_bat()
{
	int
		data_out;

	unsigned char
		data_lo, data_hi, sfr_get;
	float
		mv,per;

	//
	sfr_get = 0x00;
		sfr_get=sfr_get|OSB_0; //BIT 0 		  	[3:0] input select
		sfr_get=sfr_get|OSB_1; //BIT 1
		sfr_get=sfr_get|OSB_2; //BIT 2
		sfr_get=sfr_get|OSB_3; //BIT 3

		sfr_get=sfr_get|OSB_4; //BIT 4 			[5:4] Decimation Rate (11 = 12bit)
		sfr_get=sfr_get|OSB_5; //BIT 5

	//	sfr_get=sfr_get|OSB_6; //BIT 6 		  	[7:6] Selects reference voltage (00 - INTERNAL 1.25V REF)
	//	sfr_get=sfr_get|OSB_7; //BIT 7
	ADCCON3 =  sfr_get;	//(56)


	sfr_get = ADCCON1;
	while ((sfr_get&OSB_7)==0x00)
	{
		sfr_get = ADCCON1;
	}

	data_lo = ADCL;
	data_hi = ADCH;

	if (data_hi == (data_hi&OCB_7))
	{
		//+ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);

	}
	else
	{
		//-ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);
		data_out = 2047 - data_out;
		data_out = data_out * -1;
	}
	//	data_out -> 0-2047
	//CONVERT TO mV
	mv = (data_out*1.25)/2.047;
	data_out = (int) mv;
	
	return data_out;
}


#endif

#ifdef MOTBO
void decagon_vp3_send_meas_req()
{
	//send measurement request

//	sdi_data_sz_out = 2;
//	sdi_data_sz_in_max = 3;
//	sdi_data_sz_in_actual = 0;
//	glob_data[0] = 0x3F; // ?
//	glob_data[1] = 0x21; // !

	dpa_payload_clear ();
	glob_data_pos = 0;
	sdi_eol_reached = 0;

	sdi_data_sz_out = 3;
	sdi_data_sz_in_max = 7;
	sdi_data_sz_in_actual = 0;
	glob_data[0] = 0x30; // 0
	glob_data[1] = 0x4D; // M
	glob_data[2] = 0x21; // !

	//initiate SDI comms
	latch02_sdi = 0;
	while(latch02_sdi==0);
}

void decagon_vp3_get_data()
{
	dpa_payload_clear();

	//SDI COMMAND: read SDI data
	glob_data[0] = 0x30; // 0
	glob_data[1] = 0x44; // D
	glob_data[2] = 0x30; // 0
	glob_data[3] = 0x21; // !

	glob_data_pos = 0;
	sdi_eol_reached = 0;
	sdi_data_sz_out = 4;
	sdi_data_sz_in_max = 19;
	sdi_data_sz_in_actual = 0;

	//initiate SDI comms
	latch02_sdi = 0;
	while(latch02_sdi==0);

}
 /*
void decagon_generic_send_meas_req()
{
	//send measurement request

//	sdi_data_sz_out = 2;
//	sdi_data_sz_in_max = 3;
//	sdi_data_sz_in_actual = 0;
//	glob_data[0] = 0x3F; // ?
//	glob_data[1] = 0x21; // !

	dpa_payload_clear ();
	glob_data_pos = 0;

	sdi_data_sz_out = 3;
	sdi_data_sz_in_max = 7;
	sdi_data_sz_in_actual = 0;
	glob_data[0] = 0x30; // 0
	glob_data[1] = 0x4D; // M
	glob_data[2] = 0x21; // !

	//initiate SDI comms
	latch02_sdi = 0;
	while(latch02_sdi==0);
}

void decagon_generic_get_data()
{
	dpa_payload_clear();

	//SDI COMMAND: read SDI data
	glob_data[0] = 0x30; // 0
	glob_data[1] = 0x44; // D
	glob_data[2] = 0x30; // 0
	glob_data[3] = 0x21; // !

	glob_data_pos = 0;
	sdi_data_sz_out = 4;
	sdi_data_sz_in_max = 19;
	sdi_data_sz_actual = 0;

	//initiate SDI comms
	latch02_sdi = 0;
	while(latch02_sdi==0);

}
*/

bit rainfallgetbit();

void check_rainfall()
{

	if (latch06_rainfall_check)
   	{
   		//on every 1ms
		latch06_count = 10; //reload for next 1ms
		latch06_rainfall_check = 0;

		if (rainfallgetbit())
		{
			latch06_count = 10000; // increase delay to 1s
			rainfall_counter += 1;
			if	(rainfall_counter==100)	 rainfall_counter = 0; //cycle between 0 - 99;
		}

   }
}



int return_adc_lws()
{
	int
		data_out;

	unsigned char
		data_lo, data_hi, sfr_get;
	float
		mv,per;

	//
	sfr_get = 0x00;
		sfr_get=sfr_get|OSB_0; //BIT 0 		  	[3:0] input select
	//	sfr_get=sfr_get|OSB_1; //BIT 1
	//	sfr_get=sfr_get|OSB_2; //BIT 2
	//	sfr_get=sfr_get|OSB_3; //BIT 3

		sfr_get=sfr_get|OSB_4; //BIT 4 			[5:4] Decimation Rate (11 = 12bit)
		sfr_get=sfr_get|OSB_5; //BIT 5

	//	sfr_get=sfr_get|OSB_6; //BIT 6 		  	[7:6] Selects reference voltage (00 - INTERNAL 1.25V REF)
	//	sfr_get=sfr_get|OSB_7; //BIT 7
	ADCCON3 =  sfr_get;	//(56)


	sfr_get = ADCCON1;
	while ((sfr_get&OSB_7)==0x00)
	{
		sfr_get = ADCCON1;
	}

	data_lo = ADCL;
	data_hi = ADCH;

	if (data_hi == (data_hi&OCB_7))
	{
		//+ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);

	}
	else
	{
		//-ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);
		data_out = 2047 - data_out;
		data_out = data_out * -1;
	}
	//	data_out -> 0-2047
	//CONVERT TO mV
	mv = (data_out*1.25)/2.047;
	data_out = (int) mv;
	per = (mv - LWS_MIN);
	per /= (LWS_MAX - LWS_MIN);
	per *= 100;

	if (per < 0)
		per = 0;

	if (per > 100)
		per = 100;

	data_out = (int)per;
	
	return data_out;
}
/*
int return_adc_etsv()
{
	int
		data_out;

	unsigned char
		data_lo, data_hi, sfr_get;
	float
		mv;

	//
	sfr_get = 0x00;
		sfr_get=sfr_get|OSB_0; //BIT 0 		  	[3:0] input select
	//	sfr_get=sfr_get|OSB_1; //BIT 1 				[AIN 2 - 3]
	//	sfr_get=sfr_get|OSB_2; //BIT 2
		sfr_get=sfr_get|OSB_3; //BIT 3

		sfr_get=sfr_get|OSB_4; //BIT 4 			[5:4] Decimation Rate (11 = 12bit)
		sfr_get=sfr_get|OSB_5; //BIT 5

	//	sfr_get=sfr_get|OSB_6; //BIT 6 		  	[7:6] Selects reference voltage (00 - INTERNAL 1.25V REF)
	//	sfr_get=sfr_get|OSB_7; //BIT 7
	ADCCON3 =  sfr_get;	//(56)


	sfr_get = ADCCON1;
	while ((sfr_get&OSB_7)==0x00)
	{
		sfr_get = ADCCON1;
	}

	data_lo = ADCL;
	data_hi = ADCH;

	if (data_hi == (data_hi&OCB_7))
	{
		//+ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);

	}
	else
	{
		//-ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);
		data_out = 2047 - data_out;
		data_out = data_out * -1;
	}
	//	data_out -> 0-2047
	//CONVERT TO mV
	mv = (data_out*1.25)/2.047;
	data_out = (int) mv;
	return data_out;
}
*/

float return_adc_ets()
{
	int
		data_out;

	unsigned char
		data_lo, data_hi, sfr_get;
	float
		degc, r_shunt;

	//
	sfr_get = 0x00;
		sfr_get=sfr_get|OSB_0; //BIT 0 		  	[3:0] input select (AIN2-AIN3)
	//	sfr_get=sfr_get|OSB_1; //BIT 1
	//	sfr_get=sfr_get|OSB_2; //BIT 2
		sfr_get=sfr_get|OSB_3; //BIT 3

		sfr_get=sfr_get|OSB_4; //BIT 4 			[5:4] Decimation Rate (11 = 12bit)
		sfr_get=sfr_get|OSB_5; //BIT 5

	//	sfr_get=sfr_get|OSB_6; //BIT 6 		  	[7:6] Selects reference voltage (00 - INTERNAL 1.25V REF)
	//	sfr_get=sfr_get|OSB_7; //BIT 7
	ADCCON3 =  sfr_get;	//(56)


	sfr_get = ADCCON1;
	while ((sfr_get&OSB_7)==0x00)
	{
		sfr_get = ADCCON1;
	}

	data_lo = ADCL;
	data_hi = ADCH;

	if (data_hi == (data_hi&OCB_7))
	{
		//+ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);
		

	}
	else
	{
		//-ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);
		
		data_out = 2047 - data_out;
		data_out = data_out * -1;

	}
	
	//	data_out -> -2048 <-> 2047; EQV TO -Vref <-> Vref
	//	0mA -> 0ºC; 20mA -> 10ºC
	//	degc = ((((data_out/2047)*1.25V)/R_SHUNT)/20ma)*10ºC;
	//	= data_out*(1.25V*10ºC)/(R_SHUNT*20ma*10ºC*2047)
	//	= data_out*(125)/(R_SHUNT * 0.2 * 2047)
	//	= data_out*0.3053248656/r_shunt
	// SUSPECT: current will NOT FLOW FROM DEVICE if reading below 0degC

	r_shunt = 56;
	
	degc = data_out*0.3053248656/r_shunt;	


	return degc;
}

float return_adc_diag()
{
	int
		data_out;

	unsigned char
		data_lo, data_hi, sfr_get;
	float
		mv,out;

	//
	sfr_get = 0x00;
	//	sfr_get=sfr_get|OSB_0; //BIT 0 		  	[3:0] input select
	//	sfr_get=sfr_get|OSB_1; //BIT 1
		sfr_get=sfr_get|OSB_2; //BIT 2
	//	sfr_get=sfr_get|OSB_3; //BIT 3

		sfr_get=sfr_get|OSB_4; //BIT 4 			[5:4] Decimation Rate (11 = 12bit)
		sfr_get=sfr_get|OSB_5; //BIT 5

	//	sfr_get=sfr_get|OSB_6; //BIT 6 		  	[7:6] Selects reference voltage (00 - INTERNAL 1.25V REF)
	//	sfr_get=sfr_get|OSB_7; //BIT 7
	ADCCON3 =  sfr_get;	//(56)


	sfr_get = ADCCON1;
	while ((sfr_get&OSB_7)==0x00)
	{
		sfr_get = ADCCON1;
	}

	data_lo = ADCL;
	data_hi = ADCH;

	if (data_hi == (data_hi&OCB_7))
	{
		//+ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);

	}
	else
	{
		//-ve number
		data_hi = (data_hi&OCB_7);
		data_out = data_hi;
		data_out = data_out<<4;
		data_out += (data_lo>>4);
		data_out = 2047 - data_out;
		data_out = data_out * -1;
	}
	//	data_out -> 0-2047
	//CONVERT TO mV
	//mv = (data_out*1.25)/2.047;
	// OUT = (data_out * 1.25 / 2.047) / 1000 (mv ->V) / 1 (R_PD) * 12 (R_PD + R_PU)
	out = (data_out * 0.00732779677576941866145578895945);
	
	return out;
}
#endif