/* 
 * File:   tostring.h
 * Author: All-PC
 *
 * Created on 8 de diciembre de 2016, 2:00
 */

#ifndef TOSTRING_H
#define	TOSTRING_H
#include <string>
#include <sstream>
#include <memory>
template <typename T>
std::string to_string(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

#endif	/* TOSTRING_H */

