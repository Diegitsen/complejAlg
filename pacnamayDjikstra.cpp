
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include<stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <functional> 
using namespace System;
using namespace std;
typedef std::pair<int, int> iPair;

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ENTER 13
#define MaxCol 18/*20*/ //76 //horizontal
#define MaxFilas 15/*31//*///32 //vertical
#define INF 99999
int cuatro;
int Nv = 5;
int dy = 1;
int dx = 1;
int Mapa[MaxFilas][MaxCol];
bool CoinMap[MaxFilas][MaxCol];
int contadorPuntos = 0; //i dont know if this is going to initialize with 0
int vidas = 3;
int x = 4, y = 1; //pacman
int x1 = 6;
int fg = 1;
bool activarDijkstra; //seguimiento
int e1x = 1, e1y = 1; //enemigo 1
int dir = 2; //direccion donde se mueve el enemigo
std::map<int, std::pair<int, int>> mapaVertices;
int pacmanVertice = 0;
int enemigoVertice = 0;
bool pacmanVivo = true;
int obX, obY;


vector<vector<int>> vectorFloyd;

class Graph
{
	int V;
	std::list< std::pair<int, int> > *adj;

public:
	Graph(int V) {
		this->V = V;
		adj = new std::list<iPair>[V];
	}
	void setV(int V)
	{
		this->V = V;
	}

	void addEdge(int u, int v, int w) {
		adj[u].push_back(std::make_pair(v, w));
		adj[v].push_back(std::make_pair(u, w));
	}

	std::vector<int> shortestPath(int src) {
		std::priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
		std::vector<int> dist(V, INF);
		pq.push(std::make_pair(0, src));
		dist[src] = 0;

		while (!pq.empty()) {
			int u = pq.top().second;
			pq.pop();
			std::list< std::pair<int, int> >::iterator i;
			for (i = adj[u].begin(); i != adj[u].end(); ++i) {
				int v = (*i).first;
				int weight = (*i).second;
				if (dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					pq.push(std::make_pair(dist[v], v));
				}
			}
		}
		return dist;
	}
};

void nivel0()
{
	Console::Clear();
	char mapa[15][18] = {
		{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
		{ 3,4,1,1,4,1,1,1,1,1,1,1,4,1,1,4,3 },
		{ 3,1,3,3,1,3,3,3,3,3,3,3,1,3,3,1,3 },
		{ 3,1,3,3,4,1,1,4,3,4,1,1,4,3,3,1,3 },
		{ 3,1,3,3,3,3,3,1,3,1,3,3,3,3,3,1,3 },
		{ 3,1,3,3,4,1,1,4,1,4,1,1,4,3,3,1,3 },
		{ 3,1,3,3,1,3,3,3,3,3,3,3,1,3,3,1,3 },
		{ 3,1,3,3,1,3,3,3,3,3,3,3,1,3,3,1,3 },
		{ 3,1,3,3,1,3,3,3,3,3,3,3,1,3,3,1,3 },
		{ 3,1,3,3,4,1,1,4,1,4,1,1,4,3,3,1,3 },
		{ 3,1,3,3,3,3,3,1,3,1,3,3,3,3,3,1,3 },
		{ 3,1,3,3,4,1,1,4,3,4,1,1,4,3,3,1,3 },
		{ 3,1,3,3,1,3,3,3,3,3,3,3,1,3,3,1,3 },
		{ 3,4,1,1,4,1,1,1,1,1,1,1,4,1,1,4,3 },
		{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
	};

	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c < MaxCol; c++) {
			//if (mapa[f][c] == 4) cuatro++;
			Mapa[f][c] = mapa[f][c];
		}
	for (int f = 0; f<MaxFilas; f++)
		for (int c = 0; c < MaxCol; c++) {
			if (mapa[f][c] == 1 || mapa[f][c] == 4)
			{
				CoinMap[f][c] = true;
			}
			else
			{
				CoinMap[f][c] = false;
			}
		}

}

void gotoxy(int x, int y)
{
	HANDLE Identificador;
	Identificador = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(Identificador, dwPos);
}

void dibujarVidas(int px, int py)
{

	for (int i = 0; i < vidas; i++)
	{
		gotoxy(px + i, py);
		std::cout << char(3);
	}
	if (vidas < 3)
	{
		gotoxy(px + 2, py);
		std::cout << " ";
		if (vidas < 2)
		{
			gotoxy(px + 1, py);
			std::cout << " ";
		}
	}
}

void dibujarPuntos()
{
	gotoxy(50, 8);
	Console::ForegroundColor = ConsoleColor::Magenta;
	std::cout << "Puntos: " << contadorPuntos;
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
			if (Mapa[f][c] == 1 || Mapa[f][c] == 4)
			{

				for (int i = 0; i < 3; i++)
				{
					gotoxy(c * 3 - i, f * 2);
					Console::ForegroundColor = ConsoleColor::Black;
					std::cout << char(219);
					gotoxy(c * 3 - i, f * 2 - 1);
					Console::ForegroundColor = ConsoleColor::Black;
					std::cout << char(219);
				}

			}
			if (Mapa[f][c] == 3)
			{

				for (int i = 0; i < 3; i++)
				{
					gotoxy(c * 3 - i, f * 2);
					Console::ForegroundColor = ConsoleColor::DarkBlue;
					std::cout << char(219);
					gotoxy(c * 3 - i, f * 2 - 1);
					Console::ForegroundColor = ConsoleColor::DarkBlue;
					std::cout << char(219);
				}

			}
		}

	}
}

