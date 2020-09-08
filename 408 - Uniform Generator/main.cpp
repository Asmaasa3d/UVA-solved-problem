#include <bits/stdc++.h>

using namespace std;
int step,mod;
int seed(int z){
 return (z+step)%mod;
}
int main()
{
    while(cin>>step){
        cin>>mod;
        int x=0,z;
       bool arr[100000]={0};int cnt=1;
       arr[0]=true;
       while(true){
            z=seed(x);
                if(arr[z]==true){
            if(cnt==mod){
             cout << setw(10) << step << setw(10) << mod << "    ";
             cout << "Good Choice\n\n";
            }
            else{
               cout << setw(10) << step << setw(10) << mod << "    ";
                cout << "Bad Choice\n\n";
            }
            break;
          }

          arr[z]=true;
          cnt++;
          x=z;

        }
    }
    return 0;
}
