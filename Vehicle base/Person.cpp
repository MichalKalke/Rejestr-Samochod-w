#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include "Person.h"
#include "Menu.h"
#include "Login.h"
#include "User.h"


using namespace std;

void Person::print() {
	cout << "-------------------------------\n";
	cout << id << "\n" << name << " " << lastName << " " << birthYear << "\n" << phoneNumber << "\n" << mail << "\n" << city << "\n" << street << " " << houseNumber << endl;
}

void Person::printForUser() {
	cout << "-------------------------------\n";
	cout << name << " " << lastName << "\n" << city << endl;
}

void Person::addToPersonList(list<Person>& listOfPeronsT, Person& personsT) {
	listOfPeronsT.push_back(personsT);
}

bool Person::isPersonInBase(list<Person>& listOfPeronsT, int idT) {
	list<Person>::iterator itr = listOfPeronsT.begin();
	while (itr != listOfPeronsT.end()) {
		if (itr->id == idT) {
			return true;
		}
		++itr;
	}
	return false;
}

void Person::addFromFile(list<Person>& listOfPeronsT) {
	ifstream file;
	int idT, phoneNumberT, birthYearT;
	string nameT, lastNameT, mailT, cityT, streetT, houseNumberT;

	file.open("persons.txt", ios::in);
	if(file.good()) {
		while (file >> idT >> nameT >> lastNameT >> mailT >> phoneNumberT >> birthYearT >> cityT >> streetT >> houseNumberT) {
			Person personT(idT, nameT, lastNameT, mailT, phoneNumberT, birthYearT, cityT, streetT, houseNumberT);
			addToPersonList(listOfPeronsT, personT);
		}
		file.close();
	}
	
}

void Person::showPersons(list<Person> listOfPeronsT, int isAdmin) {
	list<Person>::iterator itr = listOfPeronsT.begin();
	while (itr != listOfPeronsT.end()) {
		isAdmin == 1 ? itr->print() : itr->printForUser();
		++itr;
	}
}

void Person::toFile(list<Person>& listOfPeronsT) {
	fstream file;
	list<Person>::iterator itr = listOfPeronsT.begin();
	int howManyItr = 0;
	int lastItr = listOfPeronsT.size() - 1;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	file.open("persons.txt", ios::out);
	try {
		while (itr != listOfPeronsT.end()) {
			if (howManyItr == lastItr) {
				file << itr->id << " " << itr->name << " " << itr->lastName << " " << itr->mail << " " << itr->phoneNumber << " "<< itr->birthYear<< " " << itr->city << " " << itr->street << " " << itr->houseNumber;
				itr++;
			}
			else {
				file << itr->id << " " << itr->name << " " << itr->lastName << " " << itr->mail << " " << itr->phoneNumber << " " << itr->birthYear << " " << itr->city << " " << itr->street << " " << itr->houseNumber << "\n";
				itr++;
				howManyItr++;
			}
		}
		file.close();
	}
	catch (ifstream::failure e) {
		cerr << "Blad zapisuP/zamkniecia pliku\n";
	}
}

void Person::addNewPerson(list<Person>& listOfPeronsT) {
	string idT, nameT, lastNameT, birthYearT, phoneNumberT, mailT, cityT, streetT, houseNumberT;
	int idN, bYN, pNN;
	Menu menuT;
	regex ptrnID("\\d{6}");
	regex ptrnBD("\\d{4}");
	regex ptrnPN("\\d{9}");
	regex ptrnName("[A-Z]{1}[a-z]{1,15}");
	cin >> idT;
	if (!menuT.checkWithPattern(idT, ptrnID)) {
		cout << "Bledny numer lub format id (liczba szesciocyforwa)\n";
		addNewPerson(listOfPeronsT);
	} else {
		idN = stoi(idT);
		if (isPersonInBase(listOfPeronsT, idN)) {
			cout << "Osoba o podanym id juz istnieje\n";
			addNewPerson(listOfPeronsT);
		}
		else {
			cout << "Podaj imie: ";
			cin >> nameT;
			cout << "Nazwisko: ";
			cin >> lastNameT;
			cout << "Rok urodzenia: ";
			cin >> birthYearT;
			cout << "Numer telefonu: ";
			cin >> phoneNumberT;
			cout << "Mail: ";
			cin >> mailT;
			cout << "Miasto: ";
			cin >> cityT;
			cout << "Ulica: ";
			cin >> streetT;
			cout << "Numer domu: ";
			cin >> houseNumberT;
			if (menuT.checkWithPattern(nameT, ptrnName) && menuT.checkWithPattern(lastNameT, ptrnName) && menuT.checkWithPattern(birthYearT, ptrnBD) && menuT.checkWithPattern(phoneNumberT, ptrnPN)  && menuT.checkWithPattern(cityT, ptrnName) && menuT.checkWithPattern(streetT, ptrnName)) {
				cout << "Dodano pomyslnie\n";
				bYN = stoi(birthYearT);
				pNN = stoi(phoneNumberT);
				Person personT(idN, nameT, lastNameT, mailT, pNN, bYN, cityT, streetT, houseNumberT);
				addToPersonList(listOfPeronsT, personT);
				toFile(listOfPeronsT);
					
			}
			else {
				cout << "Blad wpisywania\nProsze sprobowac ponownie\n";
				addNewPerson(listOfPeronsT);
			}
		}
	}
}

void Person::deleteFromList(list<Person>& listOfPeronsT, int idT) {
	list<Person>::iterator itr = listOfPeronsT.begin();
	while (itr != listOfPeronsT.end()) {
		if (itr->id == idT) {
			listOfPeronsT.erase(itr);
			break;
		}
		++itr;
	}
}

int Person::deletePerson(list<Person>& listOfPeronsT) {
	string idT;
	int id;
	regex ptrnID("\\d{6}");
	Menu menu;
	cout << "Podaj numer id osoby do usuniecia (jesli chcesz zakonczyc wpisz 'stop'): ";
	cin >> idT;
	if (idT == "stop") return NULL;
	if (!menu.checkWithPattern(idT, ptrnID)) {
		cout << "Nieprawidlowy numer id\n";
		}
	else {
		id = stoi(idT);
		if (!isPersonInBase(listOfPeronsT, id)) {
			cout << "Brak osoby w bazie o podanym id\n";
			deletePerson(listOfPeronsT);
		}
		else {
			deleteFromList(listOfPeronsT, id);
			toFile(listOfPeronsT);
			return id;
		}
	}
	return NULL;
}

void Person::showPerson(list<Person> listOfPeronsT, int isAdmin, int idP) {
	list<Person>::iterator itr = listOfPeronsT.begin();
	while (itr != listOfPeronsT.end()) {
		if (itr->id == idP) isAdmin == 1 ? itr->print() : itr->printForUser();
		++itr;
	}
}

int Person::isGivenPersonInBase(list<Person> listOfPeronsT, string nameT, string lastNameT) {
	list<Person>::iterator itr = listOfPeronsT.begin();
	while (itr != listOfPeronsT.end()) {
		if (itr->name==nameT&&itr->lastName==lastNameT) {
			return itr->id;
		}
		++itr;
	}
	return NULL;
}

int Person::isCityInBase(list<Person> listOfPeronsT, string cityT) {
	list<Person>::iterator itr = listOfPeronsT.begin();
	while (itr != listOfPeronsT.end()) {
		if (itr->city ==cityT) {
			return itr->id;
		}
		++itr;
	}
	return NULL;
}