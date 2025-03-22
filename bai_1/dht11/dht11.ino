#include <Adafruit_Sensor.h>
#include <DHT.h>

// Chọn chân kết nối với cảm biến
#define DHTPIN 4 // Chân GPIO4 trên ESP32

// Chọn loại cảm biến DHT (DHT11 hoặc DHT22)
#define DHTTYPE DHT11  

// Khởi tạo đối tượng DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    Serial.println("Khởi động cảm biến DHT11...");
    dht.begin();
}

void loop() {
    // Đọc nhiệt độ và độ ẩm từ DHT11
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Kiểm tra lỗi đọc dữ liệu
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Lỗi! Không đọc được dữ liệu từ cảm biến DHT11.");
        return;
    }

    // In kết quả lên Serial Monitor
    Serial.print("Nhiệt độ: ");
    Serial.print(temperature);
    Serial.print("°C, Độ ẩm: ");
    Serial.print(humidity);
    Serial.println("%");

    delay(2000); // Chờ 2 giây trước khi đọc lại
}
