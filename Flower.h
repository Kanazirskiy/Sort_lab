#ifndef Flower_h
#define Flower_h


#include <iostream>
#include <string>


/*!
	* @file Flower.h
	* \brief Класс цветы. Содержит 4 поля описывающие: название цветка, цвет, аромат и регион.
*/

class Flower
{
public:
	/**
       * Конструктор по умолчанию.
	   * Присваивает всем полям класса нулевое значение(пустая строка).
	*/
	Flower();
	/**
       * Конструктор.
	   * @param name строка, означающая название цветка.
       * @param colour строка, означающая цвет цветка.
	   * @param flavor строка, означающая аромат цветка.
	   * @param reg строка, означающая регион цветка.
	*/
	Flower(std::string name, std::string colour, std::string flavor, std::string reg);
	/**
       * Конструктор копирования.
	   * Создаёт новый объект класса Flower со значениями полей как у объекта other.
	   * @param other ссылка на другой объекта класса Flower.
	*/
	Flower(const Flower& other);
	/**
       * Перегрузка оператора '>'.
	   * Проводить сравнение по 3 полям - name, colour, flavor. В соответствующем порядке.
	   * @param other ссылка на другой объекта класса Flower.
	   * @return bool
	*/
	bool operator >(const Flower& other);
	/**
       * Перегрузка оператора '<'.
	   * Проводить сравнение по 3 полям - name, colour, flavor. В соответствующем порядке.
	   * @param other ссылка на другой объекта класса Flower.
	   * @return bool
	*/
	bool operator <(const Flower& other);
	/**
       * Перегрузка оператора '>='.
	   * Проводить сравнение по 3 полям - name, colour, flavor. В соответствующем порядке.
	   * @param other ссылка на другой объекта класса Flower.
	   * @return bool
	*/
	bool operator >=(const Flower& other);
	/**
       * Перегрузка оператора '<='.
	   * Проводить сравнение по 3 полям - name, colour, flavor. В соответствующем порядке.
	   * @param other ссылка на другой объекта класса Flower.
	   * @return bool
	*/
	bool operator <=(const Flower& other);
	/**
	   * Перегрузка оператора '<<' с помощью дружественной функции.
	   * @param out поток вывода.
	   * @param obj ссылка на объект класса Flower.
	*/
	friend std::ostream& operator << (std::ostream& out, const Flower& obj);
private:
	std::string name;/*!< an integer value */
	std::string colour;/*!< Цвет цветка.*/
	std::string flavor;/*!< Аромат цветка.*/
	std::string reg;/*!< Регион.*/
	
};

int diff(std::string first, std::string second);

#endif //Flower.h
