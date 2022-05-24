#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid,int right);

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        }
        else 
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int main()
{
    // Testing..
    int test1[5] = {2, 4, 1, 3,5};
    int test2[2] = {2, 1};
    int test3[5] = {5, 4, 3, 2, 1};

    // Analyzing inversions..
    int n_1 = sizeof(test1) / sizeof(test1[0]);
    int ans_1 = mergeSort(test1, n_1);
    cout << " Number of inversions are: " << ans_1 << endl;

    int n_2 = sizeof(test2) / sizeof(test2[0]);
    int ans_2 = mergeSort(test2, n_2);
    cout << " Number of inversions are: " << ans_2  << endl;

    int n_3 = sizeof(test3) / sizeof(test3[0]);
    int ans_3 = mergeSort(test3, n_3);
    cout << " Number of inversions are: " << ans_3 << endl;

    return 0;   
}
