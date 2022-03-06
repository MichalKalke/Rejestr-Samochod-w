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

/**Klasa reprezentuj�ca obiekt login
*/
class Login {
protected:
	int userID; ///< Zawiera numer id osoby loguj�cej si� do bazy
	string userPassword; ///< Zawiera has�o osoby loguj�cej si� do bazy
	bool isAdmin; ///< Zawiera informacj� czy osoba loguj�ca si� jest adminem
public:
	/**Konstuktor domy�lny
	*/
	Login() :userID(111), userPassword("mama"), isAdmin(0) {}
	/**Konstruktor tr�jargumentowy
	@param userIDT Zawiera numer id osoby loguj�cej
	@param passwordT Zawiera has�o osoby loguj�cej
	@param isAdminT Zawiera informacj� czy dana osoba jest adminem
	*/
	Login(int userIDT, string passwordT, bool isAdminT);
	/**Metoda sprawdzaj�ca za pomoc� wyra�e� regularnych czy podany wyraz jest liczb� sze�ciocyfrow�
	@param str Zawiera podany przez u�ytkownika numer w formie stringa
	*/
	bool isIdNumber(string str);
	/**Metoda s�u�y do wypisania danych o osobach maj�cych konto w bazie danych
	*/
	void show();
	/**Metoda s�u�y do zwr�cenia numeru id os�b w bazie
	*/
	int getUserID() const { return userID; }
	/**Metoda s�u�y do zwr�cenia has�a os�b w bazie
	*/
	string getPassword() const { return userPassword; }
	/**Metoda zwracaj�ca informacj� o tym czy dany u�ytkownik jest adminem
	*/
	bool getIsAdmin() const { return isAdmin; }
	/**Metoda s�u��ca do ustawienia has�a u�ytkownika na takie jakie poda�
	@param password Zawiera nowe has�o u�ytkownika
	*/
	void setPassword(string password);
	/**Metoda ta s�u�y do dodania do listy STL obiekt�w klasy Login
	@param userT Zawiera obiekt klasy Login
	@param listOfUserT lista STL do kt�rej dodawane s� obiekty klasy Login
	*/
	void addToList(Login& userT, list<Login>& listOfUserT);
	/**Metoda s�u��ca do odczytywania danych z pliku txt, nast�pnie tworz�ca obiekt klasy Login i przekazuj�ca do metody addToList()
	@param listOfUsersT lista STL
	*/
	void addFromFile(list<Login>& listOfUsersT);
	/**Metoda s�u�y do wy�wietlenia danych os�b maj�cych konto w bazie danych
	@param listOfUserT lista STL w kt�rej przechowywane s� obiekty reprezentuj�ce osoby posiadaj�ce konto w bazie danych
	*/
	void show(list<Login> listOfUserT);
	/**Metoda ta s�u�y do sprawdzenia czy loguj�ca si� osoba znajduje si� w bazie, a nast�pnie w zale�no�ci od tego czy jest adminem czy te� nie wywo�uje r�ne menu
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param number Zawiera numer id podany podczas pr�by logowania
	@param password Zawiera has�o podane podczas pr�by logowania
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	int searchForUser(Login& userT, list<Login>& listOfUsersT, int number, string password, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda ta wy�wietla menu dla u�ytkownika, kt�ry nie jest adminem
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void normalUserMenu(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda dost�pna dla zwyk�ego u�ytkownika, kt�ra s�u�y do zmiany has�a u�ytkownika
	@param userT Reprezentuje obiekt klasy Login
	@param password Zawiera nowe has�o u�ytkownika
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	*/
	void changePassword(Login& userT, string password, list<Login>& listOfUsersT);
	/**Metoda ta s�u�y do zapisania danych z listy do pliku txt 
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param userT Reprezentuje obiekt klasy Login
	*/
	void toFile(list<Login>& listOfUsersT, Login& userT);
	/**Metoda wy�wietlaj�ca menu dla admina, menu zawiera metody dla zwyk�ego u�ytkownika oraz specjalne tylko dla admina
	@param userT Reprezentuje obiekt klasy Login
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void adminUserMenu(Login& userT, list<Login>& listOfUsersT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT, Person& personsT);
	/**Metoda zwracaj�ca prawd� je�li podany u�ytkownik znajduje si� w bazie, w przeciwnym wypadku zwraca fa�sz
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param id Zawiera numer id, kt�ry b�dzie por�wnywany do numer�w id w li�cie
	*/
	bool isUserInBase(list<Login>& listOfUsersT, int id);
	/**Metoda zmieniaj�ca has�o dowolnego u�ytkownika w bazie 
	@param userT Reprezentuje obiekt klasy Login
	@param id Zawiera numer id osoby dla kt�rej nast�pi zmiana has�a
	@param password Zawiera nowe has�o 
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	*/
	void changeAnyPassword(Login& userT, int id, string password, list<Login>& listOfUsersT);
	/**Metoda s�u�y do usuni�ca podanej osoby z listy u�ytkownik�w
	@param userT Reprezentuje obiekt klasy Login
	@param id Zawiera numer id osoby do usuni�cia z bazy
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	*/
	void deleteFromBase(Login& userT, int id, list<Login>& listOfUsersT);
	/**Metoda sprawdzaj�ca czy podany numer id ju� jest zaj�ty przez kt�rego� z u�ytkownik�w w bazie
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	@param idT Podany numer id
	*/
	bool isIdInBase(list<Login>& listOfUsersT, int idT);
	/**Metoda s�u��ca do dodania nowego u�ytkownika do bazy
	@param listOfUsersT lista STL zawieraj�ca obiekty klasy Login
	*/
	void addUser(list<Login>& listOfUsersT);
};


#endif // !Login_h
