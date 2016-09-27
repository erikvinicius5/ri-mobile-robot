// Type definitions
typedef struct {
 byte pin1;
 byte pin2;
} Tire;


// Function definitions
void setTireSpin(Tire tire, int direction);


// Global variables
Tire tire = { 2, 7 };
int MAX_SPEED = 1;
int pSpeed = 3;


// Auxiliary functions
void setTireSpin(Tire tire, int direction) {
  digitalWrite(tire.pin1, direction > 0);
  digitalWrite(tire.pin2, (direction * -1)  > 0);
}


// Main Code
void setup() {
  pinMode(pSpeed, OUTPUT);
  pinMode(tire.pin1, OUTPUT);
  pinMode(tire.pin2, OUTPUT);

  analogWrite(pSpeed, MAX_SPEED);
}

void loop() {
  delay(1000);
  setTireSpin(tire, -1);
  delay(1000);
  setTireSpin(tire, 0);
  delay(1000);
  setTireSpin(tire, 1);
  delay(1000);
  setTireSpin(tire, 0);
}
