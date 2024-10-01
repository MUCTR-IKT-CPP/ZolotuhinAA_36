#include "Constants.h"

class Mage 
{
	private:	
		int power;
		int durability;
		int distance;
		int cost;
	
	public:
		Mage() {
			power = Constants::power_mage; 
			durability = Constants::durability_mage; 
			distance = Constants::distance[rand() % 3]; 
			cost = Constants::cost_1 + (rand() % (Constants::cost_2 - Constants::cost_1 + 1));
		}	
	
		void get_charaсteristic()
		{
			std::cout << "\t\tМаг:" << std::endl;
			std::cout << "\t\t\tСила - " << power << ";" << std::endl;
			std::cout << "\t\t\tСтойкость - " << durability << ";" << std::endl;
			std::cout << "\t\t\tДистанция - " << distance << ";" << std::endl;
			std::cout << "\t\t\tСтоимость - " << cost << ";" << std::endl;
		}
};
