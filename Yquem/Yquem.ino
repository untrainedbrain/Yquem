// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// This demo code returns raw readings, public domain
#include <Streaming.h>
#include <stdint.h>
#include <String.h>
#include <Adafruit_TFTLCD.h>
#include <Adafruit_ILI9341.h>
#include "TouchScreen.h"

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin
#define OHMS 300
// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, OHMS);

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

String buttonlabels[20] = { "1", "2", "3", "PUSH", "CLR",
                            "4", "5", "6", "VOL+", "VOL-",
                            "7", "8", "9", "MODE", "BAND",
                            ".", "0", "SCN-", "STEP", "SCN+" };
uint16_t buttoncolors[20] = {ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_DARKGREEN, ILI9341_RED,
                             ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_ORANGE, ILI9341_ORANGE,
                             ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_DARKGREY, ILI9341_DARKGREY,
                             ILI9341_BLUE, ILI9341_BLUE, ILI9341_ORANGE, ILI9341_ORANGE, ILI9341_ORANGE, };

class Button : Adafruit_GFX_Button
{
private:
  String label;
  uint16_t color;
  int id;
  int x;
  int y;
  int w;
  int h;
  String text;

public:
    init(Adafruit_TFTLCD tft, int X, int Y, int W, int H, String Text)
    {
      initButton( tft, X, Y, H, W, Text.charstring());
      x = X;
      y = Y;
      w = W;
      h = H;
      label = Text;
    }
    setPos( int X, int Y)
    {
      x = X;
      y = Y;
    }
};

#define BUTTON_COUNT 20
class Bag {
private:
  Button* buttons;
  int buttonCount = BUTTON_COUNT;
  int id;
  Adafruit_TFTLCD tft;
  int rows;
  int cols;
  int height;
  int width;
  int offsetX;
  int offsetY;
  int spacingX;
  int spacingY;
  int textSize;

public:
    Bag( Adafruit_TFTLCD Tft, int Count);
  int count;

};

Bag::Bag( Adafruit_TFTLCD Tft, int Count, int Rows, int Cols ) {
    buttonCount = rows * cols;
    rows = Rows;
    cols = Cols;
    tft = Tft;
    buttons = new Button[buttonCount];
}

Bag::spacing( int X, int Y )
{
  spacingX = X;
  spacingY = Y;
}
Bag::textSize( int Size )
{
  textSize = Size;
}
Bag::buttonWidthHeight( int W, int H)
{
  height = H;
  width = w;
}
Bag::initButtons( int X, int Y )
{
int row = 0;
int col = 0;
int x = 0;
int y = 0;

    for( int button = 0; buttons < buttonCount; buttons++ )
    {
        x = button % rows + offsetX;
        y = button / cols + offsetY;

        buttons[button]->init( tft,  x,  y,  width,  height,  buttonlabels[button]);
    }
}

  buttons[0]->init( &tft, )
  // create buttons
  for (uint8_t row=0; row<4; row++) {
    for (uint8_t col=0; col<5; col++) {
      buttons[col+row*5]->init( &tft, row, col,  )

      buttons[col + row*5].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X),
                                                BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                                                 BUTTON_W, BUTTON_H, ILI9341_WHITE, buttoncolors[col+row*5], ILI9341_WHITE,
                                                 buttonlabels[col + row*5], BUTTON_TEXTSIZE);
                                     buttons[col + row*5].drawButton();
                                   }
                                 }
}
//Adafruit_GFX_Button buttons[20];
Bag ButtonBag( &tft, 4, 5, );


//---------------------SETUP------------
void setup(void) {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));

  ButtonBag.createButtons( 30,90,35,30,10,10,1)


#ifdef USE_ADAFRUIT_SHIELD_PINOUT
  Serial.println(F("Using Adafruit 2.4\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Adafruit 2.4\" TFT Breakout Board Pinout"));
#endif

class Color {
public:
  #define	BLACK   0x0000
  #define	BLUE    0x001F
  #define	RED     0xF800
  #define	GREEN   0x07E0
  #define CYAN    0x07FF
  #define MAGENTA 0xF81F
  #define YELLOW  0xFFE0
  #define WHITE   0xFFFF
  int black( void )
  {
      return (BLACK);
  }

};
// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

  //Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());

  String SizeBanner = String("TFT size is " );
  SizeBanner += tft.width()  + "x";
  SizeBanner += tft.height() + "y";
  Serial << SizeBanner;

  tft.reset();

    uint16_t identifier = tft.readID();
   if(identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if(identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if(identifier == 0x4535) {
    Serial.println(F("Found LGDP4535 LCD driver"));
  }else if(identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if(identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if(identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else if(identifier==0x0101)
  {
      identifier=0x9341;
       Serial.println(F("Found 0x9341 LCD driver"));
  }
  else if(identifier==0x1111)
  {
      identifier=0x9328;
       Serial.println(F("Found 0x9328 LCD driver"));
  }
  else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    identifier=0x9328;

  }

  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  // Note Rotate 1 (landscape) for this display puts the USB port in upper left.




  // create 'text field'
  tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_WHITE);
}

void loop(void) {
  // a point object holds x y and z coordinates
  TSPoint p = ts.getPoint();

  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > ts.pressureThreshhold) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  }

  delay(100);
}
