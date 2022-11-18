/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Robotics1                                                 */
/*    Created:      11/18/2022, 8:45:50 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here
gyro Gyro = gyro(Brain.ThreeWirePort.B);

int main()
{

    Brain.Screen.printAt(10, 50, "Hello V5");

    Brain.Screen.clearLine(3, 1);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("STARTING CALIBRATION... ");

    Gyro.startCalibration();
    while (Gyro.isCalibrating())
    {
        wait(20, msec);
    }

    Brain.Screen.clearLine(3, 1);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("STARTING CALIBRATION... DONE");

    while (1)
    {

        Brain.Screen.clearLine(3, 1);
        Brain.Screen.setCursor(3, 1);
        Brain.Screen.print(Gyro.rotation());

        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
