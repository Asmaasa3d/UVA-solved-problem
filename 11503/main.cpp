// Auther : Asmaa Saad  date: 2020-03-27 
// think more code  fast
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
int f;
struct DisjSet{
map <string,string> parent ;map <string,int>rank ;
int numOftrees ;
DisjSet(int n ){
numOftrees=n;

}
string findSetParent(string i ){
if(parent.find(i)==parent.end()) return i;
return parent[i]=findSetParent(parent[i]);
}
bool check_connection(string x,string y){
x=findSetParent(x);y=findSetParent(y);
if(x==y) return true;
return false;}
bool Union (string x , string y){
x=findSetParent(x);y=findSetParent(y);
if(x==y)return false;
parent[x]=y;
rank[y]+=rank[x];
rank[x]+=rank[y];
numOftrees--;
return x!=y;
}
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
   
    while (t--)
    {   
       cin>>f;
       DisjSet s=DisjSet(f);
       string s1,s2;
       while(f--)
      { 
       cin>>s1>>s2;
       if(s.rank.find(s1)==s.rank.end())s.rank[s1]=1;
      if(s.rank.find(s2)==s.rank.end())s.rank[s2]=1;
      s.Union(s1,s2);
     // myfile<<s.rank[s.findSetParent(s1)]<<endl;
      cout<<s.rank[s.findSetParent(s1)]<<endl;}
    }
    
    return 0;
}