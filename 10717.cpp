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

int n ,t;
vector<int>coins,tbls;
unordered_set<ll>thick_Lcm;
void fnc(ll d=1,int index=0,int cnt=0){
      int b0, b1, b2;
        loop(i, 0, n)
        {
            loop(j, i + 1, n)
            {
                b0 = coins[i] * coins[j] / __gcd(coins[i], coins[j]);
                loop(z, j + 1, n)
                {
                    b1 = b0 * coins[z] / __gcd(coins[z], b0);
                    loop(k, z + 1, n)
                    {
                        b2 = b1 * coins[k] / __gcd(coins[k], b1);
                        thick_Lcm.insert(b2);
                    }
                }
            }
        }
}
ostream &operator<<(ostream &oov,const vector<ll> &a)
{
loop(i, 0, a.size())
{
oov << a[i] <<" " ;
}
return oov;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>t)
    {
        coins.clear();
        tbls.clear();
       if(n==0 && t==0)break;
        loop(i,0,n){
            ll a;cin>>a;
            coins.pb(a);
        }
         loop(i,0,t){
            ll a;cin>>a;
            tbls.pb(a);
        }
        thick_Lcm.clear();
        fnc();
       
        loop(i,0,t){
            ll mn=0,mx=1e18;
            for(auto j:thick_Lcm){
                ll x=tbls[i]/j;
                ll z=tbls[i]%j;
                
                ll q=x*j;
                ll p; (z==0)?p=x*j: p=(x+1) *j;
               
                if(q>mn)mn=q;
                if(p<mx)mx=p;

            }
            cout<<mn<<" "<<mx<<endl;
        }

    }
    
    return 0;
}