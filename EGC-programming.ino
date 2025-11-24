// ECG Monitoring with AD8232 + Arduino
// View the signal using Arduino IDE: Tools -> Serial Plotter

// Pin definitions (adjust if wired differently)
const int ECG_PIN  = A0;   // AD8232 OUTPUT pin
const int LO_PLUS  = 10;   // AD8232 LO+ pin
const int LO_MINUS = 11;   // AD8232 LO- pin

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Configure pins
  pinMode(ECG_PIN, INPUT);
  pinMode(LO_PLUS, INPUT);
  pinMode(LO_MINUS, INPUT);

  // Optional: small delay for sensor to stabilize
  delay(2000);

  Serial.println("AD8232 ECG Monitor Started");
  Serial.println("Connect electrodes and open Serial Plotter.");
  Serial.println("Plotting raw ECG values...");
}

void loop() {
  int ecgValue = analogRead(ECG_PIN);  // Read analog from AD8232

  // Check for lead-off (no proper contact)
  int loPlusState  = digitalRead(LO_PLUS);
  int loMinusState = digitalRead(LO_MINUS);

  // If leads off, you can print a constant value or message
  if (loPlusState == 1 || loMinusState == 1) {
    // In Serial Plotter, just show a flat line when leads are off
    Serial.println(0);
  } else {
    // Print ECG value for plotting
    // Serial Plotter expects a single number per line for a simple graph
    Serial.println(ecgValue);
  }

  // Sampling delay:
  // Lower delay = higher sampling rate (smoother wave, more data)
  delay(4);  // ~250 samples per second with typical Arduinos
}
