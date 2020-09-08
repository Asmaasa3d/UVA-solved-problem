#include <bits/stdc++.h>

using namespace std;
int n,h,w,cnt=0;
string s;
bool visited[10000][10000]={0};
vector<string>adlist;

void dfs(int i , int j,char c){
  if((i<0) || (i==h) || (j<0) ||(j==w )) return;
  if(visited[i][j] || adlist[i][j]!=c)
    return;
visited[i][j]=true;
//cout<<i<<" "<<j<<endl;
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

{ cin>>n;
for(int t=0;t<n;t++){
vector<pair<char,int> >rslt;
cin>>h>>w;
for(int g =0;g<h;g++)
    for(int x=0;x<w;x++)
    visited[g][x]=false;
vector<char>l;
bool arr[30];
for(int g =0;g<30;g++)
    arr[g]=false;
adlist.clear();
l.clear();
rslt.clear();
  for(int i =0;i<h;i++){
    cin>>s;
    adlist.push_back(s);
    for(int j=0;j<w;j++){
        if(!arr[s[j]-'a']){
            arr[s[j]-'a']=true;
            l.push_back(s[j]);
            }
    }

  }
  cout<<"World #"<<t+1<<endl;

 for(int i=0;i<l.size();i++){
      char c=l[i];
      cnt=0;
    for(int r =0;r<h;r++){
             for(int j=0;j<w;j++){
           if(!visited[r][j]&&adlist[r][j]==c)
               {
                   cnt++;
                 //  cout<<r<<" "<<j<<endl;
                   dfs(r,j,c);

               }
    }

  }
  // cout<<cnt<<endl;
  rslt.push_back(make_pair(c,cnt));
  }
  sort(rslt.begin(), rslt.end(), Cmp<pair<int, int> >());
  for(int z=0;z<rslt.size();z++){


     cout<<rslt[z].first<<": "<<rslt[z].second<<endl;


  }
}
    return 0;
}
