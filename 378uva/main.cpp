#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define pb          push_back
#define MP          make_pair
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
#define cp(a,b)   ( (conj(a)*(b)).imag() )	
int n,x,y,x2,y2,x3,x4,y3,y4;
typedef complex<double> point;
bool isCollinear(point a, point b, point c) {	
	return fabs( cp(b-a, c-a) ) < 0;	
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    loop(i,0,n){
     cin>>x>>y>>x2>>y2>>x3>>y3>>x4>>y4;
       point a(x,y);point b(x2,y2);
       point c(x3,y3);point d(x4,y4);
       point e=b-a;point t=d-c;
        if(cp(e,t)==0 ){
            if(cp(b-a,b-c)==0){
                cout<<"LINE\n";
            }
            else{
                cout<<"NONE\n";
            }
        }
        else{
           double a1=y-y2,b1=x2-x,c1=x*y2-x2*y,
           a2=y3-y4,b2=x4-x3,c2=x3*y4-x4*y3;
           double ya=(c1*a2 -a1*c2)/(a1*b2-a2*b1);
           double xa=(-b1*ya-c1)/a1;
           cout<<fixed<<setprecision(2)<<"POINT "<<xa<<" "<<ya<<endl;
        }

    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
