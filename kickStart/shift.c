#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    long long first;
    long long second;
} node;

long long ans;
int *firstArrayOne;
int *secondArrayOne;
int *firstArrayTwo;
int *secondArrayTwo;
node *nodeOne;
node *nodeSecond;
int indexOne;
int indexTwo;
void swap(node* a, node* b) 
{ 
	node t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (node arr[], int low, int high) 
{ 
	int pivot = arr[high].first; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j].first >= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
void quickSort(node arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void secrec(int n, int i, long long ft, long long sd)
{
    if (i == n)
    {
        nodeSecond[indexTwo].first = ft;
        nodeSecond[indexTwo].second = sd;
        indexTwo++;
    }
    else
    {
        /*
    1. first 2. second 3. both
    */
        secrec(n, i + 1, ft + firstArrayTwo[i], sd);
        secrec(n, i + 1, ft, sd + secondArrayTwo[i]);
        secrec(n, i + 1, ft + firstArrayTwo[i], sd + secondArrayTwo[i]);
    }
}
void rec(int n, int i, long long ft, long long sd)
{
    if (i == n)
    {
        nodeOne[indexOne].first = ft;
        nodeOne[indexOne].second = sd;
        indexOne++;
    }
    else
    {
        /*
    1. first 2. second 3. both
    */
        rec(n, i + 1, ft + firstArrayOne[i], sd);
        rec(n, i + 1, ft, sd + secondArrayOne[i]);
        rec(n, i + 1, ft + firstArrayOne[i], sd + secondArrayOne[i]);
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
        firstArrayOne = malloc(sizeof(int) * n / 2);
        secondArrayOne = malloc(sizeof(int) * n / 2);
        firstArrayTwo = malloc(sizeof(int) * (n - n / 2));
        secondArrayTwo = malloc(sizeof(int) * (n - n / 2));
        nodeOne = (node *)malloc(sizeof(node) * (pow(3, n / 2)+1));
        nodeSecond = (node *)malloc(sizeof(node) * (pow(3, n - n / 2)+1));
        for (int i = 0; i < n / 2; i++)
        {
            scanf("%d", &firstArrayOne[i]);
        }
        for (int i = 0; i < n - n / 2; i++)
        {
            scanf("%d", &firstArrayTwo[i]);
        }
        for (int i = 0; i < n / 2; i++)
        {
            scanf("%d", &secondArrayOne[i]);
        }
        for (int i = 0; i < n - n / 2; i++)
        {
            scanf("%d", &secondArrayTwo[i]);
        }
        rec(n / 2, 1, firstArrayOne[0], 0);
        rec(n / 2, 1, 0, secondArrayOne[0]);
        rec(n / 2, 1, firstArrayOne[0], secondArrayOne[0]);
        secrec(n - n / 2, 1, firstArrayTwo[0], 0);
        secrec(n - n / 2, 1, 0, secondArrayTwo[0]);
        secrec(n - n / 2, 1, firstArrayTwo[0], secondArrayTwo[0]);
        quickSort(nodeOne,0,indexOne-1);
        quickSort(nodeSecond,0,indexTwo-1);
        for(int i = 0; i< indexOne; i++){
            for(int j = 0; j<indexTwo;j++){
                if(nodeOne[i].first + nodeSecond[j].first >=h){
                    if(nodeOne[i].second + nodeSecond[j].second >= h){
                        ans+=1;
                    }
                }else{
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n", inp, ans);
        /*
        free(nodeSecond);
        free(nodeOne);
        free(firstArrayOne);
        free(firstArrayTwo);
        free(secondArrayOne);
        free(secondArrayTwo);
        */
    }
}
