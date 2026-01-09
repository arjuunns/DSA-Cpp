#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n-2;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<n-3;i++){
        int difference = arr[i+1]-arr[i];
        if(difference==2) printf("%d\n",arr[i]+1);
        else if(difference==3)  printf("%d\n%d\n",arr[i]+1,arr[i]+2);
    }
    return 0;
}