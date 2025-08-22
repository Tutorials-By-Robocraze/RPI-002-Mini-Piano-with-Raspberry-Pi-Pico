#define BUZZER_PIN 14

// Button pins
int buttons[] = {2, 3, 4, 5, 6, 7};
// Frequencies for notes (Hz)
int notes[] = {262, 294, 330, 349, 392, 440}; // C, D, E, F, G, A
// Note names
const char* noteNames[] = {"C", "D", "E", "F", "G", "A"};

void setup() {
  Serial.begin(115200); // Start serial communication
  pinMode(BUZZER_PIN, OUTPUT);
  for (int i = 0; i < 6; i++) {
    pinMode(buttons[i], INPUT_PULLDOWN);
  }
}

void loop() {
  for (int i = 0; i < 6; i++) {
    if (digitalRead(buttons[i]) == HIGH) {
      Serial.print("Button pressed: ");
      Serial.print(noteNames[i]);
      Serial.print("  Frequency: ");
      Serial.print(notes[i]);
      Serial.println(" Hz");

      tone(BUZZER_PIN, notes[i]);
      delay(200); // Short delay for note length
      noTone(BUZZER_PIN);
    }
  }
}
