#include <sch/S_Object/S_Sphere.h>
#include <memory>


using namespace sch;
S_Sphere::S_Sphere(const Scalar & Rad) : radius_(Rad)
{
  slices_ = 100;
  stacks_ = 50;
}

S_Sphere::~S_Sphere(void) {}

std::shared_ptr<S_Object> S_Sphere::clone() const
{
  return std::make_shared<S_Sphere>(*this);
}

Point3 S_Sphere::l_Support(const Vector3 & v, int & /*lastFeature*/) const
{
  return v * radius_;
}

S_Object::S_ObjectType S_Sphere::getType() const
{
  return S_Object::TSphere;
}

Scalar S_Sphere::getRadius() const
{
  return radius_;
}
