#ifndef _ZERO_SRC_ACTOR_H_
#define _ZERO_SRC_ACTOR_H_

#include <math.h>

class Actor {
   public:
   float GetRotation();
   float GetX();
   float GetY();
   void RotateLeftOn();
   void RotateRightOn();
   void RotateOff();
   void Update(float deltaTime);

   protected:
   float x_;
   float y_;
   float rotation_; 
   float rotationDirection_;
   float rotationSpeed_;
   float vx_;
   float vy_;
   float maxSpeed_;
};

#endif //END _ZERO_SRC_ACTOR_H_
