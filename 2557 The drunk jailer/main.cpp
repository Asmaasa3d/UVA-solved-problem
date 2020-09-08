#include <iostream>

using namespace std;

int main()
{
 int n,a;
 cin>>n;
 int arr1[]={1,4,9,16,25,36,49,64,81,100};
 while(n--){
    cin>>a;
    int cnt=0;
    for(int i=0;i<10;i++){
        if(arr1[i]<=a)
            cnt++;
        else
            break;
    }
    cout<<cnt<<endl;
 }
    return 0;
}
