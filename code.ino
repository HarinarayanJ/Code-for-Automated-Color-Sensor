#define S0 8
#define S1 7
#define S2 6
#define S3 5
#define O 4
#define SM 11
#include <Servo.h>

Servo servo;

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int r = 0;
int g = 0;
int b = 0;

int color = 0;

void setup() {

 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);

 servo.attach(SM)

 pinMode(O, INPUT);
 
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 Serial.begin(9600);
}

void loop() {
 readColor();
 Servo_Motor(r, g, b);
 delay(100);
}

// Reading color based on filter values of each output.
void readColor() {
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redFrequency = pulseIn(O, LOW);
 r = map(redFrequency, 0, 255, 255, 0);
 delay(100);

 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenFrequency = pulseIn(O, LOW);
 g = map(greenFrequency, 0, 255, 255, 0);
 delay(100);

 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueFrequency = pulseIn(O, LOW);
 b = map(blueFrequency, 0, 255, 255, 0);
 delay(100);
}

// Changing Servo Motor based on color
void Servo_Motor(r,g,b){
   if (r > 200 && g > 200 && b > 200) {
    Serial.println("Color: White");
    servo.write(0);
  } else if (r > 200 && g < 100 && b < 100) {
    Serial.println("Color: Red");
    servo.write(20);
  } else if (r > 200 && greenValue > 200 && blueValue < 100) {
    Serial.println("Color: Yellow");
    servo.write(40);
  } else if (r < 100 && greenValue > 200 && blueValue < 100) {
    Serial.println("Color: Green");
    servo.write(60);
  } else if (r < 100 && greenValue < 100 && blueValue > 200) {
    Serial.println("Color: Blue");
    servo.write(80);
  } else if (r < 100 && greenValue < 100 && blueValue < 100) {
    Serial.println("Color: Black");
    servo.write(0);
  } else {
    Serial.println("Color: Unknown");
    servo.write(0);
  }
}
