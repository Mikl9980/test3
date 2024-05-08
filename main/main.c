#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_rom_gpio.h"
//#include "driver/uart_struct.h"
#include "C:/Users/KasimovM/esp/v5.2.1/esp-idf/components/soc/esp32s3/include/soc/uart_struct.h"

#define BLINK_GPIO 2

void app_main() {
    // Установка GPIO
    esp_rom_gpio_pad_select_gpio(BLINK_GPIO);
    // Установка GPIO на вывод
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        // Включение лампочки
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        // Выключение лампочки
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}