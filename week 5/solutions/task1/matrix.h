#ifndef __MATRIX_H
#define __MATRIX_H


class Matrix {
private:
	int** mMatrix;
	size_t mSize;

	int** allocateMemory(size_t size) const;
	void copy(const Matrix&);
	void copyValue(int**);
	void deleteMemory();
public:
	Matrix();
	Matrix(size_t, int**);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	~Matrix();

	void print() const;

	int** getMatrix() const;
	size_t getSize() const;

	int getAt(size_t, size_t) const;
	Matrix add(const Matrix&) const;

	//bool equals(const Matrix&) const;
};

#endif