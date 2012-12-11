//const pin number
int ledUmbrella =  8;      // the number of the LED pin
int ledSunglasses = 9;      // the number of the LED pin
int ledMittens =  10;      // the number of the LED pin
int ledTissues =  11;      // the number of the LED pin
int ledPower =  7;      // the number of the LED pin



void setup() {
  Serial.begin(9600);

  // set the pin as output:
  pinMode(ledUmbrella, OUTPUT);      
  pinMode(ledSunglasses, OUTPUT);      
  pinMode(ledMittens, OUTPUT);      
  pinMode(ledTissues, OUTPUT);      
  pinMode(ledPower, OUTPUT);      

}

void loop(){


  /////Power Output///////////////////////////////////
  digitalWrite(ledPower, HIGH);
  
  /////Serial Read///////////////////////////////////
  while (Serial.available() == 0);
  int val = Serial.read() - '0';


  /////Umbrella Output///////////////////////////////////
  if (val == 0)
  {
    digitalWrite(ledUmbrella, HIGH);
  }

  if (val == 5)
  {
    digitalWrite(ledUmbrella, LOW);
  }

  /////Sunglasses Output///////////////////////////////////
  if (val == 1)
  {
    digitalWrite(ledSunglasses, HIGH);
  }

  if (val == 6)
  {
    digitalWrite(ledSunglasses, LOW);
  }


  /////Mittens Output///////////////////////////////////
  if (val == 2)
  {
    digitalWrite(ledMittens, HIGH);
  }

  if (val == 7)
  {
    digitalWrite(ledMittens, LOW);
  }


  /////Tissues Output///////////////////////////////////
  if (val == 3)
  {
    digitalWrite(ledTissues, HIGH);
  }

  if (val == 8)
  {
    digitalWrite(ledTissues, LOW);
  }




}


