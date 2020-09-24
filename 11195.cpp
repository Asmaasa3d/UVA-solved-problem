// Auther : asmaa saeed date: 2020-09-23
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

int n, cnt;bool queenCol[20] ,dig1[45],dig2[45];
char grid [20][20];
bool valid(int r, int c)
{
   
    if (queenCol[c] || dig1[r+c] ||dig2[c-r+n] ||grid[r][c]=='*')
            return false;
  
    return true;
}

void solve(int r)
{
    if (r == n)
    {
        cnt++;
    }
    else
    {
        loop(c, 0, n)
        {
            if (!valid(r,c))
                continue;
            queenCol[c] =dig1[r+c]=dig2[c-r+n]=1 ;
            solve(r + 1);
            queenCol[c] =dig1[r+c]=dig2[c-r+n]=0 ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
int tc=1;
    while (cin >> n ,n)
    {
        loop(i, 0, n)
        {
           loop(j,0,n)
           cin>>grid[i][j];
        }

        cnt = 0;
        clr(queenCol, 0);
        clr(dig1, 0);
        clr(dig2, 0);
        solve(0);
        cout<<"Case "<<tc<<": ";
        cout << cnt << "\n";
        tc++; 
    }

    return 0;
}