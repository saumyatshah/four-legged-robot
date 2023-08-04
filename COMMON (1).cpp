/*
 * COMMON.cpp
 *
 * Created: 1/16/2019 5:31:21 PM
 *  Author: aakash
 */ 
#include "COMMON.h"

//int distance_ultra=,0;
int ultra_pulse=0;
long pulse=0;

///////--------------------------- SHERU INITIALISE------------------------------------------------------/////
int k=0,i=0,ULTRA_temp=0,long_jump=0,c_jump=0,step=0;
double ULTRA_Final=0, dist=0,pulse_diff=0,pulse_range=0, pulse_time=0,pulse_actual=0,pulse_actual2=0; 

int r=0,l=0,flag_1=0,flag_2=0,END_PROXY=1,END_PROXY2=1,LIMIT_switch,i_switch=0,DIST=1;
int RUK_r=0,RUK_l=0,t_jump=0,n_jump=0,tt_jump=0,seedha=0,seedha_near=0,flag_turn=0,ULTRA=0,flag_turnL=0,flag_turnR=0,sand=0,flag_90=0;
//unsigned short ULTRA=0;
int i_local,i_local2;
int angle_DELAY=0,angle_DELAY_E=0,angle_DELAY_UPPER=0;
int STRAIGHT_DELAY=0,R_GEREGE=0;
double ANGLE_ERROR=0,CORRECT=0;
bool STRAIGHT_FLAG=0,B_JUMP=0,STEP=0,LONG=0,upper=0;


bool line_1=0,line_2=0,no_line=0,first_jump=0,second_jump=0,third_jump=0,fourth_jump=0,double_jump=1,sand_dune_leave=0,POINT_1=0,POINT_2=0,POINT_3=0;

double ANG_R[5]={0},ANG_L[5]={0},ANG=0,ERROR_LONG_C=0;
double ANG_R_2[5]={0},ANG_L_2[5]={0};
int dist_ultra1=0,dist_ultra2=0,dist_ultra3=0,dist_ultra4=0,side_distance=0,back_distance=0,front_distance=0,SIDE_distance=0,SIDE_DISTANCE=0,LATERAL=0, distance=0, distance1=0, distance2=0;
int ANGLE_DELAY = 0,ANGLE_DELAY_2_5_C=0,ANGLE_DELAY_C=0,ANGLE_DELAY_S_C=0,ANGLE_LONG_DELAY_C=0,ANGLE_FLAG=0,CHALTE_S_FLAG=0,CHALTE_FLAG_2_5=0,CHALTE_FLAG=0,CHALTE_LONG_FLAG=0; 
int ERROR=0,ERROR_2_5_C=0,ERROR_C=0,ERROR_S_C=0,INITIAL_ANGLE=0;
int ERROR_S=0;
////////////// for fourier & bi-polynomial series
double x=0,y=0;
///////////////////////////

////////////////////////for cubic roots & quadratic roots
double root_1=0, root_2=0, root_3=0;
//////////////////for cubic roots & quadratic coefficients
double a=0,b=0,c=0,d=0,e=0;
double VALUE=0,f = 0;
//////////////////////for derivative of polynomial uptil 9th degree
double sum=0;

//////////////////////////////////SLOPE IMU CORRECTION
short int prev_ang=0; 
//////////////////////////////////

//////////////////ffilter
int LASER_VALUE=0,count_1=0;


//================================================TFMINI FUNCTION VARIABLES DEFINATIONS======================================
int tf_dist=0,count=0;
int A=0,B=0,C=0;
int32_t lidarvalue=0,next=0;
int prev_laser=0;
unsigned char uart_data[8];

///////////==========IMP CHANGE
bool LASER=0;
short int l_switch=0;
//----------------------------------------------------------------


//uint8_t ra,rb,rc,rd,data1,data2,data3;//////////////////////////r1,r2,r3,response bits,,,ra,rb 8bit packets having distributed 16 bits,data1,data2
int q;
              //////////////////r1,r2,r3,r4   taken 32 bit for this run initially of 8 bit
int32_t r1,r2,r3,r4,ans=0,ans2=0;
 double ang=0,final_ang=0,temp_ang_init=0,temp_ang_final=0;
int imu_count,dispcount;

int ultra_count=0,temp_count=0,temp_count2=0 ,count_general=0, temp=0, echo_flag=0, prev_count=0 ;
//double temp_count=0;




/////------------------------------------- SHERU FUNCTION ----------------------------------------------------//////


/*
// 

void RED()
{
		
}

void BLUE()
{
	
}	

void BIG_JUMP(int PRESSURE,int DELAY, int steps, int buffer)
{
	//Printbin(COM0,PRESSURE);
	k=0;
	while(k<steps)
	{
		lcd((int)ang);
		cls();
		if(ang>(-buffer) && ang<buffer)
		{
				set(L);
				set(R);      //////IMP waitms(100); for tussuk maybe
				waitms(350);//225);//130);//for straight   ////////IMP waitms(250) for tussuk maybe
				reset(R);	
				reset(L);
				waitms(DELAY);     ////1000);for straight
				k++;
		}
		if(ang>buffer)      //// CHALTE CHALTE RIGHT TURN
		{
				                            //CHALTE CHALTE RIGHT
			set(R);
			waitms(60);  //70);   //100); //30);
			set(L);
			waitms(160);  //100); //100); //140);
			reset(R);
			waitms(100);  //70); //100); //70);
			reset(L);
			waitms(DELAY);
			k++;
		}
		if(ang<-buffer)      //// CHALTE CHALTE LEFT TURN
		{
	                            //CHALTE CHALTE RIGHT
			set(R);
			waitms(60);  //70);   //100); //30);
			set(L);
			waitms(160);  //100); //100); //140);
			reset(R);
			waitms(100);  //70); //100); //70);
			reset(L);
			waitms(DELAY);
			k++;
		}
	}	
}	
*/

void KHADE_ANGLE(int FINAL_L_ANGLE,int FINAL_R_ANGLE,bool frontleg)
{
	if(FINAL_R_ANGLE > FINAL_L_ANGLE)
	FINAL_R_ANGLE = FINAL_L_ANGLE;
	
	if(ang>FINAL_L_ANGLE || ang<FINAL_R_ANGLE)
	{
		if (frontleg==open)
		{
			waitms(100);
			reset(U2);
			waitms(500);//420);//400);//500);//300);
			
		} 
		
		
		if(FINAL_R_ANGLE>ang)
		{
			ERROR = FINAL_R_ANGLE - ang;
			while (ERROR>0)
			{
				cls();
				lcd((int)ang);
				if(1)//ERROR>15)
				{
					
					//if(ERROR>5)
					if (frontleg==open)
					{
							ANGLE_DELAY = -0.1243*(ERROR*ERROR) + 10.4*(ERROR) + 51.03;//(9/4)*(ERROR)+190;
					} 
					else
					{
						if(R_GEREGE==1)
							ANGLE_DELAY=235;//255//243;//213;//190;//220;///200;//220;//190;//130;		
						else
							ANGLE_DELAY=235;//222;//235;
					}
						//ANGLE_DELAY = -0.1243*(ERROR*ERROR) + 10.4*(ERROR) + 51.03;//(9/4)*(ERROR)+190;
// 					else
// 						ANGLE_DELAY = (38)*(ERROR);
// 					if (n_jump<5)
// 						if(ANGLE_DELAY > 210)//228);//235)
// 							ANGLE_DELAY = 210;//228;//235;
// 					else
// 						if(ANGLE_DELAY > 170)//228);//235)
// 							ANGLE_DELAY = 170;//228;//235;
					if (frontleg==open)
					{
						if(ANGLE_DELAY < 62)
							ANGLE_DELAY = 62;
					}
					
					lcd((char*)"left");
					lcd(ANGLE_DELAY);
					//waitms(500);
					set(R);    //khade khade turn
					waitms(ANGLE_DELAY);//235);//240);//245);//250);//270);//225);//DELAY_angle_l);//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151   CHANGE HERE
					reset(R);
					waitms(1.5*ANGLE_DELAY+50);//270*3);//angle_STEP_DELAY);//300);//400);
				}
				else
				{
					ANGLE_DELAY = KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle + 0.6*(ERROR);
					if(ANGLE_DELAY > angle_DELAY_U)
					{
						ANGLE_DELAY = angle_DELAY_U;
					}
					if(ANGLE_DELAY < angle_DELAY_L)
					{
						ANGLE_DELAY = angle_DELAY_L;
					}
					
					ANGLE_FLAG=1;   //////for left
					lcd((char*)"bleft");
					lcd(ANGLE_DELAY);
					lowerline();
					lcd((int)ang);
					set(R);
					waitms(ANGLE_DELAY);
					reset(R);
					waitms(2*ANGLE_DELAY+50);
				}
				ERROR = 0 - ang;
			}
		}
		else
		{
			ERROR = ang - FINAL_L_ANGLE;
			while (ERROR>0)
			{
				cls();
				lcd(ang,2);
				if(1)//ERROR>15)
				{
				/*
					if(ERROR>5)
						ANGLE_DELAY = (9/4)*(ERROR)+190;
					else
						ANGLE_DELAY = (38)*(ERROR);
					
					if (n_jump<5)
					{
							if(ANGLE_DELAY > 235)
							ANGLE_DELAY = 235;
					}
					else
					{
						if(ANGLE_DELAY > 170)//228);//235)
							ANGLE_DELAY = 170;//228;//235;
					}
				*/
				if (frontleg==open)
				{
					ANGLE_DELAY = -0.1243*(ERROR*ERROR) + 10.4*(ERROR) + 51.03;//(9/4)*(ERROR)+190;
					if(ANGLE_DELAY <  81)//87)//80)//90)//114)//38)
					{
						ANGLE_DELAY =  81;//87;//80;//90;//114;//38;
					}
				}
				else
				{	
					if(R_GEREGE==1)
						ANGLE_DELAY=200;//190;//220;//200;//220;//190;//130;
					else
						ANGLE_DELAY=220;
				}
					lcd((char*)"sright");
					lcd(ANGLE_DELAY);
					//waitms(500);
					set(L);    //khade khade turn
					waitms(ANGLE_DELAY);//235);//245);//250);//225);//DELAY_angle_l);//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151 CHANGE HERE
					reset(L);
					waitms(1.5*ANGLE_DELAY+50);//270*3);//angle_STEP_DELAY);//300);//400);
				}
				else
				{
					//ANGLE_DELAY = KpA4*pow(ERROR,4) + KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle;
					ANGLE_DELAY = KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle + 0.6*(ERROR);
					if(ANGLE_DELAY > angle_DELAY_U)
					{
						ANGLE_DELAY = angle_DELAY_U;
					}
					if(ANGLE_DELAY < angle_DELAY_L)
					{
						ANGLE_DELAY = angle_DELAY_L;
					}
					//ANGLE_DELAY = (-1)*KpA*(ERROR);
					ANGLE_FLAG=0;        ///////////////for right
					lcd((char*)"right");
					lowerline();
					lcd(ANGLE_DELAY);
					set(L);
					waitms(ANGLE_DELAY);
					reset(L);
					waitms(2*ANGLE_DELAY + 50);
					cls();
				}
				ERROR = ang - 0;//FINAL_L_ANGLE;
			}
		}
		if (frontleg==open)
		{
			set(U2);
			waitms(300);//150);//300);
		} 
	
			
	}
	
		
	 lcd(" ");
	 lcd((int)ang);
	 
}


/*
void KHADE_ANGLE(int FINAL_L_ANGLE,int FINAL_R_ANGLE)
{
	if(FINAL_R_ANGLE > FINAL_L_ANGLE)
	FINAL_R_ANGLE = FINAL_L_ANGLE;
	
	if(ang>FINAL_L_ANGLE || ang<FINAL_R_ANGLE)
	{
		waitms(100);
		reset(U2);
		waitms(500);//420);//400);//500);//300);
		
		if(FINAL_R_ANGLE>ang)
		{
			ERROR = FINAL_R_ANGLE - ang;
			while (ERROR>0)
			{
				cls();
				lcd(ang);
				if(1)//ERROR>15)
				{
					if(ERROR>5)
						ANGLE_DELAY = (9/4)*(ERROR)+190;
					else
						ANGLE_DELAY = (38)*(ERROR);
					if (n_jump<5)
						if(ANGLE_DELAY > 210)//228);//235)
							ANGLE_DELAY = 210;//228;//235;
					else
						if(ANGLE_DELAY > 170)//228);//235)
							ANGLE_DELAY = 170;//228;//235;
					
					if(ANGLE_DELAY < 81)//87)//80)//90)//114)//38)
					{
						ANGLE_DELAY = 81;//87;//80;//90;//114;//38;
					}
					//lcd((char*)"left");
					set(R);    //khade khade turn
					waitms(ANGLE_DELAY);//235);//240);//245);//250);//270);//225);//DELAY_angle_l);//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151   CHANGE HERE
					reset(R);
					waitms(1.5*ANGLE_DELAY+50);//270*3);//angle_STEP_DELAY);//300);//400);
				}
				else
				{
					ANGLE_DELAY = KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle + 0.6*(ERROR);
					if(ANGLE_DELAY > angle_DELAY_U)
					{
						ANGLE_DELAY = angle_DELAY_U;
					}
					if(ANGLE_DELAY < angle_DELAY_L)
					{
						ANGLE_DELAY = angle_DELAY_L;
					}
					
					ANGLE_FLAG=1;   //////for left
					lcd((char*)"bleft");
					lowerline();
					lcd(ANGLE_DELAY);
					lcd((int)ang);
					set(R);
					waitms(ANGLE_DELAY);
					reset(R);
					waitms(2*ANGLE_DELAY+50);
				}
				ERROR = 0 - ang;
			}
		}
		else
		{
			ERROR = ang - FINAL_L_ANGLE;
			while (ERROR>0)
			{
				cls();
				lcd(ang,2);
				if(1)//ERROR>15)
				{
					if(ERROR>5)
						ANGLE_DELAY = (9/4)*(ERROR)+190;
					else
						ANGLE_DELAY = (38)*(ERROR);
					
					if (n_jump<5)
					{
							if(ANGLE_DELAY > 235)
							ANGLE_DELAY = 235;
					}
					else
					{
						if(ANGLE_DELAY > 170)//228);//235)
							ANGLE_DELAY = 170;//228;//235;
					}
					if(ANGLE_DELAY <  81)//87)//80)//90)//114)//38)
					{
						ANGLE_DELAY =  81;//87;//80;//90;//114;//38;
					}
					lcd((char*)"sright");
					set(L);    //khade khade turn
					waitms(ANGLE_DELAY);//235);//245);//250);//225);//DELAY_angle_l);//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151 CHANGE HERE
					reset(L);
					waitms(1.5*ANGLE_DELAY+50);//270*3);//angle_STEP_DELAY);//300);//400);
				}
				else
				{
					//ANGLE_DELAY = KpA4*pow(ERROR,4) + KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle;
					ANGLE_DELAY = KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle + 0.6*(ERROR);
					if(ANGLE_DELAY > angle_DELAY_U)
					{
						ANGLE_DELAY = angle_DELAY_U;
					}
					if(ANGLE_DELAY < angle_DELAY_L)
					{
						ANGLE_DELAY = angle_DELAY_L;
					}
					//ANGLE_DELAY = (-1)*KpA*(ERROR);
					ANGLE_FLAG=0;        ///////////////for right
					lcd((char*)"right");
					lowerline();
					lcd(ANGLE_DELAY);
					set(L);
					waitms(ANGLE_DELAY);
					reset(L);
					waitms(2*ANGLE_DELAY + 50);
					cls();
				}
				ERROR = ang - 0;//FINAL_L_ANGLE;
			}
		}
		set(U2);
		waitms(300);//150);//300);	
	}
	
		
	 lcd(" ");
	 lcd((int)ang);
	 
}
*/

