#pragma once

#include <memory>

class Matrix
{
private:
	int rows;
	int cols;
	std::unique_ptr<std::unique_ptr<double[]>[]> matrix;

public:
	Matrix() = delete;

	Matrix(int rows, int cols);

	Matrix(int dim);

	Matrix(std::unique_ptr<std::unique_ptr<double[]>[]> matrix, int rows, int cols);


	/** Prints out the matrix
	*@param precision is how many decimals to print 
	* 
	*/
	void print(int precision) const;

	/** Generates data in all positions of the matrix in between the specified range
	*@param bottom_range is the bottom of the range
	*@param top_range is the top of the range
	*/
	void generateData(double bottom_range, double top_range);

	void inputData();

	int getNumRows() const;

	int getNumCols() const;

	Matrix getColumn(int columnIndex);

	Matrix getRow(int rowIndex);

	double getVectorNorm(double p);

	Matrix transpose() const;

	bool isSquare() const;

	friend class LinearAlgebra;
};

