#ifndef ZERO_TESTS_MOCKS_MOCKSCENEMANAGER_H_
#define ZERO_TESTS_MOCKS_MOCKSCENEMANAGER_H_

#include "iscenemanager.h"

class MockSceneManager : public ISceneManager {
   private:
      void* last_object_;
   public:
   virtual void Add(Bullet bullet);
   bool ObjectWasAdded();
   void* GetLastObjectAdded();
};

#endif
