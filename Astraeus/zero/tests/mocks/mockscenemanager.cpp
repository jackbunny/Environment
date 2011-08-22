#include "mockscenemanager.h"
#include <iostream>

void* MockSceneManager::GetLastObjectAdded() {
   return last_object_;
}

bool MockSceneManager::ObjectWasAdded() {
   return 1;
}

void MockSceneManager::Add(Bullet bullet) {
   last_object_ = &bullet;
}
