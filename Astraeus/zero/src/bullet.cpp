#include "bullet.h"

Bullet::Bullet(float x, float y, float direction) {
}

const char* Bullet::GetClass() {
   return "BULLET";
}

float Bullet::GetX() {
   return 100.0f;
}

float Bullet::GetY() {
   return 100.0f;
}
