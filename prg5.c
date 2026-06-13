#include<stdio.h>
#include<conio.h>
void selectionsort(int[],int);
void main(){
    int a[20],i,size;
    printf("enter how many elements"); 
    scanf("%d",&size);
    printf("enter %d elements\n",size);
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    selectionsort(a,size);
    printf("after sorting");
    for(i=0;i<=size;i++){
        printf("%d\t",a[i]);
    }
    getch();
} 
void selectionsort(int a[],int n){
    int i,j,temp,min;
    for(i=0;i<=n;i++){
        min=i;
        for(j=i+1;j<=n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}