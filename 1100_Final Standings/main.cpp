// Auther : asmaa saeed date: 2020-05-04 
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

int n;
struct team
{
    ll ID;int M;
};
vector<team>v;
bool compareteam(team i1, team i2) 
{ 
    return (i1.M > i2.M); 
} 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    team a;
    loop(i,0,n){
        cin>>a.ID>>a.M;
        v.pb(a);
    }
    stable_sort(v.begin(),v.end(),compareteam);
    loop(i,0,n)cout<<v[i].ID<<" "<<v[i].M<<endl;
    return 0;
}