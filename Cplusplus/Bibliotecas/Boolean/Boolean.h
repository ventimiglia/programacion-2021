#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

class Boolean
{
private:
    int _value;

public:
    Boolean();
    Boolean(int x);
    int getValue();
    void setValue(int newValue);
    Boolean _and(Boolean value);
    Boolean _or(Boolean value);
    void _not();
};

#endif // BOOLEAN_H_INCLUDED
