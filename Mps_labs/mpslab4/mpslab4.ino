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
const byte ROWS = 4; //число строк у нашей клавиатуры
const byte COLS = 3; //число столбцов у нашей клавиатуры
unsigned long ta = 0;
unsigned long tb = 0;
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
  big = rez(prom);
  delay(50);
  break;
  case '#':
  lcd.clear();
  lcd.setCursor(0,1);
  Serial.print("time:");
  lcd.print("time:");
   Serial.print(tb-ta);
   lcd.print(tb-ta);
   Serial.println(" ms");
   lcd.print(" ms");
    lcd.setCursor(0,0);
  Serial.print(big);
  lcd.print(big);
  lcd.print(" even"); 
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
  }
}


int rez(int num){ 
  ta = millis();  
  int rez = 0; 
  long_mass++;
  p = (int*) realloc (p,long_mass * sizeof(int)); //выделение памяти
      p[i]=num;
      for(int j= 0; j<long_mass; j++){
            
      Serial.print(p[j]);
      Serial.print(" ");
      delay(1);
      }
      Serial.println("");
      i++;
      prom = 0;
   
  for(int j=0; j<long_mass; j++){   //вычисление большего числа 
     if(p[j]%2 == 0)
      rez++; 
  }
   tb=millis();
  
  return(rez);
  
  
}
