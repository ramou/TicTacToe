#include <string>

#pragma once
class Player {
public:
	Player(std::string n) : name(n) {}
	std::string getName() { return name; }

private:
	std::string name;
};

