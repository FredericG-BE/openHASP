/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */


#ifndef HASP_custom_esp32_3248s035C_H
#define HASP_custom_esp32_3248s035C_H

#include "hasplib.h"
#if defined(HASP_USE_CUSTOM)

/* This function is called at boot */
void custom_esp32_3248s035C_setup();

/* This function is called every itteration of the main loop */
void custom_esp32_3248s035C_loop();

/* This function is called every second */
void custom_esp32_3248s035C_every_second();

/* This function is called every 5 seconds */
void custom_esp32_3248s035C_every_5seconds();

/* return true if the pin used by the custom code */
bool custom_esp32_3248s035C_pin_in_use(uint8_t pin);

/* Add a key which defines a JsonObject to add to the sensor JSON output */
void custom_esp32_3248s035C_get_sensors(JsonDocument& doc);

/* Receive custom topic & payload messages */
void custom_esp32_3248s035C_topic_payload(const char* topic, const char* payload, uint8_t source);

#endif // HASP_USE_CUSTOM

#endif // HASP_custom_esp32_3248s035C_H
