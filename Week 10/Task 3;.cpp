#include <iostream>
using namespace std;


int findMax(int arr[], int size) {
  
    if (size == 1) {
        return arr[0];
    }

    
    int subMax = findMax(arr + 1, size - 1);

    
    if (arr[0] > subMax) {
        return arr[0];
    }
    else {
        return subMax;
    }
}

int main() {
    int numbers[] = { 12, 45, 2, 67, 34, 89, 21 };
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int maxValue = findMax(numbers, n);

    cout << "The maximum element in the array is: " << maxValue << std::endl;

    return 0;
}