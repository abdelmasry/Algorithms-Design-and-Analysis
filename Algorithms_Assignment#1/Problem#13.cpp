#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7fffffffffffffff
using namespace std;
int n;
int pos[15][15];
int left_pare[15], right_pare[15];
long long matrix_a[15], matrix_b[15];
long long dp[15][15];
void dfs(int x, int y)
{
     if (x == y)
          return;
     left_pare[x]++;
     right_pare[y]++;
     if (x == y - 1)
          return;
     dfs(x, pos[x][y]);
     dfs(pos[x][y] + 1, y);
}
int main() // enter the number of matrices first then the rows & columns of each
{
     int kase = 0;
     while (scanf("%d", &n) == 1 && n)
     {
          for (int i = 1; i <= n; i++)
               scanf("%lld %lld", &matrix_a[i], &matrix_b[i]);
          kase++;
          memset(dp, 0, sizeof(dp));
          memset(pos, -1, sizeof(pos));
          for (int i = 1; i < n; i++)
               dp[i][i + 1] = matrix_a[i] * matrix_a[i + 1] * matrix_b[i + 1];
          for (int j = 2; j < n; j++)
               for (int i = 1; i <= n - j; i++)
               {
                    long long Min = INF;
                    for (int k = 0; k < j; k++)
                    {
                         long long temp = dp[i][i + k] + dp[i + k + 1][i + j] + matrix_a[i] * matrix_b[i + k] * matrix_b[i + j];
                         if (temp < Min)
                         {
                              Min = temp;
                              pos[i][i + j] = i + k;
                         }
                    }
                    dp[i][i + j] = Min;
               }
          memset(left_pare, 0, sizeof(left_pare));
          memset(right_pare, 0, sizeof(right_pare));
          dfs(1, n);
          printf("Case %d: ", kase);
          for (int i = 1; i <= n; i++)
          {
               for (int j = 1; j <= left_pare[i]; j++)
                    putchar('(');
               printf("A%d", i);
               for (int j = 1; j <= right_pare[i]; j++)
                    putchar(')');
               if (i != n)
                    printf(" x ");
          }
          printf("\n");
     }
     return 0;
}