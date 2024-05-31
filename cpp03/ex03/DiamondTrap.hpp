#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string _name;
	
	public:
		DiamondTrap();
		DiamondTrap( DiamondTrap const &src );
		DiamondTrap( std::string name );
		~DiamondTrap();

		DiamondTrap &operator=( DiamondTrap const &src );

		void whoAmI();
};

#endif