#include<bits/stdc++.h>
using namespace std;
int n,mm,flg;
char str[1002][1002],ch;
/*
    *
    * Prosen Ghosh
    * American International University - Bangladesh (AIUB)
    *
*/
void DFS(int x, int y){

    if(str[x][y] == '*')return;
    if(x < 0 || y < 0 || x == n || y == mm)return;
    if(str[x][y] != ch)return;
    if(str[x][y] == ch){
        str[x][y]='*';
        flg = 1;
    }
    DFS(x,y+1);
    DFS(x,y-1);
    DFS(x+1,y);
    DFS(x-1,y);
}
struct val{
    char word;
    int continar = 0;
};
bool cmp(val a, val b){
    if(a.continar == b.continar)return a.word < b.word;
    return a.continar > b.continar;
}
int main(){

    int T, cnt[30];
    cin >> T;
    for(int t = 1; t <= T;t++){
        cin >> n >> mm;
        memset(cnt, 0, sizeof(cnt));
        val v[30];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mm; j++){
                cin >> str[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mm; j++){
               if(str[i][j] != '*'){
                   ch = str[i][j];
                   DFS(i,j);
                   cnt[ch - 'a']++;
               }
            }
        }
        int k = 0;
        for(int i = 0; i < 26; i++){
            if(cnt[i] != 0){
                v[k].word = 'a'+i;
                v[k].continar = cnt[i];
                k++;
            }
        }
        sort(v,v+k,cmp);
        cout << "World #" << t << endl;
        for(int i = 0; i < k;i++){
            if(v[i].continar != 0)cout << v[i].word << ": " << v[i].continar << endl;
        }
    }
    return 0;
}
