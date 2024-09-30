#include "Constants.h"

class Swordsman
{
	private:
		int power;
		int durability;
		int distance;
		int cost;
	
	public:
		Swordsman() : 
			power(Constants::power_swordsman), 
			durability(Constants::durability_swordsman),
			distance(Constants::distance[0]),
			cost(Constants::cost_1 + (rand() % (Constants::cost_2 - Constants::cost_1 + 1))) 
			{}

		void get_charaсteristic() {
			std::cout << "\tМечник:" << std::endl;
			std::cout << "\t\tСила - " << power << ";" << std::endl;
			std::cout << "\t\tСтойкость - " << durability << ";" << std::endl;
			std::cout << "\t\tДистанция - " << distance << ";" << std::endl;
			std::cout << "\t\tСтоимость - " << cost << ";" << std::endl;
		}
};
