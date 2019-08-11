#include <DHT.h>                        //Inclui a bilbioteca DHT
#include <LiquidCrystal.h>              //Inclui a biblioteca LiquidCrystal
#define DHTPIN 12                       //Define o pino do DHT no Arduino
#define DHTTYPE DHT11                   //Define modelo do DHT
LiquidCrystal lcd(1, 3, 4, 5, 6, 7);    //Define os pinos do LCD (RS, E, D4, D5, D6, D7)
DHT dht (DHTPIN, DHTTYPE);
 
byte grau[8] ={ B00001100,              //Montagem do simbolo "grau"
                B00010010,              //Montagem do simbolo "grau"
                B00010010,              //Montagem do simbolo "grau"
                B00001100,              //Montagem do simbolo "grau"
                B00000000,              //Montagem do simbolo "grau"
                B00000000,              //Montagem do simbolo "grau"
                B00000000,              //Montagem do simbolo "grau"
                B00000000,};            //Montagem do simbolo "grau"
 
void setup() {
 
 lcd.begin(16,2);                       //Inicializa o LCD e especifica sua dimensao
 lcd.clear();                           //Limpa o LCD
 lcd.createChar(0, grau);               //Cria o caractere de grau
}
 
void loop() {
  float t = dht.readTemperature();      //Leitura do valor de temperatura
  float h = dht.readHumidity();         //Leitura do valor de umidade
  lcd.setCursor(0,0);                   //Posiciona o cursor no canto superior esquerdo do display
  lcd.print("Temp: ");                  //
  lcd.print(" ");                       //Adiciona um caractere de espaço
  lcd.setCursor(7,0);                   //Posiciona a informação de temperatura aferida pelo sensor
  lcd.print(t,1);                       //Inclui a informação de temperatura aferida pelo sensor
  lcd.setCursor(12,0);                  //Posiciona o símbolo de grau formado pelo array
  lcd.write((byte)0);                   //Mostra o símbolo de grau formado pelo array
  lcd.print("C");                       //Mostra o símbolo da unidade Celsius
 
 
lcd.setCursor(0,1);                     //Posiciona o cursor no canto inferior esquerdo do display
lcd.print("Umid : ");                   //
lcd.print(" ");                         //Adiciona um caractere de espaço
lcd.setCursor(7,1);                     //Posiciona a informação de umidade aferida pelo sensor
lcd.print(h,1);                         //Inclui a informação de umidade aferida pelo sensor
lcd.setCursor(12,1);                    //Posiciona o símbolo de porcentagem
lcd.print("%");                         //Mostra o símbolo de porcentagem de umidade
 
delay(1000);                            //Intervalo de leitura do sensor
}
