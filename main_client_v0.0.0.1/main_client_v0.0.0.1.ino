
int column_1 = 2, column_2 = 3, column_3 = 4, column_4 = 5; // Spalten der Tasten
int row_1 = 12, row_2 = 11, row_3 = 10; // Zeilen der Tasten

int pot_out_1 = 6, pot_out_2 = 7, pot_out_3 = 8, pot_out_4 = 9 // Poti Stromversorgung


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // initialize serial communication at 9600 bits per second

  // pins zu input und outputs setzen
  pinMode(column_1, INPUT);
  pinMode(column_2, INPUT);
  pinMode(column_3, INPUT);
  pinMode(column_4, INPUT);

  pinMode(row_1, OUTPUT);
  pinMode(row_2, OUTPUT);
  pinMode(row_3, OUTPUT);

  pinMode(pot_out_1, OUTPUT);
  pinMode(pot_out_2, OUTPUT);
  pinMode(pot_out_3, OUTPUT);
  pinMode(pot_out_4, OUTPUT);

  bool switches[12];
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(row_1, HIGH);

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

  if(column_1 == HIGH)
    switches[5] = true;
  else
    switches[5] = false;

  if(column_2 == HIGH)
    switches[6] = true;
  else
    switches[6] = false

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

  if(column_1 == HIGH)
    switches[9] = true;
  else
    switches[9] = false;

  if(column_2 == HIGH)
    switches[10] = true;
  else
    switches[10] = false

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
