#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

static void print_usage()
{
	std::cout << "Wrong parameters. Usage:" << std::endl << "       ./replace file s1 s2 " << std::endl;
}

static void print_io_error()
{
	std::cout << "file manipulation error." << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4 || strlen(argv[1]) == 0 || strlen(argv[2]) == 0 || strlen(argv[3]) == 0)
	{
		print_usage();
		return (42);
	}

	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream ifs(fileName);
	if (ifs.fail())
	{
		print_io_error();
		return (42);
	}

	std::ofstream ofs(fileName + ".replace");
	if (ofs.fail())
	{
		print_io_error();
		return (42);
	}

	std::stringstream buffer;
	buffer << ifs.rdbuf();

	ifs.close();

	std::string filestr = buffer.str();

	size_t nPos;
	size_t start = 0;
	while ((nPos = filestr.find(s1, start)) != std::string::npos)
	{
		filestr.erase(nPos, s1.length());
		filestr.insert(nPos, s2);
		start = nPos + s2.length();
	}

	ofs << filestr;

	ofs.close();

	return (0);
}