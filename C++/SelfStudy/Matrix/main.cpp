#include <stdio.h>
#include <algorithm>

using namespace std;

void initArray(int arr[5][5], int rowSize, int colSize) {
    int value = 1;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            arr[i][j] = value++;
        }
    }
}

void rotateMatrix(int arr[5][5], int radius, int rowSize, int colSize) {
    int temp[rowSize][colSize];
    
    // 임시 복사
    copy(&arr[0][0], &arr[0][0] + (rowSize * colSize), &temp[0][0]);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            
            // 각도별 다르게 계산
            switch (radius) {
                case 90:
                    temp[j][rowSize - 1 - i] = arr[i][j];
                    break;
                case 180:
                    temp[colSize - 1 - i][rowSize - 1 - j] = arr[i][j];
                    break;
                case 270:
                    temp[colSize - 1 - j][i] = arr[i][j];
                    break;
            }
        }
    }
    
    // 원배열에 덮어씌움
    copy(&temp[0][0], &temp[0][0] + 25, &arr[0][0]);
}

void printArray(int arr[5][5], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            // 예쁜 출력을 위해 stdio.h printf 사용
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    int arr[5][5];
    
    // 2차원 배열 초기화
    initArray(arr, 5, 5);
    
    // 원배열 출력
    printArray(arr, 5, 5);
    
    printf("---------------------------\n");
    
    // 90도 회전
    rotateMatrix(arr, 270, 5, 5);
    
    // 화면 출력
    printArray(arr, 5, 5);
    
    return 0;
}
