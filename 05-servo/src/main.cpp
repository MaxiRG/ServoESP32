/*
 *     Project 05-servo - main.cpp
 *
 * 
 *       IntroCom - Austral - 2022 - EAM
 *       Shows how a servo is positioned as per table
 *       Using ESP32 development board
 *
 *       Uses a C++ library for ESP32 servo
 */

#include <Arduino.h>

#include <Servo.h>          //  For library prototypes and definitions

/*
 *  Constants defined in platformio.ini
 *      MY_SERVO    GPIO where data is connected
 *      SERIAL_BAUD Serial port Baud rate
 */

#define END_LIST    -1      //  For end of table
#define MY_SERVO 14
#define VARIABLE_RESISTANCE 27

//    Positioning table
static const int grads[] = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, END_LIST};

Servo servo;                //    A new object of type Servo

static void
go_servo(int pos)
{

    servo.write(pos);
    delay(100);
    // Serial.printf("grads = %3d, real = %3d\n", pos, servo.read());
}

void
setup(void)
{
    pinMode(VARIABLE_RESISTANCE, INPUT);
    Serial.begin(SERIAL_BAUD);
    servo.attach(MY_SERVO); //    Attach GPIO pin to object Servo
    Serial.printf("\n\n05-servo\n");
    servo.write(0);
    delay(2000);
}

void
loop(void)
{
    int value = analogRead(VARIABLE_RESISTANCE);
    Serial.println(value);
    delay(100);

    int i, c, last,t;

    int pos = value/315 ;

    if(pos > 12){
        pos = 12;
    }
    go_servo(grads[pos]);

}


