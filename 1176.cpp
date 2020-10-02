// Auther : asmaa saeed date: 2020-09-26 
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

int t,n;ll a;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--)
    {
        cin>>n;
        int cnt[3],ans=0;
        clr(cnt,0);
        loop(i,0,n){
           cin>>a;
           if(a%3==0)ans++;
           else{
               cnt[a%3]++;
           } 
        }
        int q=min(cnt[1],cnt[2]);
        ans+=q;
        cnt[1]-=q;cnt[2]-=q;
        ans+=(cnt[1]/3);
        ans+=(cnt[2]/3);
        cout<<ans<<endl;

    }
    
    
    return 0;
}