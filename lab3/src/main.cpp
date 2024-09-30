/*
 * Лабораторная работа 3
 * Вариант 3
 *
 * Требуется написать программу, в которой:
 *     1) Будет реализована структура Фигура с полями: Тип (заданы перечислением Квадрат, Шестиугольник (с равными сторонами), Треугольник (Равносторонний), Круг), Сторона;
 *     2) Пользователь вводит число N;
 *     3) Создан массив, хранящий N фигур различного размера и типа;
 *     4) Сгенерировано N фигур различного типа и размера;
 *     5) Написать функции, которые:
 *         a) Подсчитают суммарную площадь фигур;
 *         b) Подсчитать количество всех типов фигур, имеющихся в массиве;
 *         c) Вывести все фигуры с площадью, больше указанной пользователем;
 *         d) Найти радиус окружности, в которую можно вписать все сгенерированные фигуры.
 * Генерация набора структур случайными генератора в рамках адекватных граничных условий, т.е. фигуры генерируются существующими, а размеры не превышающими 100 единиц).
 */

#include <iostream>
#include <math.h>

const int ENUM_LEN = 4;
enum class Type { Square, Hexagon, Triangle, Circle };

const char* TypeToString(Type type)
{
    switch (type)
    {
        case Type::Square: 
			return "Квадрат";

        case Type::Hexagon: 
			return "Шестиугольник";

        case Type::Triangle:
			return "Треугольник";

        case Type::Circle:
			return "Круг";
        
		default: 
			return "Ошибка";
    }
}

const int SIZE = 100;

struct Shape 
{
    Type type;
    double side;
 
    double area() const 
	{
        switch (type) 
		{
            case Type::Square:
                return side * side;

            case Type::Hexagon:
                return (3 * sqrt(3) / 2) * side * side; 

            case Type::Triangle:
                return (sqrt(3) / 4) * side * side; 

            case Type::Circle:
                return M_PI * side * side; 
			
			default:
				return 0;
        }
    }
};

void print_array(int, Shape *);
void beginning(int, Shape *);
void ending(int, Shape *);
void sum_area(int, Shape *);
void number_shapes(int, Shape *);
void print_great_shapes(int, Shape *);
void finding_radius(int, Shape *);

int main() 
{
    srand((time(nullptr)));

    int N;
    std::cout << std::endl << "\tВведите число: ";
    std::cin >> N;

    struct Shape *shapes = new Shape[N];
    for (int i = 0; i < N; i++)
	{
        shapes[i].type = static_cast<Type>(rand() % ENUM_LEN); 
        shapes[i].side = rand() % SIZE + 1; 
    }

	print_array(N, shapes);
	
	beginning(N, shapes);

    return 0;
}

