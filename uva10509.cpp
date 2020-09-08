// Auther : asmaa saeed date: 2020-08-20 
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


double n;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
while(cin>>n)
   { 
       if(n==0)break;
    double a=floor(cbrt(n));
    double dx=(n- (a*a*a))/(3*a*a);
    double ans=a+dx;
    cout<<fixed<<setprecision(4)<<  ans<<endl;}
    return 0;
}