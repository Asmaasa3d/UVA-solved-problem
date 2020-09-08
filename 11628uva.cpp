#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b){
    if(!a)
        return b;
    return gcd(b%a,a);
}
int main(){
    int n,m;
    while(cin>>n>>m&&n){
        vector<int> a(n);
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>a[i];
            sum+=a[i];
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<endl;
            if(!a[i])
                cout<<"0 / 1"<<endl;
            else{
                int g=gcd(a[i],sum);
                if(g==1)
                    cout<<a[i]<<" / "<<sum<<endl;
                else
                    cout<<a[i]/g<<" / "<<sum/g<<endl;
            }
        }
    }}