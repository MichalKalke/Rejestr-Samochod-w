/** @file */
#pragma once
#ifndef Connections_h
#define Connections_h

#include <iostream>
#include <list>

#include "Login.h"
#include "Data.h"
#include "Person.h"
#include "Vehicle.h"

using namespace std;

/**Klasa reprezentuj�ca obiekt connections (po��czenie mi�dzy id pojazdu, a id w�a�ciciela), dziedziczy publicznie po klasie Data
*/
class Connections :public Data {
	int vehicleId; ///< Zawiera id pojazdu
public:
	/**Konstruktor domy�lny korzystaj�cy z konstuktora klasy Data
	*/
	Connections() :Data(100000), vehicleId(1111111) {}
	/**Konstruktor dwuargumentowy
	@param personIdT Zawiera id osoby
	@param vehicleIdT Zawiera id pojazdu
	*/
	Connections(int personIdT, int vehicleIdT) : Data(personIdT), vehicleId(vehicleIdT) {}
	/**Metoda przys�aniaj�ca metod� wirtualn�, wypisuje po��czenia numer�w id os�b i pojazd�w
	*/
	void print();
	/**Metoda dodaj�ca do listy obiekty klasy Connections
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param connectionT Reprezentuje obiekt klasy Connections
	*/
	void addToConnectionsList(list<Connections>& listOfContsT, Connections& connectionT);
	/**Metoda ta wczytuje dane z pliku txt, tworzy obiekt klasy Connections, a ostatecznie wywo�uje metod� addToConnectionsList()
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	*/
	void addFromFile(list<Connections>& listOfContsT);
	/**Metoda wypisuj�ca dane znajduj�ce si� w li�cie za pomoc� metody print()
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	*/
	void showConnections(list<Connections> listOfContsT);
	/**Metoda sprawdzaj�ca czy istnieje ju� podane po��czenie w li�cie
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param idP Zawiera id osoby podane przez u�ytkownika
	@param idV Zawiera id pojazdu podane przez u�ytkownika
	*/
	bool checkIfConnectionExists(list<Connections>& listOfContsT, int idP, int idV);
	/**Metoda wpisuj�ca dane z listy do pliku txt
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	*/
	void toFile(list<Connections>& listOfContsT);
	/**Metoda dodaj�ca nowe po��czenie mi�dzy osob�, a pojazdem
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	*/
	void addConnection(list<Connections>& listOfContsT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT);
	/**Metoda usuwaj�ca po��czenie gdy zosta� usuni�ty pojazd z bazy pojazd�w
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param idV Zawiera numer id usuni�tego pojazdu
	*/
	void deleteWhenVehicle(list<Connections>& listOfContsT, int idV);
	/**Metoda usuwaj�ca po��czenie gdy zosta�a usuni�ta osoba z bazy os�b
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param idP Zawiera numer id usuni�tej osoby
	*/
	void deleteWhenPerson(list<Connections>& listOfContsT, int idP);
	/**Metoda usuwaj�ca z listy podane po��czenie
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param idP Zawiera id persony
	@param idV Zawiera id pojazdu
	*/
	void deleteFromList(list<Connections>& listOfContsT, int idP, int idV);
	/**Metoda usuwaj�ca po��czenie mi�dzy pojazdem, a osob�
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	*/
	void deleteConnection(list<Connections>& listOfContsT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT);
	/**Metoda ta s�u�y do wyszukania numr�w id pojazd�w, kt�re posiada aktualnie zalogowany u�ytkownik
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param userT Reprezentuje obiekt klasy Login
	*/
	void showUserCars(list<Connections> listOfContsT, list<Vehicle> listOfVehiclesT, Login userT);
	/**Zwraca numer id osoby po numerze pojazdu
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param idV Zawiera numer id pojazdu
	*/
	int findUserByVehicle(list<Connections> listOfContsT, int idV);
	/**Metoda s�u�y do znalezienia numeru pojazdu po numerze numerze u�ytkownika
	@param listOfContsT lista STL zawieraj�ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param isAdmin Zawiera informacj� czy u�ytkownik wywo�uj�cy t� metod� jest adminem
	@param idP Zawiera id persony
	*/
	void findVehicleByUser(list<Connections> listOfContsT, list<Vehicle> listOfVehiclesT, int isAdmin, int idP);
};
#endif // !connections_h
