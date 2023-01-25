#include "Person.h"
void Person::fight() {
	std::cout << "Person is fighting" << std::endl;
}
const std::string& Person::getName() {
	return _name;
}