/** @file */
#pragma once
#ifndef Vehicle_h
#define Vehicle_h

#include <iostream>
#include <iterator>
#include <string>
#include <list>

using namespace std;

/**Klasa reprezentuj¹ca obiekt Vehicle, dziedzicz¹ca publicznie po klasie Data
*/
class Vehicle :public Data {
	string typeOfVehicle; ///< Zawiera typ pojazdu
	string brand; ///< Zawiera markê pojazdu
	string model; ///< Zawiera model pojazdu
	int horsePower; ///< Zawiera iloœæ koni mechanicznych pojazdu
	string engine; ///< Zawiera uk³ad silnika
	string colour; ///< Zawiera kolor pojazdu
public:
	/**Konstruktor domyœlny korzystaj¹cy z konstuktora klasy Data
	*/
	Vehicle() :Data(77777), typeOfVehicle("samochod"), brand("Ferrari"), model("Enzo"), horsePower(999), engine("V12"), colour("Rosso Corsa") {}
	/**Konstruktor siedmioargumentowy
	@param idT Zawiera numer id pojazdu
	@param typeOfVehicleT Zawiera typ pojazdu
	@param brandT Zawiera markê pojazdu
	@param modelT Zawiera model pojazdu
	@param power Zawiera moc pojazdu
	@param engineT Zawiera uk³ad silnika
	@param colourT Zawiera kolor pojazdu
	*/
	Vehicle(int idT, string typeOfVehicleT, string brandT, string modelT, int power, string engineT, string colourT) : Data(idT), typeOfVehicle(typeOfVehicleT), brand(brandT), model(modelT), horsePower(power), engine(engineT), colour(colourT) {}
	/**Metoda zwracaj¹ca markê pojazdu
	*/
	string getBrand() const { return brand; }
	/**Metoda przys³aniaj¹ca metodê wirtualn¹, s³u¿y do wyœwietlenia pe³nych informacji o pojeŸdzie 
	*/
	void print();
	/**Metoda wypisuj¹ca wszystkie dane pojazdu oprócz numeru id
	*/
	void printForUser();
	/**Metoda s³u¿y do dodawania obiektów klasy Vehicle do listy STL
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param vehicleT Reprezentuje obiekt klasy Vehicle
	*/
	void addToVehicleList(list<Vehicle>& listOfVehiclesT, Vehicle& vehicleT);
	/**Metoda s³u¿¹ca do odczytywania danych z pliku txt, nastêpnie tworz¹ca obiekt klasy Vehicle i przekazuj¹ca go do metody addToVehicleList()
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	*/
	void addFromFile(list<Vehicle>& listOfVehiclesT);
	/**Metoda ta w zale¿noœci od tego czy u¿ytkownik jest adminem wywo³uje metodê print() b¹dŸ printForUser() gdy nie jest adminem
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param isAdmin Zawiera informacjê o tym czy u¿ytkownik jest adminem
	*/
	void showVehicles(list<Vehicle> listOfVehiclesT, int isAdmin);
	/**Metoda s³u¿¹ca do wyœwietlenia pe³ynch danych o pojazdach zalogowanego u¿ytkownika
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param idV Zawiera id pojazdu, którego w³aœcicielem jest u¿ytkownik
	*/
	void showUserVehicles(list<Vehicle> listOfVehiclesT, int idV);
	/**Metoda ta s³u¿y do sprawdzenia czy pojazd o podanym numerze id znajduje siê w bazie
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param idT Zawiera numer id pojazdu podanego przez u¿ytkownika
	*/
	bool isVehicleInBase(list<Vehicle>& listOfVehiclesT, int idT);
	/**Metoda s³u¿¹ca do zapisu do pliku txt zawartoœci listy pojazdów
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	*/
	void toFile(list<Vehicle>& listOfVehiclesT);
	/**Metoda dodaj¹ca nowy pojazd do bazy
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	*/
	void addNewVehicle(list<Vehicle>& listOfVehiclesT);
	/**Metoda usuwaj¹ca z listy pojazd o podanym numerze id
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param idT Numer id do usuniêcia z listy
	*/
	void deleteFromList(list<Vehicle>& listOfVehiclesT, int idT);
	/**Metoda usuwaj¹ca z bazy pojazdów dany pojazd
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	*/
	int deleteVehicle(list<Vehicle>& listOfVehiclesT);
	/**Metoda ta zwraca numer id pojazdu, który posiada podan¹ markê
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param brandT Zawiera markê podan¹ przez u¿ytkownika
	*/
	int searchForVehicle(list<Vehicle> listOfVehiclesT, string brandT);
	/**Metoda ta wyœwietla informacje o pojeŸdzie oo podanym numerze id
	@param listOfVehiclesT lista STL zawieraj¹ca obiekty klasy Vehicle
	@param isAdmin Zawiera informacjê o tym czy aktualny u¿ytkownik jest adminem
	@param idV Zawiera numer id pojazdu, dla którego maj¹ byæ wyœwietlone dane
	*/
	void showVehicle(list<Vehicle> listOfVehiclesT, int isAdmin, int idV);
};

#endif // !Vehicle_h

