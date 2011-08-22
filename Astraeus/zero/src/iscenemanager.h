#ifndef ZERO_SRC_ISCENEMANAGER_H_
#define ZERO_SRC_ISCENEMANAGER_H_

#include "bullet.h"

class ISceneManager
{
   public:
   virtual void Add(Bullet bullet) = 0;
};

#endif
