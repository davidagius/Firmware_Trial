#ifdef DEBUG
void led_0(bit in)
{
	P1_0 = in;
}

void led_1(bit in)
{
	P1_1 = in;
}


void pwm_output_hi()
{
	P1_1 = 1;
}

void pwm_output_lo()
{
	P1_1 = 0;
}
#endif


void led_brd(bit in)
{
	P1_3 = in;
}

void led_btn(bit in)
{
	P0_1 = in;
}

void pa_off()
{	
	P2_0 = 0;
}

void pa_on()
{	
	unsigned int 
		cnt01 = 65535;
	
	P2_0 = 1;
	
	while (cnt01>0) cnt01--;
}

void lna_off()
{	
	P2_1 = 0;
}

void lna_on()
{	
	unsigned int 
		cnt01 = 65535;

	P2_1 = 1;

	while (cnt01>0) cnt01--;
}


#ifdef NODE
void boost_off()
{	
//	clear_p1b2(); //TURN OFF BOOST
	P1_2 = 0;
}

void boost_on()
{	
//	set_p1b2(); //TURN OFF BOOST
	P1_2 = 1;
}
#endif

#ifdef SDI_P11	// VIA EXTERNAL BUFFER
void sdi_out_hi()
{	
	P1_1 = 1;
}

void sdi_out_lo()
{	
	P1_1 = 0;
}

bit sdi_in()
{	
	return P1_1;
}

void sdi_set_io_input()
{	
	char
		set;
	set = P1DIR;
	set = set&OCB_1; //set P1_1 to INPUT
	P1DIR = set;
	
	set = P1INP;
	set = set|OSB_1; //set P1_1 to tristate
	P1INP = set;
						
	set = P1;
	set = set&OCB_1; //clear P0_0
	P1 = set;
}

void sdi_set_io_output()
{	
	char
		set;

	set = P1DIR;
	set = set|OSB_1; //set P1_1 to OUTPUT
	P1DIR = set;
	
	set = P1INP;
	set = set&OCB_1; //set P1_1 to pu/pd //NO PU AVAILABLE, LEFT HERE FOR CONSISTENCY VISAVI P0
	P1INP = set;
}
#endif

#ifdef SDI_P00	// VIA ANALOG
void sdi_out_hi()
{	
	P0_0 = 1;
}


void sdi_out_lo()
{	
	P0_0 = 0;
}

bit sdi_in()
{	
	return P0_0;
}

void sdi_set_io_input()
{	
	char
		set;
	set = P0DIR;
	set = set&OCB_0; //set P0_0 to INPUT
	P0DIR = set;
	
	set = P0INP;
	set = set|OSB_0; //set P0_0 to tristate
	P0INP = set;
						
	set = P0;
	set = set&OCB_0; //clear P0_0
	P0 = set;
}

void sdi_set_io_output()
{	
	char
		set;

	set = P0DIR;
	set = set|OSB_0; //set P0_0 to OUTPUT
	P0DIR = set;
	
	set = P0INP;
	set = set&OCB_0; //set P0_0 to pu/pd				
	P0INP = set;
}
#endif

#ifdef MOTBO
bit rainfallgetbit()
{	
	bit
		p16;
	
	char
		set1a, set2a,set1b, set2b;

	set1a = P1DIR;
	set1b = set1a;
	set1a = set1a&OCB_6; //set P1_6 to INPUT
	P1DIR = set1a;
	
	set2a = P1INP;
	set2b = set2a;
	set2a = set2a&OCB_6; //set P1_6 to pu/pd				
	P1INP = set2a;

	p16 =	((P1&OSB_6)==OSB_6);

	P1DIR = set1b;
	P1INP = set2b;

	return p16;
}
#endif