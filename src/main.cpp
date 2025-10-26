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
/* Color correction */
#define LED_COLOR_CORRECTION TypicalLEDStrip

// Short initialization test of the LEDs
#define LED_TEST_ENABLE true
#define LED_TEST_DELAY 250


/* LED strip data */
CRGB leds[LED_COUNT];

/* Set all LEDs to a specific color */
void allLEDsToColor(const CRGB &color)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds[i] = color;
  }
  FastLED.show();
}

/* Test all LEDs by cycling through Red, Green, and Blue */
void testAllLEDs() {
  allLEDsToColor(CRGB::Red);
  delay(LED_TEST_DELAY);
  allLEDsToColor(CRGB::Green);
  delay(LED_TEST_DELAY);
  allLEDsToColor(CRGB::Blue);
  delay(LED_TEST_DELAY);

  // test through brightness levels
  for (int b = 0; b <= 255; b += 1) {
    FastLED.setBrightness(b);
    allLEDsToColor(CRGB::White);
    // reach top brightness within 1 second
    delay((int)((float)1000/255));
  }
}

int main()
{
  // setup Arduino core timers such that delay() works as expected
  init();

  FastLED.addLeds<LED_CONTROLLER, LED_PINS, LED_COLOR_ORDER>(leds, LED_COUNT);
  FastLED.setCorrection(LED_COLOR_CORRECTION);
  FastLED.setBrightness(128);

  // initialization test
  if (LED_TEST_ENABLE)
  {
    testAllLEDs();
  }

  // set LEDs to a nice color
  allLEDsToColor(CRGB::FairyLight);

  // idle forever
  for (;;) {
    delay(1000);
  }
}
