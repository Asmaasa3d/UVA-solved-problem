// Auther : asmaa saeed date: 2020-09-23 
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

int n,h;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    loop(a,0,t)
    {
        cin>>n>>h;
        string s;
        loop(i,0,n-h)s+='0';
        loop(i,0,h)s+='1';
        do{
            cout<<s<<"\n";

        }while(next_permutation(s.begin(),s.end()));
        if(a!=t-1)
        cout<<"\n";
    }
    
    return 0;
}