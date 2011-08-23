#include "kinematics.h"
#include <iostream>

Vector2 Kinematics::Calculate( Vector2 position,   
                       float rotation,
                       Vector2 velocity,
                       float acceleration,
                       float timeInMilliseconds)
{
   float radians = rotation * (M_PI / 180.0F);
   float seconds = timeInMilliseconds / 1000.0f;

   velocity.x += acceleration * cosf(radians) * seconds;
   velocity.y += acceleration * sinf(radians) * seconds;

   Vector2 newPosition(position.x + velocity.x,
                       position.y + velocity.y);

   return newPosition;

}

