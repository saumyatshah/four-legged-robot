/*
 * COMMON.h
 *
 * Created: 1/16/2019 5:36:08 PM
 *  Author: aakash
 */ 


#ifndef COMMON_H_
#define COMMON_H_


#define  F_CPU 16000000UL
#include "GPIO.h"
#include "LCD.h"
#include "SPI.h"
#include "UART.h"
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdlib.h> 
#include <avr/interrupt.h>


//#define baud 19200
//#define UBBR 51UL//((F_CPU/(16*baud))-1)

#define PI 3.1415926535
#define Degree_to_Rad 0.0174532925
#define Rad_to_Degree 57.142858
#define EPSILON 3
#define interrupt_constant (11.7/18.7)  ///0ld 15.1 w/0 int 11.7 new 18.7 
#define imu_l_constant 1
#define imu_r_constant 351/341//351/344    //360/351


#define Rs PORTC7
#define en PORTC5
#define d4 PORTC3
#define d5 PORTC2
#define d6 PORTC4
#define d7 PORTC6

/*
#define Rs PORTC7
#define en PORTC5
#define d4 PORTC3
#define d5 PORTC2
#define d6 PORTC4
#define d7 PORTC6
*/

//-------------SHERU Debug & Direction aliases-----------------//
//#define MT             ((PINA & 0x01<<PINA1)<<0)  //PINA0
#define red            ((PINA & 0x01<<PINA1)<<0)  //((PINA & 0x01<<PINA3)<<0)   //PINA7
#define END_proxy2 	   ((PINA & 0x01<<PINA5)<<0)//PINA4//PINC6
#define END_proxy 	   ((PINA & 0x01<<PINA6)<<0)//A0

#define trigger        PORTA2



 #define US         ((PINA & 0x01<<PINA4)<<0)   //2//left
 #define US2        ((PINA & 0x01<<PINA3)<<0)   //front
 #define US3        ((PINA & 0x01<<PINA5)<<0)   //right
 #define US4        ((PINA & 0x01<<PINA6)<<0)   //BACK
 #define BYTE1      ((PIND & 0x01<<PIND3)<<0)   //FIRST BYTE SIGNAL   arduino7
 #define BYTE2      ((PIND & 0x01<<PIND2)<<0)   //SECOND BYTE SIGNAL  arduino29

 #define MUXA			PORTD6    
 #define MUXB			PORTD4
#define front          4
#define back           3//2//3
#define left           2//1//2
#define right          1//3//1//1
#define open           0
#define close		   1
#define close_open	   2


#define small          1
#define large		   0

#define yes          1
#define no 		     0

///////////////////////////PORTC7-5-6-2
#define U2             PORTA2   
#define L 	           PORTA3
#define R 	           PORTA7
#define G			   PORTA4
#define ruk_l          2
#define ruk_r          2
/*
#define P_2            85//78
#define P_2_5          106//210//445///1000//445//approx(2_5*1024)/5.6
#define P_2_8          119//62//200

#define P_3            127//54//508//935//approx(3*1024)/5.6

#define P_3_3          140//47//47//74
#define P_3_5          148//43//0//90//94//0//94//94//336//375//approx(3_5*1024)/5.6
#define P_3_8          160//100//625//approx(4*1024)/5.6
#define P_4            168//31//625//approx(4*1024)/5.6
#define P_4_24         179//26
#define P_4_5          190//20//310//approx(4.5*1024)/5.6
#define P_4_8     	   202//96//new//197
#define P_4_93         207//61
#define P_5            211//0//3//6//approx(5*1024)/5.6    489 for 4.5  400 PE EXACT 5
#define P_5_5          233//0

*/

////NEW SUPER KHADE ANGLE
#define KpA_3			0.0644//2.722
#define KpA_2           -1.451//-13.21//-0.0603
#define KpA_			14.37//39.12//7.5405//1.5
#define BASE_angle_     38.05//5.862//45.7701


