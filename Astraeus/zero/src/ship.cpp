#include "ship.h"

Ship::Ship(float x, float y, float acceleration, float maxSpeed,
           float rotationSpeed) {
   Actor::x_ = x;
   y_ = y;
   vx_ = 0;
   vy_ = 0;

   acceleration_ = acceleration;
   maxSpeed_ = maxSpeed;
   rotationSpeed_ = rotationSpeed;
   thrustIsOn_ = 0;
   
   rotation_ = 0;
   rotationDirection_ = 0;
}

void Ship::Fire(ISceneManager* sceneManager) {
   Bullet bullet(x_, y_, 0.0f);
   sceneManager->Add(bullet);
}

void Ship::ThrustOn() {
   thrustIsOn_ = 1;
}

void Ship::ThrustOff() {
   thrustIsOn_ = 0;
}

void Ship::Update(float deltaTime) {
  float radians = rotation_ * (M_PI / 180.0f);
  float seconds = deltaTime / 1000.0f;

  if ( thrustIsOn_ ) {
      vx_ += acceleration_ * cosf(radians) * seconds;
      vy_ += acceleration_ * sinf(radians) * seconds;
   }

  Actor::Update(deltaTime);
}
