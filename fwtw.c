#include <kipr/botball.h>
//Four Wheel Drive Prototypes
void drive_forwards_fast_fw(int time);
void drive_forwards_slow_fw(int time);
void drive_backwards_fast_fw(int time);
void drive_backwards_slow_fw(int time);
void pivot_right_fw(int time);
void pivot_left_fw(int time);
void line_follow_left_fw(int threshold, int time, int surface);
void line_follow_right_fw(int threshold, int time, int surface);


//Two Wheel Drive Prototypes
void drive_forwards_fast(int time);
void drive_forwards_slow(int time);
void drive_backwards_fast(int time);
void drive_backwards_slow(int time);
void turn_left(int time);
void turn_right(int time);
void pivot_left(int time);
void pivot_right(int time);
void line_followL(int threshold, int time);
void line_followR(int threshold, int time);
void line_follow_backwardsL(int threshold, int time);
void line_follow_backwardsR(int threshold, int time);
void aosleep(int ms);


//Four Wheel Drive Variables
/*L=Left
  R=Right
  F=Front
  B=Back
*/
#define LMF 0 //Left Motor Front
#define RMF 1 //Right Motor Front
#define LMB 2 //Left Motor Back
#define RMB 3 //Right Motor Back

#define HSF 75  //High Speed Front
#define HSB 100 //High Speed Back
#define LSF 55  //Low Speed Front
#define LSB 80  //Low Speed Back
#define PSF -75 //Pivot or Reverse Speed Front
#define PSB -100//Pivot or Reverse Speed Back

#define right_angle_fw 250 //Right Angle Turn Time Four Wheels

#define ground 5 //line follow intervals
#define ramp 15


//Two Wheel Drive Variables
#define LM 0 //Left Motor
#define RM 1 //Right Motor

#define SVO 0
#define RSVO 1
#define LSVO 2
#define MSVO 3

#define HS 100
#define NS 80
#define TS -10
#define PS -100

#define right_angle 450 //Right Angle Turn Time Two Wheels
#define line_follow_threshold 155 


int main ()
{ //Start What Robot Does
   line_follow_left_fw(line_follow_threshold, 1200, ramp);
   line_follow_left_fw(line_follow_threshold, 1200, ground);
   return 0;
} //End What Robot Does


//Four Wheel Drive Functions Labeled w/ _fw
void drive_forwards_fast_fw(int time) {
    int i = 0;
    while(i++ <= time) { //All four motors quickly, front slower than back b/c bigger wheels
        motor(LMF, HSF);
        motor(RMF, HSF);
        motor(LMB, HSB);
        motor(RMB, HSB);
      }
    }

void drive_forwards_slow_fw(int time) { //All four motors slowly, front slower than back b/c bigger wheels
  int i = 0;
  while(i++ <= time) {
    motor(LMF, LSF);
    motor(RMF, LSF);
    motor(LMB, LSB);
    motor(RMB, LSB);
  }
}

void drive_backwards_fast_fw(int time) { //All four motors BACKWARDS quickly, front slower than back b/c bigger wheels
    int i = 0;
    while(i++ <= time) {
        motor(LMF, -HSF);
        motor(RMF, -HSF);
        motor(LMB, -HSB);
        motor(RMB, -HSB);
      }
    }

void drive_backwards_slow_fw(int time) { //All four motors BACKWARDS slowly, front slower than back b/c bigger wheels
  int i = 0;
  while(i++ <= time) {
    motor(LMF, -LSF);
    motor(RMF, -LSF);
    motor(LMB, -LSB);
    motor(RMB, -LSB);
  }
} 

void pivot_right_fw(int time) { //Turns robot right in place
    int i = 0;
    while(i++ <= time) {
        motor(LMF, HSF);
        motor(LMB, HSB);
        motor(RMF, PSF);
        motor(RMB, PSB);
    }
}

void pivot_left_fw(int time) { //Turns robot left in place
    int i = 0;
    while(i++ <= time) {
        motor(RMF, HSF);       //Right motors move forward
        motor(RMB, HSB);
        motor(LMF, PSF);       //Left motors move backward
        motor(LMB, PSB);
    }
}

