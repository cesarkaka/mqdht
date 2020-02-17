int x;
float y;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x = 300 ;
y = x / 1000;
Serial.println(y);
}
