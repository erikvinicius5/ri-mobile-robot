const int PinL = 2;
const int PinC = 3;
const int PinR = 4;

int PinoVelocidade = 7;//3; //Ligado ao pino 1 do L293D 
int PinoVelocidade2 = 9;//5; 
int Entrada1 = 6;//2; //Ligado ao pino 2 do L293D  
int Entrada2 = 11;//7; //Ligado ao pino 7 do L293D  
int Entrada3 = 8;//4;
int Entrada4 = 10;//6;

int velocidade = 700;
int reducao = 700;

int LState = 0;
int CState = 0;
int RState = 0; 

void setup() {
 Serial.begin(9600);
 pinMode(PinL, INPUT);
 pinMode(PinC, INPUT);
 pinMode(PinR, INPUT);
 pinMode(PinoVelocidade, OUTPUT);
 pinMode(Entrada1, OUTPUT);  
 pinMode(Entrada2, OUTPUT); 
 pinMode(PinoVelocidade2, OUTPUT);
 pinMode(Entrada3, OUTPUT);  
 pinMode(Entrada4, OUTPUT); 
}
void loop() {
 LState = digitalRead(PinL);
 CState = digitalRead(PinC);
 RState = digitalRead(PinR);
 
 
 if ((CState == HIGH) && (RState == LOW && LState == LOW)) {
   avante();
 }else{
     if(CState == HIGH && RState == HIGH && LState == HIGH){
       parar();
     }else{
       giro();
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
  liga();
  analogWrite(PinoVelocidade, velocidade);   
  analogWrite(PinoVelocidade2, velocidade - reducao);
}

void giroEsquerda(){
    Serial.println("Reduz Motor da Direita"); 
    liga();
    analogWrite(PinoVelocidade, velocidade - reducao);   
    analogWrite(PinoVelocidade2, velocidade);   
}

void avante(){
    liga();
    Serial.println("Velocidade Constante nos 2 motores");   
    analogWrite(PinoVelocidade, velocidade);   
    analogWrite(PinoVelocidade2, velocidade);     
}

void liga(){
   digitalWrite(Entrada1, LOW);  
   digitalWrite(Entrada2, HIGH);
   digitalWrite(Entrada3, LOW);  
   digitalWrite(Entrada4, HIGH);
}

void parar(){
    Serial.println("Para os 2 motores");       
    digitalWrite(Entrada1, LOW);  
    digitalWrite(Entrada2, LOW);   
    digitalWrite(Entrada3, LOW);  
    digitalWrite(Entrada4, LOW);   
}

