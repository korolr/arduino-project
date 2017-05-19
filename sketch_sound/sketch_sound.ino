int soundDetectedPin = 10; 
int soundDetectedVal = HIGH; 
boolean bAlarm = false;

unsigned long lastSoundDetectTime; 


int soundAlarmTime = 500;


void setup ()
{
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; 
}
void loop ()
{
  soundDetectedVal = digitalRead (soundDetectedPin) ;
  
  if (soundDetectedVal == LOW) 
  {
  
    lastSoundDetectTime = millis(); 
    if (!bAlarm){
      Serial.println("LOUD, LOUD");
      bAlarm = true;
    }
  }
  else
  {
    if( (millis()-lastSoundDetectTime) > soundAlarmTime  &&  bAlarm){
      Serial.println("quiet");
      bAlarm = false;
    }
  }
}