/*
//////////////////////NEW///////////////////////////////////////////////////////

double cubic_root(double a,double b,double c,double d)
{
	cls();
	root_1 = cbrt(   ((-1)*pow(b,3) )/(27*pow(a,3)) + (b*c)/(6*pow(a,2)) - d/(2*a)  + sqrt( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ) ) + cbrt(    ((-1)*pow(b,3) )/(27*pow(a,3)) + (b*c)/(6*pow(a,2)) - d/(2*a)  +  sqrt( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ) ) - b/(3*a);
	
	root_2 = cbrt(   ((-1)*pow(b,3) )/(27*pow(a,3)) + (b*c)/(6*pow(a,2)) - d/(2*a)  + sqrt( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ) ) + cbrt(    ((-1)*pow(b,3) )/(27*pow(a,3)) + (b*c)/(6*pow(a,2)) - d/(2*a)  -  sqrt( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ) ) - b/(3*a);

	root_3 = cbrt(   ((-1)*pow(b,3) )/(27*pow(a,3)) + (b*c)/(6*pow(a,2)) - d/(2*a)  - sqrt( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ) ) + cbrt(    ((-1)*pow(b,3) )/(27*pow(a,3)) + (b*c)/(6*pow(a,2)) - d/(2*a)  -  sqrt( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ) ) - b/(3*a);
	
	
	
	
	
	lcd(( pow( (  ((-1)*pow(b,3))/(27*pow(a,3))  +  (b*c)/(6*pow(a,2))  -  d/(2*a) ),2)  +  pow( (  c/(3*a) -  pow(b,2)/( 9*pow(a,2) ) ),3) ));
	//lcd(root_1,6);
	lcd(" ");
	lcd(root_1,6);
	//lcd(sqrt(-1));
	
	lowerline();
	lcd(root_2,5);
	lcd(" ");

	lcd(root_3,5);
	lcd(" ");

}//
*/

////NEW
void RANGE55(int angle)
{
	ERROR_LONG_C = angle - ang;
		if(ERROR_LONG_C>0)
		{
			CHALTE_LONG_FLAG=1;           /////for left
			//lcd((char*)"left");
			
			angle_DELAY = -0.0117*(ERROR_LONG_C)*(ERROR_LONG_C) + 2.2563*(ERROR_LONG_C) + 12.3604;
			ANGLE_ERROR =  -0.1420*(ERROR_LONG_C) + 0.5164;
			set(R);
		}
		else
		{
			ERROR_LONG_C = (-1)*ERROR_LONG_C;
			CHALTE_LONG_FLAG=0;        ///////////////for right
			//lcd((char*)"right");
						
			angle_DELAY = -0.0085*(ERROR_LONG_C)*(ERROR_LONG_C) + 2.1221*(ERROR_LONG_C) + 4.1520;
			
			if(ERROR_LONG_C<43)
			{
				ANGLE_ERROR=2;//-2;
			}
			else
			{
				ANGLE_ERROR=3;
			}
			set(L);
		}
		
		waitms(angle_DELAY);
		set(L);
		set(R);
		waitms(137);
		reset(L);
		reset(R);
		waitms(700);//200);
		if (R_GEREGE==1)
		ang=ang - ANGLE_ERROR +8;//10;
		else
		ang=ang - ANGLE_ERROR;
		//cls();
		//lcd(ERROR_LONG_C);
		//waitms(1000);
}


/////////NEW
void Ultimate_jump_s(double angle, double DISTANCE,bool NEXT_STEP,int frontleg)
{
	
	/*
	if(SENSOR == back)
	ERROR_S = DISTANCE;
	//ERROR_S = DISTANCE - dist_ultra3;////DISTANCE-dist_ultra3;
	
	if(SENSOR == front)
	ERROR_S = DISTANCE;
	//ERROR_S =  dist_ultra3 - DISTANCE;////DISTANCE-dist_ultra3;
	//cls();
	*/
	unsigned short int next_step=0;
	
	INITIAL_ANGLE=ang;
	ERROR_LONG_C = angle - ang;
	
	ERROR_S=DISTANCE;
	while(next_step<=NEXT_STEP)
	{
		if(ERROR_S>0)
		{
			//cls();
			//lcd("E");
			//lcd(ERROR_S);
			
			//lcd("A");
			//lcd(ERROR_LONG_C);
			//waitms(1000);
			//if(1)//(unsigned int)ERROR_LONG_C>20)
			{
				STRAIGHT_DELAY = 54.05 + 1.52*(ERROR_S);
				STRAIGHT_FLAG = 1;
			}
		
		}
		else
		{
			STRAIGHT_FLAG = 0;
		}
		if(STRAIGHT_FLAG)
		{
		if(STRAIGHT_DELAY > STRAIGHT_80DELAY_U)
		{
			STRAIGHT_DELAY = STRAIGHT_80DELAY_U;
		}
	
		if(STRAIGHT_DELAY < STRAIGHT_80DELAY_L)
		{
			STRAIGHT_DELAY = STRAIGHT_80DELAY_L;
		}
	
		//lowerline();
		//lcd("D");
		//STRAIGHT_DELAY*=interrupt_constant;
		//lcd(STRAIGHT_DELAY);
		//waitms(1000);
		if ( ( (ERROR_LONG_C>3 || ERROR_LONG_C<-1) && R_GEREGE==(-1) ) || (  R_GEREGE==(1) ) )//ERROR_LONG_C<4 || ERROR_LONG_C>-4)
		{
			if(ERROR_LONG_C>0)
			{
				CHALTE_LONG_FLAG=1;           /////for left
				//lcd((char*)"left");
			
				//if(R_GEREGE==1)                      //Left Turn (26.04.19)
				/*{		//GEREGE SIDE AS RED SIDE
					a = P20 + P21*STRAIGHT_DELAY;
					b = P10 + P11*STRAIGHT_DELAY + P12*pow(STRAIGHT_DELAY,2);
					c = P00 + P01*STRAIGHT_DELAY + P02*pow(STRAIGHT_DELAY,2)+ P03*pow(STRAIGHT_DELAY,3) - ERROR_LONG_C;
				  }
				  */
				//else
				{
					a = P_20 + P_21*STRAIGHT_DELAY;
					b = P_10 + P_11*STRAIGHT_DELAY + P_12*pow(STRAIGHT_DELAY,2);
					c = P_00 + P_01*STRAIGHT_DELAY + P_02*pow(STRAIGHT_DELAY,2)+ P_03*pow(STRAIGHT_DELAY,3) - ERROR_LONG_C;
			
				}
				angle_DELAY_UPPER = 120;
			}
			else
			{
				ERROR_LONG_C = (-1)*ERROR_LONG_C;
				CHALTE_LONG_FLAG=0;        ///////////////for right
				//lcd((char*)"right");
				//if(R_GEREGE==1)
				/*{
					a = P_20 + P_21*STRAIGHT_DELAY;
					b = P_10 + P_11*STRAIGHT_DELAY + P_12*pow(STRAIGHT_DELAY,2);
					c = P_00 + P_01*STRAIGHT_DELAY + P_02*pow(STRAIGHT_DELAY,2)+ P_03*pow(STRAIGHT_DELAY,3) - ERROR_LONG_C;
				}*/
				//else
				{		//GEREGE SIDE AS BLUE SIDE
					a = P20 + P21*STRAIGHT_DELAY;
					b = P10 + P11*STRAIGHT_DELAY + P12*pow(STRAIGHT_DELAY,2);
					c = P00 + P01*STRAIGHT_DELAY + P02*pow(STRAIGHT_DELAY,2)+ P03*pow(STRAIGHT_DELAY,3) - ERROR_LONG_C;
	
				}
				angle_DELAY_UPPER = 120;
			}
	

			/*
			//ANGLE = P00 + P10*d1
			a = P20 + P21*STRAIGHT_DELAY + P22*pow(STRAIGHT_DELAY,2);
			b = P10 + P11*STRAIGHT_DELAY + P12*pow(STRAIGHT_DELAY,2)+ P13*pow(STRAIGHT_DELAY,3);
			c = P00 + P01*STRAIGHT_DELAY + P02*pow(STRAIGHT_DELAY,2)+ P03*pow(STRAIGHT_DELAY,3)+ P04*pow(STRAIGHT_DELAY,4) - ERROR_LONG_C;
			*/
			/*
			a = p50;
			b = p40 + p41*(STRAIGHT_DELAY);
			c = p30 + p31*(STRAIGHT_DELAY) + p32*pow(STRAIGHT_DELAY,2);
			d = p20 + p21*(STRAIGHT_DELAY) + p22*pow(STRAIGHT_DELAY,2) + p23*pow(STRAIGHT_DELAY,3);	
			e = p10 + p21*(STRAIGHT_DELAY) + p12*pow(STRAIGHT_DELAY,2) + p13*pow(STRAIGHT_DELAY,3) + p14*pow(STRAIGHT_DELAY,4);
			f = p00	+ p01*(STRAIGHT_DELAY) + p02*pow(STRAIGHT_DELAY,2) + p03*pow(STRAIGHT_DELAY,3) + p04*pow(STRAIGHT_DELAY,4) + p05*pow(STRAIGHT_DELAY,5) -ERROR_LONG_C;
			*/
			/*
			cls();
			lcd(a,2);
			lcd(" ");
			lcd(b,2);
			lcd(" ");
			lcd(c,2);
			*/
		/*	lowerline();
			lcd(d,2);
			lcd(" ");
			lcd(e,2);
			lcd(" ");
				lcd(f,2);
				lcd(" ");
			waitms(1500);//4500);
			*/

			//angle_DELAY_UPPER = ka4*pow(STRAIGHT_DELAY,4) + ka3*pow(STRAIGHT_DELAY,3) + ka2*pow(STRAIGHT_DELAY,2) + ka1*(STRAIGHT_DELAY) + ka0;
	
			angle_DELAY = quadratic_root(a,b,c,5,angle_DELAY_UPPER);
			//cls();
			if(angle_DELAY_E)
			{
		
				x = angle_DELAY_UPPER;
				y = STRAIGHT_DELAY;
				if (CHALTE_LONG_FLAG)
				{						//left
					if(R_GEREGE==1)
					{
						ANGLE_ERROR = ERROR_LONG_C -( P10*x + P01*y + P20*pow(x,2) + P11*x*y + P02*pow(y,2) + P21*pow(x,2)*y + P12*x*pow(y,2) + P03*pow(y,3) );
					}
					else
					{
						ANGLE_ERROR = ERROR_LONG_C -( P_10*x + P_01*y + P_20*pow(x,2) + P_11*x*y + P_02*pow(y,2) + P_21*pow(x,2)*y + P_12*x*pow(y,2) + P_03*pow(y,3) );
					}
					if(ANGLE_ERROR>0)
					{
						//cls();
						//lcd("hello");
						KHADE_ANGLE_O(ANGLE_ERROR+4,ANGLE_ERROR-4);//2BUFFER
					}
					else
					KHADE_ANGLE_O((-1)*ANGLE_ERROR+4,(-1)*ANGLE_ERROR-4);//2BUFFER
			
				}
				else
				{						//right
					if(R_GEREGE==1)
					{
						ANGLE_ERROR = ERROR_LONG_C -( P_10*x + P_01*y + P_20*pow(x,2) + P_11*x*y + P_02*pow(y,2) + P_21*pow(x,2)*y + P_12*x*pow(y,2) + P_03*pow(y,3) );

					}
					else
					{
						ANGLE_ERROR = ERROR_LONG_C -( P10*x + P01*y + P20*pow(x,2) + P11*x*y + P02*pow(y,2) + P21*pow(x,2)*y + P12*x*pow(y,2) + P03*pow(y,3) );
					}
					if(ANGLE_ERROR>0)
						KHADE_ANGLE_O(ANGLE_ERROR+4,ANGLE_ERROR-4);//2BUFFER
					else
						KHADE_ANGLE_O((-1)*ANGLE_ERROR+4,(-1)*ANGLE_ERROR-4);//2BUFFER
			
				}
		
				//cls();
				//lcd(ANGLE_ERROR,2);
			}
			else
				ANGLE_ERROR=0;
			
		}
		else
		{
			//angle_DELAY=1;
			ERROR_LONG_C=0;
		}
		//lcd(" ");
		//lowerline();
	
		////////recently removed
		//lcd(angle_DELAY);
		//lcd("s");
		//lcd(STRAIGHT_DELAY);
		
		//waitms(4000);
			if(CHALTE_LONG_FLAG)          //for left	/////////////CHALTE CHALTE LEFT TO 45
			{	                             //CHALTE CHALTE LEFT
			
				if(((int)(ERROR_LONG_C))>2)//!=0)
				{
					set(R);	
					waitms(angle_DELAY);  //85);  //70);   //100); //30);          85-315-700 for lateral
					set(L);
				}
				else
				{
					set(L);
					set(R);
				}
				if( (frontleg==close) || (frontleg==close_open) )
				{
				waitms(100);
				set(U2);	
				if(STRAIGHT_DELAY>100)
				waitms((STRAIGHT_DELAY-100));  //100); //100); //140);      ///350); FOR P_4_5
				else
				waitms(1);
				}
				else
				waitms(STRAIGHT_DELAY);//*interrupt_constant);
				reset(R);
				//waitms(80);  //70); //100); //70);
				reset(L);
				if ( (frontleg==close_open) && ERROR_S>50)
				{
					
					waitms(50);
					reset(U2);
				}
				else if ( (frontleg==close_open))
				{
					reset(U2);
				}
				waitms(STRAIGHT_DELAY*2.5);//2.5//*1.7);//*1.432);//*1);////*0.3);//*0.1);//*0.4);//*1);//*1.132);//*1.432);//400);//360//400);//700);//700);
				long_jump++;
			}
			else            //for right
			{
				set(L);
				if(((int)(ERROR_LONG_C))>2)//!=0)
				waitms(angle_DELAY);  //85);  //70);   //100); //30);          85-315-700 for lateral
				set(R);
				if( (frontleg==close) || (frontleg==close_open) )
				{
					waitms(100);
					set(U2);
					if(STRAIGHT_DELAY>100)
					waitms((STRAIGHT_DELAY-100));  //100); //100); //140);      ///350); FOR P_4_5
					else
					waitms(1);
				}
				else
				waitms(STRAIGHT_DELAY);//310);
				reset(L);
				//waitms(80);  //70); //100); //70);
				reset(R);
				if ( (frontleg==close_open) && ERROR_S>50)
				{
					
					waitms(50);
					reset(U2);
				}
				else if ( (frontleg==close_open))
				{
					reset(U2);
				}
				waitms(STRAIGHT_DELAY*2.5);//2.5//*1.7);//*1.432);//*1);//*0.3);//*0.1);//*0.4);//*0.75);//*1);//*1.132);//*1.432);//360);//400);//700);//700);
				long_jump++;
			}
		}
		/*
		l=ang;
		set(L);
		waitms(50);
		set(R);
		waitms(STRAIGHT_DELAY);      ///change range
		reset(L);
		reset(R);
		waitms(930);
		//waitms(1000);
		lcd(ang-l,2);	
		*/
		
		
		//x = (INITIAL_ANGLE-ang);
		////////recently removed
		//cls();
		//lcd(x);
		//waitms(500);

// 		if (x<0)
// 		{
// 			x=x*(-1);
// 		}
 		if (ERROR_LONG_C>33)//x>33)
		{
			//c0 + c1*(x) + c2*pow(x,2) + c3*pow(x,3);
		////////recently removed
			//lcd((int)CORRECT);
		
			if(CHALTE_LONG_FLAG)///left turn angle increases in -ve
				{
					CORRECT =  -0.1420*(ERROR_LONG_C) + 0.5164;		
					//ang += CORRECT;//11.25;
				}
			else         ///right turn angle increases in +ve
				{
					if (ERROR_LONG_C<43)
					{
						CORRECT = 2;
					} 
					else
					{
						CORRECT = 3;
					}
					
				}
				if (POINT_3)
				{
					ang = ang - CORRECT + R_GEREGE*5;//+2;
				} 
				else
				{
					ang = ang - CORRECT + R_GEREGE*2;//11.25;		
				}
				 
		}
 		
		
		if(upper)
		{
			//cls();
			//lcd("INCREASE ME");
			//waitms(300);
			ERROR_S -= 85;//100;//90;//80;//90;//115;//104;
			waitms(50);
			//KHADE_ANGLE_O(angle+4,angle-4);//samall upper//4 BUFFFER//2BUFFER
		}
		else
		ERROR_S=0;
		
		//waitms(50);
		next_step++;
		
	}
}



