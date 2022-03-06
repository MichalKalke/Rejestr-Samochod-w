#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <regex>

#include "Menu.h"
#include "Login.h"
#include "User.h"
#include "Data.h"
#include "Vehicle.h"
#include "Person.h"

using namespace std;

void Menu::loginOrGuest(Login& userT, list<Login>& listOfUserT, User& guestUser, list<Vehicle>& listOfVehiclesT, Vehicle& vehicleT, list<Person>& listOfPersonsT, Person& personsT) {
	vehicleT.addFromFile(listOfVehiclesT);

	cout << "Witaj uzytkowniku, czy chcesz sie zalogowac 1 czy uzyc konta goscia 2?\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		begin(userT, listOfUserT, listOfVehiclesT, listOfPersonsT, personsT);
		break;
	case 2:
		guestUser.guestMenu(guestUser);
		break;
	default:
		break;
	}

}

void Menu::begin(Login& userT, list<Login>& listOfUserT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	userT.addFromFile(listOfUserT);
	personsT.addFromFile(listOfPersonsT);
	userT.show(listOfUserT);
	login(userT, listOfUserT, listOfVehiclesT, listOfPersonsT, personsT);
}

void Menu::login(Login& userT, list<Login>& listOfUserT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	cout << "\nWybrano opcje logowania\n";
	string num;
	string pass;
	cout << "Login: ";
	cin >> num;
	cout << "\n";
	if (!userT.isIdNumber(num)) {
		cout << "Niepoprawny format - login jest liczba szesciocyfrowa\nProsze sprobowac ponownie:\n";
		login(userT, listOfUserT, listOfVehiclesT, listOfPersonsT, personsT);
	}
	else {
		cout << "Haslo: ";
		cin >> pass;
		cout << "\n";
		int numT = stoi(num);
		userT.searchForUser(userT, listOfUserT, numT, pass, listOfVehiclesT, listOfPersonsT, personsT);
	}
}


void Menu::guestOptions(User guest) {
	int choice;
	list<Connections> listOfContsT;
	list<Vehicle> listOfVehiclesT;
	list<Person> listOfPersonsT;
	list<Login> listOfUsersT;
	Connections connectionT;
	Vehicle vehicleT;
	Person personT;
	Login user;
	user.addFromFile(listOfUsersT);
	vehicleT.addFromFile(listOfVehiclesT);
	personT.addFromFile(listOfPersonsT);
	connectionT.addFromFile(listOfContsT);
	cin >> choice;

	switch (choice)
	{
	case 1:
		user.addUser(listOfUsersT);
		break;
	case 2:
		vehicleT.showVehicles(listOfVehiclesT, guest.getIsAdmin());
		break;
	case 3:
		personT.showPersons(listOfPersonsT, guest.getIsAdmin());
		break;
	case 4:
		fromWhereVehicle(listOfVehiclesT, listOfPersonsT, listOfContsT, user);
		break;

	default:
		break;
	}
}