#define KpA3			0.02913
#define KpA2            -0.6843
#define KpA			    11.13//
#define BASE_angle      32.19//
#define angle_DELAY_TU	80//140
#define angle_DELAY_U	110
#define angle_DELAY_L	67//57//50//45
#define BASE_DELAY_S_C		0
#define ANGLE_DELAY_S_C_U	240


//--------------------------------FOR STRAIGHT  FOURIER EQUATION COEFFICIENTS

////////////old
/*
#define a0			-1073//-5.604//-352900//-5.603//-351800
#define a1			-1002//-224.1//521600//344.1//466600
#define b1			2298//453.6//113100//371//255700
#define a2			1508//249.7//-198800//-106.3//-117300
#define b2			1349//120.1//-90160//-255.8//-183300
#define a3			1235//40.77//30330//8.223//2581
#define b3			-715.3//-96.53//2.2530//104.5//37590
#define a4			-202.3//-26.83//-6.254//2581
#define b4			-846.2//3.224//-26.29//37590
#define a5			-446.6//5.789//4.571//2581
#define b5			-9.968//4.19//5.493//37590
#define a6			-42.69
#define b6			180.5
#define a7			55.61
#define b7			18.55
#define a8			3.205
#define b8			-12.81
#define w			0.04072//0.03326//0.2425//1.018//(0.00793)//*Rad_to_Degree)
*/

/////////new
#define a0			114.2
#define a1			-44.7			
#define b1			40.45
#define a2			-27.98
#define b2			94.77
#define a3			39.5
#define b3			50.2
#define a4			34.49
#define b4			-2.354
#define a5			8.888
#define b5			-13.17
#define a6			-1.852
#define b6			-4.018
#define w			0.04287

//-----------------------------------------------------------------

#define KpCSA				3.5//3//2.7
#define ANGLE_DELAY_S_C_L  35//45
#define BASE_DELAY     140
#define ANGLE_DELAY_U  110//270
#define KpCA             2.7
#define KpC3A             -2.0286//-0.4857
#define KpCS3A            -4.9231//-0.18
#define BASE_3DELAY_C     41.0263//19.4286
#define BASE_3SDELAY_C    -2.6718//-1.2364
#define ANGLE_3DELAY_C_U  160//223//160
#define ANGLE_3DELAY_C_L  35//45
#define KpSCA             16//13///10//13//10//5//5.4
#define KpSsCA			  12//7 
#define BASE_DELAY_C     0
#define ANGLE_DELAY_C_U  90//125
#define ANGLE_DELAY_C_L  1//35//45

//////////////first delays for zero  d1(angle changing delay)    now using 2nd delays for d1=50

#define KpS3						0.0002966
#define KpS2						-0.06401 
#define KpS     		        	6.237
#define BASE_DELAY_S     			57.8

#define STRAIGHT_DELAY_U	 		390
#define STRAIGHT_DELAY_L	  		50

#define STRAIGHT_80DELAY_U          223
#define STRAIGHT_80DELAY_L			70

//////////////coefficients of bi-quadratic
/*
#define P00					-249
#define P10					3.01
#define P01					3.301
#define P20					-0.009834
#define P11					-0.02781
#define P02					-0.01661
#define P21					0.00008063
#define P12					0.00008673
#define P03					0.00003717
#define P22					-0.0000001435
#define P13					-0.00000008477
#define P04					-0.00000003078	
*/

/*/NEW ONLY FOR BISECTION EXP
#define p00					-544.5
#define p10					-0.1702
#define p01					19.11T
#define p20					-0.009382
#define p11					-0.00308
#define p02					-0.2517
#define p30					0.0005191
#define p21					0.00002986
#define p12					0.0001178
#define p03					0.001567
#define p40					-0.000005937
#define p31				    -0.000001047
#define p22					-0.0000002535
#define p13					-0.0000004861
#define p04					-0.000004661


#define p50					0.00000002001
#define p41					0.000000006961
#define p32					0.0000000006661
#define p23					0.0000000007542
#define p14					0.0000000004493
#define p05					0.000000005339
*/

