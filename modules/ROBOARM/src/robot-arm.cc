#include "robot-arm.hh"

RobotArmController::RobotArmController(Stepper &x_axis, Stepper &y_axis, Stepper &z_axis,
                                       hwlib::target::pin_in &xLimitSwitch,
                                       hwlib::target::pin_in &yLimitSwitch) :
        x_axis(x_axis),
        y_axis(y_axis),
        z_axis(z_axis),
        xLimitSwitch(xLimitSwitch),
        yLimitSwitch(yLimitSwitch) {

}


void RobotArmController::reset() {
    rotateAxis(RobotAxis::Y, 250, false);
}

void RobotArmController::rotateAxis(RobotAxis axis, int degrees, bool clockwise) {

    int requiredSteps = (int) (microStepsArms * (degrees * armStepRatio) / stepSize);
    if(axis == RobotAxis::Z) {
      requiredSteps = (int) (microStepsBase * (degrees * baseStepRatio) / stepSize);
    }
    for(uint16_t stepsTaken = 0; stepsTaken<requiredSteps; stepsTaken++) {
        switch (axis) {
            case RobotAxis::X:
                if((checkLimitations() == 3 || checkLimitations() == 1) && !clockwise) {
                    break;
                }
                x_axis.step(clockwise);
                break;
            case RobotAxis::Y:
                if((checkLimitations() == 3 || checkLimitations() == 2) && !clockwise) {
                    break;
                }
                y_axis.step(clockwise);
                break;
            case RobotAxis::Z:
                z_axis.step(clockwise);
                break;

        }
    }
}

int RobotArmController::checkLimitations() {
    if (!xLimitSwitch.get() && !yLimitSwitch.get()) {
        return 3;
    } else if (!xLimitSwitch.get()) {
        return 1;
    } else if (!yLimitSwitch.get()) {
        return 2;
    } else {
        return 0;
    }

}
