#include <stdio.h>
#include <time.h>  

void mergeSort(int a[],int low , int high);
void merge(int a[],int low,int high) ; 

int main(){
    int n ;  
    scanf("%d",&n) ; 
    int a[n] ; 
    for(int i = 0 ; i<n ; ++i){
        scanf("%d",&a[i]) ;  
    }
    clock_t start = clock() ; 
    mergeSort(a,0,n-1) ; 
    clock_t end = clock() ;  
    double t = ((double)(end-start)/(double)CLOCKS_PER_SEC) ;  
    
    for(int i = 0 ; i<n ; ++i){
        printf("%d ",a[i])  ; 
    }
    printf("\n") ;  
    printf("%.30f",t) ; 

}
void mergeSort(int a[] , int low ,int high){
    if(low<high){
        int mid = (low+high)/2 ;  
        mergeSort(a,low,mid) ;  
        mergeSort(a,mid+1,high) ;  
        merge(a,low,high) ;  
    }
}
void merge(int a[],int low ,int high){
    int tmp[high-low+1] ;  int mid = (low+high)/2 ; 
    int i = low,j= mid + 1 ;  
    int k = 0 ;  
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            tmp[k++] = a[i++] ; 
        }
        else{
            tmp[k++] = a[j++] ; 
        }
    }
    while(i<=mid)tmp[k++] = a[i++] ;  
    while(j<=high)tmp[k++] = a[j++] ;  
    for(int i = 0 ; i<high-low+1;++i){
        a[low+i] = tmp[i]  ; 
    }
} 