//-------------------------------------------------------------------------------
//PAYLOAD LOAD RF MSG
//-------------------------------------------------------------------------------
#ifdef MOTBO
void dpa_payload_load_rf_req_sdi_data(int destadd)
{
	glob_data[0] = 5;
	glob_data[1] = destadd; //ADD
	glob_data[2] = 65; //A
	glob_data[3] = 80; //P
	glob_data[4] = 68; //D
	glob_data[5] = 68; //D
}

void dpa_payload_load_rf_req_led_blink(int destadd)
{
	glob_data[0] = 5;
	glob_data[1] = destadd; //ADD
	glob_data[2] = 66; //B
	glob_data[3] = 66; //B
	glob_data[4] = 66; //B
	glob_data[5] = 66; //B
}

void dpa_payload_load_rf_req_node_bat(int destadd)
{
	glob_data[0] = 5;
	glob_data[1] = destadd; //ADD
	glob_data[2] = 67; //C
	glob_data[3] = 67; //C
	glob_data[4] = 67; //C
	glob_data[5] = 67; //C
}
#endif


#ifdef NODE

void dpa_payload_load_rf_req_motbo_pair(int destadd)
{
	glob_data[0] = 5;
	glob_data[1] = destadd; //ADD
	glob_data[2] = 69; //E
	glob_data[3] = 69; //E
	glob_data[4] = 69; //E
	glob_data[5] = 69; //E
}

void dpa_payload_load_rf_from_sdi(unsigned int data_in_sz, unsigned int destadd)
{
	unsigned int
		cnt_01,
		cnt_02;

	//SHIFT ALL CONTENTS UP, NEW SIZE = (data_in_sz + 2), IE LAST BYTE IN ARRAY = glob_data[data_in_sz+1] = destadd; //ADD
	cnt_02 = data_in_sz;
	cnt_02 -= 1;
	cnt_01 = cnt_02;

	while (cnt_02>0)
	{
		glob_data[cnt_02+2] = glob_data[cnt_02];
		cnt_02--;
	}
	glob_data[0] = data_in_sz+1;
	glob_data[1] = destadd; //ADD
	glob_data[2] = 	0x4E; //N

	glob_data[data_in_sz] = 0x0D;
	glob_data[data_in_sz+1] = 0x0A;

}
void dpa_payload_load_rf_from_block(unsigned int data_in_sz, unsigned int destadd)
{
	int
		cnt_02;

	cnt_02 = data_in_sz - 1;
	//SHIFT ALL CONTENTS UP, NEW SIZE = (data_in_sz + 2), IE LAST BYTE IN ARRAY = glob_data[data_in_sz+1] = destadd; //ADD
	while (cnt_02>-1)
	{
		glob_data[cnt_02+2] = glob_data[cnt_02];
		cnt_02--;
	}
	glob_data[0] = data_in_sz+3; //adding address + 0x0D + 0x0A
	glob_data[1] = destadd; //ADD
	glob_data[data_in_sz+2] = 0x0D;
	glob_data[data_in_sz+3] = 0x0A;

}


void dpa_payload_loadmsg_rf_mark_n(unsigned int in,unsigned int destadd)
{
	glob_data[0] = 8;
	glob_data[1] = destadd; //ADD
	glob_data[2] = 	0x4E; //N
	glob_data[3] = 	0x5F; //_


	glob_data[5] = 	0x0D; //carrige return
	glob_data[6] = 	0x0A; //line feed

	if (in<10)
	{
		glob_data[4] = 	0x30; // 0
		glob_data[5] = 	0x30; // 0
		glob_data[6] = 	(0x30)+in;
	}
	if ((in>9)&&(in<100))
	{
		glob_data[4] = 	0x30; // 0
		glob_data[5] = 	(unsigned short int) ((float)(in/10));
		glob_data[6] = 	(0x30)+(unsigned short int) ((float)(in-(glob_data[5]*10)));

		glob_data[5] += 0x30;
	}

	if ((in>99)&&(in<1000))
	{

		glob_data[4] = 	(unsigned short int) ((float)(in/100));
		glob_data[5] = 	(unsigned short int) ((float)((in-(glob_data[4]*100))/10));
		glob_data[6] = 	(unsigned short int) ((float)(in-(glob_data[4]*100)-(glob_data[5]*10)));

		glob_data[4] += 0x30;
		glob_data[5] += 0x30;
		glob_data[6] += 0x30;

	}

	glob_data[7] = 0x0D;
	glob_data[8] = 0x0A;

}
#endif

//-------------------------------------------------------------------------------
//PAYLOAD LOAD UART MSG
//-------------------------------------------------------------------------------
#ifdef MOTBO
void dpa_payload_loadmsg_motbo_on()
{
	glob_data[0] = 	0x4D; //M
	glob_data[1] = 	0x42; //o
	glob_data[2] = 	0x5F; //_
	glob_data[3] = 	0x4F; //O
	glob_data[4] = 	0x4E; //N
	glob_data[5] = 	0x0D; //carrige return
	glob_data[6] = 	0x0A; //line feed
}

