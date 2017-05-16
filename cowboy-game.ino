/**************************************************************
cowboy-game.ino
BlackBug Engineering
16.01.2017
https://github.com/dbprof/cowboy-game
***************************************************************/

#include <LiquidCrystal.h>

#define DIODE_DROP 0.7

#define BUZZER_PIN 12
#define PLAYER_COUNT 2

int buttonPins[PLAYER_COUNT]={3,13};
int ledPins[PLAYER_COUNT]={9,11};
int score[PLAYER_COUNT]={0,0};
unsigned long previousMillis;
unsigned long currentMillis;
long interval;


LiquidCrystal lcd(10,8,6,5,4,2);

void setup() {
  previousMillis = 0;
  interval = random(5000,10000);

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("GREEN :0");
  lcd.setCursor(0,1);
  lcd.print("YELLOW:0");
  
  pinMode(BUZZER_PIN,OUTPUT);
  for (int player=0;player<PLAYER_COUNT;++player){
    pinMode(ledPins[player],OUTPUT);
    pinMode(buttonPins[player],INPUT_PULLUP);  
  }
}

void loop() {
  for (int player=0;;player=(player+1)%PLAYER_COUNT){

    currentMillis = millis();
    
    if(!digitalRead(buttonPins[player])){
      digitalWrite(ledPins[player],HIGH);
      --score[player];
      tone(BUZZER_PIN,100,500);
      delay(1000);
      digitalWrite(ledPins[player],LOW);
      lcd.setCursor(7,player);
      lcd.print("        ");
      lcd.setCursor(7,player);
      lcd.print(score[player]);
    }  
    //если не нажата, то продолжаем отсчитывать секунды
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      break;
    }
  }
  
  tone(BUZZER_PIN,3000,250);

  for (int player=0;;player=(player+1)%PLAYER_COUNT){
    if(!digitalRead(buttonPins[player])){
      digitalWrite(ledPins[player],HIGH);
      ++score[player];
      tone(BUZZER_PIN,4000,1000);
      delay(1000);
      digitalWrite(ledPins[player],LOW);
      lcd.setCursor(7,player);
      lcd.print("        ");
      lcd.setCursor(7,player);
      lcd.print(score[player]);
      if(score[player]==3){
        lcd.setCursor(7,player);
        lcd.print("WINNER");

        tone(BUZZER_PIN, 392, 350);
        delay(350);
        tone(BUZZER_PIN, 392, 350);
        delay(350);
        tone(BUZZER_PIN, 392, 350);
        delay(350);
        tone(BUZZER_PIN, 311, 250);
        delay(250);
        tone(BUZZER_PIN, 466, 100);
        delay(100);
        tone(BUZZER_PIN, 392, 350);
        delay(350);
        tone(BUZZER_PIN, 311, 250);
        delay(250);
        tone(BUZZER_PIN, 466, 100);
        delay(100);
        tone(BUZZER_PIN, 392, 700);
        delay(700);

        tone(BUZZER_PIN, 587, 350);
        delay(350);
        tone(BUZZER_PIN, 587, 350);
        delay(350);
        tone(BUZZER_PIN, 587, 350);
        delay(350);
        tone(BUZZER_PIN, 622, 250);
        delay(250);
        tone(BUZZER_PIN, 466, 100);
        delay(100);
        tone(BUZZER_PIN, 369, 350);
        delay(350);
        tone(BUZZER_PIN, 311, 250);
        delay(250);
        tone(BUZZER_PIN, 466, 100);
        delay(100);
        tone(BUZZER_PIN, 392, 700);
        delay(700);

        tone(BUZZER_PIN, 784, 350);
        delay(350);
        tone(BUZZER_PIN, 392, 250);
        delay(250);
        tone(BUZZER_PIN, 392, 100);
        delay(100);
        tone(BUZZER_PIN, 784, 350);
        delay(350);
        tone(BUZZER_PIN, 739, 250);
        delay(250);
        tone(BUZZER_PIN, 698, 100);
        delay(100);
        tone(BUZZER_PIN, 659, 100);
        delay(100);
        tone(BUZZER_PIN, 622, 100);
        delay(100);
        tone(BUZZER_PIN, 659, 450);
        delay(450);

        tone(BUZZER_PIN, 415, 150);
        delay(150);
        tone(BUZZER_PIN, 554, 350);
        delay(350);
        tone(BUZZER_PIN, 523, 250);
        delay(250);
        tone(BUZZER_PIN, 493, 100);
        delay(100);
        tone(BUZZER_PIN, 466, 100);
        delay(100);
        tone(BUZZER_PIN, 440, 100);
        delay(100);
        tone(BUZZER_PIN, 466, 450);
        delay(450);

        tone(BUZZER_PIN, 311, 150);
        delay(150);
        tone(BUZZER_PIN, 369, 350);
        delay(350);
        tone(BUZZER_PIN, 311, 250);
        delay(250);
        tone(BUZZER_PIN, 466, 100);
        delay(100);
        tone(BUZZER_PIN, 392, 750);
        delay(750);
        delay(5000);
      }
      
      break;
    }  
  }
}
