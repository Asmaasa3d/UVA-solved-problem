// Auther : asmaa saeed date: 2020-07-06
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
vector<bool> isPrime((10000000 + 1), true);
void PrimesInRange_sieve(int n) // Backward thinking
{

    // set all of them to primes
    isPrime[0] = isPrime[1] = 0; // 0, 1 are not primes
    for (ll i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (ll j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ofstream q;q.open("q.txt");
   
    PrimesInRange_sieve(10000000);
    while (cin >> n)
    {
        
        
        if (n < 8)
        {
            cout << "Impossible.\n";
           // q<< "Impossible.\n";
        }
        else
        {
            ll x;
           if(n&1) {
               x=n-5;
               cout<<2<<" "<<3<<" ";
           }
           else{
                x=n-4;
               cout<<2<<" "<<2<<" ";
           }
            for (ll i = 2; i <= x / 2; i++)
            {
                if (isPrime[i] && isPrime[x - i])
                {
                    cout << i << " " << x - i<<endl;;
                   // q<< 2 << " " << 2 << " " << i << " " << x - i<<endl;;
                    break;
                }
            }
        }
    }

    return 0;
}