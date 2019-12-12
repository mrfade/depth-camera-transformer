#include "Transform.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::setRotation(double ang[])
{
    for (int i = 0; i < 3; i++)
        this->angles[i] = ang[i];
}

void Transform::setTranslation(double tr[])
{
    for (int i = 0; i < 3; i++)
        this->trans[i] = tr[i];
}
