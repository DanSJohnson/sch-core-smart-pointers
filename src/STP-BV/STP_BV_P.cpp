#include <sch/STP-BV/STP_BV_P.h>

using namespace sch;

STP_BV_P::STP_BV_P(void) {}

STP_BV_P::~STP_BV_P(void) {}

std::shared_ptr<S_Object> STP_BV_P::clone() const
{
  return std::make_shared<STP_BV_P>(*this);
}

void STP_BV_P::constructFromFile(const std::string & filename)
{
  STP_BV::constructFromFile(filename);
  poly.openFromFile(filename + std::string(".otp"));
}

Point3 STP_BV_P::l_Support(const Vector3 & v, int & lastFeature) const
{
  poly.support(v, lastFeature);
  int k = lastFeature;
  return STP_BV::l_Support(v, k);
}

S_Object::S_ObjectType STP_BV_P::getType() const
{
  return S_Object::TSTP_BV_WithPolyhedron;
}
