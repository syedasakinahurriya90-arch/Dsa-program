#include<stdio.h>
#include<conio.h>
int lserch(int[],int,int);
int main(){
    int a[20],n,pos,i,ele;
    printf("enter how many elements");
    scanf("%d",&n);
    printf("enter %d elements\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the serch element");
    scanf("%d",&ele);
    pos=lserch(a,n,ele);
    if(pos>=0){
        printf("serch ii=s sucessful %d",pos);
    }
    else{
        printf("unsucessful");
    }
}
int lserch(int a[],int n,int ele){
    if(a[n]==ele){
        return n;
    }
    else{
        return lserch(a,n-1,ele);
    }
    return -1;
}