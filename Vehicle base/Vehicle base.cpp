﻿// Vehicle base.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//Michał Kalke

#include <iostream>
#include <list>
#include <string>

#include "Login.h"
#include "Menu.h"
#include "User.h"
#include "Data.h"
#include "Vehicle.h"
#include "Person.h"
#include "Connections.h"

using namespace std;

int main()
{
    list<Vehicle> listOfVehicles;
    Vehicle vehicle;
    list<Login> listOfUsers;
    Login users;
    User guestUser;
    list<Person> listOfPersons;
    Person persons;
    Menu menu;

    menu.loginOrGuest(users, listOfUsers, guestUser, listOfVehicles, vehicle, listOfPersons, persons);

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
