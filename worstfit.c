#include<stdio.h>
int main(){
    int bsize[20],psize[20];
    int all[20],m,n,i,j;
    printf("Enter no of blocks : ");
    scanf("%d",&m);
    printf("Enter size of each block : ");
    for(i=0;i<m;i++){
        scanf("%d",&bsize[i]);
    }
    printf("Enter no of processes : ");
    scanf("%d",&n);
    printf("Enter size of each process : ");
    for(i=0;i<n;i++){
        scanf("%d",&psize[i]);
        all[i]=-1;
    }
    for(i=0;i<n;i++){
        int worstplace=-1;
        for(j=0;j<m;j++){
            if(bsize[j]>=psize[i]){
                if(worstplace==-1){
                    worstplace=j;
                }
                else if(bsize[worstplace]<bsize[j]){
                    worstplace=j;
                }
            }
        }
        if(worstplace!=-1){
            all[i]=worstplace;
            bsize[worstplace] = bsize[worstplace]-psize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(all[i]!=-1){
            printf("%d\n",all[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }
}