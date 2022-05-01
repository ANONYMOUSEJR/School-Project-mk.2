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
};

