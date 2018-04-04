#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define _min(a,b) a<b ? a:b
#define MAX_COST 10000+1

int main(int argc, char** argv)
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<1 || n>100)
        return 1;
    if(k<1 || k>10000)
        return 1;

    vector<int> coin(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d",&coin[i]);

    vector<int> num_coins(k+1, MAX_COST);
    num_coins[0] = 0; //impossible case, zero sum by zero is zero

    for(int i=1; i<=n; i++)
        for(int j=coin[i]; j<=k; j++)
            num_coins[j] = _min(num_coins[j], num_coins[j-coin[i]]+1);

    if(num_coins[k] == MAX_COST) printf("-1\n");
    else printf("%d\n", num_coins[k]);

    return 0;
}
