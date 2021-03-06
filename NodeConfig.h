//************* Define Node that you're compiling for ****************/
#define WNC4

//************* Node-specific config ****************/
#ifdef WNC4
 char id[] = "WNC4";
 #define LOCATION_STRING "00.00000,-0.00000"
 byte num_repeats = '1'; //The number of hops the message will make in the network
 #define BATTV_FUDGE 1.109 // Battery Voltage ADC Calibration
 #define BEACON_INTERVAL 20 // Beacon Interval in seconds
 uint8_t rfm_power = 20; // dBmW
 #define DS18B20
 //#define ENABLE_BATTV_SENSOR // Comment out to disable
 #define BATTV_PIN 0 //ADC 0 - Battery Voltage, scaled to 1.1V
#endif

#ifdef YY01
 char id[] = "YY01";
 #define LOCATION_STRING "50.9346,-1.4531"
 byte num_repeats = '1'; //The number of hops the message will make in the network
 #define BATTV_FUDGE 1.109 // Battery Voltage ADC Calibration
 #define BEACON_INTERVAL 120 // Beacon Interval in seconds
 uint8_t rfm_power = 10; // dBmW
 #define DHT22
 #define SENSOR_VCC // Arduino Pin 8 used for switched Sensor Power Supply
 #define ENABLE_BATTV_SENSOR // Comment out to disable
 #define BATTV_PIN 0 //ADC 0 - Battery Voltage, scaled to 1.1V
#endif
