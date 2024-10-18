#include <Keypad.h>

// Mendefinisikan ukuran keypad 4x4
const byte ROWS = 4; 
const byte COLS = 4; 

// Mendefinisikan layout tombol keypad
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Mendefinisikan pin koneksi baris dan kolom
byte rowPins[ROWS] = {2, 3, 4, 5};    // Pin Arduino yang terhubung ke baris 1, 2, 3, 4
byte colPins[COLS] = {6, 7, 8, 9};    // Pin Arduino yang terhubung ke kolom 1, 2, 3, 4

// Membuat objek keypad
Keypad keypadCoba = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int a = 11; // Segment A
int b = 10; // Segment B
int c = A1; // Segment C
int d = A2; // Segment D
int e = A3; // Segment E
int f = 12; // Segment F
int g = 13; // Segment G
int dp = A0; // Decimal Point

void setup() {
  Serial.begin(9600);
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}

void loop() {
  char key = keypadCoba.getKey(); // Membaca tombol yang ditekan
  
  if (key) { // Jika tombol ditekan
    Serial.println(key); // Menampilkan tombol yang ditekan di Serial Monitor
    
    // Konversi karakter ke angka jika tombol adalah angka
    if (key >= '0' && key <= '9') {
      segment(key - '0'); // Panggil fungsi segment dengan angka yang sesuai
    } else {
      // Jika tombol bukan angka (A-D atau * / #), matikan semua segmen
      resetSegments();
    }
  }
}

void segment(int angka) {
  resetSegments(); // Reset semua segmen sebelum menampilkan angka

  switch (angka) {
        case 0:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      break;
      
    case 1:
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      break;
      
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH); 
      break;
      
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH); 
      break;

    case 4:
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;

    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;

    case 6:
      digitalWrite(a, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH); 
      digitalWrite(g, HIGH);
      break;

    case 7:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH);
      break;

    case 8:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, HIGH); 
      digitalWrite(e, HIGH); 
      digitalWrite(f, HIGH); 
      digitalWrite(g, HIGH);
      break;

    case 9:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, HIGH);
      digitalWrite(f, HIGH);  
      digitalWrite(g, HIGH);
      break;
      
    default:
        resetSegments(); // Reset jika input tidak valid
        break;
   }
}

void resetSegments() {
   // Matikan semua segmen
   digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, LOW);
   digitalWrite(g, LOW);
}