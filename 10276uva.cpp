// Auther : asmaa saeed date: 2020-06-27 
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

int t,n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>t;
    while (t--)
    {
        cin>>n;
        int ans=(n*n)/2;
        if(n%2==0)ans+=(n-1);
        else ans += n;
        cout<<ans;
        cout<<endl;
    }
    
    return 0;
}