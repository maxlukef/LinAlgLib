#include <vector>

namespace LinAlgLib {
	template <class T> class Matrix {
		
		//The matrix data. Stored in vector all the time for now, in the future only for cases where size is not known at compile time.
		std::vector<std::vector<T>> Data;

		//The number of rows in the matrix, i.e. the first dimension of Data.
		int Rows;

		//The number of columns in the matrix, i.e. the second dimension of Data.
		int Cols;
	public:

		//Constructors:-----------------------------------------------------------------------------------------------------------------------------
		//Constructor that initializes values to zero
		Matrix<T>(int rows, int cols) {
			Data = std::vector<std::vector<T>>();
			Rows = rows;
			Cols = cols;
			for (int i = 0; i < rows; i++) {
				Data.push_back(std::vector<T>());
				for (int j = 0; j < cols; j++) {
					Data[i].push_back(0);
				}
			}
		}

		//Constructor that takes rows, cols, and data
		Matrix<T>(int rows, int cols, std::vector<std::vector<T>>& data) {
			if (data.size() != rows) {
				//throw something
			}
			for (int i = 0; i < rows; i++) {
				if (data[i].size() != cols) {
					//throw something
				}
			}
			Rows = rows;
			Cols = cols;
			Data = data;
		}

		//Simple getters:-----------------------------------------------------------------------------------------------------------------------------
		T get_element(int row, int col) {
			if (row < 0 || row >= this->Rows) {
				//throw some kind of element out of bounds exception
			}
			if (col < 0 || col >= this->Cols) {
				//throw some kind of element out of bounds exception
			}
			return Data[row][col];
		}

		int get_rows() {
			return Rows;
		}

		int get_cols() {
			return Cols;
		}

		//Simple setters:------------------------------------------------------------------------------------------------------------------------------

		void set_element(int row, int col, T new_val) {
			if (row < 0 || row >= Rows) {
				//throw something
			}
			if (col < 0 || col >= Cols) {
				//throw something
			}
			Data[row][col] = new_val;
		}

		//Operators:-----------------------------------------------------------------------------------------------------------------------------------

		Matrix<T> operator+(Matrix<T> const& other) {
			if (other.Rows != Rows || other.Cols != Cols) {
				//throw something - make mismatched dimension exception
			}
			Matrix<T> new_matrix(Rows, Cols);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					new_matrix.Data[i][j] = Data[i][j] + other->Data[i][j];
				}
			}
			return new_matrix;
		}

		Matrix<T> operator-(Matrix<T> const& other) {
			if (other.Rows != Rows || other.Cols != Cols) {
				//throw something - make mismatched dimension exception
			}
			Matrix<T> new_matrix(Rows, Cols);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					new_matrix.Data[i][j] = Data[i][j] - other->Data[i][j];
				}
			}
			return new_matrix;
		}

		Matrix<T> operator*(Matrix<T> const& rhs) {
			if (rhs.Rows != Cols) {
				//throw something - make mismatched dimension exception
			}
			Matrix<T> new_matrix(Rows, rhs.Cols);
			for (int i = 0; i < new_matrix.get_rows(); i++) {
				for (int j = 0; j < new_matrix.get_cols(); j++) {
					for (int k = 0; k < new_matrix.get_cols(); k++) {
						new_matrix.Data[i][j] += Data[i][k] * rhs.Data[k][j];
					}
				}
			}
		}
	};
}