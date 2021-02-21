import smbus2
import time
    
 #for raspberry pi 1 use 0
# I2C address for testing
nbrMotoMax = 3
#addr = 0x48


class MotoShield:
    
    def __init__(self):
        self._bus_pi = smbus.SMBus(1)
        self._currentDir   = [0, 0, 0]
        self._currentSpeed = [0, 0, 0]
        self._addr = 0
        
    def initmotorShield (mCflag, addr):
        if(mCflag):
            nbrMoto = nbrMotoMax
        else :
            Exit()

        self._addr = addr
        self._currentSpeed = [0, 0, 0]#values must be between 0-255
        self._currentDir = [0, 0, 0]#values must be between 0-1
        
        #needs to be ended

    def setDirection(motor, direction):
        if ((motor<0) or (motor>=nbrMotoMax)):
            return 1
        if (direction != 1) or (direction != 0):
            return 1

        if (direction != currentdir[motor]):
            self._currentdir[motor] = direction

        return writeMotor(motor)

    def setSpeed(motor, Speed):
        if ((motor<0) or (motor>=nbrMotoMax)):
            return 1
        if (Speed < 0) or (Speed > 255):
            return 1

        if (Speed != currentdSpeed[motor]):
            self._currentSpeed[motor]= Speed

        return writeMotor(motor)

    def __writeMotor(motor):
        bus_pi.write_byte(self._addr, motor)
        bus_pi.write_byte(self._addr, self._currentDir[motor])
        bus_pi.write_byte(self._addr, self._currentSpeed[motor])
        
        return 0
        
    
