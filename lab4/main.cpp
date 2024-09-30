#include <iostream>

class Warrior
{
	private:
		int power;
	
	public:
		Warrior(int p) : power(p) { }

		void show()
			{ std::cout << power; } 
};

int main()
{
	Warrior w1(5);
	w1.show();

	return 0;
}
	
