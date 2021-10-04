#pragma once

#include <iostream>
#include <sstream>

class Sentence {
private:
	std::string sent;
	int len = 0;
public:
	Sentence(std::string str = "");

	bool operator<(const Sentence& snts2) const;
	friend std::ostream& operator<<(std::ostream& out, const Sentence& snts);
};