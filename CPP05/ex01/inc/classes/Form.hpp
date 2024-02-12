#ifndef		FORM_HPP
# define	FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class	Form
{

public:
	Form(Form const & src);
	Form&	operator=(Form const& rhs);

	void				beSigned(Bureaucrat const & b);

	std::string const&	getName() 		const;
	bool				getIsSigned()	const;
	int					getSignReq()	const;
	int					getExecReq()	const;
	
	Form(void);
	~Form(void);
private:
	std::string const&	_name;
	bool				_is_signed;
	int const			_sign_req;
	int const			_exec_req;

private: //exceptions v
	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	}
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	}

};
std::ostream& operator<<(std::ostream& o, Form const& rhs);
#endif
