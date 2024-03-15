#include <exception>


namespace LinAlgLib {
	//The exception to use for errors caused by incompatible matrix dimensions
	class DimensionException : public std::exception {
		char * msg;
	public:
		DimensionException() {
			msg = "Incompatible matrix dimensions";
		}
		DimensionException(char * msg) {
			msg = msg;
		}
		char* what() {
			return msg;
		}
	};
}