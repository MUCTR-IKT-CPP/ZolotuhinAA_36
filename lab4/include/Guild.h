#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include "Mercenary.h"

class Guild 
{
	private:
		Mercenary** mercenaries;
		int size_mercenaries;
		int capacity_mercenaries;

		Mercenary** group;
		int size_group;
		int capacity_group;

		void resize_mercenaries_mercenaries() {
			capacity_mercenaries *= 2;
		   
			Mercenary** temp_mercenaries = new Mercenary*[capacity_mercenaries];
			for (int i = 0; i < size_mercenaries; i++) 
				temp_mercenaries[i] = mercenaries[i];
		  
			delete[] mercenaries;
			mercenaries = temp_mercenaries;
		}

		void resize_mercenariesGroup() 
		{
			capacity_group *= 2;

			Mercenary** temp_group = new Mercenary*[capacity_group];
			for (int i = 0; i < size_group; i++)
				temp_group[i] = group[i];
			
			delete[] group;
			group = temp_group;
		}

	public:
		Guild() : 
			size_mercenaries(0), 
			capacity_mercenaries(2),
			size_group(0),
			capacity_group(2) 
		{
			mercenaries = new Mercenary*[capacity_mercenaries];
			group = new Mercenary*[capacity_group];
		}

		~Guild() 
		{
			for (int i = 0; i < size_mercenaries; i++)
				delete mercenaries[i]; 

			delete[] mercenaries; 
			delete[] group; 
		}

		void set_add_mercenaries(Mercenary* mercenary) {
			if (size_mercenaries >= capacity_mercenaries) 
				resize_mercenaries_mercenaries();
			
			mercenaries[size_mercenaries++] = mercenary;
		}

		void get_random_mercenaries() {
			for (int i = 0; i < Constants::capacity; i++) 
			{ 
				int type = rand() % 3;

				switch(type)
				{
					case(0):
						set_add_mercenaries(new Mercenary(new Swordsman(), 0));
					case(1):
						set_add_mercenaries(new Mercenary(new Mage(), 1));
				
					case(2):
						set_add_mercenaries(new Mercenary(new Shooter(), 2));
				}
			}
		}

		void set_add_mercenaries_group(Mercenary* mercenary) {
			if (size_group >= capacity_group)
				resize_mercenariesGroup();

			group[size_group++] = mercenary;
		}

		void get_show_mercenaries() const { 
			for (int i = 0; i < size_mercenaries; i++) 
				mercenaries[i]->get_mercenary_characteristic();
		}

		void get_show_group() const {
			for (int i = 0; i < size_group; i++)
				group[i]->get_mercenary_characteristic();
		}

		void set_group() 
		{
			int choice = 12345;
			while (choice != 3)
			{
				std::cout << "----------------------------------------------------" << std::endl;
				std::cout << std::endl << "\tВыберите число:" << std::endl;
				std::cout << "\t\t1. Добавить наемника." << std::endl;
				std::cout << "\t\t2. Показать группу." << std::endl;
				std::cout << "\t\t3. Выход." << std::endl << std::endl;
				std::cout << "----------------------------------------------------" << std::endl;
				std::cin >> choice;

				if (choice == 1)
				{
					int counter_mercenary;
					std::cout << "Номер наемника в столбце: ";
					std::cin >> counter_mercenary;

					if (counter_mercenary > 0 && counter_mercenary <= size_mercenaries) 	{
						set_add_mercenaries_group(mercenaries[counter_mercenary - 1]);
						std::cout << "Наемник добавлен" << std::endl;
					}

					set_group();
				}
				else if (choice == 2)
				{
					std::cout << std::endl << "Группа:" << std::endl;
					get_show_group();
					set_group();
				} 
				else if (choice == 3) 
						break;
			}
		}
		
		void get_ideal_group()
		{
			if (size_mercenaries < 5) 
			{
				std::cout << "Недостаточно наемников для формирования группы." << std::endl;
				return;
			}

			int max_cost;
			std::cout << "Введите вашу сумму: ";
			std::cin >> max_cost;

			int sum_power = 0;
			int sum_durability = 0;
			int sum_cost = 0;
			size_group = 0; 

			for (int i = 0; i < size_mercenaries; i++) 
			{
				Mercenary* mercenary = mercenaries[i];
				sum_power += static_cast<Swordsman*>(mercenary->character)->Swordsman::get_power(); 
				sum_durability += static_cast<Swordsman*>(mercenary->character)->Swordsman::get_durability(); 
				sum_cost += static_cast<Swordsman*>(mercenary->character)->Swordsman::get_cost(); 

				set_add_mercenaries_group(mercenary);

				if (size_group >= 5 && sum_cost <= max_cost && sum_durability >= (sum_power / 2)) 
				{
					std::cout << "Идеальная группа сформирована:" << std::endl;
					get_show_group();
					return;
				}
			}

			std::cout << "Не удалось сформировать идеальную группу в пределах заданной стоимости." << std::endl;
		}
};
#endif // GUILD_H	
