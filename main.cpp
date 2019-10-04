#include <SDL.h>
#include <stdio.h>
#include <SDL_joystick.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
int main()
{
    SDL_Joystick *joy;
    SDL_Event event;

// Initialize the joystick subsystem
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

// Check for joystick
    if (SDL_NumJoysticks() > 0) {
        // Open joystick
        joy = SDL_JoystickOpen(0);

        if (joy) {
            printf("Opened Joystick 0\n");
            printf("Name: %s\n", SDL_JoystickNameForIndex(0));
            printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
            printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
            printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
        } else {
            printf("Couldn't open Joystick 0\n");
        }
    }

    while(SDL_WaitEvent(&event)) {
        switch(event.type)
        {
            case SDL_JOYAXISMOTION:
                if ( ( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 ) )
                {
                    if( event.jaxis.axis == 0)
                    {
                        cout << "left:";
                        cout <<  event.jaxis.value << endl;
                    }

                    if( event.jaxis.axis == 1)
                    {
                        /* Up-Down movement code goes here */
                    }
                    if( event.jaxis.axis == 2) {
                        cout << "right joystick left axis";
                        cout << event.jaxis.value << endl;
                    }
                }
                break;
            case SDL_KEYDOWN:
                /* handle keyboard stuff here */
                break;

            case SDL_QUIT:
                /* Set whatever flags are necessary to */
                /* end the main game loop here */
                break;

            case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
                if ( event.jbutton.button == 0 )
                {
                    /* code goes here */
                }
                break;

        }

    }
    return 0;
}
void proto_do(){

}
//
//void dothings() {
//    /* ==== Set rotation offset to current rotation ==== */
//    roboteam_msgs::RobotCommand command;
//    command.id = joy.robotID;
//    Xbox360Controller btn;
//
//    /* ==== Driving x and y ==== */
//    rtt::Vector2 driveVector;
//    driveVector.x = getVal(msg.axes, xbox360mapping.at(Xbox360Controller::LeftStickY));
//    driveVector.y = getVal(msg.axes, xbox360mapping.at(Xbox360Controller::LeftStickX));
//    if(joy.useRelativeControl){
//        driveVector = driveVector.rotate(joy.orientation);
//    }else{
//        driveVector = driveVector.rotate((joy.orientationOffset));
//    }
//    command.x_vel = joy.profile.SPEED_MAX * driveVector.x;
//    command.y_vel = joy.profile.SPEED_MAX * driveVector.y;
//
//    // ==== Orientation ==== //
//    float orientationX = getVal(msg.axes, xbox360mapping.at(Xbox360Controller::RightStickX));
//    float orientationY = getVal(msg.axes, xbox360mapping.at(Xbox360Controller::RightStickY));
//    rtt::Vector2 orientation(orientationY, orientationX);
//
//    // This checks which control mode to use (absolute (FIFA) or relative (Call of Duty))
//    if(!joy.useRelativeControl) {
//        if (0.9 < orientation.length())
//            joy.orientation = orientation.angle();
//        command.w = joy.orientation + joy.orientationOffset;
//    } else {
//        if (0.9 < fabs(orientationX));
//        joy.orientation += orientationX * joy.profile.ROTATION_MULTIPLIER;
//        if (M_PI < joy.orientation)
//            joy.orientation -= 2 * M_PI;
//        if (joy.orientation < -M_PI)
//            joy.orientation += 2 * M_PI;
//        command.w = joy.orientation;
//    }
//
//    // Make sure the angle is within range [-16 Pi, 16 Pi]
//    if(M_PI < command.w) command.w -= 2 * M_PI;
//    if(command.w <-M_PI) command.w += 2 * M_PI;
//
//    // ==== Set Kicker ====//
//    btn = Xbox360Controller::RightBumper;
//    if(getVal(msg.buttons, xbox360mapping.at(btn)) > 0) {
//        if (!getVal(previousMsg.buttons, xbox360mapping.at(btn)) > 0) {
//            command.kicker = true;
//            command.kicker_forced = true;
//        }
//    }
//
//    /* ==== Set Chipper ====*/
//    double RightTriggerVal = getVal(msg.axes, xbox360mapping.at(Xbox360Controller::RightTrigger));
//    double RightTriggerVal_prev = getVal(previousMsg.axes, xbox360mapping.at(Xbox360Controller::RightTrigger));
//
//    // The RightTriggerVal is a range from -1 to 1, where -1 is fully pressed and 1 is fully unpressed
//    if(RightTriggerVal <= -0.9) {
//        if(RightTriggerVal_prev > -0.9) {
//            std::cout<<"CHIP!"<<std::endl;
//            command.chipper = true;
//            command.chipper_forced = true;
//        }
//    }
//    /* ==================== */
//
//    // ==== Set kicker velocity
//    if(command.kicker || command.chipper) {
//        command.kicker_vel = 5.0;
//        command.chipper_vel = 5.0;
//    }
//
//    // ==== Set dribbler ====
//    btn = Xbox360Controller::LeftBumper;
//    if(getVal(msg.buttons, xbox360mapping.at(btn))){
//        if(!getVal(previousMsg.buttons, xbox360mapping.at(btn))){
//            joy.dribblerOn = !joy.dribblerOn;
//        }
//    }
//    command.dribbler = joy.dribblerOn;
//
//    // ==== Set geneva drive state
//    command.geneva_state = joy.genevaState;
//
//    /// ==== Check speed boundaries ==== ///
//    /* === Check x === */
//    // If speed is below -SPEED_MAX
//    if(command.y_vel < -joy.profile.SPEED_MAX) { command.y_vel = -joy.profile.SPEED_MAX; }
//        // If speed is inbetween -SPEED_MAX and SPEED_MAX
//    else if(-joy.profile.SPEED_MIN < command.y_vel && command.y_vel < joy.profile.SPEED_MIN) { command.y_vel =  0.0; }
//        // If speed is above SPEED_MAX
//    else if(joy.profile.SPEED_MAX < command.y_vel) { command.y_vel =  joy.profile.SPEED_MAX; }
//
//    /* === Check y === */
//    // If speed is below -SPEED_MAX
//    if(command.x_vel < -joy.profile.SPEED_MAX) { command.x_vel = -joy.profile.SPEED_MAX; }
//        // If speed is inbetween -SPEED_MAX and SPEED_MAX
//    else if(-joy.profile.SPEED_MIN <  command.x_vel && command.x_vel < joy.profile.SPEED_MIN) { command.x_vel =  0.0; }
//        // If speed is above SPEED_MAX
//    else if(joy.profile.SPEED_MAX < command.x_vel) { command.x_vel =  joy.profile.SPEED_MAX; }
//    /* ================================ */
//
//    joy.previousMsg = *joy.msg;
//
//    return command;
//
//
//
//}
//
//
