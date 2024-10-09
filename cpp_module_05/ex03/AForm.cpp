#include "AForm.hpp"

AForm::AForm() : _name("papier"), _isSigned(false), _toSign(150), _toExec(150) {}

AForm::AForm( AForm const &src ) : _name(src._name), _isSigned(false), _toSign(src._toSign), _toExec(src._toExec) {}

AForm::AForm( std::string const name, int const toSign, int const toExec ) : _name(name), _isSigned(false), _toSign(toSign), _toExec(toExec) {
	if (_toSign < 1 || _toExec < 1)
		throw GradeTooHighException();
	if (_toSign > 150 || _toExec > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}


AForm &AForm::operator=( AForm const &src ) {
	(std::string)_name = src.getName();
	_isSigned = src.getIsSigned();
	return *this;
}


void AForm::beSigned( Bureaucrat const &b ) {
	if (_isSigned)
		throw AlreadySignedException();
	if (b.getGrade() <= _toSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string const AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getToSign() const {
	return _toSign;
}

int AForm::getToExec() const {
	return _toExec;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_isSigned)
		throw MustBeSignedException();
	if (executor.getGrade() <= _toExec)
		executeSpecial();
	else
		throw GradeTooLowException();
}


const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char *AForm::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}

const char *AForm::MustBeSignedException::what() const throw() {
	return "Form must be signed in order to be executed!";
}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
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
