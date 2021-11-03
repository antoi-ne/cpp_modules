#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "=== Trying to sign form with grade too low ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			ShrubberyCreationForm f("home");
			b.signForm(f);
			f.execute(b);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}