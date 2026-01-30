// Simple Half Adder & Full Adder

const int ledHalfSum = 10;
const int ledHalfCarry = 11;
const int ledFullSum = 12;
const int ledFullCarry = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledHalfSum, OUTPUT);
  pinMode(ledHalfCarry, OUTPUT);
  pinMode(ledFullSum, OUTPUT);
  pinMode(ledFullCarry, OUTPUT);
}

void loop() {
  // Half Adder demo
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      halfAdder(a, b);
      delay(1500);
    }
  }

  // Full Adder demo
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      for (int c = 0; c <= 1; c++) {
        fullAdder(a, b, c);
        delay(1500);
      }
    }
  }
}

void halfAdder(int a, int b) {
  int sum = a ^ b;          // Sum = A XOR B
  int carry = a & b;        // Carry = A AND B

  digitalWrite(ledHalfSum, sum);
  digitalWrite(ledHalfCarry, carry);

  Serial.print("Half: ");
  Serial.print(a);
  Serial.print("+");
  Serial.print(b);
  Serial.print(" = ");
  Serial.print(carry);
  Serial.println(sum);
}

void fullAdder(int a, int b, int cin) {
  int sum = a ^ b ^ cin;              // Sum = A XOR B XOR Cin
  int carry = (a & b) | (cin & (a ^ b)); // Carry = (A.B) + (Cin.(A XOR B))

  digitalWrite(ledFullSum, sum);
  digitalWrite(ledFullCarry, carry);

  Serial.print("Full: ");
  Serial.print(a);
  Serial.print("+");
  Serial.print(b);
  Serial.print("+");
  Serial.print(cin);
  Serial.print(" = ");
  Serial.print(carry);
  Serial.println(sum);
}
