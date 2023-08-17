#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    scanf("%d", &N);

    int count[10001]={0,};

    int num;
    for(int i=0; i<N; i++){
        scanf("%d", &num);
        count[num] += 1;
    }

    for(int num=1; num<10001; num++)
    {
        for(int i=0; i<count[num]; i++)
            printf("%d\n", num);
    }

    return 0;
}