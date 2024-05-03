#include <stdio.h>

// Hàm sắp xếp mảng theo thuật toán Insertion Sort
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Hàm sắp xếp mảng theo thuật toán Selection Sort
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Hàm sắp xếp mảng theo thuật toán Bubble Sort
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Hàm sắp xếp mảng theo thuật toán Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Hàm in ra mảng
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap %d so nguyen: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Lựa chọn thuật toán sắp xếp
    int choice;
    printf("Chon thu tu sap xep: \n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Merge Sort\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertion_sort(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            break;
        case 3:
            bubble_sort(arr, n);
            break;
        case 4:
            merge_sort(arr, 0, n - 1);
            break;
        default:
            printf("Lua chon khong hop le.\n");
            return 1;
    }

    printf("Mang sau khi sap xep: ");
    print_array(arr, n);

    return 0;
}
