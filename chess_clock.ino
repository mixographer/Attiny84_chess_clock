#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/power.h>


//standard ascii 5x5 font
static unsigned char Font5x5[] PROGMEM = {
  0x00, 0x20, 0x40, 0x60, 0x80,
  0x04, 0x24, 0x44, 0x60, 0x84,
  0x0A, 0x2A, 0x40, 0x60, 0x80,
  0x0A, 0x3F, 0x4A, 0x7F, 0x8A,
  0x0F, 0x34, 0x4E, 0x65, 0x9E,
  0x19, 0x3A, 0x44, 0x6B, 0x93,
  0x08, 0x34, 0x4D, 0x72, 0x8D,
  0x04, 0x24, 0x40, 0x60, 0x80,
  0x02, 0x24, 0x44, 0x64, 0x82,
  0x08, 0x24, 0x44, 0x64, 0x88,
  0x15, 0x2E, 0x5F, 0x6E, 0x95,
  0x04, 0x24, 0x5F, 0x64, 0x84,
  0x00, 0x20, 0x40, 0x64, 0x84,
  0x00, 0x20, 0x4E, 0x60, 0x80,
  0x00, 0x20, 0x40, 0x60, 0x84,
  0x01, 0x22, 0x44, 0x68, 0x90,
  0x0E, 0x33, 0x55, 0x79, 0x8E,
  0x04, 0x2C, 0x44, 0x64, 0x8E,
  0x1E, 0x21, 0x46, 0x68, 0x9F,
  0x1E, 0x21, 0x4E, 0x61, 0x9E,
  0x06, 0x2A, 0x5F, 0x62, 0x82,
  0x1F, 0x30, 0x5E, 0x61, 0x9E,
  0x06, 0x28, 0x5E, 0x71, 0x8E,
  0x1F, 0x22, 0x44, 0x68, 0x88,
  0x0E, 0x31, 0x4E, 0x71, 0x8E,
  0x0E, 0x31, 0x4F, 0x62, 0x8C,
  0x00, 0x24, 0x40, 0x64, 0x80,
  0x00, 0x24, 0x40, 0x6C, 0x80,
  0x02, 0x24, 0x48, 0x64, 0x82,
  0x00, 0x3F, 0x40, 0x7F, 0x80,
  0x08, 0x24, 0x42, 0x64, 0x88,
  0x0E, 0x31, 0x42, 0x64, 0x84,
  0x0E, 0x35, 0x57, 0x70, 0x8E,
  0x04, 0x2A, 0x5F, 0x71, 0x91,   
  0x1E, 0x29, 0x4E, 0x69, 0x9E,   
  0x0F, 0x30, 0x50, 0x70, 0x8F,   
  0x1E, 0x29, 0x49, 0x69, 0x9E,   
  0x1F, 0x30, 0x5E, 0x70, 0x9F,   
  0x1F, 0x30, 0x5E, 0x70, 0x90,   
  0x0F, 0x30, 0x53, 0x71, 0x8F,   
  0x11, 0x31, 0x5F, 0x71, 0x91,   
  0x0E, 0x24, 0x44, 0x64, 0x8E,   
  0x01, 0x21, 0x41, 0x71, 0x8E,   
  0x13, 0x34, 0x58, 0x74, 0x93,   
  0x10, 0x30, 0x50, 0x70, 0x9F,   
  0x11, 0x3B, 0x55, 0x71, 0x91,   
  0x11, 0x39, 0x55, 0x73, 0x91,   
  0x0E, 0x31, 0x51, 0x71, 0x8E,   
  0x1E, 0x31, 0x5E, 0x70, 0x90,   
  0x0C, 0x32, 0x56, 0x72, 0x8D,   
  0x1E, 0x31, 0x5E, 0x74, 0x92,   
  0x0F, 0x30, 0x4E, 0x61, 0x9E,   
  0x1F, 0x24, 0x44, 0x64, 0x84,   
  0x11, 0x31, 0x51, 0x71, 0x8E,   
  0x11, 0x31, 0x51, 0x6A, 0x84,   
  0x11, 0x31, 0x55, 0x7B, 0x91,   
  0x11, 0x2A, 0x44, 0x6A, 0x91,   
  0x11, 0x2A, 0x44, 0x64, 0x84,   
  0x1F, 0x22, 0x44, 0x68, 0x9F,   
  0x07, 0x24, 0x44, 0x64, 0x87,
  0x10, 0x28, 0x44, 0x62, 0x81, 
  0x1C, 0x24, 0x44, 0x64, 0x9C,
  0x04, 0x2A, 0x51, 0x60, 0x80,
  0x00, 0x20, 0x40, 0x60, 0x9F,
  0x0A, 0x2A, 0x40, 0x60, 0x80,
  0x00, 0x2E, 0x52, 0x72, 0x8D,   
  0x10, 0x30, 0x5E, 0x71, 0x9E,   
  0x00, 0x2F, 0x50, 0x70, 0x8F,   
  0x01, 0x21, 0x4F, 0x71, 0x8F,   
  0x00, 0x2E, 0x5F, 0x70, 0x8E,   
  0x04, 0x2A, 0x48, 0x7C, 0x88,   
  0x00, 0x2F, 0x50, 0x73, 0x8F,   
  0x10, 0x30, 0x56, 0x79, 0x91,   
  0x04, 0x20, 0x4C, 0x64, 0x8E,   
  0x00, 0x26, 0x42, 0x72, 0x8C,   
  0x10, 0x30, 0x56, 0x78, 0x96,   
  0x0C, 0x24, 0x44, 0x64, 0x8E,   
  0x00, 0x2A, 0x55, 0x71, 0x91,   
  0x00, 0x36, 0x59, 0x71, 0x91,   
  0x00, 0x2E, 0x51, 0x71, 0x8E,   
  0x00, 0x3E, 0x51, 0x7E, 0x90,   
  0x00, 0x2F, 0x51, 0x6F, 0x81,   
  0x00, 0x33, 0x54, 0x78, 0x90,   
  0x00, 0x23, 0x44, 0x62, 0x8C,   
  0x08, 0x3C, 0x48, 0x6A, 0x84,   
  0x00, 0x32, 0x52, 0x72, 0x8D,   
  0x00, 0x31, 0x51, 0x6A, 0x84,   
  0x00, 0x31, 0x55, 0x7B, 0x91,   
  0x00, 0x32, 0x4C, 0x6C, 0x92,   
  0x00, 0x31, 0x4A, 0x64, 0x98,   
  0x00, 0x3E, 0x44, 0x68, 0x9E,   
  0x06, 0x24, 0x48, 0x64, 0x86,
  0x04, 0x24, 0x44, 0x64, 0x84,
  0x0C, 0x24, 0x42, 0x64, 0x8C,
  0x00, 0x27, 0x5C, 0x60, 0x80,
};

