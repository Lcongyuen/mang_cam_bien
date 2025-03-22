#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22); // GPIO21 (SDA), GPIO22 (SCL)
    
    if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("BH1750 khởi động thành công!");
    } else {
        Serial.println("Lỗi! Không tìm thấy cảm biến BH1750.");
        while (1);
    }
}

void loop() {
    float lux = lightMeter.readLightLevel();
    Serial.print("Cường độ ánh sáng: ");
    Serial.print(lux);
    Serial.println(" lx");

    delay(1000);
}
