#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);          // Start Serial for Serial Monitor
  lcd.begin(16, 2);
  dht.begin();

  lcd.print("DHT11 Starting...");
  Serial.println("DHT11 Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensor values
  float humidity = dht.readHumidity();
  float tempC    = dht.readTemperature();
  float tempF    = dht.readTemperature(true);

  // Check for failed readings
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    lcd.clear();
    lcd.print("Read Error");
    Serial.println("Error: Failed to read from DHT11 sensor");
    delay(2000);
    return;
  }

  // ---- LCD output ----
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C  ");            // extra spaces to clear leftovers

  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humidity);
  lcd.print("%   ");           // extra spaces

  // ---- Serial Monitor output ----
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  |  ");

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" °C  /  ");
  Serial.print(tempF);
  Serial.println(" °F");

  delay(2000);  // Read every 2 seconds
}
