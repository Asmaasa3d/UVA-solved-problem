#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
# define ll long long
vector<string >ls;bool vis[25][25]={0};
string s;
int cnt=0;
bool valid(int r,int c){
    if(r>=ls.size()-1 || r<0 || c>=ls[0].size()|| c<0){
        //cout<<r<<"F"<<c<<endl;
    return false;}
    return true;
}
void cntReachalbleCells(int r, int c)
{  
    if( !valid(r, c) || ls[r][c] == '0' || vis[r][c] == 1){
		return;	}	// invalid position or block position
	vis[r][c] = 1;	// we just visited it, don't allow any one back to it
	cnt++;
	// Try the 4 neighbor cells
	cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
    cntReachalbleCells(r-1, c+1);
    cntReachalbleCells(r-1, c-1);
    cntReachalbleCells(r+1, c+1);
    cntReachalbleCells(r+1, c-1);


}

int main(){
    int t;scanf("%i\t",&t);
    ls=vector<string>(25);
    while (t--)
    {   int mx=0;
         //cout<<"B\n";
       ls.clear();
       loop(i,0,25){
           loop(j,0,25)
           vis[i][j]=0;
       }
        getline(cin, s);ls.push_back(s);
      while (s.length()!=0)
      {    
           getline(cin, s);
         ls.push_back(s);
         
      }
      loop(i,0,ls.size()-1){
          loop(j,0,ls[i].size()){
          if(!vis[i][j]&&ls[i][j]=='1'){
              cnt=0;
              cntReachalbleCells(i,j);
              if(cnt>mx)mx=cnt; 
          }
      }}
     
      printf("%d\n",mx);
      if(t>0)   puts("");
     
    }
    return 0;
}