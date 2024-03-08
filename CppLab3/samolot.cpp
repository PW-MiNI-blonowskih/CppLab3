#include <iostream>
#include "samolot.h"

int Samolot::max_id = 0;
int Samolot::liczba_samolotow_w_powietrzu = 0;

Samolot::Samolot() :
	liczba_pasazerow{ 0 },
	liczba_startow{ 0 },
	status{ status_samolotu::PO_NAPRAWIE },
	port_docelowy{ nullptr },
	id{ ++max_id }
{}

void Samolot::przygotuj_do_startu(int wysiada, int wsiada, const char* port) {
	if (!(status == status_samolotu::WYLADOWAL || status == status_samolotu::PO_NAPRAWIE))
		return;

	if (liczba_pasazerow < wysiada) {
		liczba_pasazerow = 0;
		// std::cout << "ERROR:\tWysiadlo wiecej osob niz jest na pokladzie" << std::endl << "\tliczba pasazerow ustawiona na 0" << std::endl;
	} 
	else {
		liczba_pasazerow -= wysiada;
	}

	if (liczba_pasazerow + wsiada > MAX_LICZBA_PASAZEROW) {
		liczba_pasazerow = MAX_LICZBA_PASAZEROW;
		// std::cout << "ERROR:\tZa duzo pasazerow, liczba ustawiona na MAX" << std::endl;
	}
	else {
		liczba_pasazerow += wsiada;
	}

	port_docelowy = port;
	status = status_samolotu::GOTOWY;
}

int Samolot::start() {
	static unsigned int liczba_startow_razem;

	if (status != status_samolotu::GOTOWY)
		return liczba_startow_razem;

	status = status_samolotu::ODLECIAL;
	++liczba_startow;
	++liczba_startow_razem;
	++liczba_samolotow_w_powietrzu;

	return liczba_startow_razem;
}

void Samolot::laduj() {
	if (status != status_samolotu::ODLECIAL)
		return;

	status = status_samolotu::WYLADOWAL;
	--liczba_samolotow_w_powietrzu;
}

std::ostream& operator<<(std::ostream& out, const Samolot& samolot) {
	std::ostream& returnStream = out << "Samolot nr " << samolot.id << " do " <<
		(samolot.port_docelowy != nullptr ? samolot.port_docelowy : "BRAK") <<
		" z " << samolot.liczba_pasazerow << " pasazerami na pokladzie ";

	switch (samolot.status)
	{
	case Samolot::status_samolotu::GOTOWY:
		return returnStream << "przygotowany do startu";
		break;
	case Samolot::status_samolotu::ODLECIAL:
		return returnStream << "odlecial";
		break;
	case Samolot::status_samolotu::PO_NAPRAWIE:
		return returnStream << "po naprawie";
		break;
	case Samolot::status_samolotu::WYLADOWAL:
		return returnStream << "wyladowal";
		break;
	default:
		return returnStream;
		break;
	}
}

int Samolot::pobierz_starty() const {
	return liczba_startow;
}

int Samolot::pobierz_liczba_w_powietrzu() {
	return liczba_samolotow_w_powietrzu;
}