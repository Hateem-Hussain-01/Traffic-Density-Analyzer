
#include <Ultrasonic.h>

// Define pin numbers for sensors
const int triggerPin1 = 2;
const int echoPin1 = 3;
const int triggerPin2 = 4;
const int echoPin2 = 5;

// Initialize Ultrasonic objects
Ultrasonic sensor1(triggerPin1, echoPin1); // Sensor 1
Ultrasonic sensor2(triggerPin2, echoPin2); // Sensor 2

void setup() {
  Serial.begin(9600);  // Start serial communication
  // Initialize any other peripherals
}

void loop() {
  long distance1 = sensor1.read();  // Read distance from sensor 1
  long distance2 = sensor2.read();  // Read distance from sensor 2
  
  // Print the distances to the serial monitor
  Serial.print("Sensor 1 Distance: ");
  Serial.print(distance1);
  Serial.print(" cm, ");
  
  Serial.print("Sensor 2 Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");
  
  // Calculate traffic density and adjust signals accordingly
  adjustTrafficSignal(distance1, distance2);
  
  delay(1000);  // Wait for 1 second before next reading
}

// Function to adjust traffic signal based on the density
void adjustTrafficSignal(long distance1, long distance2) {
  // Example logic to simulate traffic signal adjustment
  if (distance1 < 10 || distance2 < 10) {
    // If vehicles are detected within 10 cm, change signal to red
    Serial.println("High traffic density detected! Red signal.");
  } else {
    // Otherwise, green signal
    Serial.println("Traffic density normal. Green signal.");
  }
}
