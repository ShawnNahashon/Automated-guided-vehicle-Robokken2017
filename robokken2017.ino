#include<Servo.h>

const int In1 = 52; //ClockWise Input For the first Set of wheels(Right Side)
const int In2 = 7; //Counter-Clockwise input for the first set of wheels(Right Side)
const int In3 = 5; //Clockwise input for the second set of wheels(Left Side)
const int In4 = 6; //Counter-Clockwise input for the Second Set of Wheels(Left Side)
const int En1 = 3; // Speed Input for the first set of wheels(Right Side)
const int En2 = 8; // Speed Input for the Second Set Of Wheels(Left Side)
int count = 0;

const int midPinB = A1;
const int sensorPin1 = A8;
const int sensorPin2 = A9;
const int sensorPin3 = A10;
const int sensorPin4 = A11;
const int sensorPin5 = A12;
const int midPinF = A13;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int midValF = 0;


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo leftg;
Servo rightg;
void setup()
{
  
  Serial.begin(9600);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  //////////////////
  base.attach(32);
  shoulder.attach(28);
  elbow.attach(40);
  wrist.attach(26);
  leftg.attach(22);
  rightg.attach(24);
  /////////////////////
  startingHome();
  delay(100);
}

void loop ()
{
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  sensorValue5 = analogRead(sensorPin5);
  midValF = analogRead(midPinF);

  //  Serial.println(sensorValue1);
  //  Serial.println(sensorValue2);
  //  Serial.println(sensorValue3);
  //  Serial.println(sensorValue4);
  //  Serial.println(sensorValue5);
  //  Serial.println("");
  //delay(500);

  linetrack(180);

  if ( sensorValue2 < 400 && sensorValue3 < 400 && sensorValue4 < 400)
  {
    linetrack(180);
    do
    {
      sensorValue2 = analogRead(sensorPin2);
      sensorValue3 = analogRead(sensorPin3);
      sensorValue4 = analogRead(sensorPin4);

    }

    while (sensorValue2 < 400 && sensorValue3 < 400 && sensorValue4 < 400 );

    do
    {
      sensorValue2 = analogRead(sensorPin2);
      sensorValue3 = analogRead(sensorPin3);
      sensorValue4 = analogRead(sensorPin4);


    }
    while (sensorValue2 > 400 && sensorValue3 > 400 && sensorValue4 > 400);
    count++;
    linetrack(180);
    Serial.println(count);
    
    
    if (count == 4)//16

    {
      moveMid();
      turnRight(255);
      forward(0);
      linetrack(180);
    }

    if (count == 16)
    {
      moveMid();
      forward(0);
      //reverse(155);
      delay(120);
      forward(0);
      turnRight(255);
      linetrack(180);
    }
    if (count == 20)

    {
      moveMid();
      forward(0);
      delay(200);
      turnLeft(255);
      //linetrack();
    }
    if (count == 24)
    {
      moveMidMore();
       pickBlue();
      delay(100);
      // linetrack();
    }

    if (count == 25)

    {
      moveMidMore();
      pickYellow();
      delay(100);
      linetrack(180);
    }
    if (count == 26)

    {
      moveMidMore();
      pickRed();
      delay(100);
      turnLeft(255);
      linetrack(180);
    }
    if (count == 33)
    {
      moveMid();
      turnLeft(255);
      linetrack(180);
    }
    if (count == 39)
    {
      moveMid();
      delay(200);
      turnRight(255);
      linetrack(180);
    }
    if (count == 40)
    {
      moveMid();
      delay(200);
      turnLeft(255);
      //linetrack();
    }

    if (count == 51)
    {
      moveMidMore();
      delay(200);
      forward(80);
      delay(250);
      forward(0);
      voteRed();
      homePosition();
      voteYellow();
      delay(100);
      homePosition();
      voteBlue();
      delay(100);
      homePosition();
      turnLeft(255);
      delay(100);
      turnLeft(255);
      delay(100);
      linetrack(20);
    }
    
    if (count == 53)
    {
      linetrack(20);
    }
    if (count == 54)
    {
      linetrack(20);
    }
    if (count == 55)
    {
      linetrack(20);
    }
    if (count == 56)
    {
      linetrack(20);
    }
    if (count == 57)
    {
      moveMid();
      delay(200);
      turnRight(255);
      delay(200);
      linetrack(20);
    }
    if (count == 65)
    {
      moveMid();
      delay(200);
      turnRight(255);
      delay(200);
      linetrack(180);
    }

    if (count == 72)
    {
      moveMid();
      delay(200);
      turnRight(255);
      forward(0);
      delay(10000);
      linetrack(180);
    }
    linetrack(180);
  }
}
void moveMid()
{
  forward(0);
  reverse(155);
  delay(100);
  forward(0);
  forward(80);
  delay(250);
  forward(0);
  delay(200);
}
void moveMidMore()
{
  forward(0);
  reverse(155);
  delay(100);
  forward(0);
  forward(80);
  delay(270);
  forward(0);
  delay(200);
}
void linetrack(int trackSpeed)
{
  takeReading();
  if (sensorValue3 < 400)
  {
    forward(trackSpeed);
    takeReading();
  }
  else
  {

    takeReading ();

  }
  if (sensorValue2 < 400 && sensorValue3 < 400)
  {
    forward(trackSpeed);
    takeReading ();
  }
  else
  {
    takeReading ();
  }
  if (sensorValue3 < 400 && sensorValue4 < 400)
  {
    forward(trackSpeed);
    takeReading ();
  }
  else
  {
    takeReading ();
  }
  if (sensorValue1 < 400)
  {
    leftReverse(150);
    rightForward(trackSpeed);
    takeReading ();
  }
  else
  {
    takeReading ();
  }
  if (sensorValue2 < 400)
  {
    rightForward(trackSpeed);
    leftForward(0);
    takeReading();
  }
  else
  {
    takeReading();
  }

  if (sensorValue4 < 400)
  {
    rightForward(0);
    leftForward(trackSpeed);
    takeReading();
  }

  else
  {
    takeReading();
  }
  if (sensorValue5 < 400)
  {
    leftForward(trackSpeed);
    rightReverse(150);
    takeReading();
  }
  else
  {
    takeReading();
  }
  if ( sensorValue2 > 400 && sensorValue3 < 400  && sensorValue4 > 400)
  {
    forward(trackSpeed);
    takeReading();
  }
  else
  {
    takeReading();
  }

  if (sensorValue2 < 400 && sensorValue3 < 400  && sensorValue4 < 400)
  {
    forward(trackSpeed );
    takeReading();
  }
  else
  {
    takeReading();
  }

}
void takeReading ()
{
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  sensorValue5 = analogRead(sensorPin5);
}
void offsetLeft(int turnSpeed)
{
  rightReverse(turnSpeed);
  leftForward(turnSpeed);

}
void offsetRight(int turnSpeed)
{
  rightForward(turnSpeed);
  leftReverse(turnSpeed);
}

