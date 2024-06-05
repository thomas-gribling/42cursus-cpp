#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const &src );
		virtual ~WrongAnimal();

		WrongAnimal &operator=( WrongAnimal const &src );

		void makeSound() const;
		std::string getType() const;
};

#endif