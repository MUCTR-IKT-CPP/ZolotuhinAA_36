#include "Constants.h"

class Shooter 
{
	private:
		int power;
		int durability;
		int distance;
		int cost;

	public:
		Shooter() : 
			power(Constants::power_shooter), 
			durability(Constants::durability_shooter),
			distance(Constants::distance[1] + (rand() % (Constants::distance[2] - Constants::distance[1] + 1))),
			cost(Constants::cost_1 + (rand() % (Constants::cost_2 - Constants::cost_1 + 1))) 
			{}

		void get_charaсteristic()
		{
			std::cout << "\tСтрелок:" << std::endl;
			std::cout << "\t\tСила - " << power << ";" << std::endl;
			std::cout << "\t\tСтойкость - " << durability << ";" << std::endl;
			std::cout << "\t\tДистанция - " << distance << ";" << std::endl;
			std::cout << "\t\tСтоимость - " << cost << ";" << std::endl;
		}
};
