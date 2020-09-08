// Auther : asmaa saeed date: 2020-07-29
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

int main()
{

    int t;
    cin >> t;
    loop(i, 0, t)
    {
        int ans[100005] = {0};
        string s;
        cin >> s;
        stack<pair<char, int>> stk;
        loop(j, 0, s.size())
        {
            char c = s[j];
            if (c == '[' || c == '(' || c == '<' || c == '{')
            {
                stk.push(MP(c, j));
               // cout << j << "  PPPddd" << endl;
            }
            else if (!stk.empty())
            {
                if ((c == ']' && stk.top().first == '[') || (c == '}' && stk.top().first == '{') || (c == ')' && stk.top().first == '(') || (c == '>' && stk.top().first == '<'))

                {
                   // cout << j << "  oww" << endl;
                    loop(x, 0, stk.top().second + 1)
                    {
                        ans[x]++;
                    }
                     stk.pop();
                }
                 else
            {
                while (!stk.empty())
                {
                    stk.pop();
                }
            }
            }
          
        }
        loop(e, 0, s.size()) cout << ans[e] << " ";
    }
    return 0;
}