// Auther : asmaa saeed date: 2020-09-29 
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

#define eps 1e-9

double p,q,r,s,t,u;
double valid(double x){
    return(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x) +t*x*x+u);
}
double BS(){
    double st=0,en=1.0;
    int cnt=200;
    while (cnt-- && en-st>eps)
    {
        double mid=(en+st)/2;
       //cout<<st<<" "<<en<<" "<<mid<<" "<<valid(mid)<<endl;
        if(valid(mid)>0.0)
           st=mid;
        else 
         en=mid;

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

    while (cin>>p)
    {
       cin>>q>>r>>s>>t>>u;
      if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9 || p+r+u<0)
            cout<<"No solution\n";
       else
       cout<<fixed<<setprecision(4)<<BS()<<endl;
      
    }
    
    return 0;
}