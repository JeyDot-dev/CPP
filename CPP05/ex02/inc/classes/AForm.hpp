#ifndef		FORM_HPP
# define	FORM_HPP
#include <exception>
#include <iostream>

class Bureaucrat;

class	AForm
{

public:
	AForm(AForm const & src);
	AForm(std::string const& name, int s_req, int x_req);
	AForm&	operator=(AForm const& rhs);

	void				execute(Bureaucrat const & executor) const;

	void				beSigned(Bureaucrat const & b);

	std::string const&	getName() 		const;
	bool				getIsSigned()	const;
	int					getSignReq()	const;
	int					getExecReq()	const;
	
	AForm(void);
	~AForm(void);

private:
	virtual void		actuallyExecute(Bureaucrat const& executor) const = 0;
	std::string const	_name;
	bool				_is_signed;
	int const			_sign_req;
	int const			_exec_req;

public://exceptions v
    class FormNotSignedException : public std::exception
    {
        virtual const char* what() const throw();
    };
	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
private: 
};
std::ostream& operator<<(std::ostream& o, AForm const& rhs);
#endif
