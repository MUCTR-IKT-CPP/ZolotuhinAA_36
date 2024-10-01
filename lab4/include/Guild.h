#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include "Mercenary.h"

class Guild {
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

    void set_add_mercenaries_group(Mercenary* mercenary) {
        if (size_group >= capacity_group)
            resize_mercenariesGroup();

        group[size_group++] = mercenary;
    }

    void get_show_mercenaries() const {
        int number = 1;

        for (int i = 0; i < size_mercenaries; i++) {
            std::cout << number << ". ";
            mercenaries[i]->get_mercenary_characteristic();
            number++;
        }
    }

    void get_show_group() const {
        int number = 1;

        for (int i = 0; i < size_group; i++) {
            std::cout << number << ". ";
            group[i]->get_mercenary_characteristic();
            number++;
        }
    }

    void set_group() {
        int choice;
        do {
            std::cout << std::endl << "Select an action:" << std::endl;
            std::cout << "1. Print Group";
            std::cout << "2. Add mercenary to group";
            std::cout << "0. Выход";

            std::cin >> choice;

            if (choice == 1) {
                std::cout << std::endl << "Группа:" << std::endl;
                get_show_group();
            } else if (choice == 2) {
                int number_mercenary;
                std::cout << "Количество наемников: ";
                std::cin >> number_mercenary;

                if (number_mercenary > 0 && number_mercenary <= size_mercenaries) {
                    set_add_mercenaries_group(mercenaries[number_mercenary - 1]);
                    std::cout << "Наемник добавлен";
                }
            }
        } while (choice != 0);
    }

    void get_random_mercenaries() {
        for (int i = 0; i < 5; i++) { 
            int type = rand() % 3;
			if (type == 0) {
                set_add_mercenaries(new Mercenary(new Swordsman(), 0));
            } else if (type == 1) {
                set_add_mercenaries(new Mercenary(new Mage(), 1));
            } else {

                set_add_mercenaries(new Mercenary(new Shooter(), 2));
            }
        }
    }

    void get_ideal_group(int max_cost)
	{
        if (size_mercenaries < 5) {
            std::cout << "Недостаточно наемников для формирования группы." << std::endl;
            return;
        }

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
