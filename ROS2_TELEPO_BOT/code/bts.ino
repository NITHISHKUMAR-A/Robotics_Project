// --- BTS7960 Motor Driver Test with ESP32 ---
// Motor: 12V 300 RPM Johnson motor with encoder (testing rotation)

const int R_EN = 4;    // Right enable
const int L_EN = 5;    // Left enable
const int RPWM = 14;   // Right PWM (Forward)
const int LPWM = 27;   // Left PWM (Reverse)

void setup() {
  Serial.begin(115200);

  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  // Enable both sides initially
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);

  Serial.println("BTS7960 Motor Test Started");
}

void loop() {
  // Forward
  Serial.println("Motor Forward");
  analogWrite(RPWM, 200);  // speed (0–255)
  analogWrite(LPWM, 0);
  delay(3000);

  // Stop
  Serial.println("Motor Stop");
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(2000);

  // Reverse
  Serial.println("Motor Reverse");
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 200);
  delay(3000);

  // Stop again
  Serial.println("Motor Stop");
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(2000);
}
