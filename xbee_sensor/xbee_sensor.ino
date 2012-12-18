
//SENSOR INT - TEMP
int sensorPinTemp = A0;

//SENSOR INT - HUMID
float sensorPinHumid = A1;
float humidityValue = 0;
float relHumid = 0;

//SENSOR INT - SUNNIES
int sensorPinSunnies = A2;      
int sunniesValue = 0;  
int newSunniesValue;


void setup() {
  Serial.begin(9600);


}

void loop(){

  /////Serial Read///////////////////////////////////
  // while (Serial.available() == 0);
  //int val = Serial.read() - '0';

  /////Humidity Input - from http://arduino.cc/forum/index.php/topic,19961.0.html#11///////////////////////////////////
  humidityValue = analogRead(sensorPinHumid);
  relHumid = ((((humidityValue/1023)*5)-0.8)/3.1)*100;
  //Serial.println(relHumid);

  delay(300);

  /////Humidty Output
  if (relHumid >= 60)
  {
    Serial.println("U"); //need umbrella
  }

  if (relHumid <= 59)
  {
    Serial.println("u"); //no umbrella
  }

  /////Sun Input
  sunniesValue = analogRead(sensorPinSunnies);
  newSunniesValue = map(sunniesValue, 0, 1023, 0, 100);
  //Serial.println(newSunniesValue);

  /////Sun Output
  if (newSunniesValue >= 20)
  {
    Serial.println("S"); //need sunglasses
  }

  if (newSunniesValue <= 19)
  {
    Serial.println("s"); //no sunglasses
  }


  /////Temp Input - from adafruit tutorial

  // converting reading to voltage
  int readingGloves = analogRead(sensorPinTemp);  
  float voltageGloves = readingGloves * 5.0;
  voltageGloves /= 1024.0; 

  //convert to Celsius
  float temperatureC = (voltageGloves - 0.5) * 100;

  //convert to Fahrenheight
  float temperatureF = ((temperatureC * 9.0 / 5.0) + 32.0) * -1;

  //Serial.println(temperatureF);

  /////Temp Output
  if (temperatureF <= 45) 
  {
    Serial.println("m"); //need mittens
  }

  if (temperatureF >= 46)
  {
    Serial.println("M"); //no mittens
  }



  Serial.flush();

}




