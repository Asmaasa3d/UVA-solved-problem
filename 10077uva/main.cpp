#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define pb          push_back
#define MP          make_pair
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
int n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream myfile,file;
     myfile.open ("example.txt");
    file.open ("input.txt");
    while (true)
    {   
        int r_e=1,r_d=0,l_e=0,l_d=1,cur_E=1,cur_D=1;
        cin>>n>>m;
        if(n==1 && m==1)
            break;
        while (cur_E!=n ||cur_D!=m )
        {
       
            if(cur_D*n > cur_E*m){
               int t1=cur_E,t2=cur_D;
                cur_E+=r_e;
                cur_D+=r_d;
                l_e=t1;l_d=t2;
                myfile<<"R";
                cout<<"R";
            }
            else
            {
                int t1=cur_E,t2=cur_D;
                 cur_E+=l_e;
                cur_D+=l_d;
                r_e=t1;r_d=t2;
                myfile<<"L";
                cout<<"L";

            }
        }
        myfile<<"\n";
        cout<<endl;

        
    }
    myfile.clear();
    return 0;
}