// Auther : Asmaa Saad  date: 2020-03-25 
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
vii lst;

struct edge {
int from, to;double w;
edge(int from, int to): from(from), to(to){
         double dx =lst[from].first - lst[to].first ;double dy =lst[from].second- lst[to].second;
       w =(dx*dx)+(dy*dy);
        w = sqrt(w);
   }
bool operator < (const edge & e) const {
return w > e.w;
}
};
priority_queue<edge>q;
void clear( priority_queue<edge> &q )
{
  priority_queue<edge> empty;
   swap( q, empty );
}
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
return false;
}
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
int t,n,m;

void MST_KRUSKAL(DisjSet S){
    while(!q.empty()){
        edge e=q.top(); q.pop();
        if(S.Union(e.to ,e.from)){
            cout<<e.to<<" "<<e.from<<endl;
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  cin>>t;
  
  while (t--)
  {
     cin>>n;
     DisjSet s=DisjSet(n);lst.clear();
     clear(q);
     int x,y;
     lst.pb(MP(0,0));
     loop(i,1,n+1){
         cin>>x>>y;
         lst.pb(MP(x,y));

     }
    cin>>m;
    
    loop(i,0,m){
        cin>>x>>y;
        s.Union(x,y);
    }
loop(i,1,n+1){
    loop(j,i+1,n+1){
        if(i!=j)
        {if(!s.check_connection(i,j)){
            edge e(i,j);
            q.push(e);
        }}
    }
}
if(q.empty())cout<<"No new highways need\n";
MST_KRUSKAL(s);
if(t!=0)
        cout<<"\n";
  }
  
    return 0;
}