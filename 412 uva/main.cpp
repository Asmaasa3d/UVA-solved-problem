#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
if(b==0)
    return a;
    return gcd(b,a%b);
}
int com(int n){
  int r=1;
  for(int i=n;i>n-2;i--){
    r*=i;
   }
  return r/2;
}
int main()
{
    int n;
    while(true){
            int cnt=0,arr[53];
        cin>>n;
        if(n==0)
            break;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     for(int i=0;i<n;i++){
         for(int a=i+1;a<n;a++){
            if(i!=a){
                if(gcd(arr[i],arr[a])==1)
                    cnt++;
            }
         }
     }
     n=com(n);
    // cout<<n<<" ";
    // cout<<cnt<<" ";
     if(cnt>0){
     double z=sqrt((double)(6*n)/(double)cnt);

     cout<<fixed<<setprecision(6)<<z<<endl;
     }
     else
        cout<<"No estimate for this data set."<<endl;
    }

    return 0;
}