//Display pins 
const int loadPin = 8;
const int sdataPin = 7;
const int sdclkPin = 9;
const int resetPin = 10;
const int ledPin = 3;
//Button Pins
const int button1 = 0;
const int button2 = 2;
const int button3 = 1; 

//for proto board:
//const int button2 = 1;
//const int button3 = 2; 

//Initial Times
double player1Time = 91000;
double player2Time = 91000;
long increment = 5000;
int player1Minutes = 0;
int player1Seconds = 0;
double player1LastCheck = millis();
int player2Minutes = 0;
int player2Seconds = 0;
double player2LastCheck = millis();
//Who's turn is it? 
boolean isPlayer1Turn = false;
boolean isPlayer2Turn = false;
boolean gameOver = false;
// are various modes/times set? Fischer, Bronstein etc
boolean modeSet = false;
boolean timeSet = false;
boolean incrementSet = false;
//Buttons State
boolean button1state = 0;
boolean lastButton1state = 0;
boolean button2state = 0;
boolean lastButton2state = 0;
boolean button3state = 0;
boolean lastButton3state = 0;
//Buffers to hold player times
char player1DisplayTime[6] = "";
char player2DisplayTime[6] = "";
char incrementDisplayTime[6] = "";
//store the different modes here
//mode 1 is Fischer, 2 is Sudden Death, 3 Hourglass, 
byte gameMode = 2 ;

