/*
 * @Author: 金宣妤 2324935200@qq.com
 * @Date: 2025-05-05 15:37:16
 * @LastEditors: 金宣妤 2324935200@qq.com
 * @LastEditTime: 2025-05-05 20:59:21
 * @FilePath: \LED\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <Arduino.h>



void setup() {
  // 设定主角（程序里的变量对应硬件的引脚），引脚功能/作用（输入/输出）
for(int i = 14; i < 17; i++)
pinMode(i,OUTPUT);
}
 
void loop() {
  //来回for循环，设置好起止点
for(int i = 14; i < 17; i++ )
  {
    digitalWrite(i , HIGH);
    delay(500);
    digitalWrite(i , LOW);
  }
  for(int i = 16;i > 13;i--)
  {
    digitalWrite(i , HIGH);
    delay(500);
    digitalWrite(i , LOW);
    }
}
