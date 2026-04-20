#include "pitches.h"

#define BUZZER_PIN 3

// Coconut Mall - Mario Kart Wii
// Key: F Major | Tempo: ~132 BPM | Time: 4/4
// Chord loop: Gm7 | C7 | F6 | Dm7

int melody[] = {
  NOTE_D4, NOTE_DS4, NOTE_E4, REST, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  REST, NOTE_C4,
  NOTE_D4, NOTE_DS4, NOTE_E4, REST, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_C5, NOTE_F5, NOTE_D5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  REST, NOTE_C4, NOTE_CS4,
  NOTE_D4, NOTE_DS4, NOTE_E4, REST, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_C5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_A4, NOTE_F4, NOTE_D4, NOTE_E4, REST, NOTE_F4
};

int durations[] = {
  4, 4, 4, 8, 4, 4, 8, 4, 
  4, 4, 4, 4, 4, 8, 8, 8, 4,
  16, 4,
  4, 4, 4, 8, 4, 4, 8, 4,
  4, 4, 4, 8, 8, 8, 4,
  4, 8, 8,
  4, 4, 4, 8, 4, 4, 8, 4, 
  4, 4, 4, 4, 4, 8, 8, 8, 4,
  4, 4, 4, 4, 4, 8, 8, 8, 4, 4,
  4, 4, 8, 4, 16, 4
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    int pauseBetweenNotes = duration * 1;
    delay(pauseBetweenNotes);

    noTone(BUZZER_PIN);
  }

  delay(500); // pause before looping
}