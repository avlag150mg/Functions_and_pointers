#include <iostream> 
#include <Windows.h>

using namespace std;

int* allocateArray(int size) {
    return new int[size];
}
void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; 
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* &arr) {
    delete[] arr;
    arr = nullptr;
}

void separateElements(const int* arr, int size, int* &positives, int &posSize, int* &negatives, int &negSize, int* &zeros, int &zeroSize) {
    posSize = negSize = zeroSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) posSize++;
        else if (arr[i] < 0) negSize++;
        else zeroSize++;
    }

    positives = new int[posSize];
    negatives = new int[negSize];
    zeros = new int[zeroSize];

    int p = 0, n = 0, z = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positives[p++] = arr[i];
        else if (arr[i] < 0) negatives[n++] = arr[i];
        else zeros[z++] = arr[i];
    }
}

 
int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    int arr[] = {3, -1, 4, 0, -2, 5, -7, 0, 8, -9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *positives, *negatives, *zeros;
    int posSize, negSize, zeroSize;
    
    separateElements(arr, size, positives, posSize, negatives, negSize, zeros, zeroSize);
    
    cout << "Додатні: "; printArray(positives, posSize);
    cout << "Від'ємні: "; printArray(negatives, negSize);
    cout << "Нулі: "; printArray(zeros, zeroSize);
    
    deleteArray(positives);
    deleteArray(negatives);
    deleteArray(zeros);
    
    return 0; 
}
