#include "Train.hpp"

Train::Train(const std::string station, const std::string time, int number):
station(station), time(time),number(number){ std::cout << "\nКонструктор Train\n";}
Train::Train(const Train& t):station(t.station), time(t.time),number(t.number){ std::cout << "\nКонструктор копирования Train\n";}
Train::~Train(){}
	/*геттеры и сеттеры для station*/
void Train::setStation(const std::string& s){ this->station = s; }
const std::string& Train::getStation()const { return this->station; }
	/*геттеры и сеттеры для time*/
void Train::setTime(const std::string& t){ this->time = t;}
const std::string& Train::getTime()const { return this->time;}
	/*геттеры и сеттеры для number*/
void Train::setTime(int n){this->number = n;}
int Train::getNumber()const{ return this->number;}

std::istream& operator >>(std::istream& in, Train& t){
	if(!(in >> t.number >> t.station >> t.time)){//если некорректный ввод, выбиваем исключение
		throw Exception("Некорректный ввод");
	}
	return in;
}
std::ostream& operator <<(std::ostream& out, const Train& t){
	out << "\nВремя: " << t.time
		 << "\nСтанция: " << t.station
		 << "\nНомер: " <<t.number;
    return out;
}

Train& Train::operator =(const Train& t){
	station = t.station;
	number = t.number;
	time = t.time;
	return *this;
}