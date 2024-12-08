#include <Arduino.h>

#define increaseButton PA0
#define decreaseButton PA1
#define LED_PIN PB1

int button1, button2;
int dim_value = 0;

void setup() {
  pinMode(increaseButton, INPUT);
  pinMode(decreaseButton, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  button1 = digitalRead(increaseButton);
  button2 = digitalRead(decreaseButton);
  if(button1 == HIGH){
    if(dim_value > 255){
      dim_value = 255;
    }
    else{
      dim_value += 51;
      delay(300);
    }
  }

  if(button2 == HIGH){
    if(dim_value < 51){
      dim_value = 0;
    }
    else{
      dim_value -= 51;
      delay(300);
    }
  }
  analogWrite(LED_PIN, dim_value);
}