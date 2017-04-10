
void sdi_write()
{
	switch (latch02_count)
	{
		//case used due to irregular intervals caused by 830us delay not divisible into 100us
		//setting timer lower than 100us will cause problems
		case 1: 	// break - 12ms
		{

			sdi_set_io_output();
			sdi_out_hi();
		}
		break;

		case 120: 	//mark 8.3ms
		{
			sdi_out_lo();
			sdi_parity = 0;
			glob_data_pos = 0;
		}
		break;

		case 258: //	 start bit
		{
			sdi_out_hi();
			sdi_parity = 0;
		}
		break;

		case (266): //	 data bit 0
		{
			if ((glob_data[glob_data_pos]&OSB_0)==OSB_0)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 275: //	 data bit 1
		{
		   	if ((glob_data[glob_data_pos]&OSB_1)==OSB_1)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 283: //	 data bit 2
		{
			if ((glob_data[glob_data_pos]&OSB_2)==OSB_2)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 291: //	 data bit 3
		{
		   	if ((glob_data[glob_data_pos]&OSB_3)==OSB_3)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 300: //	 data bit 4
		{
		   	if ((glob_data[glob_data_pos]&OSB_4)==OSB_4)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 309: //	 data bit 5
		{
		   	if ((glob_data[glob_data_pos]&OSB_5)==OSB_5)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 316: //	 data bit 6
		{
		   	if ((glob_data[glob_data_pos]&OSB_6)==OSB_6)
			{
				sdi_out_lo();
				sdi_parity ^= 1;
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 325: //	 parity bit
		{
			if (sdi_parity)
			{
				sdi_out_lo();
		   	}
		   	else
			{
				sdi_out_hi();
		   	}
		}
		break;

		case 333: //	start of stop bit.
		{
			sdi_out_lo();
		}
		break;

		case 341: //	 end of stop bit.
		{
			glob_data_pos += 1;
			if (glob_data_pos < sdi_data_sz_out)
			{
				//restart reading
				latch02_count = 257;
			}
			else
			{
				glob_data_pos = 0;
				glob_data[glob_data_pos] = 0x7F;
				sdi_bit_num = 0;
				sdi_set_io_input();
			}
		}
		break;

		case 500: 		//stop bit + 15ms = 341 + 150
		{
			//in normal circumstances value will jump from 380 -> 2000, and will never reach 500
			//no data received in 15ms
			latch02_sdi = 1;
			latch02_count = 0;
			sdi_data_sz_in_max = 0;
			sdi_data_sz_in_actual = 0;
		}
		break;

		default :
		{
			//
		}
		break;
	}
}
void sdi_read()
{
	#ifdef SDI_DIRECT
	//read data
	//stop bit + 8.33ms = 341 + 80
	if ((latch02_count>380)&&(latch02_count<2000))//8.3ms
	{
		//wait for sensor respone
		//glob_data[glob_data_pos] = P0;
		bit01 =  sdi_in();
		if (bit01)
		{
			//begining of response - start bit
			latch02_count = 2000;
			sdi_offset = SDI_READ_OFFSET;
		}
	}
	#endif

	#ifdef SDI_BUFFER_PULLUP
	// error introduced when using p82b96 due to pull up, start bit 0-1 transition not identified
	//solution:
	//assume fist byte is always 0 (0x30)
	//[(START),	(D0),	(D1),	(D2),	(D3),	(D4),	(D5),	(D6),	(EVEN-PAR),	(STOP) ]
	//[ 1		1		1		1		1		0		0		1		1			0	]
	//for byte 0, search for start bit @ 1-0 transition
	//for byte > 0, search for start bit normally (stop bit always 0)

	if ((latch02_count>380)&&(latch02_count<2000))//8.3ms
	{
		//wait for sensor respone
		bit01 =  sdi_in();
		if ((sdi_bit_num==0)&&(glob_data_pos==0))
		{
			if (bit01==0)
			{
				//begining of D4
				latch02_count = 2000; //shifted 2 read cycles, so that next read
				sdi_offset = SDI_READ_OFFSET;
				sdi_bit_num += 5;
			}
		}
		else
		{
			if (bit01)
			{
				//begining of response - start bit
				latch02_count = 2000;
				sdi_offset = SDI_READ_OFFSET;
			}
		}
	}

	#endif


	if (latch02_count>=((int)sdi_offset+2000))//read
	{
		// 0 -> start bit
		bit01 = sdi_in();

		if (((sdi_bit_num>0)&&(sdi_bit_num<8))&&bit01)
		{
			glob_data[glob_data_pos] ^= (1<<(sdi_bit_num-1));
		}

		if (sdi_bit_num==9)
		{
			if (!sdi_eol_reached) 
				sdi_data_sz_in_actual += 1;		
			
			if	(sdi_data_sz_in_actual>sdi_data_sz_in_max) 
				sdi_data_sz_in_actual=sdi_data_sz_in_max;

			if (glob_data_pos>0)
			{
				if ((glob_data[glob_data_pos-1]==0x0D)&&(glob_data[glob_data_pos]==0x0A))
				{
					sdi_eol_reached = 1;					
				}
			}			

			//end of byte transmission
			sdi_bit_num = 0;
			glob_data_pos +=1;

			if (glob_data_pos<sdi_data_sz_in_max)
			{
				//resync with star bit
				glob_data[glob_data_pos] = 0x7f;
				latch02_count = 381;
			}
			else
			{					
				//end of packet
				latch02_sdi = 1;
				latch02_count = 0;
			}
		}
		else
		{
			sdi_bit_num	+= 1;
		}

		sdi_offset += SDI_PERIOD;
	}
}
