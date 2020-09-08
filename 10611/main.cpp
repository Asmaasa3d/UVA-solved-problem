#include <bits/stdc++.h>

using namespace std;
int n,q;
vector<int>arr;
void BS(int num){
   int lo = 0, hi = n - 1,mid;

   if(arr[0]>=num){
    cout<<"X ";return;}
	while (lo <=hi) {
		mid = lo+ ((hi-lo+1) / 2);
		if (arr[mid] < num) lo = mid +1;
		else if (arr[mid] >=num) hi = mid - 1;
 	}

	if (hi<0){ cout<<"X ";return;}
	cout<<arr[hi]<<" ";

}
void BS1(int num){
  int lo = 0, hi = n - 1;
if(arr[n-1]<=num){
    cout<<"X"<<endl;return;}
	while (lo <= hi) {
		int mid = lo+ ((hi-lo+1) / 2);
		if (arr[mid] <= num) lo = mid + 1;
		else if (arr[mid] > num) hi = mid -1;
		//cout<<arr[lo]<<"L"<<endl;
 	}

	if (lo >=n) {cout<<"X"<<endl;return;}
	cout<<arr[lo]<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        arr.push_back(t);
    }
    cin>>q;
    for(int i=0;i<q;i++){
            int x;
        cin>>x;
       BS(x);
      BS1(x);
    }
    return 0;
}
