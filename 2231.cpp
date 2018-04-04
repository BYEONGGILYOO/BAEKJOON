#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int dpFunction(int key, int n, set<int>& output)
{
    if(n==1)
        return 0;
    int gen = n-1;
    set<int> arr;

    while(gen != 0)
    {
        arr.insert(gen%10);
        gen/=10;
    }
    gen = n-1;

    int sum = 0;
    for(set<int>::iterator itr = arr.begin(); itr!=arr.end(); ++itr)
        sum += *itr;

    if(gen+sum == key){
        output.insert(gen);
        //return gen;
    }
    arr.clear();
    return dpFunction(key, gen, output);
}

int main(int argc, char** argv)
{
    int input;
    scanf("%d",&input);

    set<int> output;
    dpFunction(input, input, output);

    printf("%d\n",*output.begin());

    return 0;
}
