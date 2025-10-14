/*
A program to be used with an Arduino UNO, 3 LEDS, 3 1K resistors, 1K potentiometer and 7 wires to mimic a character selection screen except you are selecting an led
and certain effects outside of selection
*/
float readV = A5;
int redLed=4;
int yelLed=8; 
int greLed=12;

int leds [] = {redLed,yelLed,greLed};


float conv = 5.0/1023.0;
float V0;
float V1;

void setup() {
  // put your setup code here, to run once:
  pinMode(readV,INPUT);
  pinMode(redLed,OUTPUT);
  pinMode(yelLed,OUTPUT);
  pinMode(greLed,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // get the voltage across the potentiometer to see how far it has been "scrolled"
  V0=analogRead(A5);
  V1 = V0 * conv;

  // turn all leds off
  for(int led : leds){
    digitalWrite(led,LOW);
  }
  
  // selection 1
  if (0.5<=V1 && V1<=2){
    digitalWrite(redLed,HIGH);
  }

  // selection 2
  else if (2<=V1 && V1<=3){
    digitalWrite(yelLed,HIGH);
  }

  // selection 3
  else if (3<=V1 && V1<=4){
    digitalWrite(greLed,HIGH);
  }

  // all will be on
  else if(4<=V1)
  {
      digitalWrite(greLed,HIGH);
      digitalWrite(yelLed,HIGH);
      digitalWrite(redLed,HIGH);
  }
  
  // will flicker on and off in a cyclic pattern between fully off and selection 1
  else if(V1<=0.5){

     for(int led : leds){
      digitalWrite(led,HIGH);
      delay(300);
      digitalWrite(led,LOW);
      delay(50);
    }


  }
    

}
