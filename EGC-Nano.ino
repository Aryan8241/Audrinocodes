// ECG Monitoring with AD8232 + Arduino Nano
// View the signal using Arduino IDE: Tools -> Serial Plotter

// Pin definitions
const int ECG_PIN  = A0;   // AD8232 OUTPUT pin
const int LO_PLUS  = 10;   // AD8232 LO+ pin
const int LO_MINUS = 11;   // AD8232 LO- pin

void setup() {
  // Start serial communication for Arduino Nano
  Serial.begin(9600);

  // Configure pins
  pinMode(ECG_PIN, INPUT);
  pinMode(LO_PLUS, INPUT);
  pinMode(LO_MINUS, INPUT);

  // Setup delay
  delay(2000);

  Serial.println("AD8232 ECG Monitor Started (Arduino Nano)");
  Serial.println("Connect electrodes and open Serial Plotter at 9600 baud.");
}

void loop() {
  int ecgValue = analogRead(ECG_PIN);  // Read ECG signal

  // Lead-off detection
  int loPlusState  = digitalRead(LO_PLUS);
  int loMinusState = digitalRead(LO_MINUS);

  if (loPlusState == 1 || loMinusState == 1) {
    Serial.println(0);      // Flat line if leads are disconnected
  } else {
    Serial.println(ecgValue);
  }

  delay(4);  // ~250 samples per second
}
