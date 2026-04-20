// 5-Channel IR sensor reader (prints only on change)

const uint8_t IR_PINS[5] = {2, 3, 4, 5, 6};
const bool ACTIVE_LOW = true;   // set false if your board is active HIGH

uint8_t lastMask = 255;         // impossible initial value so it prints first read

uint8_t readMask() {
  uint8_t mask = 0;
  for (int i = 0; i < 5; i++) {
    int raw = digitalRead(IR_PINS[i]);                 // 0/1
    int detected = ACTIVE_LOW ? (raw == LOW) : (raw == HIGH); // 0/1
    if (detected) mask |= (1 << i);                    // bit i = sensor i
  }
  return mask;
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) pinMode(IR_PINS[i], INPUT);

  Serial.println("IR reader: will print only when reading changes.");
}

void loop() {
  uint8_t mask = readMask();

  if (mask != lastMask) {
    lastMask = mask;

    // Print a single line when it changes 
    Serial.print("Detected mask (bits S0..S4) = ");
    for (int i = 0; i < 5; i++) {
      Serial.print((mask >> i) & 1);
    }
    Serial.println();
  }

  delay(20); // small debounce / stability delay
}


