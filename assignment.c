#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 15000

void split(int a[], int low, int high);
void combine(int a[], int low, int mid, int high);

int main() {
    int a[MAX_SIZE], n, i, j, ch, temp;
    clock_t start, end;

    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                if (n <= 0 || n > MAX_SIZE) {
                    printf("Invalid array size. Please enter a value between 1 and %d.\n", MAX_SIZE);
                    continue;
                }

                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }

                start = clock();
                split(a, 0, n - 1);
                end = clock();

                printf("\nSorted array is: ");
                for (i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }

                printf("\n Time taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;

            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        a[i] = n - i; // Reverse sorted array for worst-case scenario
                    }

                    start = clock();
                    split(a, 0, n - 1);
                    end = clock();

                    printf("\n Time taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n += 1000;
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Please choose again.");
        }
    }
}

void split(int a[], int low, int high) {
    if (low >= high) return; // Explicit base case

    int mid = (low + high) / 2;
    split(a, low, mid);
    split(a, mid + 1, high);
    combine(a, low, mid, high);
}

void combine(int a[], int low, int mid, int high) {
    int c[MAX_SIZE], i, j, k;
    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            ++k;
            ++i;
        } else {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }

    if (i > mid) {
        while (j <= high) {
            c[k] = a[j];
            ++k;
            ++j;
        }
    }

    if (j > high) {
        while (i <= mid) {
            c[k] = a[i];
            ++k;
            ++i;
        }
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
