


#define speed 250
#define IN1_dr1 6
#define IN2_dr2 5
#define IN3_st1 9
#define IN4_st2 10
int x = 50;
int y = 50;

  
void setup() {
  
  Serial.begin(115200);
  // Blynk.begin(auth, ssid, pass);
   //WiFi.begin(ssid, pass);
  pinMode(IN1_dr1, OUTPUT);
  pinMode(IN2_dr2, OUTPUT);
  pinMode(IN3_st1, OUTPUT);
  pinMode(IN4_st2, OUTPUT);

  
}

    
void loop() {
  if (Serial.available() >=2) {
        // Read data from the NODEMCU
      /*  String data = Serial.readString();
        Serial.print("R:");
        // Parse the data and extract the values of x and y
        int x = data.substring(3, data.indexOf("X")).toInt();
        int y = data.substring(data.indexOf("Y") + 2).toInt();
        */
         x = Serial.read();
         y = Serial.read();
         /*Serial.print("X: ");
         Serial.println(x);
         Serial.print("Y: ");
         Serial.println(y);
        */
  smartcar();// Call the main function
}}
void smartcar() {
  if (y > 70) {
    carForward();
    //Serial.println("carForward");
  } else if (y < 30) {
    carBackward();
    //Serial.println("carBackward");
  } else if (x < 30) {
    carLeft();
    //Serial.println("carLeft");
  } else if (x > 70) {
    carRight();
    //Serial.println("carRight");
  } else if (x < 70 && x > 30 && y < 70 && y > 30) {
    carStop();
    //Serial.println("carstop");
  }
}

/**************Motor movement functions*****************/
void carForward() {
  /*analogWrite(IN1_dr1, Speed);
  analogWrite(IN4_st2, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);*/
   digitalWrite(IN1_dr1, 0);
   analogWrite(IN2_dr2, speed);
   digitalWrite(IN3_st1, 0);
   analogWrite(IN4_st2, speed);
  
}
void carBackward() {
  analogWrite(IN1_dr1, speed);
  digitalWrite(IN2_dr2, 0);
  analogWrite(IN3_st1, speed);
  digitalWrite(IN4_st2, 0); 
}
void carLeft() {
  analogWrite(IN1_dr1, speed);
  digitalWrite(IN2_dr2, 0);
  digitalWrite(IN3_st1, 0);
  analogWrite(IN4_st2, speed); 
}
void carRight() {
 digitalWrite(IN1_dr1, 0);
 analogWrite(IN2_dr2, speed);
 analogWrite(IN3_st1, speed);
 digitalWrite(IN4_st2, 0);
}
void carStop() {
  digitalWrite(IN1_dr1, 0);
  digitalWrite(IN2_dr2, 0);
  digitalWrite(IN3_st1, 0);
  digitalWrite(IN4_st2, 0); 
}
