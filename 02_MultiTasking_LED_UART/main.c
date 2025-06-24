#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

void BlinkTask(void *pvParameters) {
    while(1) {
        printf("LED ON\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
        printf("LED OFF\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void UARTTask(void *pvParameters) {
    while(1) {
        printf("Hello from UART Task\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(void) {
    xTaskCreate(BlinkTask, "Blink", 128, NULL, 2, NULL);
    xTaskCreate(UARTTask, "UART", 128, NULL, 1, NULL);
    vTaskStartScheduler();

    for(;;);
    return 0;
}
