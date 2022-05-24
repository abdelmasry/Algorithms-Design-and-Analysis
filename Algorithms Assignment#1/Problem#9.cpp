#include <iostream>
using namespace std;

class Query
{
   private:
            int size=1, *list;
   
   public:
            Query()
            {
                list = new int[size];
                list[0] = 0; // 1-based indexing
            }

            void insert(int Q)
            {
                    size++;
                    list[size-1] = Q;
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

};

int main()
{
    Query query;
    int queries;
    cout<<"Enter number of queries:"<<endl;
    cin>>queries;

    int lines = 0;
    while (lines < queries)
    {
        int query_type, argument;
        cin>>query_type>>argument;
        switch (query_type)
        {
        case 1:
            query.insert(argument);
            break;
        case 2:
            cout<<"SEARCH OUTPUT: "<<query.search(argument)<<endl;
            break;
        default:
            cout<<"No Such Query"<<endl;
            break;
        }
        lines++;
    }
    
return 0;    
}