#include <NotImplementedException.hpp>

const int NotImplementedException::MAX_MESSAGE_LEN = 1023;

NotImplementedException::NotImplementedException(const char* location, const char* func_name) : exception()
{
	what_message = new char[MAX_MESSAGE_LEN];
	snprintf(what_message, MAX_MESSAGE_LEN, "%s::%s function not yet implemented", location, func_name);
}

NotImplementedException::~NotImplementedException()
{
	delete[] what_message;
}

const char* NotImplementedException::what()
{
	return what_message;
}