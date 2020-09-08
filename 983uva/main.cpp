#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;int arr[1009][1009];int row[1009][1009];
int col[1009][1009];
ll fnc(int k ,int l){
    int i=k-(m-1);int j=l-(m-1);
    return  row[k][l] - row[k][j-1] - row[i-1][l] + row[i-1][j-1];
}

int main(){

bool endLine = false;
while (cin>>n>>m)
{

     for(int i=n;i>0;i--){
    for(int j=1;j<=n;j++){
        cin>>arr[i][j];

    }
}

 long long  s=0;

for(int i=0;i<=n;i++){
    row[0][i]=0;
 }
 for(int i=0;i<=n;i++){
    row[i][0]=0;

 }
    for(int i=1;i<=n;i++){
        s=0;
    for(int j=1;j<=n;j++){
       s+=arr[i][j];
       row[i][j]=s;
    }
}
 for(int i=2;i<=n;i++){
        s=0;
    for(int j=1;j<=n;j++){
       row[i][j]+=row[i-1][j];
    }

}
if (endLine) putchar('\n'); endLine = true;
ll sum=0;
for(int i=n;i>=m;i--){
    for(int j=m;j<=n;j++){
ll z=fnc(i,j);
     printf("%d\n", z);
      sum+=z;
    }
}
printf("%d\n", sum);
}


    return 0;
}
