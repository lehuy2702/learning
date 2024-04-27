#include <stdio.h>
#include <stdlib.h>

void nhapmang(int *nums, int n) {
    for (int i = 0; i < n; i++){
    	printf("Nhap phan tu cho mang : "); 
    	scanf("%d", nums + i);
	}
}

int soBuocNhayToiThieu(int* nums, int n) {
    if (n == 1) 
        return 0;

    int soBuocNhay = 0; 
    int viTriMaxHienTai = 0;
    int viTriXaNhat = 0; 

    for (int i = 0; i < n - 1; i++) {
        if (viTriXaNhat <= i + nums[i]) {
    		viTriXaNhat = i + nums[i];
		}
        if (i == viTriMaxHienTai) { 
            soBuocNhay++; 
            viTriMaxHienTai = viTriXaNhat; 
        }
    }
    return soBuocNhay;
}

int main() {
    int n;
    printf("Nhap kich thuoc cua mang : "); 
    scanf("%d", &n);
    
    int *nums = (int*)malloc(n * sizeof(int));
    
    nhapmang(nums, n);

    int ketQua = soBuocNhayToiThieu(nums, n);
    
    printf("So buoc nhay toi thieu: %d\n", ketQua);


    free(nums);
    return 0;
}
