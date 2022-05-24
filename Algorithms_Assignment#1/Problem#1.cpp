#include <iostream>
using namespace std;

bool insert(int array[], int rightIndex, int value) {
    int j;  bool swaps =false;
    for( j = rightIndex; j >= 0 && array[j] > value; j--) {
        array[j + 1] = array[j];
        swaps = true;
    }
    array[j + 1] = value;
    return swaps;
}

void inSort(int array[], int n){
    int swaps = 0;
    for (int i = 1; i < n; i++){
        if (insert(array, i-1, array[i])) {
            swaps++;
        }
    }
    cout<<swaps<<endl;
}

int main(){

    int a[] = {1, 1, 1, 2, 2};
    int b[] = {2, 1, 3, 1, 2};
    int c[] = {3,9, 1, 5, 2, 6, 8};

    inSort(a, 5);
    inSort(b, 5);
    inSort(c, 7);

    return 0;
}
