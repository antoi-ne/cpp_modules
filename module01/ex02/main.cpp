#include <string>
#include <iostream>

int main(void)
{
	std::string str("HI THIS IS BRAIN");

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	(void)stringPTR;
	(void)stringREF;

	std::cout << "string address: " << &str << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl << "stringREF address: " << &stringREF << std::endl;
	std::cout << "stringPTR content: " << *stringPTR << std::endl << "stringREF content: " << stringREF << std::endl;

	return (0);
}