/*
/////////NEW
void BLIND_Ultimate_jump(double angle, double DISTANCE)
{
	
	ERROR_S=DISTANCE;
	while (ERROR_S>0)
	{
		if(ERROR_S>0)
		{
			//cls();
			//lcd("E");
			//lcd(ERROR_S);
			//waitms(1000);
			if(1)//ERROR_S>20)
			{
				STRAIGHT_DELAY = BASE_DELAY_S + KpS*(ERROR_S) + KpS2*(ERROR_S*ERROR_S);
				STRAIGHT_FLAG = 1;
			}
			else
			{
						x=ERROR_S;
							STRAIGHT_DELAY = a0 +a1*cos(x*w) + b1*sin(x*w) +a2*cos(2*x*w) + b2*sin(2*x*w) + a3*cos(3*x*w) + b3*sin(3*x*w) + a4*cos(4*x*w) + b4*sin(4*x*w)+ a5*cos(5*x*w) + b5*sin(5*x*w) + a6*cos(6*x*w) + b6*sin(6*x*w);
							STRAIGHT_FLAG = 1;
			}
		}
		if(STRAIGHT_DELAY > STRAIGHT_50DELAY_U)
		{
			upper=1;
			STRAIGHT_DELAY = STRAIGHT_50DELAY_U;
		}
		else
			upper=0;
		if(STRAIGHT_DELAY < STRAIGHT_50DELAY_L)
		{
			STRAIGHT_DELAY = STRAIGHT_50DELAY_L;
		}
	
		//lowerline();
		//lcd("D");
		//lcd(STRAIGHT_DELAY);
		ERROR_LONG_C = angle - ang;
	
		if(ERROR_LONG_C>0)
		{
			CHALTE_LONG_FLAG=1;           /////for left
			//lcd((char*)"left");
			if(R_GEREGE==1)
			{		//GEREGE SIDE AS RED SIDE
				a = P20 + P21*STRAIGHT_DELAY + P22*pow(STRAIGHT_DELAY,2);
				b = P10 + P11*STRAIGHT_DELAY + P12*pow(STRAIGHT_DELAY,2)+ P13*pow(STRAIGHT_DELAY,3);
				c = P00 + P01*STRAIGHT_DELAY + P02*pow(STRAIGHT_DELAY,2)+ P03*pow(STRAIGHT_DELAY,3)+ P04*pow(STRAIGHT_DELAY,4) - ERROR_LONG_C;
				angle_DELAY_UPPER = 105;
			}
			else
			{
				a = P_20 + P_21*STRAIGHT_DELAY + P_22*pow(STRAIGHT_DELAY,2) + P_23*pow(STRAIGHT_DELAY,3);
				b = P_10 + P_11*STRAIGHT_DELAY + P_12*pow(STRAIGHT_DELAY,2)+ P_13*pow(STRAIGHT_DELAY,3) + P_14*pow(STRAIGHT_DELAY,4);
				c = P_00 + P_01*STRAIGHT_DELAY + P_02*pow(STRAIGHT_DELAY,2)+ P_03*pow(STRAIGHT_DELAY,3) + P_04*pow(STRAIGHT_DELAY,4) + P_05*pow(STRAIGHT_DELAY,5) - ERROR_LONG_C;
				angle_DELAY_UPPER = 120;
			}
		}
		else
		{
			ERROR_LONG_C = (-1)*ERROR_LONG_C;
			CHALTE_LONG_FLAG=0;        ///////////////for right
			//lcd((char*)"right");
			if(R_GEREGE==1)
			{
				a = P_20 + P_21*STRAIGHT_DELAY + P_22*pow(STRAIGHT_DELAY,2) + P_23*pow(STRAIGHT_DELAY,3);
				b = P_10 + P_11*STRAIGHT_DELAY + P_12*pow(STRAIGHT_DELAY,2)+ P_13*pow(STRAIGHT_DELAY,3) + P_14*pow(STRAIGHT_DELAY,4);
				c = P_00 + P_01*STRAIGHT_DELAY + P_02*pow(STRAIGHT_DELAY,2)+ P_03*pow(STRAIGHT_DELAY,3) + P_04*pow(STRAIGHT_DELAY,4) + P_05*pow(STRAIGHT_DELAY,5) - ERROR_LONG_C;
				angle_DELAY_UPPER = 120;
			}
			else
			{		//GEREGE SIDE AS BLUE SIDE
				a = P20 + P21*STRAIGHT_DELAY + P22*pow(STRAIGHT_DELAY,2);
				b = P10 + P11*STRAIGHT_DELAY + P12*pow(STRAIGHT_DELAY,2)+ P13*pow(STRAIGHT_DELAY,3);
				c = P00 + P01*STRAIGHT_DELAY + P02*pow(STRAIGHT_DELAY,2)+ P03*pow(STRAIGHT_DELAY,3)+ P04*pow(STRAIGHT_DELAY,4) - ERROR_LONG_C;
				angle_DELAY_UPPER = 105;
			}
		}

	
		angle_DELAY = quadratic_root(a,b,c,5,angle_DELAY_UPPER);
		//cls();
		if(angle_DELAY_E)
		{
		
			x = angle_DELAY_UPPER;
			y = STRAIGHT_DELAY;
			if (CHALTE_LONG_FLAG)
			{						//left
				if(R_GEREGE==1)
				{
					ANGLE_ERROR = ERROR_LONG_C -( P10*x + P01*y + P20*pow(x,2) + P11*x*y + P02*pow(y,2) + P21*pow(x,2)*y + P12*x*pow(y,2) + P03*pow(y,3) + P22*pow(x,2)*pow(y,2) + P13*x*pow(y,3) + P04*pow(y,4) );
				}
				else
				{
					ANGLE_ERROR = ERROR_LONG_C -( P_10*x + P_01*y + P_20*pow(x,2) + P_11*x*y + P_02*pow(y,2) + P_21*pow(x,2)*y + P_12*x*pow(y,2) + P_03*pow(y,3) + P_22*pow(x,2)*pow(y,2) + P_13*x*pow(y,3) + P_04*pow(y,4) + P_23*pow(x,2)*pow(y,3) + P_14*x*pow(y,4) + P_05*pow(y,5));

				}
				ANGLE_ERROR = ANGLE_ERROR;//KHADE_ANGLE_O(ANGLE_ERROR+2,ANGLE_ERROR-2);
			}
			else
			{						//right
				if(R_GEREGE==1)
				{
					ANGLE_ERROR = ERROR_LONG_C -( P_10*x + P_01*y + P_20*pow(x,2) + P_11*x*y + P_02*pow(y,2) + P_21*pow(x,2)*y + P_12*x*pow(y,2) + P_03*pow(y,3) + P_22*pow(x,2)*pow(y,2) + P_13*x*pow(y,3) + P_04*pow(y,4) + P_23*pow(x,2)*pow(y,3) + P_14*x*pow(y,4) + P_05*pow(y,5));

				}
				else
				{
					ANGLE_ERROR = ERROR_LONG_C -( P10*x + P01*y + P20*pow(x,2) + P11*x*y + P02*pow(y,2) + P21*pow(x,2)*y + P12*x*pow(y,2) + P03*pow(y,3) + P22*pow(x,2)*pow(y,2) + P13*x*pow(y,3) + P04*pow(y,4) );
				}
				ANGLE_ERROR = (-1)*ANGLE_ERROR;//KHADE_ANGLE_O( (-1)*ANGLE_ERROR + 2 , (-1)*ANGLE_ERROR - 2 );
			}
		
			//cls();
			//lcd(ANGLE_ERROR,2);
		}
	
		//lcd(" ");
		//lcd(angle_DELAY);
		//lcd(" ");
		//lcd(STRAIGHT_DELAY);
			if(CHALTE_LONG_FLAG)          //for left	/////////////CHALTE CHALTE LEFT TO 45
			{	                             //CHALTE CHALTE LEFT
				set(R);
				if(((int)(ERROR_LONG_C))!=0)
				waitms(angle_DELAY);  //85);  //70);   //100); //30);          85-315-700 for lateral
				set(L);
				waitms(STRAIGHT_DELAY);  //100); //100); //140);      ///350); FOR P_4_5
				reset(R);
				//waitms(80);  //70); //100); //70);
				reset(L);
				waitms((STRAIGHT_DELAY)*1.432);//*1.432);//360//400);//700);//700);
				long_jump++;
			}
			else            //for right
			{
				set(L);
				if(((int)(ERROR_LONG_C))!=0)
				waitms(angle_DELAY);  //85);  //70);   //100); //30);          85-315-700 for lateral
				set(R);
				waitms(STRAIGHT_DELAY);//310);
				reset(L);
				//waitms(80);  //70); //100); //70);
				reset(R);
				waitms((STRAIGHT_DELAY)*1.432);//*!//*1.432);//400);//700);//700);
				long_jump++;
			}
			//KHADE_ANGLE_O(angle-ang+2,angle-ang-2);
			
			if(upper)
			{
				ERROR_S -= 100;//90;//80;//90;//115;//104;
				waitms(50);
				KHADE_ANGLE_O(angle+8,angle-4);//samall upper//4 BUFFFER//2BUFFER
			}
			else
				ERROR_S=0;
				
				waitms(50);
			//KHADE_ANGLE_OB(angle+4,angle-4);//2BUFFER	
			
	}
}
*/

			//////NEW
double quadratic_root(double a,double b,double c,int lower,int upper)
{
	/*
	//////////////////ax^2 + bx + c
		root = ( -b +- sqrt(b^2-4ac) )/2a
	
	*/
	
	////////recently removed
    cls();
	//lcd(c,5);
	//lcd(" ");
	
	angle_DELAY_E = 0;
	
	root_1 = (-b + sqrt((b*b)-(4*a*c) ))/(2*a);
	root_2 = (-b - sqrt((b*b)-(4*a*c) ))/(2*a);

	//lcd( sqrt(  pow(b,2) - (4*c*a) ) );
	
	////////////////////////////////////recently removed
	//lcd(root_1,6);
	//lcd(" ");
	
	//lcd(root_1,6);
	//lcd(sqrt(-1));
	
	////////recently removed
	//lowerline();
	//lcd(root_1,5);
	//waitms(1000);
	//lcd(" ");
	
	if(root_1<upper && root_1>lower)
		return root_1;
	else if(root_2<upper && root_2>lower)
		return root_2;
	else if(root_1 > upper || root_2 > upper)
		{
			
			if(root_1 > upper)
			angle_DELAY_E = root_1 - upper;
			else
			angle_DELAY_E = root_2 - upper;
			return upper;
		}
	else 
		return 20;
}

/*
	///////////NEW
double func(double x,double a, double b, double c, double d, double e, double f)
{
	VALUE = a*pow(x,5) + b*pow(x,4) + c*pow(x,3) + d*pow(x,2) + e*x +f;
	return VALUE;
}

	//////////NEW
// Prints root of func(x) with error of EPSILON
void bisection(double Aa, double Bb,double a, double b, double c, double d,double e,double f)
{
	if ((func(Aa,a,b,c,d,e,f) * func(Bb,a,b,c,d,e,f))>= 0)
	{
		lcd("You have not assumed right a and b");
		waitms(1500);
		return;
	}
	
	double Cc = Aa;
	while ((Bb-Aa) >= EPSILON)
	{
		// Find middle point
		Cc = (Aa+Bb)/2;
		
		// Check if middle point is root
		if (func(Cc,a,b,c,d,e,f) == 0.0)
		break;
		
		// Decide the side to repeat the steps
		else if (func(Cc, a, b, c, d,e,f)*func(Aa, a, b, c, d,e,f) < 0)
		Bb = Cc;
		else
		Aa = Cc;
	}
	cls();
	lcd("The value of root:");
	lowerline();
	lcd(Cc);
}
	///////////////////NEW
double derivative_px(double x , double coeff[9],double size)
{
	cls();
	lcd((int)coeff[2]);
	lcd(" ");
	lcd((int)coeff[3]);
	lcd(" ");
	lcd((int)coeff[4]);
	lcd(" ");
	lowerline();
	for (int I = 0; I < size; I++) 
	{
		sum = sum + (I+1)*coeff[I+1]*pow(x,I);
		//lcd(sum,2);
		lcd((int)coeff[7]);
		lcd(" ");
		lcd((int)coeff[8]);
		lcd(" ");
		lcd((int)coeff[9]);
		lcd(" ");
	}
		//cls();
		//lcd(sum,3);
	return sum;	
}
	
	///////////////////NEW
double newton_raphson(double coeff)
{
	
}

*/



////////////////////////NEW
//right side turn  

//delay                  angle       error            corrected angle
//145                    46         -1               45
//140                    40         0                40
//150                    50        (-5) to (-6)      45
//155                    (55)       -5              50


////left side turn	  (red)

//delay                 imu angle     error              actual corrected angle
//140                    43        (-1) to (-1.5)         45
//130                    37          0 to (-1)            37
//150                    47         ~~(-6)                53
//160                    50         ~~(-10)               60


void NEW_KHADE(int FINAL_ANGLE,int FINAL_R_ANGLE)
{
	bool RIGHT=0;
	bool BIG=0;
	bool steps=1;
	set(U2);
	waitms(200);
	n_jump=0;
	if(ang>FINAL_ANGLE)
	{
		ERROR = ang-FINAL_ANGLE;   //RIGHT
		RIGHT=1;
	}
	else
	{
		ERROR = FINAL_ANGLE - ang;  //LEFT
		RIGHT=0;
	}
	
	
	while(ERROR>35)//25)//40)//steps)//ERROR>35)
	{
		reset(U2);//khulla
		waitms(55);
		if (RIGHT)
		{
			cls();
			lcd("RIGHT");
				set(L);
				if (ERROR>48)//BIG)
				{
					waitms(155);//50 WITH -5 ERROR FOR IMU
				} 
				else
				{
					waitms(145);//45 WITH -1 ERROR FOR IMU
				}
				
				reset(L);
				waitms(20);
			set(U2);///com
			waitms(600);
			
			if (ERROR>48)//BIG)
			{
				ang=ang-5;
			}
			else
			{
				ang=ang-1;
			}
			
			ERROR = ang-FINAL_ANGLE;   //RIGHT			
		} 
		else
		{
				set(R);
				if (0)//ERROR>48)//BIG)
				{
					waitms(140);//45 with -1 - -1.5//150);//53 WITH -6 ERROR FOR IMU
				}
				else
				{
					waitms(130);//37 with 0-(-1) error//140);//45 WITH -1 TO -1.5 ERROR FOR IMU
				}
				reset(R);
				waitms(20);
			set(U2);///com
			waitms(600);		
			
			if (0)//ERROR>48)//BIG)
			{
				ang=ang-(-1.25);
			}
			else
			{
				ang=ang-(-0.5);//-1.25;
			}
			
			ERROR = FINAL_ANGLE - ang;  //LEFT
		}
		
		cls();
		lcd("E");
		lcd(ERROR);
		n_jump++;
		waitms(50);//500);
	}
	reset(R);
	reset(L);
	reset (U2);
	waitms(100);//50);
	if (n_jump==2 && R_GEREGE)
	{
		KHADE_ANGLE_O(FINAL_ANGLE -2,FINAL_ANGLE -2);
	}
	else
	{
		KHADE_ANGLE_O(FINAL_ANGLE,FINAL_ANGLE);
	}
}


////////////////////////NEW
//right side turn
/*

Right
Delay		80	90	100	110	120	130	140	150	160
Angle		-5	-7	-18	-28	-33	-40	-45	-56	toppel
Error		-1	-1	-1	-1	-1	-5	-6	-5
Final angle -4	-6	-17	-27	-32	-35	-39	-51	#VALUE!

//left side turn

Left
Delay		80	90	100	110	120	130	140	150
Angle 		5	18	27	29	32	43	50	51
Error		-2	-3	-3	-2	0	0	1	-8
Final angle	7	21	30	31	32	43	49	59

proportional new_khade

RIGHT
 p =

 0.0033    1.3054   77.5134

LEFT
 p =

 0.0135    0.7457   72.6202

LEFT ERROR
 p =

 0.0037   -0.1238   -1.5077

RIGHT ERROR
 p =

 -0.0020   -0.0042   -0.6947


*/


