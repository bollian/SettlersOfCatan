#ifndef SETTLERS_OF_CATAN_NOTIMPLEMENTEDEXCEPTION_H_
#define SETTLERS_OF_CATAN_NOTIMPLEMENTEDEXCEPTION_H_

#include <stdexcept>

using namespace std;

class NotImplementedException : public exception
{
public:
	NotImplementedException(const char* location, const char* func_name);
	~NotImplementedException();
	
	virtual const char* what();
	
private:
	static const int MAX_MESSAGE_LEN;
	char* what_message;
	
};

#endif // SETTLERS_OF_CATAN_NOTIMPLEMENTEDEXCEPTION_H_