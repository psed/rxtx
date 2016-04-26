LiquidCrystal_I2C lcd(0x3F,20,4);

void initDisplay()
{
  lcd.init();                     
  lcd.backlight();
}
