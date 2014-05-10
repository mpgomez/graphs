/*
 * graphException.cpp
 *
 *  Created on: 27 Apr 2014
 *      Author: dreamer
 */

#include "graphException.hpp"



graphException::graphException( int errorCode )
{
    //Note here that the base class (excepition) constructor will be automatically
    //called before executing the derived class contructor code (the code here)
    this->errorCode = errorCode;
}

const char* graphException::what() const throw()
{
  return this->errorDesc.c_str();
}

int graphException::getErrorCode() const
{
    return errorCode;
}

void graphException::setErrorCode( int errorCode )
{
    this->errorCode = errorCode;
}

