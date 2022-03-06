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

/**Klasa reprezentuj�ca obiekt Person, dziedzicz�ca publicznie po klasie Data
*/
class Person :public Data {
	string name; ///< Zawiera imi� osoby
	string lastName; ///< Zawiera nazwisko osoby
	string mail; ///< Zawiera adres mailowy
	int phoneNumber; ///< Zawiera numer telefonu
	int birthYear; ///< Zawiera rok urodzenia
	string city; ///< Zawiera nazw� miejscowo�ci
	string street; ///< Zawiera nazw� ulicy
	string houseNumber; ///< Zawiera numer domu/mieszkania

public:
	/**Konstruktor domy�lny korzystaj�cy z konstuktora klasy dziedzicznej
	*/
	Person() :Data(100000), name("Imie"), lastName("Nazwisko"), mail("mk@gmail.com"), phoneNumber(718911812), birthYear(2000), city("Miasto"), street("Ulica"), houseNumber("1A") {}
	/**Konstruktor dziewi�cioargumentowy
	@param idT Zawiera numer id osoby
	@param nameT Zawiera imi� osoby
	@param lastNameT Zawiera nazwisko osoby
	@param mailT Zawiera adres mailowy
	@param phoneNumberT Zawiera numer telefonu
	@param birthYearT Zawiera rok urodzenia
	@param cityT Zawiera nazw� miejscowo�ci
	@param streetT Zawiera nazw� ulicy
	@param houseNumberT Zawiera numer domu/mieszkania
	*/
	Person(int idT, string nameT, string lastNameT, string mailT, int phoneNumberT, int birthYearT, string cityT, string streetT, string houseNumberT) : Data(idT), name(nameT), lastName(lastNameT), mail(mailT), phoneNumber(phoneNumberT), birthYear(birthYearT), city(cityT), street(streetT), houseNumber(houseNumberT) {}
	/**Metoda zwracaj�ca imi� osoby
	*/
	string getName() const { return name; }
	/**Metoda zwracaj�ca nazwisko osoby
	*/
	string getLastName() const { return lastName; }
	/**Metoda przys�aniaj�ca metod� wirtualn�, s�u�y do wy�wietlenia pe�nych informacji o osobie dla u�ytkownika
	*/
	void print();
	/**Metoda wypisuj�ca imi�, nazwisko oraz miejscowo�� osoby dla u�ytkownika 
	*/
	void printForUser();
	/**Metoda dodaj�ca do listy STL obiekty klasy Person
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param personsT Reprezentuje obiekt klasy Person
	*/
	void addToPersonList(list<Person>& listOfPeronsT, Person& personsT);
	/**Metoda sprawdzaj�ca czy osoba o podanym numerze id znajduje si� w bazie
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param idT Numer id, kt�ry jest sprawdzany czy znajduje si� w li�cie os�b
	*/
	bool isPersonInBase(list<Person>& listOfPeronsT, int idT);
	/**Metoda s�u��ca do odczytywania danych z pliku txt, nast�pnie tworz�ca obiekt klasy Person i przekazuj�ca do metody addToPersonList()
	@param listOfPersonsT lista STL zawieraj�ca obiekty klasy Person
	*/
	void addFromFile(list<Person>& listOfPersonsT);
	/**Metoda w zale�no�ci od tego czy u�ytkownik jest adminem wy�wietla pe�ne b�d� tylko og�lne informacje o osobach w bazie
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param isAdmin Zawiera informacj� czy u�ytkownik wywo�uj�cy t� metod� ma uprawnienia admina (1 - ma)
	*/
	void showPersons(list<Person> listOfPeronsT, int isAdmin);
	/**Metoda zapisuj�ca do pliku txt zawarto�� listy person
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	*/
	void toFile(list<Person>& listOfPeronsT);
	/**Metoda dodaj�ca now� osob� do bazy 
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	*/
	void addNewPerson(list<Person>& listOfPeronsT);
	/**Metoda usuwaj�ca z listy osob� o podanym numerze id
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param idT Numer id do usuni�cia z listy
	*/
	void deleteFromList(list<Person>& listOfPeronsT, int idT);
	/**Metoda usuwaj�ca osob� z bazy
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	*/
	int deletePerson(list<Person>& listOfPeronsT);
	/**Metoda wy�wietlaj�ca informacj� o podanej osobie (pe�ne informacje s� tylko ukazywane adminowi)
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param isAdmin Zawiera informacj� czy osoba wywo�uj�ca metod� jest adminem
	@param idP Zawiera id osoby, kt�rej informacje maj� by� wy�wietlone
	*/
	void showPerson(list<Person> listOfPeronsT, int isAdmin, int idP);
	/**Metoda sprawdzaj�ca czy osoba o podanym imieniu i nazwisku znajduje si� w bazie i zwracaj�ca jej numer id
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param nameT Zawiera imi� wpisane przez u�ytkownika
	@param lastNameT Zawiera nazwisko wpisane przez u�ytkownika
	*/
	int isGivenPersonInBase(list<Person> listOfPeronsT, string nameT, string lastNameT);
	/**Metoda sprawdzaj�ca czy istnieje taka miejscowo�� w bazie, je�li tak to zwraca numer id osoby, kt�ra mieszka w tej miejscowo�ci
	@param listOfPeronsT lista STL zawieraj�ca obiekty klasy Person
	@param cityT Zawiera nazw� miejscowo�ci podane przez u�ytkownika
	*/
	int isCityInBase(list<Person> listOfPeronsT, string cityT);
};

#endif // !Person_h