/*
 * @Author: 金宣妤 2324935200@qq.com
 * @Date: 2025-05-06 12:46:54
 * @LastEditors: 金宣妤 2324935200@qq.com
 * @LastEditTime: 2025-05-10 21:56:29
 * @FilePath: \seriald:\project-ESP32\oled_image\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <pgmspace.h>
#include "image_data.h"

#define SCREEN_WIDTH      128   
#define SCREEN_HEIGHT     64    
#define OLED_RESET        -1    
#define SCREEN_ADDRESS    0x3C  

Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ; // 等待串口连接
    }
    Serial.println("Setup: Initializing OLED");

    OLED.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    OLED.clearDisplay();
    OLED.drawBitmap(0, 0, bear2, 128, 64, SSD1306_WHITE);
    OLED.display();
    Serial.println("Setup: bear1 displayed, delaying 2s");
    delay(2000); // Display for 2 second
    Serial.println("Setup: Finished");
}

void loop() {
    Serial.println("Loop: Drawing bear3");
    OLED.clearDisplay();
    OLED.drawBitmap(0, 0, bear3, 128, 64, SSD1306_WHITE);
    OLED.display();
    Serial.println("Loop: bear3 displayed, delaying 1s");
    delay(500); // Display for 1 second

    Serial.println("Loop: Drawing bear2");
    OLED.clearDisplay();
    OLED.drawBitmap(0, 0, bear2, 128, 64, SSD1306_WHITE);
    OLED.display();
    Serial.println("Loop: bear2 displayed, delaying 1s");
    delay(500); // Display for 1 second

    Serial.println("Loop: Drawing bear1 (from loop)");
    OLED.clearDisplay();
    OLED.drawBitmap(0, 0, bear1, 128, 64, SSD1306_WHITE);
    OLED.display();
    Serial.println("Loop: bear1 (from loop) displayed, delaying 2s");
    delay(500); // Display for 2 second
    
}