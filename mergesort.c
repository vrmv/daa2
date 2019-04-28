#include <stdio.h>

void mergesort(int *a,int start,int end){

	int middle=(start+end)/2;
	if(end-start<=0)
		return;

	mergesort(a,start,middle);
	mergesort(a,middle+1,end);
	merge(a,start,middle,end);
}

void merge(int *a,int start,int middle,int end)
{

	int i=start;
	int j=middle+1;
	int k=0;
	int c[end-start+1];

	while(i<middle+1 && j<=end)
	{
		if(a[i]<=a[j]){
     		c[k]=a[i];
     		i++;
     		k++;
		}else{
			c[k]=a[j];
			j++;
			k++;
		}
	}

	while(i<middle+1)
	{
		c[k]=a[i];
		i++;
		k++;
	}

	while(j<=end)
	{
		c[k]=a[j];
		j++;
		k++;
	}

	for(i=start,k=0;i<=end;i++,k++)
	{
		a[i]=c[k];
	}
}


int main()
{
    int i;
	int a[]={9,8,4,0,9,2,1,4,6,8};
	int n = sizeof(a)/sizeof(int);
	printf("Before sorting\t");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	mergesort(a,0,9);
	printf("After sorting \t");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
