/*
  Control 12 LEDs with 4 pins
  Multiplexing but with 'input state' to disconnect some pins
  'Charlieplexing'

*/

int charlie_pins[] = {2, 3, 4, 5};

const int DISCONNECT = -1;

int pins[][11] = { {DISCONNECT, DISCONNECT, LOW, HIGH},
           {DISCONNECT, DISCONNECT, HIGH, LOW},
           {DISCONNECT, LOW, HIGH, DISCONNECT},
           {DISCONNECT, HIGH, LOW, DISCONNECT},
           {LOW, HIGH, DISCONNECT, DISCONNECT},
           {HIGH, LOW, DISCONNECT, DISCONNECT},
           {DISCONNECT, LOW, DISCONNECT, HIGH},
           {DISCONNECT, HIGH, DISCONNECT, LOW},
           {LOW, DISCONNECT, HIGH, DISCONNECT},
           {HIGH, DISCONNECT, LOW, DISCONNECT},
           {LOW, DISCONNECT, DISCONNECT, HIGH}, 
           {HIGH, DISCONNECT, DISCONNECT, LOW} };


const int ONE[] = {DISCONNECT, DISCONNECT, LOW, HIGH};
const int TWO[] = {DISCONNECT, DISCONNECT, HIGH, LOW};
const int THREE[] = {DISCONNECT, LOW, HIGH, DISCONNECT};
const int FOUR[] = {DISCONNECT, HIGH, LOW, DISCONNECT};
const int FIVE[] = {LOW, HIGH, DISCONNECT, DISCONNECT};
const int SIX[] = {HIGH, LOW, DISCONNECT, DISCONNECT};
const int SEVEN[] = {DISCONNECT, LOW, DISCONNECT, HIGH};
const int EIGHT[] = {DISCONNECT, HIGH, DISCONNECT, LOW};
const int NINE[] = {LOW, DISCONNECT, HIGH, DISCONNECT};
const int TEN[] = {HIGH, DISCONNECT, LOW, DISCONNECT};
const int ELEVEN[] = {LOW, DISCONNECT, DISCONNECT, HIGH};
const int TWELVE[] = {HIGH, DISCONNECT, DISCONNECT, LOW};


// Shortcut for setting mode of and digital level of the pins
void set_pin( int pin, int value){ 
  if (value == DISCONNECT){ 
    pinMode(pin, INPUT);
    digitalWrite(pin, LOW);
  }
  else if (value == LOW){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  else if (value == HIGH ){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}




// loop through 1-12 and set pins accordingly.
// send current number to serial port
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Awaiting 1st communication");   // send an initial string
    delay(300);
}

// the loop function runs over and over again forever
void loop() {

  for (int x = 1; x < 13; x++){
    Serial.print("Setting value: ");
    Serial.println(x);

    // essentially set pins as for current number x.
    // maybe abbreviate with 2D array later
    // set_pin( charlieplex[pin][x] )
    
    switch(x){
      case 1:
        set_pin(charlie_pins[0], ONE[0]);
        set_pin(charlie_pins[1], ONE[1]);
        set_pin(charlie_pins[2], ONE[2]);
        set_pin(charlie_pins[3], ONE[3]);
        //set_pins( 1 );
        break;
      case 2:
        set_pin(charlie_pins[0], TWO[0]);
        set_pin(charlie_pins[1], TWO[1]);
        set_pin(charlie_pins[2], TWO[2]);
        set_pin(charlie_pins[3], TWO[3]);
        break;
      case 3:
        set_pin(charlie_pins[0], THREE[0]);
        set_pin(charlie_pins[1], THREE[1]);
        set_pin(charlie_pins[2], THREE[2]);
        set_pin(charlie_pins[3], THREE[3]);
        break;
      case 4:
        set_pin(charlie_pins[0], FOUR[0]);
        set_pin(charlie_pins[1], FOUR[1]);
        set_pin(charlie_pins[2], FOUR[2]);
        set_pin(charlie_pins[3], FOUR[3]);
        break;
      case 5:
        set_pin(charlie_pins[0], FIVE[0]);
        set_pin(charlie_pins[1], FIVE[1]);
        set_pin(charlie_pins[2], FIVE[2]);
        set_pin(charlie_pins[3], FIVE[3]);
        break;
      case 6:
        set_pin(charlie_pins[0], SIX[0]);
        set_pin(charlie_pins[1], SIX[1]);
        set_pin(charlie_pins[2], SIX[2]);
        set_pin(charlie_pins[3], SIX[3]);
        break;
      case 7:
        set_pin(charlie_pins[0], SEVEN[0]);
        set_pin(charlie_pins[1], SEVEN[1]);
        set_pin(charlie_pins[2], SEVEN[2]);
        set_pin(charlie_pins[3], SEVEN[3]);
        break;
      case 8:
        set_pin(charlie_pins[0], EIGHT[0]);
        set_pin(charlie_pins[1], EIGHT[1]);
        set_pin(charlie_pins[2], EIGHT[2]);
        set_pin(charlie_pins[3], EIGHT[3]);
        break;
      case 9:
        set_pin(charlie_pins[0], NINE[0]);
        set_pin(charlie_pins[1], NINE[1]);
        set_pin(charlie_pins[2], NINE[2]);
        set_pin(charlie_pins[3], NINE[3]);
        break;
      case 10:
        set_pin(charlie_pins[0], TEN[0]);
        set_pin(charlie_pins[1], TEN[1]);
        set_pin(charlie_pins[2], TEN[2]);
        set_pin(charlie_pins[3], TEN[3]);
        break;
      case 11:
        set_pin(charlie_pins[0], ELEVEN[0]);
        set_pin(charlie_pins[1], ELEVEN[1]);
        set_pin(charlie_pins[2], ELEVEN[2]);
        set_pin(charlie_pins[3], ELEVEN[3]);
        break;
      case 12:
        set_pin(charlie_pins[0], TWELVE[0]);
        set_pin(charlie_pins[1], TWELVE[1]);
        set_pin(charlie_pins[2], TWELVE[2]);
        set_pin(charlie_pins[3], TWELVE[3]);
        break;

    }

    delay(3000);  // 3 second delay
  }

delay(10000);
}