void setup(){
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  //pins for controlling the display:
  pinMode(resetPin, OUTPUT);
  pinMode(sdataPin, OUTPUT);
  pinMode(sdclkPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(loadPin, OUTPUT);
  //reset the display
  digitalWrite(resetPin, LOW);
  delay(200);
  digitalWrite(resetPin, HIGH);
  setBrightness(4);
  displayBegin();
  delay(30);
}

//These are the functions that control the display:
void writeByte(const char a){
  digitalWrite(loadPin, LOW); 
  for (int b = 0; b <= 7; b++) {
    digitalWrite(sdataPin, bitRead(a, b));
    digitalWrite(sdclkPin, LOW);
    digitalWrite(sdclkPin, HIGH);
  }
  digitalWrite(loadPin, HIGH); 
}
  
  
void writeChar(byte c){
  int d = (c - 0x20) *5;
  for (int i = 0; i < 5; i++) {
    writeByte(pgm_read_byte(&Font5x5[d + i]));
  }
}
  
  
void displayChar(const char myChar, int myPos){
  writeByte(0xB0 + myPos);
  writeChar(myChar);
}

void setBrightness(int brightLevel){
  writeByte(0xF7 - brightLevel);
}

void powerDown(){
  writeByte(0xFF);
}

void pauseGame(){
  isPlayer1Turn = false;
  isPlayer2Turn = false;
  
}

void displayBegin()
{
  //reset the display
  writeByte(0xC0);
} // end of display functions


void setMode(){ //set the mode
    // modes: 1=Fischer....  2=guillotine... 3= hourglass
    displayChar('S', 0);
    displayChar('e', 1);
    displayChar('t', 2);
    displayChar(' ', 3);
    displayChar('M', 4);
    displayChar('o', 5);
    displayChar('d', 6);
    displayChar('e', 7);
    displayChar(':', 8);
    displayChar(' ', 9);
    delay(500);
    while(modeSet == false){
       button1state = digitalRead(button1);
       button2state = digitalRead(button2);
       button3state = digitalRead(button3);
         if (button2state != lastButton2state){
           if (button2state == LOW){
             // for sudden death, don't set gameMode
              delay(10);
              modeSet = true;
              delay(50);
           }
           delay(50);
           lastButton2state = button2state;
      
         } else if (button1state != lastButton1state){
           if (button1state == LOW){
              gameMode --; 
              if (gameMode < 1) { 
                 gameMode = 3;
              }
          }
          delay(50);
          lastButton1state = button1state;
      
         } else if (button3state != lastButton3state){
            if (button3state == LOW){
              gameMode ++; //delay 
              if (gameMode > 3 ) { 
                 gameMode = 1;
              }
         }
         delay(50);
         lastButton3state = button3state;
         
       } else {
       
       if (gameMode == 1){
              delay(10);
              displayChar('F', 0);
              displayChar('i', 1);
              displayChar('s', 2);
              displayChar('c', 3);
              displayChar('h', 4);
              displayChar('e', 5);
              displayChar('r', 6);
              displayChar(' ', 7);
              displayChar(' ', 8);
              displayChar(' ', 9);
       
       } else if (gameMode == 2){
              delay(10);
              displayChar('S', 0);
              displayChar('u', 1);
              displayChar('d', 2);
              displayChar('d', 3);
              displayChar('e', 4);
              displayChar('n', 5);
              displayChar('D', 6);
              displayChar('e', 7);
              displayChar('a', 8);
              displayChar('t', 9);
       }  else if (gameMode == 3){
              delay(10);
              displayChar('H', 0);
              displayChar('o', 1);
              displayChar('u', 2);
              displayChar('r', 3);
              displayChar('g', 4);
              displayChar('l', 5);
              displayChar('a', 6);
              displayChar('s', 7);
              displayChar('s', 8);
              displayChar(' ', 9);
     }
}
}
} // end setMode

 
 
void setTime(){
  player1Time = 120000;
  player2Time = 120000;
  displayChar('S', 0);
  displayChar('e', 1);
  displayChar('t', 2);
  displayChar(' ', 3);
  displayChar('T', 4);
  displayChar('i', 5);
  displayChar('m', 6);
  displayChar('e', 7);
  displayChar(':', 8);
  displayChar(' ', 9);
  //boolean timeSet = false;
  while(timeSet == false){
   button1state = digitalRead(button1);
   button2state = digitalRead(button2);
   button3state = digitalRead(button3);
   if (button2state != lastButton2state){
      if (button2state == LOW){
      delay(10);
      refreshClocks();
      delay(500);
      timeSet = true;
      }
      delay(250);
      lastButton2state = button2state;  
    } else if (button1state != lastButton1state){
      if (button1state == LOW){
        if (player1Time <= 60000){
          player1Time -= (player1Time/2);
          player2Time -= (player2Time/2);
          refreshClocks();
          } else {
          player1Time -= 60000;
          player2Time -= 60000;
          refreshClocks();
          }
      }
      delay(250);
      lastButton1state = button1state;
      
    } else if (button3state != lastButton3state){
      if (button3state == LOW){
      player1Time += 60000;
      player2Time += 60000;
      refreshClocks();
      }
      delay(250);
      lastButton3state = button3state;
    } else {}
  } 
} //end setTime

// for Fischer mode only
void setIncrement(){
  //player1Time = 120000;
  //player2Time = 120000;
  displayChar('S', 0);
  displayChar('e', 1);
  displayChar('t', 2);
  displayChar(' ', 3);
  displayChar('I', 4);
  displayChar('n', 5);
  displayChar('c', 6);
  displayChar('.', 7);
  displayChar(':', 8);
  displayChar(' ', 9);
 
  while(incrementSet == false){
   button1state = digitalRead(button1);
   button2state = digitalRead(button2);
   button3state = digitalRead(button3);
   if (button2state != lastButton2state){
      if (button2state == LOW){
      delay(10);
      refreshClocks();
      delay(500);
      incrementSet = true;
      }
      delay(100);
      lastButton2state = button2state;
      
    } else if (button1state != lastButton1state){
      if (button1state == LOW){
      increment -= 1000;
      }
      delay(100);
      lastButton1state = button1state;
      
    } else if (button3state != lastButton3state){
      if (button3state == LOW){
      increment += 1000;
      }
      delay(100);
      lastButton3state = button3state;
    } else {
      displayIncrement();
    }
  } 
} //end setIncrement

 
void loop(){
  if (timeSet == false){
    setTime();
  }
  if (modeSet == false){
    setMode();
  }
  
  if (gameMode == 1){
    if(incrementSet == false){
    setIncrement();
    }
  }
  
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);
  button3state = digitalRead(button3);
  if (button3state != lastButton3state){
  if (button3state == LOW) {
    startPlayer1Turn();
  }
  lastButton3state = button3state;
  }
  if (button1state != lastButton1state){
    if (button1state == LOW) {
    startPlayer2Turn();
    }
    lastButton1state = button1state;
  }
  if (button2state == LOW) {
    pauseGame();
  }
  if (isPlayer1Turn) {
    updatePlayer1Time();
  } else if (isPlayer2Turn) {
    updatePlayer2Time();
  
  } else {
  }
  updateDisplay();
} // end loop()

