#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
	matrix = std::make_unique<std::unique_ptr<double[]>[]>(rows);

	for (int i = 0; i < rows; ++i) {
		matrix[i] = std::make_unique<double[]>(cols);
	}
}

Matrix::Matrix(int dim) : rows(dim), cols(dim) {
	matrix = std::make_unique<std::unique_ptr<double[]>[]>(dim);

	for (int i = 0; i < dim; ++i) {
		matrix[i] = std::make_unique<double[]>(dim);
	}
}

Matrix::Matrix(std::unique_ptr<std::unique_ptr<double[]>[]> matrix, int rows, int cols) : rows(rows), cols(cols) {
	this->matrix = std::move(matrix);
}

void Matrix::print(int precision) const{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << std::fixed << std::setprecision(precision) <<  matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::generateData(double bottom_range, double top_range) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = (double)rand() / RAND_MAX * (top_range - bottom_range) + bottom_range;
		}
	}
}

void Matrix::inputData() {
	for (int i(0);i < rows; ++i) {
		for (int j(0); j < cols; ++j) {
			std::cout << "Enter the value you want to input for (row " << i << ", col " << j << ") ";
			std::cin >> matrix[i][j];
		}
	}
	std::cout << std::endl;
}

Matrix Matrix::transpose() const{
	std::unique_ptr<std::unique_ptr<double[]>[]> newMatrix = std::make_unique<std::unique_ptr<double[]>[]>(cols);

	for(int i = 0; i < cols; ++i){
		newMatrix[i] = std::make_unique<double[]>(rows);

	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			newMatrix[j][i] = matrix[i][j];
		}
	}

	return Matrix(std::move(newMatrix), cols, rows);
}

int Matrix::getNumCols() const { return cols; }

int Matrix::getNumRows() const { return rows; }

bool Matrix::isSquare() const { return rows == cols; }

Matrix Matrix::getColumn(int columnIndex) {
	std::unique_ptr<std::unique_ptr<double[]>[]> newMatrix = std::make_unique<std::unique_ptr<double[]>[]>(rows);

	for (int i = 0; i < rows; ++i) {
		newMatrix[i] = std::make_unique<double[]>(1);
	}

	for (int i = 0; i < rows; ++i) {;
		newMatrix[i][0] = matrix[i][columnIndex];
	}

	return Matrix(std::move(newMatrix), rows, 1);
}

Matrix Matrix::getRow(int rowIndex) {
	std::unique_ptr<std::unique_ptr<double[]>[]> newMatrix = std::make_unique<std::unique_ptr<double[]>[]>(1);

	newMatrix[0] = std::make_unique<double[]>(cols);

	for (int i = 0; i < cols; ++i) {
		newMatrix[0][i] = matrix[rowIndex][i];
	}

	return Matrix(std::move(newMatrix), 1, cols);
}

double Matrix::getVectorNorm( double p) {
	Matrix temp(std::move(matrix), rows, cols);
	if (cols > 1) {
		temp = temp.transpose();
	}

	assert(p >= 1 && temp.cols == 1);

	double underRoot = 0;

	for (int i(0); i < temp.rows; ++i) {
		underRoot += pow(temp.matrix[i][0], p);
	}

	return pow(underRoot, 1 / p);
}



