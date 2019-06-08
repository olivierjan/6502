int clockPin=4;
int i=0;

void setup() {
  pinMode(clockPin, OUTPUT);
}

void loop(){
  GPIOA_PDOR &=0x0000;
  for (i=0; i< 8; i++){}
  GPIOA_PDOR |=1<<13;
  for (i=0; i< 8; i++){}
}
