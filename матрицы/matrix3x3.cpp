#include "Matrix3x3.h"
#include "pch.h"
#include <iostream>
#pragma once
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix3x3 //матричный класc
{
	int value = 3; //значение равное 3
	int arr[3][3]; // Объявление массива 
public:
	Matrix3x3() { //создание двумерного массива размера 3x3
		for (int i = 0; i < value; ++i) {          //заполняем строку с номером i
			for (int j = 0; j < value; ++j) {     //сначала пишем 0 ниже диагонали
				arr[i][j] = (i * 3) * 0;
			}
		}
	};

	int element(const int i, const int j) const { return arr[i][j]; }//метод чтения элементов матрицы
	void setElement(const int i, const int j, const int value) {//метод записи в элементы матрицы
		arr[i][j] = value;//фиксированный массив, который не распадается в указатель при передаче в функцию
	}

	void fillRandomElements(const int minVal, const int maxVal) {//метод, заполняющий элементы матрицы случайными значениями в нужном диапазоне [minVal, maxVal]
		srand(time(NULL));//генерирует случайное число, используя текущую дату
		for (int i = 0; i < value; ++i) { //заполнение массива
			for (int j = 0; j < value; ++j) {
				arr[i][j] = rand() % (maxVal - minVal + 1) + minVal;
			}
		}
	}

	int sumPrincipalDiag() const {//метод, вычисляющий сумму элементов главной диагонали
		int principal = 0;//переменная, в которой будет хранится результат суммы
		for (int i = 0; i < value; i++) {  //заполнение массива
			principal += arr[i][i];
		}
		return principal;
	}

	int sumSecondaryDiag() const {//метод, вычисляющий сумму элементов побочной диагонали
		int secondary = 0; //переменная, в которой будет хранится результат суммы
		for (int i = 0; i < value; i++) {   //заполнение массива
			secondary += arr[i][2 - i];
		}
		return secondary;
	}

	int productPrincipalDiag() const {//метод, вычисляющий произведение элементов главной диагонали
		int princ = 1;//переменная, в которой будет хранится результат произведения
		for (int i = 0; i < value; i++) {//заполнение массива
			princ *= arr[i][i];
		}
		return princ;
	}

	int productSecondaryDiag() const {//метод, вычисляющий произведение элементов побочной диагонали
		int second = 1; //переменная, в которой будет хранится результат произведения
		for (int i = 0; i < value; i++) {//заполнение массива
			second *= arr[i][2 - i];
		}
		return second;
	}

	int sumRow(const int iRow) const {//метод, вычисляющий сумму элементов в строке iRow
		int row = 0; //переменная, в которой будет хранится сумма 
		for (int i = 0; i < value; i++) {//вычисление суммы
			row += arr[iRow][i];
		}
		return row;
	}

	int minColumn(const int iCol) const {//метод, вычисляющий минимальный элемент в столбце iCol
		int min = INT32_MAX;
		for (int i = 0; i < value; i++) {
			min = arr[i][iCol] < min ? arr[i][iCol] : min;
		}
		return min;
	}

	int maxColumn(const int iCol) const {//метод, вычисляющий максимальный элемент в столбце iCol
		int max = INT32_MIN; 
		for (int i = 0; i < value; i++) {
			max = arr[i][iCol] > max ? arr[i][iCol] : max;
		}
		return max;
	}
};