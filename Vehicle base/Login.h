/** @file */
#pragma once
#ifndef Login_h
#define Login_h

#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "Data.h"
#include "Vehicle.h"
#include "Person.h"



using namespace std;

/**Klasa reprezentuj¹ca obiekt login
*/
class Login {
protected:
	int userID; ///< Zawiera numer id osoby loguj¹cej siê do bazy
	string userPassword; ///< Zawiera has³o osoby loguj¹cej siê do bazy
	bool isAdmin; ///< Zawiera informacjê czy osoba loguj¹ca siê jest adminem
public:
	/**Konstuktor domyœlny
	*/
	Login() :userID(111), userPassword("mama"), isAdmin(0) {}
	/**Konstruktor trójargumentowy
	@param userIDT Zawiera numer id osoby loguj¹cej
	@param passwordT Zawiera has³o osoby loguj¹cej
	@param isAdminT Zawiera informacjê czy dana osoba jest adminem
	*/
	Login(int userIDT, string passwordT, bool isAdminT);
	/**Metoda sprawdzaj¹ca za pomoc¹ wyra¿eñ regularnych czy podany wyraz jest liczb¹ szeœciocyfrow¹
	@param str Zawiera podany przez u¿ytkownika numer w formie stringa
	*/
	bool isIdNumber(string str);
	/**Metoda s³u¿y do wypisania danych o osobach maj¹cych konto w bazie danych
	*/
	void show();
	/**Metoda s³u¿y do zwrócenia numeru id osób w bazie
	*/
	int getUserID() const { return userID; }
	/**Metoda s³u¿y do zwrócenia has³a osób w bazie
	*/
	string getPassword() const { return userPassword; }
	/**Metoda zwracaj¹ca informacjê o tym czy dany u¿ytkownik jest adminem
	*/
	bool getIsAdmin() const { return isAdmin; }
	/**Metoda s³u¿¹ca do ustawienia has³a u¿ytkownika na takie jakie poda³
	@param password Zawiera nowe has³o u¿ytkownika
	*/
	void setPassword(string password);
	/**Metoda ta s³u¿y do dodania do listy STL obiektów klasy Login
	@param userT Zawiera obiekt klasy Login
	@param listOfUserT lista STL do której dodawane s¹ obiekty klasy Login
	*/
	void addToList(Login& userT, list<Login>& listOfUserT);
	/**Metoda s³u¿¹ca do odczytywania danych z pliku txt, nastêpnie tworz¹ca obiekt klasy Login i przekazuj¹ca do metody addToList()
	@param listOfUsersT lista STL
	*/
	void addFromFile(list<Login>& listOfUsersT);
	/**Metoda s³u¿y do wyœwietlenia danych osób maj¹cych konto w bazie danych
	@param listOfUserT lista STL w której przechowywane s¹ obiekty reprezentuj¹ce osoby posiadaj¹ce konto w bazie danych
	*/
	void show(list<Login> listOfUserT);
	/**Metoda ta s³u¿y do sprawdzenia czy loguj¹ca siê osoba znajduje siê w bazie, a nastêpnie w zale¿noœci od tego czy jest adminem czy te¿ nie wywo³uje ró¿ne menu
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param number Zawiera numer id podany podczas próby logowania
	@param password Zawiera has³o podane podczas próby logowania
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	int searchForUser(Login& userT, list<Login>& listOfUsersT, int number, string password, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda ta wyœwietla menu dla u¿ytkownika, który nie jest adminem
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void normalUserMenu(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda dostêpna dla zwyk³ego u¿ytkownika, która s³u¿y do zmiany has³a u¿ytkownika
	@param userT Reprezentuje obiekt klasy Login
	@param password Zawiera nowe has³o u¿ytkownika
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	*/
	void changePassword(Login& userT, string password, list<Login>& listOfUsersT);
	/**Metoda ta s³u¿y do zapisania danych z listy do pliku txt 
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void toFile(list<Login>& listOfUsersT, Login& userT);
	/**Metoda wyœwietlaj¹ca menu dla admina, menu zawiera metody dla zwyk³ego u¿ytkownika oraz specjalne tylko dla admina
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void adminUserMenu(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda zwracaj¹ca prawdê jeœli podany u¿ytkownik znajduje siê w bazie, w przeciwnym wypadku zwraca fa³sz
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param id Zawiera numer id, który bêdzie porównywany do numerów id w liœcie
	*/
	bool isUserInBase(list<Login>& listOfUsersT, int id);
	/**Metoda zmieniaj¹ca has³o dowolnego u¿ytkownika w bazie 
	@param userT Reprezentuje obiekt klasy Login
	@param id Zawiera numer id osoby dla której nast¹pi zmiana has³a
	@param password Zawiera nowe has³o 
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	*/
	void changeAnyPassword(Login& userT, int id, string password, list<Login>& listOfUsersT);
	/**Metoda s³u¿y do usuniêca podanej osoby z listy u¿ytkowników
	@param userT Reprezentuje obiekt klasy Login
	@param id Zawiera numer id osoby do usuniêcia z bazy
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	*/
	void deleteFromBase(Login& userT, int id, list<Login>& listOfUsersT);
	/**Metoda sprawdzaj¹ca czy podany numer id ju¿ jest zajêty przez któregoœ z u¿ytkowników w bazie
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	@param idT Podany numer id
	*/
	bool isIdInBase(list<Login>& listOfUsersT, int idT);
	/**Metoda s³u¿¹ca do dodania nowego u¿ytkownika do bazy
	@param listOfUsersT lista STL zawieraj¹ca obiekty klasy Login
	*/
	void addUser(list<Login>& listOfUsersT);
};


#endif // !Login_h
