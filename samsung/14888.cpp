#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>

using namespace std;

int N;
int input[100];
int summax = numeric_limits<int>::min();
int summin = numeric_limits<int>::max();
int p, s, m, d;

#define __MAX(x,y) x > y ? x : y
#define __MIN(x,y) x < y ? x : y

void dfs(int idx, int plus, int sub, int mul, int div, int tot)
{
    if(idx == N)
    {
        summax = __MAX(summax, tot);
        summin = __MIN(summin, tot);
        return;
    }

    if(plus < p)
        dfs(idx+1, plus+1, sub, mul, div, tot+input[idx]);
    if(sub < s)
        dfs(idx+1, plus, sub+1, mul, div, tot-input[idx]);
    if(mul < m)
        dfs(idx+1, plus, sub, mul+1, div, tot*input[idx]);
    if(div < d)
        dfs(idx+1, plus, sub, mul, div+1, tot/input[idx]);

}

int main()
{
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        scanf("%d", &input[i]);

    scanf("%d%d%d%d", &p, &s, &m, &d);

    dfs(1,0,0,0,0,input[0]);
    printf("%d\n%d\n",summax, summin);

    return 0;
}
