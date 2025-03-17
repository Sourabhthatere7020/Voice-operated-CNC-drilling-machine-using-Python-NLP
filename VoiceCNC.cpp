#include <AccelStepper.h>
#include <MultiStepper.h>

#include <AccelStepper.h>

// Define the stepper motor pins for each axis
#define X_STEP_PIN 2
#define X_DIR_PIN 5
#define X_ENABLE_PIN 8

#define Y_STEP_PIN 3
#define Y_DIR_PIN 6
#define Y_ENABLE_PIN 9

#define Z_STEP_PIN 4
#define Z_DIR_PIN 7
#define Z_ENABLE_PIN 10

// Define the steps per millimeter calibration values for each axis
#define X_STEPS_PER_MM 80.0
#define Y_STEPS_PER_MM 50.0
#define Z_STEPS_PER_MM 20.0

AccelStepper stepperX(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepperY(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper stepperZ(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);

AccelStepper* stepXptr = &stepperX;

int spindleControlPin = 11; // Pin connected to the SpnEn pin on the CNC shield

void setup() {
  Serial.begin(9600);
  // Enable the stepper motor drivers for each axis
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);

  pinMode(spindleControlPin, OUTPUT);
}

void loop(){
  // Check if there is any serial data available
  if (Serial.available() > 0) {
    // Read the incoming command from Python
    String command = Serial.readStringUntil('\n');
    command.trim();

    // Process the command
    if (command.startsWith("X:")) {
      // Extract the movement value for the X-axis from the command
      float movement = command.substring(2).toFloat();

      // Calculate the number of steps based on the movement value and steps/mm calibration
      int steps = movement * X_STEPS_PER_MM;

      // Move the X-axis stepper motor to the desired position
      stepperX.moveTo(steps);
    } else if (command.startsWith("Y:")) {
      // Extract the movement value for the Y-axis from the command
      float movement = command.substring(2).toFloat();

      // Calculate the number of steps based on the movement value and steps/mm calibration
      int steps = movement * Y_STEPS_PER_MM;

      // Move the Y-axis stepper motor to the desired position
      stepperY.moveTo(steps);
    } else if (command.startsWith("Z:")) {
      // Extract the movement value for the Z-axis from the command
      float movement = command.substring(2).toFloat();

      // Calculate the number of steps based on the movement value and steps/mm calibration
      int steps = movement * Z_STEPS_PER_MM;

      // Move the Z-axis stepper motor to the desired position
      stepperZ.moveTo(steps);
    } else if (command.startsWith("SpindleOn")) {
      // Turn on the spindle motor
      digitalWrite(spindleControlPin, HIGH);
    } else if (command.startsWith("SpindleOff")) {
      // Turn off the spindle motor
      digitalWrite(spindleControlPin, LOW);
    }
  }
  
  // Move the stepper motors to their target positions
  stepperX.run();
  stepperY.run();
  stepperZ.run();
}