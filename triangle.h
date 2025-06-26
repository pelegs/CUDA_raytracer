#ifndef TRIANGLEH
#define TRIANGLEH

#include "hitable.h"
#include "plane.h"

class triangle : public hitable {
public:
  vec3 vertices[3];
  plane pln;
  material *mat_ptr;

  __device__ triangle() {}
  __device__ triangle(const vec3 &p0, const vec3 &p1, const vec3 &p2,
                      material *m) {
    this->vertices[0] = p0;
    this->vertices[1] = p1;
    this->vertices[2] = p2;

    this->pln = plane(p0, p1, p2);
  }

  __device__ virtual bool hit(const ray &r, float tmin, float tmax,
                              hit_record &rec) const {
    return false;
  }
};

#endif
