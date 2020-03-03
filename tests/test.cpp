#include <gtest/gtest.h>

extern "C" {
    #include "header.h"
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// CREATING SECTION

TEST(CreatingMatrix, RowsIncorrect) {
    size_t rows = 0;
    size_t cols = 5;
    int **matrix = GetMatrixMemory(rows, cols);

    EXPECT_EQ(matrix, nullptr);
}

TEST(CreatingMatrix, ColsIncorrect) {
    size_t rows = 2;
    size_t cols = 0;
    int **matrix = GetMatrixMemory(rows, cols);

    EXPECT_EQ(matrix, nullptr);
}

TEST(CreatingMatrix, CorrectSizes) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = GetMatrixMemory(rows, cols);

    ASSERT_TRUE(matrix);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            EXPECT_EQ(matrix[i][j], 0);
        }
    }

    FreeMatrixMemory(matrix, rows);
}

// FREEING MEMORY SECTION

TEST(FreeingMatrix, FreeingNonexistingMatrix) {
    size_t rows = 2;
    EXPECT_TRUE(FreeMatrixMemory(nullptr, rows));
}

TEST(FreeingMatrix, FreeingExistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = GetMatrixMemory(rows, cols);

    ASSERT_TRUE(matrix);

    EXPECT_FALSE(FreeMatrixMemory(matrix, rows));
}

TEST(FreeingMatrix, FreeingNoDataMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = (int **) calloc(rows, sizeof(int*));

    ASSERT_TRUE(matrix);

    for (size_t i = 0; i < rows; i++) {
        matrix[i] = nullptr;
    }

    EXPECT_FALSE(FreeMatrixMemory(matrix, rows));
}

// MATRIX READING AND PRINTING SECTION

TEST(MatrixActions, ReadingNonexistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;

    EXPECT_TRUE(ReadMatrix(nullptr, rows, cols));
}

/*
TEST(MatrixActions, ReadingExistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = GetMatrixMemory(rows, cols);

    ASSERT_TRUE(matrix);

    EXPECT_FALSE(ReadMatrix(matrix, rows, cols));

}*/

TEST(MatrixActions, PrintingNonexistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;

    EXPECT_TRUE(PrintMatrix(nullptr, rows, cols));
}

TEST(MatrixActions, PrintingExistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = GetMatrixMemory(rows, cols);

    ASSERT_TRUE(matrix);

    EXPECT_FALSE(PrintMatrix(matrix, rows, cols));
    FreeMatrixMemory(matrix, rows);
}