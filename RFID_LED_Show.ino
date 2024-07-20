#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// LEDS
const int ledPins[] = {2, 3, 4, 5, 6};
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

// Buzzer
const int buzzerPin = 7;

// RFID Card UIDS
byte redCardUID[] = {0x23, 0xD0, 0x72, 0xF5}; // Qırmızı LED UID
byte greenCardUID[] = {0xA3, 0x1D, 0xAC, 0xFD}; // Yaşıl LED UID

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();


  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  if (checkUID(rfid.uid.uidByte, rfid.uid.size, redCardUID, sizeof(redCardUID))) {
    redCardAction();
  } else if (checkUID(rfid.uid.uidByte, rfid.uid.size, greenCardUID, sizeof(greenCardUID))) {
    greenCardAction();
  } else {
    unknownCardAction();
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

bool checkUID(byte *uid, byte uidSize, byte *targetUID, byte targetUIDSize) {
  if (uidSize != targetUIDSize) {
    return false;
  }
  for (byte i = 0; i < uidSize; i++) {
    if (uid[i] != targetUID[i]) {
      return false;
    }
  }
  return true;
}

void redCardAction() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  playSound();
}

void greenCardAction() {
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  playSound();
}

void unknownCardAction() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
}

void playSound() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
