int a = 10;
int b = 9;
int c = 8;
int d = 7;
int e = 6;
int f = 5;
int g = 4;
int buzzer=A0;     
  
 void
setup(){  
  pinMode(buzzer,OUTPUT);   
}  

void setup() {
  for (int i = 10; i >= 4; i--) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    segment(i);
    delay(1000);
  }
}

void segment(int angka) {
  int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  // Set the segments based on the input digit
  digitalWrite(a, segments[angka][0]);
  digitalWrite(b, segments[angka][1]);
  digitalWrite(c, segments[angka][2]);
  digitalWrite(d, segments[angka][3]);
  digitalWrite(e, segments[angka][4]);
  digitalWrite(f, segments[angka][5]);
  digitalWrite(g, segments[angka][6]);
}
