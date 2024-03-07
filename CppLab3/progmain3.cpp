#include <iostream>
using namespace std;

#include "lotnisko.h"
#include "samolot.h"

int main()
{
	//polskie litery w konsoli
	setlocale(LC_ALL, "polish");

	cout << "ETAP 1 ----------------------------------------"<< endl;
	
	cout << "Samolot 1: " << endl;
	Samolot s1;

	cout << s1 << endl;
	s1.przygotuj_do_startu(0, 20, "Radom");
	cout << s1 << endl;;
	s1.start();
	cout << s1 << endl;;
	s1.laduj();
	cout << s1 << endl;		//wyl�dowa�
	
	s1.przygotuj_do_startu(22, 49, "Krak�w");
	cout << s1 << endl;;
	s1.start();
	cout << s1 << endl;;

	Samolot s2,s3;
	s2.start();	//niepowodzenie
	cout << endl << "Samolot 2: " << endl;
	cout << s2 << endl;;

	s3.przygotuj_do_startu(0,33,"Warszawa");
	cout << endl << "Samolot 3: " << endl;
	cout << s3 << endl;;
	s3.start();
	cout << s3 << endl;;

	cout << endl << "STATYSTYKA: " << endl;
	cout << "s1 startowa� " << s1.pobierz_starty() << " razy" << endl;	//2
	cout << "s2 startowa� " << s2.pobierz_starty() << " razy" << endl;	//0
	cout << "s3 startowa� " << s3.pobierz_starty() << " razy" << endl;	//1
	cout << "Wszystkich start�w " << s1.start() << endl;	//3: 2 razy s1, 1 raz s3
	cout << "Samolot�w w powietrzu " << Samolot::pobierz_liczba_w_powietrzu() << endl;	//2: s1, s3


	cout << endl << "ETAP 2 ----------------------------------------" << endl << endl;
	/*
	Lotnisko lot_1;
	lot_1 += s1;	//leci i wyl�dowa�
	lot_1 += s2;
	lot_1 += s3;	//leci i wyl�dowa�
	Samolot s4;
	lot_1 += s4;
	cout << lot_1 << endl;

	s4.przygotuj_do_startu(0,44,"Wroc�aw");
	s1.przygotuj_do_startu(14, 33, "Katowice");
	s2.przygotuj_do_startu(0, 21, "Gda�sk");
	cout << lot_1 << endl;

	cout << "Start samolotu s1 z lotniska 1:" << endl;
	if(lot_1.zezwol_na_start(s1))
		cout << s1 << " z lotniska nr 1" << endl;
	else
		cout << s1 << ", wi�c nie mo�e wystartowa� ponownie" << endl;

	cout << "Pr�ba ponownego wystartowania samolotu s1 :" << endl;
	if (lot_1.zezwol_na_start(s1))
		cout << s1 << " z lotniska nr 1" << endl;
	else
		cout << s1 << " wi�c nie mo�e wystartowa� ponownie" << endl;

	cout << lot_1 << endl;
	//--------------------------------------------------------
	cout << endl << "Przygotowanie samolot�w na lotnisko 2:" << endl;
	Samolot s5, s6, s7, s8, s9, s10, s11;
	s5.przygotuj_do_startu(0, 77, "Koluszki");
	s5.start();
	s6.przygotuj_do_startu(0, 45, "Modlin");
	s6.start();
	s7.przygotuj_do_startu(0, 73, "Rzesz�w");
	s7.start();
	s8.przygotuj_do_startu(0, 99, "Suwa�ki");
	s8.start();
	s9.przygotuj_do_startu(0, 12, "Pozna�");
	s9.start();
	s9.przygotuj_do_startu(0, 12, "Pozna�");
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
	cout << s9 << endl;
	cout << s10 << endl;
	cout << s11 << endl;
	Lotnisko lot_2;
	lot_2 += s10;
	lot_2 += s11;
	if (!(lot_2 += s5)) lot_2.przekieruj(s5, "Warszawa");
	if (!(lot_2 += s6)) lot_2.przekieruj(s6, "Warszawa");
	if (!(lot_2 += s7)) lot_2.przekieruj(s7, "Warszawa");
	if (!(lot_2 += s8)) lot_2.przekieruj(s8, "Warszawa");
	cout << lot_2 << endl;
	cout << "Przekierowany: " << endl;
	cout << s8 << endl;

	cout << endl << "Statystyka: " << endl;
	cout << "Wszystkich startow " << s8.start() << endl;
	cout << "Samolotow w powietrzu " << Samolot::pobierz_liczba_w_powietrzu() << endl;


	cout << endl << "ETAP 3 ----------------------------------------" << endl << endl;

	cout << s1 << endl;
	for (int i = 0; i < Samolot::MAX_LICZBA_STARTOW; i++)
	{
		lot_1.zezwol_na_start(s1);
		lot_1 += s1;
		if (s1.pobierz_starty() >= Samolot::MAX_LICZBA_STARTOW) break;
		s1.przygotuj_do_startu(0, 1, "Szczecin");
	}
	cout << s1 << endl;
	cout << "s1 wylatywa� " << s1.pobierz_starty() << " razy" << endl;
	
	for (int i = 0; i < Samolot::MAX_LICZBA_STARTOW; i++)
	{
		lot_1.zezwol_na_start(s4);
		lot_1 += s4;
		if (s4.pobierz_starty() >= Samolot::MAX_LICZBA_STARTOW) break;
		s4.przygotuj_do_startu(0, 2, "Opole");
	}
	cout << s4 << endl;
	cout << "s4 wylatywa� " << s4.pobierz_starty() << " razy" << endl;

	cout << endl << "Samoloty przed napraw�: ";
	cout << lot_1 << endl;

	////////////////////////////////////////////////////////////////////////////////////
	// co trzeba dopisa� do klas, by poni�szy fragment by� poprawny?
	for (int i = 0; i < lot_1.pobierz_liczba_samolotow(); i++)
	{
		if (lot_1[i]->pobierz_starty() >= Samolot::MAX_LICZBA_STARTOW) lot_1.naprawa(*(lot_1[i]));
	}
	////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "Samoloty po naprawie: ";
	cout << lot_1 << endl;
	*/
	
}