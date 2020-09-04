#define data 51
#define clock 52
#define LE1 49
#define LE2 53
#define NS1 5
#define NS2 10

byte zero =  B11111111;
byte one =   B01100000;
byte two =   B11011010;
byte three = B11110010;
byte four =  B01100110;
byte five =  B10110110;
byte six =   B00111110;
byte seven = B11100000;

// 0-DP-N-M-L-K-J-H-G2-G1-F-E-D-C-B-A

byte numbers[20] =  {B00000000, B00111111, B00010000, B01000000, B00000011, B00011011, B00000011, B00001111, B00000011, B00100110, 
                    B00000011, B00101101, B00000011, B00111101, B00000000, B00000111, B00000011, B00111111, B00000011, B00100111};
byte test[2] ={B00000000, B00000001};

void setup()
{
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output3
  digitalWrite(NS1, LOW);
  digitalWrite(NS2, LOW);
}

void loop()
{
  for(byte i =0; i< sizeof(numbers) ; i+=2){
    digitalWrite(LE1, HIGH);
    digitalWrite(LE2, HIGH);
    shiftOut(data, clock, MSBFIRST, numbers[i]);
    shiftOut(data, clock, MSBFIRST, numbers[i+1]);
    delay(500);
    digitalWrite(LE1, LOW);
    digitalWrite(LE2,LOW);
  }
}
