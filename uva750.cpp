// Auther : asmaa saeed date: 2020-08-09
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool row[10], d1[20], d2[20];
int cur = 1, res[9],t, r, c;
void backtrack(int col)
{
    if (col == 9)
    {
        printf("%2d      ", cur++);
        printf("%d", res[1] );
        for (int i = 2; i < 9; i++)
            printf(" %d", res[i]);
        puts("");
    }
    if(col==c)backtrack(col+1);
    else
    {
        loop(i,1,9){
            if(row[i]||d1[col+i] || d2[col-i+8])continue;
            row[i]=d1[col+i]=d2[col-i+8]=1;
            res[col]=i;
            backtrack(col+1);
            row[i]=d1[col+i]=d2[col-i+8]=0;

        }
    }
    

}
void clearing(){
    clr(row,0);
    clr(d1,0);
    clr(d2,0);
    row[r]=d1[r+c]=d2[c-r+8]=1;
    cur=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;

    loop(i, 0, t)
    {

        cin>>r>>c;
        
        clearing();
       res[c]=r;
        if (i)
            puts("");
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");       
        backtrack(1);
    }

    return 0;
}