void PROPORTIONAL_NEW_KHADE(int FINAL_ANGLE,int FINAL_R_ANGLE,bool khade_Angle)
{
	bool RIGHT=0;
	bool BIG=0;
	bool steps=1;
	int ANGLE_ERROR_F=0;
	set(U2);
	waitms(200);
	
	n_jump=0;

	if(ang>FINAL_ANGLE)
	{
		ERROR = ang-FINAL_ANGLE;   //RIGHT
		if(ERROR<45 && (khade_Angle==yes) )
		{
			
	
			angle_DELAY =  0.0033*ERROR*ERROR  + 1.3054*ERROR + 77.5134;
			//ANGLE_ERROR = -0.0020*ERROR*ERROR  + -0.0042*ERROR  -0.6947; 
			
			if (angle_DELAY>140)
			{
				angle_DELAY=140;
			} 
		
			if (angle_DELAY<80)
			{
				angle_DELAY=80;
			}
			if (angle_DELAY<105)
			{
				ANGLE_ERROR=-5;
			}
			else if (angle_DELAY<125)
			{
				ANGLE_ERROR=-1;
			}
		}
		else
		{
			
			if(khade_Angle==no)
			{
			angle_DELAY=140;//140;//150;
			ANGLE_ERROR=-6;//-6;//-5;
			}
			else
			{
				
				
				angle_DELAY=130;//140;//150;
				ANGLE_ERROR=-5;//-6;//-5;
			}
			//n_jump++;		
		}
		RIGHT=1;
		
	}
	else
	{
		ERROR = FINAL_ANGLE - ang;  //LEFT
		if (ERROR<45 && (khade_Angle==yes) )
		{
		
			angle_DELAY = 0.0135*ERROR*ERROR +  0.7457*ERROR + 72.6202;
			//ANGLE_ERROR = 0.0037*ERROR*ERROR + -0.1238*ERROR   -1.5077;
			if (angle_DELAY>130)//135////140)//145)
			{
				//cls();
				//lcd("all is well");
				//waitms(400);
				angle_DELAY=130;//135;//140//145;
			}
			else if (angle_DELAY<80)
			{
				angle_DELAY=80;
			}
			
			
			if (angle_DELAY<85)
				ANGLE_ERROR=-2;
			else if (angle_DELAY<105)
			{
				ANGLE_ERROR=-3;
			}
			else if (angle_DELAY<115)
			{
				ANGLE_ERROR=-2;
			}
			else if (angle_DELAY<135)
			{
				ANGLE_ERROR=0;
			}
			else if (angle_DELAY>135)
			{
				ANGLE_ERROR=1;
			}
		}
		else
		{
			if(khade_Angle==no)
			{
				//if(ERROR<20)
				//set(G);
				angle_DELAY=130;//140;//140;
				ANGLE_ERROR=0;//1;//1;
			}
			else
			{
				angle_DELAY=120;//140;
				ANGLE_ERROR=0;//1;
			}

			
			//n_jump++;
		}
		
		
		
		RIGHT=0;
	}
	
		if(RIGHT)//R_GEREGE==1)//red
		ANGLE_ERROR_F= 0.1638*ERROR - 3.724;
		else
		ANGLE_ERROR_F= -0.06667*ERROR +1;
		while(ERROR>(25*khade_Angle))//9)//13)//9//35//25)//40)//steps)//ERROR>35)
		{
			reset(U2);//khulla
			waitms(55);
			cls();

			if (RIGHT)
			{

				lcd("RIGHT");
				set(L);
				
				waitms(angle_DELAY);//45 WITH -1 ERROR FOR IMU
				if(ERROR<20 && angle_DELAY==140)
				set(G);
				
				reset(L);
			} 
			else
			{
				lcd("LEFT");
				set(R);
				
				waitms(angle_DELAY);//45 WITH -1 ERROR FOR IMU
				if(ERROR<20 && angle_DELAY==130)
				set(G);
				
				reset(R);
			}
				
				waitms(20);
				set(U2);///com
				waitms(600);//1600);//600);//600);
				//cls();
				//lcd(ang);
				//lcd(" ");
				//lcd(ANGLE_ERROR);
					
				
			
			ang=ang - ANGLE_ERROR;
			if (RIGHT)
			{
				ERROR = ang-FINAL_ANGLE;   //RIGHT

				if(ERROR<45 && (khade_Angle==yes) )
				{
					
					
					angle_DELAY =  0.0033*ERROR*ERROR  + 1.3054*ERROR + 77.5134;
					//ANGLE_ERROR = -0.0020*ERROR*ERROR  + -0.0042*ERROR  -0.6947;
					
					if (angle_DELAY>140)//150)
					{
						angle_DELAY=140;//150;
					}
					else if (angle_DELAY<80)
					{
						angle_DELAY=80;
					}
					else if (angle_DELAY<105)
					{
						ANGLE_ERROR=-5;
					}
					else if (angle_DELAY<125)
					{
						ANGLE_ERROR=-1;
					}
				}
				else
				{
					
					if(khade_Angle==no)
					{
						//if(ERROR<20)
						//set(G);
						
						angle_DELAY=140;//140;//150;
						ANGLE_ERROR=-6;//-6;//-5;
					}
					else
					{
						angle_DELAY=130;//140;//150;
						ANGLE_ERROR=-5;//-6;//-5;
					}
					n_jump++;					
				}
			} 
			else
			{
				ERROR = FINAL_ANGLE - ang;  //LEFT
				if (ERROR<45 && (khade_Angle==yes) )
				{
					
					angle_DELAY = 0.0135*ERROR*ERROR +  0.7457*ERROR + 72.6202;
					//ANGLE_ERROR = 0.0037*ERROR*ERROR + -0.1238*ERROR   -1.5077;
					if (angle_DELAY>130)//135////140)//145)
					{
						//cls();
						//lcd("all is well");
						//waitms(400);
						angle_DELAY=130;//140//145;
					}
					else if (angle_DELAY<80)
					{
						angle_DELAY=80;
					}
					
					
					if (angle_DELAY<85)
						ANGLE_ERROR=-2;
					else if (angle_DELAY<105)
					{
						ANGLE_ERROR=-3;
					}
					else if (angle_DELAY<115)
					{
						ANGLE_ERROR=-2;
					}
					else if (angle_DELAY<135)
					{
						ANGLE_ERROR=0;
					}
					else if (angle_DELAY>135)
					{
						ANGLE_ERROR=1;
					}
					
				}
				else
				{
					if(khade_Angle==no)
					{
						//if(ERROR<20)
						//	set(G);
						angle_DELAY=140;//140;
						ANGLE_ERROR=1;//1;
					}
					else
					{
						angle_DELAY=130;//140;
						ANGLE_ERROR=0;//1;
					}
					n_jump++;				
				}
						
			}
			if (n_jump)
				waitms(150);//300);//100);
		}
		if (khade_Angle==no)
			set(G);
		
		cls();
		lcd("E");
		lcd(ERROR);
		//n_jump++;
		//waitms(50);//500);
		reset(R);
		reset(L);
		reset (U2);
		cls();
		lcd(ang);
		lcd(" ");
		lcd(ANGLE_ERROR);
		waitms(100);//0);//300);//100);//50);
			
		
		
	//if (n_jump==2 && R_GEREGE)
	{
		//KHADE_ANGLE_O(FINAL_ANGLE -2,FINAL_ANGLE -2);
	}
	//else
	{
		if(khade_Angle==yes)
		{
			KHADE_ANGLE_O(FINAL_ANGLE ,FINAL_ANGLE);
		}
			
	}
	ang = ang - ANGLE_ERROR_F;
}



////////////////////////NEW
 
 void KHADE_ANGLE_O(int FINAL_L_ANGLE,int FINAL_R_ANGLE,bool tussuk)   //boundary angles 
 {
	 if(FINAL_R_ANGLE > FINAL_L_ANGLE)
	 FINAL_R_ANGLE = FINAL_L_ANGLE;
	  
	 if(ang>FINAL_L_ANGLE || ang<FINAL_R_ANGLE)
	 {
		 if(FINAL_R_ANGLE>ang)
		 {
			 ERROR = FINAL_R_ANGLE - ang;
			 while (ERROR>0)
			 {
				
				 if(ERROR>12)
				 {
					 cls();
					 lcd((char*)"left");
					lcd(ang);
					 set(R);    //khade khade turn
					 if(tussuk==large)
						waitms(152*interrupt_constant);//152//165//148//140      // (27-4-19 - 124    )                               //100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151
					 else
						waitms(100*interrupt_constant);//115//140
					 reset(R);
					 if(tussuk==large)
					 waitms(angle_STEP_DELAY);//300);//400);                               //100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151
					 else
					 waitms(450*interrupt_constant);
					 
				 }
				 else
				 {
					 
					 {	
						 	//GEREGE SIDE AS RED SIDE
						 //cls();
						 //lcd((char*)"left");
						 lcd(ang);
						 ANGLE_DELAY =  KpA_3*pow(ERROR,3) + KpA_2*pow(ERROR,2) + (KpA_+2)*(ERROR) + BASE_angle_;
						 
						 
						 if(ANGLE_DELAY > 155)//140)
							 ANGLE_DELAY = 155;//140;
						  if (tussuk==small)
						  {
							  if(ANGLE_DELAY < 120)//138)//120)//98)//85)//80)
							  {
							//	  cls();
							//	  lcd("increase");
								  ANGLE_DELAY = 120;//138;//120;//98;//85;
							  }
						  }
						  else
						  {
							  
							  if(ANGLE_DELAY < 140)//90)//80)
							  {
							//	  cls();
							//	  lcd("increase");
								  ANGLE_DELAY = 140;//90;//80;
							  }
						  }
					 }
					 ANGLE_FLAG=1;   //////for left
	//				 lcd((char*)"bleft");
	//				 lcd(ANGLE_DELAY);
//					 lowerline();
	//				 lcd(ang,2);
					 set(R);
					 waitms(ANGLE_DELAY*interrupt_constant);
					 reset(R);
					 waitms(2*ANGLE_DELAY+20);//2*ANGLE_DELAY+50
				 }
				 ERROR = FINAL_R_ANGLE - ang;
			 }
		 }
		 else
		 {
			 ERROR = ang - FINAL_L_ANGLE;
			 while (ERROR>0)
			 {
				 cls();
				 lcd(ang,2); 
				 if(ERROR>12)
				 {
	 				 lcd((char*)"sright");
					 set(L);    //khade khade turn
					 if(tussuk==large)
						waitms(152*interrupt_constant);//140//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151
					 else
					 {
						 lcd((char*)"bye");
						waitms(100*interrupt_constant);//115//140
					 }
					 reset(L);
					if(tussuk==large)
					waitms(angle_STEP_DELAY);//300);//400);                               //100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151
					else
					waitms(450*interrupt_constant);
					
				 }
				 else
				 {
					 {		//GEREGE SIDE AS RED SIDE
						 ANGLE_DELAY =  KpA_3*pow(ERROR,3) + KpA_2*pow(ERROR,2) + (KpA_+2)*(ERROR) + BASE_angle_;
						 if (tussuk==large)
						 {
							 if(ANGLE_DELAY > 148)//140)
								 ANGLE_DELAY = 148;//140;
						 }
						 else
							 if(ANGLE_DELAY > 140)//*(2/3))
							 	 ANGLE_DELAY = 140;//*(2/3);
							 
						 if (tussuk==small)
						 {
							if(ANGLE_DELAY < 120)//138)//120)//98)//85)//80)
							{
							//	cls();
							//	lcd("increase");
								ANGLE_DELAY = 120;//138;//120;//98;//85;//80;
							}	 
						 } 
						 else
						 {
						 
							 if(ANGLE_DELAY < 140)//90)//80)
							 {
							//	 cls();
							//	 lcd("increase");		 
								 ANGLE_DELAY = 140;//90;//80;
							 }
						 }
					 }
					 //ANGLE_DELAY = (-1)*KpA*(ERROR);
					 ANGLE_FLAG=0;        ///////////////for right
//					 lcd((char*)"right");
//					 lcd(ANGLE_DELAY);
	//				 lowerline();
//					 lcd(ang,2);
					 set(L);
					 waitms(ANGLE_DELAY*interrupt_constant);
					 reset(L);
					 waitms(2*ANGLE_DELAY + 50);
					 cls();
				 }
				 ERROR = ang - FINAL_L_ANGLE;
			 }
		 }
	 }
 }




/*
 void KHADE_ANGLE_T(int FINAL_L_ANGLE,int FINAL_R_ANGLE)
 {
	 if(FINAL_R_ANGLE > FINAL_L_ANGLE)
	 FINAL_R_ANGLE = FINAL_L_ANGLE;
	  
	 if(ang>FINAL_L_ANGLE || ang<FINAL_R_ANGLE)
	 {
		 if(FINAL_R_ANGLE>ang)
		 {
			 ERROR = FINAL_R_ANGLE - ang;
			 while (ERROR>0)
			 {
				 cls();
				 lcd(ang);
				 if(ERROR>15)
				 {
					 lcd((char*)"left");
					 set(R);    //khade khade turn
					 waitms(80);//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151
					 reset(R);
					 waitms(3*80);//angle_STEP_DELAY);//300);//400);
				 }
				 else
				 {
					 ANGLE_DELAY = KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle;
					 if(ANGLE_DELAY > angle_DELAY_TU)
					 {
						 ANGLE_DELAY = angle_DELAY_TU;
					 }
					 if(ANGLE_DELAY < angle_DELAY_L)
					 {
						 ANGLE_DELAY = angle_DELAY_L;
					 }
					 ANGLE_FLAG=1;   //////for left
					 lcd((char*)"bleft");
					 lowerline();
					 lcd(ANGLE_DELAY);
					 lcd(ang,2);
					 set(R);
					 waitms(ANGLE_DELAY);
					 reset(R);
					 waitms(2*ANGLE_DELAY+50);
				 }
				 ERROR = FINAL_R_ANGLE - ang;
			 }
		 }
		 else
		 {
			 ERROR = ang - FINAL_L_ANGLE;
			 while (ERROR>0)
			 {
				 cls();
				 lcd(ang,2);
				 if(ERROR>15)
				 {
					 lcd((char*)"sright");
					 set(L);    //khade khade turn
					 waitms(80);//100);///70);//100);//       ///doubtfull    MAIN FOR LATERAL151
					 reset(L);
					 waitms(3*80);//angle_STEP_DELAY);//300);//400);
				 }
				 else
				 {
					 //ANGLE_DELAY = KpA4*pow(ERROR,4) + KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle;
						ANGLE_DELAY =  KpA3*pow(ERROR,3) + KpA2*pow(ERROR,2) + KpA*(ERROR) + BASE_angle + 0.6*(ERROR);
					 if(ANGLE_DELAY > angle_DELAY_TU)
					 {
						 ANGLE_DELAY = angle_DELAY_TU;
					 }
					 if(ANGLE_DELAY < angle_DELAY_L)
					 {
						 ANGLE_DELAY = angle_DELAY_L;
					 }
					 //ANGLE_DELAY = (-1)*KpA*(ERROR);
					 ANGLE_FLAG=0;        ///////////////for right
					 lcd((char*)"right");
					 set(L);
					 waitms(ANGLE_DELAY);
					 reset(L);
					 waitms(2*ANGLE_DELAY + 50);
					 cls();
				 }
				 ERROR = ang - FINAL_L_ANGLE;
			 }
		 }
	 }
	 
 }
*/

/////////////////NEW
void STRAIGHT_NEW(float DISTANCE,int Front_leg,bool sand_dune,short int sand_delay,short int U2_DELAY)
{
			////Printbin(COM0,P_3_3);
			float ERROR_S=0;
			ERROR_S = DISTANCE;
			//cls();
			//if (!Front_leg)
			reset(U2);
	while (ERROR_S>0)
	{
		//Printbin(COM0,P_3_3);
		//lcd("E");
		//lcd(ERROR_S);
		if(ERROR_S>0)
		{
					STRAIGHT_DELAY = BASE_DELAY_S + (KpS*(ERROR_S)) + (KpS2*(ERROR_S)*(ERROR_S)) + (KpS3*(ERROR_S)*(ERROR_S)*(ERROR_S));
					   STRAIGHT_FLAG = 1;
				
		}
		else
		{
				STRAIGHT_FLAG = 0;
		}
		
			if(STRAIGHT_DELAY > STRAIGHT_DELAY_U)
		{
				STRAIGHT_DELAY = STRAIGHT_DELAY_U;
		}
	
			if(STRAIGHT_DELAY < STRAIGHT_DELAY_L)
		{
			STRAIGHT_DELAY = STRAIGHT_DELAY_L;
		}
		
		STRAIGHT_DELAY*= interrupt_constant;  /////imp	
		//lowerline();
		//lcd("D");
		//lcd(STRAIGHT_DELAY);
		//waitms(1000);
		if(STRAIGHT_FLAG)         
		{	    
					////Printbin(COM0,P_3_5);   
					
					set(R);
					//waitms(50);
					set(L);
					if ( (Front_leg==close) || (Front_leg==close_open) )
					{
						waitms(50);	
						set(U2);
						if (STRAIGHT_DELAY>50)
							waitms(STRAIGHT_DELAY-50);	
					}
					else
					waitms(STRAIGHT_DELAY);  
					
					reset(R);
					reset(L);
					
					//waitms(50);
					//set(U2);
					if ( (Front_leg==close_open) && ERROR_S>50)
					{
					
						waitms(50);
						reset(U2);
					}
					else if ( (Front_leg==close_open))
					{
						reset(U2);
					}
					/*
					waitms(50);
					set(U2);
					waitms(50);
					reset(U2);
					waitms(50);
					set(U2);
					waitms(50);
					reset(U2);
					waitms(50);
					*/
					if (sand_dune==yes)
					{
						//if (sand_delay!=185)//195)//145)
							set(U2);
						waitms(sand_delay);
						reset(U2);
						if (sand_delay==105)//85)
						{
							waitms(20);
						} 
						
						set(L);
						set(R);
						if (sand_delay==105)
						{
							waitms(120+U2_DELAY);//101//104//97);//140);
						} 
						else
						{
							if (sand_delay==140)//135)	
								waitms(140+U2_DELAY);//128);//120//120//104//97);//140);
							else if (sand_delay==193)//185)//195)//145)
							{
									waitms( 50);//168 );//(270*interrupt_constant)+U2_DELAY);//300//370//320
									set(U2);
									waitms(125);//134);//125);//140);//118);
							}
							else 
								waitms(128+U2_DELAY);
						}
						reset(L);
						reset(R);
						if (sand_delay==193)//185)
						{
							//reset(U2);			
						}
					} 
					if (sand_delay==193)//185)
					{
						waitms(sand_delay+100);
						set(L);
						set(R);
						
							waitms(80);//120);//191*interrupt_constant);//191//101//104//97);//140);
								
							cls();
							lcd("GO");
							//waitms(100);
						
						reset(L);
						reset(R);
					}
					waitms(STRAIGHT_DELAY*2.5);//*2.5);//*1.7);//*1.432);//*1);//*0.6);//*0.3);//*0.75);//*1);//*1.18);//*1.28);//*1.432);//*1//*1.432//STRAIGHT_DELAY+500);//700);
						
		}
				//KHADE_ANGLE_O(angle+4,angle-4);
				/*
				dist_ultra3 = laser(SENSOR);    /////////APPROACHING SAND DUNE
				
				lowerline();
				lcd((int)dist_ultra3);
				*/
		 		//lcd("  ");
				//lcd((int)ang);
				//waitms(80);
				
				ERROR_S = 0;
				//ERROR_S =  dist_ultra3 - DISTANCE;////DISTANCE-dist_ultra3;
				
	}
}




