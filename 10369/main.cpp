// Auther : Asmaa Saad  date: 2020-04-05
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << x << endl;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int x,y;
};
vector<point>v;
struct edge {
int from, to;double w;
edge(int from, int to): from(from), to(to){
         double dx =v[from].x - v[to].x ;double dy =v[from].y- v[to].y;
       w =(dx*dx)+(dy*dy);
        w = sqrt(w);
   }
bool operator < (const edge & e) const {
return w > e.w;
}
};
struct DisjSet
{
    vi parent, rank;
    int numOftrees;
    DisjSet(int n)
    {
        numOftrees = n;
        parent = vi(n + 1), rank = vi(n + 1, 1);
        loop(i, 0, n + 1) parent[i] = i;
    }
    int findSetParent(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = findSetParent(parent[i]);
    }
    bool check_connection(int x, int y)
    {
        x = findSetParent(x);
        y = findSetParent(y);
        if (x == y)
            return true;
        return false;
    }
    bool Union(int x, int y)
    {
        x = findSetParent(x);
        y = findSetParent(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[y] < rank[x])
            parent[y] = x;
        else
        {
            parent[x] = y;
            rank[y]++;
        }
        numOftrees--;
        return x != y;
    }
};
double MST(vector<edge>f,int n,int p){
    priority_queue<edge>q;
    loop(i,0,f.size()) q.push(f[i]);
    DisjSet s=DisjSet(n);
    vector<edge> a;
    double maxed=0;
    while (!q.empty())
    {
        if(s.numOftrees==p)break;
        edge e=q.top();q.pop();
        if(s.Union(e.from,e.to)){
            if(e.w>maxed)maxed=e.w;
            a.push_back(e);
        }
        

    }
    
    return maxed;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s,p,x,y;
    cin>>n;
    while (n--)
    {
        cin>>s>>p;
        vector<edge> r;
        v.clear();
        loop(i,0,p){
            cin>>x>>y;
            point a;a.x=x;a.y=y;
            v.pb(a);
        }
        loop(i,0,p){
            loop(j,i+1,p)
            {
                edge e(i,j);
                r.push_back(e);

            }
        }
        double Z=MST(r,p,s);
     
        cout<<fixed<<setprecision(2)<<Z<<endl;
                


    }
    
    return 0;
}