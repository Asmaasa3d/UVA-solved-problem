#include <iostream>

using namespace std;

int main()
{
  int n,cnt=0;
  cin>>n;
  for(int i = 1; i <= n / 2; ++i){
        cout<<i<<"aa"<<endl;
    if(n%i==0)
        cnt++,cout<<i<<endl;

  }
  cout<<cnt;
    return 0;
}
