#include <Arduino.h>
#include <FastLED.h>

/* Chipset of the LED strip */
#define LED_CONTROLLER WS2801
/* LED strip color order */
#define LED_COLOR_ORDER GBR
/* DATA_PIN, CLOCK_PIN of the SPI */
#define LED_PINS PIN_SPI_MOSI, PIN_SPI_SCK
/* Number of LEDs in the strip */
#define LED_COUNT 28

#define LED_TEST_ENABLE true
#define LED_TEST_DELAY 500

//#define DEBUG true

/* LED strip data */
CRGB leds[LED_COUNT];

/* Test LEDs by cycling through colors and LEDs */
void testLEDs()
{
  const CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
  for (const auto &color : colors)
  {
    for (int i = 0; i < LED_COUNT; i++)
    {
      leds[i] = color;
      FastLED.show();
      delay(LED_TEST_DELAY);
      // toggle initialization LED to show progress
      digitalWrite(13, !digitalRead(13));
    }
  }
}

/* Set all LEDs to a specific color */
void allLEDsToColor(const CRGB &color)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds[i] = color;
  }
  FastLED.show();
}

void testAllLEDs() {
  allLEDsToColor(CRGB::Red);
  delay(LED_TEST_DELAY);
  allLEDsToColor(CRGB::Green);
  delay(LED_TEST_DELAY);
  allLEDsToColor(CRGB::Blue);
  delay(LED_TEST_DELAY);
}

int main()
{
  // setup Arduino core timers such that delay() works as expected
  init();

  // use D13 to indicate initialization status
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

#ifdef DEBUG
  Serial.begin(9600);
#endif

  FastLED.addLeds<LED_CONTROLLER, LED_PINS, LED_COLOR_ORDER>(leds, LED_COUNT);
  FastLED.setBrightness(64);

#ifdef DEBUG
  Serial.println("initialized");
#endif

  // startup tests (run through all colors and leds)
  if (LED_TEST_ENABLE)
  {
    //testLEDs();
    testAllLEDs();
  }

#ifdef DEBUG
  Serial.println("tested");
#endif

  // set LEDs to a nice color
  allLEDsToColor(CRGB::Orange4);

  digitalWrite(13, LOW); // turn off status LED

  while (1)
    ;
}
