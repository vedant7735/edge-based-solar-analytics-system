#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t sensorTaskHandle;

void readSensors() {
    Serial.println("Reading sensors...");
}

void sensorTask(void *pvParameters) {
    while (1) {
        readSensors();
        vTaskDelay(pdMS_TO_TICKS(30000));
    }
}

void setup() {
    Serial.begin(115200);

    xTaskCreate(
        sensorTask,        // Function
        "Sensor Task",     // Name
        2048,              // Stack size
        NULL,              // Parameters
        1,                 // Priority
        &sensorTaskHandle  // Task handle
    );
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000)); // 1 second delay
}