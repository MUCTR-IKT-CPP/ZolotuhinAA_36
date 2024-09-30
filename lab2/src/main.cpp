/*
 * Лабораторная работа 2
 * Вариант 4
 *
 * Требуется написать программу, которая выполняет следующие действия.
 * 1. Получить от пользователя значение N.
 * 2. Выделить память под одномерный массив размером N. Тип int.
 * 3. Заполнить массив случайными числами от 0 до 20.
 * 4. Предложить пользователю выбор манипуляцию с массивом и реализовать её из следующего списка:
 * 	1) Поиск в массиве последовательностей идущих друг за другом в порядке возрастания, убывания или чередования (первый убывает, второй возрастает, третий убывает или наоборот), в зависимости от выбора пользователя, последовательностью будем считать 3 и более подряд идущих элементов, подходящих под условие.
 * 	2) Поиск максимального и минимального значения в массиве, с указанием их индекса, среднего арифметического и медианного значений среди всех элементов массива.
 * 	3) Формирование среза массива от введенного номера элемента a и до введенного номера элемента b (в итоге должен создаваться новый массив и выводиться в консоль).
 * 	4) Сортировка массива при помощи сортировки вставками (в итоге должен быть создан новый массив и выведен в консоль).
 */

#include <iostream>

void beginning(int, int *);
void ending(int, int *);
void print_array(int, int *);
void sequence(int, int *);
void finding_sequence(int, int *, int);
void max_min_avg_mdn(int, int *);
void splitting(int, int *);
int *insert_sort(int, int *);
void sorting(int, int *);

int main()
{
	std::srand(time(nullptr));

	int N;
	std::cout << std::endl << "Введите число: ";
	std::cin >> N;

	int *array = new int[N];

	for (int i = 0; i < N; i++)
		array[i] = rand() % 20;
	
	beginning(N, array);
	
	return 0;
}

/*
 * Начальное меню
 *
 * @param len длина массива.
 * @param array массив. 
 */

void beginning(int len, int *array)
{
	int choice;
	std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "\tМеню:" << std::endl;
	std::cout << "\t\t1. Поиск последовательностей." << std::endl;
	std::cout << "\t\t2. Поиск макс. и мин. значения, среднего арифм. и медианы."  << std::endl;
	std::cout << "\t\t3. Формирование среза массива от a до b." << std::endl;
	std::cout << "\t\t4. Сортировка массива." << std::endl;
	std::cout << "\t\t5. Выход" << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "Сделайте выбор: ";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1:
			sequence(len, array);
			break;
		
		case 2:
			max_min_avg_mdn(len, array);
			break;
		
		case 3:
			splitting(len, array);			
			break;
		case 4:
            sorting(len, array);
			break;

		case 5:
            delete [] array;
			exit(EXIT_SUCCESS);

		default:
			std::cout << "Вы ввели неправильную цифру. Попробуйте снова!" << std::endl << std::endl;
			beginning(len, array);	
	}
}

/*
 * Меню выхода
 *
 * @param len длина массива.
 * @param array массив. 
 */

void ending(int len, int *array)
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
			beginning(len, array);
			break;

		case 2:
            delete [] array;
			exit(EXIT_SUCCESS);

		default:
			std::cout << "Вы ввели неправильную цифру. Попробуйте снова!" << std::endl << std::endl;
			ending(len, array);
	}
}

/*
 * Вывод массива
 *
 * @param len длина массива.
 * @param array массив. 
 */

