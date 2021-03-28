/*
return the minimum element present in each row of the array
*/
#include <stdio.h>
void min_row(int *a, int m, int n){
    int i,j;
    int min=0;
    for(i=0;i<m;i++){
        min=*(a+i*n);
        for(j=0;j<n;j++){
            if (min > *(a+(i*n)+j))
            min=*(a+(i*n)+j);
        }
        printf("the minimum element of %dth row =%d\n",i+1,min);
    }
}
int main(){
    int m,n,i,j;
    printf("enter the size of array\n");
    scanf("%d%d", &m, &n);
    int arx[m][n];
    printf("enter the elements of array\n");
    int x=0;
    int *arr=&arx[0][0];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            x=i*n;
            scanf("%d",(arr+(i*n)+j));
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d\t",*(arr+(i*n)+j));
        printf("\n");
    }
    min_row(arr,m,n);  // if arr[][] used then min_row(&arr[0][0],m,n);
    return 0;
}