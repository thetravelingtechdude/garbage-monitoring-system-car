// Robot wheel Controls(M1, M2)
#define m1 2
#define m2 3
#define m3 4
#define m4 5

// Robot Arm Control(M3, M4)
#define m5 6
#define m6 7
#define m7 8
#define m8 9

char data = 0;//Variable for storing received data

void setup()
{
    Serial.begin(9600);   //Sets the baud rate for serial data transmission                               
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

    // ARM control Pins
    pinMode(6, OUTPUT);  
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
}

void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == '1')
      {              
         digitalWrite(2, HIGH);   // Run Forward
         digitalWrite(3, LOW);
         digitalWrite(4, HIGH);   
         digitalWrite(5, LOW);
      }      
      else if(data == '2')         //  Checks whether value of data is equal to 0
      {
         digitalWrite(2, LOW);   // Run Reverse
         digitalWrite(3, HIGH);
         digitalWrite(4, LOW);   
         digitalWrite(5, HIGH);
      }
         else if(data == '3')
         {
         digitalWrite(2, HIGH);   // Right Turn
         digitalWrite(3, LOW);
         digitalWrite(4, HIGH);   
         digitalWrite(5, HIGH);
         }
         else if(data == '4')
         {
         digitalWrite(2, HIGH);   // Left Turn
         digitalWrite(3, HIGH);
         digitalWrite(4, HIGH);   
         digitalWrite(5, LOW);
         }
         else if (data == '5')
         {
         digitalWrite(6, HIGH);   // UP
         digitalWrite(7, LOW);
         digitalWrite(8, HIGH);    
         digitalWrite(9, HIGH);     
         }
          else if(data == '6')
         {
         digitalWrite(6, LOW);   // DOWN
         digitalWrite(7, HIGH);
         digitalWrite(8, HIGH);   
         digitalWrite(9, HIGH);       
         }
         else if(data == '7')
         {
         digitalWrite(6, HIGH);   // OPEN
         digitalWrite(7, HIGH);
         digitalWrite(8, HIGH);   
         digitalWrite(9, LOW);
         }
         else if(data == '8')
         {
         digitalWrite(6, HIGH);   // CLOSE
         digitalWrite(7, HIGH);
         digitalWrite(8, LOW);   
         digitalWrite(9, HIGH);
         }
         else if(data == '0'){
         digitalWrite(2, HIGH);   // STOP
         digitalWrite(3, HIGH);
         digitalWrite(4, HIGH);   
         digitalWrite(5, HIGH);
         digitalWrite(6, HIGH);  
         digitalWrite(7, HIGH);
         digitalWrite(8, HIGH);   
         digitalWrite(9, HIGH);
          }
   }
}
