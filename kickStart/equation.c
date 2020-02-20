#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int bitArray[51];
int tArray[51];

int main()
{
    int caseNum;
    scanf("%d", &caseNum);

    for (int inp = 1; inp <= caseNum; inp++)
    {
        int n;
        long long t;
        long long mx = 0;
        scanf("%d %lld", &n, &t);
        memset(&bitArray, 0, sizeof(bitArray));
        memset(&tArray, 0, sizeof(tArray));

        for (int j = 0; j < n; j++)
        {
            long long tmp;
            scanf("%lld", &tmp);
            if (mx < tmp)
            {
                mx = tmp;
            }
            for (int i = log(tmp) / log(2); i >= 0; i--)
            {
                if (tmp >= (long long)pow(2, i))
                {
                    tmp -= (long long)pow(2, i);
                    bitArray[i] += 1;
                }
            }
        }
        long long realCost = 0;
        long long ans = 0;
        long long ct = 0;
        ;
        if(mx < t/n){
            mx = t/n;
        }
        for (int i = (log(mx) / log(2) + 1); i >= 0; i--)
        {
            ct = 0;
            for (int j = 0; j < i; j++)
            {
                if (bitArray[j] <= n / 2)
                {
                    ct += (long long)pow(2, j) * bitArray[j];
                }
                else
                {
                    ct += (long long)pow(2, j) * (n - bitArray[j]);
                }
            }
            //past cost + current bit cost + optimal future cost 
            long long tmpCost = (long long)pow(2, i) * (n - bitArray[i]);
            if (realCost + tmpCost + ct <= t)
            {
                realCost += tmpCost;
                ans += (long long)pow(2,i);
            }else{
                realCost += (long long)pow(2,i)*bitArray[i];
            }
        }
        if(ans == 0 && realCost+ct >t){
            printf("Case #%d: -1\n",inp);
        }else{
            printf("Case #%d: %lld\n",inp, ans);
        }
    }

    return 0;
}

