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
    Boolean _and(const Boolean value) const;
    Boolean _or (const Boolean value) const ;
    Boolean _not();
    Boolean operator + (const Boolean & b) const;
    Boolean operator * (const Boolean & b) const;
};

#endif // BOOLEAN_H_INCLUDED
