// Auther : asmaa saeed date: 2020-08-27
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

int n, block_plc[26];
;
stack<int> st[25];
void move_onto(int a, int b)
{
    int a_plc = block_plc[a];
    while (st[a_plc].top() != a)
    {
        int t = st[a_plc].top();
        st[a_plc].pop();
        block_plc[t] = t;
        st[t].push(t);
    }
    int b_plc = block_plc[b];
    while (st[b_plc].top() != b)
    {
        int t = st[b_plc].top();
        st[b_plc].pop();
        block_plc[t] = t;
        st[t].push(t);
    }
    st[b_plc].pop();
    st[a_plc].pop();

    block_plc[b] = b;
    block_plc[a] = block_plc[b];
    st[b].push(b);
    st[b].push(a);
}
void move_over(int a, int b)
{
    int a_plc = block_plc[a];
    while (st[a_plc].top() != a)
    {
        int t = st[a_plc].top();
        st[a_plc].pop();
        block_plc[t] = t;
        st[t].push(t);
    }
    st[a_plc].pop();
    st[block_plc[b]].push(a);
    block_plc[a] = block_plc[b];
}
void pile_onto(int a, int b)
{
    while (st[block_plc[b]].top() != b)
    {
        int t = st[block_plc[b]].top();
        st[block_plc[b]].pop();
        block_plc[t] = t;
        st[t].push(t);
    }
    st[block_plc[b]].pop();
    block_plc[b] = b;
    st[b].push(b);
    stack<int> tmp;
    while (st[block_plc[a]].top() != a)
    {
        int t = st[block_plc[a]].top();
        st[block_plc[a]].pop();
        tmp.push(t);
    }
    tmp.push(a);
    st[block_plc[a]].pop();
    while (!tmp.empty())
    {
        st[b].push(tmp.top());
        block_plc[tmp.top()] = b;
        tmp.pop();
    }
}
void pile_over(int a, int b)
{
    stack<int> tmp;
    while (st[block_plc[a]].top() != a)
    {
        int t = st[block_plc[a]].top();
        st[block_plc[a]].pop();
        tmp.push(t);
    }
    tmp.push(a);
    st[block_plc[a]].pop();
    while (!tmp.empty())
    {
        st[block_plc[b]].push(tmp.top());
        block_plc[tmp.top()] = block_plc[b];
        tmp.pop();
    }
}
void print_stack()
{
    loop(i, 0, n)
    {
        cout << i << ":";
        if (st[i].empty())
            cout << endl;
        else
        {
            while (!st[i].empty())
            {
                cout << " " << st[i].top();
                st[i].pop();
            }
            cout << endl;
        }
    }
}
void init()
{
    loop(i, 0, n)
    {
        block_plc[i] = i;
        st[i].push(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string s1, s2;
    int a, b;
    init();
    while (cin >> s1)
    {

        if (s1 == "quit")
        {
            print_stack();
            break;
        }
        else
        {
            cin >> a >> s2 >> b;
            if (a != b && block_plc[a] != block_plc[b])
            {
                if (s1[0] == 'm')
                {
                    if (s2[1] == 'n')
                    {
                        move_onto(a, b);
                    }
                    else if (s2[1] == 'v')
                    {
                        move_over(a, b);
                    }
                }
                else if (s1[0] == 'p')
                {
                    if (s2[1] == 'n')
                    {
                        pile_onto(a, b);
                    }
                    else if (s2[1] == 'v')
                    {
                        pile_over(a, b);
                    }
                }
            }
        }
    }

    return 0;
}