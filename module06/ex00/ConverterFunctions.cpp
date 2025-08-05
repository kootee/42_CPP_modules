#include "ConverterFunctions.hpp"
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iostream>

/* Helper functions */
static ConversionResult invalidResult()
{
	ConversionResult result;
	result.charStatus = INVALID;
	result.intStatus = INVALID;
	result.floatStatus = INVALID;
	result.doubleStatus = INVALID;
	return result;
}

template <typename T>
bool isWithinRange(const std::string &value)
{
    try
    {
        long double numericValue = std::stold(value);

        return numericValue >= static_cast<long double>(std::numeric_limits<T>::min()) &&
               numericValue <= static_cast<long double>(std::numeric_limits<T>::max());
    }
    catch (const std::exception &)
    {
        return false;
    }
}

ConversionResult ConverterFunctions::setPseudoLiterals(const std::string &to_convert)
{
    ConversionResult result;
	result.charStatus = INVALID;
	result.intStatus = INVALID;
	result.floatStatus = VALID;
	result.doubleStatus = VALID;

	if (to_convert.find("inf"))
	{
		result.floatValue = std::numeric_limits<float>::infinity();
		result.doubleValue = std::numeric_limits<double>::infinity();
		if (to_convert[0] == '-')
		{
			result.floatValue *= -1;
			result.doubleValue *= -1;
		}
	}
	else
	{
		result.floatValue = std::numeric_limits<float>::quiet_NaN();
		result.doubleValue = std::numeric_limits<double>::quiet_NaN();
	}
	return result;
}

/* Conversion functions */
template <typename T>
static void setCharValue(ConversionResult& result, T value)
{
	if (value >= std::numeric_limits<char>::min() &&
		value <= std::numeric_limits<char>::max())
	{
		result.charValue = static_cast<char>(value);
		result.charStatus = std::isprint(value) ? VALID : -1;
	}
	else
		result.charStatus = INVALID;
}

template <typename T>
static void setIntValue(ConversionResult& result, T value)
{
	if (value >= std::numeric_limits<int>::min() && 
		value <= std::numeric_limits<int>::max())
	{
    	result.intValue = static_cast<int>(value);
		result.intStatus = VALID;
	}
	else
		result.intStatus = INVALID;
}

template <typename T>
static void setFloatValue(ConversionResult& result, T value)
{
	if (value >= std::numeric_limits<float>::lowest() && 
		value <= std::numeric_limits<float>::max())
	{
    	result.floatValue = static_cast<float>(value);
		result.floatStatus = VALID;
	}
	else
		result.floatStatus = INVALID;
}

template <typename T>
static void setDoubleValue(ConversionResult& result, T value)
{
	if (value >= std::numeric_limits<double>::lowest() && 
		value <= std::numeric_limits<double>::max())
	{
    	result.doubleValue = static_cast<double>(value);
		result.doubleStatus = VALID;
	}
	else
		result.doubleStatus = INVALID;
}

ConversionResult ConverterFunctions::convertChar(const std::string &to_convert)
{
    ConversionResult result;
	try
	{
		result.charValue = to_convert[0];
		result.charStatus = VALID;
	}
	catch (const std::exception& e) 
	{ 
		std::cerr << "Unable to convert Char literal: " << e.what() << "\n";
		return invalidResult();
	}
	setIntValue<char>(result, result.charValue);
	setFloatValue<char>(result, result.charValue);
	setDoubleValue<char>(result, result.charValue);
    return result;
}

ConversionResult ConverterFunctions::convertInt(const std::string &to_convert)
{
	if (!isWithinRange<int>(to_convert))
		return invalidResult();

    ConversionResult result;
	try
	{
		result.intValue = std::stoi(to_convert);
		result.intStatus = VALID;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unable to convert Int literal: " << e.what() << "\n";
		return invalidResult();
	}
	setCharValue<int>(result, result.intValue);
	setFloatValue<int>(result, result.intValue);
	setDoubleValue<int>(result, result.intValue);
	return result;
}

ConversionResult ConverterFunctions::convertFloat(const std::string &to_convert)
{
	
	if (to_convert == "nanf" ||  
		to_convert == "+inff" ||
		to_convert == "-inff" )
		return (setPseudoLiterals(to_convert));
	
    if (!isWithinRange<float>(to_convert))
		return invalidResult();

	ConversionResult result;
    try
    {
        result.floatValue = std::stof(to_convert);
        result.floatStatus = VALID;
    }
    catch (const std::exception& e)
	{
		std::cerr << "Unable to convert Float literal: " << e.what() << "\n";
		return invalidResult();
	}
	setCharValue<float>(result, result.floatValue);
	setIntValue<float>(result, result.floatValue);
	setDoubleValue<float>(result, result.floatValue);
	return result;
}

ConversionResult ConverterFunctions::convertDouble(const std::string &to_convert)
{
	if (!isWithinRange<double>(to_convert))
		return invalidResult();

	if (to_convert == "nan" ||  
		to_convert == "+inf" ||
		to_convert == "-inf" )
	{
		return (setPseudoLiterals(to_convert));
	}
    ConversionResult result;
    try
    {
        result.doubleValue = std::stod(to_convert);
        result.doubleStatus = VALID;
    }
    catch (const std::exception& e)
    {
		std::cerr << "Unable to convert Float literal: " << e.what() << "\n";
		return invalidResult();
    }
	setCharValue<double>(result, result.doubleValue);
	setIntValue<double>(result, result.doubleValue);
	setFloatValue<double>(result, result.doubleValue);
	return result;
}