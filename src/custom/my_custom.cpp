#include "hasplib.h"

#if defined(HASP_USE_CUSTOM) && true

#include "hasp_debug.h"

#include "mqtt_watchdog.h"
#include "custom_esp32_3248s035C.h"

void custom_setup()
{
    mqtt_watchdog_setup();
    #ifdef CUSTOM_ESP32_3248s035C
        custom_esp32_3248s035C_setup();
    #endif
}

void custom_loop()
{
    mqtt_watchdog_loop();

    #ifdef CUSTOM_ESP32_3248s035C
        custom_esp32_3248s035C_loop();
    #endif 
}

void custom_every_second()
{
     mqtt_watchdog_every_second();

    #ifdef CUSTOM_ESP32_3248s035C
        custom_esp32_3248s035C_every_second();
    #endif 
    
}

void custom_every_5seconds()
{
    mqtt_watchdog_every_5seconds();    

    #ifdef CUSTOM_ESP32_3248s035C
        custom_esp32_3248s035C_every_5seconds();
    #endif 

}

bool custom_pin_in_use(uint8_t pin)
{
    bool inUse = false;

    inUse |= mqtt_watchdog_pin_in_use(pin);
    
    #ifdef CUSTOM_ESP32_3248s035C
        inUse |= custom_esp32_3248s035C_pin_in_use(pin);
    #endif
    
    return inUse;
}

void custom_get_sensors(JsonDocument& doc)
{
    mqtt_watchdog_get_sensors(doc);

    #ifdef CUSTOM_ESP32_3248s035C
        custom_esp32_3248s035C_get_sensors(doc);
    #endif   
}

void custom_topic_payload(const char* topic, const char* payload, uint8_t source)
{
    mqtt_watchdog_topic_payload(topic, payload, source);    
    #ifdef CUSTOM_ESP32_3248s035C
        custom_esp32_3248s035C_topic_payload(topic, payload, source);
    #endif
}

#endif // HASP_USE_CUSTOM