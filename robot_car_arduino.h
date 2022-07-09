
#ifndef robot_car_arduino_h
#define robot_car_ardino_h
#include "arduino.h"

/*************************
	Clase Ultrasonido
**************************
- distancia : long
+ pinEcho : byte*
+ pinTrigger: byte*
**************************
+ medirCM() : int
+ Ultrasonido(byte*,byte*)
****************************/
class Ultrasonido
{
private:
	long distancia;

public:
	byte *pinEcho;
	byte *pinTrigger;

	// Constructor parametrizado Recibe Trigger y Echo como byte
	Ultrasonido(byte *_pinTrigger, byte *_pinEcho);
	Ultrasonido();
	// Mide la distancia el sensor es preciso hasta 3.5 mts
	// por lo tanto el valor maximo es 350 cms
	int medirCM();
};

/*******************************************************************************
						Clase Carro
********************************************************************************
+ encoderI : byte = 2 //pin del encoder de la llanta izquierda
+ encoderD : byte = 3 // pin del encoder de la llanta derecha
+ adelanteI : byte =4; // pin avance adelante llanta Izquierda
+ atrasI : byte =5;    // pin de reversa llanta izquierda
+ potenciaI : byte =6; // pin de potencia llanta Izquierda pin PWM
+ adelanteD : byte =7; // Adelante llanta Derecha
+ atrasD : byte =8;  // atras llanta Derecha
+ potenciaD : byte =9;  // potencia llanta Derecha pin PWM
+ sensortrigerC : byte =10; //Sensor Ultrasonido Central Trigger
+ sensorechoC : byte =11; //Sensor Ultrasonido Central Echo
+ sensortrigerI : byte =12; //Sensor Ultrasonido Izquierda Trigger
+ sensorechoI : byte =13; //Sensor Ultrasonido Izquierda Echo
+ sensortrigerD : byte =14; //Sensor Ultrasonido Derecha Trigger
+ sensorechoD : byte =15; //Sensor Ultrasonido Derecha Echo
+ potenciaMAX: byte =200;  //limite regulador de la potencia maxima
+ UltraC : Ultrasonido* // Se declara como PUNTEROS
+ UltraI : Ultrasonido* // en el cpp se va a instanciar y a referir
+ UltraD : Ultrasonido*
  //DEFINIENDO LAS INTERRUPCIONES--USAN MIEMBROS ESTATICOS
  static volatile unsigned int contaI; //contador de las vueltas de la llanta Izquierda
  static volatile unsigned int contaD; //contador de las vueltas de la llanta Derecha
 *************************************************************************************
	//METODOS CONTADORES DE RUEDAS IZQUIERDA Y DERECHA
	static void contarRuedaI(); //metodo a registrar con la interrupcion en constructor
	static void contarRuedaD();

	//Constructor -- configura variables, sensores e interrupciones
	+ Carro()

	//acciona el motor, recibe como parametro la accion en la llanta izquierda y la llanta derecha
	// el valor de cada llanta si es positivo movera la llanta hacia adelante
	// si es negativo movera la llanta hacia atras
	// el numero representara la potencia aplicada a cada llanta
	// los valores pueden ir de -255 hasta 255
	+ mover(int Izquierda, int Derecha) : void

	//Gira la cantidad de grados especifica: - a la izquierda, + derecha
	//usa los contadores de vuelta para la precision al girar
	//tu decides si usas dos llantas para girar o solo una
	+ girar(int grados): void

*******************************************************************************/
class Carro
{
public:
	byte encoderI = 2;		 // pin del encoder de la llanta izquierda
	byte encoderD = 3;		 // pin del encoder de la llanta derecha
	byte adelanteI = 4;		 // pin avance adelante llanta Izquierda
	byte atrasI = 5;		 // pin de reversa llanta izquierda
	byte potenciaI = 6;		 // pin de potencia llanta Izquierda pin PWM
	byte adelanteD = 7;		 // Adelante llanta Derecha
	byte atrasD = 8;		 // atras llanta Derecha
	byte potenciaD = 9;		 // potencia llanta Derecha pin PWM
	byte sensortrigerC = 10; // Sensor Ultrasonido Central Trigger
	byte sensorechoC = 11;	 // Sensor Ultrasonido Central Echo
	byte sensortrigerI = 12; // Sensor Ultrasonido Izquierda Trigger
	byte sensorechoI = 13;	 // Sensor Ultrasonido Izquierda Echo
	byte sensortrigerD = 14; // Sensor Ultrasonido Derecha Trigger
	byte sensorechoD = 15;	 // Sensor Ultrasonido Derecha Echo
	byte potenciaMAX = 200;

	Ultrasonido UltraC; // Se declara como PUNTEROS
	Ultrasonido UltraI; // en el cpp se va a instanciar y a referir
	Ultrasonido UltraD;

	// DEFINIENDO LAS INTERRUPCIONES--USAN MIEMBROS ESTATICOS
	static volatile unsigned int contaI; // contador de las vueltas de la llanta Izquierda
	static volatile unsigned int contaD; // contador de las vueltas de la llanta Derecha

	// CONTADORES DE RUEDAS IZQUIERDA Y DERECHA
	static void contarRuedaI(); // metodo a registrar con la interrupcion en constructor
	static void contarRuedaD();

	// Constructor -- configura variables, sensores e interrupciones
	Carro();

	// acciona el motor, recibe como parametro la accion en la llanta izquierda y la llanta derecha
	//  el valor de cada llanta si es positivo movera la llanta hacia adelante
	//  si es negativo movera la llanta hacia atras
	//  el numero representara la potencia aplicada a cada llanta
	//  los valores pueden ir de -10 hasta 10
	void mover(int Izquierda, int Derecha);

	// Gira la cantidad de grados especifica: - a la izquierda, + derecha
	// usa los contadores de vuelta para la precision al girar
	// tu decides si usas dos llantas para girar o solo una
	void girar(int grados);
};

#endif