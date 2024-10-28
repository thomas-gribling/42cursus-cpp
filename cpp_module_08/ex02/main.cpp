#include "MutantStack.hpp"

int main()
{
	{
		std::cout << std::endl << "=== MUTANTSTACK ===" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl << "=== LIST (EXAMPLE) ===" << std::endl;
		std::list<int> l;

		l.push_back(5);
		l.push_back(17);

		std::cout << *(l.rbegin()) << std::endl;

		l.pop_back();

		std::cout << l.size() << std::endl;

		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		l.push_back(0);

		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
}