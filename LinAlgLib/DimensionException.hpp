#include <exception>


namespace LinAlgLib {
	//The exception to use for errors caused by incompatible matrix dimensions
	class DimensionException : public std::exception {
		char * message;
	public:
		DimensionException() {
			message = "Incompatible matrix dimensions";
		}
		DimensionException(char * msg) {
			message = msg;
		}
		DimensionException(const DimensionException& old) {
			strcpy(message, old.message);
		}
		~DimensionException() {

		}
		char* what() {
			return message;
		}
	};
}