void updateDisplay(){;
    for(int i = 0; i < 5; i++) {
      displayChar(player1DisplayTime[i], i );
    }
    for(int i = 0; i < 5; i++){
      displayChar(player2DisplayTime[i], i+5 );
    }
    setBrightness(7);
    delay(10);
}

void updateIncrementDisplay(){
   for(int i = 0; i < 5; i++){
      displayChar(incrementDisplayTime[i], i+5 );
    }
    setBrightness(7);
    delay(10);
}
  
void displayIncrement(){
  int incrementMinutes = floor(increment / 60000);
  int incrementSeconds = floor(increment / 1000) - incrementMinutes * 60;
  sprintf(incrementDisplayTime, "%2d:%02d", incrementMinutes, incrementSeconds);
  updateIncrementDisplay();
}
  
void refreshClocks(){
  player1Minutes = floor(player1Time / 60000);
  player1Seconds = floor(player1Time / 1000) - player1Minutes * 60;
  sprintf(player1DisplayTime, "%2d:%02d", player1Minutes, player1Seconds);
  player2Minutes = floor(player2Time / 60000);
  player2Seconds = floor(player2Time / 1000) - player2Minutes * 60;
  sprintf(player2DisplayTime, "%2d:%02d", player2Minutes, player2Seconds);
  updateDisplay();
}
  
    
void updatePlayer1Time(){
  player1Time -= ((millis() - player1LastCheck));
  // for hourglass, could I add to player2Time as I subtract it here? 
  if (gameMode == 3){
     player2Time += ((millis() - player1LastCheck));
  }
  player1LastCheck = millis();
  if (player1Time <= 0) {
    gameOver = true;
    flagPlayer(1);
    return;
  }
  
  refreshClocks();
}
  

