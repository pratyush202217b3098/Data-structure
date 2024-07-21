#include <stdio.h>

// Function to perform insertion sort
void insert(int a[], int n) {
    int i, j, temp;
    
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        
        // Move elements greater than temp to one position ahead of their current position
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        
        a[j + 1] = temp;
    }
}

// Function to print the array
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = { 5, 19, 3, 8, 12, 7, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Before sorting, array elements are:\n");
    printArr(a, n);
    
    insert(a, n);
    
    printf("After sorting, array elements are:\n");
    printArr(a, n);
    
    return 0;
}