/*
/////////////////NEW
void STRAIGHT(int DISTANCE,int SENSOR,double angle)
{
			////Printbin(COM0,P_3_3);
			
			//KHADE_ANGLE_O(angle+4,angle-4);
			
			dist_ultra3 = laser(SENSOR);    
	
			cls();
			lcd((int)dist_ultra3);
			lcd("  ");
			
			dist_ultra3 = laser(SENSOR);
						
			//cls();
			lcd((int)dist_ultra3);
			lcd("  ");
			
			
			
			if(SENSOR == back)
			ERROR_S = DISTANCE;
			//ERROR_S = DISTANCE - dist_ultra3;////DISTANCE-dist_ultra3;
			
			if(SENSOR == front)
			ERROR_S = DISTANCE;
			//ERROR_S =  dist_ultra3 - DISTANCE;////DISTANCE-dist_ultra3;			
			//cls();
			
	while (ERROR_S>0)
	{
		//Printbin(COM0,P_3_3);
		lcd("E");
		lcd(ERROR_S);
		if(ERROR_S>0)
		{
						cls();
						lcd("E");
						lcd(ERROR_S);
						x=ERROR_S;
				{
					   
					    //STRAIGHT_DELAY = a0 +a1*cos(x*w) + b1*sin(x*w) +a2*cos(2*x*w) + b2*sin(2*x*w) + a3*cos(3*x*w) + b3*sin(3*x*w) + a4*cos(4*x*w) + b4*sin(4*x*w)+ a5*cos(5*x*w) + b5*sin(5*x*w) + a6*cos(6*x*w) + b6*sin(6*x*w) + a7*cos(7*x*w) + b7*sin(7*x*w) + a8*cos(8*x*w) + b8*sin(8*x*w) ;
						STRAIGHT_DELAY = a0 +a1*cos(x*w) + b1*sin(x*w) +a2*cos(2*x*w) + b2*sin(2*x*w) + a3*cos(3*x*w) + b3*sin(3*x*w) + a4*cos(4*x*w) + b4*sin(4*x*w)+ a5*cos(5*x*w) + b5*sin(5*x*w) + a6*cos(6*x*w) + b6*sin(6*x*w);
						//STRAIGHT_DELAY = BASE_DELAY_S + KpS*(ERROR_S) + KpS2*(ERROR_S*ERROR_S);
						STRAIGHT_FLAG = 1;
				}
		}
		else
		{
				STRAIGHT_FLAG = 0;
		}	
			if(STRAIGHT_DELAY > STRAIGHT_DELAY_U)
		{
				STRAIGHT_DELAY = STRAIGHT_DELAY_U;
		}
	
			if(STRAIGHT_DELAY < STRAIGHT_DELAY_L)
		{
			STRAIGHT_DELAY = STRAIGHT_DELAY_L;
		}
		lowerline();
		lcd("D");
		lcd(STRAIGHT_DELAY);
		if(STRAIGHT_FLAG)         
		{	    
					////Printbin(COM0,P_3_5);                		
					set(R);
					//waitms(50);
					set(L);
					waitms(STRAIGHT_DELAY);  
					reset(R);
					reset(L);
					waitms(1.432*STRAIGHT_DELAY);//STRAIGHT_DELAY+500);//700);
		}
				//KHADE_ANGLE_O(angle+4,angle-4);
				lcd("  ");
				lcd((int)ang);
				//waitms(80);
				
				if(SENSOR == back)
				ERROR_S = 0;
				//ERROR_S = DISTANCE - dist_ultra3;////DISTANCE-dist_ultra3;

				if(SENSOR == front)
				ERROR_S = 0;
				//ERROR_S =  dist_ultra3 - DISTANCE;////DISTANCE-dist_ultra3;
				
	}
}
*/
void COORDINATE_STRAIGHT(int DISTANCE,int SIDE_SDISTANCE,int sensor,double angle)
{
		/*
						RED R_GERERE=1                                             BLUE R_GERERE=-1
			  A	 _ _ _ _ _ _ _ _ _ _ _                                         _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|A                              
				|					45/										  \45							|
				|					 /										   \							|
				|					/											\							|
				|				   /											 \							|
				|				  / 											
		         B																					      B
		
		INCREASE A ONLY
		THEN SIDE_DISTANCE= 
		*/
		
		
	KHADE_ANGLE_O(R_GEREGE*45,R_GEREGE*45);//,small);//2 BUFFER//7 BUFFER//angle+10,angle-10);
	
	//KHADE_ANGLE_O(angle,angle);//small);//KHADE_ANGLE_T(angle,angle);
	
	waitms(10);//100);	
	
	//cls();
	//lcd("COOL?");
	//waitms(500);	
	//laser(sensor);             // THESE 2 COMMNTD BY AYUSH
	//laser(sensor);

	side_distance = laser(sensor);
	//waitms(80);
	side_distance = laser(sensor);
	side_distance = laser(sensor);
	
	//side_distance = laser_filter(sensor);
	

	if(sensor==right)
		side_distance += 18;
	else
		side_distance += 12;
		
	//waitms(80);
	
	
//	cls();
//	lcd((int)side_distance);//US);//(int)distance);
	//waitms(500);
	
//	lcd(" ");
	
	//laser(back);      // THESE 2 COMMNTD BY AYUSH
	//laser(back);
	back_distance = laser(back);
	back_distance = laser(back);
	back_distance = laser(back);
	
		//back_distance = laser_filter(back);

	LASER=0;  ///////////////////////imp
	cls();
	lcd((int)ang);
	//waitms(500);
	//lcd(" ");

	
		if(side_distance > SIDE_SU)
		{
			side_distance = SIDE_SU;
		}
		
		if(side_distance < SIDE_SL)
		{
			side_distance = SIDE_SL;
		}
		
		if(back_distance > BACK_SU)
		{
			back_distance = BACK_SU;
		}
				
		if(back_distance < BACK_SL)
		{
			back_distance = BACK_SL;
		}
		
	back_distance = DISTANCE - back_distance;
	side_distance = SIDE_SDISTANCE - side_distance;   //SIDE_SDISTANCE=170
	
	lowerline();
	lcd((int)back_distance);
	lcd(" ");
	lcd((int)side_distance);
	lcd(" ");
	//waitms(1000);//300);
	
	
	if((int)back_distance>0)
	{
		ANG = (atan2(side_distance,back_distance)*180)/PI;
		
		if(sensor==left)
		ANG=(-1)*ANG;
		
		////////recently removed
		//lowerline();
		//lcd((int)ANG);
		//lcd(" ");
		//waitms(500);
		
		distance1= hypot(side_distance,back_distance);
		
		//distance1 = sqrtf(side_distance*side_distance + back_distance*back_distance);
		
		//cls();
		//lcd((int)distance1);
		//waitms(500);
		
		if((unsigned int)ANG<30)
			Ultimate_jump_s(angle+ANG,distance1,1);//BLIND_Ultimate_jump(angle+ANG,distance1);
		else
			{
				if(ANG>0)
					KHADE_ANGLE_O(angle+(ANG-30),angle+(ANG-30)); //PROPORTIONAL_NEW_KHADE(angle+(ANG-30),angle+(ANG-30)); // KHADE_ANGLE_O(angle+(ANG-30),angle+(ANG-30));
				else
					KHADE_ANGLE_O(angle+(ANG+30),angle+(ANG+30)); //PROPORTIONAL_NEW_KHADE(angle+(ANG+30),angle+(ANG+30)); // KHADE_ANGLE_O(angle+(ANG+30),angle+(ANG+30));
				
				Ultimate_jump_s(angle+ANG,distance1,1);//BLIND_Ultimate_jump(angle+ANG,distance1);
			}
			
			//while(1)
			{
				cls();
				lcd(ang);
			}
			waitms(150);//50);//100);//200);
			
			if(R_GEREGE==1)
			{
				if(POINT_1)
					ang = ang + 1;//R_GEREGE*3;
				else
					ang += 2;
			}
			else
			{
				if(POINT_1)
				ang = ang + 3;//R_GEREGE*3;
				else
				ang += 4;
			}
			waitms(150);//300); //for new_khade  
		if (R_GEREGE==1)
		{
			if (!sand_dune_leave || !line_1 || !no_line)  //RESTART
			{
				if (POINT_1)
					PROPORTIONAL_NEW_KHADE(7,7);//6//5//8//7//5,5//8//2//5//KHADE_ANGLE_O((-1)*5,(-1)*5);//7//8//6//8//5//8//3//0,0///samall upper//(angle-45,angle-47)
				else
					PROPORTIONAL_NEW_KHADE(7,7);//5//7//5//-9//12//11//5//7//KHADE_ANGLE_O((-1)*7,(-1)*7);//8//6//8//5//8//3//0,0///samall upper//(angle-45,angle-47);	
			}
			else
			{
				PROPORTIONAL_NEW_KHADE((1)*9,(1)*9);////10//11//7//9//8//7//8//5//9//8//13//KHADE_ANGLE_O((-1)*13,(-1)*13);//12//10//8//6//8//5//8//3//0,0///samall upper//(angle-45,angle-47);	
			}
		
			
		} 
		else
		{
			if (!sand_dune_leave || !line_1 || !no_line)  //RESTART
			{
				if (POINT_1)
					PROPORTIONAL_NEW_KHADE((-1)*10,(-1)*10);//10//13//13//15//16//16//14//11//10//7//4;//6//7//8 may be excess for new_khade//5//3//KHADE_ANGLE_O((-1)*3,(-1)*3);//5//6//8//5//8//3//0,0///samall upper//(angle-45,angle-47);
				else
					PROPORTIONAL_NEW_KHADE((-1)*10,(-1)*10);//15//10//7//5//7//10//KHADE_ANGLE_O((-1)*10,(-1)*10);//8//5//8//3//0,0///samall upper//(angle-45,angle-47);
			}
			else
			{
				if (POINT_1)
				PROPORTIONAL_NEW_KHADE((-1)*7,(-1)*7);//6//7//8//10//11//10////14//11//10//7//4;//6//7//8 may be excess for new_khade//5//3//KHADE_ANGLE_O((-1)*3,(-1)*3);//5//6//8//5//8//3//0,0///samall upper//(angle-45,angle-47);
				else
				PROPORTIONAL_NEW_KHADE((-1)*7,(-1)*7);//9//11//10//7//5//7//10//KHADE_ANGLE_O((-1)*10,(-1)*10);//8//5//8//3//0,0///samall upper//(angle-45,angle-47);
			}			
		}
		
		//set(U2);
		/*
		waitms(300);
		cls();
		lcd((int)ang);
		lcd(" E");
		lcd((int)distance1);
	    */
		//BLIND(distance1,ANG);
		//STRAIGHT(distance1,back,ANG);
	}	
}




