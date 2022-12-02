// Slider- / Potentiometerconfig
const int NUM_SLIDERS = 6;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A6, A7};

int analogSliderValues[NUM_SLIDERS];
int temp=0;

// Switchconfig
const int NUM_SWITCHES = 12;
int switches[NUM_SWITCHES]={false};

int column[4]={0};
int column_pin[4]={2, 3, 4, 5};  // Switch pincolumns
int row[3]={12, 11, 10};  // Switch rows

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
  for(int i=1; i<=4; i++) {
    pinMode(column_pin[i], INPUT);

  for(int i=1; i<=3; i++) {
    pinMode(row[i], OUTPUT);

  pinMode(LED_BUILTIN, Output);

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
  for(int i=1; 1<=3; i++) {
    digitalWrite(row[i], HIGH);
    delay(1);

    for(int j=1; j<=4; j++) {
      column[j] = digitalRead(column_pin[j]);

    for(int j=1; j<=4; j++) {
      for(int k=0; k<=3; k++) {

        if(column[j] == HIGH && !is_pressed[k] && any_pressed == false){
          switches[k] = true;
          is_pressed[k] = true;
          any_pressed = true;
        }
        else{
          switches[k] = false;
          if(column[j] == LOW){
            is_pressed[k] = false;
            any_pressed = false;
          }
        }
      }
    }
    
    digitalWrite(row[i], LOW);
  }
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
