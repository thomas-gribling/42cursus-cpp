#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class ICharacter{
	protected:
		std::string name;
		AMateria *inv[4];
	
	public:
		ICharacter();
		ICharacter( ICharacter const &src );
		virtual ~ICharacter();

		ICharacter &operator=( ICharacter const &src );

		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif