#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

class MinBinaryHeap {
private:
	vector<int> a;

public:
	MinBinaryHeap() {}
	void mostrar() {
		for (int i = 0; i<a.size(); i++)
			cout << i << " -> " << a[i] << endl;
		cout << endl;
	}
	void insertar(int num) {
		a.push_back(num);
		int child = a.size() - 1;
		int parent = (child - 1) / 2;
		while (a[parent]<a[child]) {
			swap(a[parent], a[child]);
			child = parent;
			parent = child / 2;
		}
	}
	int extract() {
		int r = a[0];
		a[0] = a[a.size() - 1];
		a.pop_back();
		for (int i = 0; i<a.size(); i++) {
			int child = i;
			int parent = (child - 1) / 2;
			while (a[parent]<a[child]) {
				swap(a[parent], a[child]);
				child = parent;
				parent = child / 2;
			}
		}
		return r;
	}

};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	MinBinaryHeap *b = new MinBinaryHeap();
	int num;
	int n;
	cout << "Ingrese número de elementos: ";
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> num;
		b->insertar(num);
		cout << endl;
		b->mostrar();
	}
	cout << "Se extrajo: " << b->extract();
	cout << endl << endl;
	b->mostrar();
	_getch();
	return 0;
}
