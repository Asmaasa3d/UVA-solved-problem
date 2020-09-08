// Auther : asmaa saeed date: 2020-08-25
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
string m, f;
int Case = 1;
int mem[102][105];
int sol(int i, int j)
{
    if (i == m.size() || j == f.size())
    {
        return 0;
    }
    int &val = mem[i][j];
    if (val != -1)
        return val;
    if (m[i] == f[j])
        return 1 + sol(i + 1, j + 1);
    int ch1 = sol(i + 1, j);
    int ch2 = sol(i, j + 1);
    return val = max(ch1, ch2);
}
int main()
{

    while (getline(cin, m))
    {
        if (m == "#")
            break;
        getline(cin, f);
         loop(i, 0, m.size())
    {
        loop(j, 0, f.size())
        {
            mem[i][j] = -1;
        }
    }

        cout << "Case #" << Case;
        cout << ": you can visit at most " << sol(0, 0) << " cities.\n";
        Case++;
    }
   
    return 0;
}