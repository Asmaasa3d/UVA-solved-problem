// Auther : asmaa saeed date: 2020-09-09
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

ll t, dp[65][65];
string s;
ll solve(int i ,int j){
    if(i==j)return 1;
    if(i+1==j)return 2+(s[i]==s[j]);
    ll &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(s[i]==s[j])ret+=solve(i+1,j-1)+1;
    ret+=solve(i,j-1);
    ret+=solve(i+1,j);
    ret-=solve(i+1,j-1);
    return ret;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    loop(i, 0, t)
    {
        cin >> s;
        clr(dp, -1);
        cout<<solve(0,s.size()-1)<<endl;
    }
    return 0;
}