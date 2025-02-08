#include <iostream> 
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

void appendElement(int* &arr, int &size, int value) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}

void insertElement(int* &arr, int &size, int index, int value) {
    if (index < 0 || index > size) return;
    int* newArr = new int[size + 1];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == index) newArr[i] = value;
        else newArr[i] = arr[j++];
    }
    delete[] arr;
    arr = newArr;
    size++;
}

void removeElement(int* &arr, int &size, int index) {
    if (index < 0 || index >= size) return;
    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) newArr[j++] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

int main() { 
    int size = 5;
    int* arr = allocateArray(size);
    initializeArray(arr, size);
    printArray(arr, size);

    appendElement(arr, size, 10);
    printArray(arr, size);

    insertElement(arr, size, 2, 20);
    printArray(arr, size);

    removeElement(arr, size, 3);
    printArray(arr, size);

    deleteArray(arr);
    
    return 0; 
}