void TUSSUK_NEW(int sensor,int angle,int Front_leg)
{
	//Printbin(COM0,P_4);
	reset(U2);
	ERROR_C = angle - ang;
	if(!tt_jump)
	{
		
		k=0;
		while(k<5)
		{
			side_distance = laser(sensor);
			k++;
		}
		k=0;
		
		//side_distance = laser_filter(sensor);
		side_distance *= cos((angle-ang)*Degree_to_Rad);
		//waitms(80);
		cls();
		//lcd((int)side_distance);//US);//(int)distance);
		
		//lcd(" ");

		while(k<5)
		{
			back_distance = laser(back);
			k++;
		}
		k=0;
		laser(front);
		
		//back_distance = laser_filter(back);
		LASER=0; //////IMP
		
		//lcd(" ");
		back_distance *= cos((angle-ang)*Degree_to_Rad); 
		lcd((int)back_distance);
		lcd(" ");
		lcd((int)side_distance);
		lcd(" ");
		lcd((int)ang);
		lcd(" ");
		//waitms(1000);
	
	
		if(side_distance > SIDE_TU)
		{
			side_distance = SIDE_TU;
		}
	
		if(side_distance < SIDE_TL)
		{
			side_distance = SIDE_TL;
		}
	
		if(back_distance > BACK_TU)
		{
			back_distance = BACK_TU;
		}
	
		if(back_distance < BACK_TL)
		{
			back_distance = BACK_TL;
		}
		//lowerline();
		cls();
		lcd((int)back_distance);
		lcd(" ");
		lcd((int)side_distance);
		lcd(" ");
		lcd(angle);
	///..
		//waitms(2000);
		if (side_distance<64 && !tt_jump)//|| side_distance>75)                        ////  
		{
			
			while(back_distance<80)//90)//88)//89)//92)//95//97)//95)//93)//93)//95)//92//96//92)//88)                    
			{
				//Ultimate_jump_s(0,109-dist_ultra1);//120//93//130//93//93//96//95
				STRAIGHT_NEW(82-back_distance);//109
				
				waitms(200);
				
				laser(back);
				laser(back);
				laser(back);     ///necessary
				laser(back);
				laser(back);
				back_distance = laser(back);
				laser(front);
				
				//back_distance = laser_filter(back);
				LASER=0; //////IMP
				
				lcd(" ");
				lcd(ang);
				//waitms(50);//30);////1000);
				
			}


			ANG = ((BASE_ANGLE_TN + M_TN*(side_distance)));
			
			//else             //side_distance>75
			//ANG = ((BASE_ANGLE_T + M_T*(side_distance)));
			if(R_GEREGE==1)
				KHADE_ANGLE_O(angle - ANG-4,angle - ANG-4,small);//KHADE_ANGLE_T(angle - ANG-4,angle - ANG-4);//angle - ANG-4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8 
			else
				KHADE_ANGLE_O(angle - ANG-4,angle - ANG-4,small);//KHADE_ANGLE_T(angle + ANG+4,angle + ANG+4);//angle + ANG+4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
			////Printbin(COM0,P_4);
			seedha=1;
			seedha_near=1;
			lcd(" ");
			lcd(ANG);
		}
		else
		{
			while(back_distance<80)//95//97)//95)//93)//93)//95)//92//96//92)//88)
			{
				//Ultimate_jump_s(0,109-dist_ultra1);//120//93//130//93//93//96//95
				STRAIGHT_NEW(82-back_distance);
				
				waitms(200);
				
				laser(back);
				laser(back);     ///necessary
				laser(back);
				laser(back);
				laser(back);
				back_distance = laser(back);
				laser(front);
				
				//back_distance = laser_filter(back);
				LASER=0; //////IMP
				
				lcd(" ");
				lcd(ang);
				waitms(50);//30);////1000);
				
			}
		}
		//waitms(1000);	
	}
	else
	{
		//if(side_distance<40)
		{
			lcd(angle-ANG);
			//waitms(1000);
			if(R_GEREGE==1)
				KHADE_ANGLE_O(angle-4,angle-4,small);//-9//-2//+10//+8
			else
				KHADE_ANGLE_O(angle+4,angle+4,small);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
			//Printbin(COM0,P_4);
			seedha=1;
		}
	}
	cls();
	lcd(" ");
	lcd(angle-ANG);
	//waitms(1000);
	//lcd(ANGLE_DELAY_C
	if( !tt_jump && seedha)
	{
		if(side_distance<85)//99)
		{
			if(back_distance<102)//110)
			{
				//cls();
				//lcd("normal");
				//waitms(1000);
				//Ultimate_jump(ang,216);
				if (side_distance<50)//65)
				STRAIGHT_NEW(206-back_distance,Front_leg);//196//216//206//196//191//191-back//STRAIGHT(200-back_distance,back,ERROR_C);
				else
				STRAIGHT_NEW(210-back_distance,Front_leg);//206//216//206//196//191//191-back//STRAIGHT(200-back_distance,back,ERROR_C);
							
				/*
				set(R);
				set(L);
				waitms(273);//275);//270);//265);//260);7
				reset(R);
				reset(L);
				waitms(380);//1.432*265);
				k=0;
				waitms(50);
				while(k<3)//2)//3)
				{
					set(R);
					//waitms(50);
					set(L);
					waitms(30);
					reset(R);
					reset(L);
					waitms(130);//100);//200);//700);
					k++;
				}
				k=0;
				*/
			}
			else
			{
			//cls();
			//lcd("left_near");
			//waitms(1000);	
			
			STRAIGHT_NEW(186-back_distance,close);//181-BACK//191-back//STRAIGHT(200-back_distance,back,ERROR_C);
			}
		}
		else
		{
			if(back_distance<102)//110)
			{
				//cls();
				//lcd("right_away");
				//waitms(1000);
				
				STRAIGHT_NEW(220-back_distance,close);//206//196
				
			
			}
			else
			{
				//cls();
				//lcd("right_near");
				//waitms(1000);
				
				STRAIGHT_NEW(186-back_distance,close);
			}
		}
		n_jump=0;
		while(back_distance>250 && n_jump<2)
		{
			
			reset(U2);
			if(tt_jump)
			STRAIGHT_NEW(65,close);//45//5//85//65
			else
			{
				waitms(800);//300);
				//STRAIGHT_NEW(8,back,angle,close);//15//65
				k=0;
				waitms(50);
				while(k<3)//3)
				{
					set(R);
					set(L);
					waitms(23);//30);
					reset(R);
					reset(L);
					waitms(130);//100);//200);//700);
					k++;
				}
				k=0;
				
			}
			waitms(70);
			reset(U2);
			
			laser(back);
			laser(back);
			back_distance = laser(back);
			back_distance = laser(back);
			back_distance = laser(back);
			laser(front);
			
			waitms(100);
			//back_distance = laser_filter(back);
			LASER=0;///////////////IMP
			//waitms(70);
			n_jump++;
		}
	}
	else
	{
		
		waitms(100);
		
		laser(back);
		laser(back);
		back_distance = laser(back);
		back_distance = laser(back);
		back_distance = laser(back);
		laser(front);
		
		//back_distance = laser_filter(back);
		LASER=0;///////////////IMP
		back_distance *= cos((angle-ang)*Degree_to_Rad);
		cls();
		lcd((int)back_distance);
		lcd(" ");
		lcd((int)ang);
		lcd(" ");
		//waitms(1000);
		if (back_distance<175)
		{			
			waitms(400);
			if(R_GEREGE==1)
			{	STRAIGHT_NEW(10);
				STRAIGHT_NEW(10);
			}
			else
			{	
				STRAIGHT_NEW(10);
				STRAIGHT_NEW(10);
			}
			waitms(270);
		}
		
		side_distance = laser(sensor);
		side_distance = laser(sensor);
		side_distance = laser(sensor);
		
		//side_distance = laser_filter(sensor);
		side_distance *= cos(angle-ang*Degree_to_Rad);
		//waitms(80);
		cls();
		lcd((int)side_distance);//US);//(int)distance);
		lcd(" ");
		//waitms(1000);
		LASER=0;///////////////IMP
		
		if (back_distance<195)//190)
		{
			if(side_distance<50)//65)//71)
			{
				STRAIGHT_NEW(5,Front_leg);
				waitms(270);
				STRAIGHT_NEW(75,Front_leg);
			}
			else
				STRAIGHT_NEW(95,Front_leg);
		}
		else
		{
			if(side_distance<50)
				STRAIGHT_NEW(75,Front_leg);//85//75//70//75
			else
				STRAIGHT_NEW(85,Front_leg);//95
		}
		STRAIGHT_NEW(72,close);//15//65
	}
	waitms(200);//100);
	
	k=0;
	while(k<5)
	{
		laser(back);	
		k++;
	}
	k=0;
	back_distance = laser(back);
	laser(front);
	
	//back_distance = laser_filter(back);
	LASER=0;///////////////IMP
	
	//waitms(500);
	
	n_jump=0;
	
	tt_jump++;
}




/////////////////NEW
void SLOPE_P_4(double FINAL_ANGLE_C)     //SLOPE classic  no of steps 6
{
	//Printbin(COM0,P_4);   //REMEMBER
	cls();
	lcd(ang,3);
	if(!n_jump)
	{
		
		reset(U2);	
		//waitms(300);
		//Ultimate_jump_s(0,150,close);
		set(L);
		set(R);
		waitms(170);//150);                     /////////// 200           //230);//240);//220);//200);
		set(U2);
		waitms(80);
		reset(L);
		reset(R);
		waitms(270*1.4);//*1.133);
		//Ultimate_jump_s(0,60,close);//80//90  imp and reliable
		waitms(200);//80);//200);
		/*
		k=0;
		while(0)//k<2)//4   imp and reliable
		{
			Ultimate_jump(0,45);
		
		set(L);
		set(R);
		waitms(170);//100);//270);
		reset(L);
		reset(R);
		
		waitms(500);//140);	
		
		k++;
		}
		k=0;
		*/
	}
	
	if(n_jump)
	{
			if(n_jump==1 || n_jump>3)//4)
			{
				waitms(120);
				set(U2);
				if (n_jump>1)
				{
					waitms(500);//240);//220);//330);//270);//145//130//80//50
				}
				else
				{
					waitms(500);//350);//240);//220);//330);//270);//145//130//80//50
				}
			}
			
			if (n_jump>2)
			{
		     /*
				dist_ultra1=laser(right);
				dist_ultra1=laser(right);
				dist_ultra1=laser(right);
				cls();
				lcd(dist_ultra1);
				lcd(" ");
				
				dist_ultra2=laser(left);
				dist_ultra2=laser(left);
				dist_ultra2=laser(left);
				lcd(dist_ultra2);
				//waitms(1000);
				cls();
			   */
			}
			
			if(n_jump<2)
				KHADE_ANGLE(1,-1,close);//3//5,-5//2,-2);//3//15//17//20)//23//25
			else if(n_jump<3)//4
				KHADE_ANGLE(5,-5,close);//2//4//15//17//20)//23//25
			else if(n_jump<4)//5)//4)
				KHADE_ANGLE(10,-10,close);//5//2//6//5//15//17//20)//23//25
			else 
				KHADE_ANGLE(20,-20,close);//10//5//30
			//if(n_jump<5)//4)
				//KHADE_ANGLE(8,-8);//15//17//20)//23//25
			
			if(0)//n_jump==5)//4)//5)
			{
				reset(U2);
				waitms(50);//300);
			}
		ERROR_C = FINAL_ANGLE_C - ang;
			/*		
			if((unsigned)ERROR_C<10)
			ANGLE_DELAY_C = BASE_DELAY_C + KpSsCA*((unsigned)ERROR_C);
			else
			ANGLE_DELAY_C = BASE_DELAY_C + KpSCA*((unsigned)ERROR_C);
			*/
			if (ERROR_C>0)
			{
				CHALTE_FLAG=1;        ///////////////for left
				//lcd((char*)"left");
				ANGLE_DELAY_C = 45 - 10.5*ERROR_C;//45 - 8.5*ERROR_C;//20 + 10*(ERROR_C);//20 + 9*(ERROR_C);//20 + 7*(ERROR_C);//29 + 7*(ERROR_C);	
			} 
			else
			{
				CHALTE_FLAG=0;        ///////////////for right
				//lcd((char*)"right");
				if(1)//(-1)*ERROR_C<8)
					ANGLE_DELAY_C = 20 + 8.5*(ERROR_C);//20 + 10*(ERROR_C);//45 - 8.5*ERROR_C;//60 + 12*((-1)*ERROR_C);//50 10//45 + 9*((-1)*ERROR_C);//40 + 8*((-1)*ERROR_C);//10 + 13*((-1)*ERROR_C);
				//else
					//ANGLE_DELAY_C = -130 + 27*((-1)*ERROR_C);//-69 + 23*((-1)*ERROR_C);//10 + 13*((-1)*ERROR_C);//-60 + 20*((-1)*ERROR_C);
			}
			
			prev_ang=ang;          ////imp
			
			cls();
			lcd(ang,3);
			//lcd(" ");
			lowerline();
			//lcd(ANGLE_DELAY_C);
			//waitms(1000);
		if(ANGLE_DELAY_C > ANGLE_DELAY_C_U)
		{
			ANGLE_DELAY_C = ANGLE_DELAY_C_U;
		}
		
		//                                       REMOVED COMMENT FOR SMALL ANGLES CORRECTION REMEMBER                                            
			if(ANGLE_DELAY_C < ANGLE_DELAY_C_L)        /////////LOWER COULD BE DIFFERENT FOR P_4 BAR
		{
			ANGLE_DELAY_C = ANGLE_DELAY_C_L;
		}
		
		//lcd(ANGLE_DELAY_C);
	/*
		if(ERROR_C<2 && ERROR_C>-2)
		{
			ANGLE_DELAY_C = 1;
		}
	*/
		
		if(CHALTE_FLAG)          //for left	/////////////CHALTE CHALTE LEFT TO 45
		{	                             //CHALTE CHALTE LEFT
			
				
				if(((unsigned int)(ERROR_C))>2 && n_jump<4)//ERROR_C>4//n_jump<5)//10//0)//((int)(ERROR_C))!=0)
				{
					set(R);
					//waitms(ANGLE_DELAY_C);
					/*
					if(((unsigned int)(ERROR_C))<10)
					{
						lowerline();
						lcd("L4-10");
						waitms(1000);
						set(R);
						waitms(78);//65);
					}
					else if(((unsigned int)(ERROR_C))<17)
					{
						lowerline();
						lcd("L10-17");
						waitms(1000);
						set(R);						
						waitms(130);//200);//120);//ANGLE_DELAY_C);           //85-315-700 for lateral
					}
					else
					{
						lowerline();
						lcd("L17-20");
						waitms(1000);
						set(R);
						waitms(240);
					}
					*/
				}
				else
				set(R);
				
				set(L);
		}
		else            //for right
		{
				//set(L);
				if(((unsigned int)(ERROR_C))>2 && n_jump<4)//ERROR_C>4//n_jump<5)//10)//0)//((int)(ERROR_C))!=0)
				{
					set(L);
					//waitms(ANGLE_DELAY_C);
					/*
					if(((unsigned int)(ERROR_C))<10)
					{
						lowerline();
						lcd("L4-10");
						waitms(1000);
						set(L);
						waitms(20);
					}	
					else if(((unsigned int)(ERROR_C))<17)
						{
							lowerline();
							lcd("L10-17");
							waitms(1000);
							set(L);
							waitms(50);//40);//120);//ANGLE_DELAY_C);           //85-315-700 for lateral
						}
					else
					{
						lowerline();
						lcd("L17-20");	
						waitms(1000);
						set(L);
						waitms(60);
					}*/
				}
				else
				set(L);
				
				set(R);
		}
					//waitms(320);
					if(n_jump<3)//4)//5)//4)//5)//4)//3)//<4)
					waitms(415);//392);//400);//300);//385);//390);//360);//345);//330);//450);//500);//330);
					else if (n_jump==3)
					{
						waitms(283);//415);//350);//270
					}
					else if(1) //n_jump==3)//4)
					waitms(283);//303//1000/(n_jump-0.7));//-0.65//-0.4//300);//335);//320);
					//else if(0)n_jump==4)
					//waitms(1000/(n_jump + 0.4));//+2//+0));//+3));//+1));//250);//345);//260);//220);
					//else
					//waitms(1000/(n_jump+2));
					/*
					else
					{
						waitms(160);
						//set(U2);
						waitms(200);//150
					}
					*/
				reset(L);
				reset(R);
	
				//if (n_jump==4)
				{
				//set(G);
				//reset(U2);
				}
				if(n_jump<1)
				{
					waitms(350);//480);//600);
				}
				else if(n_jump<3)//4)
				{
					/*
					waitms(100);//400);//200);//100);
					reset(U2);
					waitms(250);//400);//250);//150);//100);
					set(U2);	
					*/
					if (n_jump==2)
					{
						waitms(1300);//1100);
					} 
					else
						waitms(1300);//1100//800);//700);//600);//530);//480);//760);//630);//600);
				}
				else if(1)//n_jump<3)
				{
					waitms(900);//500);//600);//480);//760);//630);//350);//600);//1250);//760);//705);//1115);//915);
					reset(U2);
					waitms(200);//600);//700);//450);//380);//180);//100);
				}
				else
				waitms(530);//1000/(n_jump));//+3//+1));//250);///345);//260);//220);
				if (0)//ang<prev_ang)
					ang += 4;
				//else
				//	ang -= 4;
	}
	n_jump++;
}


