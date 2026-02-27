#pragma once

namespace foge
{
    struct Vec3
    {
        float x{}, y{}, z{};

        Vec3() = default;
        Vec3(float a, float b, float c) : x(a), y(b), z(c)
        {
        }

        float &operator[](int i)
        {
            return ((&x)[i]);
        }

        const float &operator[](int i) const
        {
            return ((&x)[i]);
        }

        Vec3 &operator*=(float s)
        {
            x *= s;
            y *= s;
            z *= s;
            return (*this);
        }

        Vec3 &operator/=(float s)
        {
            s = 1.0F / s;
            x *= s;
            y *= s;
            z *= s;
            return (*this);
        }

        Vec3 &operator+=(const Vec3 &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return (*this);
        }

        Vec3 &operator-=(const Vec3 &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return (*this);
        }
    };

    inline Vec3 operator*(const Vec3 &v, float s)
    {
        return (Vec3(v.x * s, v.y * s, v.z * s));
    }

    inline Vec3 operator/(const Vec3 &v, float s)
    {
        return (Vec3(v.x / s, v.y / s, v.z / s));
    }

    inline Vec3 operator-(const Vec3 &v)
    {
        return (Vec3(-v.x, -v.y, -v.z));
    }

    inline Vec3 operator+(const Vec3 &a, const Vec3 &b)
    {
        return (Vec3(a.x + b.x, a.y + b.y, a.z + b.z));
    }

    inline Vec3 operator-(const Vec3 &a, const Vec3 &b)
    {
        return (Vec3(a.x - b.x, a.y - b.y, a.z - b.z));
    }

    inline float Magnitude(const Vec3 &v)
    {
        return (std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
    }

    inline Vec3 Normalize(const Vec3 &v)
    {
        return (v / Magnitude(v));
    }
}