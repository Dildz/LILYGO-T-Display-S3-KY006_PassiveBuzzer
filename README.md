 LilyGO T-Display-S3 Buzzer Melody Project
 
 Description:
 
   This code controls a KY-006 Passive Buzzer Module connected to a LilyGO T-Display-S3 microcontroller.
   
   It plays a melody using the BuzzerMelody library and displays the current status on the built-in 
   screen. The melody is controlled using the built-in BOOT and KEY buttons.
 
 How It Works:
 
   1. Buzzer Control: The code manages a passive buzzer, capable of playing melodies via PWM signals.
   2. Melody Playback: The buzzer plays a predefined melody (Super Mario Bros Theme) when the BOOT
       button is pressed. The KEY button stops the melody.
   3. The BuzzerMelody library makes it easier to play melodies using PWM signals.
   4. The TFT_eSPI library is used for displaying status information.
 
 Pin Connections:
   - Buzzer S Pin  -> GPIO1
   - Buzzer middle -> Not Connected
   - Buzzer - Pin  -> GND
   - LCD Backlight -> GPIO15
 
 KY-006 Specifications:
   - Operating Voltage: 3.3V to 5V
   - Sound Frequency Range: 1.5 kHz to 2.5 kHz
   - Type: Passive Piezoelectric Buzzer
   - Control Method: PWM Signal
 
  Notes:
   - The SuperMarioBrosTheme.h file was copied from the BuzzerMelody library example folder to this
     projects include folder.
