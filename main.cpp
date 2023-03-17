#include "Flower.h"
#include <fstream>
#include <vector>
using namespace std;


/*!
	* @file main.cpp
	* \brief Основной файл, в котором реализованы сортировки и проводится проверка их работы.
*/
/**
       * Реализация сортировки выбором.
	   * @param data ссылка на вектор состоящий из объектов класса Flower.
	   * @param size длина вектора.
*/
void selectSort(std::vector<Flower> &data, long size)
{
	long i, j, k;
	Flower x;
	for (i = 0; i < size - 1; i++)
	{
		k = i;
		x = data[i];
		for (j = i + 1; j < size; j++)
		{
			if (data[j] < x)
			{
				k = j; x = data[j];
			}
		}
		data[k] = data[i]; data[i] = x;
	}
}

/**
       * Вспомогательная функция для пирамидной сортировки
	   * @param data ссылка на вектор состоящий из объектов класса Flower.
	   * @param n - размер кучи.
	   * @param i - индекс элемента который будет корнем поддерева.
*/
void heapify(std::vector<Flower>& data, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l] > data[largest])
        largest = l;
    if (r < n && data[r] > data[largest])
        largest = r;

    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}
/**
       * Реализация пирамидальной сортировки.
	   * @param data ссылка на вектор состоящий из объектов класса Flower.
	   * @param n - длина вектора.
*/
void heapSort(std::vector<Flower>& data, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}


/**
       * Вспомогательная функция для быстрой сортировки.
	   * @param data ссылка на вектор состоящий из объектов класса Flower.
	   * @param start - индекс начала.
	   * @param end - индекс конца.
*/
int Partition(vector<Flower>& data, int start, int end) {

	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		if (data[i] < data[pivot]) {
			swap(data[i], data[j]);
			++j;
		}
	}
	swap(data[j], data[pivot]);
	return j;

}

/**
       * Реализация быстрой сортировки.
	   * @param data ссылка на вектор состоящий из объектов класса Flower.
	   * @param start - индекс начала.
	   * @param end - индекс конца.
*/
void Quicksort(vector<Flower>& data, int start, int end) {

	if (start < end) {
		int p = Partition(data, start, end);
		Quicksort(data, start, p - 1);
		Quicksort(data, p + 1, end);
	}
}

/**
       * Основная функция.
       * В ней считываются данные из файла и тестируются функции сортировки.
*/
int main()
{
	std::vector<Flower> data;
	const int size = 1024;
	char buff[size];
	ifstream readFile("/home/kali/ilya/Sort/data100000.txt");

	size_t flag = 0;
	std::vector<std::string> vec;
	vec.push_back("");
	vec.push_back("");
	vec.push_back("");
	vec.push_back("");
	while (!readFile.eof())
	{
		readFile.getline(buff, size);

		for (int i = 0; i < size; i++)
		{
			if (buff[i] == '\0')
			{
				break;
			}
			else
			{
				if (buff[i] != ' ')
					vec[flag].append(1, buff[i]);
				else
					flag += 1;
			}
		}
		data.push_back(Flower(vec[0], vec[1], vec[2], vec[3]));
		vec[0] = "";
		vec[1] = "";
		vec[2] = "";
		vec[3] = "";
		flag = 0;
	}
	readFile.close();
	clock_t t = clock();
	heapSort(data,data.size());
	std::cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC)<<'\n';


	return 0;
}
