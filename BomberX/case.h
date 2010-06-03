#ifndef CASE_H
#define CASE_H

#include "position.h"
#include "base.h"

class Case : public Position
{
public:
    Case(TypeDeCase _typeDeCase);

    TypeDeCase getTypeDeCase();
    void setTypeDeCase(TypeDeCase _typeDeCase);

private:
    TypeDeCase typeDeCase;

};

#endif // CASE_H
