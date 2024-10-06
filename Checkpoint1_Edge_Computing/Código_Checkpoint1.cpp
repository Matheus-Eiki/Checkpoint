//Define os pinos
const int buzzerPin = 9; //Atribui a porta digital 9 a variável buzzerPin 
const int ldrPin = A0;  // Pino analógico utilizado para ler o LDR
const int ledVerde = 10; //Atribui a porta digital 10 a variável ledVerde
const int ledAmarelo = 11;//Atribui a porta digital 11 a variável ledAmarelo
const int ledVermelho = 12;//Atribui a porta digital 12 a variável ledVermelho

//Variáveis globais
int ldrValue = 0;//Armazena a leitura do sensor LDR
const int freq = 5;//Contador de frequência

//Define a inicialização do código
void setup() {
    Serial.begin(9600);// Inicia a comunicação serial
    pinMode(ldrPin, INPUT);// Define o pino do LDR como entrada
    pinMode(buzzerPin, OUTPUT);// // Define o pino do buzzerPin como saída
    pinMode(ledVerde, OUTPUT);//Define o pino do ledVerde como saída
    pinMode(ledAmarelo, OUTPUT);// Define o pino do ledAmarelo como saída
    pinMode(ledVermelho, OUTPUT);// Define o pino do ledVermelho como saída
}

//Começa um ciclo dentro do código
void loop() {
// Mapeia a leitura para uma escala de 0 a 100
   ldrValue = map(analogRead(ldrPin), 49, 969, 0, 100);

  //Verifica se o valor do LDR foi maior que 30
   if (ldrValue < 30) {
   digitalWrite(ledVerde, HIGH);//Acende o ledVerde
   }
  else
     digitalWrite(ledVerde, LOW);//Desliga o ledVerde
   
  //Verifica se o valor do LDR foi maior que 30 e menor que 60
   if (ldrValue > 30 && ldrValue < 60) {
    digitalWrite(ledAmarelo, HIGH);//Acende o ledAmarelo
  }
  else
    digitalWrite(ledAmarelo, LOW);//Desliga o ledAmarelo

  //Verifica se o valor do LDR foi maior que 60
  if (ldrValue > 60) {
    digitalWrite(ledVermelho, HIGH);//Acende o ledVermelho
  }
  else
    digitalWrite(ledVermelho, LOW);//Desliga o ledVermelho
  //Verifica se o valor do LDR foi maior que 30
  if (ldrValue > 30) {
    digitalWrite(buzzerPin, HIGH);{//Liga o buzzer
    delay(3000);// Aguarda 3 segundos antes da próxima leitura
    }
  }
  else
    digitalWrite(buzzerPin, LOW);{//Mantém o buzzer desligado
    delay(ldrValue);// Aguarda a próxima leitura

  }
	 // Imprime a intensidade de luz
  	Serial.println(ldrValue);


  delay(300);// Aguarda 300 milissegundos antes da próxima leitura
}