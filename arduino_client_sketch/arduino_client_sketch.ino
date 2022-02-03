// Slider- / Potentiometerconfig
const int NUM_SLIDERS = 6;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A6, A7};

int analogSliderValues[NUM_SLIDERS];

// Switchconfig
const int NUM_SWITCHES = 12;
bool switches[NUM_SWITCHES];

int column_1 = 0, column_2 = 0, column_3 = 0, column_4 = 0;
int column_1_pin = 2, column_2_pin = 3, column_3_pin = 4, column_4_pin = 5; // Switch pincolumns
int row_1 = 12, row_2 = 11, row_3 = 10; // Switch rows

int pot_out_1 = 6, pot_out_2 = 7, pot_out_3 = 8, pot_out_4 = 9; // Slider power



void setup() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }

  // set pins to in and output
  pinMode(column_1_pin, INPUT);
  pinMode(column_2_pin, INPUT);
  pinMode(column_3_pin, INPUT);
  pinMode(column_4_pin, INPUT);

  pinMode(row_1, OUTPUT);
  pinMode(row_2, OUTPUT);
  pinMode(row_3, OUTPUT);

  pinMode(pot_out_1, OUTPUT);
  pinMode(pot_out_2, OUTPUT);
  pinMode(pot_out_3, OUTPUT);
  pinMode(pot_out_4, OUTPUT);

  // set slider power high
  digitalWrite(pot_out_1, HIGH);
  digitalWrite(pot_out_2, HIGH);
  digitalWrite(pot_out_3, HIGH);
  digitalWrite(pot_out_4, HIGH);

  for(int i = 0; i < NUM_SWITCHES; i++){
    switches[i] = false;
  }

  Serial.begin(9600);
}

void loop() {
  updateSwitchValues(); // Actually send data (all the time)
  sendSwitchValues();

  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
  // printSliderValues(); // For debug
  delay(10);
}

void updateSwitchValues() {
  digitalWrite(row_1, HIGH);
  delay(1);

  column_1 = digitalRead(column_1_pin);
  column_2 = digitalRead(column_2_pin);
  column_3 = digitalRead(column_3_pin);
  column_4 = digitalRead(column_4_pin);

  if(column_1 == HIGH)
    switches[1] = true;
  else
    switches[1] = false;

  if(column_2 == HIGH)
    switches[2] = true;
  else
    switches[2] = false;

  if(column_3 == HIGH)
    switches[3] = true;
  else
    switches[3] = false;

  if(column_4 == HIGH)
    switches[4] = true;
  else
    switches[4] = false;
  digitalWrite(row_1, LOW);


  digitalWrite(row_2, HIGH);
  delay(1);

  column_1 = digitalRead(column_1_pin);
  column_2 = digitalRead(column_2_pin);
  column_3 = digitalRead(column_3_pin);
  column_4 = digitalRead(column_4_pin);

  if(column_1 == HIGH)
    switches[5] = true;
  else
    switches[5] = false;

  if(column_2 == HIGH)
    switches[6] = true;
  else
    switches[6] = false;

  if(column_3 == HIGH)
    switches[7] = true;
  else
    switches[7] = false;

  if(column_4 == HIGH)
    switches[8] = true;
  else
    switches[8] = false;
  digitalWrite(row_2, LOW);


  digitalWrite(row_3, HIGH);
  delay(1);

  column_1 = digitalRead(column_1_pin);
  column_2 = digitalRead(column_2_pin);
  column_3 = digitalRead(column_3_pin);
  column_4 = digitalRead(column_4_pin);

  if(column_1 == HIGH)
    switches[9] = true;
  else
    switches[9] = false;

  if(column_2 == HIGH)
    switches[10] = true;
  else
    switches[10] = false;

  if(column_3 == HIGH)
    switches[11] = true;
  else
    switches[11] = false;

  if(column_4 == HIGH)
    switches[12] = true;
  else
    switches[12] = false;
  digitalWrite(row_3, LOW);
}

void sendSwitchValues() {
  String builtStringSwitch = String("s");

  for (int i = 0; i < NUM_SWITCHES; i++) {
    builtStringSwitch += String((int)switches[i]);

    if (i < NUM_SWITCHES - 1) {
      builtStringSwitch += String("|");
    }
  }

   Serial.println(builtStringSwitch);

}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtStringSlider = String("p");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtStringSlider += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtStringSlider += String("|");
    }
  }

  Serial.println(builtStringSlider);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
