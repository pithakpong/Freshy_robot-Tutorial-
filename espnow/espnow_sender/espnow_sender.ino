//0C:B8:15:D8:86:B4 receiver
//B0:A7:32:29:AC:B0 transmiter

#include <WiFi.h>
#include <esp_now.h>

// Replace with the MAC address of your receiver ESP32
uint8_t receiverAddress[] = {0x0C, 0xB8, 0x15, 0xD8, 0x86, 0xB4};

typedef struct package_send {
  bool buttonState;
} package_send;

package_send senderData;
esp_now_peer_info_t peerInfo;

void setup() {
  Serial.begin(115200);

  // Set your ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register peer
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Simulate a button state (true or false)
  senderData.buttonState = digitalRead(15); // Replace BUTTON_PIN with your button pin

  // Send the button state to the receiver
  esp_err_t result = esp_now_send(receiverAddress, (uint8_t*)&senderData, sizeof(senderData));
  if (result == ESP_OK) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Error sending data");
  }
  // You can add a delay here if needed to control the sending rate
  delay(10); // Send data every 0.01 second
}
