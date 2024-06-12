/*
    Project name : Turbidity sensor Particle Sensor
    Modified Date: 12-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-turbidity-sensor-particle-sensor
*/

// Turbidity Sensor (Particle Sensor)
const int turbidityPin = A0; // Analog pin connected to the turbidity sensor

// Function to convert analog reading to turbidity value in PPM
float convertToTurbidity(int analogValue) {
  // Calibrate this function based on the characteristics of your turbidity sensor
  // Example calibration: 1 PPM per 10 analog units
  return analogValue / 10.0; // Adjust the divisor based on your sensor's calibration
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set turbidity pin as input
  pinMode(turbidityPin, INPUT);
}

void loop() {
  // Read the analog value from the turbidity sensor
  int turbidityValue = analogRead(turbidityPin);

  // Convert analog value to turbidity value in PPM
  float turbidityPPM = convertToTurbidity(turbidityValue);

  // Print the turbidity value to the Serial Monitor
  Serial.print("Turbidity Value (Analog): ");
  Serial.println(turbidityValue);
  Serial.print("Turbidity Value (PPM): ");
  Serial.println(turbidityPPM);

  // Delay for a short interval
  delay(1000); // Adjust delay as needed
}
