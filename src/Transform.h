/**
 * @file Transform.h
 * @author Enes Solak (enessolak99@gmail.com)
 * @date December, 2019
 */

class Transform
{
private:
    double angles[3];
    double trans[3];
    double transMatrix[4][4];

public:
    Transform();
    ~Transform();
    void setRotation(double[3]);
    void setTranslation(double[3]);
};