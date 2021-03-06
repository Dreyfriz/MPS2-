#include <stdio.h>
#include <stdlib.h>
#include <Keypad.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int i = 0;
int prom = 0;
int long_mass = 0; // переменная для длинны массива
int *p = NULL;  // массив
int m[6] = {0,0,0,0,0,0};
int big = 0;
int mins = 0;
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
switch (Key)
{
  case '1':
  chislo(1);
  Serial.print(prom);
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
  lcd.clear();
  big = rez(prom);
  mins =rez1(prom);
  delay(50);
  break;
  case '#':
  Serial.println(big);
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("max-");
  lcd.print(big); 
  lcd.setCursor(0,1);
   lcd.print("min-");
  lcd.print(mins);
  free(p);
  delay(50);
  break;
}
}
}

int chislo(int a)
{
  if ( prom == 0 ){
  prom = a;}
  else{
  prom = prom*10+a;
  lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print(prom);
  }
}

int rez(int num){   
  int rez = 0; 
  long_mass++;
  p = (int*) realloc (p,long_mass * sizeof(int)); //выделение памяти
      p[i]=num;
      for(int j= 0; j<long_mass; j++){
      
      Serial.print(p[j]);
      Serial.print(" ");
   lcd.clear();
   lcd.setCursor(0,0); 
      }
      i++;
      prom = 0;
      
   rez = p[0];
  for(int j=1; j<long_mass; j++){   //вычисление большего числа 
     if(p[j] > rez)
      rez = p[j]; 
  }
  return(rez);
}
int rez1(int num){   
  int rez = 0;
  rez = p[0];
  for(int j=1; j<long_mass; j++){   //вычисление большего числа 
     if (p[j] ==0)
     j++;
     else if(p[j] < rez)
      rez = p[j]; 
  }
  return(rez);
}
