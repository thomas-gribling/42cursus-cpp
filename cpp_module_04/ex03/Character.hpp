#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string name;
		AMateria *inv[4];

	public:
		Character();
		Character( Character const &src );
		Character( std::string name );
		~Character();

		Character &operator=( Character const &src );

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif