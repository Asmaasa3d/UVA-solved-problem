#include <bits/stdc++.h>
using namespace std;
#define loop(i, str, end) for (int i = str; i < end; i++)
#define ll long long
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
struct node
{
    double x,y;
};
vector<node>lst;
struct edge
{
   int to,from;double w;
   edge(int from, int to): from(from), to(to) {
         double dx =lst[from].x - lst[to].x ;double dy =lst[from].y- lst[to].y;
       w =(dx*dx)+(dy*dy);
        w = sqrt(w);
   }

	bool operator < (const edge & e) const {
		return w > e.w;	
	}
};


int n, t;
double PRIM_MST(){
    
	double  mstCost = 0;bool vstd[103]={0};
    priority_queue<edge>q;
    q.push( edge(0, 0  ) );
    while (!q.empty())
    {
       edge e=q.top();q.pop();
       if(vstd[e.to]) continue;
       vstd[e.to]=1;
       mstCost+=e.w;
       loop(i,0,n){
           edge ne(e.to,i);
           if(!vstd[i]) q.push(ne);
       }
    }
    return mstCost;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--)
    {
        cin >> n;
        lst.clear();
        loop(i, 0, n)
        {   node a;
            cin>>a.x>>a.y;
            lst.pb(a);
        }
      
        cout<< fixed<<setprecision(2)<< PRIM_MST()<<endl;
        if(t!=0)
        cout<<"\n";
    }

    return 0;
}