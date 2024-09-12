 #include <SoftwareSerial.h>

// Configurar pines para SoftwareSerial
SoftwareSerial bt(10, 11); // TX, RX
//COMANDOS AT
//AT = devuelve como resultado ok
//AT+NAME= establece el nombre pero debe ser seguido
//AT+PIN=establece la constraseña

void setup() {
  // Iniciar la comunicación con el monitor serial para ver los resultados
  Serial.begin(9600);
  // Iniciar la comunicación con el módulo Bluetooth HC-06
  bt.begin(9600);

}

void loop() {
  // Verificar si hay respuesta del módulo Bluetooth
  if (bt.available()) {
    Serial.write(bt.read());
    
  }
  if(Serial.available()){
    bt.write(Serial.read());
  }
}
