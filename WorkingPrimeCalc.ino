//Arduino project. 
//Arduino Mega, lcd screen, 10k potentiometer, button. 

//Prints a prime number on the second line and moves to the next prime number with each press of the button

#include <LiquidCrystal.h>

const int d4 = 2, d5 = 4, d6 = 6, d7 = 8, rs = 12, en = 10;
const int buttonPin = 24;
int num = 1, buttonState = 0;
char findNext = 'y';
bool notPrime;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); 
  lcd.print("Push for prime."); //remains on top screen for full duration of run time. 
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  while ( findNext == 'y' ) {   // findNext will be set to n at the end of the loop, it will be reset to 'y' when the button is pressed
    notPrime = PrimeCheck(num); //primecheck function defined below

    if ( notPrime != true ) {
      lcd.setCursor(0, 1);
      lcd.print(num);
      num++;
      findNext = 'n';
      delay(1000);  // without this delay the number counts up really fast, i'm guessing its running 1
    }               // 1000s of times a second so the button push is registering a lot of presses
    else {
      num++;
    }
  }

  if (buttonState == LOW) {
    findNext = 'y';
  }
}

bool PrimeCheck(int n) {      // this will return the value true if a number is not prime. 
  bool flag = false;

  for (int i = 2; i <= n / 2; i++ ) {
    if ( n % i == 0 ) {
      flag = true;
      break;
    }
  }
  return flag;
}
