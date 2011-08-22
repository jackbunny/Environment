#include "actor.h"

float Actor::GetRotation() {
   return rotation_;
}

float Actor::GetX() {
   return x_;
}

float Actor::GetY() {
   return y_;
}

void Actor::RotateLeftOn() {
   rotationDirection_ = 1;
}

void Actor::RotateRightOn() {
   rotationDirection_ = -1;
}

void Actor::RotateOff() {
   rotationDirection_ = 0;
}

void Actor::Update(float deltaTime) {
   float radians = rotation_ * (M_PI / 180.0f);
   float seconds = deltaTime / 1000.0f;

   x_ += vx_ * seconds; 
   y_ += vy_ * seconds; 

   rotation_ += rotationSpeed_ * rotationDirection_ * seconds;
   if ( rotation_ >= 360 ) {
      rotation_ = rotation_ - 360;
   } else if (rotation_ < 0) {
      rotation_ = 360 + rotation_;
   }
}
