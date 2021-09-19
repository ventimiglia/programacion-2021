#include "Boolean.h"

Boolean::Boolean()
{
    this->_value = 0;
}

Boolean::Boolean(int x)
{
    this->_value=x;
}

int Boolean::getValue()
{
    return this->_value;
}

Boolean Boolean::_and(const Boolean b) const
{
    if(this->_value && b._value)
    {
        return Boolean(1);
    }

    return Boolean(0);
}

Boolean Boolean::_or(const Boolean b) const
{
    if(this->_value || b._value)
    {
        return Boolean(1);
    }

    return Boolean(0);
}

Boolean Boolean::_not()
{
    Boolean result;
    if(this->_value == 1)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }

    return Boolean(result);
}
//
//Boolean operator *(int localValue, Boolean parameterValue)
//{
//    Boolean result = parameterValue._value * localValue;
//    return result;
//}
//
//Boolean operator +(int localValue, Boolean parameterValue)
//{
//    Boolean result = parameterValue._value + localValue;
//    return result;
//}
//
//

Boolean Boolean::operator + (const Boolean & b) const
{
    if(this->_value || b._value)
    {
        return Boolean(1);
    }

    return Boolean(0);
}

Boolean Boolean::operator * (const Boolean & b) const
{
    if(this->_value && b._value)
    {
        return Boolean(1);
    }

    return Boolean(0);
}
