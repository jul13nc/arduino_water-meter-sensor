
const int SENSOR_INPUT_PIN=6;
const int OPTO_OUTPUT_PIN=2;
// Duration of the pulse in microseconds
unsigned long pulseDuration;
// Minmum duration of the pulse  to be taken into account
// Maximum flow should be around 1L/s, so 0,5s per pulse (half disk)
// Having the minimum pulse to 0,2s should be enough to avoid false positive
// And to be able to still read all possible values
const unsigned long minDuration = 200000; // 0,2s

const unsigned long TIMEOUT_FOR_PULSE_INPUT = 180000000;

void setup() {
    pinMode(SENSOR_INPUT_PIN, INPUT);
    pinMode(OPTO_OUTPUT_PIN, OUTPUT);
}
 
void loop() {
  pulseDuration = pulseInLong(SENSOR_INPUT_PIN, LOW, TIMEOUT_FOR_PULSE_INPUT);
  if (pulseDuration > minDuration) {
    digitalWrite(OPTO_OUTPUT_PIN, HIGH);
    delay(200);
    digitalWrite(OPTO_OUTPUT_PIN, LOW);
  }
}
