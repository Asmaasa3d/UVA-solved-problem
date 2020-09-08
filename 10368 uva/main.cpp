#include <iostream>

using namespace std;
#define ll long long
int cnt =0;
ll check(ll a,ll b){

    if(b==0)
        return 0;
    if(a/b >1)
        return 1;
       //  cout<<a<<" "<<b<<endl;
    return check(b,a-b)+1;
}
int main()
{
    ll a ,b;
    while(true){
        cin>>a>>b;

        if(a==0&&b==0)
            break;
    ll x=check(max(a,b),min(a,b));
    //cout<<cnt<<endl;

       if(x%2==0){
        cout<<"Ollie wins"<<endl;
       }
       else
         cout<<"Stan wins"<<endl;


    }

    return 0;
}
