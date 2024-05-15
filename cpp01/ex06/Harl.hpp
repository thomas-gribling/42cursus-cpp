#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		int	getLevel( std::string level);
	
	public:
		void	complainMore( std::string level );
};

typedef void (Harl::*func)(void);

#endif