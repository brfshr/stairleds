# stairleds

Motion activated staircase lights using an Arduino, PIR motion sensors, and a WS2812B LED strip.

The goal of this project is to have animated lighting underneath the handrail of a staircase that turns on when motion is detected at the top or the bottom using PIR motion sensors.

This project requires the FastLED library - https://github.com/FastLED/FastLED

Components:
* WS2812B LED strip
* PIR motion sensors (x2)
* 1000uF capacitor
* 5v 10a power supply
* Solid single core wire (22AWG)
* Head shrink tubing

View of the lights going down the stairs.
![](images/stairview.JPG)

The LEDs from the other side of the railing.
![](images/stairview2.JPG)

Bottom motion sensor is connected directly to the LED strip. There's a wire running along side the LEDs to the Arduino.
![](images/bottomsensor.JPG)

Top motion sensor. Heat shrink tubing was used at the top and bottom to conceal solder points.
![](images/topsensor.JPG)

The LED strip had pre-installed adhesive that made mounting it to the underside of the handrail easy.
![](images/ledapplication.JPG)

The Arduino is hanging at the top of the stairs using the mount that it came with. I still need to 3D print a case and tidy up the wiring. :)
![](images/arduino.jpeg)
