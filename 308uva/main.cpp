#include <bits/stdc++.h>

using namespace std;
int n=0,x1,x2,z1,y2;
pair<int,int> apair;
pair<int,int> apair1;
vector<pair<int,int> > v_temp;
int arr_key[100][100]={0};
vector< vector<pair<int ,int > > >adjl;

int main()
{
    while(true){
        cin>>n;
        int key=0,index;
        if(n==0)
            break;
       adjl = vector< vector<pair<int ,int > > >(n+1);
        for(int i=0;i<n;i++){
            cin>>x1>>z1>>x2>>y2;

         //   apair1.first=x2;apair1.second=y2;
           if(arr_key[x1][z1]==0)
           {
        //   cout<<"Y"<<endl;
           key++;
               arr_key[x1][z1]=key;
               index=key;
             //  cout<<key<<endl;
       apair.first=x1;apair.second=z1;
       adjl[index].push_back(apair);
     //  cout<<adjl[index][0].first<<endl;
           }
           else index=arr_key[x1][z1];
           // v_temp.push_back(make_pair(x2,y2));
            adjl[index].push_back(make_pair(x2,y2));
           // v_temp.clear();

        }
        vector<pair<int ,int> >v;
        cout<<adjl.size()<<endl;
 for(int j=1;j<adjl.size();j++){
for(int i=0;i<adjl[j].size();i++){
    cout<<adjl[j].size()<<endl;
    cout<<"first"<<adjl[j][i].first<<" "<<adjl[j][i].second<<endl;

}
 }




    }
    return 0;
}
