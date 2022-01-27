
int column_1 = 0, column_2 = 0, column_3 = 0, column_4 = 0;
int column_1_pin = 2, column_2_pin = 3, column_3_pin = 4, column_4_pin = 5; // Spalten der Tasten
int row_1 = 12, row_2 = 11, row_3 = 10; // Zeilen der Tasten

int pot_out_1 = 6, pot_out_2 = 7, pot_out_3 = 8, pot_out_4 = 9; // Poti Stromversorgung


bool switches[12];

int pot[6];
int pot_alt[6];


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // initialize serial communication at 9600 bits per second

  // pins zu input und outputs setzen
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
  
  
  // Poti Stromversorgung an
  digitalWrite(pot_out_1, HIGH);
  digitalWrite(pot_out_2, HIGH);
  digitalWrite(pot_out_3, HIGH);
  digitalWrite(pot_out_4, HIGH);
  
  for(int i = 0; i < 12; i++)
    switches[i] = false;


  for(int i = 0; i < 6; i++)
    pot[i] = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  // Tasten auslesen
  digitalWrite(row_1, HIGH);

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
  
  
  // Potis auslesen
  for(int i = 0; i < 6; i++){
    pot_alt[i] = pot[i];
  }
  
  pot[0] = analogRead(A0);
  pot[1] = analogRead(A1);
  pot[2] = analogRead(A2);
  pot[3] = analogRead(A3);
  
  pot[4] = analogRead(A6);
  pot[5] = analogRead(A7);
  
  //if((pot_alt-pot)/pot_alt >= 0.02) {
    // übertragen an pc: pot
  //}
  
  // übertragen an pc: pot
  // übertragen an pc: switches

  for(int i = 0; i < 12; i++){
    Serial.print(switches[i]);
  }
  
  
  for(int i = 0; i < 6; i++){
    Serial.print(pot[i]);
  }

  Serial.println();
  
}
