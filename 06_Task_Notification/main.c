#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>

// Simulated print for embedded environment
#define LOG(msg) printf("%s\n", msg)

// Task Handles
TaskHandle_t sensorTaskHandle = NULL;
TaskHandle_t processTaskHandle = NULL;

// Sensor Task — Sends notification
void SensorTask(void *pvParameters)
{
    while (1)
    {
        LOG("SensorTask: Reading sensor data...");
        vTaskDelay(pdMS_TO_TICKS(1000)); // simulate data read delay

        // Notify processing task that data is ready
        xTaskNotifyGive(processTaskHandle);
        LOG("SensorTask: Notified ProcessTask");
    }
}

// Processing Task — Waits for notification
void ProcessingTask(void *pvParameters)
{
    while (1)
    {
        // Wait until notified by SensorTask
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        LOG("ProcessingTask: Received notification. Processing data...");
    }
}

int main(void)
{
    LOG("System starting...");

    // Create tasks
    xTaskCreate(SensorTask, "SensorTask", 128, NULL, 2, &sensorTaskHandle);
    xTaskCreate(ProcessingTask, "ProcessTask", 128, NULL, 1, &processTaskHandle);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    while (1)
        ;
    return 0;
}
