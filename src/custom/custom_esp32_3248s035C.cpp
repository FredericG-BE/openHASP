// USAGE: - Copy this file to src\custom\my_custom_esp32_3248s035C_esp32_3248s035C.cpp, also copy my_custom_esp32_3248s035C_template.h and rename it to my_custom.h
//        - Uncomment in your user_config_override.h the line containing #define HASP_USE_CUSTOM 1
//        - Led state can be set with hasp/<yourplate>/custom/led and payload {"red":1,"green":1,"blue":1} 
//          Leds are on off only so use 1 or 0 on each led
//        - Light level will be sent with the topic hasp/<yourplate>/custom/light
//          Light level will update every 5 second only if it has changed by more than the tolerance value
#include "hasplib.h"

#if defined(HASP_USE_CUSTOM) && true

#include "hasp_debug.h"

#define LIGHT_SENSOR 34
#define LED_RED 4
#define LED_GREEN 16
#define LED_BLUE 17

int iLastLightLevel = 0; // light reading from the sensor
unsigned int iLightTolerance = 10; // to reduce messages only send light message if change is outside tolerance

void custom_esp32_3248s035C_setup()
{
    LOG_INFO(TAG_CUSTOM, "===> esp32-3248s035C INIT");

    // intialise light sensor
    pinMode(LIGHT_SENSOR, ANALOG);
    analogSetPinAttenuation(LIGHT_SENSOR, ADC_0db); // 0dB(1.0) 0~800mV
    iLastLightLevel = analogReadMilliVolts(LIGHT_SENSOR);
    
    // inialise led (off)
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    digitalWrite(LED_BLUE, HIGH); // off is HIGH, on is LOW 
    digitalWrite(LED_RED, HIGH); // off is HIGH, on is LOW 
    digitalWrite(LED_GREEN, HIGH); // off is HIGH, on is LOW 
}

void custom_esp32_3248s035C_loop()
{
}

void custom_esp32_3248s035C_every_second()
{
}

void custom_esp32_3248s035C_every_5seconds()
{
    char sLightLevel[32];

    // send light level reading if changed
    int iNewLightLevel = analogReadMilliVolts(LIGHT_SENSOR);
    if ((iNewLightLevel > (iLastLightLevel + iLightTolerance)) || (iNewLightLevel < (iLastLightLevel - iLightTolerance))) {
        snprintf_P(sLightLevel, sizeof(sLightLevel), PSTR("{\"light\":%d}"), iNewLightLevel);
        dispatch_state_subtopic("light",sLightLevel);
        iLastLightLevel = iNewLightLevel;
    }
}

bool custom_esp32_3248s035C_pin_in_use(uint8_t pin)
{
    switch(pin) {
        case LIGHT_SENSOR:
        case LED_BLUE:
        case LED_RED:
        case LED_GREEN:
            return true;
        default:
            return false;
    }
}

void custom_esp32_3248s035C_get_sensors(JsonDocument& doc)
{
}

void custom_esp32_3248s035C_topic_payload(const char* topic, const char* payload, uint8_t source)
{    
    // set the led bit1: red, bit2: green, bit3: blue
    if(!strcmp(topic, "led")) {
        StaticJsonDocument<1024> led_doc;
        deserializeJson(led_doc, payload);

        digitalWrite(LED_RED, led_doc["red"] == 1 ? LOW : HIGH); 
        digitalWrite(LED_GREEN, led_doc["green"] == 1  ? LOW : HIGH); 
        digitalWrite(LED_BLUE, led_doc["blue"] == 1  ? LOW : HIGH); 
    }
}

#endif // HASP_USE_CUSTOM