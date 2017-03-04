// long_text.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

#include <string>
#include <cctype>
#include <fstream>
#include <math.h>
using namespace std;

 

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	char ch;
	
	
	ifstream fin("1.txt");
	int c[33];
	for (int i=0;i<33;i++) c[i]=0;
	
	char s [33] = {'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я'};
	if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
	{
			while (!fin.eof())
		{
			fin>>ch;
			if ((wchar_t)ch>=65472 && (wchar_t)ch<=65477) {c[(wchar_t)ch-65472]++; n++;}
			if ((wchar_t)ch>=65478 && (wchar_t)ch<=65503) {c[(wchar_t)ch-65471]++; n++;}
			if ((wchar_t)ch==65448 || (wchar_t)ch==65464) {c[6]++; n++;}
			if ((wchar_t)ch>=65504 && (wchar_t)ch<=65509) {c[(wchar_t)ch-65504]++; n++;}
			if ((wchar_t)ch>=65510 && (wchar_t)ch<=65535) {c[(wchar_t)ch-65503]++; n++;}
		}
	}
	cout << "Количество букв: "<<n<<endl;
	for (int i= 0;i<33;i++)
	{
		cout<<"c["<<s[i]<<"] = "<<((double)(c[i])/n)*100<<"%"<<endl;
		//cout<<c[i]<<endl;
		
	}

	system("pause");
}



