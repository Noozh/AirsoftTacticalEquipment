boolean disarmed = false;
int val = 0; //variable para asignar la lectura del sensor PIR
int sense;
void setup()
{
  tone(6,25,10000);
  Serial.begin(115200);
  Serial.println("Armando mina");
  delay(10000);
  Serial.println("Armada");
  digitalWrite(6,HIGH);
}
void loop()
{
  if (!disarmed){
      digitalWrite(6,HIGH);
      sense = analogRead(0); //Lee el valor de la variable (val)
      if (sense > 100){
        Serial.println("Enemigo detectado");
        tone(4,3000,5000);
        delay(1000);
        disarmed = true;
      }
      delay(100);
      
  }else{
    digitalWrite(6,LOW);
    Serial.println("Mina desarmada");
  }
}
