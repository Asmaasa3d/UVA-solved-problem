// Auther : Asmaa Saad  date: 2020-03-26 
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x  << x<<endl ;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,m;
struct edge {
int from, to, w;
edge(int from, int to, int w): from(from), to(to), w(w) {}
bool operator < (const edge & e) const {
return w > e.w;
}
bool operator== (const edge &e) const {
return (e.from == from && e.to == to && e.w ==w) ;
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
bool check_connection(int x,int y){
x=findSetParent(x);y=findSetParent(y);
if(x==y) return true;
return false;}
bool Union (int x , int y){
x=findSetParent(x);y=findSetParent(y);
if(x==y)return false;
if(rank[x]<rank[y])parent[x]=y;
else if(rank[y]<rank[x])parent[y]=x;
else {
parent[x]=y;
rank[y]++;
}
numOftrees--;
return x!=y;
}
};
void clear( priority_queue<edge> &q )
{
 priority_queue<edge> empty;
 swap( q, empty );
}

 vector<edge>edges;
edge x=edge(INF,INF,INF);
pair<int,vector<edge> > MST_Kruskal(){
    DisjSet s=DisjSet(n); int cost=0;
    vector<edge>v;priority_queue<edge>q;
    loop(i,0,m)q.push(edges[i]);
    while (!q.empty())
    {
        edge e=q.top(); q.pop();
        if(x == e) {
            continue;}
        else
        {if(s.Union(e.from,e.to)){
            cost+=e.w;
            v.push_back(e);
        }}
    }
   if(v.size()!=n-1) return MP(INF,vector<edge>()); 
   return MP(cost,v);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
   
    while (t--)
    {
        cin>>n>>m;
        edges.clear();
        loop(i,0,m){
            int A,B,C;
            cin>>A>>B>>C;
            edge e=edge(A,B,C);
            edges.pb(e);
        }
    pair<int,vector<edge> > p;
    int smst=INF;
    p=MST_Kruskal();
    loop(i,0,p.second. size()){
        x=p.second[i];
        pair<int,vector<edge> > t;
        t=MST_Kruskal();
        if(t.first<smst){
            smst=t.first;
        }
    }
    cout<<p.first<<" "<<smst<<endl;
    }
    return 0;
}