void PaintCoinMap()
{
	for (int f = 0; f < MaxFilas; f++)
	{
		for (int c = 0; c < MaxCol; c++)
		{
			if (CoinMap[f][c] == 1)
			{
				gotoxy(c * 3, f * 2);
				Console::ForegroundColor = ConsoleColor::DarkCyan;
				std::cout << char(79);

			}
		}
	}
}

void dibujarPacman(int px, int py)
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(px * 3 - i, py * 2);
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::Yellow;
		std::cout << char(1);
		gotoxy(px * 3 - i, py * 2 - 1);
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::Yellow;
		std::cout << char(1);
	}
	gotoxy(px * 3 - 1, py * 2 - 1);
	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::Red;
	std::cout << char(1);
}

void borrarPacman(int px, int py)
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(px * 3 - i, py * 2);
		std::cout << " ";
		gotoxy(px * 3 - i, py * 2 - 1);
		std::cout << " ";
	}
}

void moverPacman(int &px, int &py)
{
	if (kbhit())
	{
		char tecla = getch();
		borrarPacman(px, py);
		if (tecla == ARRIBA && (Mapa[py - 1][px] == 1 || Mapa[py - 1][px] == 2 || Mapa[py - 1][px] == 4))
		{
			if (CoinMap[py - 1][px])
			{
				contadorPuntos += 5;
				CoinMap[py - 1][px] = false;
			}
			py--;
		}
		if (tecla == ABAJO && (Mapa[py + 1][px] == 1 || Mapa[py + 1][px] == 2 || Mapa[py + 1][px] == 4))
		{
			if (CoinMap[py + 1][px])
			{
				contadorPuntos += 5;
				CoinMap[py + 1][px] = false;
			}
			py++;
		}
		if (tecla == DERECHA && (Mapa[py][px + 1] == 1 || Mapa[py][px + 1] == 2 || Mapa[py][px + 1] == 4))
		{
			if (CoinMap[py][px + 1])
			{
				contadorPuntos += 5;
				CoinMap[py][px + 1] = false;
			}
			px++;
		}
		if (tecla == IZQUIERDA && (Mapa[py][px - 1] == 1 || Mapa[py][px - 1] == 2 || Mapa[py][px - 1] == 4))
		{
			if (CoinMap[py][px - 1])
			{
				contadorPuntos += 5;
				CoinMap[py][px - 1] = false;
			}
			px--;
		}
		if (Mapa[py][px]>4)
		{
			pacmanVertice = Mapa[py][px];
		}
		Mapa[py][px] = 1;

		dibujarPacman(px, py);
	}
}

void dibujarPacman2(int px, int py)
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(px * 3 - i, py * 2);
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::DarkRed;
		std::cout << char(1);
		gotoxy(px * 3 - i, py * 2 - 1);
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::DarkRed;
		std::cout << char(1);
	}
	gotoxy(px * 3 - 1, py * 2 - 1);
	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::Cyan;
	std::cout << char(1);
}