/////////////////NEW
void NEW2_SLOPE_P_4(double FINAL_ANGLE_C)     //SLOPE classic  no of steps 6
{
	//Printbin(COM0,P_4);   //REMEMBER
	cls();
	lcd(ang,3);
	if(0)//!n_jump)
	{
		reset(U2);	
		//waitms(300);
		
		//Ultimate_jump_s(0,150,close);
		set(L);
		set(R);
		waitms(200);//230);//240);//220);//200);
		set(U2);
		waitms(80);
		reset(L);
		reset(R);
		waitms(270*1.133);
		//Ultimate_jump_s(0,60,close);//80//90  imp and reliable
		waitms(80);//200);
		/*
		k=0;
		while(0)//k<2)//4   imp and reliable
		{
			Ultimate_jump(0,45);
		
		set(L);
		set(R);
		waitms(170);//100);//270);
		reset(L);
		reset(R);
		
		waitms(500);//140);	
		
		k++;
		}
		k=0;
		*/
	}
	if(1)//n_jump)
	{
			if(n_jump==1)
			{
				waitms(800);//120);
				set(U2);
				waitms(240);//220);//330);//270);//145//130//80//50
			}
			if (0)//n_jump>2)
			{
				dist_ultra1=laser(right);
				dist_ultra1=laser(right);
				dist_ultra1=laser(right);
				cls();
				lcd(dist_ultra1);
				lcd(" ");
				
				dist_ultra2=laser(left);
				dist_ultra2=laser(left);
				dist_ultra2=laser(left);
				lcd(dist_ultra2);
				//waitms(1000);
				cls();
				
			}
			
			if(1)//n_jump<2)
				KHADE_ANGLE(8,-8);//2,-2);//3//15//17//20)//23//25
			else if(n_jump<3)//4
				KHADE_ANGLE(5,-5);//2//4//15//17//20)//23//25
			else if(n_jump<5)//4)
				KHADE_ANGLE(5,-5);//2//6//5//15//17//20)//23//25
			else 
				KHADE_ANGLE(10,-10);//5//30
			//if(n_jump<5)//4)
				//KHADE_ANGLE(8,-8);//15//17//20)//23//25
			
			if(0)//n_jump==5)//4)//5)
			{
				reset(U2);
				waitms(50);//300);
			}
		ERROR_C = FINAL_ANGLE_C - ang;
			/*		
			if((unsigned)ERROR_C<10)
			ANGLE_DELAY_C = BASE_DELAY_C + KpSsCA*((unsigned)ERROR_C);
			else
			ANGLE_DELAY_C = BASE_DELAY_C + KpSCA*((unsigned)ERROR_C);
			*/
			if (ERROR_C>0)
			{
				CHALTE_FLAG=1;        ///////////////for left
				//lcd((char*)"left");
				ANGLE_DELAY_C = 20 + 10*(ERROR_C);//20 + 9*(ERROR_C);//20 + 7*(ERROR_C);//29 + 7*(ERROR_C);	
			} 
			else
			{
				CHALTE_FLAG=0;        ///////////////for right
				//lcd((char*)"right");
				if(1)//(-1)*ERROR_C<8)
					ANGLE_DELAY_C = 45 - 8.5*ERROR_C;//60 + 12*((-1)*ERROR_C);//50 10//45 + 9*((-1)*ERROR_C);//40 + 8*((-1)*ERROR_C);//10 + 13*((-1)*ERROR_C);
				//else
					//ANGLE_DELAY_C = -130 + 27*((-1)*ERROR_C);//-69 + 23*((-1)*ERROR_C);//10 + 13*((-1)*ERROR_C);//-60 + 20*((-1)*ERROR_C);
			}
			
			prev_ang=ang;          ////imp
			
			cls();
			lcd(ang,3);
			//lcd(" ");
			lowerline();
			//lcd(ANGLE_DELAY_C);
			//waitms(1000);
		if(ANGLE_DELAY_C > ANGLE_DELAY_C_U)
		{
			ANGLE_DELAY_C = ANGLE_DELAY_C_U;
		}
		
		//                                       REMOVED COMMENT FOR SMALL ANGLES CORRECTION REMEMBER                                            
			if(ANGLE_DELAY_C < ANGLE_DELAY_C_L)        /////////LOWER COULD BE DIFFERENT FOR P_4 BAR
		{
			ANGLE_DELAY_C = ANGLE_DELAY_C_L;
		}
		
		//lcd(ANGLE_DELAY_C);
	/*
		if(ERROR_C<2 && ERROR_C>-2)
		{
			ANGLE_DELAY_C = 1;
		}
	*/
		
		if(CHALTE_FLAG)          //for left	/////////////CHALTE CHALTE LEFT TO 45
		{	                             //CHALTE CHALTE LEFT
			
				
				if(((unsigned int)(ERROR_C))>2 && n_jump<4)//ERROR_C>4//n_jump<5)//10//0)//((int)(ERROR_C))!=0)
				{
					set(R);
					//waitms(ANGLE_DELAY_C);
					/*
					if(((unsigned int)(ERROR_C))<10)
					{
						lowerline();
						lcd("L4-10");
						waitms(1000);
						set(R);
						waitms(78);//65);
					}
					else if(((unsigned int)(ERROR_C))<17)
					{
						lowerline();
						lcd("L10-17");
						waitms(1000);
						set(R);						
						waitms(130);//200);//120);//ANGLE_DELAY_C);           //85-315-700 for lateral
					}
					else
					{
						lowerline();
						lcd("L17-20");
						waitms(1000);
						set(R);
						waitms(240);
					}
					*/
				}
				else
				set(R);
				
				set(L);
		}
		else            //for right
		{
				//set(L);
				if(((unsigned int)(ERROR_C))>2 && n_jump<4)//ERROR_C>4//n_jump<5)//10)//0)//((int)(ERROR_C))!=0)
				{
					set(L);
					//waitms(ANGLE_DELAY_C);
					/*
					if(((unsigned int)(ERROR_C))<10)
					{
						lowerline();
						lcd("L4-10");
						waitms(1000);
						set(L);
						waitms(20);
					}	
					else if(((unsigned int)(ERROR_C))<17)
						{
							lowerline();
							lcd("L10-17");
							waitms(1000);
							set(L);
							waitms(50);//40);//120);//ANGLE_DELAY_C);           //85-315-700 for lateral
						}
					else
					{
						lowerline();
						lcd("L17-20");	
						waitms(1000);
						set(L);
						waitms(60);
					}*/
				}
				else
				set(L);
				
				set(R);
		}
					//waitms(320);
					if(1)//n_jump<4)//3)//<4)
					waitms(250);//250);//365);//385);//390);//360);//345);//330);//450);//500);//330);
					if(n_jump<4)//3)//<4)
					waitms(300);//250);//365);//385);//390);//360);//345);//330);//450);//500);//330);
					else if(1) //n_jump==3)//4)
					waitms(1000/(n_jump));//300);//335);//320);
					//else if(0)n_jump==4)
					//waitms(1000/(n_jump + 0.4));//+2//+0));//+3));//+1));//250);//345);//260);//220);
					//else
					//waitms(1000/(n_jump+2));
					/*
					else
					{
						waitms(160);
						//set(U2);
						waitms(200);//150
					}
					*/
				reset(L);
				reset(R);
	
				//if (n_jump==4)
				{
				//set(G);
				//reset(U2);
				}
				if(1)//n_jump<1)
				{
					waitms(1200);//500);//350);//480);//600);
				}
				else if(n_jump<2)
				waitms(530);//480);//760);//630);//600);
				else if(n_jump<3)
				waitms(530);//480);//760);//630);//350);//600);//1250);//760);//705);//1115);//915);
				else
				waitms(530);//1000/(n_jump));//+3//+1));//250);///345);//260);//220);
				if (0)//ang<prev_ang)
					ang += 4;
				//else
				//	ang -= 4;
	}
	n_jump++;
}


/////////////////NEW
void NEW_SLOPE_P_4(double FINAL_ANGLE_C)     //SLOPE classic  no of steps 6
{
	//Printbin(COM0,P_4);   //REMEMBER
	cls();
	lcd(ang,3);
	if(!n_jump)
	{
		reset(U2);	
		//waitms(300);
		
		//Ultimate_jump_s(0,150,close);
		set(L);
		set(R);
		waitms(235);//245);//230);//200);//230);//240);//220);//200);
		set(U2);
		waitms(65);//80);
		reset(L);
		reset(R);
		waitms(270*1.133);
		//Ultimate_jump_s(0,60,close);//80//90  imp and reliable
		waitms(80);//200);
		/*
		k=0;
		while(0)//k<2)//4   imp and reliable
		{
			Ultimate_jump(0,45);
		
		set(L);
		set(R);
		waitms(170);//100);//270);
		reset(L);
		reset(R);
		
		waitms(500);//140);	
		
		k++;
		}
		k=0;
		*/
	}
	if(n_jump)
	{
			if(n_jump==1)
			{
				waitms(120);
				set(U2);
				waitms(240);//220);//330);//270);//145//130//80//50
			}
			
				KHADE_ANGLE(11,-40);//8,-40);//5,-40);//40,-5);//5,-40);//15//17//20)//23//25
			
			if(0)//n_jump==5)//4)//5)
			{
				reset(U2);
				waitms(50);//300);
			}
		ERROR_C = FINAL_ANGLE_C - ang;
			/*		
			if((unsigned)ERROR_C<10)
			ANGLE_DELAY_C = BASE_DELAY_C + KpSsCA*((unsigned)ERROR_C);
			else
			ANGLE_DELAY_C = BASE_DELAY_C + KpSCA*((unsigned)ERROR_C);
			*/
			if (ERROR_C>0)
			{
				CHALTE_FLAG=1;        ///////////////for left
				//lcd((char*)"left");
				ANGLE_DELAY_C = 20 + 10*(ERROR_C);//20 + 9*(ERROR_C);//20 + 7*(ERROR_C);//29 + 7*(ERROR_C);	
			} 
			else
			{
				CHALTE_FLAG=0;        ///////////////for right
				//lcd((char*)"right");
				if(1)//(-1)*ERROR_C<8)
					ANGLE_DELAY_C = 45 - 8.5*ERROR_C;//60 + 12*((-1)*ERROR_C);//50 10//45 + 9*((-1)*ERROR_C);//40 + 8*((-1)*ERROR_C);//10 + 13*((-1)*ERROR_C);
				//else
					//ANGLE_DELAY_C = -130 + 27*((-1)*ERROR_C);//-69 + 23*((-1)*ERROR_C);//10 + 13*((-1)*ERROR_C);//-60 + 20*((-1)*ERROR_C);
			}
			
			prev_ang=ang;          ////imp
			
			cls();
			lcd(ang,3);
			//lcd(" ");
			lowerline();
			//lcd(ANGLE_DELAY_C);
			//waitms(1000);
		if(ANGLE_DELAY_C > ANGLE_DELAY_C_U)
		{
			ANGLE_DELAY_C = ANGLE_DELAY_C_U;
		}
		
		//                                       REMOVED COMMENT FOR SMALL ANGLES CORRECTION REMEMBER                                            
			if(ANGLE_DELAY_C < ANGLE_DELAY_C_L)        /////////LOWER COULD BE DIFFERENT FOR P_4 BAR
		{
			ANGLE_DELAY_C = ANGLE_DELAY_C_L;
		}
		
		//lcd(ANGLE_DELAY_C);
	/*
		if(ERROR_C<2 && ERROR_C>-2)
		{
			ANGLE_DELAY_C = 1;
		}
	*/
		
		if(CHALTE_FLAG)          //for left	/////////////CHALTE CHALTE LEFT TO 45
		{	                             //CHALTE CHALTE LEFT
			
				
				if(((unsigned int)(ERROR_C))>2 && n_jump<4)//ERROR_C>4//n_jump<5)//10//0)//((int)(ERROR_C))!=0)
				{
					set(R);
					//waitms(40);
					//waitms(ANGLE_DELAY_C);
					/*
					if(((unsigned int)(ERROR_C))<10)
					{
						lowerline();
						lcd("L4-10");
						waitms(1000);
						set(R);
						waitms(78);//65);
					}
					else if(((unsigned int)(ERROR_C))<17)
					{
						lowerline();
						lcd("L10-17");
						waitms(1000);
						set(R);						
						waitms(130);//200);//120);//ANGLE_DELAY_C);           //85-315-700 for lateral
					}
					else
					{
						lowerline();
						lcd("L17-20");
						waitms(1000);
						set(R);
						waitms(240);
					}
					*/
				}
				else
				set(R);
				
				set(L);
		}
		else            //for right
		{
				//set(L);
				if(((unsigned int)(ERROR_C))>2 && n_jump<4)//ERROR_C>4//n_jump<5)//10)//0)//((int)(ERROR_C))!=0)
				{
					set(L);
					//waitms(ANGLE_DELAY_C);
					/*
					if(((unsigned int)(ERROR_C))<10)
					{
						lowerline();
						lcd("L4-10");
						waitms(1000);
						set(L);
						waitms(20);
					}	
					else if(((unsigned int)(ERROR_C))<17)
						{
							lowerline();
							lcd("L10-17");
							waitms(1000);
							set(L);
							waitms(50);//40);//120);//ANGLE_DELAY_C);           //85-315-700 for lateral
						}
					else
					{
						lowerline();
						lcd("L17-20");	
						waitms(1000);
						set(L);
						waitms(60);
					}*/
				}
				else
				set(L);
				
				set(R);
		}
					//waitms(320);
					if(n_jump<2)//3)//3)//<4)
					waitms(310);//320);//330);//353);//370);//350);//330);//320);//310);//330);//340);//355);//370);//330);//300);//270);//365);//385);//390);//360);//345);//330);//450);//500);//330);
					else if(n_jump==2)//1//0) //n_jump==3)//4)
					waitms(330);//1000/(n_jump));//300);//335);//320);
					else if(1)//n_jump==4)
					waitms(400);//385);//370);//1000/(n_jump + 0.4));//+2//+0));//+3));//+1));//250);//345);//260);//220);
					//else
					//waitms(1000/(n_jump+2));
					/*
					else
					{
						waitms(160);
						//set(U2);
						waitms(200);//150
					}
					*/
				reset(L);
				reset(R);
	
				//if (n_jump==4)
				{
				//set(G);
				//reset(U2);
				}
				if(n_jump<1)
				{
					waitms(350);//480);//600);
				}
				else if(n_jump<3)//2)
				waitms(600);//500);//450);//600);//530);//480);//760);//630);//600);
				else if(1)//n_jump<3)
				waitms(800);//630);//550);//530);//480);//760);//630);//350);//600);//1250);//760);//705);//1115);//915);
				else
				waitms(600);//530);//1000/(n_jump));//+3//+1));//250);///345);//260);//220);
				if (0)//ang<prev_ang)
					ang += 4;
				//else
				//	ang -= 4;
	}
	n_jump++;
}


