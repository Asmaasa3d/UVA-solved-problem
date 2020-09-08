#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define pb          push_back
#define MP          make_pair
#define P(x,s1,s2)   cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<x<<" knight moves.\n"
struct point
{
    int x,y;
};
point p1,p2;
queue<point>q;
bool vstd[10][10]={0};
int cnt=0;point par[10][10];
bool valid(point p){
    if(p.x>8 || p.x<1 ||p.y>8 || p.y<1 ||vstd[p.x][p.y]) return false;
    return true;
}
void count(point a){
    if(a.x==p1.x && a.y==p1.y)return;
    count(par[a.x][a.y]);
   // cout<<par[a.x][a.y].x<<" "<<par[a.x][a.y].y<<endl;
    cnt++;
}
void add_point(int x,int y,point cur){
    point p;p.x=x;p.y=y;
    if(!valid(p)) return;
    q.push(p);
   par[x][y]=cur;
    vstd[p.x][p.y]=true;
}
void BFS(point p1,point p2){
 q=queue<point>();
 memset(vstd,0,sizeof(vstd));
 cnt=0;
 q.push(p1);
 for(;!q.empty();)
 {
    point cur;cur=q.front();q.pop();
    int x=cur.x;int y=cur.y;    
    if(cur.x==p2.x && cur.y==p2.y){
        count(cur);
        return;}
    add_point(x-1,y-2,cur);
    add_point(x-1,y+2,cur);
    add_point(x-2,y-1,cur);
    add_point(x-2,y+1,cur);
    add_point(x+1,y-2,cur);
    add_point(x+1,y+2,cur);
    add_point(x+2,y-1,cur);
    add_point(x+2,y+1,cur);
 }
 

}

int main(){
    string s1,s2;
    while (cin>>s1>>s2)
    {
    p1.x=s1[1]-'0';p1.y=s1[0]-'a' +1;
    p2.x=s2[1]-'0';p2.y=s2[0]-'a' +1;
    BFS(p1,p2);
    P(cnt,s1,s2);

    }
    
    return 0;
}