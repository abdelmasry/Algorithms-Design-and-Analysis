//1. Insert data to the list
//2. Remove data from the list 
//3. Print an index(1 - based) from a specified data after the list was sorted ascendingly
//4. Print data from a specified index(1 - based) after the list was sorted ascendingly
//We want to make insertion, deletion, getting operations in O(log2(n))

/*Input contains several lines. Each line follows one of these formats.
1 n: Insert n (0 <= n <= 231 - 1) to the list
2 n: Remove n from the list. If n was not found, do nothing
3 n: Print n's index (1-based) after the list was sorted ascendingly
4 i: Print data on i-th index (1-based) after the list was sorted ascendingly (0 <= i <= 231 - 1)
-1: End of input */
#include <iostream>
using namespace std;

class Query
{
private:
    int size = 1, *list; 

public:
    Query()
    {
        list = new int[size];
        list[0] = 0; // 1-based indexing
    }

    void insert(int Q)
    {
        size++;
        list[size - 1] = Q;
        int j;
        // using insertion sort
        for (int i = 1; i < size; i++)
        {
            Q = list[i];
            j = i - 1;

            while (j >= 0 && list[j] > Q)
            {
                list[j + 1] = list[j];
                j = j - 1;
            }
            list[j + 1] = Q;
        }
    }
    void remove(int N)
    {
        int i;
        for (i = 0; i < size; i++)
            if (list[i] == N)
                break;

        if (i < size)
        {
            size = size - 1;
            for (int j = i; j < size; j++)
                list[j] = list[j + 1];
        }
    }

    int search(int K) //binary search
    {
        int mid, first = 0, last = size;
        while (first <= last)
        {
            mid = (first + last) / 2;
            if (list[mid] == K)
                return mid;
            else if (list[mid] < K)
                first = mid + 1;
            else
                last = mid - 1;
        }
        return -1;
    }

    void print(int index)
    {   if (list[index] == 0)
            cout << "Data Output: " << -1 << endl;
        else 
            cout << "Data Output: " << list[index] << endl;
    }

};

int main()
{
    Query query;
    bool Querying = true;

    while (Querying)
    {
        int type, input;
        cin>>type;
        if (type != -1) cin>>input;
        
        switch (type)
        {
        case 1: query.insert(input);
            break;
        case 2: query.remove(input);
            break;
        case 3: cout << "Search output: " << query.search(input) << endl;
            break;
        case 4: query.print(input);
            break;
        case -1: Querying = false;
            break;
        default: cout << "Query not supported" << endl;
            break;
        }
    }

return 0;
}