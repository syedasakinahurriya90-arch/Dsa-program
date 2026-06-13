#include<stdio.h>
#include<conio.h>
void bublesort(int[],int);
void main(){
    int a[20],i,size;
    printf("enter how many elements"); 
    scanf("%d",&size);
    printf("enter %d elements\n",size);
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    bublesort(a,size);
    printf("after sorting");
    for(i=0;i<=size;i++){
        printf("%d\t",a[i]);
    }
    getch();
}
void bublesort(int a[],int n){
    int i,j,temp;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}