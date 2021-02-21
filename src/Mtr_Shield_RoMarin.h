//
// Created by elfuius on 21/03/18.
//

#ifndef MOTORSHIELDROMARIN_MOTORSHIELDROMARIN_H
#define MOTORSHIELDROMARIN_MOTORSHIELDROMARIN_H

#include <assert.h>
#include <Wire.h>

/*
 * motorshieldRomarin is designed to cooperate
 */

class motorshieldRomarin {
public:
    /* Initialisation
     * whichArduino assignement: 0->micro, other->todo
    */
    motorshieldRomarin();
    motorshieldRomarin(uint8_t whichArduino, uint8_t address);
    ~motorshieldRomarin();


    /*
     * Functions to command the motors
     * the return int is for debugging:
     * 0 : Everything is ok
     * 11 : motor is not defined ( 0<= motor < nbrOfMotors does not hold )
     * 12 : Value is out of range (dir is not 0 or 1)
     * Other : See the errors of Wire listed at https://www.arduino.cc/en/Reference/WireEndTransmission
     */
    int setDirection(uint8_t motor, uint8_t dir);
    int setSpeed(uint8_t motor, uint8_t speed);

private:
    int _writeMotor(uint8_t thisMotor);
    uint8_t * _currentPWM;
    uint8_t * _currentDir;
    uint8_t _address, _nbrOfMotors;
};


#endif //MOTORSHIELDROMARIN_MOTORSHIELDROMARIN_H
