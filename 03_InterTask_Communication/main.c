#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define QUEUE_LENGTH 5
#define QUEUE_ITEM_SIZE sizeof(int)
#define PRODUCER_DELAY pdMS_TO_TICKS(1000)
#define CONSUMER_DELAY pdMS_TO_TICKS(500)

// Queue handle
QueueHandle_t xQueue;

// Producer task: sends an integer to the queue every second
void vProducerTask(void *pvParameters)
{
    int counter = 0;
    while (1)
    {
        if (xQueueSend(xQueue, &counter, portMAX_DELAY) == pdPASS)
        {
            printf("Producer sent: %d\n", counter);
            counter++;
        }
        vTaskDelay(PRODUCER_DELAY);
    }
}

// Consumer task: receives and prints data from the queue
void vConsumerTask(void *pvParameters)
{
    int receivedValue = 0;
    while (1)
    {
        if (xQueueReceive(xQueue, &receivedValue, portMAX_DELAY) == pdPASS)
        {
            printf("Consumer received: %d\n", receivedValue);
        }
        vTaskDelay(CONSUMER_DELAY);
    }
}

int main(void)
{
    // Create the queue
    xQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE);
    if (xQueue == NULL)
    {
        printf("Queue creation failed!\n");
        while (1)
            ;
    }

    // Create tasks
    xTaskCreate(vProducerTask, "Producer", 1000, NULL, 1, NULL);
    xTaskCreate(vConsumerTask, "Consumer", 1000, NULL, 1, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    // Should never reach here
    while (1)
        ;

    }