///////////////////45 range

//#define range_H 75//65//78//90          ////////////IF FIELD OR AIR LUBRICATION DIFFERS DECREASE range_h

/////

////////////////////////for IMU VALUE CORRECTION


#define c3					0.00004264
#define c2					-0.007234
#define c1					0.4546
#define c0					-8.486
///////////

#define P00                        74.35 
#define P10                        -0.7863
#define P01                        -1.628
#define P20                        0.000868
#define P11                        0.01493
#define P02                        0.01063
#define P21                        0.000004779
#define P12                        -0.00003657
#define P03                       -0.00002229


#define P_00                      72.61//77.52
#define P_10                      -4.086//-0.8617
#define P_01                      -1.245//-1.758
#define P_20                      -0.0005354//-0.001248
#define P_11                      0.05165//0.01712
#define P_02                      0.007101//0.01252
#define P_21                      0.00003636//0.00002878
#define P_12                      -0.0001455//-0.00005024
#define P_03                      -0.0000125//-0.00002694



//// done for new SANDUNE TO TUSSUK
#define	Q1 	                      0.0005858
#define	Q2 	                      -0.1724
#define	Q3 	                      16.3
#define	Q4 	                      -460.5



/////////////coefficients for d1 upper limit w.r.t d2
#define ka4					-0.0000001483
#define ka3					0.0001386
#define ka2					-0.04789
#define ka1					7.252
#define ka0					-213.
			

#define KpSs			            5.25
#define BASE_DELAY_Ss     		94.68

#define STRAIGHT_DELAY_U	 	390//300//260//400//420
#define STRAIGHT_DELAY_L	  	50//28//30//40//50//30
//#define SIDE_DISTANCE           150//137//125//130//110//110//140//120//140
//#define SIDE_SDISTANCE          180//176//186//190//194//187//180//170//190//170//75//86//89//83//96//89//83//90//80
#define MAX_STRAIGHT			((330 - 177)/2.6) //(STRAIGHT_DELAY_U - BASE_DELAY_S)/KpS
//#define LATERAL					50////35//25//10
#define SIDE_U	 				135//420//380//460
#define SIDE_L                  9
#define BACK_U				 	140//420//380//460
#define BACK_L	  				20
#define BASE_ANGLE        -67.5556 AFTER SAND DUNE//-72.5556//-75.5553//-65.5556//-58.75
#define M                 0.4333 AFTER SAND DUNE
#define BASE_ANGLE_TN      14.724//45last//50//30//-15.5435  //-67.5556 AFTER SAND DUNE//-72.5556//-75.5553//-65.5556//-58.75
#define M_TN              -0.2414//-0.9last//-0.78125//-0.46875//-0.390625//0.2826   //0.4333 AFTER SAND DUNE
#define BASE_ANGLE_T     30  //-67.5556 AFTER SAND DUNE//-72.5556//-75.5553//-65.5556//-58.75
#define M_T               -0.4  //0.4333 AFTER SAND DUNE
#define SIDE_SU	 				170//(maxlaser156)//135//420//380//460
#define SIDE_SL                  9
#define BACK_SU				 	512//400//140//420//380//460
#define BACK_SL	  				20
#define SIDE_TU	 				150//420//380//460
#define SIDE_TL                 30//9
#define BACK_TU				 	130//140//420//380//460
#define BACK_TL	  				20

#define Kp3LCA     		        0.0008
#define Kp2LCA     		        -0.0907
#define KpLCA     		        5.6619
#define BASE_LONG_DELAY_sC       0
#define KpLCsA     		        2.4732
#define BASE_LONG_DELAY_C     -27.8303
#define ANGLE_DELAY_L_C_U 	  155
#define ANGLE_DELAY_L_C_L	  	0




