#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class AMateria {
	public:
		AMateria();
		AMateria( AMateria const &src );
		AMateria( std::string const &type );
		~AMateria();

		AMateria &operator=( AMateria const &src );

		std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		//virtual void use(ICharacter &target);
};

#endif