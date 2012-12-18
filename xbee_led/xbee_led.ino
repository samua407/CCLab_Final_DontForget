//LED Pins
int ledUmbrella =  11;      // the number of the LED pin
int ledSunglasses = 9;      // the number of the LED pin
int ledMittens =  7;      // the number of the LED pin
//int ledTissues =  8;      // the number of the LED pin
int ledPower =  13;      // the number of the LED pin


void setup() {
  Serial.begin(9600);

  // set the pin as output:
  pinMode(ledUmbrella, OUTPUT);      
  pinMode(ledSunglasses, OUTPUT);      
  pinMode(ledMittens, OUTPUT);      
  //pinMode(ledTissues, OUTPUT);      
  pinMode(ledPower, OUTPUT);      

}

void loop(){
  while(Serial.available()){  //is there anything to read?
    char getData = Serial.read();  //if yes, read it

    digitalWrite(ledPower, HIGH);

    if(getData == 'U'){
      digitalWrite(ledUmbrella, HIGH);
    }
    else if(getData == 'u'){
      digitalWrite(ledUmbrella, LOW);
    }

    if(getData == 'S'){
      digitalWrite(ledSunglasses, HIGH);
    }
    else if(getData == 's'){
      digitalWrite(ledSunglasses, LOW);
    }

    if(getData == 'M'){
      digitalWrite(ledMittens, HIGH);
    }
    else if(getData == 'm'){
      digitalWrite(ledMittens, LOW);
    }

    // if(getData == 'T'){
    //   digitalWrite(ledTissues, HIGH);
    // }
    // else if(getData == 't'){
    //   digitalWrite(ledTissues, LOW);
    // }
  }
}



