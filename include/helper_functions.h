/*
 * helper_functions.h
 */

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <BuzzerMelody.h>

// Forward declarations (these are defined in the main file)
extern TFT_eSPI tft;
extern BuzzerMelody buzzerMelody0;
extern bool isPlaying;
extern bool redrawDisplay;
 
/**************************************************************
 ********************** HELPER FUNCTIONS **********************
 **************************************************************/
 
// Draw static screen elements
void drawStaticElements(TFT_eSPI &tft) {
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.setCursor(0, 0);
  tft.println("----------------------------");
  tft.println("  KY006 Passive Buzzer");
  tft.println("----------------------------");
  tft.setCursor(0, 70);
  tft.print("Status: ");
  tft.setCursor(0, 305);
  tft.print("PLAY");
  tft.setCursor(137, 305);
  tft.print("STOP");
}

// Update dynamic screen elements
void updateDynamicElements(TFT_eSPI &tft) {
  tft.setCursor(50, 70);
  tft.print("              "); // clear previous text (14 spaces)
  tft.setCursor(50, 70);
  tft.print(isPlaying ? "PLAYING" : "STOPPED");
}

// Button press handlers
void onKeyPress() {
  if (isPlaying) {
    buzzerMelody0.stop();
    isPlaying = false;
    redrawDisplay = true;
  }
}

void onBootPress() {
  if (!isPlaying) {
    buzzerMelody0.play();
    isPlaying = true;
    redrawDisplay = true;
  }
}

#endif // HELPER_FUNCTIONS_H
