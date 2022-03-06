#include <iostream>
#include<iterator>
#include<string>
#include <regex>
#include<fstream>
#include<sstream>
#include<list>

#include"Login.h"
#include"Menu.h"
#include "User.h"
#include "Vehicle.h"
#include "Connections.h"

using namespace std;

void Vehicle::print() {
	cout << "-------------------------------\n";
	cout << id << " " << typeOfVehicle << "\n" << brand << " " << model << "\nmoc: " << horsePower << " uklad silnika: " << engine << " kolor: " << colour << endl;
}

void Vehicle::printForUser() {
	cout << "-------------------------------\n";
	cout << typeOfVehicle << "\n" << brand << " " << model << "\nmoc: " << horsePower << " uklad silnika: " << engine << " kolor: " << colour << endl;
}

void Vehicle::addToVehicleList(list<Vehicle>& listOfVehiclesT, Vehicle& vehicleT) {
	listOfVehiclesT.push_back(vehicleT);
}

void Vehicle::addFromFile(list<Vehicle>& listOfVehiclesT) {
	ifstream file;
	int ID, power;
	string typeOfVehicleT, brandT, modelT, engineT, colourT;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	file.open("vehicles.txt", ios::in);
	try {
		while (!file.eof()) {
			file >> ID >> typeOfVehicleT >> brandT >> modelT >> power >> engineT >> colourT;
			Vehicle vehicleT(ID, typeOfVehicleT, brandT, modelT, power, engineT, colourT);
			addToVehicleList(listOfVehiclesT, vehicleT);
		}
		file.close();
	}
	catch (ifstream::failure e) {
		cerr << "Blad odczytuV/zamkniecia pliku\n";
	}
}

void Vehicle::showVehicles(list<Vehicle> listOfVehiclesT, int isAdmin) {
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	while (itr != listOfVehiclesT.end()) {
		isAdmin == 1 ? itr->print() : itr->printForUser();
		++itr;
	}
}

void Vehicle::showUserVehicles(list<Vehicle> listOfVehiclesT, int idV) {
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	while (itr != listOfVehiclesT.end()) {
		if (idV == itr->id) {
			itr->print();
			break;
		}
		++itr;
	}
}

bool Vehicle::isVehicleInBase(list<Vehicle>& listOfVehiclesT, int idT) {
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	while (itr != listOfVehiclesT.end()) {
		if (itr->id == idT) {
			return true;
		}
		++itr;
	}
	return false;
}

void Vehicle::toFile(list<Vehicle>& listOfVehiclesT) {
	fstream file;
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	int howManyItr = 0;
	int lastItr = listOfVehiclesT.size() - 1;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	file.open("vehicles.txt", ios::out);
	try {
		while (itr != listOfVehiclesT.end()) {
			if (howManyItr == lastItr) {
				file << itr->id << " " << itr->typeOfVehicle << " " << itr->brand << " " << itr->model << " " << itr->horsePower << " " << itr->engine << " " << itr->colour;
				++itr;
			}
			else {
				file << itr->id << " " << itr->typeOfVehicle << " " << itr->brand << " " << itr->model << " " << itr->horsePower << " " << itr->engine << " " << itr->colour << "\n";
				++itr;
				++howManyItr;
			}
		}
		file.close();
	}
	catch (ifstream::failure e) {
		cerr << "Blad zapisuV/zamkniecia pliku\n";
	}
}


void Vehicle::addNewVehicle(list<Vehicle>& listOfVehiclesT) {
	string idT, typeOfVehicleT, brandT, modelT, powerT, engineT, colourT;
	int idN, powerN;
	Menu menuT;
	regex ptrnID("\\d+");
	regex ptrnPower("\\d{1,4}");
	regex ptrnEngine("\\w\\d{1,2}");
	cout << "Podaj ID pojazdu: ";
	cin >> idT;
	if (!menuT.checkWithPattern(idT, ptrnID)) {
		cout << "Niepoprawny format id pojazdu\n";
		addNewVehicle(listOfVehiclesT);
	}
	else {
		idN = stoi(idT);
		if (isVehicleInBase(listOfVehiclesT, idN)) {
			cout << "Podane id wystepuje w bazie\n";
			addNewVehicle(listOfVehiclesT);
		}
		else {
			cout << "Podaj typ pojazdu: ";
			cin >> typeOfVehicleT;
			cout << "Podaj marke pojazdu: ";
			cin >> brandT;
			cout << "Podaj model pojazdu: ";
			cin >> modelT;
			cout << "Podaj moc pojazdu: ";
			cin >> powerT;
			cout << "Podaj uklad silnika pojazdu: ";
			cin >> engineT;
			cout << "Podaj kolor pojazdu: ";
			cin >> colourT;
			if (menuT.checkWithPattern(powerT, ptrnPower) && (menuT.checkWithPattern(engineT, ptrnEngine) || engineT == "elektryk")) {
				powerN = stoi(powerT);
				cout << "Pomyslnie dodano\n";
				Vehicle vehicleT(idN, typeOfVehicleT, brandT, modelT, powerN, engineT, colourT);
				addToVehicleList(listOfVehiclesT, vehicleT);
				toFile(listOfVehiclesT);
			}
			else {
				cout << "Dane nieporawne ze wzorcem - moc liczba 4 cyfrowa; silnik w formacie ukladIloscCylindrow np. W16\n";
				addNewVehicle(listOfVehiclesT);
			}
		}
	}
}

void Vehicle::deleteFromList(list<Vehicle>& listOfVehiclesT, int idT) {
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	while (itr != listOfVehiclesT.end()) {
		if (itr->id == idT) {
			listOfVehiclesT.erase(itr);
			break;
		}
		++itr;
	}
}

int Vehicle::deleteVehicle(list<Vehicle>& listOfVehiclesT) {
	string idT;
	int id;
	regex ptrnId("\\d+");
	Menu menu;
	cout << "Podaj numer id pojazdu do usuniecia (jesli chcesz zakonczyc wpisz 'stop'): ";
	cin >> idT;
	if (idT == "stop") return NULL;
	if (!menu.checkWithPattern(idT, ptrnId)) {
		cout << "Nieprawidlowy numer id\n";
	}
	else {
		id = stoi(idT);
		if (!isVehicleInBase(listOfVehiclesT, id)) {
			cout << "Brak pojazdu o podanym id\n";
			deleteVehicle(listOfVehiclesT);
		}
		else {
			deleteFromList(listOfVehiclesT, id);
			toFile(listOfVehiclesT);
			return id;
		}
	}
	return NULL;
}

int Vehicle::searchForVehicle(list<Vehicle> listOfVehiclesT, string brandT) {
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	while (itr != listOfVehiclesT.end()) {
		if (itr->brand == brandT) return itr->id;
		itr++;
	}
	return NULL;
}

void Vehicle::showVehicle(list<Vehicle> listOfVehiclesT, int isAdmin, int idV) {
	list<Vehicle>::iterator itr = listOfVehiclesT.begin();
	while (itr != listOfVehiclesT.end()) {
		if (itr->id == idV) isAdmin == 1 ? itr->print() : itr->printForUser();
		++itr;
	}
}