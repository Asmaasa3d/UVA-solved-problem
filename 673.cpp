// Auther : asmaa saeed date: 2020-09-25
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

int n, m, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    int l = 1, r = n;
    loop(i, 0, m)
    {

        cin >> a >> b;
        if (a > b)
            swap(a, b);
        l=max(l,a);
        r=min(r,b);
    }
    cout<<max(0,r-l);
    return 0;
}