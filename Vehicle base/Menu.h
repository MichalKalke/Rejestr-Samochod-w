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
	/**Metoda daj¹ca mo¿liwoœæ u¿ytkownikowi  zalogowania siê b¹dŸ skorzystania z programu jako goœæ
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUserT lista STL zawieraj¹ca obiekty klasy Login
	@param guestUser Reprezentuje obiekt klasy User (goœæ)
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param vehicleT Reprezentuje obiekt klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void loginOrGuest(Login& userT, list<Login>& listOfUserT, User& guestUser, list<Vehicle>& listOfVehiclesT, Vehicle& vehicleT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda ta s³u¿y do wywo³ania poszczególych metod, aby wczytaæ dane z plików i przetrzymywaæ je w odpowiednich listach STL
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUserT lista STL zawieraj¹ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void begin(Login& userT, list<Login>& listOfUserT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda s³u¿y do logowania u¿ytkownika jeœli wybra³ logowanie w metodzie loginOrGuest()
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUserT lista STL zawieraj¹ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void login(Login& userT, list<Login>& listOfUserT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda ta s³u¿y do wywo³ywania metod, które wybra³ goœæ 
	@param guest Reprezentuje obiekt klasy User (goœæ)
	*/
	void guestOptions(User guest);
	/**Metoda ta s³u¿y do wywo³ywania metod, które wybra³ u¿ytkownik, b¹dŸ admin (dziêki zabezpieczeniom u¿ytkownik nie jest w stanie wywo³aæ metod przeznaczonych dla admina)
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void userChoice(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda która odpowiada za wywo³anie metody zmieniaj¹cej has³o u¿ytkownika
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void changePassword(list<Login>& listOfUsersT, Login userT);
	/**Metoda która odpowiada za wywo³anie metody zmieniaj¹cej has³o dowolnego u¿ytkownika
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void changeUserPassword(list<Login>& listOfUsersT, Login userT);
	/**Metoda odpowiada za wywo³anie metody usuwaj¹cej u¿ytkownika z bazy
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void deleteUser(list<Login>& listOfUsersT, Login userT);
	/**Uniwersalna metoda sprawdzaj¹ca za pomoc¹ RegEx'a czy podany string jest zgodny z podanym wzorcem
	@param str Zawiera wyraz do sprawdzenia ze wzorcem
	@param pattern Zawiera wzorzec, który jest porównywany ze stringiem
	*/
	bool checkWithPattern(string str, regex pattern);
	/**Metoda s³u¿¹ca do zobaczenia kto jest w³aœcicielem podanej marki pojazdu
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param listOfContsT lista STL zawieraj¹ca konekcje miêdzy osobami, a pojazdami
	@param userT Reprezentuje obiekt klasy Login
	*/
	void whoseVehicle(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT);
	/**Metoda s³u¿¹ca do zobaczenia jakie pojazdy posiada dana osoba
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param listOfContsT lista STL zawieraj¹ca konekcje miêdzy osobami, a pojazdami
	@param userT Reprezentuje obiekt klasy Login
	*/
	void whichVehiclePersonHave(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT);
	/**Metoda ta s³u¿y do zobaczenia gdzie znajduj¹ siê pojazdy danej marki (na podstawie miejscowoœci zamieszkania w³aœciciela)
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param listOfContsT lista STL zawieraj¹ca konekcje miêdzy osobami, a pojazdami
	@param userT Reprezentuje obiekt klasy Login
	*/
	void fromWhereVehicle(list<Vehicle> listOfVehiclesT, list<Person> listOfPersonsT, list<Connections> listOfContsT, Login userT);
	/**Metoda s³u¿¹ca do sprawdzenia czy u¿ytkownik chce kontynuowaæ czy skoñczyæ korzystanie z programu
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void checkIfContinue(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
};

#endif // !Menu_h