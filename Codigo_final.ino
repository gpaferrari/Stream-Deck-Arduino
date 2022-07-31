#include <SoftwareSerial.h>

SoftwareSerial serial1(12, 13); // RX, TX

const int vermelho = 2;
const int verde = 3;
const int azul = 4;

char botao[8] = {A0, A1, A2, A3, A4, A5, 6, 7};
int estadobotao[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int first = 0;

void setup() {

  serial1.begin(9600);
  Serial.begin(9600);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);

  for(int cont = 0; cont < 8; cont ++){
    pinMode(botao[cont], INPUT);
  }
}

//Criando funções
void LigaVermelho(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}
void LigaAzul(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}
void LigaVerde(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}
void DesligaLed(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}

void loop() {
  int caracter = 0;
  DesligaLed();

  //Testando energia
  if(first == 0){
    LigaVerde();
    delay(1500);
    DesligaLed();
    Serial.println("Start");
    //Testando Bluetooth
   
    if(caracter == 56){
      Serial.println("Conectado");
      LigaAzul();
      delay(1500);
    }
    first = 1;
  }
  
  DesligaLed();
  
  for(int cont = 0; cont < 8; cont ++){
    estadobotao[cont] = digitalRead(botao[cont]);
    if(estadobotao[cont] == 1){
      LigaVermelho();
      Serial.print("Botao ");
      Serial.print(cont);
      Serial.println(" apertado");
      estadobotao[cont] = 0; 
      serial1.print(cont);
      delay(800);
    }
    else if (estadobotao[cont] == 0){
      estadobotao[cont] = 0;  
    }
  }
}
