#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int caseNum;
    scanf("%d", &caseNum);

    /*
        eachCase
    */
    for(int i = 0; i<caseNum; i++){
        int t,m,p;
        long long ans = 0;
        scanf("%d %d %d",&t,&m,&p);
        int bArray[t+1];
        memset(&bArray,0,sizeof(bArray));

        while(m--){
            int tmp;
            scanf("%d",&tmp);
            bArray[tmp] = 1;
        }

        while(p--){
            int eachp;
            scanf("%d",&eachp);
            for(int j = eachp; j<=t;j+=eachp){
                if(!bArray[j]){
                    ans ++;
                }
            }
        }
        printf("Case #%d: %lld\n",i,ans);

    }


    return 0;
}
