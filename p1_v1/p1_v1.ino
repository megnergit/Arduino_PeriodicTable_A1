#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int NX = 64;
const int NY = 12;
char pt[NY][NX] = {
    {"H                                 He"},
    {"LiBe                    B C N O F Ne"},
    {"NaMg                    AlSiP S ClAr"},
    {"K CaScTiV CrMnFeCoNiCuZnGaGeAsSeBrKr"},
    {"RbSrY ZrNbMoTcRuRhPdAgCdInSnAbTeI Xe"},
    {"CsBa  HfTaWReOsIrPtAuHgTlPbBiPoAtRn "},
    {"FrRa  RfDbSgBhHsMtDsRgCnNhFlMcLvTsOg"},
    {"                                    "},
    {"    LaCePrNdPmSmEuGdTbDyHoErTmYbLu  "},
    {"    AcThPaU NpPuAmCmBkCfEsFmMdNoLr  "},
};

int x = 0;
int y = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(NX, NY);
  renew(x, y);
}
void renew(int x, int y)
{
  int xp = x;
  String p0 = pt[y];
  String p1 = pt[y + 1];

  Serial.println(x);
  Serial.println(xp);

  lcd.clear();

  // right part
  if (x < 0)
  {
    xp = 0;
    Serial.println("substring: ");
    p0 = p0.substring(-x, NX);
    p1 = p1.substring(-x, NX);
  };

  //    Serial.println("\n");
  Serial.println(p0);
  Serial.println(p1);

  lcd.setCursor(xp, 0);
  lcd.print(p0);

  lcd.setCursor(xp, 1);
  lcd.print(p1);

  // Serial output for debugging
  /*  Serial.print(x);
    Serial.print("\t");
    Serial.print(y);
    Serial.print("\n"); */
  /*  for (int i = 0; i < NY; i++)
    {
      Serial.println(pt[i]);
    }; */
}

void loop()
{
  //  int x, y;
  int ADCdata = analogRead(A0);

  if (x < -NX)
  {
    x = -NX;
  };
  if (x >= NX)
  {
    x = (NX - 1);
  };
  if (y < 1)
  {
    y = 0;
  };
  if (y > NY)
  {
    y = (NY - 1);
  };

  lcd.setCursor(x, y);

  if (ADCdata < 50)
  { // right
    x = x + 1;
    renew(x, y);
  }
  else if (ADCdata < 150)
  { // up
    y = y - 1;
    renew(x, y);
  }
  else if (ADCdata < 350)
  { // down
    y = y + 1;
    renew(x, y);
  }
  else if (ADCdata < 500)
  { // left
    x = x - 1;
    renew(x, y);
  }
  else
  {
  }
  delay(200);
}
