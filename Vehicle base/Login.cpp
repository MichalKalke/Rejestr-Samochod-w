#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <list>

#include "Login.h"
#include "Menu.h"
#include "User.h"
#include "Vehicle.h"

using namespace std;

Login::Login(int userIDT, string passwordT, bool isAdminT) {
	this->userID = userIDT;
	this->userPassword = passwordT;
	this->isAdmin = isAdminT;
}

bool Login::isIdNumber(string str) {
	regex pattern("\\d{6}");
	if (regex_match(str, pattern)) {
		return true;
	}
	return false;
}

void Login::show() {
	cout << this->userID << this->userPassword << this->isAdmin << endl;
}

void Login::setPassword(string password) {
	userPassword = password;
}

void Login::addToList(Login& userT, list<Login>& listOfUserT) {
	listOfUserT.push_back(userT);
}

void Login::addFromFile(list<Login>& listOfUsersT) {
	ifstream file;
	int userIDT;
	string passwordT;
	bool isAdminT;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	file.open("users.txt", ios::in);
	try {
		while (!file.eof()) {
			file >> userIDT >> passwordT >> isAdminT;
			Login userT(userIDT, passwordT, isAdminT);
			addToList(userT, listOfUsersT);
		}
		file.close();
	}
	catch (ifstream::failure e) {
		cerr << "Blad odczytuL/zamkniecia pliku\n";
	}
}


void Login::show(list<Login> listOfUserT) {
	list<Login>::iterator itr;
	for (itr = listOfUserT.begin(); itr != listOfUserT.end(); ++itr) {
		cout << itr->getUserID() << " " << itr->getPassword() << " " << itr->getIsAdmin() << endl;
	}
}

int Login::searchForUser(Login& userT, list<Login>& listOfUsersT, int numer, string password, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	Menu menuT;
	list<Login>::iterator itr = listOfUsersT.begin();
	while (itr != listOfUsersT.end()) {
		if (itr->userID == numer && itr->userPassword == password) {
			if (itr->isAdmin == 1) {
				Login adminUser(itr->userID, itr->userPassword, itr->isAdmin);
				adminUserMenu(adminUser, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
				return 0;
			}
			if (itr->isAdmin == 0) {
				Login normalUser(itr->userID, itr->userPassword, itr->isAdmin);
				normalUserMenu(normalUser, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
				return 0;
			}
		}
		if (itr->userID == numer && itr->userPassword != password) {
			cout << "Bledne haslo! Sprobuj ponownie:\n";
			menuT.login(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
			return 0;
		}
		++itr;
	}
	cout << "Nie ma takiego uzytkownika...\n";
	menuT.login(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
	return 0;
}

void Login::normalUserMenu(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	Menu menuT;
	cout << "Witaj uzytkowniku " << userT.userID << "\nCo chcesz zrobic?\n";
	cout << "Wcisnij:\n1 aby wyswietlic baze pojazdow\n2 aby wyswietlic baze osob\n3 zmiana hasla\n4 wyszukaj jakie sa pojazdy w danej miejscowosci\n5 wyswietl swoje samochody\n6 kto jest wlascicielem danej marki\n7 wyszukaj pojazdy danej osoby\n";
	menuT.userChoice(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
}

void Login::changePassword(Login& userT, string password, list<Login>& listOfUsersT) {
	list<Login>::iterator itr = listOfUsersT.begin();
	while (itr != listOfUsersT.end()) {
		if (itr->userID == userT.userID) {
			itr->userPassword = password;
			userT.userPassword = password;
		}
		++itr;
	}
}

void Login::toFile(list<Login>& listOfUsersT, Login& userT) {
	fstream file;
	list<Login>::iterator itr = listOfUsersT.begin();
	int howManyItr = 0;
	int lastItr = listOfUsersT.size() - 1;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	file.open("users.txt", ios::out);
	try {
		while (itr != listOfUsersT.end()) {
			if (howManyItr == lastItr) {
				file << itr->userID << " " << itr->userPassword << " " << itr->isAdmin;
				++itr;
			}
			else {
				file << itr->userID << " " << itr->userPassword << " " << itr->isAdmin << "\n";
				++itr;
				++howManyItr;
			}
		}
		file.close();
	}
	catch (ifstream::failure e) {
		cerr << "Blad zapisuL/zamkniecia pliku\n";
	}
}

void Login::adminUserMenu(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	Menu menuT;
	cout << "Witaj adminie " << userT.userID << "\nCo chcesz zrobic?\n";
	cout << "Wcisnij:\n1 aby wyswietlic baze pojazdow\n2 aby wyswietlic baze osob\n3 zmiana hasla\n4 wyszukaj jakie sa pojazdy w danej miejscowosci\n5 wyswietl swoje samochody\n6 kto jest wlascicielem danej marki\n7 wyszukaj pojazdy danej osoby\n\nDodatkowe funkcje admina:\n\n8 zmiana hasla uzytkownika\n9 wyswietlenie polaczen miedzy pojazdami, a osobami\n10 dodanie nowej osoby do bazy\n11 usuniecie osoby z bazy\n12 dodawanie pojazdu do osoby\n13 usuniecie pojazdu osobie\n14 dodanie uzytkownika\n15 usuniecie uzytkownika\n16 dodanie pojazdu do bazy\n17 usuniecie pojazdu z bazy\n";
	menuT.userChoice(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
}

bool Login::isUserInBase(list<Login>& listOfUsersT, int id) {
	list<Login>::iterator itr = listOfUsersT.begin();
	while (itr != listOfUsersT.end()) {
		if (itr->getUserID() == id) {
			return true;
		}
		++itr;
	}
	return false;
}

void Login::changeAnyPassword(Login& userT, int id, string password, list<Login>& listOfUsersT) {
	list<Login>::iterator itr = listOfUsersT.begin();
	while (itr != listOfUsersT.end()) {
		if (itr->getUserID() == id) {
			itr->setPassword(password);
		}
		++itr;
	}
}

void Login::deleteFromBase(Login& userT, int id, list<Login>& listOfUsersT) {
	list<Login>::iterator itr = listOfUsersT.begin();
	while (itr != listOfUsersT.end()) {
		if (itr->getUserID() == id) {
			listOfUsersT.erase(itr);
			break;
		}
		++itr;
	}
}

bool Login::isIdInBase(list<Login>& listOfUsersT, int idT) {
	list<Login>::iterator itr = listOfUsersT.begin();
	while (itr != listOfUsersT.end()) {
		if (itr->getUserID() == idT) {
			return false;
		}
		++itr;
	}
	return true;
}

void Login::addUser(list<Login>& listOfUsersT) {
	string sId;
	string passwordT;
	cout << "Podaj ID uzytkownika (pamietaj, ze to liczba szesciocyfowa), a nastepnie jego haslo\nID: ";
	cin >> sId;
	if (!isIdNumber(sId)) {
		cout << "ID uzytkownika nie jest liczba szesciocyfrowa!\nSprobuj ponownie\n";
		addUser(listOfUsersT);
	}
	else {
		int idT = stoi(sId);
		if(!isIdInBase(listOfUsersT, idT)) {
			cout << "W bazie istnieje juz uzytkownik o podanym id\n";
			addUser(listOfUsersT);
		}
		else {
			cout << "\nHaslo: ";
			cin >> passwordT;
			cout << "\n";
			Login newUser(idT, passwordT, 0);
			addToList(newUser, listOfUsersT);
			toFile(listOfUsersT, newUser);
		}
	}
}
