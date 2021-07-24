sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

void main()
{
  char a[10];
  int  value,temp;
  double r,logr;
  float c1=1.009249522e-03,c2=2.37840544e-04,c3=2.019202697e-07;
  Lcd_Init();
  ADCON1=0b00000000;
while(1)
{
  value= ADC_Read(0);
  r=10000.0/((1023/value)-1);
  logr=log(r);
  temp=((1.0/(c1+c2*logr+c3*logr*logr*logr))-273.15);
  IntToStr(temp,a);
  Lcd_Out(2,1,a);
  Delay_ms(200);
}
}