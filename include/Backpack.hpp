#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Backpack
{
private:
	int maxW, n;
	int **array;
	int max(int a, int b)
	{
		int max = 0;
		if (a > b)
			max = a;
		else
			max = b;
		return max;
	}
public:
	Backpack();
	Backpack(int, int);
	int Weight() const;
	int Value()const;
	int knapSack(int wT[], int val[], Backpack &);
};

Backpack::Backpack() : maxW(0), n(0), array{nullptr}
{}

int Backpack::Weight()const
{
	return maxW;
}

int Backpack::Value()const
{
	return n;
}

Backpack::Backpack(int a, int b) : maxW(a), n(b)
{
	array = new int *[a];
	for (int i = 0; i < a; i++)
	{
		array[i] = new int[b];
	}
}

int Backpack::knapSack(int wT[], int vaL[], Backpack &copy)
{
	int **array = new int*[copy.n+1];
	for (int count = 0; count < (n + 1); count++)
		array[count] = new int[copy.maxW + 1];
	for (int i = 0; i <= copy.n; i++)
	{
		for (int w = 0; w <= copy.maxW; w++)
		{
			if (i == 0 || w == 0)
				array[i][w] = 0;
			else if (wT[i - 1] <= w)
				array[i][w] = max(vaL[i - 1] + array[i - 1][w - wT[i - 1]], array[i - 1][w]);
			else
				array[i][w] = array[i - 1][w];
		}
	}
	return array[copy.n][copy.maxW];
}