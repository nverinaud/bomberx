#include "case.h"

Case::Case()
{
}

Case::Case(TypeDeCase _typeDeCase)
{
    this->setTypeDeCase(_typeDeCase);
}

TypeDeCase Case::getTypeDeCase()
{
    return this->typeDeCase;
}

void Case::setTypeDeCase(TypeDeCase _typeDeCase)
{
    this->typeDeCase = _typeDeCase;
}
