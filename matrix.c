#include <stdio.h>
#include <stdlib.h>

// 행렬 구조체
typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

int mul_success = 1;

// 행렬 생성 함수
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}
// 행렬 소멸 함수
void freeMatrix(Matrix mat) { 
    for (int i = 0; i < mat.rows; i++) { 
        free(mat.data[i]);
    }
        free(mat.data);
}
// 행렬 입력 함수
void inputMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            scanf("%d", &mat.data[i][j]);
        }
    }
}

// 행렬 출력 함수
void print_Matrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

// 행렬 덧셈 함수
Matrix addition_matrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

// 행렬 뺄셈 함수
Matrix subtraction_matrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    return result;
}

// 행렬 전치 함수
Matrix transpose_matrix(Matrix mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.cols; i++) {
        for (int j = 0; j < mat.rows; j++) {
            result.data[i][j] = mat.data[j][i];
        }
    }
    return result;
}

// 행렬 곱셈 함수
Matrix multiply_matrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat2.cols);
    if (mat1.cols != mat2.rows) {
        printf("error\n");
        mul_success=0; 
        return result;
    }
    mul_success = 1;
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j];
            result.data[i][j] += mat1.data[i][k] * mat2.data[k][j]; 
        }
    }
}
return result;
}

int main() {
int rows, cols;
printf("Enter the number of rows and columns: ");
scanf("%d %d", &rows, &cols);

// 행렬 A 생성
printf("Enter the elements of matrix A:\n");
Matrix A = createMatrix(rows, cols);
inputMatrix(A);

// 행렬 B 생성
printf("Enter the elements of matrix B:\n");
Matrix B = createMatrix(rows, cols);
inputMatrix(B);

// 행렬 A 출력
printf("Matrix A:\n");
print_Matrix(A);

// 행렬 B 출력
printf("Matrix B:\n");
print_Matrix(B);

// 덧셈
printf("Addition of A and B:\n");
Matrix C = addition_matrix(A, B);
print_Matrix(C); 

// 뺄셈
printf("Subtraction of A and B:\n");
Matrix D = subtraction_matrix(A, B);
print_Matrix(D);

// 전치
printf("Transpose of matrix A:\n");
Matrix T = transpose_matrix(A);
print_Matrix(T);

// 곱셈
printf("Multiplication of A and B:\n");
Matrix E = multiply_matrix(A, B);
if(mul_success==1)
print_Matrix(E);

// 할당된 메모리 해제
freeMatrix(A);
freeMatrix(B);
freeMatrix(C);
freeMatrix(D);
freeMatrix(T);
freeMatrix(E);

printf("[----- [Taehyung Kim] [2020039024] -----]");
return 0;
}