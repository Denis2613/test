#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class Train{
	std::string station;//пункт назначения
	int number;//номер поезда
	std::string time;//время отправления
public:
	Train(const std::string station = "", const std::string time = "", int number = 0);
	Train(const Train& t);
	~Train();
	/*геттеры и сеттеры для station*/
	void setStation(const std::string& s);
	const std::string& getStation()const;
	/*геттеры и сеттеры для time*/
	void setTime(const std::string& t);
	const std::string& getTime()const;
	/*геттеры и сеттеры для number*/
	void setTime(int n);
	int getNumber()const;
	/*операторы ввода и вывода*/
	friend std::istream& operator >>(std::istream& in, Train& t);
	friend std::ostream& operator <<(std::ostream& out, const Train& t);
	Train& operator =(const Train& t);//опиратор присваивания
};													  