#include<stdio.h>
#include<conio.h>
void insertionsort(int[],int);
void main(){
    int a[20],i,size;
    printf("enter how many elements"); 
    scanf("%d",&size);
    printf("enter %d elements\n",size);
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(a,size);
    printf("after sorting\n");
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    getch();
} 
void insertionsort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        temp=a[i];
        for(j=i;j>0&&temp<a[j-1];j--){
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
}