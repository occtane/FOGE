#include <cmath>
#include <iostream>

#include "include/vec3.h"

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
}
