
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include<stdlib.h>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
using namespace System;
/*const int INF 99999
const int vertice 4
const int ARRIBA 72
const int ABAJO 80
const int IZQUIERDA 75
const int DERECHA 77
const int ENTER 13
const int MaxCol 13*/

#define INF 999
#define vertice 22
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ENTER 13
#define MaxCol 41//41/*20*/ //76 //horizontal
#define MaxFilas 11//19/*31//*///32 //vertical
int puntitos = 0;
int recor[vertice][vertice];
int dist[vertice][vertice];
int dy = 1;
int dx = 1;
int dex = 1, dey = 1;
int Mapa[MaxFilas][MaxCol];
int contadorPuntos = 0; //i dont know if this is going to initialize with 0
int vidas = 5;
//int x = 5, y = 5; //pacman
//int ex = 2, ey = 2; //enemigo 1
int dir = 2; //direccion donde se mueve el enemigo
int lastGhost = 0;// aquí le dí un valor de cero para que la ultima posición sea sero, es solo la inicialización
int lastPacman;//this could be the problem
			   //int dirr = 0;



void gotoxy(int x, int y)
{
	HANDLE Identificador;
	Identificador = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(Identificador, dwPos);
}



//20 31
void Nivel1()
{
	Console::Clear();
	int Matriz[32][76] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3,  3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 2, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1 } };
	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c<MaxCol; c++)
			Mapa[f][c] = Matriz[f][c];

}



