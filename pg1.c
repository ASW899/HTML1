#include <stdio.h> 
int main() 
{ 
int arr1[50]; 
int arr2[50]; 
int arr3[100]; 
int m, n, i, j, k = 0; 
printf("Enter the size of first array: "); 
scanf("%d", &m); 
printf("Enter the elements of first array: "); 
for (i = 0; i < m; i++) 
{ scanf("%d", &arr1[i]); } 
printf("Enter the size of second array: "); 
scanf("%d", &n); 
printf("Enter the elements of second array: "); 
for (j = 0; j < n; j++) 
{ scanf("%d", &arr2[j]); } 
i = 0; j = 0; 
//Merge two sorted arrays 
while (i < m && j < n) 
{ if (arr1[i] < arr2[j]) 
{ arr3[k] = arr1[i]; 
i++; } 
else 
{ arr3[k] = arr2[j];
 j++; } 
 k++; } 
 //Copy remaining elements of arr1 
 while (i < m) 
 { arr3[k] = arr1[i]; i++; k++; } 
 // Copy remaining elements of arr2 
 while (j < n) 
 { arr3[k] = arr2[j]; j++; 
 k++; } 
 printf("The merged sorted array: "); 
 for (k = 0; k < m + n; k++) 
 { printf("%d ", arr3[k]); } 
 return 0; 
 }
