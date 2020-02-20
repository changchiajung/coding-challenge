#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long ans;
int *firstArray;
int *secondArray; 
void rec(int n, int i, long long ft, long long sd, long long h){
    if(n == i){
        if(ft>=h && sd >=h){
            ans +=1;
        }
    }else{
    /*
    1. first 2. second 3. both
    */
    rec(n, i + 1, ft + firstArray[i], sd, h);
    rec(n, i + 1, ft, sd + secondArray[i], h);
    rec(n, i + 1, ft + firstArray[i], sd + secondArray[i], h);
    /*
    */
    }

}
int main()
{
    int casenum;
    scanf("%d", &casenum);
    for (int inp = 1; inp <= casenum; inp++)
    {
        ans = 0;
        /*
            n for testNum
            h for happiness
        */
        int n, h;
        scanf("%d %d", &n, &h);
        firstArray = malloc(sizeof(int) * n);
        secondArray = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &firstArray[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &secondArray[i]);
        }
        rec(n, 1, firstArray[0], 0, h);
        rec(n, 1, 0, secondArray[0], h);
        rec(n, 1, firstArray[0], secondArray[0], h);
        printf("Case #%d: %lld\n",inp,ans);
    }
}
