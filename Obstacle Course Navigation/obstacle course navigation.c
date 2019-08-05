
#include "simpletools.h"                      // Include simple tools
#include "abdrive360.h"

#define FRONT input(7)
#define LEFT input(9)
#define RIGHT input(8)
#define DRIVESPEED 64

int rightTurn;      //declaring variables for L&R turn speeds
int leftTurn;

void dChoice();
int main()                                    // Main function
{ 
drive_setMaxSpeed(64);

  while(1)
  {
    pause(150);
    drive_speed(DRIVESPEED,DRIVESPEED);
    pause(150);
    while(FRONT);     //drives until object detected (; allows this to work)
    pause(150);       //wait 150ms
    if(LEFT){         //if left IR has nothing beside it
      dChoice(1);     //turn right
        pause(150);   //wait 150ms
        drive_speed(DRIVESPEED,DRIVESPEED);   //drive
        pause(150);           //pause 100ms
        while(!RIGHT && FRONT); //while the front is open and an object is on the right side keep driving
          dChoice(0);           //turn right
          pause(150);           //pause 100ms
        }else{
          dChoice(0);  //turn right
          pause(150);
          drive_speed(DRIVESPEED,DRIVESPEED);
          pause(150);
          while(!LEFT && FRONT);
          dChoice(1);  //turn left
          pause(150);                                
        }        
    }
}    

void dChoice(int turnD){
    drive_speed(0,0);  //stop robot
    pause(150);        //wait 150ms
    if(turnD == 0){ 
      drive_goto(26, -26);  //turns right
    }
    else{
      drive_goto(-26,26);  //turns left        
  }  
}

//how to make something check ir sensors left and right again if it loses the object