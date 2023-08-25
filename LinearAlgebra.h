#pragma once

#include "Matrix.h"

class LinearAlgebra
{
private:
public:
	static Matrix multiplyMatrices(Matrix m1, Matrix m2);

	static Matrix addMatrices(Matrix m1, Matrix m2);

	static Matrix subtractMatrices(Matrix m1, Matrix m2);

	static Matrix scaleMatrix(Matrix m1, double scalar);

	static Matrix getIdentityMatrix(int dim);

	static Matrix getHouseHolderVector(Matrix colVect, int index);

	static std::unique_ptr<Matrix[]> QRDecomposition(Matrix A);
};

