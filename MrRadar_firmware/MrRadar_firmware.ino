#include <Adafruit_DotStar.h>

//Defining pins for the RGB Led on board the trinket
#define NUMPIXELS 1 
#define DATAPIN 7
#define CLOCKPIN 8

//Setup for the RGB Led
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

//Define the pins on trinket to read voltages
int ModeA = 1;
int ModeB = 2;
int p3 = 3;
int p4 = 4;

//Initialize the voltage values
int ModeA_val = 0;
int ModeB_val = 0;
int p3_val = 0;
int p4_val = 0;

void setup()
{
  //Start RGB Led
  strip.begin();
  strip.show();

  //Start a serial connection for debugging
  Serial.begin(9600);

  //Initialize Red LED
  pinMode(13, OUTPUT);

  //Power feed for Resistance measurement
  pinMode(1,OUTPUT);

}

void loop()
{
  //Read voltages on each pin for PoE
  ModeA_val = analogRead(ModeA);
  ModeB_val = analogRead(ModeB);
  //End PoE Readings

  //Turn on voltage for resistance reading
  digitalWrite(1, HIGH);          
  delay(50);
  p3_val = analogRead(p3);
  p4_val = analogRead(p4);
  
  //Turn off voltage for resistance reading
  digitalWrite(1, LOW);           
  delay(50);

  //Display those voltages across serial link for debuggin
  Serial.print(ModeA_val);
  Serial.println(" ");
  Serial.print(ModeB_val);
  Serial.println(" ");
  Serial.print(p3_val);
  Serial.println(" ");
  Serial.print(p4_val);
  Serial.println(" ");
  
  Serial.println(" ");
  Serial.println(" ");

  //If Pair 2 and Pair 4 are both connected to a transfomer then
  //cause the RGB LED to go green.
  if((p3_val>150)&&(p4_val>150))
  {
    strip.setPixelColor(0, 0x00FF00); // green
    strip.show();
  }
  //If Pair 2 is connected, but Pair 4 is not connected to a transfomer then
  //cause the RGB LED to go orange.
  else if((p3_val>150)&&(p4_val<150))
  {
    strip.setPixelColor(0, 255,165,0); // orange
    strip.show();
  }
  //If neither pair is connected, turn off the RGB LED.
  else
  {
    strip.clear();
    strip.show();
  }

  //If voltage is present on pairs 2 and 3, then blink red LED fast.
  if(ModeA_val>15 || ModeA_val==0)
  {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);   
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
    digitalWrite(13, HIGH);                           
  }
  //If voltage is present on pairs 1 and 4, then blink red LED slow.
  else if(ModeB_val>15 || ModeB_val==0)
  {
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    delay(300);
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, HIGH);
  }
  //If no voltage is present, darken the LED.
  else
  {
    digitalWrite(13, LOW);
  }
  delay(250);
}
