#include <Adafruit_DotStar.h>

//Defining pins for the RGB Led on board the trinket
#define NUMPIXELS 1 
#define DATAPIN 7
#define CLOCKPIN 8

//Setup for the RGB Led
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

//Define the pins on trinket to read voltages
int ModeA = 1;  //Analog Pin 1
int ModeB = 2;  //Analog Pin 2
int Pair2 = 3;  //Analog Pin 3
int Pair4 = 4;  //Analog Pin 4

//Initialize the voltage values
int ModeA_val = 0;
int ModeB_val = 0;
int Pair2_val = 0;
int Pair4_val = 0;

void setup()
{
  //Start RGB Led
  strip.begin();
  strip.show();

  //Start a serial connection for debugging
  Serial.begin(9600);

  //Initialize Red LED
  pinMode(13, OUTPUT);  //Digital Pin 13 is an LED on the Trinket M0

  //Power feed for Resistance measurement
  pinMode(1,OUTPUT);  //Digital Pin 1 is the same as Analog Pin 0.
                      //pinMode is a function for digital Pins so we use 1
}

void loop()
{
  //Read voltages on each pin for PoE
  ModeA_val = analogRead(ModeA);
  ModeB_val = analogRead(ModeB);
  //End PoE Readings

  //Turn on voltage for resistance reading
  digitalWrite(1, HIGH);          //Turn on digital Pin 1 to create a voltage on the line        
  delay(150);                     //Provide enough time for the line to achieve steady state
  Pair2_val = analogRead(Pair2);  //Read voltage on Pair 2
  Pair4_val = analogRead(Pair4);  //Read voltage on Pair 4
  
  //Turn off voltage for resistance reading
  digitalWrite(1, LOW);           
  delay(150);

  //Display those voltages across serial link for debugging
  //Values will be between 0 and 1024. 
  Serial.print("Mode A: ");
  Serial.print(ModeA_val);
  Serial.println(" ");
  Serial.print("Mode B: ");
  Serial.print(ModeB_val);
  Serial.println(" ");
  Serial.print("Pair 2 present? ");
  Serial.print(Pair2_val);
  Serial.println(" ");
  Serial.print("Pair 4 present? ");
  Serial.print(Pair4_val);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");

  //If Pair 2 and Pair 4 are both connected to a transformer then
  //cause the RGB LED to go green.
  if((Pair2_val>150)&&(Pair4_val>150))
  {
    strip.setPixelColor(0, 0x00FF00); // green
    strip.show();
  }
  //If Pair 2 is connected, but Pair 4 is not connected to a transformer then
  //cause the RGB LED to go orange.
  else if((Pair2_val>150)&&(Pair4_val<150))
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

  //If voltage is present on pair 3, then blink red LED fast.
  if(ModeA_val>98 || ModeA_val<90)
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
  //If voltage is present on pair 1, then blink red LED slow.
  else if(ModeB_val>98 || ModeB_val<90)
  {
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    delay(300);
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
  }
  //If no voltage is present, darken the LED.
  else
  {
    digitalWrite(13, LOW);
  }
  delay(1000);
}
