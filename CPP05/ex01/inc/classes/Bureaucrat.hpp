#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP
#include <iostream>

class	Bureaucrat
{

public:
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&	operator=(Bureaucrat const& rhs);
	
	Bureaucrat(std::string name, int grade);

	void				signForm(Form &f) const;
	std::string const&	getName() const;
	int					getGrade() const;
	void				incGrade();
	void				decGrade();

	~Bureaucrat(void);

private:
	Bureaucrat(void);

	std::string const	_name;
	int					_grade;

private:

	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);
#endif
