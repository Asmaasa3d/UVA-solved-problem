// Auther : asmaa saeed date: 2020-07-28
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (ll v = st; v < en; v++)
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

ll a, b, n;
ll calc(ll x)
{
    a = a % n;
    x = x % n;
    x = (x * x) % n;
    b = b % n;
    ll q = (a * x) % n;
    q += b;
    return q % n;
}
map<ll, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n)
    {
        if (n == 0)
            break;
        m.clear();
      
        ll cnt = n;
        cin >> a >> b;
        ll i = 0,q=0;

        while (true)
        {
             q = calc(q);
          
            m[q]++;
            if (m[q] == 2)
            {
                cnt--;
                
              
            }
            if (m[q] == 3)
                break;
        
        }
        cout << cnt << endl;
    }

    return 0;
}