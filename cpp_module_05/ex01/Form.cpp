#include "Form.hpp"

Form::Form() : _name("papier"), _isSigned(false), _toSign(150), _toExec(150) {}

Form::Form( Form const &src ) : _name(src._name), _isSigned(false), _toSign(src._toSign), _toExec(src._toExec) {}

Form::Form( std::string const name, int const toSign, int const toExec ) : _name(name), _isSigned(false), _toSign(toSign), _toExec(toExec) {
	if (_toSign < 1 || _toExec < 1)
		throw GradeTooHighException();
	if (_toSign > 150 || _toExec > 150)
		throw GradeTooLowException();
}

Form::~Form() {}


Form &Form::operator=( Form const &src ) {
	(std::string)_name = src.getName();
	_isSigned = src.getIsSigned();
	return *this;
}


void Form::beSigned( Bureaucrat const &b ) {
	if (_isSigned)
		throw AlreadySignedException();
	if (b.getGrade() <= _toSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string const Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getToSign() const {
	return _toSign;
}

int Form::getToExec() const {
	return _toExec;
}


const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high! (max is 1)";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low! (min is 150)";
}

const char *Form::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
	std::string s = "";
	if (!f.getIsSigned())
		s = "n't";
	os << "Form \"";
	os << f.getName();
	os << "\" is" << s << " signed. Grade needed to sign it is ";
	os << f.getToSign();
	os << ", grade needed to execute it is ";
	os << f.getToExec();
	os << "." << std::endl;
	return os;
}
