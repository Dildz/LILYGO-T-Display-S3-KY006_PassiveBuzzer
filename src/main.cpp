/*********************************************************************************************************
 * LilyGO T-Display-S3 Buzzer Melody Project
 *
 * Description:
 *   This code controls a KY-006 Passive Buzzer Module connected to a LilyGO T-Display-S3 microcontroller.
 *   It plays a melody using the BuzzerMelody library and displays the current status on the built-in 
 *   screen. The melody is controlled using the built-in BOOT and KEY buttons.
 *
 * How It Works:
 *   1. Buzzer Control: The code manages a passive buzzer, capable of playing melodies via PWM signals.
 *   2. Melody Playback: The buzzer plays a predefined melody (Super Mario Bros Theme) when the BOOT
 *       button is pressed. The KEY button stops the melody.
 *   3. The BuzzerMelody library makes it easier to play melodies using PWM signals.
 *   4. The TFT_eSPI library is used for displaying status information.
 *
 * Pin Connections:
 *   - Buzzer S Pin  -> GPIO1
 *   - Buzzer middle -> Not Connected
 *   - Buzzer - Pin  -> GND
 *   - LCD Backlight -> GPIO15
 * 
 *  KY-006 Specifications:
 *   - Operating Voltage: 3.3V to 5V
 *   - Sound Frequency Range: 1.5 kHz to 2.5 kHz
 *   - Type: Passive Piezoelectric Buzzer
 *   - Control Method: PWM Signal
 * 
 *  Notes:
 *   - The SuperMarioBrosTheme.h file was copied from the BuzzerMelody library example folder to this
 *     projects include folder.
 *********************************************************************************************************/


/*************************************************************
******************* INCLUDES & DEFINITIONS *******************
**************************************************************/

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <OneButton.h>
#include <BuzzerMelody.h>

#include "SuperMarioBrosTheme.h"
#include "helper_functions.h"

// Hardware definitions
#define BUZZER_PIN      1  // GPIO1
#define BUZZER_CHANNEL  0  // LEDC channel
#define PIN_LCD_BL      15 // Backlight control
#define BOOT_BUTTON_PIN 0  // GPIO0 (BOOT button)
#define KEY_BUTTON_PIN  14 // GPIO14 (KEY button)

// Global objects
TFT_eSPI tft = TFT_eSPI();
BuzzerMelody buzzerMelody0(BUZZER_PIN, BUZZER_CHANNEL, NUM_OF_NOTES0, melody0);
OneButton bootButton(BOOT_BUTTON_PIN, true);
OneButton keyButton(KEY_BUTTON_PIN, true);

// Global state variables
bool isPlaying = false;
bool redrawDisplay = true;


/*************************************************************
*********************** MAIN FUNCTIONS ***********************
**************************************************************/

// SETUP
void setup() {
  // Initialize the buzzer as stopped
  buzzerMelody0.stop();
  buzzerMelody0.setup();
  
  // Initialize the TFT display
  tft.init();
  tft.setRotation(0); // adjust rotation (0 & 2 portrait | 1 & 3 landscape)
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(2); // set the font size
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // set text colour (white) and background colour (black)

  // Draw static elements once
  drawStaticElements(tft);

  // Set up button event handlers
  keyButton.attachClick(onKeyPress);
  bootButton.attachClick(onBootPress);

  // Update the display initially
  updateDynamicElements(tft);
}

// MAIN LOOP
void loop() {
  // Keep the button states updated
  keyButton.tick();
  bootButton.tick();

  // Update the buzzer melody state
  buzzerMelody0.loop();

  // Update the display if something has changed
  if (redrawDisplay) {
    updateDynamicElements(tft);
    redrawDisplay = false; // reset the flag
  }
}
