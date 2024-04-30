#include<stdio.h>
#include<systemtopologyapi.h>
/*int A(int x,int y){
    return(x+y);
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",A(x,y));
    system("pause");
    return 0;
} */
/* YangHuiTriangle
#include<stdio.h>
#include<systemtopologyapi.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int arry[n][n];
    arry[0][0]=1;
    printf("%d\n",arry[0][0]);
    for(i=1;i<n;i++){
        for(j=0;j<i+1;j++){
            if(i==j||j==0){
                arry[i][j]=1;
            }
            else
                arry[i][j] = arry[i-1][j]+arry[i-1][j-1];
            printf("%d\t",arry[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
} */
