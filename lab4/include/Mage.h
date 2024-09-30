#include "Constants.h"

class Mage 
{
	private:
		int power;
		int durability;
		int distance;
		int cost;

	public:
		Mage() : 
			power(Constants::power_mage), 
			durability(Constants::durability_mage),
			distance(Constants::distance[1] + (rand() % (Constants::distance[2] - Constants::distance[1] + 1))),
			cost(Constants::cost_1 + (rand() % (Constants::cost_2 - Constants::cost_1 + 1))) 
			{}

		void get_charaсteristic()
		{
			std::cout << "\tМаг:" << std::endl;
			std::cout << "\t\tСила - " << power << ";" << std::endl;
			std::cout << "\t\tСтойкость - " << durability << ";" << std::endl;
			std::cout << "\t\tДистанция - " << distance << ";" << std::endl;
			std::cout << "\t\tСтоимость - " << cost << ";" << std::endl;
		}
};
