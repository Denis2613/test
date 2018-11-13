#include "Train.hpp"
#include <iostream>
#define cnt 8		//количество поездов
#define SWAP(A, B) { Train t = A; A = B; B = t; } //меняем местами

using namespace std;

void sort(Train *trains) {
	int j, n = cnt;
	do {
		int nn = 0;
		for (j = 1; j < n; ++j)
			if (trains[j - 1].getNumber() > trains[j].getNumber()) {
				SWAP(trains[j - 1], trains[j]);
				nn = j;
			}
		n = nn;
	} while (n);
}

Train* search(Train *trains, int a) {

	int i = 0;
	for (; i < cnt; ++i) {
		if (trains[i].getNumber() == a) {
			return trains + i;
		}
	}
	return nullptr;
}

void read(Train *trains) {
	cout << "Номер станция время\n";
	for (int i = 0; i < cnt; ++i) {
		try {
			cin >> trains[i];
		}	  //обрабатываем исключение
		catch (const Exception& e) {
			cout << "\n" << e.what() << "\n";
			--i;//откатываем i назад для повторного ввода
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	Train trains[cnt];
	int a;
	//меню
	while (true) {
		cout << "\n1. Выход\n2. Считать поезда\n3. Вывести информацию\n";
		if (!(cin >> a)) {//если некорректный ввод, то пропускаем всё
			continue;
		}
		if (a == 1) {
			return 0;
		}
		else if (a == 2) {
			//считываем данные о поездах
			read(trains);
			/*сортируем пузырьком по номерам*/
			sort(trains);

		}
		else if (a == 3) {
			int a;
			cout << "Номер: ";
			if (!(cin >> a)) {
				cout << "некорректный номер";
				continue;
			}
			Train *tmp = search(trains, a);
			if (tmp != nullptr) {
				cout << *tmp;
			}
			else {
				cout << "Не найдено";
			}
		}
	}

}
