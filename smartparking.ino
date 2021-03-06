#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "oDj4oS4aI1wWTTII2WKy75tfEj_o--oH";
char ssid[] = "Diptendu123";
char pass[] = "abcdefgh";

WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led3(V3);
WidgetLED led4(V4);

int a,b,c,d;
String p = "slot1", q = "slot2", r = "slot3", s = "slot4";
  

void setup() {
  Serial.begin(9600);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D5, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  a = digitalRead(D1);
  b = digitalRead(D2);
  c = digitalRead(D3);
  d = digitalRead(D5);
  String data = String("D1 DATA:")+String(a)+String("|||||||||")+String("D2 DATA:")+String(b)+String("|||||||||")+String("D3 DATA:")+String(c)+String("|||||||||")+String("D5 DATA:")+String(d);
  Serial.print(data);
  Serial.print("/n");
  if(a == 1)
    {p = "SLOT 1 IS ENGAGED";led1.off();}
  if(a == 0)
    {p = "SLOT 1 IS VACANT";led1.on();}
  if(b == 1)
    {q = "SLOT 2 IS ENGAGED";led2.off();}
  if(b == 0)
    {q = "SLOT 2 IS VACANT";led2.on();}
  if(c == 1)
    {r = "SLOT 3 IS ENGAGED";led3.off();}
  if(c == 0)
    {r = "SLOT 3 IS VACANT";led3.on();}
  if(d == 1)
    {s = "SLOT 4 IS ENGAGED";led4.off();}
  if(d == 0)
    {s = "SLOT 4 IS VACANT";led4.on();}

  delay(500);
}