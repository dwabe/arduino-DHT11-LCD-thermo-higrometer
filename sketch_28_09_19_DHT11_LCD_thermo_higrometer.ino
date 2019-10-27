#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 9
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu układu na 0x27

const int intTimePause = 1000;

float fltHumidity;
float fltTemperature;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16,2); //Inicjacja wyświetlacza
  lcd.clear();
  lcd.backlight(); //Włączenie podświetlenia

}

void loop() {
  fltHumidity = dht.readHumidity();
  fltTemperature = dht.readTemperature();
  if (isnan(fltTemperature) || isnan(fltHumidity))
    {
    lcd.setCursor(0, 0);
    lcd.print("DHT");
    lcd.print(DHTTYPE);
    lcd.setCursor(7, 0);
    lcd.print(": no data");
    }
  else
    {
    lcd.setCursor(0, 0);
    lcd.print("Temp. : ");
    lcd.setCursor(9, 0);
    lcd.print(fltTemperature);
    lcd.setCursor(15, 0);
    lcd.print((char)223);
    lcd.setCursor(14, 0);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humidity : ");
    lcd.setCursor(11, 1);
    lcd.print(fltHumidity);
    lcd.setCursor(15, 1);
    lcd.print("%");
    }
  delay(intTimePause);
}
