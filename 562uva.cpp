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

int n, m, arr[105], sum,mem[103][500003];

int sol(int i,int r )
{
    if (i == m)
        return abs(2*r-sum);
    int &val=mem[i][r];
    if(val!=-1)return val;
    int ch1 = sol(i + 1,r+arr[i]);
    int ch2 = sol(i + 1,r);

    return val=min(ch1, ch2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--)
    {
        sum = 0;
        cin >> m;
        loop(i, 0, m)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        loop(i,0,m){
            loop(j,0,sum+10)
            mem[i][j]=-1;
        }
        cout << sol(0,0) << endl;
    }

    return 0;
}