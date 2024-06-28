#include <stdio.h>

void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge until one of the arrays is exhausted
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    // Input size of both arrays
    printf("Enter size of array 1: ");
    scanf("%d", &size1);
    printf("Enter size of array 2: ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2], merged[size1 + size2];

    // Input elements of first array
    printf("Enter elements of array 1 in sorted order:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input elements of second array
    printf("Enter elements of array 2 in sorted order:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merge both arrays into merged array
    merge_sorted_arrays(arr1, size1, arr2, size2, merged);

    // Output the merged array
    printf("Merged array in sorted order:\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