/*
 * Вывод массива, хранящего N фигур различного размера и типа, и их площадей 
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void print_array(int len, Shape *shapes)
{
	for (int i = 0; i < len; i++)	
	{
		std::cout << std::endl << "\t\tТип = " << TypeToString(shapes[i].type);
		std::cout << ", сторона = " << shapes[i].side;
		std::cout << ", Площадь = " << shapes[i].area() << "." << std::endl;	
	}
}

/*
 * Начальное меню
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void beginning(int len, Shape *shapes)
{
	int choice;
	std::cout << std::endl << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "\tМеню:" << std::endl;
	std::cout << "\t\t1. Подсчет суммарной площади фигур." << std::endl;
	std::cout << "\t\t2. Подсчет количества всех типов фигур, имеющихся в массиве."  << std::endl;
	std::cout << "\t\t3. Вывод всех фигур с площадью, больше указанной пользователем." << std::endl;
	std::cout << "\t\t4. Поиск радиуса окружности, в которую можно вписать все сгенерированные фигуры." << std::endl;
	std::cout << "\t\t5. Выход" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "Сделайте выбор: ";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1:
			sum_area(len, shapes);
			break;
		
		case 2:
			number_shapes(len, shapes);
			break;
		
		case 3:
			print_great_shapes(len, shapes);	
			break;

		case 4:
            finding_radius(len, shapes);
			break;

		case 5:
            delete [] shapes;
			exit(EXIT_SUCCESS);

		default:
			std::cout << "Вы ввели неправильную цифру. Попробуйте снова!" << std::endl << std::endl;
			beginning(len, shapes);	
	}
}

/*
 * Меню выхода
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void ending(int len, Shape *shapes)
{
	int choice;
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "\t\t1. Вернуться в меню." << std::endl;
	std::cout << "\t\t2. Выход" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << std::endl << "Сделайте выбор: ";
	std::cin >> choice;

	switch(choice)
	{
		case 1:
			beginning(len, shapes);
			break;

		case 2:
            delete [] shapes;
			exit(EXIT_SUCCESS);

		default:
			std::cout << "Вы ввели неправильную цифру. Попробуйте снова!" << std::endl << std::endl;
			ending(len, shapes);
	}
}

/*
 * Подсчет суммарной площади фигур 
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void sum_area(int len, Shape *shapes)
{ 
	std::cout << std::endl << "---------- Подсчет суммарной площади фигур ----------" << std::endl;

    double sum = 0;

    for (int i = 0; i < len; i++) 
        sum += shapes[i].area();

	std::cout << "\t" << "Суммарная площадь фигур: " << sum << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;
	
	ending(len, shapes);
}

/*
 * Подсчет количества всех типов фигур 
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void number_shapes(int len, Shape *shapes)
{
	std::cout << std::endl << "---------- Подсчет количества всех типов фигур ----------" << std::endl;

	int *count = new int[ENUM_LEN]; 
    
	for (int i = 0; i < len; i++) 
        count[static_cast<int>(shapes[i].type)]++;

	std::cout << "\tКоличество типов фигур: " << std::endl;
    std::cout << "\t\tКвадрат - " << count[static_cast<int>(Type::Square)] << std::endl;
    std::cout << "\t\tШестиугольник - " << count[static_cast<int>(Type::Hexagon)] << std::endl;
    std::cout << "\t\tТреугольник - " << count[static_cast<int>(Type::Triangle)] << std::endl;
    std::cout << "\t\tКруг - " << count[static_cast<int>(Type::Circle)] << std::endl;

	delete [] count; 

	std::cout << "-----------------------------------------------------" << std::endl;
	
	ending(len, shapes);
}

/*
 * Вывод всех фигур с площадью, больше указанной пользователем 
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void print_great_shapes(int len, Shape *shapes) 
{
	std::cout << std::endl << "---------- Вывод всех фигур с площадью, больше указанной пользователем ----------" << std::endl;

	double min_area;
    std::cout << "\tВведите минимальную площадь для фильтрации фигур: ";
    std::cin >> min_area;

    std::cout << "\tФигуры с площадью, большей чем " << min_area << ":" << std::endl;
	bool absent = true;
    for (int i = 0; i < len; i++) 
	{	
        if (shapes[i].area() > min_area) 
		{
            std::cout << std::endl << "\t\tТип = " << TypeToString(shapes[i].type) << std::endl; 
			std::cout << "\t\tСторона = " << shapes[i].side << std::endl;
            std::cout << "\t\tПлощадь = " << shapes[i].area() << std::endl;
			absent = false;
		}
	}
	std::cout << ((absent) ? "\t\tТаких нет\n" : "");

	std::cout << "---------------------------------------------------------------------------------" << std::endl;

	ending(len, shapes);
}

/*
 * Поиск радиуса окружности, в которую можно вписать все сгенерированные фигуры 
 *
 * @param len длина массива.
 * @param shapes массив. 
 */

void finding_radius(int len, Shape *shapes) 
{
	std::cout << std::endl << "---------- Поиск радиуса окружности, в которую можно вписать все сгенерированные фигуры ----------" << std::endl;

    double radius = 0;
	double shape_radius;
    for (int i = 0; i < len; i++) 
	{
        switch (shapes[i].type) 
		{
            case Type::Square:
				shape_radius = shapes[i].side * sqrt(2) / 2;
                radius = (radius > shape_radius) ? radius : shape_radius;
                break;

            case Type::Hexagon:
				shape_radius = shapes[i].side;
                radius = (radius > shape_radius) ? radius : shape_radius;
                break;

            case Type::Triangle:
				shape_radius = shapes[i].side / sqrt(3);
                radius = (radius > shape_radius) ? radius : shape_radius;
                break;

            case Type::Circle:
				shape_radius = shapes[i].side;
                radius = (radius > shape_radius) ? radius : shape_radius;
                break;
        }
    }

    std::cout << "\tРадиус окружности, в которую можно вписать все фигуры: " << radius << std::endl;

	std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;

	ending(len, shapes);
}
