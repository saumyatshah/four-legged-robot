/*
 * MR2.cpp
 *
 * Created: 25-02-2019 21:19:42
 * Author : Admin
 */ 




#include "COMMON.h"

#define baud 9600
#define UBBR 103UL//((F_CPU/(16*baud))-1)
ISR(TIMER0_OVF_vect);
//ISR(TIMER2_OVF_vect);




int main(void)
{
	//DDRB|= (1<<(DDB1));
	
	SPI_Init(Master,MSB_first,rise,leading,By64);         //SPI_Init(uint8_t Mode,uint8_t data_order,uint8_t clk_pol,uint8_t clk_phase,uint8_t clk_rate)
	
	
	set(PORTB2);		//DDRB =0XFF;
	///ONLY FOR PPR UART
	/* 
	ConfigUART(COM0,UBBR,_TX,WORD_LENGTH_8,STOP_BIT_1,none);
	UBRRH=0;
	UBRRL=103UL;
	
	*/
	
	
	///////////////////////////imp
	DDRA = 0b10011100;//0b11111100; FOR LCD AND SWITCH//0X00; WHEN USING SWITCHES AND ULTRASONIC
	//DDRC = 0b11111100;
	
	
	//PORTA = 0b11100100;//0xFE;FOR LCD AND SWITCH
	//PORTC = 0xfc;
	///////////////////////////
	/////////////////IMP
	DDRC |= 0xFF; 
	//DDRA |= 0b11100100;
	////////////////
	
	DDRB|=0x04;
	//PORTA |=0b01111000;//0b01101100;
	
	
	DDRD = 0xF0;
	//D0-1 UART, D2-3 GPIO INT ,D4-6 MUX S0 S1 ,D5-7 HIGH FOR FUTURE PWM DAC PPR PURPOSE
	//
	PORTD |= 0b00001100;
	
	PORTC = 0xfE;
	ConfigLcd(Rs,en,d4,d5,d6,d7);
	
	ConfigUART(COM0,UBBR,_RX,WORD_LENGTH_8,STOP_BIT_1,none);   //// BAUD RATE = 9600 is fixed for arduino communication  DO NOT CHANGE THE UBBR
	UBRRL = 103UL;
	UBRRH= 0UL;

	//ConfigUART(COM0,7,_TX,WORD_LENGTH_8,STOP_BIT_1,none);   //// BAUD RATE = 9600 is fixed for arduino communication  DO NOT CHANGE THE UBBR
	waitms(100);
	timer2_init();
	sei();
	
	timer_init();
	waitms(50);
	//	timer2ultra_init();
	sei();
	
	//lcd((char*)"POINT");
	lowerline();
	lcd((char*)"TEAM INDIA 2019");
	// lcd(attempt);
	waitms(100);
	ang=0;

	//Enable(ADC);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//==========================================	SHERU JUMP================================================///////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool last=0;
	bool r=0,l=0,flag=0,flag_1=0,flag_2=0,flag_3=0,END_PROXY=1,END_PROXY2=1,MOUNTAIN=1,LIMIT_switch,SLOPE=0,i_switch=0;
	short int count_1=0,RUK_r=0,RUK_l=0,t_jump=0,flag_turn=0,ULTRA=0,flag_turnL=0,flag_turnR=0,sand=0,flag_90=0,go = 1,N_jump=0,c_jump=0,k=0,i_local_3=0,i_local,i_local2,count=0;
	short int step=0,CONTINUE=0;
	//unsigned short ULTRA=0;
	double ANG_R[5]={0},ANG_L[5]={0};
	double ANG_R_2[5]={0},ANG_L_2[5]={0};
	short int dist_ultra1=0,dist_ultra2=0,dist_ultra3=0,dist_ultra4=0,initial_back=0,initial_side=0,initial_side2=0,initial_front=0;
	R_GEREGE = 1;//red;
	MOUNTAIN=0;
	/*
	set(L);
	waitms(1000);
	set(R);
	waitms(1000);
	set(U2);
	waitms(1000);
	set(G);
	waitms(1000);
	*/

		LASER=0;

		//waitms(50);
		//dist_ultra1 = laser(right);
		while(0)//dist_ultra1==0)
		{
			//cls();
			dist_ultra1 = laser(right);
			//lcd("R");
			//lcd(dist_ultra1);
			//k++;
		
		}
	
	while(0)
	{
		for (int j=0;j>=0;j++)
		{
			cls();
			lcd(j);
			waitms(1000);
		}
	}
	reset(U2);
		while(0)
		{            ////////////////////INCLUDE LASER LOOP & COMMENT LCD IN STRAIGHT_NEW
			for(int i=2;i<=12;i+=2)
			{
				KHADE_ANGLE_O(i,i);
				waitms(4000);
			}
			KHADE_ANGLE_O(15,15);
			KHADE_ANGLE_O(40,40);
			
			/*STRAIGHT_NEW(90,close);*/
			while(1)
			{
				
			}
		}
/*
	while (0)
	{
		for (int J=0;J<111;J++)
		{
			cls();
			lcd(J);
			waitms(500);
		}
		cls();
		lcd("heyy");
	}
	//reset(U2);
	//waitms(1000);
	
	lcd(MT);
	//waitms(1000);
	R_GEREGE = 1;//red;
	MOUNTAIN=0;
*/
//for all laser
		while(0)
	{
	cls();
	lcd(ang);
	}
	
	
	while (0)
	{
		//cls();
	//	lcd(213);
		
		laser(back);
		laser(back);
		laser(back);
		dist_ultra1=laser(back);
		lowerline();
		lcd(dist_ultra1);
		//lowerline();
		
	/*
		laser(left);
		laser(left);
		laser(left);
		dist_ultra3=laser(left);
		lcd(dist_ultra3);
		lowerline();
		laser(front);
		laser(front);
		laser(front);
		dist_ultra2=laser(front);
		lcd(dist_ultra2);
		lcd(" ");
		laser(right);
		laser(right);
		laser(right);
		dist_ultra2=laser(right);
		lcd(dist_ultra2);
		waitms(1000);
		//STRAIGHT_NEW(75,back,0,close);
		//while (1)
		//STRAIGHT_NEW(25,back,0,close);
	*/
	}
/*	
	while(0)
	{
		for (int q=40;q<90;q=q+10)
		{
			cls();
			STRAIGHT_DELAY = 72.05 + 1.993*(q);
			lcd(q);
			lowerline();
			lcd(STRAIGHT_DELAY);
			waitms(1000);
		}
	}
	/*
	set(L);
	waitms(56);
	set(R);
	waitms(181);//181);
	reset(L);
	reset(R);
	waitms(400);
	*/
	/*
	int prev_LASER=0;
	int BA=0;
	int diff=0;
	cls();
	laser(back);
	laser(back);
	dist_ultra1=laser(back);
	lcd((int)dist_ultra1);
	waitms(400);
	prev_LASER=dist_ultra1;
	set(R);
	waitms(80);
	reset(R);
	waitms(140);
	flag_turnL=1;
	flag_turnR=0;
	//count=0;
	
	while(0)
	{
		if(!BA)
		{
		
		cls();
		laser(back);
		laser(back);
		laser(back);
		dist_ultra1=laser(back);
		lcd(dist_ultra1);
		lcd(" ");
		lcd((prev_LASER-(int)dist_ultra1));
		lcd(" ");
		lcd(ang);
		waitms(1000);
		diff=prev_LASER-(int)dist_ultra1;
		
			if(flag_turnR)
			{
				set(L);
				waitms(60);//90
				reset(L);
				waitms(140);
				flag_turnR=1;
				flag_turnL=0;
			}
			else
			{
				set(R);
				waitms(60);//90);
				reset(R);
				waitms(140);
				flag_turnR=0;
				flag_turnL=1;
			}
			
		if(diff<-1)
		{
			int J=0;
			while(J<2)
			{	
				if(flag_turnR)
				{
					set(L);
					waitms(60);//90
					reset(L);
					waitms(140);
					flag_turnR=1;
					flag_turnL=0;
				}
				else
				{
					set(R);
					waitms(60);//90);
					reset(R);
					waitms(140);
					flag_turnR=0;
					flag_turnL=1;
				}
				J++;
			}
			BA=1;
			flag_turnL=!flag_turnL;
			flag_turnR=!flag_turnR;
		}
		
				
			
		
		prev_LASER=(int)dist_ultra1;
		
		}
		lcd(" ");
		lcd(ang);
	}
	while(1)
	{
		
	}
	while(1)
	{
	cls();
	
	f=0;
		while(f<3)
		{
			cls();
			laser(back);
			laser(back);
			laser(back);
			dist_ultra1=laser(back);
			lcd((int)dist_ultra1);
			waitms(400);
			lcd(" ");
			laser(right);
			laser(right);
			laser(right);
			dist_ultra1=laser(right);
			lcd((int)dist_ultra1);
			waitms(400);
			lcd(" ");
			lcd(ang);
			f++;
		}
		waitms(600);
	}
	*/
	/*
	while(1)
	{
		//STRAIGHT_NEW(75,back,0,open);
		
		//TUSSUK_NEW(left,0,open);
		//TUSSUK_NEW(left,0,close);
		//for (int I=15;I<97;I=I+10)
		//{

		//for (int j=86;j<97;j=j+10)
		{
			//for (k=2;k>0;k--)
			{
				
// 					set(L);
// 					waitms(j);
// 					set(R);
// 					waitms(0);//480-jjd);
// 					reset(L);
// 					reset(R);
// 					
				
				//Ultimate_jump_s(-51.9,j);
				KHADE_ANGLE(0,0);
				k=150;//350;//220;    //100 counts for 5 seconds
				while (k)
				{
					cls();
					lcd(ang,3);//Ultimate_jump_s(0,70);
					k--;
				}
				//ang=0;
				KHADE_ANGLE(0,0);
				//Ultimate_jump_s(30,j);
				k=150;//350;//220;    //100 counts for 5 seconds
				while (k)
				{
					cls();
					lcd(ang,3);//Ultimate_jump_s(0,70);
					k--;
				}
				//ang=0;
			}
		}
		//}
		while(1)
		{}
	}
	
/*

	while(0)
	{
			waitms(300);//400);
			//COORDINATE_STRAIGHT(138,right,0);
			S2T_NEW(right,0);
			waitms(300);
			cls();
			laser(front);
			laser(front);
			dist_ultra1 = laser(front);
			lcd((int)dist_ultra1);
			waitms(400);
			//KHADE_ANGLE_O(-45,-47);
			
				//KHADE_ANGLE_O(0,-1);
			
			while (1)
			{
				cls();
				lcd(ang,3);
			}
			
	}
	
	while (0)
	{
		laser(back);     ///necessary
		laser(back);
		while(f<3)
		{
			cls();
			dist_ultra1=laser(back);
			lcd((int)dist_ultra1);
			waitms(400);
			f++;
		}
		
		cls();
		dist_ultra1 = laser(back);
		lcd(dist_ultra1);
		lcd(" ");
		
		
		laser(left);
		laser(left);
		dist_ultra2 = laser(left);
		//lcd(dist_ultra2);
		lcd(" ");
		lcd(ang);
		waitms(1000);
		if (dist_ultra1<95)//88)
		{
			Ultimate_jump_s(0,100-dist_ultra1);
			laser(back);     ///necessary
			laser(back);
			dist_ultra1 = laser(back);
			lcd(dist_ultra1);
			lcd(" ");
			lcd(ang);
			//waitms(1000);
			
		}
		if(dist_ultra1>110)
		Ultimate_jump_s(0,85);
		else
		Ultimate_jump_s(0, 200-dist_ultra1);//185-dist_ultra1);
		Ultimate_jump_s(0,200 - dist_ultra1);//96+195-dist
		//STRAIGHT(96 + 105 - dist_ultra1,back,0);
		//Ultimate_jump_s(-45,87);
		while (1)
		{
			Ultimate_jump_s(0,10);
		}
	}
	
	*/
	
	//set(U2);  // for closing front legs
	//reset(U2);  // for opening front legs
	
	/*
	set(L);
	set(R);
	waitms(260);      //CHANGE DELAY HERE
	//set(U2);    ///if needed
	reset(L);
	reset(R);
	cls();
	lcd(ang,2);
	*/
	//lcd(dist_ultra1);
	
	/*
	while(0)
	{
	for(int j=0;j<800;j++)//int j=0;j<800;j++)
	{
		if (j<200)
		{
		cls();
		dist_ultra1= laser(1);
		lcd("L1");
		lcd(dist_ultra1);
		}
		
		else if(j<400)
		{
			cls();
			dist_ultra2= laser(2);
			lcd("L2");
			lcd(dist_ultra2);
		}
		else if(j<600)
		{
			cls();
			dist_ultra3= laser(3);
			lcd("L3");
			lcd(dist_ultra3);
		}
		else if(j<800)
		{
			cls();
			dist_ultra4= laser(4);
			lcd("L4");
			lcd(dist_ultra4);
		}
	}
	}
	
	while (0)
	{
		if (MT)
		{
			cls();
			dist_ultra4= laser(front);
			lcd("Lf");
			lcd(dist_ultra4,2);
		}
		else
		{
			cls();
			dist_ultra4= laser(back);
			lcd("Lb");
			lcd(dist_ultra4,2);
		}
	}
	while(0)//k<5)
	{
		//KHADE_ANGLE(0,0);
		//waitms(1000);
		lcd(ang,2);
		//waitms(1000);
		SLOPE_P_4(0);
		while(k<3)
		{
			cls();
			dist_ultra1=laser(back);
			lcd((int)dist_ultra1);
			//waitms(400);
			k++;
		}
		k=0;
		dist_ultra1=laser(back);
		lcd((int)dist_ultra1);
		waitms(500);
		//KHADE_ANGLE_O(-20,-21);
	}
	
	while (0)
	{
	while(k<3)
	{
		cls();
		dist_ultra2=laser(front);
		lcd((int)dist_ultra2);
		waitms(400);
		k++;
	}
	
	dist_ultra2=laser(front);
	lcd((int)dist_ultra2);
	//waitms(1000);
	if(dist_ultra2>80)
	{
		Ultimate_jump_s(0,dist_ultra2-65);
	}
	else
	{
		//KHADE_ANGLE_O(55,35);
		cls();
		lcd((char*)" 45 checked");
	}
	cls();
	dist_ultra2=laser(front);
	lcd((int)dist_ultra2);
	//waitms(1000);
	Ultimate_jump_s(0,35 + dist_ultra2 );
	
	
	
		
	}
	
	while(0)
	{
		waitms(200);
			
			
			
			TUSSUK_NEW(left,0,open);
			TUSSUK_NEW(left,0,close);
			//Ultimate_jump_s(0, 200-dist_ultra1);//185-dist_ultra1);
			//Ultimate_jump_s(-5,200 - dist_ultra1);//96+195-dist
			//STRAIGHT(96 + 105 - dist_ultra1,back,0);
			//Ultimate_jump_s(-45,87);
			STRAIGHT_NEW(50,close);//80//Ultimate_jump_s(0,70);
			//STRAIGHT_NEW(40,back,0,close);//20\STRAIGHT_NEW(40,back,0,close);//20
			while (1)
			{
				//set(R);
				//set(L);
				//waitms(170);
				cls();
				lcd(ang,3);
			}
	}
	//waitms(2000);
	
	//KHADE_ANGLE(0,0);
	/*
	set(L);
	set(R);
	waitms(30);
	set(U2);
	waitms(230);
	reset(L);
	reset(R);
	*/
	//STRAIGHT_NEW(104,back,0,open);
	/*
	set(R);
	set(L);
	waitms(260);
	reset(L);
	reset(R);
	*/
	
	/*
	
	while (0)
	{
		KHADE_ANGLE_OB(0,0);
		cls();
		lcd(ang,3);
	}
		*/
		
		
		/*
	while (0)
	{
		
		waitms(350);
			//STRAIGHT(3,back,45);
			//waitms(300);//400);
			//COORDINATE(38,140,0,right,0);
		
			//S2T_NEW(right,45);
			COORDINATE_STRAIGHT(126,right,0);//130//105//120//126//130//133//138
			
			while(f<5)
			{
				cls();
				dist_ultra1=laser(back);
				lcd((int)dist_ultra1);
				//waitms(400);
				f++;
			}
		
			cls();
			dist_ultra1 = laser(back);
			lcd(dist_ultra1);
			
			lcd(" ");
			lcd(ang);	
			//waitms(1000);
			while(dist_ultra1<93)//92//96//92)//88)
			{
				Ultimate_jump_s(-45,93-dist_ultra1);//96//95
					waitms(200);
					cls();
					laser(back);
					laser(back);     ///necessary
					laser(back);
					dist_ultra1 = laser(back);
					lcd(dist_ultra1);
					lcd(" ");
					lcd(ang);
					//waitms(1000);//50);//30);////1000);
				
			}
			//waitms(1000);
			TUSSUK_NEW(left,-45,open);
			TUSSUK_NEW(left,-45,close);
			//Ultimate_jump_s(0, 200-dist_ultra1);//185-dist_ultra1);
			//Ultimate_jump_s(-5,200 - dist_ultra1);//96+195-dist
			//STRAIGHT(96 + 105 - dist_ultra1,back,0);
			//Ultimate_jump_s(-45,87);
			STRAIGHT_NEW(80,back,-45,close);//Ultimate_jump_s(0,70);
			STRAIGHT_NEW(40,back,-45,close);//20\STRAIGHT_NEW(40,back,0,close);//20
			while (1)
			{
				 
				cls();
				lcd(ang,3);
			}
	}*/
	//STRAIGHT(12,back,45);//12//5//15//12//12//5//9//12 reliable//8//7//15//distance20
	/*
	k=0;
	while (k<1)
	{
		set(L);
		set(R);
		waitms(260);//FOR LEFT250);
		reset(R);
		reset(L);
		waitms(500);
		k++;
	}
	
	//set(G);


	while(0)
	{
		cls();
		lcd(ang,3);
	}
	
	
	
	
	while(0)
	{
		Ultimate_jump_s(-45,90);//75);
		lcd(" ");
		lcd(ang,2);
		waitms(3000);
		k=400;
		while(k>0)
		{
			cls();
			lcd(ang,2);
			k-- ;
			//waitms(60);
		}
	}
	
	*/
	while(0)
	{
		//set(R);
		//waitms(270);//FOR LEFT250);
		//reset(R);
		//waitms(500);
		//SLOPE_P_4(0);
		
		{
			dist_ultra1=laser(right);
			dist_ultra1=laser(right);
			dist_ultra1=laser(right);
			dist_ultra1=laser(right);
			dist_ultra1=laser(right);
			
			cls();
			lcd(dist_ultra1);
			lcd(" ");
			
			dist_ultra2=laser(left);
			dist_ultra2=laser(left);
			dist_ultra2=laser(left);
			dist_ultra2=laser(left);
			dist_ultra2=laser(left);
			
			lcd(dist_ultra2);
		}
		
		dist_ultra1=laser(back);//front);//back);
		dist_ultra1=laser(back);
		dist_ultra1=laser(back);
		dist_ultra1=laser(back);
		dist_ultra1=laser(back);
		
		lowerline();
		lcd(dist_ultra1);
		lcd(" ");
		dist_ultra2=laser(front);//back);
		dist_ultra2=laser(front);
		
		dist_ultra2=laser(front);//back);
		dist_ultra2=laser(front);
		dist_ultra2=laser(front);
		//cls();
		lcd(dist_ultra2);
		lcd(" ");
		//LASER=0;
		//cls();
		lcd(ang,3);
		waitms(1000);
		
	}
	
	
	/////////////////////////	///////////////////////// 	/////////////////////////
	
	
	
	/////////////////ULTIMATE_JUMP_DATA
/*	
	while(0)
	{
		for (int l=230;l<300;l=l+20)
		{
			
			for (int j=10;j<140;j=j+10)
			{
				
				cls();
				lcd("D");
				lcd(l);
				lcd(" ");
				lcd(j);
				waitms(400);
				
				ang=0;
				set(R);
				waitms(j);
				set(L);
				waitms(l);
				reset(L);
				reset(R);
				k=0;
				while (k<100)
				{
					cls();
					lcd(ang);
					k++;
				}
				if (l==190 && j==10)
				{
					j=60;
				}
			}
			k=0;
			while (k<125)//120)
			{
				cls();
				lcd(ang);
				k++;
			}
			
		}
		while(1);
	}
	*/
	
	
	
	
	
	
	//set(U2);
	// 
	/*
	k=0;
	while(1)
	{
		KHADE_ANGLE(0,0,close);
		k++;
	}
	*/
			
  
	/*
	//sand dune leaving
	while(0)
	{	
		k=0;
		while(k<1)////3)//2)////1)
		{
		
			set(L);
			waitms(98);//78);//70);
			reset(L);
			waitms(260);//230);//200);
		
		
			set(R);
			waitms(98);//78);//70);
			reset(R);
			waitms(260);//230);//200);
			k++;
		}
		//laser(back);
		//laser(back);
		//dist_ultra2=laser(back);
		while(0)//dist_ultra2>90)//45)
		{
			set(L);
			waitms(98);//78);//70);
			reset(L);
			waitms(290);//260);//230);//200);
			
			
			set(R);
			waitms(98);//78);//70);
			reset(R);
			waitms(290);//260);//230);//200);
			laser(back);
			laser(back);
			dist_ultra2=laser(back);
			
		}
		waitms(200);
		set(U2);
		
		set(L);
		set(R);
		//waitms(50);
	
		waitms(140);//155);//186);//172);//145);//160);//172);//122);//172);//180);//172);//167);//160);//155);//160);//180);
		reset(L);
		reset(R);
		waitms(1.432*180);
	
		k=0;
		waitms(150);//50);
		while(0)//k<3)//2)//4)//3)                     ///////////IF RANGE DECREASES INCREASE NO OF JUMPS
		{
			set(R);
			set(L);
			waitms(60);//30);
			reset(R);
			reset(L);
			waitms(130);//100);//200);//700);
			k++;
		}
		k=0;
			waitms(200);
			reset(U2);
			waitms(50);//150);
			
		while(1);	
	}
	*/
	
	//sand dune leaving
	while(0)
	{	
		k=0;
		int i=100;
		while(i)
		{
			cls();
			lcd(ang);
			i--;
		}
		KHADE_ANGLE_O(0,0,small);
		while(0)//k<1)//3)//2)////1)
		{
		
		
		
			set(R);
			waitms(90);//78);//70);
			reset(R);
			waitms(400);//230);//200);
		
			set(L);
			waitms(90);//78);//70);
			reset(L);
			waitms(400);//230);//200);
			
		
			k++;
		}
// 		laser(back);
// 		laser(back);
// 		dist_ultra2=laser(back);
		while(0)//dist_ultra2>90)//45)
		{
			set(L);
			waitms(98);//78);//70);
			reset(L);
			waitms(290);//260);//230);//200);
			
			
			set(R);
			waitms(98);//78);//70);
			reset(R);
			waitms(290);//260);//230);//200);
			laser(back);
			laser(back);
			dist_ultra2=laser(back);
			
		}
		//waitms(200);
		//set(U2);
	/*
		set(L);
		set(R);
		//waitms(50);
	
		waitms(140);//155);//186);//172);//145);//160);//172);//122);//172);//180);//172);//167);//160);//155);//160);//180);
		reset(L);
		reset(R);
		waitms(1.432*180);
	*/
		k=0;
		waitms(150);//50);
		while(k<4)//3)//2)//4)//3)                     ///////////IF RANGE DECREASES INCREASE NO OF JUMPS
		{
			set(R);
			set(L);
			if (k<2)
			{
				waitms(60);//30);
				
			} 
			else
			{
				waitms(50);
				
			}
			reset(R);
			reset(L);
			waitms(130);//100);//200);//700);
			k++;
		}
		k=0;
		
		laser(back);
		laser(back);
		dist_ultra2=laser(back);
	     while(dist_ultra2>40)//90)//45)
	     {
			set(R);
			set(L);
			waitms(30);//30);
			reset(R);
			reset(L);
			waitms(130);//100);//200);//700);
			 
			 laser(back);
			 laser(back);
			 dist_ultra2=laser(back);
		 }
		    waitms(200);
			reset(U2);
			waitms(50);//150);
			
		while(1);	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	LASER=0;
	R_GEREGE=-1;
	double S2T_ANG=0;
	
	while(0)
	{
		//STRAIGHT_NEW(100);
		//waitms(1000);
	//	cls();			//	COORDINATE_STRAIGHT(90,165,right,45);//150,180//143//133//130//95//105//120//126//130//133//138   cordn_sstrt(back,left/right)//
	//	lcd("sfd");
		//..
		/*
        dist_ultra2=laser(left);
		cls();
	   
		lcd((int)dist_ultra2);
		waitms(200);	
		//COORDINATE_STRAIGHT(58,130,left,0);//right//45);
		Ultimate_jump_s(-40,30);
		Ultimate_jump_s(55,70);
	     */
 //.... 
	
	    
		for (int i=0;i<3;i++)
		{
			
		dist_ultra1 = laser(left);
		cls();
		lcd(dist_ultra1);
	//	lowerline();
	//	lcd(Q2,3);
		
		/*
		for (int i=0;i<5;i++)
		{
			dist_ultra2 = laser(left);
		}
		
	    	S2T_ANG = ((Q1)*(dist_ultra2)*(dist_ultra2)*(dist_ultra2)) + ((Q2)*(dist_ultra2)*(dist_ultra2))+ (Q3*(dist_ultra2)) + Q4 ;
	    			
		cls();
		lcd(S2T_ANG);
       lowerline();
	   lcd(dist_ultra2);
		*/
		
		}
	     
		 
//////========================================================		 
		 
		 if (dist_ultra1<75)
		 {
		 				
				k=0;
				waitms(50);
				while(k<1)//3)                     ///////////IF RANGE DECREASES INCREASE NO OF JUMPS 
				{	
					set(R);
					set(L);
					waitms(23);////30);
					reset(R);
					reset(L);
					waitms(150);//100);//200);//700);
					k++;
				}
				k=0;
			
					reset(U2);
				waitms(50);//150);
			
			
			//// SAND DUNE CROSSED
			
			
			if (!line_1)
			{
				//if(R_GEREGE==1)
					ang=ang+(45*R_GEREGE);
				//else
					//ang=ang-45;
				cls();
				lcd("restrart_line_2");
				//waitms(1000);
			}
			
			if(R_GEREGE==1)
				COORDINATE_STRAIGHT(90,160,right,45);//150,180//143//133//130//95//105//120//126//130//133//138   cordn_sstrt(back,left/right)
			else
				COORDINATE_STRAIGHT(90,160,left,-45);//150,180//143//133//130//95//105//120//126//130//133//138
		
		
		if(R_GEREGE==1)
			{
			    TUSSUCK_NEWEST_NEW(left,0);
			}
			else
			{
		    TUSSUCK_NEWEST_NEW(right,0);
			}
		 
		 }
	
		 else if(dist_ultra1>75)
		 {
		 		for (int i=0;i<3;i++)
		 		{
			 		dist_ultra2 = laser(left);
		 		}
                
			  	S2T_ANG = ((Q1)*(dist_ultra2)*(dist_ultra2)*(dist_ultra2)) + ((Q2)*(dist_ultra2)*(dist_ultra2))+ (Q3*(dist_ultra2)) + Q4 ;
			  	   
			  	Ultimate_jump_s(-S2T_ANG,30);
                Ultimate_jump_s(55,70);
		 }

//           KHADE_ANGLE_O(4,6,small);           
		
		
	//	lowerline();
	//	lcd(123);
		
		//STRAIGHT_NEW(100);
///////==================================================		
	while(1);
	}
	
	/*
	
	while(0)
	{
		cls();
		lcd(ang,2);
		lowerline();
		lcd(final_ang,3);
	}*/
	//R_GEREGE=-1;
	while(0)
	{
		Ultimate_jump_s(40,55);    // 68,137 for blue  range 63 angle37  // 54,137 for red  range 48 angle24
		while(1)                           //37,65 
		{
			cls();
			lcd(ang);
		}
	}
	
	/////////////////////////////////////////////////////NEW_KHADE
	
	//NEW_KHADE(45,45);//-90);
	//waitms(1000);
	while(0)
	{
		//Ultimate_jump_s(-1,105);
				while(0)
				{
					//PROPORTIONAL_NEW_KHADE(0,0);
					k=0;
					while(k<150)
					{
						k++;
					}		
				}
				//PROPORTIONAL_NEW_KHADE(-90,-90);
// 				
// 				k=0;
// 				while(k<150)//;//300)
// 				{
// 					cls();
// 					lcd("heyy");
// 					lcd(" ");
// 					lcd(ang);
// 					k++;
// 				}
// 				ang=0;
		for (int l=90;l<120;l=l+15)
		{
	
			cls();
			lcd(l);
			waitms(500);
			//Ultimate_jump_s(46,55);//46,
			/*
			set(R);
			waitms(l);
			set(L);
			waitms(137);
			reset(L);
			reset(R);
			waitms(200);
			*/
			/*
			set(U2);
			waitms(200);
			
			reset(U2);//khulla
			waitms(55);
			//if (RIGHT)
			{
				cls();
				lcd("RIGHT");
				set(L);
				//if (ERROR>48)//BIG)
				{
					waitms(l);//155);//50 WITH -5 ERROR FOR IMU
				}
				//else
				{
					//waitms(145);//45 WITH -1 ERROR FOR IMU
				}
				
				reset(L);
				waitms(20);
				set(U2);///com
				waitms(600);
				//reset(U2);
			}
			reset(R);
			reset(L);
			reset (U2);
			waitms(100);//50);
			
			*/
			
			//RANGE55(-l);
			PROPORTIONAL_NEW_KHADE(-l,-l);
			
			
			
			k=0;
			while(k<150)//;//300)
			{
				cls();
				lcd("heyy");
				lcd(" ");
				lcd(ang);
				k++;
			}
			ang=0;
		}
		
		waitms(500);
		for (int l=40;l<135;l=l+20)
		{
	
			cls();
			lcd(-l);
			waitms(500);
			//Ultimate_jump_s(46,55);//46,
			/*
			set(R);
			waitms(l);
			set(L);
			waitms(137);
			reset(L);
			reset(R);
			waitms(200);
			*/
			
			/*
			set(U2);
			waitms(200);
			
			reset(U2);//khulla
			waitms(55);
			//if (RIGHT)
			{
				cls();
				lcd("LEFT");
				set(R);
				//if (ERROR>48)//BIG)
				{
					waitms(l);//155);//50 WITH -5 ERROR FOR IMU
				}
				//else
				{
					//waitms(145);//45 WITH -1 ERROR FOR IMU
				}
				
				reset(R);
				waitms(20);
				set(U2);///com
				waitms(600);
			}
			reset(R);
			reset(L);
			reset (U2);
			waitms(100);//50);
			*/
			PROPORTIONAL_NEW_KHADE(l,l);
			//RANGE55(-l);
		
			k=0;
			while(k<150)
			{
				cls();
				lcd(ang);
				k++;
			}
			ang=0;
		}
		
		/*
		cls();
		lcd(115);//l);
		waitms(500);
		//Ultimate_jump_s(46,55);//46,
		set(L);
		waitms(115);//l);
		set(R);
		waitms(137);
		reset(L);
		reset(R);
		waitms(200);
	
		//RANGE55();
	
		k=0;
		while(k<150)
		{
			cls();
			lcd(ang);
			k++;
		}
		ang=0;
		cls();
		lcd(120);//l);
		waitms(500);
		//Ultimate_jump_s(46,55);//46,
		set(L);
		waitms(120);//l);
		set(R);
		waitms(137);
		reset(L);
		reset(R);
		waitms(200);
	
		//RANGE55();
	
		k=0;
		while(k<150)
		{
			cls();
			lcd(ang);
			k++;
		}
		ang=0;
		*/
		while(1)//k<150)
		{
			initial_side2=laser(left);
			cls();
			lcd(ang);
			lcd(" ");
			lcd(initial_side2);
			k++;
		}
	}
	//////////////////////////////////////////////////////////////
		
		
		//DDOUBLE _JUMMP FOR TUSSUK
// 		waitms(100);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		laser(back);
// 		dist_ultra1=laser(back);
// 		
// 		STRAIGHT_NEW(200-dist_ultra1,open,yes,193);//200);//193//185//201//202-//240//199-//185);//195//145
// 		while(1)
// 		{
// 			//cls();
// 			lcd("d");
// 			lcd(ang);
// 		}
		/////////////////////////////////
		while(0)
			{
				ang=ang-45;
				while(k<3)        //3)
					{
						cls();
						dist_ultra2=laser(front);
						lcd((int)dist_ultra2);
						waitms(70);//100);//400);//400);
						k++;
					}
					
					lcd(" ");
					dist_ultra2=laser(front);
					lcd((int)dist_ultra2);
					
					//dist_ultra2 = laser_filter(front);
					//waitms(1000);
					LASER=0;  ///////////////////////imp
					
						//if(R_GEREGE==1)
						//	KHADE_ANGLE_O(R_GEREGE*49,R_GEREGE*41);        /// removed just now
						//else
							//KHADE_ANGLE_O(-48,-42);
					
			
				
						while(dist_ultra2>75)//70//60)//75)//85//80//90)//100)//71//75)//80)                        ///////  SAND DUNE APPROACH 
						{

							//if(R_GEREGE==1)
							if (dist_ultra2>85)
							{
								STRAIGHT_NEW(dist_ultra2-65);//69//81//Ultimate_jump_s(R_GEREGE*45,(dist_ultra2-81));
							} 
							else
							{
								STRAIGHT_NEW(dist_ultra2-73);//-73//-69//-75//Ultimate_jump_s(R_GEREGE*45,(dist_ultra2-75));//73//71//70//80//90//70);//STRAIGHT(dist_ultra2-75,back,45);//-65
							}
								
										k=0;
										while(k<3)        //3)
										{
											cls();
											dist_ultra2=laser(front);
											lcd((int)dist_ultra2);
											waitms(60);//100);//50//400);
											k++;
										}
										dist_ultra2=laser(front);
										
						}
							//else	
								//Ultimate_jump_s(-45,dist_ultra2-65);//70);//STRAIGHT(dist_ultra2-75,back,45);//-65
							//KHADE_ANGLE_O(48,42);
						cls();
						lcd((int)dist_ultra2);
						lcd(" ");
							lcd("approach done");				
							//dist_ultra2 = laser_filter(front);
							waitms(200);//200 for dummy//80);//150);//..
						
						cls();
						lcd(ang);
						//waitms(1000);
				
						LASER=0;  ///////////////////////imp
					
							if(R_GEREGE==1)
								KHADE_ANGLE_O(44,44);//36//45//37//38//40,40);//41,41//10 buffer
							else
								KHADE_ANGLE_O(-45,-45);//-43//-45,-44);//10BUFFER
							//cls();
							//lcd((char*)" 45 checked");
						cls();
						lcd(ang);
						//waitms(1000);
		//				cls();
		//				lcd((int)dist_ultra2);
						//waitms(1000);
						//STRAIGHT_NEW(33+dist_ultra2);//33//38//35//+33//+27//+20//+27//+30//+35//+37//+30//+22//+18//+19//+16//+20//12+//31+///18+//8+             /////   first sand dune jump {land on  sand dune}
						
						STRAIGHT_NEW(33+dist_ultra2,open,yes);
						/*
						set(L);
						set(R);
						if(dist_ultra2<65)
						{
							waitms(30);
							set(U2);
							waitms(160);//240);//230);//240);//237);//230);//225);//240);//230);
						}
						else
							waitms(190);//270);//260);//270);//267);//260);//255);//270);//260);
						reset(L);
						reset(R);
						//Ultimate_jump_s(45,110);// 36 + dist_ultra2 );//50//43//36 reliable vaala///31//35//24
						//Ultimate_jump_s(45,20);
						*/
						waitms(300);//450);//900);//450);//300);
						cls();
						lcd(ang);
				while(1);
				}
	
	while(0)
	{
		cls();
		lcd("R");
		set(R);
		waitms(100);
		reset(R);
		waitms(250);
		set(L);
		waitms(100);
		reset(L);
		waitms(250);
		
		

		
	}
	
	
	/////////////////////////////
///////////////////////////////////////////	MAIN CODE
	//set(G);
	LASER=0;
	
	while(1)
	{
			if (red)
			{
				cls();
				lcd("RED");
				waitms(100);
			}
			else
			{
				cls();
				lcd("BLUE");
				waitms(100);
			}
			if(red)//0)//1)//0)//red)
			{
				R_GEREGE=1;//0;
				//#define END_proxy2 	   ((PINA & 0x01<<PINA4)<<0)//PINC6
				//#define END_proxy 	   ((PINA & 0x01<<PINA0)<<0)
			}
			else
			{
				R_GEREGE=-1;//1;//red;//1;//red;       //************IMP************//
				//#define END_proxy2 	   ((PINA & 0x01<<PINA0)<<0)//PINC6
				//#define END_proxy 	   ((PINA & 0x01<<PINA4)<<0)
			}
			
			//waitms(1000);//300);
			
			while(k<3)
			{
				//cls();
				initial_back=laser(back);
				//lcd(initial_back);
				//if(k)
				waitms(50);//200);//200);//100);//30);//30//200);
				k++;
			}
			k=0;
			cls();
			lcd(initial_back);
			LASER=0;  ///////////////////////imp
			waitms(100);//300);
			
			
 		if ( (initial_back<70 || initial_back>120) )//>100//MT)//MT)//0)//1)//MT)
 		{	
			 while(k<3)
			{
				//cls();
				initial_front=laser(front);
				//lcd(initial_back);
				//if(k)
				//waitms(50);//200);//200);//100);//30);//30//200);
				k++;
			}
			k=0;
			cls();
			lcd(initial_front);
			
			
			//initial_back = laser_filter(back);
			
			while(k<3)
			{
				//cls();
				if(R_GEREGE==1) 
				initial_side=laser(left);//right);//left);   needed
				else
				initial_side=laser(right);//left);//right);
				//lcd((int)dist_ultra2);
				//waitms(1000);
				k++;
			}
			lcd(" ");
			lcd(initial_side);//back);
			k=0;
			while(k<3)
			{
				//cls();
				if(R_GEREGE==1)
				initial_side2=laser(right);//left);   needed
				else
				initial_side2=laser(left);//right);
				//lcd((int)dist_ultra2);
				//waitms(1000);
				k++;
			}
			k=0;
			/*
			if(R_GEREGE==1)
			initial_side = laser_filter(right);
			else
			initial_side = laser_filter(left);
			
			*/
			lcd(" ");
			lcd(initial_side2);//back);
			waitms(100);//0);
			LASER=0;  ///////////////////////imp
			//waitms(300);
			
			if ( ((initial_side+initial_side2)>130) &&  (initial_side2<200))
			{
			 
 				if (initial_back<65 && initial_back>40 && initial_side>50 && initial_front>390)//f>410//initial_back>35//initial_back>40)
 				{
	// 				no_line=1;
	// 			}
	// 			else if( (initial_back >100 && initial_back<200 && initial_front>180) )//&& initial_side>50))
	// 				{
	// 					first_jump=1;
	// 				}
	// 			else if( (initial_back >180 && initial_back<300 && in )
	// 				second_jump=1;
	// 			else if((initial_back >100 && initial_back<400) )
	// 			
				
	//			if(no_line)	
	//			{
					
					if (R_GEREGE==1)
					{
					
						cls();
						lcd(END_proxy2);
					
						while(END_PROXY2)
						{
							//proxy(END_PROXY,END_proxy,2000);
							cls();
							lcd(END_proxy2);
							if(!END_proxy2)
							{
								i_local2=10000;//8000;//2000;//1200;//300;
								while(i_local2--)
								{
									if(!END_proxy2)
									{
										if(i_local2==1)
										END_PROXY2=0;
									}
									else
									i_local2=0;
								}
							}
						}
					
					} 
					else
					{
					
						cls();
						lcd(END_proxy);
					
						while(END_PROXY)
						{
							//proxy(END_PROXY,END_proxy,2000);
							cls();
							lcd(END_proxy);
							if(!END_proxy)
							{
								i_local=10000;//8000;//5000;//2000;//1200;//300;
								while(i_local--)
								{
									if(!END_proxy)
									{
										if(i_local==1)
										END_PROXY=0;
									}
									else
									i_local=0;
								}
							}
						}
					
					}
				
					waitms(400);//300*(10/13));
					k=0;
					
				
					
					   
							//COORDINATE_STRAIGHT(260,left,0);
							STRAIGHT_NEW(112);//105);//120);//,close_open);//105//120);//115);//(105);//100);//90);//110);
							waitms(300);//100);//100);//300);//300 for delay removal///500);//600);////450);//200);
							first_jump=1;
				}
							if(first_jump || (initial_back >120 && initial_back<160 && initial_front>200))//back>100//back now 121
							{
								if (!first_jump)
								{
									cls();
									lcd("RESTART SECOND_JUMP");
									waitms(50);
								
								}
								//STRAIGHT_NEW(120,close_open);//105);
								Ultimate_jump_s(0,112);//105//120);//,0,close_open);//105);//120);//115);//(0,105);//STRAIGHT_NEW(105);//100);//90);//110);//105);
							/*
								waitms(100);//300);//200);//400);//10);//150);//200);
								laser(back);
								laser(back);
								dist_ultra1=laser(back);
							*/	
								dist_ultra1=laser_filter(back);//,2,12);//,2,12);
								second_jump=1;
							}
						
							if(second_jump || (initial_back >159 && initial_back<285 && initial_front>160) )//<220
							{
								if (!second_jump)
								{
									cls();
									lcd("RESTART third_JUMP");
									waitms(150);
								dist_ultra1=initial_back;
								}
								cls();
								lcd(dist_ultra1);
								
								//cls();
								//lcd(dist_ultra1);
								//waitms(500);//1000);//200);  //removed for delay remaoval //500);
								//Ultimate_jump_s(0,285-dist_ultra1);
								if (0)//dist_ultra1<220)
								{
									dist_ultra1=240;
								}
								//STRAIGHT_NEW(290-dist_ultra1,close_open);
								Ultimate_jump_s(0,300-dist_ultra1);//290-//,0,close_open);//309//290//286//280//294//292//294//289//284//294//289//297//285//320//335//355//285-dist//STRAIGHT_NEW(285-dist_ultra1);
								waitms(150);//500);//600);//200);//50VERY LESS);//200);
								cls();
								lcd(ang);
								//waitms(300);//3000);
								//KHADE_ANGLE_O(0,0);
								third_jump=1;
							}
						
							//Ultimate_jump_s(0,117);   //97      117(26.04.19)
							//Ultimate_jump_s(0,117);
							//waitms(250);//100);
							//Ultimate_jump_s(45,80);//70);//65);//50);//75);//50);//63);//75);//50);
					
							//lcd("heyy");
							//waitms(100);
					
				
			
	// 				k=0;
	// 				
	// 		
	// 				while(k<3)//3)
	// 				{
	// 					cls();
	// 					if(R_GEREGE==1)
	// 						dist_ultra2=laser(left);
	// 					else
	// 						dist_ultra2=laser(right);
	// 					//lcd((int)dist_ultra2);
	// 					//waitms(100);
	// 					k++;
	// 				}
	// 				lcd((int)dist_ultra2);
	// 				//waitms(500);
	// 				k=0;
	// 				
	// 			/*
	// 				if(R_GEREGE==1)
	// 				dist_ultra2 = laser_filter(right);
	// 				else
	// 				dist_ultra2 = laser_filter(left);
	// 				*/
	// 				
	// 				while(k<3)//3)
	// 				{
	// 					
	// 					dist_ultra1=laser(back);
	// 					//lcd((int)dist_ultra1);
	// 					//if(k)
	// 					//waitms(50);//200);//200);//100);//30);//30//200);
	// 					k++;
	// 				}
	// 				lcd((int)dist_ultra1);
	// 				//waitms(500);
	// 				k=0;
	// 				
	// 				//dist_ultra1 = laser_filter(back);
	// 				//lcd(" ");
	// 				//lcd((int)dist_ultra2);  //side
	// 				LASER=0;  ///////////////////////imp
	// 			
	// 				double range=0;
	// 				
	// 				range = (dist_ultra2 + 288 - dist_ultra1 + 40 +18)*cos(45*Degree_to_Rad);  //+40+25 //+17//+0//+20 ((dist_ultra2+12) + 288 - dist_ultra1 - 10)*cos(45*Degree_to_Rad);//+20
	// 				
	// 				cls();
	// 				lcd(range);
	// 				waitms(1000);
	// 				if (range>55)//40)//65)//75)//65//78//90   ////////////IF FIELD OR AIR LUBRICATION DIFFERS DECREASE range_h
	// 					range=55;
	// 				
	// 				if(range<1)
	// 					range=1;
 					
					if(third_jump || (initial_back>284 && initial_back<400 && initial_front>130) ) //<320//<350
					{
						if (!third_jump)
						{
							cls();
							lcd("RESTART fourth_JUMP");
							//waitms(150);//50);
						}
				
						if(R_GEREGE==1)
							RANGE55(36);//39);//39//41);//45//NEW_KHADE(44,44);//46//Ultimate_jump_s(46,55);//61);//55);//40//61);//55//60//range//50          //range      ///   first 45 jump to sand dune
						else
							RANGE55(-42);//-41);//-45);//NEW_KHADE(-40,-40);//Ultimate_jump_s(-40,61);//55
						
						waitms(80);//300);//250);//160);//120);//80);//30);//100);//300);//100);
						//while(1)
						{
							
						
						cls();
						lcd(ang);
						}
						waitms(600);//1000);
						
						if(R_GEREGE==1)
							KHADE_ANGLE_O(42,42,small);//42,42//44//37//36//45//37//38//40,40//41,41//10 buffer
						else
							KHADE_ANGLE_O(-45,-45,small);//-43//-45,-44//10BUFFER
						cls();
						lcd(ang);
						//waitms(500);//80);//1000);//250);//80);//50);//1000);
							no_line=1;
						/*							
							while(k<3)//4)//12)//6)        //3)
							{
								//cls();
								dist_ultra2=laser(front);
								//lcd((int)dist_ultra2);
								//waitms(70);//100);//35);//100);//400);//400);
								k++;
							}
							
							//lcd(" ");
							cls();
							dist_ultra2=laser(front);
							lcd((int)dist_ultra2);
							
						*/
						
							dist_ultra2=laser_filter(front,2,3);//3);//,2,12);
							
							//dist_ultra2 = laser_filter(front);
							//waitms(50);//200);
							LASER=0;  ///////////////////////imp
							
					}
					
				if(no_line || (initial_back >100 && initial_back<400 && initial_front<160 && ((initial_side+initial_side2)<250) && ((initial_side2+initial_side)>165)) )//&& initial_side>50))
				{
				
						if (!no_line)
						{	
							//if(R_GEREGE==1)
								ang=ang + R_GEREGE*45; 
							//else
								//ang=ang + R_GEREGE*45;
							dist_ultra2=initial_front;
							cls();
							lcd("restrart_line_1");
							//waitms(1000);
						}
						line_1=1;		
				
					
						//if(R_GEREGE==1)
						//	KHADE_ANGLE_O(R_GEREGE*49,R_GEREGE*41);        /// removed just now
						//else
						//KHADE_ANGLE_O(-48,-42);
					
					
					int length=0;
					length=90;//85;
						while(dist_ultra2>length)//90//75)//71)//75)//70//60)//75)//85//80//90)//100)//71//75)//80)                        ///////  SAND DUNE APPROACH
						{

							//if(R_GEREGE==1)
							if (dist_ultra2>(length+10))//100//85)//81)//85)
							{
								STRAIGHT_NEW(dist_ultra2-(length-10));//80//65//61);//65);//69//81//Ultimate_jump_s(R_GEREGE*45,(dist_ultra2-81));
							}
							else
							{
								STRAIGHT_NEW(dist_ultra2-(length-2));//69);//-73//-69//-75//Ultimate_jump_s(R_GEREGE*45,(dist_ultra2-75));//73//71//70//80//90//70);//STRAIGHT(dist_ultra2-75,back,45);//-65
							}
						/*
							k=0;
							cls();
							while(k<3)        //3)
							{
								
								dist_ultra2=laser(front);
							//	waitms(60);//100);//50//400);
								k++;
							}
							
							dist_ultra2=laser(front);
							lcd((int)dist_ultra2);
							//waitms(200);						
						*/
						
						dist_ultra2=laser_filter(front,2,2);//3);//,2,12);
						}
						//else
						//Ultimate_jump_s(-45,dist_ultra2-65);//70);//STRAIGHT(dist_ultra2-75,back,45);//-65
						//KHADE_ANGLE_O(48,42);
						cls();
						lcd((int)dist_ultra2);
						lcd(" ");
						lcd("approach done");
						//dist_ultra2 = laser_filter(front);
						//waitms(900);//200);//400);//200);//200 for dummy//80);//150);//..
					
						//cls();
						lcd(ang);
						//waitms(600);//300);
					
						LASER=0;  ///////////////////////imp
					
						if(R_GEREGE==1)
						{
							if (!no_line)
							{
								KHADE_ANGLE_O(45,45-1,small);
							} 
							else
								KHADE_ANGLE_O(42,42-1,small);//44//37//36//45//37//38//40,40);//41,41//10 buffer
						}
						else
							KHADE_ANGLE_O(-45+1,-45,small);//-43//-45,-44);//10BUFFER
						//cls();
						//lcd((char*)" 45 checked");
						cls();
						lcd(ang);
						//waitms(500);//1000);
						//				cls();
						//				lcd((int)dist_ultra2);
						
						//waitms(50);//120);//80);//1000);
						
						dist_ultra2=laser_filter(front,2,2);//,2,12);
						
						//range 38+dist to 33+ dist since range increased(piston cool)
						short int b=0;
							b=0;//2;
							
						
							
						if (dist_ultra2<57)
						{
							STRAIGHT_NEW(36+dist_ultra2+b,close,yes,110);//105//99
						}
						else if (dist_ultra2<60)
						{
							STRAIGHT_NEW(36+dist_ultra2+b,open,yes,110);//open//110//9//34+////if both  //33//31
						} 
						else if (dist_ultra2<73)//70)
							STRAIGHT_NEW(36+dist_ultra2+b,open,yes,121);//116//111//106//34+//101//103//33//31//33//38//35//+33//+27						STRAIGHT_NEW(33+dist_ultra2);//38//35//+33//+27//+20//+27//+30//+35//+37//+30//+22//+18//+19//+16//+20//12+//31+///18+//8+             /////   first sand dune jump {land on  sand dune}
						else if (dist_ultra2<80)
							STRAIGHT_NEW(34+dist_ultra2+b,open,yes,132);//137//140//135//33+//130//34+//125//120
						else if (dist_ultra2<85)
							STRAIGHT_NEW(44+dist_ultra2+b,open,yes,140);//38+
						else
							STRAIGHT_NEW(51+dist_ultra2+b,open,yes,145);//150//48+
						
						
						/*
						
						if (dist_ultra2<57)
							STRAIGHT_NEW(36+dist_ultra2,close);//38
						else
							STRAIGHT_NEW(36+dist_ultra2);//38
						
						*/
						
						/*
						set(L);
						set(R);
						if(dist_ultra2<65)
						{
							waitms(30);	
							set(U2);
							waitms(160);//240);//230);//240);//237);//230);//225);//240);//230);
						}
						else
							waitms(190);//270);//260);//270);//267);//260);//255);//270);//260);
						reset(L);
						reset(R);
						//Ultimate_jump_s(45,110);// 36 + dist_ultra2 );//50//43//36 reliable vaala///31//35//24
						//Ultimate_jump_s(45,20);
						*/
						
						//waitms(20);//100);//300);//450);//900);//450);//300);
						k=0;
						
						//while(1)//k<200)
						{
							
						k++;
						cls();
						lcd(ang);
						}
						//waitms(1000);
							//STRAIGHT(12,back,45);//12//5//15//12//12//5//9//12 reliable//8//7//15//distance20
					
						 reset(U2);
						 waitms(60);//200); 
				
				
						/////////////////////////////  IF RANGE DECREASES INCREASE SECOND JUMP
						
					
						k=0;					
						//waitms(100);
						
						waitms(200);
 						laser(back);
 						laser(back);
 						dist_ultra2 = laser(back);
// 						dist_ultra2 = laser_filter(back,2,12);
//						dist_ultra1 = laser_filter(front,2,12);
						/*		
						
							laser(front);
							laser(front);
							dist_ultra1 = laser(front);
						
						
						while(dist_ultra1<100 && k<20)//0)//30)//80)//20)
						{
							laser(front);
							laser(front);
								dist_ultra1 = laser(front);
 							k++;
							//dist_ultra1 = laser_filter(front,2,12);
						} 
					
 						laser(back);
 						laser(back);
 						dist_ultra2 = laser(back);	
 						*/
						
						//waitms(200);
						laser(front);
						laser(front);
						laser(front);
						dist_ultra1 = laser(front);
						
						
					//    dist_ultra2 = laser_filter(back,2,12);
				
					}
			}
				if (line_1 || (initial_side>200) )//&& initial_front> )
				{
					sand_dune_leave=1;
					if(!line_1)
					{
						dist_ultra2=initial_back;
						dist_ultra1=initial_front;
						ang=ang+(45*R_GEREGE);
						cls();
						lcd("RESTART SAND DUNE ");
						//waitms(50);
					}
					if (dist_ultra2>100)
					{
						double_jump=0;
						
						if (dist_ultra1>100)//50)//70)
						{
							double_jump=1;
							set(L);
							set(R);
							//set(U2);
							waitms(165);//175);//155);//145);//200);//186);//172);//180);//172);//167);//160);//155);//160);//180);
							reset(L);
							reset(R);
							waitms(1.432*200);//180);
						}
						else
						{
							
							k=0;
						
						
							waitms(10);//200);
							if(R_GEREGE==1)
							{	
								if (!no_line || !line_1)
								{
									KHADE_ANGLE_O(45+2,45-2,small);
								}
								else
									KHADE_ANGLE_O(44+2,44-2,small);//37//36//45//38//43+-2//40+-2//42+-2
							}
							else
								KHADE_ANGLE_O(-45+2,-45-2,small);//44//45//R_GEREGE*45+2,R_GEREGE*45-2,small);
							while(k<3)//4)//3)//2)//4)//3)                     ///////////IF RANGE DECREASES INCREASE NO OF JUMPS
							{
								set(R);
								set(L);
							
								if (k<2)
								waitms(62);//70high//60);//60);//30);
								else
								waitms(55);//53);//60);//50);//30);
							
								reset(R);
								reset(L);
								waitms(130);//100);//200);//700);
								k++;
							}
							k=0;
						
							laser(back);
							laser(back);
							dist_ultra2=laser(back);
							while(dist_ultra2>60)//50)//40)//90)//45)
							{
						
								set(R);
								set(L);
								waitms(53);//60);//50);//30);
								reset(R);
								reset(L);
								waitms(130);//100);//200);//700);
								waitms(50);//100);//200);
								laser(back);
								laser(back);
								dist_ultra2=laser(back);
							}
							//waitms(200);
							//reset(U2);
				
						}
						set(R);
						set(L);
						waitms(43);//60);//50);//30);
						reset(R);
						reset(L);
						waitms(130);//100);//200);//700);
					
						//waitms(50);//150);
			
						//KHADE_ANGLE_O(36,36);//45//38//42
					}
					//while(1)
					{
						cls();
						lcd(ang);
						waitms(50);//800);//400);
					}
					if (no_line && line_1)
					{
						if (R_GEREGE==1)
						{
								if (1)//!double_jump)
									ang=ang+4;//12;//9;
									
										//ang=ang+8;//7;//9;
						} 
						else
						{
							if (double_jump)
							{
								ang=ang+5;///2/7after double jump;
							}
							else
								ang=ang+5;//7;
						}
					}
					
					
				}
			
			//// SAND DUNE CROSSED
			if (sand_dune_leave ||(initial_back<60 && initial_front>79 && ((initial_side+initial_side2)>125) ))//&& initial_front<410//&& initial_front>80))
			{
			
					
					if (!sand_dune_leave)
					{
						//if(R_GEREGE==1)
							ang=ang+(45*R_GEREGE);
						//else
							//ang=ang-45;
						cls();
						lcd("restrart_line_2");
						//waitms(1000);
					}
					//if(initial_side<130)
			
					//STRAIGHT(3,back,45);
					//waitms(300);//400);
					//COORDINATE(38,140,0,right,0);
		
					//S2T_NEW(right,45);
		
				
				
				
				if (R_GEREGE==1)
				{
					for (int i=0;i<3;i++)//5
					{			
						dist_ultra1 = laser(right);
										
					}
					cls();
					lcd(dist_ultra1);
				} 
				else
				{
					for (int i=0;i<3;i++)//5
					{		
						dist_ultra1 = laser(left);
					}	
					cls();
					lcd(dist_ultra1);
				}
				
				LASER=0;
		//////========================================================		 
				line_2=1;
				/*
				waitms(150);//100);
				NEW_KHADE(R_GEREGE*90,R_GEREGE*90);
				//while(1)
				{
					cls();
					lcd(ang);
				}
				waitms(200);
				Ultimate_jump_s(10,80);//0,80
				*/
				
				
				 if (dist_ultra1<65)//70)//75)
				 {
		 				
			
					//		reset(U2);
						waitms(50);//150);
				POINT_3=1;
			
					//// SAND DUNE CROSSED
			
			
			
			
					cls();
					lcd("fsg");
					//waitms(250);//500);
					//R_GEREGE=-1;
			
					if(R_GEREGE==1)  //RED
						COORDINATE_STRAIGHT(87,192,right,45);//angle42,95,261//100,252//108,242,//96,222//89,218//79,208//90,191//90,184//90,175//80,140//angle45);//90,130//90,160//90,160//150,180//143//133//130//95//105//120//126//130//133//138   cordn_sstrt(back,left/right)
					else
					{
						lcd(" ");
						lcd("heyy");
						//waitms(250);//500);
						COORDINATE_STRAIGHT(87,192,left,-45);//87,155//80,140//90,130//90,160//150,180//143//133//130//95//105//120//126//130//133//138
					}
		
		 
		 
				 }
	
	
	
				 else if(dist_ultra1>=65 && dist_ultra1<100)//95)//75//<115)
				 {
					 cls();
					 lcd("ayush2");
					 lcd(" ");
					 lcd(ang);
					 //waitms(1000);
					POINT_2=1;
					 LASER=0;
					 //R_GEREGE=-1;
						/////////PEHLE RED ME EK HI POINT THA
						if(R_GEREGE==1)      //RED
							{	if (!sand_dune_leave || !line_1 || !no_line )//RESTART
								{
									COORDINATE_STRAIGHT(96,181,right,50);//90,178//80,176//86,184//90,172//-50);//80,158,//105,164
								}
								else
									COORDINATE_STRAIGHT(68,181,right,50);//106,178//103,176//97,174//99,172//90,167//81,166//77,165//68,181//70,178(2 june)//73,182//76,168,//80,158//85,170//80,158//90,189,ANGLE47//82,173//78,161//69,174//73,183//80,178//75,170//85,188//95,198//115,208,//125,198//115,180//100,180//90,180//80,180//80,190//93,190//106,190//115,190//102,180//angle50);//110,168//angle48//100,160//angle45//90,160//90,150//80,140//75,130//85,130//75,130//75,150//75,175//95,175//105,175//120,175//150,180//143//133//130//95//105//120//126//130//133//138
							}
						else
							if (!sand_dune_leave || !line_1 || !no_line )//RESTART
							{
								COORDINATE_STRAIGHT(95,168,left,-50);//91,166//87,164//91,166//98,156//87,154,//83,160,//90,172//83,160//90,172//80,158,//105,164
							} 
							else
								COORDINATE_STRAIGHT(112,166,left,-50);////106,163//110,165//97,157//81,152//78,156//83,150,//80,158,//105,164//104,161//103,153//107,168,//105,178//103,186//108,192//102,180//110,168//angle48//100,160//angle45//90,160//90,150//80,140//75,130//85,130//75,130//75,150//75,175//95,175//105,175//120,175//150,180//143//133//130//95//105//120//126//130//133//138			
     			 }
				 else
				 {
					 POINT_1=1;
					 	if(R_GEREGE==1)
							if (!sand_dune_leave || !line_1 || !no_line )//RESTART
								COORDINATE_STRAIGHT(119,197,right,50);//113,194 //109,192 //100,189//104,183,
							else
					 			COORDINATE_STRAIGHT(109,195,right,50);//108,198//113,193//118,195//111,192//104,190//100,189,//115,189//120,187//104,183//107,177//113,181//113,173//112,192,47);//115,194//112,190//110,188//108,185//98,187//118,202//128,212//115,197//130,208//140,218//120,197//120,192//115,185//115,180//100,180
						else
						{
							if (!sand_dune_leave || !line_1 || !no_line )//RESTART
								COORDINATE_STRAIGHT(109,164,left,-50);//113,166//119,169//115,167//119,169//123,171//117,168//112,166//128,162//124,158,//124,158//117,168//114,162//119,182
							else
					 			COORDINATE_STRAIGHT(99,168,left,-50);//101,169//109,173//113,175//117,177//121,179//125,181//129,183/109,178/113,174//108,173//114,183//124,177//119,182,//113,173,//100,176//107,177//113,181//(113,173//-50);//113,176//103,186//108,192//102,180//110,168//angle48//100,160//angle45//90,160//90,150//80,140//75,130//85,130//75,130//75,150//75,175//95,175//105,175//120,175//150,180//143//133//130//95//105//120//126//130//133//138
						}
				 }
				
				//while(1)
				{
					cls();
					lcd(ang);
				}
			//}
			//if (line_2  || (initial_back<220 && initial_back>120 && initial_front>70 && initial_front<162) )
			//{
				
			
				if (0)//!line_2)
				{
					cls();
					lcd("RESTART LAST");
					waitms(100);
					ang=ang+R_GEREGE*75;//*85;
					PROPORTIONAL_NEW_KHADE(R_GEREGE*8,R_GEREGE*8);//KHADE_ANGLE_O(R_GEREGE*8,R_GEREGE*8);
				}
				//while(1)
				{
					cls();
					lcd(ang);
					waitms(50);
				}
				last=1;    //////imp 
			   cls();
			   lcd("tusuk");
			   //waitms(1000);//200);
		   
			   //ang=0;
		       		if(R_GEREGE==1)
	    		{
		    		TUSSUCK_NEWEST_NEW(left,0);
	    		}
	    		else
	    		{
		    		TUSSUCK_NEWEST_NEW(right,0);
	    		}
			}
				if (!last)
				{
					cls();
					lcd("RESTART TUSSUK");
					waitms(50);
					//tt_jump=1;
				}
					if(R_GEREGE==1)
					{
						TUSSUCK_NEWEST_NEW(left,0,yes);
					}
					else
					{
						TUSSUCK_NEWEST_NEW(right,0,yes);
					}
			
			
	
		
		
				//KHADE_ANGLE_O(0,-1);
			
			//*******
			
			
			
			

			//Ultimate_jump_s(0, 200-dist_ultra1);//185-dist_ultra1);
			//Ultimate_jump_s(-5,200 - dist_ultra1);//96+195-dist
			//STRAIGHT(96 + 105 - dist_ultra1,back,0);
			//Ultimate_jump_s(-45,87);
			
			//STRAIGHT_NEW(50,back,0,close);//80//Ultimate_jump_s(0,70);
			
			//STRAIGHT_NEW(40,back,0,close);//20\STRAIGHT_NEW(40,back,0,close);//20
			
			
			k=0;
			while (1)//k<30)
			{
				//set(R);
				//set(L);
				//waitms(170);
				cls();
				lcd((int)ang);
				k++;
			}
			
		}
		else
		{
			
			LASER=0;
				cls();
				lcd("SLOPE");
				waitms(100);
								
			if(R_GEREGE==1)
			{	
				cls();
				lcd(END_proxy);
			
				while(END_PROXY)
				{
					//proxy(END_PROXY,END_proxy,2000);
					cls();
					lcd(END_proxy);
					if(!END_proxy)
					{
						i_local2=500;//1000//2000;//1200;//300;
						while(i_local2--)
						{
							if(!END_proxy)
							{
								if(i_local2==1)
								END_PROXY=0;
							}
							else
							i_local2=0;
						}
					}
				}
				while(!END_proxy);
			
			}
			else
			{
				cls();
				lcd(END_proxy2);
				while(END_PROXY2)
				{
					//proxy(END_PROXY,END_proxy,2000);
					cls();
					lcd(END_proxy2);
					//lcd(" ");
					//lcd(END_proxy2);
					if(!END_proxy2 )//&& !END_proxy2)
					{
						i_local=500;//2000;//1200;//300;
						while(i_local--)
						{
							if(!END_proxy2 )//&& !END_proxy2)
							{
								if(i_local==1)
								END_PROXY2=0;
							}
							else
							i_local=0;
						}
					}
				}
				while(!END_proxy2);
			}
			
			ang=0;
			cls();
			lcd("ATTENTION");
			waitms(100);
			
			/*
			cls();
			lcd(END_proxy2);
			while(END_PROXY2)
			{
				//proxy(END_PROXY2,END_proxy2,2000);
				cls();
				lcd(END_proxy2);
				if(!END_proxy2)
				{
					i_local=2000;//1200;//300;
					while(i_local--)
					{
						if(!END_proxy2)
						{
							if(i_local==1)
							END_PROXY2=0;
						}
						else
						i_local=0;
					}
				}
			}
			*/
			
			while(!SLOPE)//N_jump<5)//!SLOPE)//k<5)
			{
				
				
				lcd((int)ang);
				
				/*
				while (0)
				{
					dist_ultra1=laser(right);
					dist_ultra2=laser(left);
					cls();
					lcd(dist_ultra1);
					lcd(" ");
					lcd(dist_ultra2);
					//waitms(1000);
					//cls();
				}
				*/
				
				//NEW_SLOPE_P_4(0);//(0);
				if (dist_ultra2<135 && N_jump>3)//<150//>141//>4)//3)//130
				{
					waitms(50);
					/// KHADE_ANGLE_O(10,-10);
					//set(G);
					// STRAIGHT_NEW(dist_ultra2-65);///-65//-75//90//SLOPE_P_4(0,yes);
						//set(G);
						SLOPE=1;
				} 
				else
				{
					SLOPE_P_4(0);	
				}
				
				//NEW_SLOPE_P_4(0);//(0);
				N_jump++;
				
				//waitms(100);
				if(N_jump>3)//4)//3range decreased)//4)//0//N_jump>4)//3)//4)//6)//5)
				{
					
					/*
					if(N_jump==5)
					{
						//reset(U2);
						//waitms(500);
					}
					
					dist_ultra1=laser(back);//front);//back);
					dist_ultra1=laser(back);
					dist_ultra1=laser(back);
					cls();
					lcd(dist_ultra1);
					lcd(" ");
					*/
					//dist_ultra1 = laser_filter(back);
					
					waitms(260);//300//400);//250);//500);
					dist_ultra2=laser(front);//back);
					dist_ultra2=laser(front);
					//NEW 3MORE TIMES
					dist_ultra2=laser(front);
					dist_ultra2=laser(front);
					dist_ultra2=laser(front);
					cls();
					//dist_ultra2=laser(front);
					lcd(dist_ultra2);
					lcd(" ");
					//dist_ultra2 = laser_filter(front);
					LASER=0;                                   
					//lowerline();
					//lcd((int)ang);
					//waitms(1000);
					if(dist_ultra2<=95)//90)//85)// && dist_ultra1>550)//80)//85)//70)
					{
						i_local_3=2;//3;//5;//1200;//300;
						while(i_local_3--)
						{
							/*
							dist_ultra1=laser(back);//front);//back);
							dist_ultra1=laser(back);
							dist_ultra1=laser(back);
							cls();
							lcd(dist_ultra1);
							lcd(" ");
							*/
							//dist_ultra1 = laser_filter(back);
							//waitms(80);
							dist_ultra2=laser(front);//back);
							dist_ultra2=laser(front);
							//dist_ultra2=laser(front);
							lcd(dist_ultra2);
							lcd(" ");
							//dist_ultra2 = laser_filter(front);
							//lowerline();
							//lcd((int)ang);
							//waitms(500);
							if(dist_ultra2<=95)//90)//<85)// && dist_ultra1>550)//80)//85)//70)
							{
								if(i_local_3==1)
									SLOPE=1;
							}
							else
							{
								i_local_3=0;
							}
						}
					}
				}
				k++;
				//if(N_jump==5)
				//SLOPE=1;
			}
			//KHADE_ANGLE(10,-10);
			
			waitms(100);
			
			laser(right);
			laser(right);
			dist_ultra1=laser(right);
			laser(left);
			laser(left);
			dist_ultra2=laser(left);
			
			cls();
			lcd(dist_ultra1);
			lcd(" ");
			lcd(dist_ultra2);
			
			if ( (ang>-15 && ang<5) ) //<15 
			{
				
				if ( ( dist_ultra1-dist_ultra2) >5 )
				{
					PROPORTIONAL_NEW_KHADE((-55),-55,no);//-35//-45//90
				} 
				else
					PROPORTIONAL_NEW_KHADE((70),(70),no);//60//60//90
			}
			else
			{
				if (ang>0)
				{
					if(dist_ultra2>=35)//40)
						PROPORTIONAL_NEW_KHADE((70),(70),no);
					else
						PROPORTIONAL_NEW_KHADE((-55),(-55),no);
				}
				else
				{
					if(dist_ultra1>=35)//40)
						PROPORTIONAL_NEW_KHADE((-55),(-55),no);
					else
						PROPORTIONAL_NEW_KHADE((70),(70),no);
				}
			}
			set(G);
			reset(U2);
			
			cls();
			lcd("cool");
		
			while(1)
			{
				cls();
				lcd(ang,3);
			}
				
		}
			
	}
	
/*	
	
	
	lcd("S");
		lcd(MT);
		waitms(1000);
		MOUNTAIN=0;
		if(!MT)//!MOUNTAIN)//MT)
		{
			reset(G);
			cls();
			lcd(END_proxy);
			while(END_PROXY)
			{
				//proxy(END_PROXY,END_proxy,2000);
				cls();
				lcd(END_proxy);
				if(!END_proxy)
				{
					i_local=2000;//1200;//300;
					while(i_local--)
					{
						if(!END_proxy)
						{
							if(i_local==1)
							{
								END_PROXY=0;
							}
						}
						else
						i_local=0;
					}
				}
			}
			//Printbin(COM0,P_3_5);
			waitms(500);
			//dist_ultra1=laser(back);
			lcd((int)dist_ultra1);
			while(dist_ultra1<200)//225//flag_3<2)
			{
				CHALTE_LONG_ANGLE_3_5(0);//CHALTE_ANGLE_3_5(0);
				lcd("heyy");
				//dist_ultra1=laser(back);
				lcd((int)dist_ultra1);
				//flag_3++;
			}
			
			COORDINATE_STRAIGHT(256,left,0);//261//257//265//250//260/254//250//265
			KHADE_ANGLE_O(-2,-10);
			waitms(1000);
			CHALTE_OLD_ANGLE_3(-45);
			cls();
			lcd((char*)" 400 DONE");
			lcd((int)ang);
			KHADE_ANGLE_O(-42,-44);
			cls();
			lcd((char*)" 45 DONE");
		
			approach(70,front);
			
			if(step)
			KHADE_ANGLE_O(-42,-44);
		
			step=0;
			cls();
			lcd((char*)" SAND DUNE APPROACH DONE");
			//Printbin(COM0,P_3_3);//2);//0);//P_5);
			//Printbin(COM0,P_3_3);
			//Printbin(COM0,P_3_3);
			waitms(500);
			
			lcd((int)ang);
			waitms(1000);
			while(sand==0)          ////////SAND DUNE JUMP P_5
			{
				set(L);
				set(R);      //////IMP waitms(100); for tussuk maybe
				waitms(340);//380);////390);////250);//270);//315);//340);//(344);//370);//360);//400);//350);//225);//130);//for straight   ////////IMP waitms(250) for tussuk maybe
				reset(R);
				reset(L);
				//reset(U2);
				waitms(2000);     ////1000);for straight
				sand=1;
			}
			waitms(500);//1000
			CHALTE_SMALL_ANGLE_2_5(-45);
			//Printbin(COM0,P_3_3);
			waitms(300);
			//Printbin(COM0,P_3_3);
			KHADE_ANGLE_O(-40,-50);
			//Printbin(COM0,P_3_3);
			c_jump=0;
			while(c_jump<1)
			{
				S2T(left,ang);
				c_jump++;
			}
			//Printbin(COM0,P_3_3);
			KHADE_ANGLE_O(9,6);//3,0
			approach(100,back);
			/*
			if(step)
			KHADE_ANGLE_O(3,0);//3,0
			*/
			/*
			//Printbin(COM0,P_4);
			
			//dist_ultra1=laser(right);
			lcd((int)dist_ultra1);
			lcd("  ");
			//dist_ultra1=laser(back);
			lcd((int)dist_ultra1);
			
			while(t_jump<2)          ////////TUSSUK JUMP
			{
				cls();
				lcd((int)ang);
				lcd(" ");
				//dist_ultra1=laser(right);
				lcd((int)dist_ultra1);
				lcd("  ");
				//dist_ultra1=laser(back);
				
				lcd((int)dist_ultra1);
				//CHALTE_LONG_ANGLE_4(0);
				TUSSUK(right,8);
				t_jump++;
			}
			approach(100,front);
		}
		else
		{
		cls();
		lcd("mountain_urttu");
		cls();
		while(k<3)//k<3)
		{
			lcd(ang,2);
			CHALTE_SLOPE_ANGLE_4(0);
			k++;
		}
		while(1)
		{
			cls();
			lcd(ang,2);
			SLOPE_P_4(0);
		}
		/*
		while(!SLOPE)
		{
			SLOPE_P_4(0);//SLOPE_P_4(0);
			N_jump++;
			cls();
			dist_ultra2 =  (front);//laser(front);
			//waitms(100);
			if(N_jump>3)
			{
				cls();
				lcd((int) );  //dist_ultra2);
				lowerline();
				lcd(ang);
				if(dist_ultra2<85)//70)
				{
					i_local_3=5;//1200;//300;
					while(i_local_3--)
					{
						dist_ultra2 = laser(front);
						//waitms(100);
						cls();
						lcd((int)dist_ultra2);
						lowerline();
						lcd(ang);
						if(dist_ultra2<85)//70)
						{
							if(i_local_3==1)
							{
								SLOPE=1;
							}
						}
						else
						{
							i_local_3=0;
						}
					}
				}
			}
			k++;
		}
		set(G);
		
	}
	while(1)
	{}
		*/
	}
		

