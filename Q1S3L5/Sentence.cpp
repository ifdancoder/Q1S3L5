#include "Sentence.h"

Sentence::Sentence(std::string str) : sent(str) {
	std::stringstream ss;
	ss << str;
	std::string tmp;
	while (ss >> tmp) {
		len++;
	}
}

bool Sentence::operator<(const Sentence& snts2) const {
	return len < snts2.len;
}

std::ostream& operator<< (std::ostream& out, const Sentence& snts)
{
    out << snts.sent << " (" << snts.len << " words)";
    return out;
}