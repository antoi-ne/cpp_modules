#include <string>
#include <iostream>

int main(void)
{
	std::string str("HI THIS IS BRAIN");

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	(void)stringPTR;
	(void)stringREF;

	std::cout << "str content: " << str << std::endl << "str address: " << (void *)&str << std::endl;
	std::cout << "stringPTR content: " << *stringPTR << std::endl << "stringPTR address: " << (void *)stringPTR << std::endl;
	std::cout << "stringREF content: " << stringREF << std::endl << "stringREF address: " << (void *)&stringREF << std::endl;

	return (0);
}