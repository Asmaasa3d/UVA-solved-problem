// Auther : asmaa saeed date: 2020-07-01 
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

int n,m,t;

struct edge {
int from, to, w;
edge(int from, int to, int w): from(from), to(to), w(w) {}
bool operator < (const edge & e) const {
return w > e.w;
}
};
struct DisjSet{
vi parent , rank ;
int numOftrees ;
DisjSet(int n ){
numOftrees=n;
parent = vi(n+1), rank = vi(n+1,1);
loop(i,0,n+1)parent[i]=i ;
}
int findSetParent(int i ){
if(parent[i]==i)return i ;
return parent[i]=findSetParent(parent[i]);
}
void Union (int x , int y){
x=findSetParent(x);y=findSetParent(y);
if(x==y)return;
if(rank[x]<rank[y])parent[x]=y;
else if(rank[y]<rank[x])parent[y]=x;
else {
parent[x]=y;
rank[y]++;
}
numOftrees--;
}
bool connected(int x,int y){
x=findSetParent(x);y=findSetParent(y);
if(x==y) return true;
return false;
}
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    ofstream q;
    q.open("q.txt");
    loop(i,0,t){
        cin>>m>>n;
        int cnt=0;vector<edge>v;DisjSet s=DisjSet(m);
        map<string,int>mp;
        loop(i,0,n){
            string s1,s2;int a;
            cin>>s1>>s2>>a;
            if ( mp.find(s1) == mp.end() ){
                cnt++; mp[s1]=cnt;
            }
            if ( mp.find(s2) ==mp.end() ){
                cnt++; mp[s2]=cnt;
            }
            edge e(mp[s1],mp[s2],a);
            v.pb(e);
        }
        ll ans=0;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        loop(i,0,n){ 
            if(!s.connected(v[i].from,v[i].to)){
               
                s.Union(v[i].from,v[i].to);
                ans+=v[i].w;
            }
            if(s.numOftrees==1)break;
        }
cout<<ans<<endl;
if(i!=t-1){cout<<endl;}
    }

    return 0;
}