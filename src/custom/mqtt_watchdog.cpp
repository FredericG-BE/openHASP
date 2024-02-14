#include "hasplib.h"

#if defined(HASP_USE_CUSTOM) && true

#include "hasp_debug.h"
#include "mqtt_watchdog.h"

#define WATCHDOG_TO_MIN 3

static uint8_t cnt = 0;

void mqtt_watchdog_setup()
{
    LOG_INFO(TAG_CUSTOM, "MQTT Watchdog INIT"); 
}

void mqtt_watchdog_loop()
{
}

void mqtt_watchdog_every_second()
{
    cnt++;
    if (cnt > WATCHDOG_TO_MIN*60)
    {
        LOG_INFO(TAG_CUSTOM, "MQTT Watchdog triggered");
        delay(500);
        dispatch_reboot(true);
    }
}

void mqtt_watchdog_every_5seconds()
{
}

bool mqtt_watchdog_pin_in_use(uint8_t pin)
{
    return false;
}

void  mqtt_watchdog_get_sensors(JsonDocument& doc)
{
}

void mqtt_watchdog_topic_payload(const char* topic, const char* payload, uint8_t source)
{
    if(strcmp(topic, "heartbeat") == 0)
    {
        LOG_INFO(TAG_CUSTOM, "MQTT Watchdog HB received cnt was %d", cnt);
        cnt = 0;
    }
}

#endif // HASP_USE_CUSTOM