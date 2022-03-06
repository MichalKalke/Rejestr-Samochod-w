#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <list>

#include "Login.h"
#include "Menu.h"
#include "User.h"


using namespace std;

void User::guestMenu(User guest) {
	Menu menu;
	cout << "\nWitaj gosciu\n\nWcisnij:\n1 aby stworzyc konto\n2 aby wyswietlic baze pojazdow\n3 aby wyswietlic baze osob\n4 aby znalezc jakie pojazdy znajduja sie w podanej miejscowosci\n";
	menu.guestOptions(guest);
}