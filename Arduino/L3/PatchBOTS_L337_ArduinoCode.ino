// =======================================================================================
//                          L3-37 - AlexaPI Voice Assistant
// =======================================================================================
//                               Written By: PatchBOTS
// =======================================================================================
//
// ---------------------------------------------------------------------------------------
//                              ARUDINO NANO - PIN LAYOUT 
// ---------------------------------------------------------------------------------------
//
//                           +-----+
//              +------------| USB |------------+
//              |            +-----+            |
//              | [ ]D13                 D12[ ] |   
//              | [ ]3.3V                D11[ ]~|   
//              | [ ]V.ref     ___       D10[ ]~|   
//              | [ ]A0       / N \       D9[ ]~|  HS-805BB+ Servo (per TicoServo Library) 
//              | [ ]A1      /  A  \      D8[ ] |  
//              | [ ]A2      \  N  /      D7[ ] |  
//              | [ ]A3       \_0_/       D6[ ]~|  
//              | [ ]A4                   D5[ ]~|  
//              | [ ]A5                   D4[ ] |   
//              | [ ]A6                   D3[ ]~|  NeoPixels
//              | [ ]A7                   D2[ ] |  Input from Pi
//     5v In    | [ ]5V                  GND[ ] |     
//              | [ ]RST                 RST[ ] |  
//     GnD In   | [ ]GND   5V MOSI GND   TX1[ ] |   
//              | [ ]Vin   [ ] [ ] [ ]   RX1[ ] |   
//              |          [ ] [ ] [ ]          |
//              |          MISO SCK RST         |
//              | NANO-V3                       |
//              +-------------------------------+

// ---------------------------------------------------------------------------------------
//                                   NOTES
// --------------------------------------------------------------------------------------





// ---------------------------------------------------------------------------------------
//                         Libraries
// ---------------------------------------------------------------------------------------
#include <Adafruit_NeoPixel.h> 
#include <Adafruit_TiCoServo.h>

// ---------------------------------------------------------------------------------------
//                          Definitions Variables
// ---------------------------------------------------------------------------------------

 //********************Pinouts****************
#define PiRead_Pin     2 // Digital Pin Reading GPIO pin from RaspPi
#define NeoPixels      3 // Digital Write for 'always on' LED (see notes)
#define Servo_Pin      9 // Digital PWM Pin for Servo 


 //********************NEOPIXELS****************
#define NUMPIXELS      4
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NeoPixels, NEO_GRB + NEO_KHZ800);


 //********************Servo****************
Adafruit_TiCoServo HeadServo;
//actual Min/Max of the HS-805BB+ is 556/2420. Head in down position will be at servo Max (endstop), and the Min will be the up position which will be tweaked. 
#define Servo_Min      2100 // tweak for up position (lower number-->higher head raise)
#define Servo_Max      2420 // Don't Touch. 


// ---------------------------------------------------------------------------------------
//                          Variables
// ---------------------------------------------------------------------------------------

int Trigger = 0; //varialbe attached to the read of the Servo_Pin


// =======================================================================================
//                          SETUP DEFINITIONS
// =======================================================================================

void setup() {

  //********************SETUP SERIAL****************
  Serial.begin(9600);

  //********************SETUP NEOPIXELS****************  
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();

  //*********************PIN MODES******************

  pinMode(PiRead_Pin, INPUT);
  pinMode(NeoPixels, OUTPUT);
  pinMode(Servo_Pin, OUTPUT);


  //*********************Servo setup******************
  HeadServo.attach(Servo_Pin);
  HeadServo.write(Servo_Max);
  
}

// =======================================================================================
//                          MAIN APPLICATION LOOP
// =======================================================================================

void loop() {

//***************Read and Map*******************
// Get the updated trigger value :
  int Trigger = digitalRead(PiRead_Pin);

 
/* 
   //Debug to check this is working
 
   Serial.print("Trigger=");
   Serial.println(Trigger);
*/
   
  

  if ( Trigger == 1 ) {
      HeadServo.write(Servo_Min);
      pixels.setPixelColor(0, pixels.Color(255,255,255)); 
      pixels.setPixelColor(1, pixels.Color(255,255,255)); 
      pixels.setPixelColor(2, pixels.Color(255,255,255)); 
      pixels.setPixelColor(3, pixels.Color(255,255,255));
     } 
     else {
      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.setPixelColor(1, pixels.Color(0,0,0)); 
      pixels.setPixelColor(2, pixels.Color(0,0,0)); 
      pixels.setPixelColor(3, pixels.Color(0,0,0));
      HeadServo.write(Servo_Max);
  }
pixels.show();
}



