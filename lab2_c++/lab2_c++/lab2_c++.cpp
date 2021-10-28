#include <iostream>
using namespace std;

int* FindMax(const int* start, const int* end) {
    const int* max = start;
    if (start != end)
        for (const int* current = start + 1; current <= end; current++) {
            if (*current > *max) max = current;
        }
    return const_cast<int*>(max);
}

void MySort(int* start, int* end) {
    if (start != end)
        for (int i = 0; i < end - start; i++)
            for (int* current = start + 1; current <= end - i; current++)
                if (*current < *(current - 1)) {
                    *current += *(current - 1);
                    *(current - 1) = *current - *(current - 1);
                    *current -= *(current - 1);
                }
}

void PrintArray(const int* start, const int* end) {
    for (auto current = start; current <= end; current++)
        cout << *current << " ";
}

int main()
{
    setlocale(LC_ALL, "russian");

    int array[25];
    for (int i = 0; i < 25; i++)
        array[i] = -100 + rand() % (201);

    cout << "До сортировки: ";
    PrintArray(array, array + 24);

    cout << endl << "Максимальное значение: " << *(FindMax(array, array + 24)) << endl;

    MySort(array, array + 24);

    cout << "После сортировки: ";
    PrintArray(array, array + 24);

}
