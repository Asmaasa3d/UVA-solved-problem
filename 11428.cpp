// Auther : asmaa saeed date: 2020-09-28
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

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (cin >> n && n)
    {
        int a = cbrt(n);
        if (a * a * a < n)
        {
            a++;
        }
        
        bool tst = false;
        loop(i, a, n + 1)
        {
            for(int j=i-1;j>0;j--){
                if(((i*i*i)-n)==(j*j*j)){
                    cout<<i<<" "<<j<<"\n";
                    tst=true;
                    i=n+1;
                    break;
                }
               
            }
        }
        if (!tst)
            cout << "No solution\n";
    }

    return 0;
}