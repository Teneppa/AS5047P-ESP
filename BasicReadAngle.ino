// include the library for the AS5047P sensor.
#include <AS5047P.h>

// define a led pin.
#define LED_PIN 10

// define the chip select port.
#define AS5047P_CHIP_SELECT_PORT 15

// define the spi bus speed 
#define AS5047P_CUSTOM_SPI_BUS_SPEED 50000

// initialize a new AS5047P sensor object.
AS5047P as5047p(AS5047P_CHIP_SELECT_PORT, AS5047P_CUSTOM_SPI_BUS_SPEED);

// arduino setup routine
void setup() {

  // set the pinmode of the led pin to output.
  pinMode(LED_PIN, OUTPUT);

  // initialize the serial bus for the communication with your pc.
  Serial.begin(115200);

  // initialize the AS5047P sensor and hold if sensor can't be initialized.
  while (!as5047p.initSPI()) {
    Serial.println(F("Can't connect to the AS5047P sensor! Please check the connection..."));
    delay(500);
  }

}

// arduino loop routine
void loop() {

  // read the sensor
  digitalWrite(LED_PIN, HIGH);                    // activate the led.
  Serial.print("Angle: ");                        // print some text to the serial consol.
  Serial.println(as5047p.readAngleDegree());      // read the angle value from the AS5047P sensor an print it to the serial consol.
  delay(250);                                     // wait for 500 milli seconds.

  // wait
  digitalWrite(LED_PIN, LOW);                     // deactivate the led.
  delay(250);                                     // wait for 500 milli seconds.

}
