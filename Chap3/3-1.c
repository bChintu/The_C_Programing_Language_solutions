#include<stdio.h>
int binsearch(int a,int arr[],int b);
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int value=binsearch(3,arr,10);
    printf("index value : %d\n",value);
}
int binsearch(int ele,int arr[],int max)
{
    int lower=0;
    int high=max-1;
    int mid;
    while(lower <= high && arr[(mid=(lower+high)/2)] != ele)
    {
        mid=(lower+high)/2;
        if(ele < arr[mid])
        {
            high=mid-1;
        }
        else
        {
            lower=mid+1;
        }
    }
    return (arr[mid]==ele)? mid:-1;
}


