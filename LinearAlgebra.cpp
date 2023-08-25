#include "LinearAlgebra.h"
#include <cassert>
#include <iostream>
#include <cmath>

Matrix LinearAlgebra::multiplyMatrices(Matrix m1, Matrix m2) {
	assert(m1.cols == m2.rows);
	Matrix newMatrix(m1.rows, m2.cols);
	double count = 0;
	for (int i = 0;i < m1.rows; ++i) {
		for (int j = 0;j < m2.cols; ++j) {
			for (int k = 0; k < m1.cols; ++k) {
				count += m1.matrix[i][k] * m2.matrix[k][j];
			}
			newMatrix.matrix[i][j] = count;
			count = 0;
		}
	}
	return newMatrix;
}

Matrix LinearAlgebra::addMatrices(Matrix m1, Matrix m2) {
	assert(m1.rows == m2.rows && m1.cols == m2.cols);

	Matrix newMatrix(m1.rows, m1.cols);

	for (int i = 0; i < m1.rows; ++i) {
		for (int j = 0; j < m1.cols; ++j) {
			newMatrix.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
	}

	return newMatrix;
}

Matrix LinearAlgebra::subtractMatrices(Matrix m1, Matrix m2) {
	assert(m1.rows == m2.rows && m1.cols == m2.cols);

	Matrix newMatrix(m1.rows, m1.cols);

	for (int i = 0; i < m1.rows; ++i) {
		for (int j = 0; j < m1.cols; ++j) {
			newMatrix.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
		}
	}

	return newMatrix;
 }

Matrix LinearAlgebra::scaleMatrix(Matrix m1, double scalar) {
	Matrix newMatrix(m1.rows, m1.cols);

	for (int i = 0; i < m1.rows; ++i) {
		for (int j = 0; j < m1.cols; ++j) {
			newMatrix.matrix[i][j] = scalar * m1.matrix[i][j];
		}
	}

	return newMatrix;
 }

Matrix LinearAlgebra::getIdentityMatrix(int dim) {
	Matrix newMatrix(dim);

	for (int i(0); i < dim; ++i) {
		newMatrix.matrix[i][i] = 1;
	}

	return newMatrix;
}


Matrix LinearAlgebra::getHouseHolderVector(Matrix colVect, int index) {
	std::cout << colVect.getVectorNorm(2);
	double sign;
	if (colVect.matrix[0][0] < 0) {
		sign = -1;
	}
	else {
		sign = 1;
	}

	return colVect;
}

//std::unique_ptr<Matrix[]> QRDecomposition() {
//
//}


