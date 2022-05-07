#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "math.h"

using namespace std;

class user : public math{
public:
	string name;
	inline void getName() { getline(cin, name); }
	//friend ostream& operator<<(ostream& os, const user& us);
};

/*ostream& operator<<(ostream& os, const user& us) {
	os << us.name;
	return os;
}*/