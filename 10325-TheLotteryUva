// Auther : asmaa saeed date: 2020-07-07 
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

ll n;int m;
vector<int>v;
ll gcd(ll a, ll b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
ll fnc(int index=0,int sign=-1,ll Lcm=1){
    if(index==m){
        if(Lcm==1)return 0;
        return (sign*n)/Lcm;
    }
    ll x=(Lcm*v[index])/(gcd(v[index],Lcm));
    return fnc(index+1,sign,Lcm) +fnc(index+1,sign*-1,x); 
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>m)
    {
        v.clear();
        loop(i,0,m){
            int a;cin>>a;
            v.pb(a);
        }
        ll ans=fnc();
        cout<<n-ans<<endl;
    }
    
    return 0;
}