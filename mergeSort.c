#include<stdio.h>
void main(){
    int low=0,high,i,n;
    int arr[15];
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    high=n-1;
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
    mergeSort(low,high,n,arr);
    printf("Sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void mergeSort(int low,int high,int n,int arr[n])
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(low,mid,n,arr);
        mergeSort(mid+1,high,n,arr);
        merge(low,mid,high,n,arr);
    }
}

void merge(int low,int mid,int high,int n,int arr[n])
{
    int i=low,j=mid+1,k=low,c[n];
    while(i<=mid&&j<=high)
    {
        if(arr[i]<arr[j])
        {
            c[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            c[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        c[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        c[k]=arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i]=c[i];
    }
}
