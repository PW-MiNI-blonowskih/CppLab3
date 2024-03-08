#include "lotnisko.h"
#include "samolot.h"

int Lotnisko::max_id_lotniska = 0;

Lotnisko::Lotnisko() :
	id_lotniska { max_id_lotniska + 1 },
	liczba_samolotow { 0 }
{
	for (int i = 0; i < MAX_LICZBA_SAMOLOTOW; i++) {
		samoloty[i] = nullptr;
	}

	max_id_lotniska++;
}

bool Lotnisko::operator+=(Samolot& s) {
	if (!(s.status == Samolot::status_samolotu::ODLECIAL ||
		s.status == Samolot::status_samolotu::PO_NAPRAWIE)) {
		return false;
	}

	if (liczba_samolotow < MAX_LICZBA_SAMOLOTOW) {
		samoloty[liczba_samolotow] = &s;
		liczba_samolotow++;

		if (s.status == Samolot::status_samolotu::ODLECIAL) {
			s.laduj();
		}
	}

	return true;
}

bool Lotnisko::zezwol_na_start(Samolot& s) {
	for (int i = 0; i < MAX_LICZBA_SAMOLOTOW; i++) {
		if (samoloty[i] == &s) {
			s.start();
			samoloty[i] = nullptr;
			
			for (int j = i; j < MAX_LICZBA_SAMOLOTOW - 1; j++) {
				samoloty[j] = samoloty[j + 1];
			}
			samoloty[MAX_LICZBA_SAMOLOTOW - 1] = nullptr;

			return true;
		}
	}

	return false;
}

void Lotnisko::przekieruj(Samolot& s, const char* port) {
	if (s.status == Samolot::status_samolotu::ODLECIAL) {
		s.port_docelowy = port;
	}
}

std::ostream& operator<<(std::ostream& out, Lotnisko& lotnisko) {
	out << "Samoloty na lotnisku nr " << lotnisko.id_lotniska << ":" << std::endl;

	int i = 0;
	while (i < lotnisko.MAX_LICZBA_SAMOLOTOW && lotnisko.samoloty[i] != nullptr) {
		out << *(lotnisko.samoloty[i]) << std::endl;
		i++;
	}

	return out;
}
