/** @file */
#pragma once
#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <string>
#include <list>
#include <string>
#include <regex>

#include "Login.h"
#include "User.h"
#include "Data.h"
#include "Vehicle.h"
#include "Person.h"
#include "Connections.h"

using namespace std;

class Menu {
public:
	/**Metoda daj�ca mo�liwo�� u�ytkownikowi  zalogowania si� b�d� skorzystania z programu jako go��
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUserT lista STL zawieraj�ca obiekty klasy Login
	@param guestUser Reprezentuje obiekt klasy User (go��)
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param vehicleT Reprezentuje obiekt klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void loginOrGuest(Login& userT, list<Login>& listOfUserT, User& guestUser, list<Vehicle>& listOfVehiclesT, Vehicle& vehicleT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda ta s�u�y do wywo�ania poszczeg�lych metod, aby wczyta� dane z plik�w i przetrzymywa� je w odpowiednich listach STL
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUserT lista STL zawieraj�ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void begin(Login& userT, list<Login>& listOfUserT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda s�u�y do logowania u�ytkownika je�li wybra� logowanie w metodzie loginOrGuest()
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUserT lista STL zawieraj�ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void login(Login& userT, list<Login>& listOfUserT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda ta s�u�y do wywo�ywania metod, kt�re wybra� go�� 
	@param guest Reprezentuje obiekt klasy User (go��)
	*/
	void guestOptions(User guest);
	/**Metoda ta s�u�y do wywo�ywania metod, kt�re wybra� u�ytkownik, b�d� admin (dzi�ki zabezpieczeniom u�ytkownik nie jest w stanie wywo�a� metod przeznaczonych dla admina)
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void userChoice(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda kt�ra odpowiada za wywo�anie metody zmieniaj�cej has�o u�ytkownika
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void changePassword(list<Login>& listOfUsersT, Login userT);
	/**Metoda kt�ra odpowiada za wywo�anie metody zmieniaj�cej has�o dowolnego u�ytkownika
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void changeUserPassword(list<Login>& listOfUsersT, Login userT);
	/**Metoda odpowiada za wywo�anie metody usuwaj�cej u�ytkownika z bazy
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void deleteUser(list<Login>& listOfUsersT, Login userT);
	/**Uniwersalna metoda sprawdzaj�ca za pomoc� RegEx'a czy podany string jest zgodny z podanym wzorcem
	@param str Zawiera wyraz do sprawdzenia ze wzorcem
	@param pattern Zawiera wzorzec, kt�ry jest por�wnywany ze stringiem
	*/
	bool checkWithPattern(string str, regex pattern);
	/**Metoda s�u��ca do zobaczenia kto jest w�a�cicielem podanej marki pojazdu
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param listOfContsT lista STL zawieraj�ca konekcje mi�dzy osobami, a pojazdami
	@param userT Reprezentuje obiekt klasy Login
	*/
	void whoseVehicle(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT);
	/**Metoda s�u��ca do zobaczenia jakie pojazdy posiada dana osoba
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param listOfContsT lista STL zawieraj�ca konekcje mi�dzy osobami, a pojazdami
	@param userT Reprezentuje obiekt klasy Login
	*/
	void whichVehiclePersonHave(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT);
	/**Metoda ta s�u�y do zobaczenia gdzie znajduj� si� pojazdy danej marki (na podstawie miejscowo�ci zamieszkania w�a�ciciela)
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param listOfContsT lista STL zawieraj�ca konekcje mi�dzy osobami, a pojazdami
	@param userT Reprezentuje obiekt klasy Login
	*/
	void fromWhereVehicle(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT);
	/**Metoda s�u��ca do sprawdzenia czy u�ytkownik chce kontynuowa� czy sko�czy� korzystanie z programu
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void checkIfContinue(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
};

#endif // !Menu_h