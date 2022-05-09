// Slider- / Potentiometerconfig
const int NUM_SLIDERS = 6;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A6, A7};

int analogSliderValues[NUM_SLIDERS];
int temp=0;

// Switchconfig
const int NUM_SWITCHES = 12;
int switches[NUM_SWITCHES]={false};

int column_1 = 0, column_2 = 0, column_3 = 0, column_4 = 0;
int column_1_pin = 2, column_2_pin = 3, column_3_pin = 4, column_4_pin = 5; // Switch pincolumns
int row_1 = 12, row_2 = 11, row_3 = 10; // Switch rows

bool is_pressed[NUM_SWITCHES]={false};
bool any_pressed = false;

bool opend = false;
String themp;
int count = 0;

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

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if(opend == true){


    //Switches
    updateSwitchValues();

    for(int i=0; i<NUM_SWITCHES; i++){
      temp += switches[i];
      }
     if(temp<=1){
      sendSwitchValues(); // Actually send data (all the time)
     }
     temp = 0;
  

    //Sliders
    updateSliderValues();
    delay(10);
    sendSliderValues(); // Actually send data (all the time)
    

    themp = Serial.read();
    if(themp != "99"){  //check for c
      
      count ++;
      
      if(count >=100){
        opend = false;
        count = 0;
        Serial.println("closed");
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
    else{
      count = 0;
    }

    
    delay(10);
  }
  else{
  themp = Serial.read();
  Serial.println(themp);
    if(themp == "111"){  //check for o
      opend = true;
      Serial.println("opend");
    }
    else{
      delay(10000);
    }
    if(themp != "-1"){
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}

void updateSwitchValues() {
  digitalWrite(row_1, HIGH);
  delay(1);

  column_1 = digitalRead(column_1_pin);
  column_2 = digitalRead(column_2_pin);
  column_3 = digitalRead(column_3_pin);
  column_4 = digitalRead(column_4_pin);

  if(column_1 == HIGH && !is_pressed[0] && any_pressed == false){
    switches[0] = true;
    is_pressed[0] = true;
    any_pressed = true;
  }
  else{
    switches[0] = false;
    if(column_1 == LOW){
      is_pressed[0] = false;
      any_pressed = false;
    }
  }

 if(column_2 == HIGH && !is_pressed[1] && any_pressed == false){
    switches[1] = true;
    is_pressed[1] = true;
    any_pressed = true;
  }
  else{
    switches[1] = false;
    if(column_2 == LOW){
      is_pressed[1] = false;
      any_pressed = false;
    }
  }

 if(column_3 == HIGH && !is_pressed[2] && any_pressed == false){
    switches[2] = true;
    is_pressed[2] = true;
    any_pressed = true;
  }
  else{
    switches[2] = false;
    if(column_3 == LOW){
      is_pressed[2] = false;
      any_pressed = false;
    }
  }

  if(column_4 == HIGH && !is_pressed[3] && any_pressed == false){
    switches[3] = true;
    is_pressed[3] = true;
    any_pressed = true;
  }
  else{
    switches[3] = false;
    if(column_4 == LOW){
      is_pressed[3] = false;
      any_pressed = false;
    }
  }
  digitalWrite(row_1, LOW);


  digitalWrite(row_2, HIGH);
  delay(1);

  column_1 = digitalRead(column_1_pin);
  column_2 = digitalRead(column_2_pin);
  column_3 = digitalRead(column_3_pin);
  column_4 = digitalRead(column_4_pin);

  if(column_1 == HIGH && !is_pressed[4] && any_pressed == false){
    switches[4] = true;
    is_pressed[4] = true;
    any_pressed = true;
  }
  else{
    switches[4] = false;
    if(column_1 == LOW){
      is_pressed[4] = false;
      any_pressed = false;
    }
  }

   if(column_2 == HIGH && !is_pressed[5] && any_pressed == false){
    switches[5] = true;
    is_pressed[5] = true;
    any_pressed = true;
  }
  else{
    switches[5] = false;
    if(column_2 == LOW){
      is_pressed[5] = false;
      any_pressed = false;
    }
  }

   if(column_3 == HIGH && !is_pressed[6] && any_pressed == false){
    switches[6] = true;
    is_pressed[6] = true;
    any_pressed = true;
  }
  else{
    switches[6] = false;
    if(column_3 == LOW){
      is_pressed[6] = false;
      any_pressed = false;
    }
  }

   if(column_4 == HIGH && !is_pressed[7] && any_pressed == false){
    switches[7] = true;
    is_pressed[7] = true;
    any_pressed = true;
  }
  else{
    switches[7] = false;
    if(column_4 == LOW){
      is_pressed[7] = false;
      any_pressed = false;
    }
  }
  digitalWrite(row_2, LOW);


  digitalWrite(row_3, HIGH);
  delay(1);

  column_1 = digitalRead(column_1_pin);
  column_2 = digitalRead(column_2_pin);
  column_3 = digitalRead(column_3_pin);
  column_4 = digitalRead(column_4_pin);

  if(column_1 == HIGH && !is_pressed[8] && any_pressed == false){
    switches[8] = true;
    is_pressed[8] = true;
    any_pressed = true;
  }
  else{
    switches[8] = false;
    if(column_1 == LOW){
      is_pressed[8] = false;
      any_pressed = false;
    }
  }

  if(column_2 == HIGH && !is_pressed[9] && any_pressed == false){
    switches[9] = true;
    is_pressed[9] = true;
    any_pressed = true;
  }
  else{
    switches[9] = false;
    if(column_2 == LOW){
      is_pressed[9] = false;
      any_pressed = false;
    }
  }

  if(column_3 == HIGH && !is_pressed[10] && any_pressed == false){
    switches[10] = true;
    is_pressed[10] = true;
    any_pressed = true;
  }
  else{
    switches[10] = false;
    if(column_3 == LOW){
      is_pressed[10] = false;
      any_pressed = false;
    }
  }

  if(column_4 == HIGH && !is_pressed[11] && any_pressed == false){
    switches[11] = true;
    is_pressed[11] = true;
    any_pressed = true;
  }
  else{
    switches[11] = false;
    if(column_4 == LOW){
      is_pressed[11] = false;
      any_pressed = false;
    }
  }
  digitalWrite(row_3, LOW);
}

void sendSwitchValues() {
  String builtStringSwitch = String("k");

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
  String builtStringSlider = String("s");

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
