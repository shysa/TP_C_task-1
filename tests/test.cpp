#include <gtest/gtest.h>

extern "C" {
    #include "include.h"
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// CREATING SECTION

TEST(CreatingMatrix, RowsIncorrect) {
    size_t rows = 0;
    size_t cols = 5;
    int **matrix = get_matrix_memory(rows, cols);

    EXPECT_EQ(matrix, nullptr);
}

TEST(CreatingMatrix, ColsIncorrect) {
    size_t rows = 2;
    size_t cols = 0;
    int **matrix = get_matrix_memory(rows, cols);

    EXPECT_EQ(matrix, nullptr);
}

TEST(CreatingMatrix, CorrectSizes) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = get_matrix_memory(rows, cols);

    ASSERT_TRUE(matrix);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            EXPECT_EQ(matrix[i][j], 0);
        }
    }

    free_matrix_memory(matrix, rows);
}

// FREEING MEMORY SECTION

TEST(FreeingMatrix, FreeingNonexistingMatrix) {
    size_t rows = 2;
    EXPECT_TRUE(free_matrix_memory(nullptr, rows));
}

TEST(FreeingMatrix, FreeingExistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = get_matrix_memory(rows, cols);

    ASSERT_TRUE(matrix);

    EXPECT_FALSE(free_matrix_memory(matrix, rows));
}

TEST(FreeingMatrix, FreeingNoDataMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = (int **) calloc(rows, sizeof(int*));

    ASSERT_TRUE(matrix);

    for (size_t i = 0; i < rows; i++) {
        matrix[i] = nullptr;
    }

    EXPECT_FALSE(free_matrix_memory(matrix, rows));
}

// MATRIX READING AND PRINTING SECTION

TEST(MatrixActions, ReadingNonexistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;

    EXPECT_TRUE(read_matrix(stdin, nullptr, rows, cols));
}

TEST(MatrixActions, PrintingNonexistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;

    EXPECT_TRUE(print_matrix(nullptr, rows, cols));
}

TEST(MatrixActions, PrintingExistingMatrix) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = get_matrix_memory(rows, cols);

    ASSERT_TRUE(matrix);

    EXPECT_FALSE(print_matrix(matrix, rows, cols));
    free_matrix_memory(matrix, rows);
}

TEST(MatrixActions, ReadCorrectData) {
    size_t rows = 3;
    size_t cols = 5;

    const int data[15] = {
            1, 2, 3, 4, 5,
            10, 20, 30, 40, 50,
            100, 200, 300, 400, 500
    };

    FILE * file = fopen("correct_data_test.txt", "w+");
    for (int value : data) {
        fprintf(file, "%d", value);
    }
    fclose(file);

    file = fopen("correct_data_test.txt", "r");

    int **matrix = get_matrix_memory(rows, cols);
    ASSERT_TRUE(matrix);

    EXPECT_FALSE(read_matrix(file, matrix, rows, cols));

    free_matrix_memory(matrix, rows);
    fclose(file);

}

TEST(MatrixActions, ReadIncorrectData) {
    size_t rows = 3;
    size_t cols = 3;

    const char data[10] = {
            'a', 'b', 'c',
            'd', 'e', 'f',
            'g', 'i', 'j'
    };

    FILE * file = fopen("correct_data_test.txt", "w+");
    for (int value : data) {
        fprintf(file, "%c", value);
    }
    fclose(file);

    file = fopen("correct_data_test.txt", "r");

    int **matrix = get_matrix_memory(rows, cols);
    ASSERT_TRUE(matrix);

    EXPECT_TRUE(read_matrix(file, matrix, rows, cols));
    fclose(file);
}

// CREATING STRUCTURES SECTION

TEST(ProgramActions, CreatingResult) {
    size_t rows = 2;
    size_t cols = 5;
    int **matrix = nullptr;

    int *** result = forming_matrix((const int **) matrix, rows, cols);
    EXPECT_EQ(result, nullptr);
}

TEST(ProgramActions, CreatingMatrixes) {
    size_t rows = 3;
    size_t cols = 5;

    const int data[15] = {
            1, 2, 3, 4, 5,
            10, 20, 30, 40, 50,
            100, 200, 300, 400, 500
    };

    FILE * file = fopen("correct_data_test.txt", "w+");
    for (int value : data) {
        fprintf(file, "%d", value);
    }
    fclose(file);

    file = fopen("correct_data_test.txt", "r");

    int **matrix = get_matrix_memory(rows, cols);
    ASSERT_TRUE(matrix);
    read_matrix(file, matrix, rows, cols);

    int *** result = forming_matrix((const int **) matrix, rows, cols);
    ASSERT_TRUE(result);

    for (size_t cur_matrix = 0; cur_matrix < NUM_MATRIXES; cur_matrix++) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = cur_matrix, result_j = 0; j < cols; j+=NUM_MATRIXES, result_j++) {
                EXPECT_EQ(result[cur_matrix][i][result_j], matrix[i][j]);
            }
        }
    }

    free_matrix_memory(matrix, rows);
    free_result(result, rows);
    fclose(file);
}