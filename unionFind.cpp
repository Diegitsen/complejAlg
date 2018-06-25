#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
using namespace System;

class UFDS
{
private:
	int n;
	int max;
	vector<int> rank;
	vector<int> parent;
	vector<int> elements;

public:
	UFDS(int n)
	{
		this->n = n;

		for (int i = 0; i < n; i++)
		{
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int i)
	{
		if (parent[i] != i)
			parent[i] = find(parent[i]);

		return parent[i]; //also can be only i
	}

	bool sameSet(int x, int y)
	{
		return find(x) == find(y);
	}

	void unionSetUtil(int x, int y)
	{
		if (!sameSet(x, y))
		{
			if (rank[x] > rank[y])
				parent[y] = x;

			else if (rank[y] > rank[x])
				parent[x] = y;

			else
			{
				parent[x] = y;
				rank[y]++;
			}
		}
		
	}

	void unionSet(int x, int y)
	{
		unionSetUtil(find(x), find(y));
	}

	void showSet()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "El padre de " << i << " es: " << parent[i] << endl;
		}
	}

};

int main()
{
	UFDS u(6);

	u.showSet();
	cout << endl;

	u.unionSet(1, 2);
	u.unionSet(2, 4);
	u.unionSet(0, 2);
	u.unionSet(3, 5);

	cout << endl;
	u.showSet();

	_getch();
}
