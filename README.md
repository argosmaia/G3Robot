## Robot Control System

This project implements a control system for a robot using an Arduino board. The main functionalities include motor control, distance sensing, and servo motor manipulation for gripping objects.

### Motor Control (motor.h)

#### Constants
- `motor1Pin1`, `motor1Pin2`, `motor2Pin1`, `motor2Pin2`: Define the digital pins for controlling the motors.
- `vs`: Global constant for regulating the motor speed.

#### Functions
1. `motorSetup()`: Initializes the motor control pins.
2. `forward()`: Moves the robot forward.
3. `backwards()`: Moves the robot backward.
4. `turnRight()`: Turns the robot right.
5. `turnLeft()`: Turns the robot left.
6. `stop()`: Stops the robot.

### Main Program (main.ino)

#### Libraries
- `HCSR04`: Library for interfacing with ultrasonic distance sensors.
- `Servo`: Library for controlling servo motors.

#### Variables
- `aberto`: Represents the open state of the gripper.
- `fechado`: Represents the closed state of the gripper.
- `distance`: Global variable to store the distance measured by the ultrasonic sensor.

#### Setup
- Initializes serial communication and servo motor.

#### Loop
1. Measures the distance using the ultrasonic sensor.
2. If the distance is less than 12 cm, stops the robot, closes the gripper, moves forward, opens the gripper, and moves backward.
3. If the distance is greater than 55 cm, opens the gripper and randomly turns left or right.
4. Otherwise, opens the gripper and moves forward.
5. Delays for 800 milliseconds before repeating.
