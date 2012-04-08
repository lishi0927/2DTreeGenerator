/*
 * Created on January 11, 2012, 1:52 PM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef MYMATH_H
#define	MYMATH_H

#include <math.h>

/****************  2D ****************/

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

/****************  3D ****************/

class cVector3D
{
    public:

        float   x;
        float   y;
        float   z;

        cVector3D() {}

        cVector3D(float r, float s, float t)
        {
            x = r;
            y = s;
            z = t;
        }

        cVector3D& set(float r, float s, float t)
        {
            x = r;
            y = s;
            z = t;
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

        cVector3D& operator +=(const cVector3D& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return (*this);
        }

        cVector3D& operator -=(const cVector3D& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return (*this);
        }

        cVector3D& operator *=(float t)
        {
            x *= t;
            y *= t;
            z *= t;
            return (*this);
        }

        cVector3D& operator /=(float t)
        {
            float f = 1.0F / t;
            x *= f;
            y *= f;
            z *= f;
            return (*this);
        }

        cVector3D& operator &=(const cVector3D& v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            return (*this);
        }

        cVector3D operator -(void) const
        {
            return (cVector3D(-x, -y, -z));
        }

        cVector3D operator +(const cVector3D& v) const
        {
            return (cVector3D(x + v.x, y + v.y, z + v.z));
        }

        cVector3D operator -(const cVector3D& v) const
        {
            return (cVector3D(x - v.x, y - v.y, z - v.z));
        }

        cVector3D operator *(float t) const
        {
            return (cVector3D(x * t, y * t, z * t));
        }

        cVector3D operator /(float t) const
        {
            float f = 1.0F / t;
            return (cVector3D(x * f, y * f, z * f));
        }

        float operator *(const cVector3D& v) const
        {
            return (x * v.x + y * v.y + z * v.z);
        }

        cVector3D operator &(const cVector3D& v) const
        {
            return (cVector3D(x * v.x, y * v.y, z * v.z));
        }

        bool operator ==(const cVector3D& v) const
        {
            return ((x == v.x) && (y == v.y) && (z == v.z));
        }

        bool operator !=(const cVector3D& v) const
        {
            return ((x != v.x) || (y != v.y) || (z != v.z));
        }

        cVector3D& normalize(void)
        {
            return (*this /= sqrtf(x * x + y * y + z * z));
        }

        cVector3D& rotate(float angle);
};

class cPoint3D : public cVector3D
{
    public:

        cPoint3D() {}

        cPoint3D(float r, float s, float t) : cVector3D(r, s, t) {}

        cPoint3D& operator =(const cVector3D& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            return (*this);
        }

        cPoint3D& operator *=(float t)
        {
            x *= t;
            y *= t;
            z *= t;
            return (*this);
        }

        cPoint3D& operator /=(float t)
        {
            float f = 1.0F / t;
            x *= f;
            y *= f;
            z *= f;
            return (*this);
        }

        cPoint3D operator -(void) const
        {
            return (cPoint3D(-x, -y, -z));
        }

        cPoint3D operator +(const cVector3D& v) const
        {
            return (cPoint3D(x + v.x, y + v.y, z + v.z));
        }

        cPoint3D operator -(const cVector3D& v) const
        {
            return (cPoint3D(x - v.x, y - v.y, z - v.z));
        }

        cVector3D operator -(const cPoint3D& p) const
        {
            return (cVector3D(x - p.x, y - p.y, z - p.z));
        }

        cPoint3D operator *(float t) const
        {
            return (cPoint3D(x * t, y * t, z * t));
        }

        cPoint3D operator /(float t) const
        {
            float f = 1.0F / t;
            return (cPoint3D(x * f, y * f, z * f));
        }
};

inline cVector3D operator *(float t, const cVector3D& v)
{
    return (cVector3D(t * v.x, t * v.y, t * v.z));
}

inline float distance(const cPoint3D &p1, const cPoint3D &p2)
{
    return sqrt( ((p2.x - p1.x)*(p2.x - p1.x))+((p2.y - p1.y )*(p2.y - p1.y))+((p2.z - p1.z )*(p2.z - p1.z)));
}

inline cPoint3D operator *(float t, const cPoint3D& p)
{
    return (cPoint3D(t * p.x, t * p.y, t * p.z));
}

inline float dot(const cVector3D& v1, const cVector3D& v2)
{
    return (v1 * v2);
}


#endif	/* MYMATH_H */

