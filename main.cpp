#include <cmath>
#include <iostream>

struct Vector3D
{
  float x{}, y{}, z{};

  Vector3D() = default;
  Vector3D(float a, float b, float c) : x(a), y(b), z(c)
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

  Vector3D &operator*=(float s)
  {
    x *= s;
    y *= s;
    z *= s;
    return (*this);
  }

  Vector3D &operator/=(float s)
  {
    s = 1.0F / s;
    x *= s;
    y *= s;
    z *= s;
    return (*this);
  }
};

inline Vector3D operator*(const Vector3D &v, float s)
{
  return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator-(const Vector3D &v)
{
  return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D &v)
{
  return (std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D &v)
{
  return (v / Magnitude(v));
}

int main()
{
  Vector3D v;

  v[0] = 30.f;
  v[1] = 9.8f;
  v[2] = 12.f;

  std::cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")\n";

  return 0;
}
