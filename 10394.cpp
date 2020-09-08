// Auther : asmaa saeed date: 2020-07-06 
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x  <<" = { "<< x<<" }\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int s;
vector<pll>v;
int countPrimesInRange_sieve(int n)	// Backward thinking
{
    v=vector<pll>(1000005);
	vector<bool> isPrime((n+1), true);	// set all of them to primes
	isPrime[0] = isPrime[1] = 0;		// 0, 1 are not primes
    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (ll j = i * 2; j <= n; j += i)
            	isPrime[j] = 0;
        }
    }

    ll cnt = 0;

    for (ll i = 0; i < (ll)isPrime.size(); ++i)
     if((i+2) < isPrime.size())
    {	if(isPrime[i]&&isPrime[i+2])
    		{cnt++;
            v[cnt].first=i;
            v[cnt].second=i+2;
            }
}
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    countPrimesInRange_sieve(20000000);
   
    while (cin>>s)
    {
      cout<<"("<<v[s].first<<", "<<v[s].second<<")"<<endl;
    }
    
    return 0;
}