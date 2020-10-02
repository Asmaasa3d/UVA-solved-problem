// Auther : asmaa saeed date: 2020-09-28 
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

ll S,D,q;
bool valid(ll n){
   ll a,b;
   if((n%2)==0){
       a=n;
       b=n+1;
   }
   else
   {
       a=n+1;b=n;
   }
   
   ll z=(D+q)/b;
   if(((D+q)%b)!=0)z++;
    return (a/(1ll*2))>=z;
}
ll Solve(){
    ll st=S,en=1e15;
    while (st<en)
    {
        ll mid=st+(en-st)/2;
       // cout<<mid<<" "<<valid(mid)<<endl;
        if(valid(mid)){
            en=mid;
        }
        else
        {
            st=mid+1;
        }
        
    }
   return st; 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt","rt",stdin);
freopen("output.txt","wt",stdout);
#endif
while (cin>>S>>D)
{ 
    ll a=max(S-1,1ll);

    q=(S*a)/(1ll*2);
   //cout<<q<<endl;
   //cout<<valid(3);
   cout<<Solve()<<endl;
 

}

    
    return 0;
}