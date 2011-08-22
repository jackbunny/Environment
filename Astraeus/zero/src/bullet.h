#ifndef ZERO_SRC_BULLET_H_
#define ZERO_SRC_BULLET_H_ 

#include <string.h>

class Bullet 
{
   public:
   Bullet(float x, float y, float direction);
   const char* GetClass();
   float GetX();
   float GetY();
};

#endif
