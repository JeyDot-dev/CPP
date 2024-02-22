#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP
#include <iostream>

class AForm;

class	Bureaucrat
{

public:
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&	operator=(Bureaucrat const& rhs);
	
	Bureaucrat(std::string name, int grade);

    void                executeForm(AForm const & form) const;
	void				signForm(AForm &f) const;
	std::string const&	getName() const;
	int					getGrade() const;
	void				incGrade();
	void				decGrade();

	~Bureaucrat(void);

private:
	Bureaucrat(void);

	std::string const	_name;
	int					_grade;

public://exceptions v
	class GradeTooHighException : public std::exception
	{
    public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
    public:
		virtual const char*	what() const throw();
	};
private:
};
std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);
#endif
