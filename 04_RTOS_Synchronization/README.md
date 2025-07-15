```markdown
# 🔄 FreeRTOS Binary Semaphore Synchronization Example

## 🧠 Concept

Two tasks are created:
- **TaskA (Producer):** Gives a binary semaphore every 1 second.
- **TaskB (Consumer):** Waits for the semaphore and performs an action when it's received.

This simulates how tasks can coordinate actions using semaphores, a basic but powerful RTOS synchronization primitive.

##  📁 FreeRTOS-Binary-Semaphore-Demo
┣ 📄 main.c            # FreeRTOS application source code
┣ 📄 README.md         # This documentation


## ⚙️ Requirements

- FreeRTOS
- STM32CubeIDE / Keil / QEMU / or any FreeRTOS-supported board/simulator
- If using printf(), make sure standard I/O is available or redirect via UART

## 🚀 How to Run

1. Clone the repo:
   ```bash
    clone  this repository 
````

2. Open in STM32CubeIDE or copy into your FreeRTOS environment.

3. Build and flash (or simulate).

4. You should see:

   ```
   TaskA: Sending signal
   TaskB: Received signal! Doing work...
   ```

## 🔑 Core FreeRTOS APIs Used

* `xSemaphoreCreateBinary()`
* `xSemaphoreGive()`
* `xSemaphoreTake()`
* `vTaskDelay()`
* `vTaskStartScheduler()`

---

📌 **Note**: This is an educational example to understand task-level synchronization in RTOS. Useful in producer-consumer models, button press handling, or interrupt signaling.

---

## 📧 Author

Tharun Kumar Akula
[GitHub](https://github.com/tharunerd) | [LinkedIn](https://linkedin.com/in/akula-tharun-kumar)

```

---
