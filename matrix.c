#include <stdio.h>
#include <stdlib.h>

// 행렬 구조체
typedef struct {
    int **data; // 행렬의 데이터
    int rows;   // 행의 수
    int cols;   // 열의 수
} Matrix;

int mul_success = 1;

// 행렬 생성 함수
Matrix createMatrix(int rows, int cols) {
    Matrix mat; // 구조체 변수 선언
    mat.rows = rows; // 행렬의 행을 초기화
    mat.cols = cols; // 행렬의 열을 초기화
    mat.data = (int **)malloc(rows * sizeof(int *)); // 행렬의 데이터에 동적 할당
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int *)malloc(cols * sizeof(int)); // 행렬의 요소에 동적 할당
    }
    return mat; // 구조체를 리턴 받음
}
// 행렬 소멸 함수
void freeMatrix(Matrix mat) { 
    for (int i = 0; i < mat.rows; i++) { 
        free(mat.data[i]); // 행렬 요소의 메모리 해제
    }
        free(mat.data); // 행렬 데이터 메모리 해제
}
// 행렬 입력 함수
void inputMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) { // 행과 열의 수 만큼
            scanf("%d", &mat.data[i][j]); // 행렬을 입력 받음
        }
    }
}

// 행렬 출력 함수
void print_Matrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]); // 입력 받은 행렬을 출력 해줌
        }
        printf("\n");
    }
}

// 행렬 덧셈 함수
Matrix addition_matrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) { // 입력 받은 행렬의 행과 열의 개수 만큼 반복한다
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j]; // 행렬의 합을 result에 저장한다
        }
    }
    return result;
}

// 행렬 뺄셈 함수
Matrix subtraction_matrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) { // 입력 받은 행렬의 행과 열의 개수 만큼 반복한다
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j]; // 행렬의 차를 result에 저장한다
        }
    }
    return result;
}

// 행렬 전치 함수
Matrix transpose_matrix(Matrix mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.cols; i++) {
        for (int j = 0; j < mat.rows; j++) { // 열과 행의 수 만큼 반복
            result.data[i][j] = mat.data[j][i]; // 행과 열을 전치 시켜서 result에 저장
        }
    }
    return result;
}

// 행렬 곱셈 함수
Matrix multiply_matrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat2.cols);
    if (mat1.cols != mat2.rows) {
        printf("error\n");
        mul_success=0; // 행렬 1의 열 개수와 행렬 2의 행 개수가 같지 않으면 error를 출력하고 mul_success 변수에 0 저장
        return result;
    }
    mul_success = 1; // 그렇지 않으면 mul_success 변수값을 1로 유지한다
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) { // mat1의 행과 mat2의 열만큼 반복한다
            result.data[i][j] = 0; // 행렬 초기화
            for (int k = 0; k < mat1.cols; k++) { // mat1의 열 개수 만큼 반복
                result.data[i][j];
            result.data[i][j] += mat1.data[i][k] * mat2.data[k][j]; // result행렬에 행렬 mat1과 mat2의 곱을 저장한다
        }
    }
}
return result; // result 반환
}

int main() {
int rows, cols; // 행 열 변수 선언
printf("Enter the number of rows and columns: ");
scanf("%d %d", &rows, &cols); // 행렬의 행과 열의 개수를 입력 받음

// 행렬 A 생성
printf("Enter the elements of matrix A:\n");
Matrix A = createMatrix(rows, cols); // A행렬 동적 할당
inputMatrix(A);

// 행렬 B 생성
printf("Enter the elements of matrix B:\n");
Matrix B = createMatrix(rows, cols); // B행렬 동적 할당
inputMatrix(B);

// 행렬 A 출력
printf("Matrix A:\n");
print_Matrix(A); // A행렬 출력

// 행렬 B 출력
printf("Matrix B:\n");
print_Matrix(B); // B행렬 출력

// 덧셈
printf("Addition of A and B:\n");
Matrix C = addition_matrix(A, B); // A행렬과 B행렬의 합을 C행렬에 저장
print_Matrix(C); // C행렬 출력

// 뺄셈
printf("Subtraction of A and B:\n");
Matrix D = subtraction_matrix(A, B); // A행렬과 B행렬의 차를 D행렬에 저장
print_Matrix(D); // D행렬 출력

// 전치
printf("Transpose of matrix A:\n");
Matrix T = transpose_matrix(A); // A의 전치행렬을 T행렬에 저장
print_Matrix(T); // T행렬 출력

// 곱셈
printf("Multiplication of A and B:\n");
Matrix E = multiply_matrix(A, B); // A행렬과 B행렬의 곱을 E행렬에 저장
if(mul_success==1) // mul_success 변수 값이 1로 유지된다면
print_Matrix(E); // E행렬 출력

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