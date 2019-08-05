
#include "simpletools.h" // Include simple tools
#include "abdrive360.h"

#define FRONT input(7)        //defining inputs for sensors
#define LEFT input(9)
#define RIGHT input(8)
#define  DRIVESPEED 64

int rightTurn;         //declaring variables for L&R turn speeds
int leftTurn;

void dChoice();     //declaring direction choice function
int main()             // Main function
{
      drive_setMaxSpeed(64);       //max speed is 64
     
  while(1){
    pause(150);                    //pause 150ms
    drive_speed(DRIVESPEED,DRIVESPEED);     //drive forward
    pause(150);                   //wait 150ms
    while(FRONT);                                      //drives until object detected
    pause(150);                                          //wait 150ms
    
    if(LEFT){                                           //if left IR has nothing beside it
      dChoice(1);                                    //turn left
      pause(150);                                   //wait 150ms
      drive_speed(DRIVESPEED,DRIVESPEED);                    //drive
      pause(150);                                  //pause 150ms
      while(!RIGHT && FRONT);         //while right detects object but front does not
      dChoice(0);                                   //turn right
      pause(150);                                   //pause 150ms
    }
    else{       
        dChoice(0);                          //turn right
        pause(150);                         //pause 150ms
        drive_speed(DRIVESPEED,DRIVESPEED);           //drive forwards
        pause(150);                         //pause 150ms
        while(!LEFT && FRONT);  //while left detects object and front is open
        dChoice(1);                         //turn left
        pause(150);                        //pause 150ms
     }
  }
}
void dChoice(int turnD){       //uses 0 for right and 1 for left
  drive_speed(0,0);                    //stop robot
  pause(150);                              //wait 100ms
  if(turnD == 0){
    drive_goto(26, -26);               //turns right
   }
  else{
    drive_goto(-26,26);               //turns left
  }
}