void Menu::userChoice(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	int choice;
	cin >> choice;
	list<Connections> listOfContsT;
	Connections connectionT;
	Vehicle vehicleT;
	Login login;
	connectionT.addFromFile(listOfContsT);

	switch (choice)
	{
	case 1:
		vehicleT.showVehicles(listOfVehiclesT, userT.getIsAdmin());
		break;
	case 2:
		personsT.showPersons(listOfPersonsT, userT.getIsAdmin());
		break;
	case 3:
		changePassword(listOfUsersT, userT);
		break;
	case 4:
		fromWhereVehicle(listOfVehiclesT, listOfPersonsT, listOfContsT, userT);
		break;
	case 5:
		cout << "Twoje pojazdy to:\n";
		connectionT.showUserCars(listOfContsT, listOfVehiclesT, userT);
		break;
	case 6:
		whoseVehicle(listOfVehiclesT, listOfPersonsT, listOfContsT, userT);
		break;
	case 7:
		whichVehiclePersonHave(listOfVehiclesT, listOfPersonsT, listOfContsT, userT);
		break;
	case 8:
		changeUserPassword(listOfUsersT, userT);
		break;
	case 9:
		connectionT.showConnections(listOfContsT);
		break;
	case 10:
		if (userT.getIsAdmin() == 1) {
			personsT.addNewPerson(listOfPersonsT);
		}
		else cout << "Brak uprawnien\n";
		break;
	case 11:
		if (userT.getIsAdmin() == 1) {
			connectionT.deleteWhenPerson(listOfContsT, personsT.deletePerson(listOfPersonsT));
		}
		else cout << "Brak uprawnien\n";
		break;
	case 12:
		if (userT.getIsAdmin() == 1) {
			connectionT.addConnection(listOfContsT, listOfVehiclesT, listOfPersonsT);
		}
		else cout << "Brak uprawnien\n";
		break;
	case 13:
		if (userT.getIsAdmin() == 1) {
			connectionT.deleteConnection(listOfContsT, listOfVehiclesT, listOfPersonsT);
		}
		else cout << "Brak uprawnien\n";
		break;
	case 14:
		if (userT.getIsAdmin() == 1) {
			userT.addUser(listOfUsersT);
		}
		else cout << "Brak uprawnien\n";
		break;
	case 15:
		deleteUser(listOfUsersT, userT);
		break;
	case 16:
		if (userT.getIsAdmin() == 1) {
			vehicleT.addNewVehicle(listOfVehiclesT);
		}
		else cout << "Brak uprawnien\n";
		break;
		
	case 17:
		if (userT.getIsAdmin() == 1) {
			connectionT.deleteWhenVehicle(listOfContsT, vehicleT.deleteVehicle(listOfVehiclesT));
		}
		else cout << "Brak uprawnien\n";
		break;
	default:
		break;
	}
	checkIfContinue(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
}

void Menu::changePassword(list<Login>& listOfUsersT, Login userT) {
	string newPassword = "";
	cout << "zmiana hasla\n";
	cout << "Podaj nowe haslo:\n";
	cin >> newPassword;
	userT.changePassword(userT, newPassword, listOfUsersT);
	userT.toFile(listOfUsersT, userT);
}

void Menu::changeUserPassword(list<Login>& listOfUsersT, Login userT) {
	if (userT.getIsAdmin() == 1) {
		cout << "Podaj id uzytkownika dla ktorego chcesz zmienic haslo:\n";
		int id = 0;
		string newPassword = "";
		cin >> id;
		if (userT.isUserInBase(listOfUsersT, id)) {
			cout << "Podaj nowe haslo:\n";
			cin >> newPassword;
			userT.changeAnyPassword(userT, id, newPassword, listOfUsersT);
			userT.toFile(listOfUsersT, userT);
		}
		else cout << "Brak takiej osoby w bazie\n";
	}
	else cout << "Brak uprawnien\n";
}

void Menu::deleteUser(list<Login>& listOfUsersT, Login userT) {
	int id = 0;
	if (userT.getIsAdmin() == 1) {
		cout << "Podaj id uzytkownika ktorego chcesz usunac z bazy uzytkownikow:\n";
		cin >> id;
		if (userT.isUserInBase(listOfUsersT, id)) {
			userT.deleteFromBase(userT, id, listOfUsersT);
			userT.toFile(listOfUsersT, userT);

		}
		else cout << "Brak takiej osoby w bazie\n";
	}
	else cout << "Brak uprawnien\n";
}

bool Menu::checkWithPattern(string str, regex pattern) {
	if (regex_match(str, pattern)) {
		return true;
	}
	return false;
}

void Menu::whoseVehicle(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT) {
	cout << "Podaj marke pojazdu: ";
	int idP = 0, idV = 0;
	string brand ="";
	Connections connections;
	Person person;
	Vehicle vehicle;
	regex ptrn("[A-Z]{1}[a-z]{1,15}");
	cin >> brand;
	if (!checkWithPattern(brand, ptrn)) {
		cout << "Bledna marka, sprobuj ponownie\n";
		whoseVehicle(listOfVehiclesT, listOfPersonsT, listOfContsT, userT);
	}
	else if(vehicle.searchForVehicle(listOfVehiclesT, brand)!=NULL) {
		list<Vehicle>::iterator itr = listOfVehiclesT.begin();
		while (itr != listOfVehiclesT.end()) {
			if (itr->getBrand()==brand) {
				idV = itr->id;
				idP = connections.findUserByVehicle(listOfContsT, idV);
				person.showPerson(listOfPersonsT, userT.getIsAdmin(), idP);
			}
			itr++;
		}
	}
	else {
		cout << "Brak podanej marki w bazie pojazdow\n";
	}
}

void Menu::whichVehiclePersonHave(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT) {
	cout << "Podaj imie i nazwisko osoby dla ktorej chcesz zobaczyc posiadane pojazdy\nImie: ";
	string name = "", lastName = "";
	regex ptrn("[A-Z]{1}[a-z]{1,15}");
	int idP = 0;
	Person person;
	Connections connections;
	Vehicle vehicle;
	cin >> name;
	cout << "Nazwisko: ";
	cin >> lastName;
	if (!checkWithPattern(name, ptrn) || !checkWithPattern(lastName, ptrn)) {
		cout << "Blednie podane dane, sprobuj ponownie\n";
		whichVehiclePersonHave(listOfVehiclesT, listOfPersonsT, listOfContsT, userT);
	}
	else if(person.isGivenPersonInBase(listOfPersonsT, name, lastName)!=NULL){
		idP = person.isGivenPersonInBase(listOfPersonsT, name, lastName);
		connections.findVehicleByUser(listOfContsT, listOfVehiclesT,userT.getIsAdmin(), idP);
	}
	else {
		cout << "Brak podanej osoby w bazie\n";
	}
}

void Menu::fromWhereVehicle(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT) {
	cout << "Podaj miejscowosc dla ktorej chcesz wyswietlic zarejestrowane w niej pojazdy\n";
	string city = "";
	cin >> city;
	regex ptrn("[A-Z]{1}[a-z]{1,15}");
	int idP = 0;
	Person person;
	Connections connections;
	Vehicle vehicle;
	if (!checkWithPattern(city, ptrn)) {
		cout << "Bledny format miejscowosci\n";
	}
	else if (person.isCityInBase(listOfPersonsT, city)!=NULL) {
		idP = person.isCityInBase(listOfPersonsT, city);
		connections.findVehicleByUser(listOfContsT, listOfVehiclesT, userT.getIsAdmin(), idP);
	}
	else {
		cout << "Brak podanej miejscowosci w bazie\n";
	}
}

void Menu::checkIfContinue(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT) {
	string again = "";
	Login login;
	cout << "\nCzy chcesz kontynuowac - t (tak) - n (nie)\nWybor[t/n]: "; 
	cin >> again;
	if (again == "t") {
		if (userT.getIsAdmin() == 1)
			login.adminUserMenu(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
		else login.normalUserMenu(userT, listOfUsersT, listOfVehiclesT, listOfPersonsT, personsT);
	}
	else return;
}