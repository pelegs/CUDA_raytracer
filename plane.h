#ifndef PLANE
#define PLANE

#include "vec3.h"

class plane {
public:
  vec3 p0, p1, p2;
  vec3 normal;
  // float a, b, c, d;

  __device__ plane() {}
  __device__ plane(const vec3 &p0, const vec3 &p1, const vec3 &p2) {
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;

    // set normal vector
    vec3 v0 = p1 - p0;
    vec3 v1 = p2 - p1;
    this->normal = unit_vector(cross(v0, v1));

    // set std representation (ax+by+cz+d=0)
    // ...
  }
};

#endif
