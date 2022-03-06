#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>

#include "Connections.h"
#include "Login.h"
#include "Menu.h"
#include "User.h"
#include "Vehicle.h"

using namespace std;

void Connections::print() {
	cout << "-------------------------------\n";
	cout << id << " - " << vehicleId << endl;
}

void Connections::addToConnectionsList(list<Connections>& listOfContsT, Connections& connectionT) {
	listOfContsT.push_back(connectionT);
}

void Connections::addFromFile(list<Connections>& listOfContsT) {
	ifstream file;
	int personIdT, vehicleIdT;

	file.open("connections.txt", ios::in);
	if(file.good()) {
		while (file >> personIdT >> vehicleIdT) {
			Connections connection(personIdT, vehicleIdT);
			addToConnectionsList(listOfContsT, connection);
		}
		file.close();
	}
}

void Connections::showConnections(list<Connections> listOfContsT) {
	list<Connections>::iterator itr = listOfContsT.begin();
	while (itr != listOfContsT.end()) {
		itr->print();
		++itr;
	}
}

bool Connections::checkIfConnectionExists(list<Connections>& listOfContsT, int idP, int idV) {
	list<Connections>::iterator itr = listOfContsT.begin();
	while (itr != listOfContsT.end()) {
		if (itr->id == idP && itr->vehicleId == idV) {
			return true;
		}
		++itr;
	}
	return false;
}

void Connections::toFile(list<Connections>& listOfContsT) {
	fstream file;
	list<Connections>::iterator itr = listOfContsT.begin();
	int howManyItr = 0;
	int lastItr = listOfContsT.size() - 1;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	file.open("connections.txt", ios::out);
	try {
		while (itr != listOfContsT.end()) {
			if (howManyItr == lastItr) {
				file << itr->id << " " << itr->vehicleId;
				++itr;
			}
			else {
				file << itr->id << " " << itr->vehicleId << "\n";
				++itr;
				++howManyItr;
			}
		}
		file.close();
	}
	catch (ifstream::failure e) {
		cerr << "Blad zapisuC/zamkniecia pliku\n";
	}
}

void Connections::addConnection(list<Connections>& listOfContsT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT) {
	string idPT, idVT;
	int idP, idV;
	Person person;
	Menu menu;
	Vehicle vehicle;
	regex idPPtrn("\\d{6}");
	regex idVPtrn("\\d+");
	cout << "Podaj najpierw ID uzytkownika (liczba szesciocyfrowa): ";
	cin >> idPT;
	cout << "Podaj ID pojazdu: ";
	cin >> idVT;
	if (menu.checkWithPattern(idPT, idPPtrn) && menu.checkWithPattern(idVT, idVPtrn)) {
		idP = stoi(idPT);
		idV = stoi(idVT);
		if (person.isPersonInBase(listOfPersonsT, idP) && vehicle.isVehicleInBase(listOfVehiclesT, idV)) {
			if (!checkIfConnectionExists(listOfContsT, idP, idV)) {
				Connections connection(idP, idV);
				addToConnectionsList(listOfContsT, connection);
				toFile(listOfContsT);
				cout << "Operacja wykonana pomyslnie\n";
			}
			else {
				cout << "Podana osoba jest juz wlascicielem pojazdu\n";
			}
		}
		else {
			cout << "Nie ma uzytkownika badz pojazdu o podanym id\n";
			addConnection(listOfContsT, listOfVehiclesT, listOfPersonsT);
		}
	}
	else {
		cout << "Blad formatu id - id persony liczba szesciocyfrowa, id pojazdu liczba\n";
		addConnection(listOfContsT, listOfVehiclesT, listOfPersonsT);
	}
}

void Connections::deleteWhenVehicle(list<Connections>& listOfContsT, int idV) { 
	list<Connections>::iterator itr = listOfContsT.begin();
	list<Connections>::iterator itr2;
	if (idV == NULL) return;
	while (itr != listOfContsT.end()) {
		if (itr->vehicleId == idV) {
			itr2 = itr;
			itr++;
			listOfContsT.erase(itr2);
			if (itr == listOfContsT.end()) break;
		}
		++itr;
	}
	toFile(listOfContsT);
}

void Connections::deleteWhenPerson(list<Connections>& listOfContsT, int idP) {
	list<Connections>::iterator itr = listOfContsT.begin();
	list<Connections>::iterator itr2;
	if (idP == NULL) return;
	while (itr != listOfContsT.end()) {
		if (itr->id == idP) {
			itr2 = itr;
			itr++;
			listOfContsT.erase(itr2);
			if (itr == listOfContsT.end()) break;
		}
		++itr;
	}
	toFile(listOfContsT);
}

void Connections::deleteFromList(list<Connections>& listOfContsT, int idP, int idV) {
	list<Connections>::iterator itr = listOfContsT.begin();
	while (itr != listOfContsT.end()) {
		if (itr->id == idP && itr->vehicleId == idV) {
			listOfContsT.erase(itr);
			break;
		}
		++itr;
	}
}

void Connections::deleteConnection(list<Connections>& listOfContsT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT) {
	string idPT, idVT;
	int idP, idV;
	regex idPPtrn("\\d{6}");
	regex idVPtrn("\\d+");
	Menu menu;
	Vehicle vehicle;
	Person person;
	cout << "Podaj id osoby: ";
	cin >> idPT;
	cout << "Podaj id pojazdu: ";
	cin >> idVT;
	if (menu.checkWithPattern(idPT, idPPtrn) && menu.checkWithPattern(idVT, idVPtrn)) {
		idP = stoi(idPT);
		idV = stoi(idVT);
		if (!vehicle.isVehicleInBase(listOfVehiclesT, idV) || !person.isPersonInBase(listOfPersonsT, idP)) {
			cout << "Brak podanej osoby lub pojazdu w bazie\n";
			deleteConnection(listOfContsT, listOfVehiclesT, listOfPersonsT);
		}
		else {
			deleteFromList(listOfContsT, idP, idV);
			showConnections(listOfContsT);
			toFile(listOfContsT);
			cout << "Operacja wykonana poprawnie\n";
		}
	}
	else {
		cout << "Bledny format id - id osoby liczba szesciocyfrowa, id pojazdu musi byc liczba\n";
		deleteConnection(listOfContsT, listOfVehiclesT, listOfPersonsT);
	}
}

void Connections::showUserCars(list<Connections> listOfContsT, list<Vehicle> listOfVehiclesT, Login userT) {
	list<Connections>::iterator itr = listOfContsT.begin();
	Vehicle vehicle;
	while (itr != listOfContsT.end()) {
		if (itr->id == userT.getUserID()) {
			vehicle.showUserVehicles(listOfVehiclesT, itr->vehicleId);
		}
		++itr;
	}
}

int Connections::findUserByVehicle(list<Connections> listOfContsT, int idV) {
	list<Connections>::iterator itr = listOfContsT.begin();
	while (itr != listOfContsT.end()) {
		if (itr->vehicleId == idV) return itr->id;
		++itr;
	}
	return NULL;
}

void Connections::findVehicleByUser(list<Connections> listOfContsT, list<Vehicle> listOfVehiclesT,int isAdmin, int idP) {
	list<Connections>::iterator itr = listOfContsT.begin();
	int idV = 0;
	Vehicle vehicle;
	while (itr != listOfContsT.end()) {
		if (itr->id == idP) {
			idV = itr->vehicleId;
			vehicle.showVehicle(listOfVehiclesT, isAdmin, idV);
		}
		++itr;
	}
}
