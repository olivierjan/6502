int clockPin=4;
int i=0;

void setup() {
  pinMode(clockPin, OUTPUT);
  while(1){
    GPIOA_PDOR &=0x0000;
    for (i=0; i< 100000000; i++){}
    GPIOA_PDOR |=1<<13;
    for (i=0; i< 100000000; i++){}
  }
}

void loop(){
  GPIOA_PDOR &=0x0000;
  for (i=0; i< 200; i++){}
  GPIOA_PDOR |=1<<13;
  for (i=0; i< 200; i++){}
}
