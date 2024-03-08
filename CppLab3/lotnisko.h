#pragma once
#include <iostream>	

class Samolot;

class Lotnisko
{
private:
	const int id_lotniska;
	static int max_id_lotniska;

	int liczba_samolotow;

	static const int MAX_LICZBA_SAMOLOTOW = 5;
	Samolot* samoloty[MAX_LICZBA_SAMOLOTOW]{ nullptr };

public:
	Lotnisko();

	bool operator+=(Samolot& s);
	bool zezwol_na_start(Samolot& s);
	void przekieruj(Samolot& s, const char* port);
	int pobierz_liczba_samolotow();

	void naprawa(Samolot& s) const;

	//uzupe�nij potrzeba? (ETAP 3)
	friend std::ostream& operator<<(std::ostream& out, Lotnisko& lotnisko);
	Samolot* operator[](int i);
};