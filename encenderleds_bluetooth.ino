#include <SoftwareSerial.h>

// Configurar pines para SoftwareSerial
SoftwareSerial BTSerial(10, 11); // RX, TX

// Definir pines para LEDs
const int LED1_PIN = 5;
const int LED2_PIN = 6;
const int LED3_PIN = 7;
const int LED4_PIN = 8;
char letra =' ';

void setup() {
  // Iniciar comunicación serial para el monitor serial
  Serial.begin(9600);
  
  // Iniciar comunicación con el módulo Bluetooth HC-06
  BTSerial.begin(9600);
  
  // Configurar los pines de los LEDs como salida
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
Serial.println("Iniciando control..");
}

void loop() {
  // Verificar si hay datos disponibles desde el módulo Bluetooth
  if (BTSerial.available()) {
    letra = BTSerial.read();
    Serial.print("Comando recibido: ");
    Serial.println(letra);
    onOffLeds();
      
  }
}
void onOffLeds(void){
  if(letra =='A'){digitalWrite(8,HIGH);}
  if(letra =='B'){digitalWrite(8,LOW);}
  if(letra =='C'){digitalWrite(7,HIGH);}
  if(letra =='D'){digitalWrite(7,LOW);}
  if(letra =='1'){digitalWrite(5,HIGH);}
  if(letra =='2'){digitalWrite(5,LOW);}
  if(letra =='3'){digitalWrite(6,HIGH);}
  if(letra =='4'){digitalWrite(6,LOW);}
}

void comprobarLeds(){
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);
  delay(200);

  digitalWrite(9,HIGH);
  delay(200);
  digitalWrite(9,LOW);
  delay(200);
}
