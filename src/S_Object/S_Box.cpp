#include <sch/S_Object/S_Box.h>
#include <memory>

using namespace sch;

inline Scalar sign(Scalar i)
{
  return (i > 0) ? 1 : -1;
}

S_Box::S_Box(Scalar _a, Scalar _b, Scalar _c) : a_(fabs(_a / 2)), b_(fabs(_b / 2)), c_(fabs(_c / 2)) {}

S_Box::~S_Box(void) {}

std::shared_ptr<S_Object> S_Box::clone() const
{
  return std::make_shared<S_Box>(*this);
}

Point3 S_Box::l_Support(const Vector3 & v, int & /*lastFeature*/) const
{
  return Point3(sign(v[0]) * a_, sign(v[1]) * b_, sign(v[2]) * c_);
}

S_Object::S_ObjectType S_Box::getType() const
{
  return S_Object::TBox;
}

void S_Box::getBoxParameters(Scalar & a, Scalar & b, Scalar & c) const
{
  a = a_ * 2;
  b = b_ * 2;
  c = c_ * 2;
}
