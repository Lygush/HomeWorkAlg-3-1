#include <iostream>

void PrintMass(int* mass, int size) {
    for (int i{}; i < size; ++i) {
        std::cout << mass[i] << " ";
    }
    std::cout << std::endl;
}

void MergeSort(int* arr, int size) {
    if (size == 1) {
        return;
    }
    else {
        int firstSize{size / 2}, secondSize{firstSize};
        if (size % 2 != 0) {
            secondSize++;
        }

        int* firstArr = new int[firstSize];
        int* secondArr = new int[secondSize];
        int j{}, k{};
        for (int i{}; i < size; ++i) {
            if (j < firstSize ) {
                firstArr[j] = arr[i];
                j++;
            }
            else {
                secondArr[k] = arr[i];
                k++;
            }
        }
        MergeSort(firstArr, firstSize);
        MergeSort(secondArr, secondSize);

        j = 0;
        k = 0;
        int* resultArr = new int[size];
        for (int i{}; i < size; ++i) {
            if (j == firstSize) {
                resultArr[i] = secondArr[k];
                k++;
            }
            else if (k == secondSize) {
                resultArr[i] = firstArr[j];
                j++;
            }
            else {
                if (firstArr[j] <= secondArr[k]) {
                    resultArr[i] = firstArr[j];
                    j++;
                }
                else {
                    resultArr[i] = secondArr[k];
                    k++;
                }
            }
        }
        for (int i{}; i < size; ++i) {
            arr[i] = resultArr[i];
        }
        delete[] firstArr;
        delete[] secondArr;
        delete[] resultArr;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int arrFirst[10] {3, 43, 3, 29, 18, 72, 57, 61, 2, 33};
    std::cout << "Исходный массив: ";
    PrintMass(arrFirst, 10);
    MergeSort(arrFirst, 10);
    std::cout << "Отсортированный массив: ";
    PrintMass(arrFirst, 10);
    std::cout << std::endl;

    int arrSecond[15] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    std::cout << "Исходный массив: ";
    PrintMass(arrSecond, 15);
    MergeSort(arrSecond, 15);
    std::cout << "Отсортированный массив: ";
    PrintMass(arrSecond, 15);
    std::cout << std::endl;

    int arrThird[18] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    std::cout << "Исходный массив: ";
    PrintMass(arrThird, 18);
    MergeSort(arrThird, 18);
    std::cout << "Отсортированный массив: ";
    PrintMass(arrThird, 18);
    std::cout << std::endl;

    return 0;
}

