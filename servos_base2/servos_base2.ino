#include <Servo.h>
 
Servo myservox;  // crea el objeto servo
Servo myservoy;
int posy=90;    // posicion del servo
int posx=90;
int lectura=0;
void setup() {
   Serial.begin(9600);
   myservoy.attach(9);  // vincula el servo al pin digital 9
   myservox.attach(6);
   myservoy.write(posy);
   myservox.write(posx);

}
 
void loop() {
   if(Serial.available()>=1){
      lectura =Serial.read(); 
    }
   //varia la posicion de 0 a 180, con esperas de 15ms
   if (lectura=='D') 
   {
      posy=posy+1;
      myservoy.write(posy);              
      delay(500);
   }
   
   if (lectura=='U') 
   {
     posy=posy-1;
      myservoy.write(posy);              
      delay(500);     
   }

   if (lectura=='L') 
   {
      posx=posx+1;
      myservox.write(posx);              
      delay(500);           
   }
   
   if (lectura=='R') 
   {
        posx=posx-1;
        myservox.write(posx);              
        delay(500);                       
   }
   
}
