#pragma once
#include "Boja.h"
#ifndef _ukras_h_
#define _ukras_h_

class Ukras {
	int masa;
	Boja boja;
protected:
	virtual void pisi(ostream& it);
public:
	Ukras(Boja& b, int g) :boja(b), masa(g) {}
	int dohvMasu()const { return masa; }
	Boja& dohvBoju() { return boja; }
	friend ostream& operator<<(ostream& it, Ukras& u);
};

#endif // !_ukras_h_