void turnLeft(int turnSpeed)
{
  do
  {

    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    offsetRight(turnSpeed);
    delay(150);
  }
  while (!( sensorValue3));
  forward(0);
  delay(100);

  do
  {

    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;

    offsetRight(turnSpeed);
  }
  while (!(sensorValue3 == 0));
  forward(0);
  delay(300);

}
void turnRight(int turnSpeed)
{
  do
  {

    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    offsetLeft(turnSpeed);
    delay(200);
  }
  while (!( sensorValue3));
  forward(0);
  delay(100);

  do
  {

    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    offsetLeft(turnSpeed);
  }
  while (!(sensorValue3 == 0));
  forward(0);
  delay(300);

}


void rightForward(int rightSpeed)
{
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(En1, rightSpeed);

}
void rightReverse(int rightSpeed)
{
  digitalWrite(In3, LOW);//Clockwise motion of the right wheels
  digitalWrite(In4, HIGH);// anti-clockwise motion of the right side motors
  analogWrite(En1, rightSpeed);//LEFT SIDE SPEED
}
void leftForward(int leftSpeed)
{
  digitalWrite(In1, HIGH);//Clockwise motion of the right wheels
  digitalWrite(In2, LOW);//Turn off anti-clockwise motion of the right side motors
  analogWrite(En2, leftSpeed);//LEFT SIDE SPEED
}
void leftReverse(int leftSpeed)
{
  digitalWrite(In1, LOW);//Clockwise motion of the right wheels
  digitalWrite(In2, HIGH);//Turn off anti-clockwise motion of the right side motors
  analogWrite(En2, leftSpeed);//LEFT SIDE SPEED
}
void forward(int speedMove)
{
  rightForward(speedMove);
  leftForward(speedMove);
}
void reverse(int speedMove)
{
  rightReverse(speedMove);
  leftReverse(speedMove);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pickRed()
{
  homePosition();
  delay(10);
  getRed();
  delay(10);
  opengrip();
  delay(10);
  approach();
  delay(10);
  closegrip();
  delay(10);
  Return();
  delay(10);
  returnRed();
  delay(10);

  }
void pickYellow()
{
  homePosition();
  delay(100);
  getYellow();
  delay(100);
  opengrip();
  delay(100);
  approach();
 delay(100);
 closegrip();
 delay(100);
 Return();
 delay(100);
 returnYellow();
 delay(100);
 opengrip();
 delay(100);
 straight();
 }
void pickBlue()
{
  homePosition();
  delay(100);
  getBlue();
  delay(100);
  opengrip();
 delay(100);
  approach();
 delay(100);
 closegrip();
 delay(100);
  Return();
  delay(100);
  returnBlue();
  delay(100);
  opengrip();
  }
void homePosition()
{
  base.write(122); 
  shoulder.write(20);
  elbow.write(60);
  wrist.write(60);
  rightg.write(5);
  leftg.write(130);
  closegrip();
}

void approach()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 30, 83);
    elbow_move = map(angle_count, 0, 100, 55,70);
    wrist_move = map(angle_count, 0, 100, 30, 110);

    shoulder.write(shoulder_move);
    wrist.write(wrist_move);
    elbow.write(elbow_move);
    
    delay(10);
  }
}

