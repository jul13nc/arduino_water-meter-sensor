# Water meter sensor 

Using a proximity sensor LJ18A3-8-Z to tranform the water meter rotating wheel to a Zigbee Switch

## LJ18A3-8-Z / Arduino

Connect LJ18A3-8-Z to arduino using the following pins

* Blue to GND
* Brown to 5V
* Black to pin 6

## Arduino / Zigbee Switch

Using an optocoupler to simulate button press on the Zigbee switch from the Arduino

The optocoupler is connected to the arduino using the following pins

* 1 to Pin 2 via 220Ohm resistor
* 2 to GND
* 3 not used
* 4 not used
* 5 to Interruptor
* 6 to Interruptor


