#include<stdio.h>

void merge(int *num,int l, int m, int r){
	
	int n1 = m - l + 1;
  	int n2 = r - m;
  	int i,j,k;
  	int L[n1], M[n2];
  	int n = l+r;
  	
  	for (i = 0; i < n1; i++)
    L[i] = num[l + i];
  for (j = 0; j < n2; j++)
    M[j] = num[m + 1 + j];
  	
  	i = 0;
  	j = 0;
  	k = l;
  	
  	while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      num[k] = L[i];
      i++;
    } else {
      num[k] = M[j];
      j++;
    }
    k++;
  }
  
   while (i < n1) {
    num[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    num[k] = M[j];
    j++;
    k++;
  }
  
}

void mergeSort(int *num,int l,int r){
	
	if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(num, l, m);
    mergeSort(num, m + 1, r);
    merge(num, l, m, r);
  }
}
int main(){
	int n,i;
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	int num[n];
	
	printf("Enter the numbers to sort\n");
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	printf("The numbers before sorting: ");
	for(i=0;i<n;i++){
		printf("%d  ",num[i]);
	}
	mergeSort(num,0,n-1);
	
	printf("\nThe numbers after sorting: ");
	for(i=0;i<n;i++){
		printf("%d  ",num[i]);
	}
}
