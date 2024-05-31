#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		bool _guard;
	
	public:
		ScavTrap();
		ScavTrap( ScavTrap const &src );
		ScavTrap( std::string name );
		~ScavTrap();

		ScavTrap &operator=( ScavTrap const &src );

		void attack( const std::string &target );
		void guardGate();
};

#endif