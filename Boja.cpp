#include"Boja.h"
Boja::Boja(int r, int g, int b)
{
	try {
		if ((r < 0 || r>255) && (g < 0 || g>255) && (b < 0 || b>255)) throw new GLosaVrednost();
		this->red = r;
		this->green = g;
		this->blue = b;
	}
	catch (exception e) {}
}

bool Boja::operator==(Boja& b) const
{
	if (this->red == b.red && this->green == b.green && this->blue == b.blue)return true;
	return false;
}

Boja& Boja::operator+(Boja& b)
{
	int rpom, bpom, gpom;
	rpom = (this->red + b.red) / 2;
	gpom = (this->green + b.green) / 2;
	bpom = (this->blue + b.blue) / 2;
	return *new Boja(rpom, gpom, bpom);
}

ostream& operator<<(ostream& it, Boja& b)
{
	it << "(" << b.red << "," << b.green << "," << b.blue << ")";
	return it;
}