void flagPlayer(int playerNumber){
  digitalWrite(3, HIGH);
  isPlayer1Turn = false;
  isPlayer2Turn = false;
    if (playerNumber == 1){
      displayChar('F', 0);
      displayChar('L', 1);
      displayChar('A', 2);
      displayChar('G', 3);
      displayChar(' ', 4);
    }else{
      displayChar(' ', 5);
      displayChar('F', 6);
      displayChar('L', 7);
      displayChar('A', 8);
      displayChar('G', 9);
    }
    delay(15000);
    powerDown();
    digitalWrite(3, LOW);
    //write everything low, we're going to sleep:
    //This got it to uA levels.
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    digitalWrite(button1, LOW);
    digitalWrite(button2, LOW);
    digitalWrite(button3, LOW);
    ADCSRA = 0;
    power_all_disable();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    //delay(100);
    sleep_enable();
    sleep_cpu();
}    

void updatePlayer2Time(){
  player2Time -= ((millis() - player2LastCheck));
  // for hourglass, could I add to player1Time as I subtract it here? 
  if (gameMode == 3){
     player1Time += ((millis() - player2LastCheck));
  }
  player2LastCheck = millis();
  if (player2Time <= 0) {
    gameOver = true;
    flagPlayer(2);
    return;
  }
  refreshClocks();
  }
  
//}
   
void startPlayer1Turn () {
  if (isPlayer1Turn) {
    return;
  }
  //unsigned long startP1turn = millis();
  if (gameMode == 1){
    player1Time += increment;
  }
//  if(gameMode == 2){
//    if (millis() - startP1turn < 3000){
//      isPlayer1Turn = false;
//      isPlayer2Turn = false;
//    }
//  }
  isPlayer1Turn = true;
  isPlayer2Turn = false;
  player1LastCheck = millis();
}

void startPlayer2Turn () {
  if (isPlayer2Turn) {
    return;
  }
  //unsigned long startP2turn = millis();
  if (gameMode == 1){
    player2Time += increment;
  } 
//  if(gameMode == 2){
//    if (millis() - startP2turn < 3000){
//      isPlayer1Turn = false;
//      isPlayer2Turn = false;
//    }
//  }
  isPlayer2Turn = true;
  isPlayer1Turn = false;
  player2LastCheck = millis();
}

