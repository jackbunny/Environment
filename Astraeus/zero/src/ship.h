#ifndef ZERO_SRC_SHIP_H_ 
#define ZERO_SRC_SHIP_H_

#define _USE_MATH_DEFINES

#include "actor.h"
#include "iscenemanager.h"
#include "bullet.h"
#include <math.h>
#include <iostream>

class Ship : public Actor {
public:
   Ship(float x, float y, float acceleration, float maxSpeed,
        float rotationSpeed);
   void Fire(ISceneManager* sceneManager);
   void ThrustOn();
   void ThrustOff();
   void Update(float deltaTime);

private:
   bool thrustIsOn_;
   float acceleration_;
};

#endif //ZERO_SRC_SHIP_H_
