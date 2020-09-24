// Auther : asmaa saeed date: 2020-09-09 
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

int n,d[15],path[15][15];

ll db[15][15];
ll solve(int st,int en){
    if(st==en )return 0;
    ll &ret=db[st][en];
    if(ret!=-1)return ret;
  ll best=1000000;
    loop(i,st,en){
        ll z=d[st-1]*d[i]*d[en];

        best=solve(st,i)+solve(i+1,en)+z;
        if(ret==-1||best<ret){
            ret=best;
            path[st][en]=i;
        }

    }
    return ret;
}
void print_path(int i,int j){
    if(i==j)cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_path(i,path[i][j]);
        cout<<" x ";
        print_path(path[i][j]+1,j);
        cout<<")";
    }
    

}
int main () {
  int caseno=1;
    while (cin>>n)
    {
        if(n==0)break;
    
        loop(i,0,n){cin>>d[i]>>d[i+1];
        }
        clr(db,-1);
        solve(1,n);
        cout<<"Case "<<caseno<<": ";
        print_path(1,n);
        caseno++;
        cout<<"\n";
    }
    
    return 0;
}