#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
int Ca,Cb,N;
string actions[] = { "fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B", "Start" };
enum list		   {  FILL_B ,  FILL_A ,  EMPTY_B ,  EMPTY_A ,  POUR_B_A ,  POUR_A_B  , Start};
struct  state
{
  int a,b,action;
};
const int MaX=1000+9;
bool reached[MaX][MaX]={0};
state prev_state[MaX][MaX];
queue<state>qu;
void baktrake(state cur){
    if(cur.a==0 && cur.b==0)return;
    baktrake(prev_state[cur.a][cur.b]);
    cout<<actions[cur.action]<<endl;
}
void add_state(int a,int b,int action,state parent){
    if(reached[a][b]) return;

    state cur={a,b,action};
    qu.push(cur);
    prev_state[a][b]=parent;
    reached[a][b]=true;
}
void BFS(int a,int b){
    qu=queue<state>();
    memset(reached,0,sizeof(reached));
    add_state(0,0,Start,state());
    while (!qu.empty())
    {
       state cur =qu.front();
       qu.pop();
       int a=cur.a,b=cur.b,aa,bb;
       if(b==N){
                baktrake(cur);
                cout<<"success\n";
			    return;
       }
    add_state(Ca,b,FILL_A,cur);
    add_state(a,Cb,FILL_B,cur);
    add_state(a,0,EMPTY_B,cur);
    add_state(0,b,EMPTY_A,cur);
    aa=(a+b)>Ca ?Ca:a+b;
    bb=(a+b)>Ca? (b-(Ca-a)):0;
    add_state(aa,bb,POUR_B_A,cur);
    aa=(a+b)>Cb ?a+b-Cb:0;
    bb=(a+b)>Ca? Cb:a+b;
    add_state(aa,bb,POUR_A_B,cur);

    }
    
    
}
int main(){
    while (cin>>Ca>>Cb>>N)
    {
        BFS(0,0);
    }
    
    return 0;
}