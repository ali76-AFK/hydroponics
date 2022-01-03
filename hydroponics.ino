int pinphp=10;//ph+
int pinphm=9;//ph-
int pinfn=8;//fertilizer and urea
int pinmixer=7;//mixer
int pinled=6;
int pinplantpipeIR=A0;
int pinturb=A1;
int pintankIR=A2;
int pinph=A3;
int pinlight=A4;
int pintemp=A5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
pinMode(pinphp,OUTPUT);
pinMode(pinphm,OUTPUT);
pinMode(pinfn,OUTPUT);
pinMode(pinmixer,OUTPUT);
pinMode(pinled,OUTPUT);
pinMode(pinplantpipeIR,INPUT);
pinMode(pinturb,INPUT);
pinMode(pintankIR,INPUT);
pinMode(pinph,INPUT);
pinMode(pinlight,INPUT);
pinMode(pintemp,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
int plantpipeIR = 0, turb=0, tankIR=0, ph=0, light=0;
int x=0, pumpphp=0, mixer=0,pumpphm=0,led=0, pumpfn=0;
int temp=0;
plantpipeIR= analogRead(pinplantpipeIR);
turb= analogRead(pinturb);
tankIR= analogRead(pintankIR);
ph=analogRead(pinph);
light= analogRead(pinlight);
temp = analogRead(pintemp);


Serial.print("water level in the plant container");
x = 9-(plantpipeIR * (5/1023));
if(x<3){
  Serial.print("water level is ");
  Serial.println(x);
Serial.println("there is a water drop in the system due to clogging in the pipe");
}
else{
  Serial.print("water level is ");
  Serial.println(x);
  }

x=0;
x= turb * (250/1023);

if(x<30)
{Serial.print("water turbidity level ");
Serial.println(x);
  Serial.println("water quality is adeqet");}
  
else{Serial.println("water isnt compatible anymore, changing is required");}

x = 0;
//

x=0;
x = ph * (14/1023);

if(x<7 && x>6){
  Serial.print("water ph level is ");
  Serial.println(x);
  Serial.println("the water ph level is compatible");
  }
else if(x<6){
  digitalWrite(pumpphp,1);
  delay(1000);
  digitalWrite(pumpphp,0);
  delay(2000);
  digitalWrite(mixer,1);
  delay(5000);
  digitalWrite(mixer,0);
  }
   if(x>7){
  digitalWrite(pumpphm,1);
  delay(1000);
  digitalWrite(pumpphm,0);
  delay(2000);
  digitalWrite(mixer,1);
  delay(5000);
  digitalWrite(mixer,0);
  }

x=0;

if(light<300){
  Serial.print("light intensity level is  ");
  Serial.println(light);
  digitalWrite(led,0);
  }

  if(light>800){
    Serial.print("light intensity is ");
    Serial.println(light);
    digitalWrite(led,1);
  }
  

  x=0;
 x= temp * (100/1023);
if(x>20 && x<27){
  Serial.print("the temperature is compatible which is ");
  Serial.println(x);
  }

 else if(x<20){
    Serial.print("temperature is low, around");
    Serial.println(x);
//    digitalWrite();//turn on the heater
    }
    else{
    Serial.print("temperature is high, around");
    Serial.println(x);
//    digitalWrite();//turn on the cooler
    }
int fn=0;
  Serial.println("how many drops of ferilizer + nitrogen");
  while(Serial.available()>0){
     fn = Serial.read();
  }
int i = 0;
  for(i=0;i<=fn;i++){
    
    digitalWrite(pumpfn,1);
    delay(1000);
    digitalWrite(pumpfn,0);
    }
int php=0;
   Serial.println("how many drops of ph+");
  while(Serial.available()>0){
     php = Serial.read();
  }
 i = 0;
  for(i=0;i<=php;i++){
    
    digitalWrite(pumpphp,1);
    delay(1000);
    digitalWrite(pumpphp,0);
    }
int phm=0;
   Serial.println("how many drops of ph-");
  while(Serial.available()>0){
     phm = Serial.read();
  }
 i = 0;
  for(i=0;i<=phm;i++){
    
    digitalWrite(pumpphm,1);
    delay(1000);
    digitalWrite(pumpphm,0);
    }




    
    }
    
