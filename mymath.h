/*
 * Created on January 11, 2012, 1:52 PM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef MYMATH_H
#define	MYMATH_H

#include <math.h>

class cVector2D
{
    public:

        float   x;
        float   y;

        cVector2D() {}

        cVector2D(float r, float s)
        {
            x = r;
            y = s;
        }

        cVector2D& set(float r, float s)
        {
            x = r;
            y = s;
            return (*this);
        }

        float& operator [](long k)
        {
            return ((&x)[k]);
        }

        const float& operator [](long k) const
        {
            return ((&x)[k]);
        }

        cVector2D& operator +=(const cVector2D& v)
        {
            x += v.x;
            y += v.y;
            return (*this);
        }

        cVector2D& operator -=(const cVector2D& v)
        {
            x -= v.x;
            y -= v.y;
            return (*this);
        }

        cVector2D& operator *=(float t)
        {
            x *= t;
            y *= t;
            return (*this);
        }

        cVector2D& operator /=(float t)
        {
            float f = 1.0F / t;
            x *= f;
            y *= f;
            return (*this);
        }

        cVector2D& operator &=(const cVector2D& v)
        {
            x *= v.x;
            y *= v.y;
            return (*this);
        }

        cVector2D operator -(void) const
        {
            return (cVector2D(-x, -y));
        }

        cVector2D operator +(const cVector2D& v) const
        {
            return (cVector2D(x + v.x, y + v.y));
        }

        cVector2D operator -(const cVector2D& v) const
        {
            return (cVector2D(x - v.x, y - v.y));
        }

        cVector2D operator *(float t) const
        {
            return (cVector2D(x * t, y * t));
        }

        cVector2D operator /(float t) const
        {
            float f = 1.0F / t;
            return (cVector2D(x * f, y * f));
        }

        float operator *(const cVector2D& v) const
        {
            return (x * v.x + y * v.y);
        }

        cVector2D operator &(const cVector2D& v) const
        {
            return (cVector2D(x * v.x, y * v.y));
        }

        bool operator ==(const cVector2D& v) const
        {
            return ((x == v.x) && (y == v.y));
        }

        bool operator !=(const cVector2D& v) const
        {
            return ((x != v.x) || (y != v.y));
        }

        cVector2D& normalize(void)
        {
            return (*this /= sqrtf(x * x + y * y));
        }

        cVector2D& rotate(float angle);
};


class cPoint2D : public cVector2D
{
    public:

        cPoint2D() {}

        cPoint2D(float r, float s) : cVector2D(r, s) {}

        cPoint2D& operator =(const cVector2D& v)
        {
            x = v.x;
            y = v.y;
            return (*this);
        }

        cPoint2D& operator *=(float t)
        {
            x *= t;
            y *= t;
            return (*this);
        }

        cPoint2D& operator /=(float t)
        {
            float f = 1.0F / t;
            x *= f;
            y *= f;
            return (*this);
        }

        cPoint2D operator -(void) const
        {
            return (cPoint2D(-x, -y));
        }

        cPoint2D operator +(const cVector2D& v) const
        {
            return (cPoint2D(x + v.x, y + v.y));
        }

        cPoint2D operator -(const cVector2D& v) const
        {
            return (cPoint2D(x - v.x, y - v.y));
        }

        cVector2D operator -(const cPoint2D& p) const
        {
            return (cVector2D(x - p.x, y - p.y));
        }

        cPoint2D operator *(float t) const
        {
            return (cPoint2D(x * t, y * t));
        }

        cPoint2D operator /(float t) const
        {
            float f = 1.0F / t;
            return (cPoint2D(x * f, y * f));
        }
};


inline cVector2D operator *(float t, const cVector2D& v)
{
    return (cVector2D(t * v.x, t * v.y));
}

inline float distance(const cPoint2D &p1, const cPoint2D &p2)
{
    return sqrt( ((p2.x - p1.x)*(p2.x - p1.x))+((p2.y - p1.y )*(p2.y - p1.y)));
}

inline cPoint2D operator *(float t, const cPoint2D& p)
{
    return (cPoint2D(t * p.x, t * p.y));
}

inline float dot(const cVector2D& v1, const cVector2D& v2)
{
    return (v1 * v2);
}
#endif	/* MYMATH_H */

