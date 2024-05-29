#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hp;  // Health points
		unsigned int _ep;  // Energy points
		unsigned int _dmg; // Attack damage
	
	public:
		ClapTrap();
		ClapTrap( ClapTrap const &src );
		ClapTrap( std::string name );
		~ClapTrap();

		ClapTrap &operator=( ClapTrap const &src);

		void attack( const std::string &target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};

#endif