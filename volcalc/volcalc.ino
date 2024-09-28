/*#include <LiquidCrystal.h>
#include <math.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;
const int rpm = 15;

const int trigPin = 9; 
const int echoPin = 10;
float duration, distance;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Stepper horizontalScanner(stepsPerRevolution, 6, 7, 8, 13);
//String volume = String(tan(M_PI * 45/180));

void setup(){
  //Initialize stepper
  horizontalScanner.setSpeed(rpm);
  Serial.begin(9600);

  //Initialize LCD screen
  lcd.begin(16, 2);

  // Initialize ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  //Stepper movementp
  Serial.println("clockwise");
  horizontalScanner.step(stepsPerRevolution);
  delay(500);

  Serial.println("counter-clockwise");
  horizontalScanner.step(-stepsPerRevolution);
  delay(500);

  //LCD update
  lcd.setCursor(0, 1);

  //US sensor capture
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  

  //US sensor distance calculation and output
  duration = pulseIn(echoPin, HIGH);
  //cm -> meters
  distance = ((duration*.0343)/2)/100;
  lcd.print(distance);
  delay(100);
}
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 4, 5, 6, 3);

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
int fixedDistance = 30; 
int bottleDistance;
int diameter;
int radius;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.print("Measuring...");
  delay(2000);
  lcd.clear();
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  bottleDistance = duration * 0.034 / 2;

  diameter = fixedDistance - bottleDistance;
  radius = diameter / 2;

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(bottleDistance);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Diam: ");
  lcd.print(diameter);
  lcd.print(" Rad: ");
  lcd.print(radius);

  delay(100);  
}
