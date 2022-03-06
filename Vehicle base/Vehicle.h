/** @file */
#pragma once
#ifndef Vehicle_h
#define Vehicle_h

#include <iostream>
#include <iterator>
#include <string>
#include <list>

using namespace std;

/**Klasa reprezentuj�ca obiekt Vehicle, dziedzicz�ca publicznie po klasie Data
*/
class Vehicle :public Data {
	string typeOfVehicle; ///< Zawiera typ pojazdu
	string brand; ///< Zawiera mark� pojazdu
	string model; ///< Zawiera model pojazdu
	int horsePower; ///< Zawiera ilo�� koni mechanicznych pojazdu
	string engine; ///< Zawiera uk�ad silnika
	string colour; ///< Zawiera kolor pojazdu
public:
	/**Konstruktor domy�lny korzystaj�cy z konstuktora klasy Data
	*/
	Vehicle() :Data(77777), typeOfVehicle("samochod"), brand("Ferrari"), model("Enzo"), horsePower(999), engine("V12"), colour("Rosso Corsa") {}
	/**Konstruktor siedmioargumentowy
	@param idT Zawiera numer id pojazdu
	@param typeOfVehicleT Zawiera typ pojazdu
	@param brandT Zawiera mark� pojazdu
	@param modelT Zawiera model pojazdu
	@param power Zawiera moc pojazdu
	@param engineT Zawiera uk�ad silnika
	@param colourT Zawiera kolor pojazdu
	*/
	Vehicle(int idT, string typeOfVehicleT, string brandT, string modelT, int power, string engineT, string colourT) : Data(idT), typeOfVehicle(typeOfVehicleT), brand(brandT), model(modelT), horsePower(power), engine(engineT), colour(colourT) {}
	/**Metoda zwracaj�ca mark� pojazdu
	*/
	string getBrand() const { return brand; }
	/**Metoda przys�aniaj�ca metod� wirtualn�, s�u�y do wy�wietlenia pe�nych informacji o poje�dzie 
	*/
	void print();
	/**Metoda wypisuj�ca wszystkie dane pojazdu opr�cz numeru id
	*/
	void printForUser();
	/**Metoda s�u�y do dodawania obiekt�w klasy Vehicle do listy STL
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param vehicleT Reprezentuje obiekt klasy Vehicle
	*/
	void addToVehicleList(list<Vehicle>& listOfVehiclesT, Vehicle& vehicleT);
	/**Metoda s�u��ca do odczytywania danych z pliku txt, nast�pnie tworz�ca obiekt klasy Vehicle i przekazuj�ca go do metody addToVehicleList()
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	*/
	void addFromFile(list<Vehicle>& listOfVehiclesT);
	/**Metoda ta w zale�no�ci od tego czy u�ytkownik jest adminem wywo�uje metod� print() b�d� printForUser() gdy nie jest adminem
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param isAdmin Zawiera informacj� o tym czy u�ytkownik jest adminem
	*/
	void showVehicles(list<Vehicle> listOfVehiclesT, int isAdmin);
	/**Metoda s�u��ca do wy�wietlenia pe�ynch danych o pojazdach zalogowanego u�ytkownika
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param idV Zawiera id pojazdu, kt�rego w�a�cicielem jest u�ytkownik
	*/
	void showUserVehicles(list<Vehicle> listOfVehiclesT, int idV);
	/**Metoda ta s�u�y do sprawdzenia czy pojazd o podanym numerze id znajduje si� w bazie
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param idT Zawiera numer id pojazdu podanego przez u�ytkownika
	*/
	bool isVehicleInBase(list<Vehicle>& listOfVehiclesT, int idT);
	/**Metoda s�u��ca do zapisu do pliku txt zawarto�ci listy pojazd�w
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	*/
	void toFile(list<Vehicle>& listOfVehiclesT);
	/**Metoda dodaj�ca nowy pojazd do bazy
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	*/
	void addNewVehicle(list<Vehicle>& listOfVehiclesT);
	/**Metoda usuwaj�ca z listy pojazd o podanym numerze id
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param idT Numer id do usuni�cia z listy
	*/
	void deleteFromList(list<Vehicle>& listOfVehiclesT, int idT);
	/**Metoda usuwaj�ca z bazy pojazd�w dany pojazd
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	*/
	int deleteVehicle(list<Vehicle>& listOfVehiclesT);
	/**Metoda ta zwraca numer id pojazdu, kt�ry posiada podan� mark�
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param brandT Zawiera mark� podan� przez u�ytkownika
	*/
	int searchForVehicle(list<Vehicle> listOfVehiclesT, string brandT);
	/**Metoda ta wy�wietla informacje o poje�dzie oo podanym numerze id
	@param listOfVehiclesT lista STL zawieraj�ca obiekty klasy Vehicle
	@param isAdmin Zawiera informacj� o tym czy aktualny u�ytkownik jest adminem
	@param idV Zawiera numer id pojazdu, dla kt�rego maj� by� wy�wietlone dane
	*/
	void showVehicle(list<Vehicle> listOfVehiclesT, int isAdmin, int idV);
};

#endif // !Vehicle_h