void moverPacman2(int &px, int &py)
{
	if (kbhit())
	{
		char tecla = getch();
		borrarPacman(px, py);
		if (tecla == 105 && (Mapa[py - 1][px] == 1 || Mapa[py - 1][px] == 2 || Mapa[py - 1][px] == 4))
		{
			if (Mapa[py - 1][px] == 2)
			{
				contadorPuntos += 5;
			}
			py--;
		}
		if (tecla == 107 && (Mapa[py + 1][px] == 1 || Mapa[py + 1][px] == 2 || Mapa[py + 1][px] == 4))
		{
			if (Mapa[py + 1][px] == 2)
			{
				contadorPuntos += 5;
			}
			py++;
		}
		if (tecla == 108 && (Mapa[py][px + 1] == 1 || Mapa[py][px + 1] == 2 || Mapa[py][px + 1] == 4))
		{
			if (Mapa[py][px + 1] == 2)
			{
				contadorPuntos += 5;
			}
			px++;
		}
		if (tecla == 106 && (Mapa[py][px - 1] == 1 || Mapa[py][px - 1] == 2 || Mapa[py][px - 1] == 4))
		{
			if (Mapa[py][px - 1] == 2)
			{
				contadorPuntos += 5;
			}
			px--;
		}

		Mapa[py][px] = 1;

		dibujarPacman2(px, py);
	}
}

void dibujarEnemigo(int ex, int ey, int c)
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(ex * 3 - i, ey * 2);
		Console::BackgroundColor = ConsoleColor::Black;
		switch (c) {
		case 1:
			Console::ForegroundColor = ConsoleColor::DarkMagenta;
			break;
		case 2:
			Console::ForegroundColor = ConsoleColor::DarkRed;
			break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Green;
			break;
		}
		std::cout << char(1);
		gotoxy(ex * 3 - i, ey * 2 - 1);
		Console::BackgroundColor = ConsoleColor::Black;
		switch (c) {
		case 1:
			Console::ForegroundColor = ConsoleColor::DarkMagenta;
			break;
		case 2:
			Console::ForegroundColor = ConsoleColor::DarkRed;
			break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Green;
			break;
		}
		std::cout << char(1);
	}
}

void borrarEnemigo(int ex, int ey)
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(ex * 3 - i, ey * 2);
		std::cout << " ";
		gotoxy(ex * 3 - i, ey * 2 - 1);
		std::cout << " ";
	}
}

void choque(int px, int py, int ex, int ey)
{
	if ((px == ex || px == ex + 1 || px == ex + 2 || px + 1 == ex || px + 2 == ex) && py == ey)
		vidas--;
}

void pintarMonedasBorradasPorEnemigo(int x, int y)
{
	gotoxy(x, y);
	if (Mapa[y][x] == 2)
	{
		Console::ForegroundColor = ConsoleColor::Red;
		std::cout << char(79);
	}
}

