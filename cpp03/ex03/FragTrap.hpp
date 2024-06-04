#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	protected:
		const static int defaultHp = 100;
		const static int defaultEP = 100;
		const static int defaultDmg = 30;

	public:
		FragTrap();
		FragTrap( FragTrap const &src );
		FragTrap( std::string name );
		~FragTrap();

		FragTrap &operator=( FragTrap const &src );

		void highFivesGuys(void);
};

#endif