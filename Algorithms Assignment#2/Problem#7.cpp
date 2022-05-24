/*
Binary Huffman code, 
or binary prefix code is a function f, that maps each letter that appears in the string to some
binary string (that is, string consisting of characters '0' and '1' only) such that for each pair of
different characters ai and aj string f(ai) is not a prefix of f(aj) (and vice versa). The result of the
encoding of the message a1, a2, ..., an is the concatenation of the encoding of each character, that
is the string f(a1)f(a2)... f(an). Huffman codes are very useful, as the compressed message can be
easily and uniquely decompressed, if the function f is given. Code is usually chosen in order to
minimize the total length of the compressed message, i.e. the length of the string f(a1)f(a2)... f(an).

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
struct Sub
{
    int li, ri, id;
} c[N];
int k, n, m, S, L = 1, R;
int a[N], b[N];
int cnt[N], s[N], sum[N];
bool v[N];
ll minLength[N];
vector<int> g;
inline bool Compressed(Sub x, Sub y)
{
    return b[x.li] < b[y.li] || (b[x.li] == b[y.li] && x.ri < y.ri);
}
inline void Update(int x, int y)
{
    sum[cnt[x]]--;
    cnt[x] += y;
    sum[cnt[x]]++;
}
inline ll minComp()
{
    ll minLength = 0;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < g.size(); i++)
        if (cnt[g[i]] > S)
            Q.push(cnt[g[i]]);
    int lst = 0;
    for (int i = 1; i <= S; i++)
        s[i] = sum[i];
    for (int i = 1; i <= S; i++)
        if (s[i])
        {
            if (lst)
            {
                minLength += i + lst;
                if (i + lst <= S)
                    s[i + lst]++;
                else
                    Q.push(i + lst);
                s[i]--;
                lst = 0;
            }
            if (s[i] & 1)
                lst = i;
            minLength += 1ll * (s[i] >> 1) * (i << 1);
            if ((i << 1) <= S)
                s[i << 1] += s[i] >> 1;
            else
                for (int j = 1; j <= (s[i] >> 1); j++)
                    Q.push(i << 1);
        }
    if (lst)
        Q.push(lst);
    while (Q.size() > 1)
    {
        int x = Q.top();
        Q.pop();
        x += Q.top();
        Q.pop();
        minLength += x;
        Q.push(x);
    }
    return minLength;
}
int main()
{
    scanf("%d", &n); //the length of the initial message

    for (int i = 1; i <= n; i++) // characters of the message
        scanf("%d", &a[i]), cnt[a[i]]++;

    scanf("%d", &m); // the number of queries

    for (int i = 1; i <= m; i++) //q lines: contains two integers li and ri (the position of the left and right ends of the i-th substring respectively)
        scanf("%d%d", &c[i].li, &c[i].ri), c[i].id = i;

    S = sqrt(n);
    for (int i = 1; i <= n; i++)
        if (cnt[a[i]] > S && !v[a[i]])
            g.push_back(a[i]), v[a[i]] = 1;

    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        b[i] = (i - 1) / S + 1;

    sort(c + 1, c + m + 1, Compressed);
    for (int i = 1; i <= m; i++)
    {
        while (R < c[i].ri)
            Update(a[++R], 1);
        while (R > c[i].ri)
            Update(a[R--], -1);
        while (L > c[i].li)
            Update(a[--L], 1);
        while (L < c[i].li)
            Update(a[L++], -1);
        minLength[c[i].id] = minComp();
    }

    // Print q lines. Each line should contain a single integer (the minimum possible length of the Huffman encoding of the substring ali... ari)
    for (int i = 1; i <= m; i++)
        printf("%I64d\n", minLength[i]);

return 0;
}