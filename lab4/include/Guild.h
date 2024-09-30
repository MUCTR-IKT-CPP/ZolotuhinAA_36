#include "Swordsman.h"
#include "Mage.h"
#include "Shooter.h"
#include "Mercenary.h"

class Guild
{
	private:
		Mercenary **mercenaries;	
		int size;
		int capacity;
	public:
		Guild(int c) : size(0), capacity(c)
			{ mercenaries = new Mercenary*[capacity]; }

		~Guild()
		{
			for (int i = 0; i < size; i++)
				delete mercenaries[i];

			delete [] mercenaries;
		}

		void set_mercenary(void *character, const char *type)
		{
			if (size >= capacity)
			{
				capacity *= 2;

				Mercenary **new_mercenaries = new Mercenary*[capacity];
				for (int i = 0; i < size; i++)
					new_mercenaries[i] = mercenaries[i];
				
				delete [] mercenaries;
				mercenaries = new_mercenaries;
			}

			mercenaries[size++] = new Mercenary(character, type);
		}

		void get_mercenary_list()
		{
			std::cout << "Список наемников:" << std::endl;
			for (int i = 0; i < size; i++)
				std::cout << "Тип: " << mercenaries[i]->type << std::endl;
		}
};
