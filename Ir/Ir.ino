const int PinL = 2;
const int PinC = 3;
const int PinR = 4;
int LState = 0;
int CState = 0;
int RState = 0; 
void setup() {
 Serial.begin(9600);
 pinMode(PinL, INPUT);
 pinMode(PinC, INPUT);
 pinMode(PinR, INPUT);
}
void loop() {
 LState = digitalRead(PinL);
 CState = digitalRead(PinC);
 RState = digitalRead(PinR);
 
 if ((CState == HIGH) && (RState == LOW && LState == LOW)) {
   avante();
 }else{
   if (CState == LOW) {
     giro();     
   }else{
     if(RState == HIGH && LState == HIGH){
       parar();
     }else{
       giro();
     }
   }
 }

}

void giro(){
  if(RState == HIGH){
    giroDireita();
  }else{
    if(LState == HIGH){
      giroEsquerda();
    }else{
      parar();
    }       
  }
}

void giroDireita(){
  Serial.println("Reduz Motor da Esquerda"); 
}

void giroEsquerda(){
    Serial.println("Reduz Motor da Direita"); 
}

void avante(){
    Serial.println("Velocidade Constante nos 2 motores");   
}

void parar(){
    Serial.println("Para os 2 motores");   
}

