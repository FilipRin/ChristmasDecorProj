#pragma once
#pragma once
#ifndef _lista_h_
#define _lista_h_
#include<exception>
using namespace std;

class GNepostojiTekuci :public exception {
public:
	const char* what()const override {
		return "***Ne postoji tekuci!";
	}
};

template<typename T>
class Lista
{
	struct Elem
	{
		T* t;
		Elem* next;
		Elem( T& tt) { t = &tt, next = nullptr; }
	};
	Elem* prvi, * poslednji;
	mutable Elem* tek;
	int br;

	void brisi();
public:
	Lista() { prvi = poslednji = tek = nullptr; br = 0; }
	Lista(const Lista& l) = delete;
	Lista& operator=(const Lista& l) = delete;

	int const dohvBroj()const { return br; }

	void operator<<=( T& t) {
		poslednji = (!prvi ? prvi : poslednji->next) = new Elem(t);
		br++;
	}
	void operator>>=( T& t) {
		if (!prvi) {
			prvi = poslednji = new Elem(t);
			br++;
		}
		else {
			Elem* temp = new Elem(t);
			temp->next = prvi;
			prvi = temp;
			br++;
		}
	}
	friend ostream& operator<<(ostream& it, Lista& l) {
		for (l.postaviNaPrvi(); l.postojiTek(); l.pomeriNaSledeci()) {
			it << l.dohvElem() <<endl;
		}
		return it;
	}

	Lista& postaviNaPrvi() {
		tek = prvi;
		return *this;
	}
	const Lista& postaviNaPrvi()const {
		tek = prvi;
		return *this;
	}
	Lista& pomeriNaSledeci() {
		if (!postojiTek()) throw new GNepostojiTekuci();
		tek = tek->next;
		return *this;
	}
	bool postojiTek() const{
		if (tek)return true;
		return false;
	}

	T& dohvElem()const {
		if (!postojiTek()) throw new GNepostojiTekuci();
		return *tek->t;
	}
	~Lista() { brisi(); }
};

#endif // !_lista_h_

template<typename T>
void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	poslednji = tek = nullptr;
}
