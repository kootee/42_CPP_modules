#include <string>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define VALID 4
#define INVALID 5

struct ConversionResult
{
    char charValue;
    int charStatus;

    int intValue;
    int intStatus;

    float floatValue;
    int floatStatus;

    double doubleValue;
    int doubleStatus;
};

class ConverterFunctions
{
	private:
		ConverterFunctions() = delete;
		~ConverterFunctions() = delete;
		ConverterFunctions(const ConverterFunctions &src) = delete;
		ConverterFunctions &operator=(const ConverterFunctions &src) = delete;

    public:
		static ConversionResult	convertChar(const std::string &to_convert);
		static ConversionResult	convertInt(const std::string &to_convert);
		static ConversionResult	convertFloat(const std::string &to_convert);
		static ConversionResult	convertDouble(const std::string &to_convert);
		static ConversionResult setPseudoLiterals(const std::string &to_convert);
};