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

/**Klasa reprezentuj¹ca obiekt user (goœæ)
*/
class User {
	bool isAdmin; ///< Zawiera informacjê czy goœæ jest adminem czy te¿ nie
public:
	/**Konstuktor domyœlny
	*/
	User() :isAdmin(0) {}
	/**Metoda s³u¿¹ca do wyœwietlenia menu goœcia
	@param guest Reprezentuje obiekt klasy User
	*/
	void guestMenu(User guest);
	/**Metoda zwracaj¹ca zmienn¹ isAdmin zawieraj¹c¹ informacjê czy goœæ jest adminem
	*/
	bool getIsAdmin() const { return isAdmin; }
};

#endif // !User_h

