/*
There are n smtp servers connected by network cables. Each of the m cables connects two
computers and has a certain latency measured in milliseconds required to send an email
message. What is the shortest time required to send a message from server to server along a
sequence of cables.
Input
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a
line containing n (number of servers), m (number of route), S (source) and T(destination). S != T.
The next m lines (routes) will each contain 3 integers: 2 different servers (in the range [0, n-1])
that are connected by a bidirectional cable and the latency (w)
Output
For each test case, output the line Case #x:, followed by the number of milliseconds required to
send a message from S to T. Print (unreachable), if there is no route from S to T
*/

#include <iostream>
using namespace std;

int main()
{
    int cases = 0;
    cout << "Enter number of cases:" << endl;
    cin >> cases;
    int n, m, S, T, S1, S2, W;
    for (int i = 0; i < cases; i++)
    {
        cin >> n >> m >> S >> T;
        if (m == 0)
            cout << "CASE#" << i + 1 << "--> unreachable " << endl;
            continue;
        if (S == T)
            cout<< "The Source and Destination can't be the same!!!"<<endl;    
        else
        {
            int network[n - 1][n - 1];
            for (int j = 0; j < m; j++)
            {
                cin >> S1 >> S2 >> W;
                network[S1][S1] = 0;
                network[S1][S2] = W;
                network[S2][S1] = W;
                network[S2][S2] = 0;
            }
            bool connected = false;
            if (S > T)
            {
                for (int g = S; g > T; g--)
                {
                    if (network[g][g - 1] > 0)
                    {
                        connected = true;
                    }
                }
            }
            else 
            {
                for (int g = S; g < T; g++)
                {
                    if (network[g][g + 1] > 0)
                    {
                        connected = true;
                    }
                }
            }
            if (connected)
            {
                int direct_route = 0;
                if (network[S][T] > 0)
                {
                    int direct_route = network[S][T];
                }
                int indirect_route = 0;
                if (S > T)
                    for (int y = S; y > T; y--)
                        indirect_route += network[y][y - 1];
                        
                else if (T > S)
                    for (int j = S; j < T; j++)
                        indirect_route += network[j][j + 1];

                if (direct_route > 0)
                {
                    cout << "CASE#" << i + 1 << "---> Minimum Latency: " << min(indirect_route, direct_route) << endl;
                }
                else
                    cout << "CASE#" << i + 1 << "---> Minimum Latency: " << indirect_route << endl;
            }
            else
                cout << "CASE#" << i + 1 << "--> unreachable " << endl;
        }
    }

    return 0;
}