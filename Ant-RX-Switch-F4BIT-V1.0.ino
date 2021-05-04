// Arduino Nano Antenna RX Switch V1.0
// LCD 16x2 + 8 Relay Module
// Switch SP8T HMC253 DC-2.5 GHz
// Stéphane F4BIT/N4BIT
// stephane@mangeolle.fr
// Copyleft@2021 for Hamradio

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //  addresse du LCD en I2C sur A4-A5

// initialise les descriptions des antennes

char antenna1[16] =     "Antenne 1";
char description1[16] = "Description1";
char antenna2[16] =     "Antenne 2";
char description2[16] = "Description2";
char antenna3[16] =     "Antenne 3";
char description3[16] = "Description3";
char antenna4[16] =     "Antenne 4";
char description4[16] = "Description4";
char antenna5[16] =     "Antenne 5";
char description5[16] = "Description5";
char antenna6[16] =     "Antenne 6";
char description6[16] = "Description6";
char antenna7[16] =     "Antenne 7";
char description7[16] = "Description7";
char antenna8[16] =     "Antenne 8";
char description8[16] = "Description8";

// initialise les pins relais

const int relay1 = 12; // relais 1
const int relay2 = 11; // relais 2
const int relay3 = 10; // relais 3


// initialise les pins boutons

const int boutonUP = 2; // déclaration du bouton Haut
const int boutonDOWN = 3; // déclaration du bouton Bas

int boutonUPappui = 0; // variable lorsque j'appuie sur le bouton
int boutonDOWNappui = 0; // variable lorsque j'appuie sur le bouton

int etatboutonUP = 0; // etat dans lequel se trouve le bouton
int etatboutonDOWN = 0; // etat dans lequel se trouve le bouton

int Data = 0; // variable
int oldData; // variable

void setup()
{

  // initialise les pins relais 1,2,3 comme output

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);


  // initialise les relais à OFF

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);


  // initialise les pins bouttons à input

  pinMode(boutonUP, INPUT_PULLUP);// déclaration du bouton en entrée avec la résistance pullup
  pinMode(boutonDOWN, INPUT_PULLUP);// déclaration du bouton en entrée avec la résistance pullup

  // initialise le moniteur serie

  Serial.begin(9600);// mon port de communication
  Serial.println ("Antenna RX Switch by F4BIT V1.0");

  // Message d'accueil sur le LCD

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Ant-RX Switch");
  lcd.setCursor(0, 1);
  lcd.print("  v1.0 - F4BIT");
  delay(4000);

}
void loop()
{
  // test des boutons +-

  boutonUPappui = digitalRead(boutonUP);//etatbouton est égale à la lecture du bouton
  boutonDOWNappui = digitalRead(boutonDOWN);//etatbouton est égale à la lecture du bouton
  oldData = Data;
  if ((boutonUPappui == HIGH && etatboutonUP == LOW) && (Data >= 1 && Data <= 8 ) ) {
    Data = Data + 1;
    delay(100);
  }
  if (Data >= 8) {
    Data = 8;
  }
  else
  {
    Data = Data;
  }
  if ((boutonDOWNappui == HIGH && etatboutonDOWN == LOW) && (Data >= 1 && Data <= 8 ) ) {
    Data--;
    delay(100);
  }
  if (Data <= 1) {
    Data = 1;
  }
  else
  {
    Data = Data;
  }

  etatboutonUP = boutonUPappui ;
  etatboutonDOWN = boutonDOWNappui ;

  if (oldData != Data) {
    Serial.print(" Data : ");
    Serial.println(Data);

    if (Data == 1) {
      menu1();
    }
    else if (Data == 2) {
      menu2();
    }
    else if (Data == 3) {
      menu3();
    }
    else if (Data == 4) {
      menu4();
    }
    else if (Data == 5) {
      menu5();
    }
    else if (Data == 6) {
      menu6();
    }
    else if (Data == 7) {
      menu7();
    }
    else if (Data == 8) {
      menu8();
    }
  }
  else
  {
    oldData = Data ;
  }
}
// Menus pour chaque relais/antenne

void menu1()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna1);
  lcd.setCursor(0, 1);
  lcd.print(description1);
  resetrelay();
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
}

void menu2()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna2);
  lcd.setCursor(0, 1);
  lcd.print(description2);
  resetrelay();
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
}

void menu3()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna3);
  lcd.setCursor(0, 1);
  lcd.print(description3);
  resetrelay();
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
}

void menu4()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna4);
  lcd.setCursor(0, 1);
  lcd.print(description4);
  resetrelay();
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
}

void menu5()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna5);
  lcd.setCursor(0, 1);
  lcd.print(description5);
  resetrelay();
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
}

void menu6()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna6);
  lcd.setCursor(0, 1);
  lcd.print(description6);
  resetrelay();
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
}

void menu7()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna7);
  lcd.setCursor(0, 1);
  lcd.print(description7);
  resetrelay();
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
}

void menu8()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(antenna8);
  lcd.setCursor(0, 1);
  lcd.print(description8);
  resetrelay();
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
}

void resetrelay()
{
  // initialise les relais à OFF

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);

}
