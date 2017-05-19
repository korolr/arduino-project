#include <dht11.h>      
#include <LiquidCrystal.h>
  
#define DHT11_PIN 10 // Датчик DHT11 подключен к цифровому пину номер 10 
dht11 DHT;     

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)

void setup(){
  Serial.begin(9600);   // Скорость работы порта
  lcd.begin(16, 2);     // Задаем размерность экрана
  lcd.clear();
}

void loop(){
  int chk;
  // Мониторинг ошибок
  chk = DHT.read(DHT11_PIN);  
  switch (chk){
  case DHTLIB_OK:  
    break;
  case DHTLIB_ERROR_CHECKSUM:
    Serial.println("Checksum error, \t");
    break;
  case DHTLIB_ERROR_TIMEOUT:
    Serial.println("Time out error, \t");
    break;
  default:
    Serial.println("Unknown error, \t");
    break;
  } 
  lcd.setCursor(0,0); 
  lcd.print("Temp : ");
  lcd.print(" ");
  lcd.setCursor(7,0);
  lcd.print(DHT.humidity,1);
  lcd.setCursor(12,0);

  lcd.write((byte)0);
 
  lcd.setCursor(0,1); 
  lcd.print("Humid: ");
  lcd.print(" ");
  lcd.setCursor(7,1); 
  lcd.print(DHT.temperature,1);
  lcd.setCursor(12,1);
  lcd.print("%");
 
  delay(2000);
}

