//We use a NodeMCU controller to monitor Dustbin 2

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#define TRIGGERPIN D1
#define ECHOPIN    D2


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon), copy and paste the auth token from the Blynk app here
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
// Type in your Wifi network id and password
char ssid[] = "";
char pass[] = "";

WidgetLCD lcd(V2);
WidgetLED led(V3);

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //1Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  lcd.print(4,0,"Dustbin 2"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  delay(1000);
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Distance in %"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  
  long distance,duration;
  
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3);  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  digitalWrite(TRIGGERPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);
  
  // distance= duration*0.034/2;
  distance= duration/58.2;
  Serial.print(distance);
  Serial.println("%");
  l:if(distance <=10)
  {
    lcd.clear();
    lcd.print(0,0,"Dustbin2 Empty %");
    lcd.print(7, 1,distance%100*10-20);
    if(distance <= 3)
    {
      led.on();
      Blynk.setProperty(V3,"color","#e80606");  // Red
    }
    else
    {
      led.on();
      Blynk.setProperty(V3,"color","#d69e04");  // Orange
    }
  }
  
  else if(distance <=0  || distance > 10)
  {
    lcd.print(0,1,"Dustbin2 Empty");
    led.on();
    Blynk.setProperty(V3,"color","#0c990c");  // Green
    if (distance<=0)
      goto l;
   }
  Blynk.run();
  delay(3500);
}
