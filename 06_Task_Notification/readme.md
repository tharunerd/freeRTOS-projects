# 🌅 FreeRTOS Task Notification Example

This repository demonstrates a simple inter-task communication mechanism using **FreeRTOS Task Notifications**. It simulates two tasks in a real-time system:

### 👨‍💻 Components

- **SensorTask:** Simulates reading sensor data periodically and notifies another task when new data is available.
- **ProcessingTask:** Waits for the task notification and processes the data upon receiving it.

### 🔗 Key Concepts

- `xTaskNotifyGive()` and `ulTaskNotifyTake()` for task synchronization
- Task priorities and delay simulation using `vTaskDelay`
- Basic multitasking in FreeRTOS

### 🛠 How to Run

You can run this on:
- STM32CubeIDE (STM32F4 or STM32F1 boards)
- Any FreeRTOS simulator or QEMU environment
- Online embedded C simulators (with FreeRTOS support)

### 📂 File Structure
````
├── main.c // Core logic with SensorTask and ProcessingTask
├── FreeRTOSConfig.h // (Optional) RTOS config file if you're using your own config
├── README.md // Project overview and usage instructions
├── .gitignore // Git ignore rules (optional)
└── Makefile // Build script (if you're using CLI or simulator)
````