void nivelone()
{
	Console::Clear();
	char mapa[11][41] = {
		//0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8
		/*0*/{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
		/*1*/{ 3,4,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,1,3,3,3,1,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,4,3 },
		/*2*/{ 3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		/*3*/{ 3,1,2,1,3,3,3,1,2,1,1,3,3,1,1,2,1,1,3,3,3,1,1,1,1,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
		/*4*/{ 3,1,2,1,3,3,3,1,2,1,1,3,3,1,1,2,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
		/*5*/{ 3,4,2,1,3,3,3,1,2,4,1,3,3,4,1,2,1,1,1,1,1,1,1,1,1,4,3,3,1,4,1,1,1,3,3,1,1,4,3 },
		/*6*/{ 3,1,2,1,3,3,3,1,2,1,1,3,3,1,1,2,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
		/*7*/{ 3,1,2,1,3,3,3,1,2,1,1,3,3,1,1,2,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
		/*8*/{ 3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
		/*9*/{ 3,4,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,1,3,3,3,1,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,4,3 },
		/*10*/{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
	};

	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c<MaxCol; c++)
			Mapa[f][c] = mapa[f][c];
}

void nivelprueba()
{
	Console::Clear();
	//         y   x
	char mapa[11][13] = {
		{ 3,3,3,3,3,3,3,3,3,3,3,3,3 },
	{ 3,4,1,1,1,1,1,1,1,4,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,4,1,1,1,1,1,1,1,4,3,3,3 },
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3 },
	};
	/*
	0 -> 1 1
	1 -> 9 1
	2 -> 1 9
	3 -> 9 9
	*/

	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c<MaxCol; c++)
			Mapa[f][c] = mapa[f][c];
}

void nivelprueba2()
{
	Console::Clear();
	//         y   x
	char mapa[11][13] = {  //3 -> 12 -> x
		{ 3,3,3,3,3,3,3,3,3,3,3,3,3 },
	{ 3,4,1,1,1,4,1,1,1,4,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,4,1,1,1,4,1,1,1,4,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,1,1,1,1,1,1,1,1,1,3,3,3 },
	{ 3,4,1,1,1,4,1,1,1,4,3,3,3 },
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3 },
	};

	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c<MaxCol; c++)
			Mapa[f][c] = mapa[f][c];
}



void nivel0()
{
	Console::Clear();
	char mapa[19][41] = {
		{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
	{ 3,4,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,3,3,3,3,3,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,4,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,3,3,3,1,3,3,3,3,3,1,3,3,3,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,3,3,3,1,3,3,3,3,3,1,3,3,3,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
	{ 3,4,1,1,1,4,1,1,1,4,1,3,3,4,3,3,3,3,3,3,3,3,3,3,3,4,3,3,1,4,1,1,1,4,1,1,1,4,3 },
	{ 3,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,3,3,3,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,3,3,3,3,1,3,3,3,1,3,3,3,3,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,4,1,1,1,4,1,1,1,4,1,3,3,4,3,3,3,3,3,3,3,3,3,3,3,4,3,3,1,4,1,1,1,4,1,1,1,4,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,1,3,3,3,3,3,3,3,3,3,3,3,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,3,3,3,3,1,3,3,3,1,3,3,3,3,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,4,1,1,1,4,1,1,1,4,1,3,3,4,1,1,1,1,3,3,3,1,1,1,1,4,3,3,1,4,1,1,1,4,1,1,1,4,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,1,3,3,3,3,3,3,3,3,3,3,3,1,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,1,1,1,3,3,3,1,1,1,1,3,3,3,3,1,3,3,3,3,3,3,3,3,1,3,3,3,1,1,1,1,3,3,3,1,1,1,3 },
	{ 3,4,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,4,1,1,1,4,1,1,1,4,3 },
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
	};

	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c<MaxCol; c++)
			Mapa[f][c] = mapa[f][c];
}

int localizePacman(int x, int y) //aaquí se debe actualizar las posiciones del pacman para saber en que nodo está de la nueva matriz
{
	if (Mapa[y][x] == 4)
	{
		if (x == 1 && y == 1)
		{
			lastPacman = 0;
			return 0;

		}

		if (x == 5 && y == 1)
		{
			lastPacman = 1;
			return 1;

		}

		if (x == 9 && y == 1)
		{
			lastPacman = 2;
			return 2;

		}


		if (x == 13 && y == 1)
		{
			lastPacman = 3;
			return 3;

		}

		if (x == 25 && y == 1)
		{
			lastPacman = 4;
			return 4;

		}

		if (x == 29 && y == 1)
		{
			lastPacman = 5;
			return 5;

		}

		if (x == 33 && y == 1)
		{
			lastPacman = 6;
			return 6;

		}

		if (x == 37 && y == 1)
		{
			lastPacman = 7;
			return 7;

		}

		if (x == 1 && y == 5)
		{
			lastPacman = 8;
			return 8;

		}

		if (x == 9 && y == 5)
		{
			lastPacman = 9;
			return 9;

		}

		if (x == 13 && y == 5)
		{
			lastPacman = 10;
			return 10;
		}

		if (x == 25 && y == 5)
		{
			lastPacman = 11;
			return 11;

		}

		if (x == 29 && y == 5)
		{
			lastPacman = 12;
			return 12;

		}

		if (x == 37 && y == 5)
		{
			lastPacman = 13;
			return 13;

		}

		if (x == 1 && y == 9)
		{
			lastPacman = 14;
			return 14;

		}

		if (x == 5 && y == 9)
		{
			lastPacman = 15;
			return 15;

		}

		if (x == 9 && y == 9)
		{
			lastPacman = 16;
			return 16;

		}

		if (x == 13 && y == 9)
		{
			lastPacman = 17;
			return 17;

		}

		if (x == 25 && y == 9)
		{
			lastPacman = 18;
			return 18;

		}

		if (x == 19 && y == 9)
		{
			lastPacman = 19;
			return 19;
		}

		if (x == 33 && y == 9)
		{
			lastPacman = 20;
			return 20;

		}

		if (x == 37 && y == 9)
		{
			lastPacman = 21;
			return 21;

		}
	}


	else//if ((ey != 1 && ex != 1) && (ey != 1 && ex != 9) && (ey != 9 && ex != 1) && (ey != 9 && ex != 9))
	{
		return lastPacman;
	}

}
//aquí cambie todos los localpacman por localghost
int localizeGhost(int ex, int ey) //i could change the parameters...maybe
{//aquí cambie las posicinoes del fantasma para saber cual es su nodo actual de la nueva matriz

	if (Mapa[ey][ex] == 4)
	{
		if (ex == 1 && ey == 1)
		{
			lastGhost = 0;
			return 0;

		}

		if (ex == 5 && ey == 1)
		{
			lastGhost = 1;
			return 1;

		}

		if (ex == 9 && ey == 1)
		{
			lastGhost = 2;
			return 2;

		}


		if (ex == 13 && ey == 1)
		{
			lastGhost = 3;
			return 3;

		}

		if (ex == 25 && ey == 1)
		{
			lastGhost = 4;
			return 4;

		}

		if (ex == 29 && ey == 1)
		{
			lastGhost = 5;
			return 5;

		}

		if (ex == 33 && ey == 1)
		{
			lastGhost = 6;
			return 6;

		}

		if (ex == 37 && ey == 1)
		{
			lastGhost = 7;
			return 7;

		}

		if (ex == 1 && ey == 5)
		{
			lastGhost = 8;
			return 8;

		}

		if (ex == 9 && ey == 5)
		{
			lastGhost = 9;
			return 9;

		}

		if (ex == 13 && ey == 5)
		{
			lastGhost = 10;
			return 10;
		}

		if (ex == 25 && ey == 5)
		{
			lastGhost = 11;
			return 11;

		}

		if (ex == 29 && ey == 5)
		{
			lastGhost = 12;
			return 12;

		}

		if (ex == 37 && ey == 5)
		{
			lastGhost = 13;
			return 13;

		}

		if (ex == 1 && ey == 9)
		{
			lastGhost = 14;
			return 14;

		}

		if (ex == 5 && ey == 9)
		{
			lastGhost = 15;
			return 15;

		}

		if (ex == 9 && ey == 9)
		{
			lastGhost = 16;
			return 16;

		}

		if (ex == 13 && ey == 9)
		{
			lastGhost = 17;
			return 17;

		}

		if (ex == 25 && ey == 9)
		{
			lastGhost = 18;
			return 18;

		}

		if (ex == 19 && ey == 9)
		{
			lastGhost = 19;
			return 19;
		}

		if (ex == 33 && ey == 9)
		{
			lastGhost = 20;
			return 20;

		}

		if (ex == 37 && ey == 9)
		{
			lastGhost = 21;
			return 21;

		}
	}
	if (Mapa[ey][ex] != 4) {
		return lastGhost;
	}



}

void printSolution(int dist[][vertice])
{
	/*printf("The following matrix shows the shortest distances"
	" between every pair of vertices \n");*/
	for (int i = 0; i < vertice; i++)
	{
		cout << i << "->";
		for (int j = 0; j < vertice; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int getWeight(int src, int dest)
{
	return dist[src][dest];
}

int getRecor(int src, int dest)
{
	return recor[src][dest];
}

void floydWarshall(int graph[vertice][vertice])
{
	int i, j, k;

	//recor
	for (int i = 0; i<vertice; i++)
	{
		for (int j = 0; j<vertice; j++)
		{
			if (i == j)
				recor[i][j] = 0;
			else
				recor[i][j] = j;
		}
	}

	for (i = 0; i < vertice; i++)
		for (j = 0; j < vertice; j++)
		{
			dist[i][j] = graph[i][j];
		}


	for (k = 0; k < vertice; k++)
		for (i = 0; i < vertice; i++)
			for (j = 0; j < vertice; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					recor[i][j] = k;
				}

	//printSolution(dist);
	//cout << endl << endl;
	//printSolution(recor);
}




void borrarEnemigo(int ex, int ey)
{
	gotoxy(ex, ey);
	cout << " ";
}

void dibujarEnemigo(int ex, int ey)
{
	gotoxy(ex, ey);

	Console::ForegroundColor = ConsoleColor::DarkGreen;
	//Console::BackgroundColor = ConsoleColor::Yellow;
	cout << 'x';
}


void movingGhost(int &ex, int &ey, int direction)
{
	switch (direction)
	{
	case 0:
		dey = 0;
		dex = 1;
		break;
	case 1:
		dey = 1;
		dex = 0;
		break;
	case 2:
		dey = -1;
		dex = 0;
		break;
	case 3:
		dey = 0;
		dex = -1;
		break;
	}

	borrarEnemigo(ex, ey);

	ey += dey;
	ex += dex;

	dibujarEnemigo(ex, ey);
}


void moveGhost(int src, int dest, int &ex, int &ey) //( localizeghost, localizepacman)
{
	switch (dest)
	{
	case 0:
		movingGhost(ex, ey, 2);
		break;
	case 1:
		movingGhost(ex, ey, 1);
		break;
	case 2:
		movingGhost(ex, ey, 0);
		break;
	case 3:
		movingGhost(ex, ey, 3);
		break;
	}
}



void dibujarVidas(int px, int py)
{
	for (int i = 0; i < vidas; i++)
	{
		gotoxy(px + i, py);
		cout << char(3);
	}
}

void dibujarPuntos()
{
	gotoxy(50, 8);
	Console::ForegroundColor = ConsoleColor::Magenta;
	cout << "Puntos: " << contadorPuntos;
}

void dibujarInfo()
{
	dibujarPuntos();
	dibujarVidas(50, 9);

}


void PintarMapa()
{
	for (int f = 0; f < MaxFilas; f++)
	{
		for (int c = 0; c < MaxCol; c++)
		{
			if (Mapa[f][c] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Black;
				cout << char(219);
			}
			if (Mapa[f][c] == 3)
			{
				Console::ForegroundColor = ConsoleColor::DarkBlue;
				cout << char(219);
			}
			if (Mapa[f][c] == 4)
			{
				Console::ForegroundColor = ConsoleColor::Red;
				cout << char(79);
			}

			if (Mapa[f][c] == 2)
			{
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << char(79);
			}
		}
		cout << "\n";
	}
}

void dibujarPacman(int px, int py)
{
	gotoxy(px, py);
	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << char(1);
}

void borrarPacman(int px, int py)
{
	gotoxy(px, py);
	cout << " ";
}

void moverPacman(int &px, int &py)
{
	if (kbhit())
	{
		char tecla = getch();
		borrarPacman(px, py);
		if (tecla == ARRIBA && (Mapa[py - 1][px] == 1 || Mapa[py - 1][px] == 2 || Mapa[py - 1][px] == 4))
		{
			if (Mapa[py - 1][px] == 2)
			{
				contadorPuntos += 5;
			}
			py--;
		}


		if (tecla == ABAJO && (Mapa[py + 1][px] == 1 || Mapa[py + 1][px] == 2 || Mapa[py + 1][px] == 4))
		{
			if (Mapa[py + 1][px] == 2)
			{
				contadorPuntos += 5;
			}
			py++;
		}


		if (tecla == DERECHA && (Mapa[py][px + 1] == 1 || Mapa[py][px + 1] == 2 || Mapa[py][px + 1] == 4))
		{
			if (Mapa[py][px + 1] == 2)
			{
				contadorPuntos += 5;
			}
			px++;
		}


		if (tecla == IZQUIERDA && (Mapa[py][px - 1] == 1 || Mapa[py][px - 1] == 2 || Mapa[py][px - 1] == 4))
		{
			if (Mapa[py][px - 1] == 2)
			{
				contadorPuntos += 5;
			}
			px--;
		}

		if (Mapa[py][px] == 2)
		{
			puntitos += 5;
			Mapa[py][px] = 1;
		}

		if (Mapa[py][px] == 4)
		{
			gotoxy(px, py);
			Console::ForegroundColor = ConsoleColor::Red;
			cout << char(79);
		}

		//Mapa[py][px] = 1; --this

		dibujarPacman(px, py);

	}
}




void choque(int px, int py, int ex, int ey)
{
	if (px == ex && py == ey)
		vidas--;

	if (vidas < 0)
	{
		vidas = 0;
	}
}

//i d k why yhis doesnt work
void pintarMonedasBorradasPorEnemigo(int x, int y)
{
	gotoxy(x, y);
	if (Mapa[y][x] == 2)
	{
		Console::ForegroundColor = ConsoleColor::Red;
		cout << char(79);
	}
}




void moverEnemigo(int &ex, int &ey)
{
	borrarEnemigo(ex, ey);          // las coordenadas del enemigo

									/*ex += dx;                      // dx es una variable que se le asigna 1

									choque(x, y, ex, ey);

									if (ex < 16 || ex > 64)       // si se pasa de los limites
									dx *= -1;                 // se le multiplica por -1, asi cambia de direccion*/

	if (Mapa[ey][ex] == 4)
		dir = rand() % 4;

	if (dir == 0)
	{
		if (Mapa[ey - 1][ex] != 3)
		{
			pintarMonedasBorradasPorEnemigo(ex, ey - 1);
			ey -= 1;
		}

		else
			dir = rand() % 4;
	}

	if (dir == 1)
	{
		if (Mapa[ey + 1][ex] != 3)
			ey += 1;

		else
			dir = rand() % 4;
	}

	if (dir == 2)
	{
		if (Mapa[ey][ex + 1] != 3)
			ex += 1;

		else
			dir = rand() % 4;
	}

	if (dir == 3)
	{
		if (Mapa[ey][ex - 1] != 3)
		{
			ex -= 1;
		}

		else
			dir = rand() % 4;
	}



	/*

	if (dir == 0) //arriba
	{
	ey -= 1;
	}

	if (dir == 1) //abajo
	ey += 1;

	if (dir == 2) //derecha
	ex += 1;

	if (dir == 3) //izquierda
	ex -= 1;*/

	dibujarEnemigo(ex, ey);

	Sleep(120);

}




class Grafo
{
private:
	int n;
	//list<int> *listita;
	vector<vector<int>> vec;
public:
	Grafo(int n)
	{
		this->n = n;
		//listita = new list<int>[n];

	}

	void addEdge(int u, int v)
	{
		vec.at(u).push_back(v);
	}

};


int pasitoTunTun(int src, int dest)
{
	int v = dest;

	while (v != getRecor(src, v))
	{
		v = getRecor(src, v);
	}

	return v;
}

void retornoValores(int n, int &x, int &y)
{//actualice los valores para que retorne los valores del nodo en la nueva matriz, ya no son 4 casos sino 9

	switch (n)
	{
	case 0:
		x = 1;
		y = 1;
		break;

	case 1:
		x = 5;
		y = 1;
		break;

	case 2:
		x = 9;
		y = 1;
		break;

	case 3:
		x = 13;
		y = 1;
		break;
	case 4:
		x = 25;
		y = 1;
		break;
	case 5:
		x = 29;
		y = 1;
		break;
	case 6:
		x = 33;
		y = 1;
		break;
	case 7:
		x = 37;
		y = 1;
		break;
	case 8:
		x = 1;
		y = 5;
		break;

	case 9:
		x = 9;
		y = 5;
		break;

	case 10:
		x = 13;
		y = 5;
		break;

	case 11:
		x = 25;
		y = 5;
		break;

	case 12:
		x = 29;
		y = 5;
		break;

	case 13:
		x = 37;
		y = 5;
		break;
	case 14:
		x = 1;
		y = 9;
		break;
	case 15:
		x = 5;
		y = 9;
		break;
	case 16:
		x = 9;
		y = 9;
		break;
	case 17:
		x = 13;
		y = 9;
		break;
	case 18:
		x = 25;
		y = 9;
		break;
	case 19:
		x = 29;
		y = 9;
		break;
	case 20:
		x = 33;
		y = 9;
		break;
	case 21:
		x = 37;
		y = 9;
		break;
	}


}


int getNumberOfVertices()
{
	int cont = 0;
	for (int i = 0; i < MaxCol; i++)
	{
		for (int j = 0; j < MaxFilas; j++)
		{
			if (Mapa[j][i] == 4)
				cont++;
		}
	}
	return cont;
}



void moveEnemy(int &ex, int &ey, int src, int dest, bool &bandera)
{

	borrarEnemigo(ex, ey);

	if (bandera) {
		//aquí es donde toma importancia la bandera, como  la inicialice en true (línea 844), en la primera pasada, el fantasma empezará a moverse
		//y dejará demoverse solo cuando la bandera sea false, para ello debemos hacer que cambie y eso está en la línea 767
		int MX;
		int MY;

		retornoValores(pasitoTunTun(src, dest), MX, MY);  //1 9




		if (MX > ex && Mapa[ey][ex + 1] != 3) {
			ex += 1;
		}

		if (MX < ex  && Mapa[ey][ex - 1] != 3)
		{
			ex -= 1;
		}

		if (MY > ey  && Mapa[ey + 1][ex] != 3)
		{
			ey += 1;
		}

		if (MY < ey  && Mapa[ey - 1][ex] != 3)
			ey -= 1;


	}
	//aquí le aumenté que la posición del fantasma debe coincidir con la función pasito para que solo se detenga cuando llegue al nodo correcto y no a otro
	if (Mapa[ey][ex] == 4 && localizeGhost(ex, ey) == pasitoTunTun(src, dest)) {// aquí pregunto si la posición en donde está mi fantasma es un nodo o no, y como ´lo pregunto al final primero
																				// realizará el movimiento y luego realiza este if, entonces cuando mi fantasma se mueva
																				//llegará un punto donde encuentre otro nodo, y ahí es donde cambio mi bandera a false, para que no continue con el moviemiento, hasta que reestablezca la bandera
		bandera = false;
	}
	/*
	direcciones
	0 -> derecha
	1 -> abajo
	2 -> arriba
	3 -> izquierda
	*/
	/*
	if (dir == 0)
	{
	if (Mapa[ey][ex + 1] != 3)
	ex += 1;

	if (Mapa[ey][ex] == 4)
	dir = 1;
	}

	if (dir == 1)
	{
	if (Mapa[ey + 1][ex] != 3)
	ey += 1;

	if (Mapa[ey][ex] == 4)
	dir = 3;
	}

	if (dir == 3)
	{
	if (Mapa[ey][ex - 1] != 3)
	ex -= 1;

	if (Mapa[ey][ex] == 4)
	dir = 2;
	}

	if (dir == 2)
	{
	if (Mapa[ey - 1][ex] != 3)
	ey -= 1;

	if (Mapa[ey][ex] == 4)
	dir = 0;
	}

	if (src == dest)
	{
	switch (dir)
	{
	case 0:
	ex--;
	break;
	case 1:
	ey--;
	break;
	case 2:
	ey++;
	break;
	case 3:
	ex++;
	break;
	}
	}
	*/
	dibujarEnemigo(ex, ey);
	Sleep(45);

}


void main()
{
	Grafo g(22);
	Console::SetWindowSize(100, 43);
	//g.addEdge(1,2);
	nivelone();
	bool bandera = true;// cree una bandera para que solo haga un movimiento, adelante lo explico más detalladamente
	int count = 0;//agregué un contador y una posición inicial serán útiles para la función de moverEnemy
	int posicióninicial;
	int graph[vertice][vertice] = {
		//  0   1    2     3    4    5    6    7    8    9   10    11   12   13   14   15   16   17   18   19  20   21
		{ 0,  2 , INF,  INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ 2,  0 ,   2,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF,   2,   0,    2, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF,   2,    0, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF,   0,   2, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF,   2,   0,   2, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF,   2,   0,   2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF, INF,   2,   0, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF,   0, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF, INF },
	{ INF, INF,   4,  INF, INF, INF, INF, INF, INF,   0, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF },
	{ INF, INF, INF,    4, INF, INF, INF, INF, INF, INF,   0, INF,   8, INF, INF, INF, INF,   4, INF, INF, INF, INF },
	{ INF, INF, INF,  INF,   4, INF, INF, INF,  8 , INF, INF,   0, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF },
	{ INF, INF, INF,  INF, INF,   4, INF, INF, INF, INF, INF, INF,   0, INF, INF, INF, INF, INF, INF,   4, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF,   4, INF, INF, INF, INF, INF,   0, INF, INF, INF, INF, INF, INF, INF,   4 },
	{ 4, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   0,   2, INF, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   2,   0,   2, INF, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   2,   0,   2, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF,   2,   0, INF, INF, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF,   0,   2, INF, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF,   2,   0,   2, INF },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   2,   0,   2 },
	{ INF, INF, INF,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   4, INF, INF, INF, INF, INF,   2,   0 },
	};
	/*
	int graph[vertice][vertice] = {
	{ 0,   2,  INF,  INF },
	{ INF, 0,   INF, 4 },
	{ 4,   INF, 0,   INF },
	{ INF, INF, 2,   0 }
	};*/


	while (1)
	{
		PintarMapa();
		int ex = 1, ey = 1;//modifique la posición de ex para que empiece en el nodo 0 que es el ex=1, ey=1; por comodidad
		int x = 4, y = 5;
		dibujarEnemigo(ex, ey);
		dibujarPacman(x, y);
		int dirr = 0;



		//gotoxy(30, 20);
		//cout << "xdd" << endl;

		while (1)
		{
			dibujarInfo();
			//verEnemigo(ex, ey);

			//moveGhost(localizeGhost(ex, ey), localizePacman(), ex, ey);

			if (Mapa[y][x] == 4) {//aquí pregunto si la posición donde está mi pacman es un nodo, y si es u nodo, recién se mueve el fantasma
				if (count == 0) {
					posicióninicial = localizeGhost(ex, ey);
				}
				count++;


				moveEnemy(ex, ey, posicióninicial, localizePacman(x, y), bandera);
			}
			if (Mapa[y][x] != 4) {  //aquí pregunto si la posición donde está mi pacman, no es un nodo para reiniciar mi bandera;
									//esto es para simular una salida del nodo, ya que si mi pacaman se encuentran en un número diferente a 4, significa que no estoy en un nodo
				count = 0;          //la bandera lo explico dentro de la función moveEnemy
				bandera = true;
			}
			gotoxy(40, 2);
			cout << "Puntos: " << puntitos;
			gotoxy(40, 3);
			cout << "Vidas: " << vidas;
			moverPacman(x, y);
			choque(x, y, ex, ey);
			gotoxy(40, 5);
			cout << getNumberOfVertices();
			gotoxy(40, 8);
			cout << "loca pacman->" << localizePacman(x, y) << "dir->" << dirr;
			gotoxy(40, 10);
			cout << "loca ghos(dirr)-> " << dirr;//localizeGhost(ex,ey);
			gotoxy(0, 20);
			floydWarshall(graph);
			gotoxy(40, 12);
			cout << "weight is: " << getWeight(localizeGhost(ex, ey), localizePacman(x, y));
			gotoxy(40, 14);
			cout << "ex->" << ex << " ey->" << ey;

			gotoxy(40, 17);
			cout << "l ghost->" << localizeGhost(ex, ey);
			gotoxy(40, 18);
			cout << "l pac->" << localizePacman(x, y);
			//retornoValores(pasitoTunTun(localizeGhost(ex, ey), localizePacman(x, y)), MX, MY);

			//gotoxy(20, 18);
		}
	}




	_getch();
}
