/**
 * @file Transform.h
 * @author Enes Solak (enessolak99@gmail.com)
 * @date December, 2019
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform
{
private:
    double angles[3];
    double trans[3];
    double transMatrix[4][4];

public:
    Transform();
    ~Transform();
    void setRotation(double[]);
    void setTranslation(double[]);
};

#endif TRANSFORM_H
