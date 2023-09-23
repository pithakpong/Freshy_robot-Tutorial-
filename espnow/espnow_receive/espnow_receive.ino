#include <WiFi.h>
#include <esp_now.h>

// Define the structure to hold received data
typedef struct package_receive {
  bool buttonState;
} package_receive;

package_receive receiverData;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&receiverData, incomingData, sizeof(receiverData));
  Serial.print("Received button state: ");
  Serial.println(receiverData.buttonState);
}

void setup() {
  Serial.begin(115200);
  pinMode(23,OUTPUT);
  // Set your ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register callback function to handle received data
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Your receiver code can perform other tasks here
  digitalWrite(23,receiverData.buttonState);
}
