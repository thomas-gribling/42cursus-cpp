#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice( Ice const &src );
		virtual ~Ice();

		Ice &operator=( Ice const &src );

		Ice *clone() const;
		void use(ICharacter &target);
};

#endif