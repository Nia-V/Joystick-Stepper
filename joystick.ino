#include <Stepper.h>

// Define Constants

// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 

//  Amount of Gear Reduction
const float GEAR_RED = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Define Variables

// Number of Steps Required
int StepsRequired;
int jspin = A0;
int jsval;
int turn;
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);

void setup()
{
}

void loop()
{
   steppermotor.setSpeed(700);    // set speed to 700rpm   
jsval = analogRead(jspin);
turn = map(jsval, 0, 1024, -6144, 6144);// map the jsval (A1) to the min value -6144 (3 reverse turns) and the max value 6144 (3 turns) and save in spot turn
if (jsval <= 1024 && jsval >= 550){
steppermotor.step(turn);
}
if (jsval <= 500 && jsval >= 0){
steppermotor.step(turn);
}
}