#include<iostream>
using namespace std;

long long m_z, m_w;
int get_random()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 1000000000;
}

int Partition(int a[], int beg, int end)
{
    int p = beg, pivot = a[beg], loc;

    for (loc = beg + 1; loc <= end; loc++)
    {
        if (pivot > a[loc])
        {
            a[p] = a[loc];
            a[loc] = a[p + 1];
            a[p + 1] = pivot;

            p = p + 1;
        }
    }
    return p;
}

void QuickSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int p = Partition(a, beg, end);
        QuickSort(a, beg, p - 1);
        QuickSort(a, p + 1, end);
    }
}    

int main()
{
    int m_w_1 = 100, m_w_2 = 75;
    int m_z_1 = 100, m_z_2 = 94;
    int N_1 = 100000, N_2 = 1000000;
    int test_1[N_1], test_2[N_2];

        // Generating array elements
        for (int i = 0; i < N_1; i++)
        {
            test_1[i] = get_random();
        }
        for (int i = 0; i < N_2; i++)
        {
            test_2[i] = get_random();
        }
            // Sorting Array 
            QuickSort(test_1, 0, N_1);
            QuickSort(test_2, 0, N_2);

            // Taking the index to search for...
            int K = 0;
            cin >> K;

            // Output the Kth element in the array
            cout << test_1[K] << endl;

            // Taking the index to search for...
            K = 0;
            cin >> K;

            // Output the Kth element in the array
            cout << test_2[K] << endl;
return 0;
}