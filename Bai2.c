#include <stdio.h>
#include <math.h>

int is_chinh_phuong(int num) {
    int sqrt_num = sqrt(num);
    return (sqrt_num * sqrt_num == num);
}
void dem_so_chinh_phuong(int n) {
    printf("Cac so chinh phuong nho hon %d la:\n", n);
    for (int i = 1; i < n; i++) {
        if (is_chinh_phuong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    dem_so_chinh_phuong(n);
    return 0;
}