void line_follow_right_fw(int threshold,int time,int surface) { //Follows left side of black line
  int i = 0;
  while(i++ <= time) {
    if(analog(0) <= threshold) {    //if surface black
      int j = 0; 
      for(j=0; j <= surface; j++) {
        motor(LMF, 15);             //turn left motors slowly
        motor(LMB, 30);
        motor(RMF, HSF);            //turn right motors quickly
        motor(RMB, HSB);
      }                             //turns robot left overall to move towards left of black surface
    }
    else {                          //if surface white/not black, eg. wood
      int k = 0;
      for(k=0; k <= surface; k++) {
        motor(LMF, HSF);            //turn left motors quickly
        motor(LMB, HSB);
        motor(RMF, 15);             //turn right motors slowly
        motor(RMB, 30);
      }                             //turns robot right overall to move back to left edge of black surface
    }
  }
}

void line_follow_left_fw(int threshold, int time, int surface) {
  int i = 0;
  while(i++ <= time) {
    if(analog(0) <= threshold) {    //if surface black
      int k = 0;
      for(k=0; k <= surface; k++) {
        motor(LMF,HSF);             //turn left motors quickly
        motor(LMB,HSB);
        motor(RMF,15);              //turn right motors slowly
        motor(RMB,30);
      }                             //turns robot right overall to move towards right of black surface
    }
    else {                          //if surface white/not black, eg. wood
      int j = 0; 
      for(j=0; j <= surface; j++) {
        motor(LMF,15);              //turn left motors slowly
        motor(LMB,30);
        motor(RMF,HSF);             //turn right motors quickly
        motor(RMB,HSB);
      }                             //turns robot left overall to move back to right edge of black surface
    }
  }
}


//Two Wheel Drive Functions
void aosleep(int ms) { //Stop and sleep
  ao();
  msleep(ms);
}

void drive_forwards_fast(int time) { //Both motors quickly
  int i = 0;
  while(i++ <= time) {
    motor(LM, HS);
    motor(RM, HS);
  }
}
void drive_forwards_slow(int time) { //Both motors slowly
  int i = 0;
  while(i++ <= time) {
    motor(LM, NS);
    motor(RM, NS);
  }
}
void drive_backwards_fast(int time) { //Both motors BACKWARDS quickly
  int i = 0;
  while(i++ <= time) {
    motor(LM, -HS);
    motor(RM, -HS);
  }
}
void drive_backwards_slow(int time) { //Both motors BACKWARDS slowly
  int i = 0;
  while(i++ <= time) {
    motor(LM, -NS);
    motor(RM, -NS);
  }
}
void turn_left(int time) { //Turn left while moving forwards
  int i = 0;
  while(i++ <= time) {
    motor(RM, HS);
    motor(LM, TS);         //Left motor not fully backwards to maintain forward motion
  }
}
void turn_right(int time) { //Turn right while moving forwards
  int i = 0;
  while(i++ <= time) {      
    motor(RM, TS);          //Right motor not fully backwards to maintain forward motion
    motor(LM, HS);          
  }
}
void pivot_left(int time) { //Turn left in place
  int i = 0;
  while(i++ <= time) {
    motor(LM, PS);          //Left motor moves with same speed, but opposite direction
    motor(RM, HS);
  }
}
void pivot_right(int time) { //Turn right in place
  int i = 0;
  while(i++ <= time) {
    motor(LM, HS);
    motor(RM, PS);           //Right motor moves with same speed, but backwards
  }
}
void line_followL(int threshold, int time) { //Just look at the _fw version and remove front wheels
  int i = 0;
  while(i++ < time) {
    if(analog(0) <= threshold) {
      for(i=0; i<5; i++) {
        motor(LM, 100);
        motor(RM, 65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(RM, 100);
        motor(LM, 65);
      }   
    }
  }
}
void line_followR(int threshold, int time) { //Like seriously, I straight-up stole most of this for the _fw
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(RM, 100);
        motor(LM, 65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(LM, 100);
        motor(RM, 65);
      }   
    }
  }
}
void line_follow_backwardsL(int threshold, int time) { //Okay Joe, we get it, you know how to make robots work
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(LM, -100);
        motor(RM, -65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(RM, -100);
        motor(LM, -65);
      }   
    }
  }
}
void line_follow_backwardsR(int threshold, int time) { //I submit to my superior
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(RM, -100);
        motor(LM, -65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(LM, -100);
        motor(RM, -65);
      }   
    }
  }
}

/*Created by Joe Farah
  Edited by the MEME TEAM
  Commented by His shadow*/
