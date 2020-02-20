#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
long long ans;
int *firstArray;
int *secondArray; 
long long *firstResultOne;
long long *firstResultTwo;
long long *secondResultOne;
long long *secondResultTwo;
int indexOne;
int indexTwo;

void swap(long long* a, long long* b) 
{ 
	long long t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (long long arr[], int low, int high,int num) 
{ 
    long long pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] >= pivot) 
        { 
            i++;    // increment index of smaller element 
            //swap(i,j,num); 
            if(num == 1){
                swap(&arr[i],&arr[j]);
                swap(&secondResultOne[i],&secondResultOne[j]);
            }else{
               swap(&arr[i],&arr[j]);
                swap(&secondResultTwo[i],&secondResultTwo[j]); 
            }
        } 
    } 
    //swap(i+1,high,num); 
            if(num == 1){
                swap(&arr[i+1],&arr[high]);
                swap(&secondResultOne[i+1],&secondResultOne[high]);
            }else{
               swap(&arr[i+1],&arr[high]);
                swap(&secondResultTwo[i+1],&secondResultTwo[high]); 
            }
    return (i + 1); 
} 
  

void quickSort(long long arr[], int low, int high,int num) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high,num); 

		quickSort(arr, low, pi - 1,num); 
		quickSort(arr, pi + 1, high,num); 
	} 
} 

void secrec(int n, int i, long long ft, long long sd, long long h){
    if(i == n/2){
        /*
        if(ft>=h && sd >=h){
            ans +=1;
        }
        */
        firstResultOne[indexOne] = ft;
        secondResultOne[indexOne] = sd;
        indexOne++;
    }else if(i==n){
        firstResultTwo[indexTwo] = ft;
        secondResultTwo[indexTwo] = sd;
        indexTwo++;
    }else{
    /*
    1. first 2. second 3. both
    */
    secrec(n, i + 1, ft + firstArray[i], sd, h);
    secrec(n, i + 1, ft, sd + secondArray[i], h);
    secrec(n, i + 1, ft + firstArray[i], sd + secondArray[i], h);
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
        indexOne = 0;
        indexTwo = 0;
        /*
            n for testNum
            h for happiness
        */
        int n, h;
        scanf("%d %d", &n, &h);
        firstArray = malloc(sizeof(int) * n);
        secondArray = malloc(sizeof(int) * n);
        firstResultOne = malloc(sizeof(long long) * pow(3,10));
        firstResultTwo = malloc(sizeof(long long) * pow(3,10));
        secondResultOne = malloc(sizeof(long long) * pow(3,10));
        secondResultTwo = malloc(sizeof(long long) * pow(3,10));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &firstArray[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &secondArray[i]);
        }
        
        secrec(n, 1, firstArray[0], 0, h);
        secrec(n, 1, 0, secondArray[0], h);
        secrec(n, 1, firstArray[0], secondArray[0], h);
        secrec(n, n/2+1, firstArray[n/2], 0, h);
        secrec(n, n/2+1, 0, secondArray[n/2], h);
        secrec(n, n/2+1, firstArray[n/2], secondArray[n/2], h);
               for (int i = 0; i < indexTwo; i++)
        {
            printf("<%lld ,%lld> ", firstResultTwo[i],secondResultTwo[i]);
        }
        printf("\n"); 
        quickSort(firstResultOne,0,indexOne-1,1);
        quickSort(firstResultTwo,0,indexTwo-1,2);
               for (int i = 0; i < indexTwo; i++)
        {
            printf("<%lld ,%lld> ", firstResultTwo[i],secondResultTwo[i]);
        }
        printf("\n"); 
        for(int i = 0; i< indexOne; i++){
            for(int j = 0; j<indexTwo;j++){
                if(firstResultOne[i] + firstResultTwo[j] >=h){
                    if(secondResultOne[i] + secondResultTwo[j] >= h){
                        ans+=1;
                    }
                }else{
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n",inp,ans);
        
        free(firstResultOne);
        free(firstResultTwo);
        free(secondResultOne);
        free(secondResultTwo);
    }
}
