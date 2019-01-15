#include <stdio.h>
#include <stdlib.h>
#include <Keypad.h> // подключаем нашу библиотеку
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int prom = 0;
float A = 0;
float B = 0;
float x = 0;
float i = 0;
float Fx = 0;
const byte ROWS = 4; //число строк у нашей клавиатуры
const byte COLS = 3; //число столбцов у нашей клавиатуры

char hexaKeys[ROWS][COLS] = {

{'1','2','3'}, // здесь мы располагаем названия наших клавиш, как на клавиатуре,для удобства пользования

{'4','5','6'},

{'7','8','9'},

{'*','0','#'}

};

byte rowPins[ROWS] = {8, 7, 6, 5}; //к каким выводам подключаем управление строками

byte colPins[COLS] = { 4, 3, 2}; //к каким выводам подключаем управление столбцами

//initialize an instance of class NewKeypad

Keypad Keypres = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27,16,2); // присваиваем имя lcd для дисплея 16х2
void setup(){
  lcd.init(); // инициализация LCD дисплея
  lcd.backlight(); // включение подсветки дисплея
  
Serial.begin(9600);

}

void loop(){
char Key = Keypres.getKey();
if(Key)
{
switch(Key)
{
  case '1':
  chislo(1);
  Serial.println(prom);
  lcd.clear();
  lcd.setCursor(0,0); // ставим курсор на 1 символ первой строки
  lcd.print(prom); // печатаем сообщение на первой строке 
  delay(50);
  break;
   case '2':
   chislo(2);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '3':
   chislo(3);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '4':
   chislo(4);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '5':
   chislo(5);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '6':
   chislo(6);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '7':
   chislo(7);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '8':
   chislo(8);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '9':
   chislo(9);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '0':
   chislo(0);
   Serial.println(prom);
   lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
   delay(50);
  break;
  case '*':
  if ( prom > 10){
    Serial.println("Error: 2");
    prom = 0;
    i = 0;
    break;
  }
   else if ( prom < -10){
    Serial.println("Error: 2");
    prom = 0;
    i = 0;
    break;
  }
 
  chislo(10);
   delay(250);
  break;
  case '#':
  chislo(11);
  Serial.println(prom);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(prom);
  delay(50);
  break;
}
}
}
int chislo(int a)
{
  if (a == 10){
    if (i==0)
    A = prom;
    else if (i == 1){
    B = prom;
    vivod();
    rez();
    }
    else {
    Serial.println("Error: 1 ");
    lcd.setCursor(0,0); 
    lcd.print("Error: 1");}
  prom = 0;
  i++;
    
  }
  else if (a == 11)
  prom = 0 - prom;
  else{
    if ( prom == 0 ){
    prom = a;}
    else
    prom = prom*10+a;
    
  }
}

int vivod(){
  lcd.clear();
  Serial.print("A=");
  lcd.setCursor(0,0); 
  lcd.print("A");
  lcd.print("=");
Serial.println(A); 
  lcd.print(A);
Serial.print("B=");
 lcd.setCursor(0,1); 
  lcd.print("B");
  lcd.print("="); 
  lcd.print(B);
Serial.println(B);
}
  

int rez(){
  x =(A-0.5)+(B+A)/5;
 if(x >= -5)
 Fx = (A*x+0.7*B)/(A*B)-((4*x)/15);
 else 
 Fx = A*x+((0.9*B)/(4*x));
  Serial.println(Fx);
  lcd.printstr(" ");
  lcd.printstr("Fx=");
  lcd.print(Fx);
 
}
