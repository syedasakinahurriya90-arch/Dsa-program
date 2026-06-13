#include<stdio.h>
#include<conio.h>
int binaryrec(int[],int,int,int);
int binarynonrec(int[],int,int,int);
int main(){
    int a[40],key,n,pos,ch,i,low,high;
    printf("enter the size");
    scanf("%d",&n);
    low=0;
    high=n-1;
    printf("enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to be found\n");
    scanf("%d",&key);
    printf("1.recursion\t2.non recurssion\n");
    printf("enter the choice");
    scanf("%d",&ch);
    switch(ch){
        case 1:pos=binaryrec(a,low,high,key);
        break;
        case 2:pos=binarynonrec(a,low,high,key);
        break;
    
    }
    if(pos<0){
        printf("element not found");
    }
    else{
        printf("position %d",pos);
        }
    getch();    
}
int binarynonrec(int x[],int low,int high,int k){
    int mid;
    while(low<=high){
        mid=low+high/2;
        if(k==x[mid]){
            return mid;
        }
        else if(k<x[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return 0;
}

int binaryrec(int x[],int low,int high,int k){
    int mid;

        mid=low+high/2;
        if(k==x[mid]){
            return mid;
        }
        else if(k<x[mid]){
            return binaryrec(x,low,mid-1,k);
        }
        else{
            return binaryrec(x,mid+1,high,k);
        }
}