void print_array(int len, int *array)
{
	std::cout << "\tМассив: ";
	for (int i = 0; i < len; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

/*
 * Меню выбора последовательностей
 *
 * @param len длина массива.
 * @param array массив. 
 */

void sequence(int len, int *array)
{
	std::cout << std::endl << "---------- Поиск последовательностей идущих друг за другом в порядке возрастания, убывания или чередования -------------" << std::endl;  

	print_array(len, array);

    int choice;
  	std::cout << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "\tВыбор:" << std::endl;
	std::cout << "\t\t1. Увеличение." << std::endl;
	std::cout << "\t\t2. Уменьшение." << std::endl;
    std::cout << "\t\t3. Чередование." << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << std::endl << "Сделайте выбор: ";
	std::cin >> choice;

    std::cout << "-----------------------------------------------------" << std::endl;

	switch(choice)
	{
		case 1:
			finding_sequence(len, array, choice);
			break;

		case 2:
			finding_sequence(len, array, choice);
			break;

		case 3:
			finding_sequence(len, array, choice);
			break;

		default:
			std::cout << "Вы ввели неправильную цифру. Попробуйте снова!" << std::endl << std::endl;
			ending(len, array);
	}

    std::cout << "-----------------------------------------------------" << std::endl;

   	ending(len, array);
}

/*
 * Поиск последовательности
 *
 * @param len длина массива.
 * @param array массив. 
 * @param choice выбор.
 */

void finding_sequence(int len, int *array, int choice)
{
    bool found_sequence = false;

    for (int i = 0; i < len; i++) {
        int j = i;
        
        if (choice == 1) 
            while (j < len - 1 && array[j] < array[j + 1]) 
                j++;
        else if (choice == 2) 
            while (j < len - 1 && array[j] > array[j + 1]) 
                j++;
        else if (choice == 3) 
        {
            bool increasing = array[i] < array[i + 1];
            
            while (j < len - 1 && ((increasing && array[j] < array[j + 1]) || (!increasing && array[j] > array[j + 1]))) {
                j++;
                increasing = !increasing;
            }
        }

        if (j - i >= 2) 
        {
            found_sequence = true;

            std::cout << "\tПоследовательность от индекса " << i << " до " << j << ": ";

            for (int k = i; k <= j; k++) 
                std::cout << array[k] << " ";

            std::cout << std::endl;
            
            i = j;
        }
    }

    if (!found_sequence)
        std::cout << "\tПоследовательности нет" << std::endl;
} 

/*
 * Поиск максимума, минимума, среднего арифметического и медианы
 *
 * @param len длина массива.
 * @param array массив. 
 */

void max_min_avg_mdn(int len, int *array)
{
	std::cout << std::endl << "---------- Поиск макс. и мин. значения, среднего арифм. и медианы -------------" << std::endl;

	print_array(len, array);

	int max_value = array[0], min_value = array[len - 1], index_max = 0, index_min = len - 1;	
	float sum = 0.0, average, median;

	for (int i = 0; i < len; i++)
	{
		if (array[i] > max_value) 
		{
			max_value = array[i];
			index_max = i;
		}
		else if (array[i] < min_value)
		{
			min_value = array[i];
			index_min = i;
		}	

		sum += array[i]; 
	}

	std::cout << "\n\tMax: " << max_value << ". Index: " << index_max << std::endl;
        std::cout << "\tMin: " << min_value << ". Index: " << index_min << std::endl;

	average = sum / len;
	std::cout << "\n\tAverage: " << average << std::endl;

    int *inserted_array = insert_sort(len, array);
    median = (len % 2 == 0) ? ((inserted_array[len / 2 - 1] + inserted_array[len / 2]) / 2.0) : inserted_array[len / 2];
    std::cout << "\n\tMedian: " << median << std::endl; 

	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	ending(len, array);
}	

/*
 * Формирование среза массива от a до b
 *
 * @param len длина массива.
 * @param array массив. 
 */

void splitting(int len, int *array)
{
	std::cout << std::endl << "---------- Формирование среза массива от a до b -------------" << std::endl;
	
	print_array(len, array);

	int a, b;

	std::cout << std::endl << "\t\tВведите число a: ";
	std::cin >> a;

	std::cout << "\t\tВведите число b: ";
	std::cin >> b;

	int splitted_len = b - a;
	int splitted_array[splitted_len] = {0};

	for (int i = a, j = 0; i < b; i++, j++) 
		splitted_array[j] = array[i];
    
    std::cout << std::endl;	
	print_array(splitted_len, splitted_array);

	std::cout << "-------------------------------------------------------------" << std::endl;

	ending(len, array);
}

/*
 * Сортировка массива вставками
 *
 * @param len длина массива.
 * @param array массив. 
 */

int *insert_sort(int len, int *array)
{ 
    int *inserted_array = new int[len];
    
    for (int i = 0; i < len; i++)
    {
        int j = i - 1;

        int temp = array[i];
        
        for ( ; inserted_array[j] > temp && j >= 0; j--)
            inserted_array[j + 1] = inserted_array[j];
        
        inserted_array[j + 1] = temp;
    }

    return inserted_array;
} 

/*
 * Задание по сортировке массива вставками
 *
 * @param len длина массива.
 * @param array массив. 
 */

void sorting(int len, int *array)
{
    std::cout << std::endl << "---------- Сортировка массива вставками -------------" << std::endl;
	
	print_array(len, array);

    int *inserted_array = insert_sort(len, array); 

    print_array(len, inserted_array);

    delete [] inserted_array;

   	std::cout << "-----------------------------------------------------" << std::endl;

    ending(len, array);     
}