void TUSSUCK_NEWEST_NEW(int sensor,int angle,bool second_jump_restart)
{
	cls();
	lcd((int)ang);
	f=0;
	
	int initial_ang;
	//ang=0;
	reset(U2);
	//ERROR_C = angle - ang;
	
	if (second_jump_restart == yes)
	tt_jump=1;
	
	if(!tt_jump)
	{
		
		initial_ang=0; 
		k=0;
		while(k<5)//3)//5)
		{
			back_distance = laser(back);
			k++;
			cls();
			lcd(back_distance);
			//lowerline();
			//lcd(side_distance);
		}
		k=0;
		cls();
		lcd(back_distance);
		
		while(back_distance<81)//87)//93)//91)//87)//85)//81)//86)//92)//86)//83)//80)//72)//80)
		{
			k=1;
			//Ultimate_jump_s(0,109-dist_ultra1);//120//93//130//93//93//96//95
			STRAIGHT_NEW(90-back_distance);///96//93//90//95//89//82 FOR 80//109
			
			waitms(200);//100);//200);
			laser(back);
			laser(back);
			laser(back);
			laser(back);  /////////REDUCED TO 3 FOR DELAY REMOVAL
			laser(back);     ///necessary
			back_distance = laser(back);
			//laser(front);
			//back_distance = laser_filter(back);
			LASER=0; //////IMP
			lcd(back_distance);
			lcd(" ");
			lcd(ang);
			waitms(50);//30);////1000);
		}
		k=0;
		while(k<5)
		{
			side_distance = laser(sensor);
			k++;
		}
		k=0;
		
		//side_distance = laser_filter(sensor);
		side_distance *= cos((angle-ang)*Degree_to_Rad);
		if(sensor==left)
			side_distance += 6;
		//waitms(80);
		cls();
		//lcd((int  )side_distance);//US);//(int)distance);
		
		//lcd(" ");
		
		/*
		
		while(k<5)//3)//5)
		{
			back_distance = laser(back);
			k++;
			cls();
			lcd(back_distance);
			//lowerline();
			//lcd(side_distance);
		}
		k=0;
		*/
		
		back_distance=laser_filter(back,2,12);
		
		cls();
				lcd(back_distance);
				lowerline();
				lcd(side_distance);
		waitms(500);
		//laser(front);
		
		//back_distance = laser_filter(back);
		LASER=0; //////IMP
		
		lcd(" ");
		back_distance *= cos((angle-ang)*Degree_to_Rad);
		lcd((int)back_distance);
		lcd(" ");
		lcd((int)side_distance);
		lcd(" ");
		lcd((int)ang);
		lcd(" ");
		
		//waitms(1000);
		
		
		
		if(side_distance > SIDE_TU)
		{
			side_distance = SIDE_TU;
		}
		
		if(side_distance < SIDE_TL)
		{
			side_distance = SIDE_TL;
		}
		
		if(back_distance > BACK_TU)
		{
			back_distance = BACK_TU;
		}
		
		if(back_distance < BACK_TL)
		{
			back_distance = BACK_TL;
		}
		//lowerline();
		cls();
		lcd((int)back_distance);
		lcd(" ");
		//lcd((int)side_distance);
		//lcd(" ");
		//lcd((int)ang);
		 //waitms(500);
	    
		
		
		
		//while(1)
		{
			cls();
			lcd(ang);
		}
	/*	
		 if (side_distance<66 && !tt_jump)//<62//<64//|| side_distance>75)                        ////
	     {
		     
		         lcd(" ");
			     lcd(ang);
			     //waitms(50);//30);////1000);
			     
		     
			//back_distance = laser_filter(back,2,10);//,2,12);//2,12
			cls();
			lcd("O");
			lcd((int)ang);
			lcd("N");
		     ANG = ((BASE_ANGLE_TN + M_TN*(side_distance)));
		     
		     //else             //side_distance>75
		     //ANG = ((BASE_ANGLE_T + M_T*(side_distance)));
		     if(R_GEREGE==1)
			 {
				 if (!sand_dune_leave || !line_1 || !no_line)
				 {
					if (POINT_1)
						angle = 8;//-5;
					else
						angle = 12;//-13;
				 }
				 else
					 angle = 12;//10;//-13;
				 
			 }
			 else
			 {
				 if (!sand_dune_leave || !line_1 || !no_line)
				 {
					 if (POINT_1)
					 angle = -10;
					 else
					 angle = -14;
				 }
				 else
				 {
					 if (POINT_1)
						 angle = -10;
					 else
						angle=-10;
				 }
			 }
			 lcd(R_GEREGE*ANG);
				waitms(2000);//500);
			  KHADE_ANGLE_O(angle - R_GEREGE*ANG,angle - R_GEREGE*ANG,small);//KHADE_ANGLE_T(angle + ANG+4,angle + ANG+4);//angle + ANG+4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
			 ////Printbin(COM0,P_4);
		     seedha=1;
		     seedha_near=1;
		     //lcd(" ");
		     //lcd(ANG);
			 cls();
			 lcd(ang);
			 waitms(2000);//500);
	     }
	     else
	     */{
		
		
		 /*
		 while(back_distance<81)//90)//88)//89)//92)//95//97)//95)//93)//93)//95)//92//96//92)//88)
		 {
			 //Ultimate_jump_s(0,109-dist_ultra1);//120//93//130//93//93//96//95
			 //STRAIGHT_NEW(82-back_distance);//109
			 if (back_distance<71)//85
			 {
				 STRAIGHT_NEW(91-back_distance);//65);//69//81//Ultimate_jump_s(R_GEREGE*45,(dist_ultra2-81));
			 }
			 else
			 {
				 STRAIGHT_NEW(83-back_distance);//-73//-69//-75//Ultimate_jump_s(R_GEREGE*45,(dist_ultra2-75));//73//71//70//80//90//70);//STRAIGHT(dist_ultra2-75,back,45);//-65
			 }
			 waitms(200);
			 
			 laser(back);
			 laser(back);
			 laser(back);     ///necessary
			 laser(back);
			 laser(back);
			 back_distance = laser(back);
			 laser(front);
			 
			 //back_distance = laser_filter(back);
			 LASER=0; //////IMP
			 
		 */
		 //waitms(300);
	   ////////THIS PART INCLUDED FOR CORRECTION AFTER APPROACH 
				//waitms(80);//300);
				
				
			//back_distance = laser_filter(back,2,10);//2,12	
			if(R_GEREGE==1)
			{
				if (!sand_dune_leave || !line_1 || !no_line)
				{
					
				
					if (POINT_1)
						KHADE_ANGLE_O(-2,-2);//-6//-5//-3//-2//0//3//6//7//6//5//5//-2//5//6//8//7//7//8//angle,angle// ,small);//4//8//KHADE_ANGLE_T(angle - ANG-4,angle - ANG-4);//angle - ANG-4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8			}
					else
						KHADE_ANGLE_O(0,0);//2//3//4//6//7//5//-7//-9//1//3//8//7//7//8//angle,angle// ,small);//4//8//KHADE_ANGLE_T(angle - ANG-4,angle - ANG-4);//angle - ANG-4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8			}
				}
				else
				{
					KHADE_ANGLE_O(2,2);//3//0//2//4//6//9//7//8//9//11//9//10//11//7//9//7//-8//8coord//13//10//8//7//7//8//angle,angle// ,small);//4//8//KHADE_ANGLE_T(angle - ANG-4,angle - ANG-4);//angle - ANG-4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8					
				}
			}
			else
			{
				
			if (!sand_dune_leave || !line_1 || !no_line)
				{
					if (POINT_1)
						KHADE_ANGLE_O((-1)*2,(-1)*2);//3//5//7//9//10//9//10//12//11//13//15//16//10//4//5//3//5//6//10//8//7//ABSOLUT AFTER IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
					else
						KHADE_ANGLE_O((-1)*3,(-1)*3);//7//14//15//11//10//7//10//12//11//10//8//7//ABSOLUT AFTER IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
				} 
			else
				{
					KHADE_ANGLE_O((1)*2,(1)*(2));//1//(-1)*2//3//6//7//6//7//8//10//11//12;//14//11//10//9//8//7//7//8//angle,angle// ,small);//-4//KHADE_ANGLE_T(angle + ANG+4,angle + ANG+4);//angle + ANG+4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
				
				}
			}
			
		}
			if(k)
				waitms(120);
			else
				waitms(50);//200);//50);//100);
			initial_ang=ang;
			/*
			k=0;			
			while(k<5)//3)//5)
			{
				back_distance = laser(back);
				k++;
				cls();
				lcd(back_distance);

			}
			k=0;
			cls();
			lcd(back_distance);
			*/
			
			//while(1)
			{
				cls();
				lcd(ang);
			}
			
			//back_distance = laser_filter(back,2,12);//,2,12);//2,12
			  
	   if (R_GEREGE==1)
	   {
		   
			if(back_distance>100)//85)//100)
				STRAIGHT_NEW(197.5-back_distance,close);//197//198//200//201
			else
				STRAIGHT_NEW(197.5-back_distance);//197//198//200//201//200//199//201//198//199//200//201 (1/6 morning)//202 for second jump//201//200//199//200//202//200//203//199//197//201//205//193//188//193//183//175  /// FIRST JUMP
	   }
	   else
	   {
		   if (!sand_dune_leave || !line_1 || !no_line)
		   {
				if(back_distance>100)//85)//100)
					STRAIGHT_NEW(197.5-back_distance,close);//198//199//200
				else
					STRAIGHT_NEW(197.5-back_distance);//198//200//199//198//197//198//199//200//201//200//197 SMALL//201//198//200//202//199//197//193//188//193//183//175  /// FIRST JUMP
		   }
		   else
				if(back_distance>100)//85)//100)
					STRAIGHT_NEW(197.5-back_distance,close);//198//200
				else
					STRAIGHT_NEW(197.5-back_distance);//198//200//199//198//197//198//200//201//200//199//200//201//202//201//202//201////197
	   }
	       //waitms(300);
			/*
	      	if(R_GEREGE==1)
	      	KHADE_ANGLE_O(angle ,angle ,small);//+4//KHADE_ANGLE_T(angle - ANG-4,angle - ANG-4);//angle - ANG-4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
	      	else
	      	KHADE_ANGLE_O(angle ,angle ,small);//-4//KHADE_ANGLE_T(angle + ANG+4,angle + ANG+4);//angle + ANG+4,-36);    //-4 after IMU ANGLE CORRECT IN ULTIMATE_JUMP//-8
	        */ 		
			n_jump=0;
			
			waitms(600);//500);//300);
			laser(back);
			laser(back);
			back_distance = laser(back);
			back_distance = laser(back);
			back_distance = laser(back);
			LASER=0;
			while(back_distance>250 && n_jump<2)
			{
				
				reset(U2);
			//	if(tt_jump)
			//	STRAIGHT_NEW(65,close);//45//5//85//65
			//	else
				{
					waitms(180);//300);//800);//300);
					//STRAIGHT_NEW(8,back,angle,close);//15//65
					k=0;
					waitms(50);
					while(k<2)//3)//3)
					{
						set(R);
						set(L);
						waitms(60);//23);//30);
						reset(R);
						reset(L);
						waitms(140);//130);//100);//200);//700);
						k++;
					}
					k=0;
					
				}
				waitms(170);//70);
				reset(U2);
				
				laser(back);
				laser(back);
				back_distance = laser(back);
				back_distance = laser(back);
				back_distance = laser(back);
				//laser(front);
				LASER=0;
				waitms(100);
				//back_distance = laser_filter(back);
				LASER=0;///////////////IMP
				//waitms(70);
				n_jump++;
			}
			if (R_GEREGE==1)
			{
				KHADE_ANGLE_O(initial_ang+5,initial_ang-12,small);//+1//10//0//+4//-4//+6//-4//,small);//-30);
			} 
			else
				KHADE_ANGLE_O(initial_ang+12,initial_ang-5,small);//-3//-1//0//-4//+4//-6//-4//,small);//-30);
				waitms(56);//100); 
			    
	}
	else
	{
		
			if (R_GEREGE==1)
			{	
				if (second_jump_restart == no)
					STRAIGHT_NEW(101,close);//102//99//98);//95);//100);//90);            /// SECOND JUMP 
				else
					STRAIGHT_NEW(101,close);//105//102//99//98);//95);//100);//90);            /// SECOND JUMP 
			}
			else
			{
				if (second_jump_restart == no)
					STRAIGHT_NEW(101,close);//107//104//101//99//98);//95);//100);//90);            /// SECOND JUMP
				else
					STRAIGHT_NEW(100,close);//101//104//105//104//103//101//107//101//99//98);//95);//100);//90);            /// SECOND JUMP
			}
			n_jump=0;
			
			waitms(300);//300);
			laser(back);
			laser(back);
			back_distance = laser(back);
			back_distance = laser(back);
			back_distance = laser(back);
			LASER=0;
			while(back_distance>300 && n_jump<2) //250
			{
				
				reset(U2);
				if(1)//ang<12 && ang>-12)//tt_jump)
					STRAIGHT_NEW(25,close);//35//65//45//5//85//65
				else
				{
					waitms(300);//800);//300);
					//STRAIGHT_NEW(8,back,angle,close);//15//65
					k=0;
					waitms(50);
					while(k<3)//3)
					{
						set(R);
						set(L);
						waitms(60);//23);//30);
						reset(R);
						reset(L);
						waitms(140);//130);//100);//200);//700);
						k++;
					}
					k=0;
					
				}
				waitms(70);
				reset(U2);
				
				laser(back);
				laser(back);
				back_distance = laser(back);
				back_distance = laser(back);
				back_distance = laser(back);
				//laser(front);
				
				waitms(100);
				//back_distance = laser_filter(back);
				LASER=0;///////////////IMP
				//waitms(70);
				n_jump++;
			}
			
			//waitms(80);//150);
	         STRAIGHT_NEW(25);//40);//30);//40
	       //  if ( (R_GEREGE==1 && ang>(-75) ) || (R_GEREGE==(-1) && ang<75) )//105//115
	         {
				 waitms(80);
				 STRAIGHT_NEW(20);
	         }
			// if ( (R_GEREGE==1 && ang>(-75) ) || (R_GEREGE==(-1) && ang<75) )
			 {
				 STRAIGHT_NEW(20);
			 } 
			 //STRAIGHT_NEW(20);
             //STRAIGHT_NEW(40);
	}
	n_jump=0;
	tt_jump++;	
}





/*
/////////////////NEW

void CALIBRATE(int pressure,int final_delay,int start_delay)
{
		//Printbin(COM0,pressure);
		double old_angle=0,new_angle=0;
		for(int c=start_delay;c<final_delay;c=c+5)
		{
			old_angle = ang;
			set(L);
			waitms(c);  //85);  //70);   //100); //30);          85-315-700 for lateral
			set(R);
			waitms(315);  //100); //100); //140);      ///350); FOR P_4_5
			reset(L);
			//waitms(80);  //70); //100); //70);
			reset(R);
			waitms(700);//700);
			new_angle = ang;
			cls();
			lcd((char*)"D ");
			lcd(c );
			lcd((char*)"A ");
			lcd(new_angle-old_angle);
			waitms(5000);
			
		}
 
}
*/



int laser_filter(int number,int buffer,int counts)
{
	short int CONTINUE =1;
	unsigned int PREV_LASER=0, CHAGE_IN_LASER=0;
	while(CONTINUE)
	{
		PREV_LASER=LASER_VALUE;
		//cls();
		LASER_VALUE = laser(number);
		//lcd("R");
		//lcd(LASER_VALUE);
		//k++;
		CHAGE_IN_LASER=LASER_VALUE-PREV_LASER;
		if(CHAGE_IN_LASER<buffer && LASER_VALUE>=30)//3)
		{
			count_1=counts;//1200;//300;
			
			while(count_1)
			{
				count_1--;
				PREV_LASER=LASER_VALUE;
				//cls();
				LASER_VALUE = laser(number);
				//lcd("R");
				//lcd(LASER_VALUE);
				//k++;
				CHAGE_IN_LASER=LASER_VALUE-PREV_LASER;
				if( (CHAGE_IN_LASER<buffer))
				{
					if(count_1<=1)
					CONTINUE=0;
				}
				else
				{
					count_1=0;
					k=0;
				}
			}
		}
	}
	cls();
	lcd("ans=");
	lcd(LASER_VALUE);
	return LASER_VALUE;
}


/////////////
double laser(int number)//,int stop)              ///////////////IMP ULTRASONIC 
{  
 //===========================================================================================================================================	
//==============================================================  WORKING PART ==============================================================	
	//cls();
	LASER=1;
	//if(number!=prev_laser )//|| l_switch<2)
	{
		if(number == 1)
		{
			reset(MUXA);
			reset(MUXB);
			//lcd((char*)"L1=");
		}
		else if(number == 2)
		{
			set(MUXA);
			reset(MUXB);
			//lcd((char*)"L2=");
		}
		else if(number == 3)
		{
			reset(MUXA);
			set(MUXB);
			//lcd((char*)"L3=");
		}
		else if(number == 4)
		{
			set(MUXA);
			set(MUXB);
			//lcd((char*)"L4=");
		}
		prev_laser = number;
			waitms(35);
			l_switch++;
	}
	
	l_switch=0;
		//lcd(A);
		//if(number == 4)
		{
			//if(A==510)//A==1023)
				//lcd("E");
			//else
		}
		if(number==front)
			return(A+5);
		else
			return(A);
			//return (A/0.947);  //CONSIDERING 4% ERROR	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 
void timer2_init()
{
	TCCR2 |= (1<<CS20); // (1<<CS02)|(1<<CS00); ///(1<<CS02)| (1<<CS00);
	TIMSK |=(1<<TOIE2);
	TCNT2  = 0;
}

ISR(TIMER2_OVF_vect)                                                               ///////////////  982ovf/sec
{
	cli();
	count++;
	if (count==2510)                        ///////////////   count should be at least  ,
	{
		if(1)//LASER)
		{
			
			if(BYTE1 && !BYTE2 )	
			{ 
			
				A=Inputbin(COM0);
			}
			else if(BYTE2 && !BYTE1)
			{
			/*	
				B=Inputbin(COM0);
				B=B+255;
			*/
				A=Inputbin(COM0);
				A=A+256;//255;
			}
			else if(BYTE2 && BYTE1)
			{
				A=Inputbin(COM0);
				A=A+512;
			}
			else if(!BYTE2 && !BYTE1)
			{
				A=Inputbin(COM0);
				A=A+768;
			}
			//LASER=0;
		}
count=0;
TCNT2 =0;


 	}
	
	sei();
}

ISR (INT1_vect)
{
cli();	
//A=Inputbin(COM0);
 /*
 for(int i=0;i<=255;i++)
 {
	 cls();
	 lcd(i);
	 waitms(10);
 }
*/
sei();
}   

//////////////////////////////////////////////////////////////////////////////////////////

void timer_init()
{
	TCCR0 |= (1<<CS01); // (1<<CS02)|(1<<CS00); ///(1<<CS02)| (1<<CS00);
	TIMSK |=(1<<TOIE0);
	TCNT0  = 0;
}

void get_rate()
{
	////////////////////////////////////////////////////////////////////////////command of 32 bits////////////////////////////////////////////////////////////////
	temp_ang_init = ang;
	ans=0;
	reset(PORTB2);
	r1=SPI_Communicate(0x80);
	r2=SPI_Communicate(0x00);
	r3=SPI_Communicate(0x00);
	r4=SPI_Communicate(0x00);
	set(PORTB2);

	ans = (r1<<24)|(r2<<16)|(r3<<8)|(r4);
	ans = (ans &  0x001FFFE0);
	ans = (ans>>5);
	ans2 = ans;

	if(ans2>32767)                                 ////////////(ans>32767)
	ans2 = (ans2-65535);
                                                   //awesome drift setting-85
	ans2 = ans2-72.8;//85;

	if((ans2 >= (-20)) && (ans2 <= (20)))
	temp = ans2/800;
	
	else
	temp = ans2/80;
	
	ang = ang + temp*(0.0022);                     ///////////////(0.0020813);
	

	temp_ang_final=ang;
	
	if ((temp_ang_final-temp_ang_init) < (-0.008)) //-0.01 // clockwise
	{
	 final_ang = ang*imu_r_constant; 	
	}
	 
	else if((temp_ang_final-temp_ang_init) > (0.008)) //0.01
	 {
	 final_ang = ang*imu_l_constant; 
	 }
	 
	 else
	 {
	// final_ang=ang;
	 }


}

ISR(TIMER0_OVF_vect)                                                               ///////////////  982ovf/sec
{
	
	cli();
	imu_count++;
	if (imu_count==17)  //19)   // 17                     ///////////////   imu_count should be at least  ,
	{
		get_rate();
		imu_count=0;
		TCNT0=0;
	}
	sei();
	
}
