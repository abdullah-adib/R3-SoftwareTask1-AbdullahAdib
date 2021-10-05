// C++ code
//
// Assign names for pins to make it easier to track
int potPin = A5;                                    // Pin initialized for the 
int SA1 = 6, SA2 = 7, SA3 = 8, SA4 = 9;             // Pins used to connect to 1st decoder
int SB1 = 2, SB2 = 3, SB3 = 4, SB4 = 5;             // Pins used to connect to 2nd decoder
int onesDigit, tensDigit;

// Initialize pins as input and output 
void setup()
{
  pinMode(potPin, INPUT);
  pinMode(SA1, OUTPUT);
  pinMode(SA2, OUTPUT);
  pinMode(SA3, OUTPUT);
  pinMode(SA4, OUTPUT);
  pinMode(SB1, OUTPUT);
  pinMode(SB2, OUTPUT);
  pinMode(SB3, OUTPUT);
  pinMode(SB4, OUTPUT);
  Serial.begin(9600);
}

// The instruction that is carried out for as long as the circuit is running
void loop()
{
  int potMeasure = analogRead(A5);                  // Reads input from the potentiometer
  potMeasure = map(potMeasure, 0, 1023, 0, 99);     // Built in map function rescales 0 to 1023 scale to 0 to 99 scale
  Serial.println(potMeasure);                       // Was used to display on serial screen during debugging 
  onesDigit = potMeasure%10;                        // Splices two digit number to get the ones digits
  tensDigit = (potMeasure/10)%10;                   // Splices two digit number to get the tens digits
  leftSSEG(tensDigit);                              // Calls function for the left sseg and passes the tens digit
  rightSSEG(onesDigit);                             // Calls function for the right sseg and passes ones digit
}

// Uses switch cases to map each digit from 0-9 with a combination of high's and lows for the signals that is read by the decoder
void rightSSEG(int onesDigit)
{
  switch (onesDigit)
  {
    case 0:		//0000	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, LOW);
    digitalWrite(SB2, LOW);
    digitalWrite(SB1, LOW);
    break;
    
    case 1:		//0001	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, LOW);
    digitalWrite(SB2, LOW);
    digitalWrite(SB1, HIGH);
    break;
    
    case 2:		//0010	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, LOW);
    digitalWrite(SB2, HIGH);
    digitalWrite(SB1, LOW);
    break;
    
    case 3:		//0011	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, LOW);
    digitalWrite(SB2, HIGH);
    digitalWrite(SB1, HIGH);
    break;
    
    case 4:		//0100	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, HIGH);
    digitalWrite(SB2, LOW);
    digitalWrite(SB1, LOW);
    break;
    
    case 5:		//0101	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, HIGH);
    digitalWrite(SB2, LOW);
    digitalWrite(SB1, HIGH);
    break;
    
    case 6:		//0110	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, HIGH);
    digitalWrite(SB2, HIGH);
    digitalWrite(SB1, LOW);
    break;
    
    case 7:		//0111	
    digitalWrite(SB4, LOW);
    digitalWrite(SB3, HIGH);
    digitalWrite(SB2, HIGH);
    digitalWrite(SB1, HIGH);
    break;
    
    case 8:		//1000	
    digitalWrite(SB4, HIGH);
    digitalWrite(SB3, LOW);
    digitalWrite(SB2, LOW);
    digitalWrite(SB1, LOW);
    break;
    
    case 9:		//1001	
    digitalWrite(SB4, HIGH);
    digitalWrite(SB3, LOW);
    digitalWrite(SB2, LOW);
    digitalWrite(SB1, HIGH); 
    break;
  }
}

// Same process as right sseg but passes tenDigit variable instead
void leftSSEG(int tensDigit)
{
  switch (tensDigit)
  {
    case 0:		//0000	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, LOW);
    digitalWrite(SA2, LOW);
    digitalWrite(SA1, LOW);
    break;
    
    case 1:		//0001	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, LOW);
    digitalWrite(SA2, LOW);
    digitalWrite(SA1, HIGH);
    break;
    
    case 2:		//0010	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, LOW);
    digitalWrite(SA2, HIGH);
    digitalWrite(SA1, LOW);
    break;
    
    case 3:		//0011	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, LOW);
    digitalWrite(SA2, HIGH);
    digitalWrite(SA1, HIGH);
    break;
    
    case 4:		//0100	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, HIGH);
    digitalWrite(SA2, LOW);
    digitalWrite(SA1, LOW);
    break;
    
    case 5:		//0101	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, HIGH);
    digitalWrite(SA2, LOW);
    digitalWrite(SA1, HIGH);
    break;
    
    case 6:		//0110	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, HIGH);
    digitalWrite(SA2, HIGH);
    digitalWrite(SA1, LOW);
    break;
    
    case 7:		//0111	
    digitalWrite(SA4, LOW);
    digitalWrite(SA3, HIGH);
    digitalWrite(SA2, HIGH);
    digitalWrite(SA1, HIGH);
    break;
    
    case 8:		//1000	
    digitalWrite(SA4, HIGH);
    digitalWrite(SA3, LOW);
    digitalWrite(SA2, LOW);
    digitalWrite(SA1, LOW);
    break;
    
    case 9:		//1001	
    digitalWrite(SA4, HIGH);
    digitalWrite(SA3, LOW);
    digitalWrite(SA2, LOW);
    digitalWrite(SA1, HIGH); 
    break;
  }
}

  
