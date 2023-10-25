
#define WhitePin2 2
#define WhitePin3 3
#define RedPin1 4
#define RedPin2 0


int brightness = 0;
int fadeAmount = 5;

unsigned long OldWhiteTime = 0;
unsigned long OldRedTime = 0;

const long WhiteTimer = 100;
const long RedTimer = 300;
const long GlowTimer = 500;

bool RedState = false;
bool WhiteState = false;

void setup() {
  pinMode(WhitePin2, OUTPUT);
  pinMode(WhitePin3, OUTPUT);
  pinMode(RedPin1, OUTPUT);
  pinMode(RedPin2, OUTPUT);

  analogWrite(RedPin1, 255);
  analogWrite(RedPin2, 255);

  digitalWrite(WhitePin2, HIGH);
  digitalWrite(WhitePin3, HIGH);

  delay(500);
  digitalWrite(WhitePin2, LOW);
  delay(500);
  digitalWrite(WhitePin3, LOW);
  delay(500);
  analogWrite(RedPin1, 0);
  analogWrite(RedPin2, 0);

}

void loop() {
  unsigned long WhiteTime = millis();
  unsigned long RedTime = millis();

  if (WhiteTime - OldWhiteTime >= WhiteTimer) {
    OldWhiteTime = WhiteTime;

    if (WhiteState == false) {
      WhiteState = true;
      if (RedState == true) {
        WhiteState = false;
      }
    } else {
      WhiteState = false;
    }
    digitalWrite(WhitePin2, WhiteState);
    digitalWrite(WhitePin3, WhiteState);
  }

  if (RedTime - OldRedTime >= RedTimer) {
    OldRedTime = RedTime;

    analogWrite(RedPin1, brightness);
    analogWrite(RedPin2, brightness);

    RedState = true;
    WhiteState = false;
    brightness = brightness + fadeAmount;

    if (brightness <= 0 && brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
  } else {
    RedState = false;

    analogWrite(RedPin1, 0);
    analogWrite(RedPin2, 0);
  }
}
