void dpa_set_timer_period_us(int period_us)
{	
	double
		  double_01;
	unsigned short int		  //16bit
		count_01;

	double_01 = period_us * XOSC_MHZ;	 		
	count_01 = (unsigned short int)  double_01;
	T1CC0H = (char)(count_01>>8);
	T1CC0L = (char)(count_01);
}

dpa_clear_wdt()
{
	unsigned char 
		set;	
	 
	//WRITE 1010 TO CLR[3:0]		

	set=WDCTL;	
	//	set=set|OSB_0; 	//INT[1:0]
	//	set=set|OSB_1; 	
	//	set=set|OSB_2; 	//MODE
	//	set=set|OSB_3; 	//EN
		set=set&OCB_4; 	//CLR[3:0]
		set=set|OSB_5; 
		set=set&OCB_6; 
		set=set|OSB_7; 
	WDCTL = set;


	//WRITE 0101 TO CLR[3:0]	
	//	set=set|OSB_0; 	//INT[1:0]
	//	set=set|OSB_1; 	
	//	set=set|OSB_2; 	//MODE
	//	set=set|OSB_3; 	//EN
		set=set|OSB_4; 	//CLR[3:0]
		set=set&OCB_5; 
		set=set|OSB_6; 
		set=set&OCB_7; 
	WDCTL = set;  	
	

} 
	