#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;

		Animal();
		Animal( Animal const &src );
	
	public:
		virtual ~Animal();

		Animal &operator=( Animal const &src );

		virtual void makeSound() const = 0; // = 0: pure virtual, you need a subclass to use it
		std::string getType() const;
};

#endif