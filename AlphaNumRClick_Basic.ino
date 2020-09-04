#define data 51
#define clock 52
#define LE1 49
#define LE2 53
#define NS1 5
#define NS2 10

//14 Segment LED is made up of two bits. Here are the specific LEDs: 0-DP-N-M-L-K-J-H-G2-G1-F-E-D-C-B-A

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

//Cycles through numbers 0-9
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
