#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <stdio.h>

SemaphoreHandle_t xBinarySemaphore;

void TaskA(void *pvParameters)
{
    while (1)
    {
        printf("TaskA: Sending signal\n");
        xSemaphoreGive(xBinarySemaphore); // Give semaphore to unblock TaskB
        vTaskDelay(pdMS_TO_TICKS(1000));  // Delay for 1 second
    }
}

void TaskB(void *pvParameters)
{
    while (1)
    {
        if (xSemaphoreTake(xBinarySemaphore, portMAX_DELAY) == pdTRUE)
        {
            printf("TaskB: Received signal! Doing work...\n");
        }
    }
}

int main(void)
{
    // Create binary semaphore
    xBinarySemaphore = xSemaphoreCreateBinary();

    if (xBinarySemaphore != NULL)
    {
        // Create the tasks
        xTaskCreate(TaskA, "TaskA", 128, NULL, 2, NULL);
        xTaskCreate(TaskB, "TaskB", 128, NULL, 1, NULL);

        // Start scheduler
        vTaskStartScheduler();
    }
    else
    {
        printf("Failed to create semaphore.\n");
    }

    while (1)
        ;
}
// This code implements a simple FreeRTOS application with two tasks and a binary semaphore.
// TaskA sends a signal to TaskB using the semaphore, allowing TaskB to perform its work.
// The tasks run indefinitely, demonstrating synchronization between them using the semaphore.