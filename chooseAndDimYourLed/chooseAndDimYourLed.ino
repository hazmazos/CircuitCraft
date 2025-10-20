/*
A program that uses 2 Potentiometers, 3 Leds, 3 1K Resistors and appropiate wire connections to allow for the selection of 3 leds
whilst also offering the ability to adjust the brightness of each led.
*/
int gLed = 11;
float gLedBrightness;

int yLed = 10;
float yLedBrightness;

int rLed = 9;
float rLedBrightness;

int leds [] = {gLed,yLed,rLed};

float conversion = 5.0/1023.0;

float changeBrightnessPin = A5;
float changeLedSelectionPin = A0;


float ledRead;
float chosenLed;

float brightnessRead;
float chosenBrightness;




void setup() {
  // put your setup code here, to run once:
  for(int led : leds){
    pinMode(led,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  chooseLed();

}

void chooseLed(){

  ledRead = analogRead(changeLedSelectionPin);
  chosenLed = ledRead * conversion;
  
  if(chosenLed<=1.0){
    for(int led : leds){
      turnOn(led);
      delay(450);
      turnOff(led);
      delay(150);
    }
  }

  else if(1<chosenLed && chosenLed<=2){
    turnAllOff(leds);
    customWrite(gLed);
  }

  else if(2<chosenLed && chosenLed<=3){
    customWrite(yLed);
  }

  else if(3<chosenLed && chosenLed<=4){
    customWrite(rLed);
  }

  else{
    customWriteAll();
  }
}

void turnOn(int pin){
  digitalWrite(pin,HIGH);
}
void turnOff(int pin){
  digitalWrite(pin,LOW);
}
void turnAllOff(int pins []){
  for(int led : leds){
    turnOff(led);
  }
}

void customWrite(int pin){
  brightnessRead = analogRead(changeBrightnessPin);
  chosenBrightness = brightnessRead * conversion;
  
  analogWrite(pin,chosenBrightness);
  
}
void customWriteAll(){
  for(int led : leds){
    customWrite (led);
  }

}