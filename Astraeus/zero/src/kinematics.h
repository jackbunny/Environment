#ifndef _ZERO_SRC_KINEMATICS_H_
#define _ZERO_SRC_KINEMATICS_H_

#define _USE_MATH_DEFINES 

#include "vector2.h"
#include <math.h>

class Kinematics {
   public:
      static Vector2 Calculate( Vector2 position,
                                float rotation,
                                Vector2 velocity, 
                                float acceleration,
                                float timeInMilliseconds);
};

#endif //_ZERO_SRC_KINEMATICS_H_
