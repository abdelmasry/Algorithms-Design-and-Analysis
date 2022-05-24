#include <bits/stdc++.h>
using namespace std;
struct point
{
    int first;
    int second ;
    int idx;
};

bool compX(point  p1, point p2)
{
    return p1.first < p2.first;;
}
bool compY(point  p1, point p2)
{
    return p1.second < p2.second;;
}

double dist(point p1, point p2)
{
    return sqrt( (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

float getMin(vector<point>::iterator start, int &p1,int &p2,int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(*(start+i), *(start+j)) < min)
            {
                min = dist(*(start+i), *(start+j));

                p1 =(start+i)->idx;
                p2 = (start+j)->idx;
            }

    return min;
}

int main(){

return 0;
}