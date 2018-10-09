#include "Train.hpp"
#include <iostream>
#define cnt 2		//количество поездов
#define SWAP(A, B) { Train t = A; A = B; B = t; } //меняем местами

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	Train trains[cnt];
	int a;
	//меню
	while(true){
		cout << "\n1. Выход\n2. Считать поезда\n3. Вывести информацию\n";
		if(!(cin >> a)){//если некорректный ввод, то пропускаем всё
		 continue;
		}
		if(a == 1){
			return 0;
		}
		else if(a == 2){
			//считываем данные о поездах
			cout << "Номер станция время\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> trains[i];
				}	  //обрабатываем исключение
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//откатываем i назад для повторного ввода
				}
			}
			/*сортируем пузырьком по номерам*/
			int j, n = cnt;
			  do {
				int nn = 0;
				for (j = 1; j < n; ++j)
				  if (trains [j-1].getNumber() > trains[j].getNumber()) {
					SWAP( trains[j-1], trains[j] );
					nn = j;
				  }
				n = nn;
			  } while (n);
		}
		else if(a == 3){
			cout << "Номер: ";
			if(!(cin >> a)){
				cout << "некорректный номер";
				continue;
			}
			int i = 0;
			for(; i < cnt; ++i){
				if(trains[i].getNumber() == a){
					cout << trains[i];
					break;
				}
			}
			if(i == cnt){
				cout << "такого поезда нет!";
			}
		}
	}

}