void dpa_payload_loadmsg_mark_n(unsigned int in)
{
	glob_data[0] = 	0x4D; //M
	glob_data[1] = 	0x5F; //_


	glob_data[5] = 	0x0D; //carrige return
	glob_data[6] = 	0x0A; //line feed

	if (in<10)
	{
		glob_data[2] = 	0x30; // 0
		glob_data[3] = 	0x30; // 0
		glob_data[4] = 	(0x30)+in;
	}
	if ((in>9)&&(in<100))
	{
		glob_data[2] = 	0x30; // 0
		glob_data[3] = 	(unsigned short int) ((float)(in/10));
		glob_data[4] = 	(unsigned short int) (in-(glob_data[3]*10));

		glob_data[3] += 0x30;
		glob_data[4] += 0x30;
	}

	if ((in>99)&&(in<1000))
	{

		glob_data[2] = 	(unsigned short int) ((float)(in/100));
		glob_data[3] = 	(unsigned short int) ((float)((in-(glob_data[2]*100))/10));
		glob_data[4] = 	(unsigned short int) ((float)(in-(glob_data[2]*100)-(glob_data[3]*10)));

		glob_data[2] += 0x30;
		glob_data[3] += 0x30;
		glob_data[4] += 0x30;

	}

}
#endif

//-------------------------------------------------------------------------------
//PAYLOAD CHECK RF MSG
//-------------------------------------------------------------------------------
#ifdef MOTBO
bit dpa_payload_check_rf_req_motbo_pair()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[2] == 69);
	data_ok = data_ok && (glob_data[3] == 69);
	data_ok = data_ok && (glob_data[4] == 69);
	data_ok = data_ok && (glob_data[5] == 69);

	return data_ok;
}
#endif

#ifdef NODE
bit dpa_payload_check_rf_req_sdi_data()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[2] == 65);
	data_ok = data_ok && (glob_data[3] == 80);
	data_ok = data_ok && (glob_data[4] == 68);
	data_ok = data_ok && (glob_data[5] == 68);

	return data_ok;
}

bit dpa_payload_check_rf_req_led_blink()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[2] == 66);
	data_ok = data_ok && (glob_data[3] == 66);
	data_ok = data_ok && (glob_data[4] == 66);
	data_ok = data_ok && (glob_data[5] == 66);

	return data_ok;
}

bit dpa_payload_check_rf_req_node_bat()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[2] == 67);
	data_ok = data_ok && (glob_data[3] == 67);
	data_ok = data_ok && (glob_data[4] == 67);
	data_ok = data_ok && (glob_data[5] == 67);

	return data_ok;
}
#endif
//-------------------------------------------------------------------------------
//PAYLOAD CHECK UART MSG
//-------------------------------------------------------------------------------
#ifdef MOTBO
bit dpa_payload_check_uart_req_sensor_data(unsigned char *dest_address)
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x41);  //A
	data_ok = data_ok && (glob_data[2] == 0x31 ); //1
	data_ok = data_ok && (glob_data[6] == 13 );	

	*dest_address = glob_data[5] - 0x30;
	*dest_address += (glob_data[4] - 0x30)*10;
	*dest_address += (glob_data[3] - 0x30)*100;


	return data_ok;
}

bit dpa_payload_check_uart_req_sensor2_data()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x41);  //A
	data_ok = data_ok && (glob_data[2] == 0x32 ); //2
	data_ok = data_ok && (glob_data[3] == 13 );	

	return data_ok;
}

bit dpa_payload_check_uart_req_sensor3_data()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x41);  //A
	data_ok = data_ok && (glob_data[2] == 0x33 ); //3
	data_ok = data_ok && (glob_data[3] == 13 );	

	return data_ok;
}

bit dpa_payload_check_uart_req_sensor4_data()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x41);  //A
	data_ok = data_ok && (glob_data[2] == 0x34 ); //4
	data_ok = data_ok && (glob_data[3] == 13 );	

	return data_ok;
}

bit dpa_payload_check_uart_req_sensor5_data()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x41);  //A
	data_ok = data_ok && (glob_data[2] == 0x35 ); //5
	data_ok = data_ok && (glob_data[3] == 13 );	

	return data_ok;
}

bit dpa_payload_check_uart_req_diag01()	   //MOTBO BATTERY VOLTAGE
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x42);  //B
	data_ok = data_ok && (glob_data[2] == 0x31 ); //1
	data_ok = data_ok && (glob_data[3] == 13 );	

	return data_ok;
}

bit dpa_payload_check_uart_req_led_blink(unsigned char *dest_address)
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x42);  //B
	data_ok = data_ok && (glob_data[2] == 0x32 ); //2
	data_ok = data_ok && (glob_data[6] == 13 );	

	*dest_address = glob_data[5] - 0x30;
	*dest_address += (glob_data[4] - 0x30)*10;
	*dest_address += (glob_data[3] - 0x30)*100;

	return data_ok;
}

bit dpa_payload_check_uart_req_node_bat(unsigned char *dest_address)		  //NODE BATTERY VOLTAGE
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x42);  //B
	data_ok = data_ok && (glob_data[2] == 0x33 ); //3
	data_ok = data_ok && (glob_data[6] == 13 );	

	*dest_address = glob_data[5] - 0x30;
	*dest_address += (glob_data[4] - 0x30)*10;
	*dest_address += (glob_data[3] - 0x30)*100;
	
	return data_ok;
}


bit dpa_payload_check_diagnostics()
{
	bit
		data_ok = 1;

	data_ok = data_ok && (glob_data[1] == 0x42);  //B
	data_ok = data_ok && (glob_data[2] == 0x34 ); //4
	data_ok = data_ok && (glob_data[3] == 13 );	

	return data_ok;
}
#endif
//-------------------------------------------------------------------------------
//PAYLOAD MISC
//-------------------------------------------------------------------------------

void dpa_payload_clear()
{
	char
		cnt_01 = 0;

	while (cnt_01<BUFFER_SIZE)
	{
		glob_data[cnt_01] = 0x00;
		cnt_01++;
	}
}





