#include "string.h"
#include "FiguraException.h"

const char * FiguraException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
    return "No se puede crear el triangulo.";
}
