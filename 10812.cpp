
// Auther : asmaa saeed date: 2020-07-25
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

int n, s, d, x, y;

int main()
{

    cin >> n;
    while (n--)
    {
        cin >> s >> d;
        if (d > s || ((s+d)%2 !=0))
            cout << "impossible\n";
        else
        {
            x = (s + d) / 2;
            y = s - x;
            cout<<x<< " "<<y;
            if(n>0)cout<<endl;
        }
    }

    return 0;
}