#include <LiquidCrystal.h>

const int d4 = 2, d5 = 4, d6 = 6, d7 = 8, rs = 12, en = 10;
const int buttonPin = 24;
int num = 1, buttonState = 0;
char findNext = 'y';
bool notPrime;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Push for prime.");
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  while ( findNext == 'y' ) {
    notPrime = PrimeCheck(num);

    if ( notPrime != true ) {
      lcd.setCursor(0, 1);
      lcd.print(num);
      num++;
      findNext = 'n';
      delay(1000);
    }
    else {
      num++;
    }
  }

  if (buttonState == LOW) {
    findNext = 'y';
  }
}

bool PrimeCheck(int n) {
  bool flag = false;

  for (int i = 2; i <= n / 2; i++ ) {
    if ( n % i == 0 ) {
      flag = true;
      break;
    }
  }
  return flag;
}