#define DELAY_straight 490//480//460 ///473    /////470   /////479    ///450  ///P_5
//#define DELAY_straight 455 ///473    /////470   /////479    ///450  ///P_5
#define DELAY_old      350  ///
#define DELAY_approach 150  //180  ///P_3_5
#define DELAY_angle_l  120//135//110//130//151  ///P_3_5
#define DELAY_angle_r  120//135//110//130  ///P_3_5
#define angle_STEP_DELAY 600*interrupt_constant//450//380//330//450




//-------------------------------------VARIABLES USED THROUGHT THE CODE------------------------------------------
extern bool LASER;/////////////imp
extern int LASER_VALUE;


extern bool line_1,line_2,no_line,first_jump,second_jump,third_jump,fourth_jump,double_jump,sand_dune_leave,POINT_1,POINT_2,POINT_3;

extern int R_GEREGE;
extern int STRAIGHT_DELAY;
extern double ERROR_LONG_C;
extern double a,b,c,d,e,f;
extern int ultra_pulse;
//
extern int A,B;
//FOR ULTRASONIC SENSOR
extern int echo_flag,temp_count;
extern double ang,final_ang,temp_ang_init,temp_ang_final,dist,pulse_range0, pulse_time,pulse_actual,pulse_actual2,pulse_diff;



//-------------FUNCTION DECLARATION FOR USE IN WHOLE PROJECT---------
//void test();


int laser_filter(int number,int buffer=3,int counts=6);//4 ,5


double laser(int number);//,int stop=0); 

void get_rate();
void timer_init();
ISR(TIMER0_OVF_vect);
//void BLUE(void);
//void RED(void);

//-----------------------------------FUCTION DECLARATIONS FOR TFMINI----------------------------------------//


void timer2_init();
ISR(TIMER2_OVF_vect);
ISR (INT1_vect);
//-----------------------------------------------------------------------------------------------------------------//

//double cubic_root(double a,double b,double c,double d);
double quadratic_root(double a,double b,double c,int lower,int upper);

//double func(double x,double a, double b, double c, double d,double e,double f );
//void bisection(double Aa, double Bb,double a, double b, double c, double d, double e, double f);

//double derivative_px(double x,double coeff[9]={0},double size = 0);
//double newton_raphson(double coeff);

void RANGE55(int angle);
void Ultimate_jump_s(double angle, double distance,bool NEXT_STEP=0,int frontleg = open);       //

//void Ultimate_jump(double angle, double distance = 0);

/*
void BLIND_Ultimate_jump(double angle, double distance);
*/

void KHADE_ANGLE(int FINAL_L_ANGLE,int FINAL_R_ANGLE,bool frontleg = open);
void KHADE_ANGLE_O(int FINAL_L_ANGLE,int FINAL_R_ANGLE,bool tussuk = large);
void NEW_KHADE(int FINAL_ANGLE,int FINAL_R_ANGLE);
void PROPORTIONAL_NEW_KHADE(int FINAL_ANGLE,int FINAL_R_ANGLE,bool khade_Angle=yes);
//void KHADE_ANGLE_T(int FINAL_L_ANGLE,int FINAL_R_ANGLE);


void SLOPE_P_4(double FINAL_ANGLE_C);

void NEW_SLOPE_P_4(double FINAL_ANGLE_C);

void NEW2_SLOPE_P_4(double FINAL_ANGLE_C);


void STRAIGHT_NEW(float DISTANCE,int Front_leg = open,bool sand_dune=no,short int sand_delay=100,short int U2_DELAY=0);//25//5





void TUSSUK_NEW(int sensor,int angle,int Front_leg);

void COORDINATE_STRAIGHT(int DISTANCE,int SIDE_SDISTANCE,int sensor,double angle);
//void CALIBRATE(int pressure,int final_delay,int start_delay);
void TUSSUCK_NEWEST_NEW(int sensor,int angle,bool second_jump_restart = no);

#endif /* COMMON_H_ */