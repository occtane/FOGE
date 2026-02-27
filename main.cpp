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

inline Vector3D operator/(const Vector3D &v, float s)
{
  return (Vector3D(v.x / s, v.y / s, v.z / s));
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
  Vector3D v(30.0f, 9.8f, 12.0f);

  // [] overload
  std::cout << "v = (" << v[0] << ", " << v[1] << ", " << v[2] << ")\n";

  // *= overload (mutates v)
  v *= 2.0f;
  std::cout << "after v *= 2: (" << v.x << ", " << v.y << ", " << v.z << ")\n";

  // /= overload (mutates v)
  v /= 4.0f;
  std::cout << "after v /= 4: (" << v.x << ", " << v.y << ", " << v.z << ")\n";

  // unary - overload (creates new vector)
  Vector3D neg = -v;
  std::cout << "-v = (" << neg.x << ", " << neg.y << ", " << neg.z << ")\n";

  // operator* overload (creates new vector)
  Vector3D scaled = v * 3.0f;
  std::cout << "v * 3 = (" << scaled.x << ", " << scaled.y << ", " << scaled.z << ")\n";

  // operator/ overload (creates new vector)
  Vector3D half = v / 2.0f;
  std::cout << "v / 2 = (" << half.x << ", " << half.y << ", " << half.z << ")\n";

  // your helper functions
  float len = Magnitude(v);
  Vector3D unit = Normalize(v);
  std::cout << "|v| = " << len << "\n";
  std::cout << "Normalize(v) = (" << unit.x << ", " << unit.y << ", " << unit.z << ")\n";

  return 0;
}
