#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP
#include <iostream>

class	Bureaucrat
{

public:
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&	operator=(Bureaucrat const& rhs);
	
	Bureaucrat(std::string name, int grade);

	std::string const&	getName() const;
	int					getGrade() const;
	void				incGrade();
	void				decGrade();

	~Bureaucrat(void);

private:
	Bureaucrat(void);

	std::string const	_name;
	int					_grade;

public:

	class GradeTooHighException : public std::exception
	{
    public:
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
    public:
		virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);
#endif
