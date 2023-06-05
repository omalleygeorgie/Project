int buzz = D6;
int sensorPin = D5;

void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(sensorPin, INPUT_PULLUP);
  Particle.subscribe("send_notification", handleWebhook);
}

void loop() {
  int barkCount = 0;
  
  for (int i = 0; i < 50; i++) {
    if (digitalRead(sensorPin) == LOW) {
      barkCount += 1;
    }
    delay(10);
  }
  
  if (barkCount >= 5) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
      delay(500);
    }
    
    Particle.publish("send_notification");
  }
}

void handleWebhook(const char* event, const char* data) {
}
