// defines pins numbers
const int LtrigPin = 7;
const int LechoPin = 8;

const int RtrigPin = 2 ;
const int RechoPin = 4;

// defines variables
long Lduration;
int Ldistance;
long Rduration;
int Rdistance;

void setup() {
  pinMode(LtrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(LechoPin, INPUT); // Sets the echoPin as an Input
  pinMode(RtrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(RechoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(LtrigPin, LOW);
  digitalWrite(RtrigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(LtrigPin, HIGH);
  digitalWrite(RtrigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(LtrigPin, LOW);
  digitalWrite(RtrigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  Lduration = pulseIn(LechoPin, HIGH);
  Rduration = pulseIn(RechoPin, HIGH);
  // Calculating the distance
  Ldistance = Lduration * 0.034 / 2;
  Rdistance = Rduration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Left Distance: ");
  Serial.println(Ldistance);

  Serial.print("Right Distance: ");
  Serial.println(Rdistance);
}
