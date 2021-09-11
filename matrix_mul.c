/*
* the matrix multiplication of two matrixes of M x N and P x Q sizes
*/
#include <stdio.h>
int main(){
    int m,n,p,q;
    int i,j,k;
    // entery of elements of the array
    printf("enter the size of the first matrix\n");
    scanf("%dx%d",&m,&n);
    int arr1[m][n];
    printf("enter the elements of the first matrix\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d",&arr1[i][j]);
    
    printf("enter the size of the second matrix\n");
    scanf("%dx%d",&p,&q);
    int arr2[p][q];
    printf("enter the elements of the second matrix\n");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d",&arr2[i][j]);

    // display of the matrixes
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
        printf("%d\t",arr1[i][j]);
        printf("\n");
    }
    for(i=0;i<p;i++){
        for(j=0;j<q;j++)
        printf("%d\t",arr2[i][j]);
        printf("\n");
    }

    //multiplication begins
    int index;
    if(n==p)
    printf("matrix multiplication possible\n");
    else
    {
        return 0;
    }

    int mul[m][q], sum=0;
    for(i=0;i<m;i++){
        index=0;
        for(index=0;index<q;index++){
            for(k=0, j=0; j<n; k++, j++){
                sum += arr1[i][j]*arr2[k][index];
            }
            mul[i][index] = sum;
            sum=0;
        }
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<q;j++)
        printf("%d\t",mul[i][j]);
        printf("\n");
    }
    return 0;
}