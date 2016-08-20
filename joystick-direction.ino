#define Up 2
#define Down 3
#define Right 4
#define Left 5

#define PIN_JOYSTICK_X 0
#define PIN_JOYSTICK_Y 1

int CO1,CO2,CO3,CO4,lastcode;
void setup() {
  setup_begin();
  setup_joystick();
  Serial.println("Debug: ");
}

void loop() {
  displayDebug(joystickUpdate());
}

void setup_begin(){
  Serial.begin(9600);
}

void setup_joystick(){
  Serial.println("Deplacez vers la GAUCHE");

  while(true){
    int x = analogRead(PIN_JOYSTICK_X);
    int y = analogRead(PIN_JOYSTICK_Y);
    if (y < 50) { CO1 = Left;CO2 = Right;CO4 = Up;CO3 = Down;break;}
    if (y > 700){ CO2 = Left;CO1 = Right;CO3 = Up;CO4 = Down;break;}
    if (x < 150){ CO3 = Left;CO4 = Right;CO1 = Up;CO2 = Down;break;}
    if (x > 650){ CO4 = Left;CO3 = Right;CO2 = Up;CO1 = Down;break;}
 }
 Serial.println("Parfait !");
}
int joystickUpdate(){
  int x = analogRead(PIN_JOYSTICK_X);
  int y = analogRead(PIN_JOYSTICK_Y);
  int result = 0;

  if (y < 50) result=CO1;
  if (y > 700) result=CO2;
  if (x < 150) result=CO3;
  if (x > 650) result=CO4;

  if(result != lastcode){
    lastcode = result;
    return result;
  }else{
    return 0;
  }
  lastcode = result;
}
void displayDebug(int code) {
      switch (code) {
        case 2:
          Serial.println(">  HAUT / #2");
          break;
        case 3:
          Serial.println(">  BAS / #3");
          break;
        case 5:
          Serial.println(">  GAUCHE / #5");
          break;
        case 4:
          Serial.println(">  DROITE / #4");
          break;
        default:
          break;
      }
}

