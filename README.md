Arduino GPS Sensor Node
=========

This is an adaptation of the UKHASnet sensor code to allow the connection of a GPS module to update the LOCATION_STRING variable and so broadcast the node's location during a survey.

**Hardware**
The connected GPS can be any unit that streams standard NMEA words. The default baud rate of the GPS mus be set in **GPSBaud**. The serial connection is via Arduino pins 3 and 4 using SoftwareSerial.

**Code Changes**
All code changes are annotated by +++ to make them easy to find. Two additional libraries are required as follows: **tinyGPS++** parses the GPS NMEA output and allows extraction of lat and lon.
**SoftwareSerial** provides an additional serial port to handle the GPS output. Two new functions have been added: **gpsLocate()** fetches the lat/lon coordinates and updates LOCATION_STRING.
**smartDelay(ms)** refreshes the GPS coordinates.

**Portability**
Although originally tested on Moteino boards, the code should work on any Arduino based HASnet node providing the correct board is selected in the IDE.

**The original notes for the sensor node follow:**


arduino-sensor
==========

This is a low-power sensor implementation designed to be used with an ATMega168/328 and the Arduino IDE.

Sensors Supported:
* DS18B20 (Temperature)
* DHT22 (Temperature + Humidity)

This does not repeat, instead it sleeps inbetween it's own beacons to save battery power. This can run for many months off a single set of cheap AA batteries (7 months so far and counting!).


NodeConfig.h
======

Copy NodeConfig-template.h to NodeConfig.h to set up code for your nodes.

**char id[]**

This sets the ID, or callsign, of the repeater. This should be unique within the network, but as short as possible. You can see existing IDs on ukhas.net

**LOCATION_STRING**

If this is set then it will be sent as a location at boot and then every 25 packets. This sets the Lat/Long of the node on the map at ukhas.net

If you don't wish your location to be visible, comment out this line to disable it.

**BEACON_INTERVAL**

The time interval between the nodes own beacons will be a random number of seconds between (this value)x8 and (this value+10)x8

**rfm_power**

This configures the Transmit Power of the RFM69, in dBmW. eg. 1dBmW = 1mW, 10dBmW = 10mW, 17dBmW = 50mW, 20dBm = 100mW.

Note: Only the RFM69*H*W can transmit at more than 50mW.

**SENSOR_VCC**

This should be enabled when the sensor (DS18B20/DHT22) uses pin 'PB0' (Arduino 'D8') for positive voltage supply. This will allow the sensor to be fully powered down while the microcontroller is in sleep. The sensor will be powered up 15ms before communication is attempted.
