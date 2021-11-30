#ifndef FIGURAEXCEPTION_H
#define FIGURAEXCEPTION_H
#include "exception"
#include <string>

using namespace std;

class FiguraException : public exception
{
public:
    const char * what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
};

#endif // FIGURAEXCEPTION_H
