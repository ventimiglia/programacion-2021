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

void setValue(int newValue)
{
    this->_value = newValue;
}

Boolean Boolean::_and(Boolean value)
{
    Boolean andResult = this->_value * value.getValue();

    return andResult;
}

Boolean Boolean::_or(Boolean value)
{
    Boolean orResult = this->_value + value.getValue();

    return orResult;
}

Boolean Boolean::_not()
{
    Boolean result;
    if(this->_value == 1)
    {
        result = 0
    }
    else
    {
        result = 1
    }

    return result

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
