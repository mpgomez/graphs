/*
 * graphException.h
 *
 *  Created on: 27 Apr 2014
 *      Author: dreamer
 */

#ifndef GRAPHEXCEPTION_H_
#define GRAPHEXCEPTION_H_

#include <exception>
#include <string>

class graphException : public std::exception
{
protected:
    int errorCode = 0;
    std::string errorDesc = "Default error";

public:
    virtual ~graphException() throw() {};
    graphException( int errorCode = 0 );
    virtual const char* what() const throw();

    int getErrorCode() const;
    void setErrorCode(int errorCode = 0);
};
#endif /* GRAPHEXCEPTION_H_ */
