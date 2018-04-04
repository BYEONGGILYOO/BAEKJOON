#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

using namespace std;

vector<int> call;
vector<int> dp;

int fibonacci(int n)
{
    call[n]++;

    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    if(dp[n] != -1) return dp[n];

    dp[n] = fibonacci(n-2) + fibonacci(n-1);
    return dp[n];
}
int main(int argc, char** argv)
{
    clock_t start, end;
    int n;
    scanf("%d", &n);
    call.resize(n+1);
    dp.resize(n+1, -1);

    start = clock();
    printf("%d\n", fibonacci(n));
    end = clock();
    cout << "Time required for execution: "<<(double)(end-start)/CLOCKS_PER_SEC <<"s\n";

    for(int i=0; i<=n; i++)
        printf("F(%d): %d times called\n",i,call[i]);

    return 0;
}
