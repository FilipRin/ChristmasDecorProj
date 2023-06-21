#pragma once
#ifndef _boja_h_
#define _boja_h_
#include<exception>
#include <iostream>
using namespace std;

class GLosaVrednost :public exception {
public:
	const char* what()const {
		return  "***Vrednost nije dobra!";
	}
};

class Boja {

	int red;
	int green;
	int blue;

public:
	Boja(int r, int g, int b);
	bool operator==(Boja& b)const;
	Boja& operator+(Boja& b);
	friend ostream& operator<<(ostream& it, Boja& b);
};

#endif // !_boja_h_
