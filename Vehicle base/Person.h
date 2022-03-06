/** @file */
#pragma once
#ifndef Person_h
#define Person_h

#include <iostream>
#include <iterator>
#include <string>
#include <list>

#include "Data.h"

using namespace std;

/**Klasa reprezentuj¹ca obiekt Person, dziedzicz¹ca publicznie po klasie Data
*/
class Person :public Data {
	string name; ///< Zawiera imiê osoby
	string lastName; ///< Zawiera nazwisko osoby
	string mail; ///< Zawiera adres mailowy
	int phoneNumber; ///< Zawiera numer telefonu
	int birthYear; ///< Zawiera rok urodzenia
	string city; ///< Zawiera nazwê miejscowoœci
	string street; ///< Zawiera nazwê ulicy
	string houseNumber; ///< Zawiera numer domu/mieszkania

public:
	/**Konstruktor domyœlny korzystaj¹cy z konstuktora klasy dziedzicznej
	*/
	Person() :Data(100000), name("Imie"), lastName("Nazwisko"), mail("mk@gmail.com"), phoneNumber(718911812), birthYear(2000), city("Miasto"), street("Ulica"), houseNumber("1A") {}
	/**Konstruktor dziewiêcioargumentowy
	@param idT Zawiera numer id osoby
	@param nameT Zawiera imiê osoby
	@param lastNameT Zawiera nazwisko osoby
	@param mailT Zawiera adres mailowy
	@param phoneNumberT Zawiera numer telefonu
	@param birthYearT Zawiera rok urodzenia
	@param cityT Zawiera nazwê miejscowoœci
	@param streetT Zawiera nazwê ulicy
	@param houseNumberT Zawiera numer domu/mieszkania
	*/
	Person(int idT, string nameT, string lastNameT, string mailT, int phoneNumberT, int birthYearT, string cityT, string streetT, string houseNumberT) : Data(idT), name(nameT), lastName(lastNameT), mail(mailT), phoneNumber(phoneNumberT), birthYear(birthYearT), city(cityT), street(streetT), houseNumber(houseNumberT) {}
	/**Metoda zwracaj¹ca imiê osoby
	*/
	string getName() const { return name; }
	/**Metoda zwracaj¹ca nazwisko osoby
	*/
	string getLastName() const { return lastName; }
	/**Metoda przys³aniaj¹ca metodê wirtualn¹, s³u¿y do wyœwietlenia pe³nych informacji o osobie dla u¿ytkownika
	*/
	void print();
	/**Metoda wypisuj¹ca imiê, nazwisko oraz miejscowoœæ osoby dla u¿ytkownika 
	*/
	void printForUser();
	/**Metoda dodaj¹ca do listy STL obiekty klasy Person
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void addToPersonList(list<Person>& listOfPeronsT, Person& personsT);
	/**Metoda sprawdzaj¹ca czy osoba o podanym numerze id znajduje siê w bazie
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param idT Numer id, który jest sprawdzany czy znajduje siê w liœcie osób
	*/
	bool isPersonInBase(list<Person>& listOfPeronsT, int idT);
	/**Metoda s³u¿¹ca do odczytywania danych z pliku txt, nastêpnie tworz¹ca obiekt klasy Person i przekazuj¹ca do metody addToPersonList()
	@param listOfPersonsT lista STL zawieraj¹ca obiekty klasy Person
	*/
	void addFromFile(list<Person>& listOfPersonsT);
	/**Metoda w zale¿noœci od tego czy u¿ytkownik jest adminem wyœwietla pe³ne b¹dŸ tylko ogólne informacje o osobach w bazie
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param isAdmin Zawiera informacjê czy u¿ytkownik wywo³uj¹cy tê metodê ma uprawnienia admina (1 - ma)
	*/
	void showPersons(list<Person> listOfPeronsT, int isAdmin);
	/**Metoda zapisuj¹ca do pliku txt zawartoœæ listy person
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	*/
	void toFile(list<Person>& listOfPeronsT);
	/**Metoda dodaj¹ca now¹ osobê do bazy 
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	*/
	void addNewPerson(list<Person>& listOfPeronsT);
	/**Metoda usuwaj¹ca z listy osobê o podanym numerze id
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param idT Numer id do usuniêcia z listy
	*/
	void deleteFromList(list<Person>& listOfPeronsT, int idT);
	/**Metoda usuwaj¹ca osobê z bazy
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	*/
	int deletePerson(list<Person>& listOfPeronsT);
	/**Metoda wyœwietlaj¹ca informacjê o podanej osobie (pe³ne informacje s¹ tylko ukazywane adminowi)
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param isAdmin Zawiera informacjê czy osoba wywo³uj¹ca metodê jest adminem
	@param idP Zawiera id osoby, której informacje maj¹ byæ wyœwietlone
	*/
	void showPerson(list<Person> listOfPeronsT, int isAdmin, int idP);
	/**Metoda sprawdzaj¹ca czy osoba o podanym imieniu i nazwisku znajduje siê w bazie i zwracaj¹ca jej numer id
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param nameT Zawiera imiê wpisane przez u¿ytkownika
	@param lastNameT Zawiera nazwisko wpisane przez u¿ytkownika
	*/
	int isGivenPersonInBase(list<Person> listOfPeronsT, string nameT, string lastNameT);
	/**Metoda sprawdzaj¹ca czy istnieje taka miejscowoœæ w bazie, jeœli tak to zwraca numer id osoby, która mieszka w tej miejscowoœci
	@param listOfPeronsT lista STL zawieraj¹ca obiekty klasy Person
	@param cityT Zawiera nazwê miejscowoœci podane przez u¿ytkownika
	*/
	int isCityInBase(list<Person> listOfPeronsT, string cityT);
};

#endif // !Person_h