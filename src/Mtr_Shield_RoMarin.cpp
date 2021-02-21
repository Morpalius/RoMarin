//
// Created by elfuius on 21/03/18.
// Reviewed by Darknut14 20/04/18

#include "motorshieldRomarin.h"

const uint8_t nbrOfMotorsMicro = 3;


motorshieldRomarin::motorshieldRomarin(uint8_t whichArduino, uint8_t address) {
    assert((address>=0)&&(address<127));
    _address = address;
    switch (whichArduino){
        case 0:
            _nbrOfMotors = nbrOfMotorsMicro;
            break;
        default:assert(false);
    }
    _currentPWM = new uint8_t[_nbrOfMotors];//malloc(_nbrOfMotors* sizeof(uint8_t));
    _currentDir = new uint8_t[_nbrOfMotors];//malloc(_nbrOfMotors* sizeof(uint8_t));
    for(uint8_t counter=0; counter<_nbrOfMotors; ++counter){
        _currentPWM[counter] = 0;
        _currentDir[counter] = 0;
    }
    Wire.begin(); //Init the i2c (reinit if already called)
}

motorshieldRomarin::motorshieldRomarin() {
    _currentDir=NULL;
    _currentPWM=NULL;
}

motorshieldRomarin::~motorshieldRomarin() {
    //free(_currentPWM);
    //free(_currentDir);
    delete[] _currentPWM;
    delete[] _currentDir;
}

int motorshieldRomarin::setDirection(uint8_t motor, uint8_t dir) {
    if ((motor<0) || (motor>=_nbrOfMotors)){
        return 1;
    }
    if (not((dir==0)|| (dir==1))){
        return 2;
    }

    //Check if change
    if (dir != _currentDir[motor]){
        _currentDir[motor] = dir; //Apply change in memory
        return _writeMotor(motor); //Write to slave
    }
    return 0;
}

int motorshieldRomarin::setSpeed(uint8_t motor, uint8_t speed) {
    if ((motor < 0) || (motor >= _nbrOfMotors)) {
        return 1;
    }

    //Check if change
    if (speed != _currentPWM[motor]){
        _currentPWM[motor] = speed; //Apply change in memory
        return _writeMotor(motor); //Write to slave
    }
    return 0;
}

int motorshieldRomarin::_writeMotor(uint8_t thisMotor){

    Wire.beginTransmission(_address);
    Wire.write(thisMotor);
    Wire.write(_currentDir[thisMotor]);
    Wire.write(_currentPWM[thisMotor]);
    return (int) Wire.endTransmission();
}


