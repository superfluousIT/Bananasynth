
// This is the code to run a bananasynth using an arduino board
//
// In essence it detects which bananas you touch and plays the corresponding note
// The arduino board is plugged into the computer and the code sends serial data
// to the computer where the signal is converted to MIDI before it is sent to the DAW
// You can find many examples of banansynth for Arduino. The difference here to most
// other you will find is that you can play multiple bananas at the same time. I also
// wanted the note to play as long as you are holding the banana and stop when you let
// go
//
// one input is used per banana. Since Arduino Uno has limited number a combination 
// of analog and digital inputs where used. It requires slightly different 
// circuitry and code. 
//
// The following software was used to create a standalone solution
// Hairless MIDI to convert seriel to MIDI 
// Cubase as DAW
// Asio4all and IPMidi to run DAW on computer speakers/headphones instead of Interface
// 

// Array to keep track of which bananas are touched
int keysPressed[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

byte noteOn = 144;
const int pressed = 1;
const int notPressed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
}

void loop() { 


  // The logic in each of these if/else clauses is the same
  // If you are already touching the banana and keep on touching it do nothing
  // If you are touching the banana start playing the note
  // If note is playing but you no longer touching the banana turn it off
  
  // Setting up some bass bananas. These run an octave when pressed
  // LOW D
  if(analogRead(A5) < 950 && keysPressed[0] == pressed){}
  else if (analogRead(A5) < 950 && keysPressed[0] == notPressed) {
    MIDIMessage(noteOn, 50,100);
    MIDIMessage(noteOn, 38,100);
    keysPressed[0] = pressed;
  }
  else if(keysPressed[0] == pressed) {
    keysPressed[0] = notPressed;
    MIDIMessage(noteOn, 50, 0);
    MIDIMessage(noteOn, 38,0);
  }  

  // LOW G
  if(analogRead(A4) < 950 && keysPressed[1] == pressed){}
  else if (analogRead(A4) < 950 && keysPressed[1] == notPressed) {
    MIDIMessage(noteOn, 55,100);
    MIDIMessage(noteOn, 43,100);
    keysPressed[1] = pressed;
  }
  else if(keysPressed[1] == pressed) {
    keysPressed[1] = notPressed;
    MIDIMessage(noteOn, 55, 0);
    MIDIMessage(noteOn, 43, 0);
  }  

  // LOW Bb
  if(analogRead(A3) < 950 && keysPressed[2] == pressed){}
  else if (analogRead(A3) < 950 && keysPressed[2] == notPressed) {
    MIDIMessage(noteOn, 58,100);
    keysPressed[2] = pressed;
  }
  else if(keysPressed[2] == pressed) {
    keysPressed[2] = notPressed;
    MIDIMessage(noteOn, 58, 0);
  }  

  // C
  if(analogRead(A2) < 950 && keysPressed[3] == pressed){}
  else if (analogRead(A2) < 950 && keysPressed[3] == notPressed) {
    MIDIMessage(noteOn, 60,100);
    keysPressed[3] = pressed;
  }
  else if(keysPressed[3] == pressed) {
    keysPressed[3] = notPressed;
    MIDIMessage(noteOn, 60, 0);
  }  

  // D
  if(analogRead(A1) < 950 && keysPressed[4] == pressed){}
  else if (analogRead(A1) < 950 && keysPressed[4] == notPressed) {
    MIDIMessage(noteOn, 62,100);
    keysPressed[4] = pressed;
  }
  else if(keysPressed[4] == pressed) {
    keysPressed[4] = notPressed;
    MIDIMessage(noteOn, 62, 0);
  }  

  // E
  if(analogRead(A0) < 950 && keysPressed[5] == pressed){}
  else if (analogRead(A0) < 950 && keysPressed[5] == notPressed) {
    MIDIMessage(noteOn, 64,100);
    keysPressed[5] = pressed;
  }
  else if(keysPressed[5] == pressed) {
    keysPressed[5] = notPressed;
    MIDIMessage(noteOn, 64, 0);
  }  

  // F
  if(digitalRead(7)== LOW && keysPressed[7] == pressed){}
  else if (digitalRead(7) == LOW && keysPressed[7] == notPressed) {
    MIDIMessage(noteOn, 65,100);
    keysPressed[7] = pressed;
  }
  else if(keysPressed[7] == pressed) {
    keysPressed[7] = notPressed;
    MIDIMessage(noteOn, 65, 0);
  }  

  // G
  if(digitalRead(8)== LOW && keysPressed[8] == pressed){}
  else if (digitalRead(8) == LOW && keysPressed[8] == notPressed) {
    MIDIMessage(noteOn, 67,100);
    keysPressed[8] = pressed;
  }
  else if(keysPressed[8] == pressed) {
    keysPressed[8] = notPressed;
    MIDIMessage(noteOn, 67, 0);
  }  

  // A
  if(digitalRead(9)== LOW && keysPressed[9] == pressed){}
  else if (digitalRead(9) == LOW && keysPressed[9] == notPressed) {
    MIDIMessage(noteOn, 69,100);
    keysPressed[9] = pressed;
  }
  else if(keysPressed[9] == pressed) {
    keysPressed[9] = notPressed;
    MIDIMessage(noteOn, 69, 0);
  }  

  // Bb
  if(digitalRead(10)== LOW && keysPressed[10] == pressed){}
  else if (digitalRead(10) == LOW && keysPressed[10] == notPressed) {
    MIDIMessage(noteOn, 70,100);
    keysPressed[10] = pressed;
  }
  else if(keysPressed[10] == pressed) {
    keysPressed[10] = notPressed;
    MIDIMessage(noteOn, 70, 0);
  }  



  // B
  if(digitalRead(11)== LOW && keysPressed[11] == pressed){}
  else if (digitalRead(11) == LOW && keysPressed[11] == notPressed) {
    MIDIMessage(noteOn, 71,100);
    keysPressed[11] = pressed;
  }
  else if(keysPressed[11] == pressed) {
    keysPressed[11] = notPressed;
    MIDIMessage(noteOn, 71, 0);
  }  

   // High C
  if(digitalRead(12)== LOW && keysPressed[12] == pressed){}
  else if (digitalRead(12) == LOW && keysPressed[12] == notPressed) {
    MIDIMessage(noteOn, 72,100);
    keysPressed[12] = pressed;
  }
  else if(keysPressed[12] == pressed) {
    keysPressed[12] = notPressed;
    MIDIMessage(noteOn, 72, 0);
  }  

  // High D
  if(digitalRead(13)== LOW && keysPressed[13] == pressed){}
  else if (digitalRead(13) == LOW && keysPressed[13] == notPressed) {
    MIDIMessage(noteOn, 74,100);
    keysPressed[13] = pressed;
  }
  else if(keysPressed[13] == pressed) {
    keysPressed[13] = notPressed;
    MIDIMessage(noteOn, 74, 0);
  }  
}

// A function to send a serial message to the MIDI converter
void MIDIMessage(int command, int data1, int data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
  
}
