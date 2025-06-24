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

int main(void) {
    xTaskCreate(BlinkTask, "Blink", 128, NULL, 1, NULL);
    vTaskStartScheduler();

    // Will never reach here
    for(;;);
    return 0;
}
