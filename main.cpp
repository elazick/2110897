#include "strukt.h"

int main() {
	studentas duom;
	std::vector<studentas>stud_arr;
	std::list<studentas>stud_list;
	std::string pasirinkimas;
	std::cout << "Laba diena!" << std::endl;
	std::cout << "Ar atlikti laiko tyrima?(T/N)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "T" || pasirinkimas == "t") {
		std::cout << "Rezultata skaiciuoti naudojant vidurki ar mediana?(V/M)";
		std::cin >> pasirinkimas;
		std::cout << std::left << std::setw(25) << "Irasu skaicius faile" << std::left << std::setw(15) << "List" << std::left << std::setw(15) << "Vector" << std::endl;
		std::cout << std::left << std::setw(25) << "1000" << std::left << std::setw(15) << list_laikas(1000,pasirinkimas) << std::left << std::setw(15) << vektoriaus_laikas(1000,pasirinkimas) << std::endl;
		std::cout << std::left << std::setw(25) << "10000" << std::left << std::setw(15) << list_laikas(10000,pasirinkimas) << std::left << std::setw(15) << vektoriaus_laikas(10000,pasirinkimas) << std::endl;
		std::cout << std::left << std::setw(25) << "100000" << std::left << std::setw(15) << list_laikas(100000,pasirinkimas) << std::left << std::setw(15) << vektoriaus_laikas(100000,pasirinkimas) << std::endl;
		std::cout << std::left << std::setw(25) << "1000000" << std::left << std::setw(15) << list_laikas(1000000,pasirinkimas) << std::left << std::setw(15) << vektoriaus_laikas(1000000,pasirinkimas) << std::endl;
		std::cout << std::left << std::setw(25) << "10000000"<< std::left << std::setw(15) << list_laikas(10000000,pasirinkimas) << std::left << std::setw(15) << vektoriaus_laikas(10000000,pasirinkimas) << std::endl;
		std::cout << std::endl;

	}
	else if (pasirinkimas == "n" || pasirinkimas == "N") {
		std::cout << "Generuoti failus atsitiktinai?(T/N)";
		std::cin >> pasirinkimas;
		if (pasirinkimas == "T" || pasirinkimas == "t") {
			int a;
			std::cout << "Kiek duomenu generuoti?";
			std::cin >> a;
			stud_gen(a);
			stud_arr = gen_nuskaitymas(a);
			gen_irasymas(stud_arr, std::to_string(a));
			std::cout << std::endl;
			exit(0);
		}
		else if (pasirinkimas == "N" || pasirinkimas == "n") {
			std::cout << "Ar norite duomenis skaityti is failo?(T/N)";
			std::cin >> pasirinkimas;
			if (pasirinkimas == "T" || pasirinkimas == "t") {
				stud_arr = read_from_file(stud_arr);
				write_to_file(stud_arr);
				std::cout << "\n" << "Rezultatu failas vadinasi 'rezultatai.txt' ji rasite C : disko paieskoje ivede pavadinima." << std::endl << std::endl;;
				std::cout << "Spauskite bet kuri mygtuka programai uzdaryti" << std::endl;
			}
			else if (pasirinkimas == "N" || pasirinkimas == "n") {
				bool vedimas = true;
				while (vedimas) {
					duom = stud();
					std::cout << "Ar vesite dar duomenu?(T/N)";
					std::cin >> pasirinkimas;
					if (pasirinkimas == "T" || pasirinkimas == "t") {
						vedimas = true;
					}
					else if (pasirinkimas == "n" || pasirinkimas == "N") {
						vedimas = false;
					}
					else {
						std::cout << "KLAIDA";
						return 0;
					}
					stud_arr.push_back(duom);
				}
				for (int i = 0; i < stud_arr.size(); i++) {
					std::cout << "Vardas\t" << "Pavarde\t" << "Rezultatas\t" << std::endl;
					std::cout << stud_arr[i].vardas << "\t" << stud_arr[i].pavarde << "\t" << stud_arr[i].rezultatas << std::endl << std::endl;
				}
				std::cout << "Spauskite bet koki mygtuka programai uzdaryti";
			}
			else std::cout << "KLAIDA!" << std::endl;
			exit(0);
		}
		else std::cout << "KLAIDA!" << std::endl;
		exit(0);
	}
	
}