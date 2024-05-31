
const int SENSOR_INPUT_PIN=6;
const int OPTO_OUTPUT_PIN=2;
// Duration of the pulse in microseconds
unsigned long pulseDuration;
// Minmum duration of the pulse  to be taken into account
// Maximum flow should be around 1L/s, so 0,5s per pulse (half disk)
// Having the minimum pulse to 0,2s should be enough to avoid false positive
// And to be able to still read all possible values
const unsigned long minDurationMillis = 200; // 0,2s
// Time the input became LOW
unsigned long BEGINNING_STATE_LOW;
bool STATE_LOW_SENT = false;
int INPUT_LAST_STATE = LOW;

const unsigned long TIMEOUT_FOR_PULSE_INPUT = 180000000;

void setup() {
    pinMode(SENSOR_INPUT_PIN, INPUT);
    pinMode(OPTO_OUTPUT_PIN, OUTPUT);
}
 
void loop() {
  // Lecture etat capteur
  int inputCurrentState = digitalRead(SENSOR_INPUT_PIN);

  if (inputCurrentState == LOW) {
    // La capteur détecte du métal
    if (INPUT_LAST_STATE == HIGH) {
      // Première détection
      // Enregistrement du moment de démarrage
      BEGINNING_STATE_LOW = millis();
    } else if (!STATE_LOW_SENT) {
      // Ca fait plusieurs tours, et le signal n'a pas été envoyé
      unsigned long duration = millis() - BEGINNING_STATE_LOW;
      // Si c'est suffisamment long, envoi du signal
      if (duration > minDurationMillis) {
        sendButtonClick();
        STATE_LOW_SENT = true;
      }
    }
  } else {
    // Reset so we're ready to send next LOW
    STATE_LOW_SENT = false;
  }
  INPUT_LAST_STATE = inputCurrentState;

}

void sendButtonClick() {
  digitalWrite(OPTO_OUTPUT_PIN, HIGH);
  delay(100);
  digitalWrite(OPTO_OUTPUT_PIN, LOW);
}
