// First algorithm (non-recursive)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 1; i < n; i += 2) {
        if (array[i] > array[i - 1]) {
            if (array[i] < array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        } else {
            int temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
            if (array[i] < array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

// Second algorithm (recursive)
#include <stdio.h>
#include <stdlib.h>

void wigglesort(int arr[], int n) {
    if (n <= 1)
        return;
    int mid = n / 2;
    wigglesort(arr, mid);
    wigglesort(arr + mid, n - mid);
    for (int i = 0; i < mid; i++) {
        int j = i + mid;
        if (arr[i] < arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() { 
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    wigglesort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    return 0;
}
