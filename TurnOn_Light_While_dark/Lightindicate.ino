
  int DIMLED = 12;
  int LIGHTLED = 11;
  int BRIGHTLED = 10;
  int VERYBRIGHT= 9;
  int DARKLED = 8;
  int ACON = 7;
  bool LIGHTON= false;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(DARKLED, OUTPUT);
  pinMode(DIMLED,OUTPUT);
  pinMode(LIGHTLED, OUTPUT);
  pinMode(BRIGHTLED,OUTPUT);
  pinMode(VERYBRIGHT,OUTPUT);
  pinMode(ACON, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
    int analogValue = analogRead(A0);
    Serial.print("Analog reading = ");
    Serial.print(analogValue); 
  
  
   digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  if (analogValue < 10) {
    Serial.println(" - Dark");
    digitalWrite(DARKLED, HIGH);
    LIGHTON = true;
    
  } else if (analogValue < 200) {
    digitalWrite(DIMLED,HIGH);
    digitalWrite(13, HIGH);
    Serial.println(" - Dim");
    LIGHTON = true;
  } else if (analogValue < 500) {
    Serial.println(" - Light");
    digitalWrite(LIGHTLED, HIGH);
  } else if (analogValue < 800) {
    Serial.println(" - Bright");
    digitalWrite(BRIGHTLED,HIGH);
  } else {
    Serial.println(" - Very bright");
    digitalWrite(VERYBRIGHT,HIGH);
  }
   if(LIGHTON){
     digitalWrite(ACON, HIGH);
  }
  delay(500);
  
  digitalWrite(DARKLED, LOW);
  digitalWrite(DIMLED,LOW);
  digitalWrite(LIGHTLED, LOW);
  digitalWrite(BRIGHTLED,LOW);
  digitalWrite(VERYBRIGHT,LOW);
  digitalWrite(ACON, LOW);

 
  
}
