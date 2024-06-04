#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	private:
		bool _guard;
	
	protected:
		const static int defaultHp = 100;
		const static int defaultEP = 50;
		const static int defaultDmg = 20;
	
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