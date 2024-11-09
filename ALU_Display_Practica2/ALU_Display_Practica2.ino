int w = 0;
int x = 0;
int y = 0;
int z = 0;
int EstadoA = 0;
int EstadoB = 0;

void setup() {
//pines del display (prende autom.)
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
//puertos botones
  pinMode(18, INPUT); 
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  pinMode(17, INPUT);//A
  pinMode(16, INPUT);//B  
}

void loop() {
  //uno();
  //cero();
  //dos();
 //menos();
 //low();//deberia llamarse high xd
 //infinito();
 //indefinido();

  //digitalWrite (2, LOW);
 //digitalWrite (3, LOW);
  //digitalWrite (4, LOW);
  // digitalWrite (5, LOW);
  //digitalWrite (6, LOW);
  //digitalWrite (7, LOW);
  //digitalWrite (8, LOW);
  /*
18 a 21 botones
17 A y 16 B
2 a 8 pines display
NI MOO, EL HIGH ES LOW Y AL REVES (ánodo)
  */
  EstadoA = digitalRead(17);//A
  EstadoB = digitalRead(16);//B
  w = digitalRead(21);//suma
  x = digitalRead(20);//resta
  y = digitalRead(19);//div
  z = digitalRead(18);
// suma
  if (!z && !y && !x && w){
    if (EstadoA ^ EstadoB){
      uno();//0+1, 1+0
    } else if (EstadoA && EstadoB){
      dos();//1+1
    } else {
      cero();//0+0
    }
  }
//retsa
  if (!z && !y && x && !w) {
    if (EstadoA && !EstadoB){
      uno();//1-0
    } else if (!EstadoA && EstadoB){
      menos();//0-1
    } else {
      cero();//0-0, 1-1
    }
  }
  //mult
  if (!z && !y && x && w) {
    if (EstadoA && EstadoB) {
      uno();
    } else {
      cero();
    }
  }
  //div
  if ((EstadoA && EstadoB)&&(!z && y && !x && !w)) {
    uno();
  }
  if ((!EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    indefinido();
  }
  if ((EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    infinito();
  }
  if ((!EstadoA && EstadoB)&&(!z && y && !x && !w)){
    cero();
  }

//compuertas, and
  if(!z && y && !x && w){
    if(EstadoA && EstadoB){
      uno();
    }
  }
  //or
  if ((EstadoA || EstadoB) && (!z && y && x && !w)) {
    uno();
  }
  //not (sin estado B)
  if (!EstadoA && (!z && y && x && w)) {
    uno();
  }
  //xor
  if ((EstadoA ^ EstadoB) && (z && !y && !x && !w)) {
    uno();
  }
  //xnor
  if (!(EstadoA ^ EstadoB) && (z && !y && !x && w)) {
    uno();
  }
  //nand
  if (!(EstadoA && EstadoB) && (z && !y && x && !w)) {
    uno();
  }
  //nor
  if (!(EstadoA || EstadoB) && (z && !y && x && w)) {
    uno();
  }
//00 = 0
//10 = 01
//01 = 01
//11 = 10
}//loop

//ops del display (ánodo)
  void uno(){
  digitalWrite(2, LOW);
 digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, LOW);
  digitalWrite (6, HIGH);
 digitalWrite (7, HIGH);
  digitalWrite (8, HIGH);
}

void low(){//LOS HIGH SON LOW
  digitalWrite(2, HIGH);
 digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, HIGH);
  digitalWrite (6, HIGH);
 digitalWrite (7, HIGH);
  digitalWrite (8, HIGH);
}

void cero (){
  digitalWrite(2, LOW);
 digitalWrite (3, LOW);
  digitalWrite (4, HIGH);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
 digitalWrite (7, LOW);
  digitalWrite (8, LOW);
}

void dos(){
  digitalWrite(2, LOW);
 digitalWrite (3, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, HIGH);
  digitalWrite (6, LOW);
 digitalWrite (7, LOW);
  digitalWrite (8, HIGH);
}
void menos(){
  digitalWrite(2, LOW);
 digitalWrite (3, HIGH);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);
  digitalWrite (6, HIGH);
 digitalWrite (7, HIGH);
  digitalWrite (8, HIGH);
}
void infinito(){
  digitalWrite(2, LOW);
 digitalWrite (3, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
 digitalWrite (7, LOW);
  digitalWrite (8, LOW);
}
void indefinido(){
  digitalWrite(2, HIGH);
 digitalWrite (3, HIGH);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
 digitalWrite (7, LOW);
  digitalWrite (8, HIGH);
}