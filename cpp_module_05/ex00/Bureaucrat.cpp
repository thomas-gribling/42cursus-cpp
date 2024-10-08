#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("MISSINGNO"), _grade(150) {}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) {
	*this = src;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}


Bureaucrat &Bureaucrat::operator=( Bureaucrat const &src ) {
	(std::string)_name = src._name;
	_grade = src._grade;
	return *this;
}


void Bureaucrat::incrementGrade( int amt ) {
	if (_grade - amt < 1)
		throw GradeTooHighException();
	_grade -= amt;
}

void Bureaucrat::decrementGrade( int amt ) {
	if (_grade + amt > 150)
		throw GradeTooLowException();
	_grade += amt;
}

std::string const Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! (max is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! (min is 150)";
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName();
	os << ", bureaucrat grade ";
	os << b.getGrade();
	os << "." << std::endl;
	return os;
}