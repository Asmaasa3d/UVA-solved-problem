#include <bits/stdc++.h>
using namespace std;
int cnt=0;
vector<string>adjl;  int x,y;string s;bool visited[50][50]={0};
void dfs(int i , int j,char c ){
  if((i<0) || (i==x) || (j<0) ||(j==y )) return ;
  if(visited[i][j] || adjl[i][j]!=c)
    return ;
visited[i][j]=true;
cnt++;
 //cout<< cnt++<<endl;
//cout<<i<<"dfs "<<j<<endl;
dfs(i-1,j,c);
dfs(i+1,j,c);
dfs(i,j-1,c);
dfs(i,j+1,c);

}
template<typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
        if(p1.second > p2.second) return true;
        if(p1.second == p2.second) return p1.first < p2.first;
        return false;
    }
};

int main()
{
  for(int pn=1; ;pn++){
         cnt=0;
        cin>>x>>y;
        for(int g =0;g<x;g++)
    for(int a=0;a<y;a++)
    visited[g][a]=false;

    if(x==0&&y==0)
        break;
    vector<pair<char,int> >rslt;
    rslt.clear();
    adjl.clear();
   for(int i =0;i<x;i++){
        cin>>s;
        adjl.push_back(s);
    }
    for(int i =0;i<x;i++){
    for(int j=0;j<y;j++){
            //cout<<adjl[i][j]<<endl;
      if(!visited[i][j]&&adjl[i][j]!='.'){
      char c=adjl[i][j];
      dfs(i,j,c);
     //cout<<i<<" "<<j<<" "<<c<<" "<<endl;
     //cout<<cnt<<endl;
      rslt.push_back(make_pair(c,cnt) );
      cnt=0;
      }
    }}
    cout<<"Problem "<<pn<<":"<<endl;
 sort(rslt.begin(), rslt.end(), Cmp<pair<int, int> >());
   for(int z=0;z<rslt.size();z++){
    cout<<rslt[z].first<<" "<<rslt[z].second<<endl;
  }

  }
    return 0;
}
