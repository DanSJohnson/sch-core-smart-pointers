#ifndef _CD_DEPTH
#define _CD_DEPTH

#pragma once
#include <sch/CD/CD_SimplexEnhanced.h>
#include <sch/S_Object/S_Object.h>
#include <sch/sch_api.h>
#include <memory>

namespace sch
{

class CD_Depth
{

protected:
  std::shared_ptr<S_Object> sObj1_;
  std::shared_ptr<S_Object> sObj2_;

  Scalar precision_, epsilon_;

public:
  SCH_API CD_Depth(std::shared_ptr<S_Object> Obj1, std::shared_ptr<S_Object> Obj2);
  SCH_API virtual ~CD_Depth(void);

  /*!
   *\brief sets the relative precision of the proximity queries to a given value. Default is 1e-3
   */
  SCH_API void setRelativePrecision(Scalar);

  /*!
   *\brief Sets the machine epsilon. Default is 1e-24
   */
  SCH_API void setEpsilon(Scalar);

  SCH_API Scalar getPenetrationDepth(Vector3 & v,
                                     Point3 & p1,
                                     Point3 & p2,
                                     const CD_SimplexEnhanced & s,
                                     const CD_Simplex & s1_,
                                     const CD_Simplex & s2_);
};

} // namespace sch

#endif
