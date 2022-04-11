/*
 Name:		SignageCounter003.ino
 Created:	3/9/2022 10:44:53 AM
 Author:	Tyler Stilson tyler.stilson5@gmail.com
*/


const int recv_pin = 2;
const int trans_pin = 3;
const int led_pin = 13;

float dist_raw;
bool toggle = false;
float range = 1;
//int timer = 60000;
unsigned long timer = 60000;
unsigned long delayStart = 0;
unsigned long x;

int count;
float Xduration;
float Xdis;

int counterTimer = 0;

float PastDis;

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(9600);
	pinMode(trans_pin, OUTPUT);
	pinMode(recv_pin, INPUT);
	pinMode(led_pin, OUTPUT);

	digitalWrite(trans_pin, LOW);
	delayMicroseconds(5);

	digitalWrite(trans_pin, HIGH);
	delayMicroseconds(10);

	digitalWrite(trans_pin, LOW);
	Xduration = pulseIn(recv_pin, HIGH);

	Xdis = (Xduration * (340 * 39.37) / (2 * 1000000)) / 12;
	Serial.println("base is ");
	Serial.print(Xdis);
	Serial.println(" ft");


}

// the loop function runs over and over again until power down or reset
void loop() {

	digitalWrite(led_pin, LOW);
	float duration;

	digitalWrite(trans_pin, LOW);
	delayMicroseconds(5);

	digitalWrite(trans_pin, HIGH);
	delayMicroseconds(10);

	digitalWrite(trans_pin, LOW);
	duration = pulseIn(recv_pin, HIGH, 20000);
	

	if (duration) {
		dist_raw = (duration * (340 * 39.37) / (2 * 1000000)) / 12;
		Serial.println(dist_raw);



		if (dist_raw > (Xdis - .25)) {
			toggle = false;
			delay(100);
		}

		if (dist_raw <= (Xdis - .25) && toggle == false) {
			count += 1;
			digitalWrite(led_pin, HIGH);
			delay(100);

			toggle = true;
		}
		
	}
	else {
		Serial.println("no signal recieved");
		digitalWrite(led_pin, LOW);
		float durationy;

		digitalWrite(trans_pin, LOW);
		delayMicroseconds(5);

		digitalWrite(trans_pin, HIGH);
		delayMicroseconds(10);

		digitalWrite(trans_pin, LOW);
		durationy = pulseIn(recv_pin, HIGH, 20000);
		dist_raw = (duration * (340 * 39.37) / (2 * 1000000)) / 12;
		Serial.println(dist_raw);
	}

	

	/*if (dist_raw > (PastDis - .25) & dist_raw <(PastDis + .25)) {
		
		}
		else {
			if (dist_raw < (Xdis - .5) & dist_raw > 0) {
				count += 1;	
				PastDis = dist_raw;
			}
		}*/


	
	/*counterTimer += 1;*/

	/*if (counterTimer >= timer) {*/
	
	/*x = millis() - delayStart;
	Serial.println(delayStart);
	Serial.println(x);*/

	if ((millis() - delayStart) >= timer){
		delayStart += timer;
		
		Serial.println(count);
		// toggle = false;
		count = 0;
		/*counterTimer = 0;*/

	}
	

}
