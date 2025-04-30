#include "matrix.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void CreateMatrix(int rows, int cols, Matrix *M) {
    M->rows = rows;
    M->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M->data[i][j] = 0;
        }
    }
}

int GetRows(Matrix M) {
    return M.rows;
}

int GetCols(Matrix M) {
    return M.cols;
}

float *GetElement(Matrix *M, int row, int col) {
    if (row >= M->rows || col >= M->cols || row < 0 || col < 0) return NULL;
    return &(M->data[row][col]);
}

bool SetElement(Matrix *M, int row, int col, float value) {
    if (row >= 0 && row < M->rows && col >= 0 && col < M->cols) {
        M->data[row][col] = value;
        return true;
    }
    return false;
}

void ReadMatrix(Matrix *M) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    while (rows <= 0 || cols <= 0 || rows >= MAX_ROWS || cols >= MAX_COLS) {
        scanf("%d %d", &rows, &cols);
    }
    CreateMatrix(rows, cols, M);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &(M->data[i][j]));
        }
    }
}

void PrintMatrix(Matrix M) {
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            printf("%.2f", M.data[i][j]);
            if (j < M.cols - 1) {
                printf(" ");
            }
        }
        printf(" \n");
    }
}

bool IsSquare(Matrix M) {
    return M.rows == M.cols;
}

bool IsSymmetric(Matrix M) {
    if (!IsSquare(M)) return false;
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            if (M.data[i][j] != M.data[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool IsDiagonallyDominant(Matrix M) {
    float sum;
    for (int i = 0; i < M.rows; i++) {
        sum = 0;
        for (int j = 0; j < M.cols; j++) {
            if (j != i) {
                sum += fabs(M.data[i][j]);
            }
        }
        if (fabs(M.data[i][i]) <= sum) {
            return false;
        }
    }
    return true;
}

Matrix *MultiplyMatrix(Matrix M1, Matrix M2) {
    if (M1.cols != M2.rows) return NULL;
    Matrix *result = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M2.cols, result);
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M2.cols; j++) {
            float sum = 0;
            for (int k = 0; k < M1.cols; k++) {
                sum += M1.data[i][k] * M2.data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

Matrix *AddMatrix(Matrix M1, Matrix M2) {
    if (M1.rows != M2.rows || M1.cols != M2.cols) return NULL;
    Matrix *result = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M1.cols, result);
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            result->data[i][j] = M1.data[i][j] + M2.data[i][j];
        }
    }
    return result;
}

Matrix *SubtractMatrix(Matrix M1, Matrix M2) {
    if (M1.rows != M2.rows || M1.cols != M2.cols) return NULL;
    Matrix *result = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M1.cols, result);
    for (int i = 0; i < M1.rows; i++) {
        for (int j = 0; j < M1.cols; j++) {
            result->data[i][j] = M1.data[i][j] - M2.data[i][j];
        }
    }
    return result;
}

Matrix MultiplyScalar(Matrix M, float scalar) {
    Matrix result;
    CreateMatrix(M.rows, M.cols, &result);
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            result.data[i][j] = M.data[i][j] * scalar;
        }
    }
    return result;
}

Matrix GetTranspose(Matrix M) {
    Matrix result;
    CreateMatrix(M.cols, M.rows, &result);
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.cols; j++) {
            result.data[j][i] = M.data[i][j];
        }
    }
    return result;
}