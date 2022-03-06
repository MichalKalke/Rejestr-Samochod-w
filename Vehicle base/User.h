/** @file */
#pragma once
#ifndef User_h
#define User_h

#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "Login.h"

using namespace std;

/**Klasa reprezentuj�ca obiekt user (go��)
*/
class User {
	bool isAdmin; ///< Zawiera informacj� czy go�� jest adminem czy te� nie
public:
	/**Konstuktor domy�lny
	*/
	User() :isAdmin(0) {}
	/**Metoda s�u��ca do wy�wietlenia menu go�cia
	@param guest Reprezentuje obiekt klasy User
	*/
	void guestMenu(User guest);
	/**Metoda zwracaj�ca zmienn� isAdmin zawieraj�c� informacj� czy go�� jest adminem
	*/
	bool getIsAdmin() const { return isAdmin; }
};

#endif // !User_h

