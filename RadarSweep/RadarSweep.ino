#include <Servo.h>

#define ECHO 		5
#define TRIG		6	
#define SERVO_MIN	0
#define SERVO_MAX	180
#define servoPin	3

Servo servo;
int servoPosition;
double distance;

void trigger();

void setup() {
	servo.attach(servoPin);
	pinMode(ECHO, INPUT);
	pinMode(TRIG, OUTPUT);
	Serial.begin(115200);
}

void loop() {
	servoPosition = SERVO_MIN;
	while(servoPosition <= SERVO_MAX){
		servo.write(servoPosition);
		trigger();
		distance = pulseIn(ECHO, HIGH, 25000)/57.753;
		Serial.print(servoPosition++);
		Serial.print(",");
		Serial.println((int)distance);
		_delay_ms(5);
		
	}
	while(servoPosition >= SERVO_MIN){
		servo.write(servoPosition);
		trigger();
		distance = pulseIn(ECHO, HIGH, 25000)/57.753;
		Serial.print(servoPosition--);
		Serial.print(",");
		Serial.println((int)distance);
		_delay_ms(5);
	}
}

void trigger(){
	digitalWrite(TRIG, HIGH);
	_delay_us(10);
	digitalWrite(TRIG, LOW);
}
