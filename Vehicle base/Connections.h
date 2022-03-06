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

/**Klasa reprezentuj¹ca obiekt connections (po³¹czenie miêdzy id pojazdu, a id w³aœciciela), dziedziczy publicznie po klasie Data
*/
class Connections :public Data {
	int vehicleId; ///< Zawiera id pojazdu
public:
	/**Konstruktor domyœlny korzystaj¹cy z konstuktora klasy Data
	*/
	Connections() :Data(100000), vehicleId(1111111) {}
	/**Konstruktor dwuargumentowy
	@param personIdT Zawiera id osoby
	@param vehicleIdT Zawiera id pojazdu
	*/
	Connections(int personIdT, int vehicleIdT) : Data(personIdT), vehicleId(vehicleIdT) {}
	/**Metoda przys³aniaj¹ca metodê wirtualn¹, wypisuje po³¹czenia numerów id osób i pojazdów
	*/
	void print();
	/**Metoda dodaj¹ca do listy obiekty klasy Connections
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param connectionT Reprezentuje obiekt klasy Connections
	*/
	void addToConnectionsList(list<Connections>& listOfContsT, Connections& connectionT);
	/**Metoda ta wczytuje dane z pliku txt, tworzy obiekt klasy Connections, a ostatecznie wywo³uje metodê addToConnectionsList()
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	*/
	void addFromFile(list<Connections>& listOfContsT);
	/**Metoda wypisuj¹ca dane znajduj¹ce siê w liœcie za pomoc¹ metody print()
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	*/
	void showConnections(list<Connections> listOfContsT);
	/**Metoda sprawdzaj¹ca czy istnieje ju¿ podane po³¹czenie w liœcie
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param idP Zawiera id osoby podane przez u¿ytkownika
	@param idV Zawiera id pojazdu podane przez u¿ytkownika
	*/
	bool checkIfConnectionExists(list<Connections>& listOfContsT, int idP, int idV);
	/**Metoda wpisuj¹ca dane z listy do pliku txt
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	*/
	void toFile(list<Connections>& listOfContsT);
	/**Metoda dodaj¹ca nowe po³¹czenie miêdzy osob¹, a pojazdem
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	*/
	void addConnection(list<Connections>& listOfContsT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT);
	/**Metoda usuwaj¹ca po³¹czenie gdy zosta³ usuniêty pojazd z bazy pojazdów
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param idV Zawiera numer id usuniêtego pojazdu
	*/
	void deleteWhenVehicle(list<Connections>& listOfContsT, int idV);
	/**Metoda usuwaj¹ca po³¹czenie gdy zosta³a usuniêta osoba z bazy osób
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param idP Zawiera numer id usuniêtej osoby
	*/
	void deleteWhenPerson(list<Connections>& listOfContsT, int idP);
	/**Metoda usuwaj¹ca z listy podane po³¹czenie
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param idP Zawiera id persony
	@param idV Zawiera id pojazdu
	*/
	void deleteFromList(list<Connections>& listOfContsT, int idP, int idV);
	/**Metoda usuwaj¹ca po³¹czenie miêdzy pojazdem, a osob¹
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	*/
	void deleteConnection(list<Connections>& listOfContsT, list<Vehicle>& listOfVehiclesT, list<Person>& listOfPersonsT);
	/**Metoda ta s³u¿y do wyszukania numrów id pojazdów, które posiada aktualnie zalogowany u¿ytkownik
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param userT Reprezentuje obiekt klasy Login
	*/
	void showUserCars(list<Connections> listOfContsT, list<Vehicle> listOfVehiclesT, Login userT);
	/**Zwraca numer id osoby po numerze pojazdu
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param idV Zawiera numer id pojazdu
	*/
	int findUserByVehicle(list<Connections> listOfContsT, int idV);
	/**Metoda s³u¿y do znalezienia numeru pojazdu po numerze numerze u¿ytkownika
	@param listOfContsT lista STL zawieraj¹ca obiekty klasy Connections
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param isAdmin Zawiera informacjê czy u¿ytkownik wywo³uj¹cy tê metodê jest adminem
	@param idP Zawiera id persony
	*/
	void findVehicleByUser(list<Connections> listOfContsT, list<Vehicle> listOfVehiclesT, int isAdmin, int idP);
};
#endif // !connections_h
