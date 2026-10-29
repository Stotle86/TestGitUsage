#include <Conceptinetics.h>

DMX_Slave dmx_slave (1);

uint16_t channelsReceived = (0);
uint16_t startReceived = (0);

const byte xSVOx = 2;
const byte xDIRx  = 5;
const byte EN = 8;

uint8_t DMXread;
uint8_t DMXreturn;
uint16_t posMAP;

void setup(){

    pinMode(EN, OUTPUT);
    digitalWrite(EN, LOW);
    pinMode(xSVOx, OUTPUT);
    pinMode(xDIRx, OUTPUT); 

  dmx_slave.enable ();
  dmx_slave.setStartAddress (1); 
  
}

void loop(){

POSmap();

 if (DMXread != posMAP) {

     while (posMAP > DMXread)
      {digitalWrite(xDIRx, HIGH);
        digitalWrite(xSVOx, HIGH);
        delayMicroseconds(1000);
        digitalWrite(xSVOx, LOW);
        delayMicroseconds(1000);
        POSmap();
      DMXreturn = DMXread;
      }delay(10);
    }

    while(posMAP < DMXread)
      {digitalWrite(xDIRx, LOW);
        digitalWrite(xSVOx, HIGH);
        delayMicroseconds(1000);
        digitalWrite(xSVOx, LOW);
        delayMicroseconds(1000);
        POSmap();
      DMXreturn = DMXread;
      }delay(10);

    while(DMXread == DMXreturn) 
     {readDATA();}
    } 

void POSmap() {

DMXread = map(dmx_slave.getChannelValue (1), 0 , 255 , 0 , 255);
posMAP = map(analogRead (A0) , 0, 785, 255, 0);

}

void readDATA() {

DMXread = map(dmx_slave.getChannelValue (1), 0 , 255 , 0 , 255);

}
