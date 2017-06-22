#include "FieldBilder.h"


FieldBilder::FieldBilder(const eFieldBilderType & fieldBilderType) : fieldBilderType_(fieldBilderType)
{
}


void FieldBilder::setFieldBilderType(const eFieldBilderType & fieldBilderType)
{
	fieldBilderType_ = fieldBilderType;
}

eFieldBilderType FieldBilder::getFieldBilderType() const
{
	return fieldBilderType_;
}

FieldBilder::~FieldBilder()
{
}