void floyd_warshal(vector<vector<int>> v, int n) {
	vector<vector<int>> dist;
	vector<vector<int>> recor;

	//iniciar vector de vector
	vector<int> aux;
	for (int i = 0; i < n; i++)
		aux.push_back(INF);

	for (int i = 0; i < n; i++) {
		dist.push_back(aux);
		recor.push_back(aux);
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			recor[i][j] = j;
		}
	}

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			dist[i][j] = v[i][j];

	for (int k = 0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (dist[i][k] + dist[k][j]<dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					recor[i][j] = k;
				}
			}
		}
	}
	

}
Graph g(29);
void moverEnemigo(int &ex, int &ey, int c)
{
	borrarEnemigo(ex, ey);

	if (Mapa[ey][ex] >= 4)
		dir = rand() % 4;

	if (dir == 0)
	{
		if (Mapa[ey - 1][ex] != 3)
		{
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
	if(Mapa[ey][ex] > 4)
	{
		vector<int> hola(29);
			hola=g.shortestPath(Mapa[ey][ex]);
		if(hola[pacmanVertice]>hola[25]|| hola[pacmanVertice]>hola[10]|| hola[pacmanVertice]>hola[14])
		{ 
		

			if(x>e1x)
			{ 
				if (Mapa[ey][ex + 1] != 3)
					ex += 1;
			}
			else
			{
				if (Mapa[ey][ex - 1] != 3)
					ex -= 1;	
			}
			if (y>e1y)
				{
					if (Mapa[ey+1][ex ] != 3)
						ey += 1;
				}
			else
				{
					if (Mapa[ey - 1][ex] != 3)
					{
						ey -= 1;
					}
				}

				
		}

	}

	dibujarEnemigo(ex, ey, c);
}

void findEdge(int i, int j, int d)
{

	Mapa[i][j] = Nv;
	mapaVertices.insert(std::make_pair(Nv, std::make_pair(i, j)));
	int k = 0;
	if (d != 1) {
		do
		{
			k++;
			if (Mapa[i + k][j] == 3 && Mapa[i + k][j] >= 4)
				break;
		} while (Mapa[i + k][j] == 1);
		if (Mapa[i + k][j] >= 4)
		{
			if (Mapa[i + k][j] == 4) {

				g.addEdge(Nv, Nv + 1, k);

				Nv++;
				findEdge(i + k, j, 2);

			}
			else
			{


				g.addEdge(Nv, Mapa[i + k][j], k);
			}

		}
	}

	if (d != 2) {
		k = 0;
		do
		{
			k++;
			if (Mapa[i - k][j] == 3 && Mapa[i][j + k] >= 4)
				break;
		} while (Mapa[i - k][j] == 1);

		if (Mapa[i - k][j] >= 4)
		{
			if (Mapa[i - k][j] == 4) {

				g.addEdge(Nv, Nv + 1, k);
				Nv++;
				findEdge(i - k, j, 1);
			}
			else
			{

				g.addEdge(Nv, Mapa[i - k][j], k);
			}

		}
	}


	if (d != 3) {
		k = 0;
		do
		{
			k++;
			if (Mapa[i][j + k] == 3 && Mapa[i][j + k] >= 4)
				break;
		} while (Mapa[i][j + k] == 1);

		if (Mapa[i][j + k] >= 4)
		{
			if (Mapa[i][j + k] == 4) {

				g.addEdge(Nv, Nv + 1, k);
				Nv++;
				findEdge(i, j + k, 4);
			}
			else
			{


				g.addEdge(Nv, Mapa[i][j + k], k);
			}

		}
	}

	if (d != 4) {
		k = 0;
		do
		{
			k++;
			if (Mapa[i][j - k] == 3 && Mapa[i][j - k] >= 4)
				break;
		} while (Mapa[i][j - k] == 1);

		if (Mapa[i][j - k] >= 4)
		{
			if (Mapa[i][j - k] == 4) {

				g.addEdge(Nv, Nv + 1, k);
				Nv++;
				findEdge(i, j - k, 3);
			}
			else
			{

				g.addEdge(Nv, Mapa[i][j - k], k);
			}

		}
	}
}

void createGraph()
{
	for (int i = 0; i<MaxCol; i++)
		for (int j = 0; j<MaxFilas; j++)
		{
			if (Mapa[i][j] == 4) {
				findEdge(i, j, 0);
				break;
			}
		}
}

void clean()
{
	for (int f = 0; f<50; f++)
		for (int c = 0; c < 50; c++) {
			gotoxy(f, c);
			std::cout << " ";
		}
}

int main()
{
	nivel0();
	int c = 0;
	//createGraph();
	//	g.shortestPath(6);
	
	vector<int> aux;
	for (int i = 0; i < 29; i++)
		aux.push_back(INF);

	for (int i = 0; i < 29; i++)
		vectorFloyd.push_back(aux);

	for (int i = 0; i<29; i++) {
		for (int j = 0; j<29; j++)
			if (i == j) vectorFloyd[i][j] = 0;
	}
	while (pacmanVivo)
	{

		PintarMapa();


		while (pacmanVivo)
		{

			dibujarPacman(x, y);


			c++;
			if (c % 900 == 0) {
				PaintCoinMap();
				dibujarInfo();
			}

			if (c % 300 == 0) {
				moverEnemigo(e1x, e1y, 1);
				//	moverEnemigo(e2x, e2y,2);
				//	moverEnemigo(e3x, e3y,3);
			}
			if (c > 9999999)
				c = 0;

			if (x == e1x && y == e1y)
			{
				vidas = vidas--;
				x = 4;
				y = 1;
			}
			if (vidas <= 0 || contadorPuntos == 500)
			{
				pacmanVivo = false;
			}

			moverPacman(x, y);


		}
	}
	clean();
	if (contadorPuntos >= 450) {
		std::cout << "Ganaste :D" << std::endl;
	}
	else {
		std::cout << "Perdiste :'(" << std::endl;
	}
	system("PAUSE");
	return 0;
}



