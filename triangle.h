#ifndef TRIANGLEH
#define TRIANGLEH

#include "hitable.h"

const float tfar = 1.0E10;

__host__ __device__ inline float signed_volume(const vec3 &a, const vec3 &b,
                                               const vec3 &c, const vec3 &d) {
  float v = 1.0 / 6.0 * dot(cross(b - a, c - a), d - a);
  return copysignf(1.0, v);
}

class triangle : public hitable {
public:
  __device__ triangle() {}
  __device__ triangle(const vec3 &p0, const vec3 &p1, const vec3 &p2,
                      material *m);
  __device__ virtual bool hit(const ray &r, float tmin, float tmax,
                              hit_record &rec) const;

  vec3 vertices[3];
  vec3 normal;
  material *mat_ptr;
};

__device__ triangle::triangle(const vec3 &p0, const vec3 &p1, const vec3 &p2,
                              material *m) {
  this->vertices[0] = p0;
  this->vertices[1] = p1;
  this->vertices[2] = p2;

  // set normal vector
  vec3 v0 = p1 - p0;
  vec3 v1 = p2 - p1;
  this->normal = unit_vector(cross(v0, v1));
}

__device__ bool triangle::hit(const ray &r, float tmin, float tmax,
                              hit_record &rec) const {
  vec3 q1 = r.point_at_parameter(-1.0 * tfar);
  vec3 q2 = r.point_at_parameter(tfar);
  vec3 p1 = this->vertices[0];
  vec3 p2 = this->vertices[1];
  vec3 p3 = this->vertices[2];
  return (signed_volume(q1, p1, p2, p3) != signed_volume(q2, p1, p2, p3) &&
          signed_volume(q1, q2, p1, p2) == signed_volume(q1, q2, p2, p3) &&
          signed_volume(q1, q2, p3, p1) == signed_volume(q1, q2, p2, p3));
}

#endif