void Return()
{

  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 83, 20);
    elbow_move = map(angle_count, 0, 100, 70, 80);
    wrist_move = map(angle_count, 0, 100, 110, 60);

    
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    shoulder.write(shoulder_move);
    delay(10);
}
}

void straight()
{
  elbow.write(60);
 }
void closegrip()
{
  int grip_angle, grip_left, grip_right;
  for (grip_angle=0; grip_angle<=10; grip_angle++)
  {
    grip_left=map(grip_angle, 0, 10, 130, 178); //176
    grip_right=map(grip_angle, 0, 10, 5, 27); //24

    leftg.write(grip_left);
    rightg.write(grip_right);
    delay(15);
  }
}

void opengrip()
{
   int  grip_angle, grip_left, grip_right;
  for (grip_angle=0; grip_angle<=10; grip_angle++)
  {
    grip_left=map(grip_angle, 0, 10, 175, 130);
    grip_right=map(grip_angle, 0, 10, 20, 5);

    leftg.write(grip_left);
    rightg.write(grip_right);
    delay(15);
}}
void getBlue()
{ 
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 125, 41);
  
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnBlue()
{ 
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++){
  baseAngle = map(angleCount, 0, 100, 44, 119);
  base.write(baseAngle); 
  delay(10);
  } 
}

void getYellow()
{  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 125, 41);
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnYellow()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 44, 98);
  base.write(baseAngle); 
  delay(10);
  } 
}

void getRed()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 100, 125, 41);
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnRed()
{ 
int baseAngle, angleCount;
int elbowAngle;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 46, 125); 
  elbowAngle = map(angleCount, 0, 100, 60, 60);
  base.write(baseAngle); 
  delay(10);
  elbow.write(elbowAngle);
  } 
}

void goRedBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 100, 80, 137);
  base.write(baseAngle); 
  delay(10);
  } 
}
void goYellowBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 165, 150);
  base.write(baseAngle); 
  delay(10);
  } 
 
}

void goBlueBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++){
  
  baseAngle = map(angleCount, 0, 100, 80, 150);
  base.write(baseAngle); 
  delay(10);
  } 
 
}

void pickVote()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 90, 100);
    elbow_move = map(angle_count, 0, 100, 60, 40);
    wrist_move = map(angle_count, 0, 100, 60, 40);

    shoulder.write(shoulder_move);
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    delay(10);
  }

  closegrip();
}


void approachBallotBox()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 20, 55);
    elbow_move = map(angle_count, 0, 100, 60, 60);
    wrist_move = map(angle_count, 0, 100, 60, 120);
    base_move = map(angle_count, 0, 100, 137, 130);
    shoulder.write(shoulder_move);
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    base.write(base_move);
    delay(10);
  }
}

void ReturnFromBallotBox()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 130, 100);
    elbow_move = map(angle_count, 0, 100, 50, 60);
    wrist_move = map(angle_count, 0, 100, 90, 50);

    shoulder.write(shoulder_move);
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    delay(10);
}

  
}

void voteRed()
{
  approachBallotBox();
  delay(500);
  opengrip();
  delay(500); 
}

void voteYellow()
{
  returnYellow();
  delay(500);
  funguagripYellow();
  delay(500);
  base.write(98);
  chukuaYellow();
  closegrip();
  delay(500);
 closegrip();
  delay(500);
  elbow.write(50);
  delay(500);
  wekaYellow();
  delay(500);
  opengrip();
  delay(500);
}

void voteBlue()
{
opengrip();
delay(500);
chukuaBlue();
delay(500);
closegrip();
delay(500);
elbow.write(70);
delay(500);
wekaBlue();
delay(500);
opengrip();
delay(500);
}

void chukuaYellow ()
{
  int baseAngle,angle_count,elbow_move,wrist_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
  //baseAngle = map(angleCount, 0, 100, 70, 119);
   elbow_move = map(angle_count, 0, 100, 60,97   );
   wrist_move = map(angle_count, 0, 100, 60,42);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
  
  delay(10);
  } 
  closegrip();
}

void wekaYellow ()
{
  int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
   baseAngle = map(angle_count, 0, 100, 137,110 );
   elbow_move = map(angle_count, 0, 100, 60,48 );
   wrist_move = map(angle_count, 0, 100, 60,115);
   shoulder_move = map(angle_count, 0, 100, 20,59);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
}
}
void funguagripYellow()
{
 
  int  grip_angle, grip_left, grip_right;
  for (grip_angle=0; grip_angle<=10; grip_angle++)
  {
    grip_left=map(grip_angle, 0, 10, 175, 170);
    grip_right=map(grip_angle, 0, 10, 20, 1);

    leftg.write(grip_left);
    rightg.write(grip_right);
    delay(15);
} 
}
void chukuaBlue()
{
    int baseAngle,angle_count,elbow_move,wrist_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
  baseAngle = map(angle_count, 0, 100, 125, 129);
   elbow_move = map(angle_count, 0, 100, 60,96);
   wrist_move = map(angle_count, 0, 100, 60,49);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   base.write(baseAngle);
  
  delay(10);
  } 
  closegrip();
}

void wekaBlue()
{
  int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
   baseAngle = map(angle_count, 0, 100, 137,92);
   elbow_move = map(angle_count, 0, 100, 60,65);
   wrist_move = map(angle_count, 0, 100, 60,160);
   shoulder_move = map(angle_count, 0, 100, 20,70);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
} 
}

void startingHome()
{
   base.write(116); 
  shoulder.write(10);
  elbow.write(145);
  wrist.write(177);
  rightg.write(5);
  leftg.write(130);
  closegrip();
}





