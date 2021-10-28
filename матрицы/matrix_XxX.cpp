#include "MatrixXnX.h"
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


class MatrixXnX //матричный класс
{
	int** arr;   //указатель на указатель на int* arr (указатель на пам€ть, в которой лежит двумерна€ матрица)
	int size = 0; //переменна€ начального размера 0
public:
	MatrixXnX(const int iDim) { //создание двумерного массива, по умолчанию принимающий размерность матрицы iDim
		arr = new int* [iDim]; //выделение пам€ти дл€ массива 
		for (int x = 0; x < iDim; x++) //заполнение массива 
			arr[x] = new int[iDim];
		for (int i = 0; i < iDim; i++) {
			for (int j = 0; j < iDim; j++) {
				arr[i][j] = (i * size) * 0;
			}
		}
		size = iDim;
	}
	int element(const int i, const int j) const { return arr[i][j]; } //метод чтени€ элементов матрицы

	void setElement(const int i, const int j, const int value) { //метод записи в элементы матрицы
		arr[i][j] = value;//фиксированный массив, который не распадаетс€ в указатель при передаче в функцию
	}
	}

	void fillRandomElements(const int minVal, const int maxVal) {// метод, заполн€ющий элементы матрицы случайными значени€ми в нужном диапазоне[minVal, maxVal]
		srand(time(NULL));   //генерирует случайное число, использу€ текущую дату
		for (int i = 0; i < size; i++) { //заполнение массива
			for (int j = 0; j < size; j++) {
				arr[i][j] = rand() % (maxVal - minVal + 1) + minVal;
			}
		}
	}

	int sumPrincipalDiag() const { //метод, вычисл€ющий сумму элементов главной диагонали
		int principal = 0;  //переменна€, в которой будет хранитс€ результат суммы
		for (int i = 0; i < size; i++) {   //заполнение массива
			principal += arr[i][i];
		}
		return principal;
	}

	int sumSecondaryDiag() const { //метод, вычисл€ющий произведение элементов побочной диагонали
		int secondary = 0; //переменна€, в которой будет хранитс€ результат суммы
		for (int i = 0; i < size; i++) {  //заполнение массива
			secondary += arr[i][size - 1 - i];
		}
		return secondary;
	}

	int productPrincipalDiag() const { //метод, вычисл€ющий произведение элементов главной диагонали
		int princ = 1; // переменна€, в которой будет хранитс€ результат произведени€
		for (int i = 0; i < size; i++) { //заполнение массива
			princ *= arr[i][i];
		}
		return princ;
	}

	int productSecondaryDiag() const {//метод, вычисл€ющий произведение элементов побочной диагонали
		int second = 1;   //переменна€, в которой будет хранитс€ результат произведени€
		for (int i = 0; i < size; i++) {//заполнение массива
			second *= arr[i][size - 1 - i];
		}
		return second;
	}

	int sumRow(const int iRow) const {//метод, вычисл€ющий сумму элементов в строке iRow
		int row = 0; //переменна€, в которой будет хранитс€ сумма 
		for (int i = 0; i < size; i++) {//вычисление суммы
			row += arr[iRow][i];
		}
		return row;
	}

	int minColumn(const int iCol) const { //метод, вычисл€ющий минимальный элемент в столбце iCol
		int min = INT32_MAX;
		for (int i = 0; i < size; i++) {
			min = arr[i][iCol] < min ? arr[i][iCol] : min;
		}
		return min;
	}

	int maxColumn(const int iCol) const {//метод, вычисл€ющий максимальный элемент в столбце iCol
		int max = INT32_MIN;
		for (int i = 0; i < size; i++) {
			max = arr[i][iCol] > max ? arr[i][iCol] : max;
		}
		return max;
	}

	void deleteArr() { //освобождение пам€ти под элементы матрицы
		delete[] arr; //освобождение выделенной пам€ти 
		arr = nullptr; //обнуление arr
	}
};