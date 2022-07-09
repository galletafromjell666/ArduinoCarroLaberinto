#include <robot_car_arduino.h>
Carro carrito;
int detener = 12; //distancia en que el carrito se detiene
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  carrito.potenciaMAX = 210; // potencia maxima
}

void loop()
{
  carrito.mover(0, 0);
  int izquierdaUltra = carrito.UltraI.medirCM();
  int centroUltra = carrito.UltraC.medirCM();
  int derechaUltra = carrito.UltraD.medirCM();

  Serial.print("Izquierda = ");
  Serial.print(izquierdaUltra);
  Serial.print(" Centro = ");
  Serial.print(centroUltra);
  Serial.print(" Derecha = ");
  Serial.println(derechaUltra);
  // INICIO CORRECIONES
  if (centroUltra == 0 || derechaUltra == 0 || izquierdaUltra == 0) {
    Serial.println("algun sensor marca 0, repitiendo lectura para corroborar");
    if (derechaUltra == 0) {
      //retrocede y se mueve a la izquierda
      carrito.mover(-10, -9);
      delay(250);
      carrito.mover(0, 0);
      delay(100);
      carrito.mover(-10, 9);
      delay(300);
      carrito.mover(0, 0);
      delay(100);
      izquierdaUltra = carrito.UltraI.medirCM();
      centroUltra = carrito.UltraC.medirCM();
      derechaUltra = carrito.UltraD.medirCM();
    }
    if (izquierdaUltra == 0) {
      //retrocede y se mueve a la derecha
      carrito.mover(-10, -9);
      delay(250);
      carrito.mover(0, 0);
      delay(100);
      carrito.mover(10, -9);
      delay(300);
      carrito.mover(0, 0);
      delay(100);
      izquierdaUltra = carrito.UltraI.medirCM();
      centroUltra = carrito.UltraC.medirCM();
      derechaUltra = carrito.UltraD.medirCM();
    }
    if (centroUltra == 0) {
      //solo retrocede
      carrito.mover(-10, -9);
      delay(250);
      carrito.mover(0, 0);
      delay(200);
      izquierdaUltra = carrito.UltraI.medirCM();
      centroUltra = carrito.UltraC.medirCM();
      derechaUltra = carrito.UltraD.medirCM();

    }
  }

  Serial.print("Izquierda = ");
  Serial.print(izquierdaUltra);
  Serial.print(" Centro = ");
  Serial.print(centroUltra);
  Serial.print(" Derecha = ");
  Serial.println(derechaUltra);
  //FIN DE CORRECIONES
  if (centroUltra < detener && derechaUltra < detener && izquierdaUltra < detener)
  {
    // obstaculo en todos lados
    Serial.println("A giro derecha");

    carrito.mover(10, -9);
    delay(300);
    carrito.mover(0, 0);
    delay(200);
  }
  else if (centroUltra < detener && derechaUltra < detener && izquierdaUltra > detener)
  {
    // obscatuclo frente y derecha
    Serial.println("B giro izquierda");

    carrito.mover(-10, 9);
    delay(300);
    carrito.mover(0, 0);
    delay(200);
  }
  else if (centroUltra < detener && derechaUltra > detener && izquierdaUltra < detener)
  {
    // obstaculo izq y frente
    Serial.println("C giro derecha");

    carrito.mover(10, -9);
    delay(300);
    carrito.mover(0, 0);
    delay(200);
  }
  else if (centroUltra < detener && derechaUltra > detener && izquierdaUltra > detener)
  {
    // obstaculo frente, girar derecha
    Serial.println("D giro derecha");

    carrito.mover(10, -9);
    delay(300);
    carrito.mover(0, 0);
    delay(200);
  }
  else if (centroUltra > detener && derechaUltra > detener && izquierdaUltra < detener)
  {
    // obstaculo izquierda
    Serial.println("E giro derecha");

    carrito.mover(10, -9);
    delay(300);
    carrito.mover(0, 0);
    delay(200);
    carrito.mover(8, 7);
    delay(100);
  }
  else if (centroUltra > detener && derechaUltra < detener && izquierdaUltra > detener)
  {
    Serial.println("giro izquierda");
    //se verifica pues este sensor parece fallar
    delay(250);
    if (centroUltra > detener && derechaUltra < detener && izquierdaUltra > detener) {
      // obstaculo derecha
      Serial.println("F giro izquierda");

      carrito.mover(-10, 9);
      delay(300);
      carrito.mover(8, 7);
      delay(100);
    }

  }
  else
  {
    Serial.println("G ir hacia adelante");
    //movemos el carrito hacia adelante
    carrito.mover(8, 7);
    delay(150);
    carrito.mover(0, 0);
  }
}
