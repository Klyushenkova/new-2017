// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
 
#define PI 3.1415956535
 
using namespace std;
 
class Matrix;
 
class Array
{
public:
    int x[5];
    Array() {
        for (int i = 0; i < 5; i++) {
            x[i] = rand() % 21 - 10;
        }
    }
 
    int& operator [](int i)
    {
        return x[i];
    }
    friend Matrix;
};
 
 
 
class Matrix
{
 
public:
    Array y[5];
 
    void show() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << setw(4) << y[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
 
    void edit(int a, int b) {
        cin >> y[a][b];
    }
	int kolvo_ed (Matrix N)
	{
		int kl;
		for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
				if (N.y[i][j]==1) kl++;
			}
		}
		return kl;
	}

 
};
 class Boolean: Matrix
{

 }

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

