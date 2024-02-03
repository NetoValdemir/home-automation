void setup() {
 pinMode(6,OUTPUT);//Relé Ventilador
 pinMode(7,OUTPUT);//Relé Lampada
 pinMode(A0,INPUT);//Sensor Ventilador
 pinMode(A1,INPUT);//Sensor Lampada
 pinMode(10,INPUT);//Botao automatico/manual
 pinMode(11,INPUT);//Botão Liga/Desliga Ventilador
 pinMode(12,INPUT);//Botão Liga/Desliga Lampada
 int flag = 1;
}

void Modo_Auto()
{
  if(digitalRead(11)== LOW || digitalRead(12) == LOW)
  {
  if(analogRead(A0)>345)//Leitura do Sensor do Ventilador
{
  digitalWrite(6,1);
  }
  else{
    digitalWrite(6,0);
    }
  if(analogRead(A1)>345)//Leitura do Sensor da Lampada
{
  digitalWrite(7,1);
  }
  else{
    digitalWrite(7,0);
    }
  flag = 1;
  }
  flag = 0;
  }

  void Modo_Manual()
  {
    if(digitalRead(11))//Acionamento manual do Ventilador
    {
      digitalWrite(6,1);
      }
      if(digitalRead(12))//Acionamento manual da lâmpada
    {
      digitalWrite(7,1);
      }
     if(digitalRead(10))
     {
      flag = 1;
      }
    }
  
void loop() {
  if (flag == 1){
  Modo_Auto();
  }
    Modo_Manual();
}
