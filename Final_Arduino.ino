//LED Pins
int ledUmbrella =  11;      // the number of the LED pin
int ledSunglasses = 10;      // the number of the LED pin
int ledMittens =  9;      // the number of the LED pin
int ledTissues =  8;      // the number of the LED pin
int ledPower =  12;      // the number of the LED pin

//SENSOR INT - TEMP
int sensorPinTemp = A0;

//SENSOR INT - SUNNIES
int sensorPinSunnies = A2;      
int sunniesValue = 0;  
int newSunniesValue;

//SENSOR INT - HUMID
float sensorPinHumid = A1;
float humidityValue = 0;
float relHumid = 0;



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

/////Humidity Input - from http://arduino.cc/forum/index.php/topic,19961.0.html#11///////////////////////////////////
  humidityValue = analogRead(sensorPinHumid);
  relHumid = ((((humidityValue/1023)*5)-0.8)/3.1)*100;
  //Serial.println(relHumid);

  delay(300);

/////Humidty Output
  if (relHumid >= 70)
  {
    Serial.println("Don't forget your umbrella!");
    digitalWrite(ledUmbrella, HIGH);
  }

  if (relHumid = 4)
  {
    Serial.println("You don't need an umbrella.");
    digitalWrite(ledUmbrella, LOW);
  }
/////Sun Input
  sunniesValue = analogRead(sensorPinSunnies);
  newSunniesValue = map(sunniesValue, 0, 1023, 0, 100);
  //Serial.println(newSunniesValue);
  
/////Sun Output
  if (newSunniesValue >= 20)
  {
    Serial.println("Don't forget your sunnies!");
    digitalWrite(ledSunglasses, HIGH);
  }

  if (newSunniesValue <= 10)
  {
    Serial.println("You don't need your sunnies.");
    digitalWrite(ledSunglasses, LOW);
  }


/////Temp Input - from adafruit tutorial

  // converting reading to voltage
  int readingGloves = analogRead(sensorPinTemp);  
  float voltageGloves = readingGloves * 5.0;
  voltageGloves /= 1024.0; 

  //convert to Celsius
  float temperatureC = (voltageGloves - 0.5) * 100;

  //convert to Fahrenheight
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
  Serial.println(temperatureF);

/////Temp Output
  if (temperatureF <= 45) 
  {
    Serial.println("Don't forget your gloves!"); 
    digitalWrite(ledMittens, HIGH);
  }

  if (temperatureF >= 46)
  {
    Serial.println("You don't need gloves.");
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



    Serial.flush();

}


