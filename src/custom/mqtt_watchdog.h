/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */


#ifndef HASP_mqtt_watchdog_H
#define HASP_mqtt_watchdog_H

#include "hasplib.h"
#if defined(HASP_USE_CUSTOM)

/* This function is called at boot */
void mqtt_watchdog_setup();

/* This function is called every itteration of the main loop */
void mqtt_watchdog_loop();

/* This function is called every second */
void mqtt_watchdog_every_second();

/* This function is called every 5 seconds */
void mqtt_watchdog_every_5seconds();

/* return true if the pin used by the custom code */
bool mqtt_watchdog_pin_in_use(uint8_t pin);

/* Add a key which defines a JsonObject to add to the sensor JSON output */
void mqtt_watchdog_get_sensors(JsonDocument& doc);

/* Receive custom topic & payload messages */
void mqtt_watchdog_topic_payload(const char* topic, const char* payload, uint8_t source);

#endif // HASP_USE_CUSTOM

#endif // HASP_mqtt_watchdog_H
