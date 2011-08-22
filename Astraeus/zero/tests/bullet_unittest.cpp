#include "bullet.h"
#include "gtest/gtest.h"

class BulletTest : public ::testing::Test {
   protected:
   BulletTest() : bullet_(testX_, testY_, direction_) {}

   static const float testX_;
   static const float testY_;
   static const float direction_;
   static const float speed_;
   Bullet bullet_;
};

const float BulletTest::testX_ = 100.0f;
const float BulletTest::testY_ = 100.0f;
const float BulletTest::direction_ = 100.0f;
const float BulletTest::speed_ = 100.0f;

TEST_F(BulletTest, ConstructorTest) {
   EXPECT_EQ(bullet_.GetX(), BulletTest::testX_);
   EXPECT_EQ(bullet_.GetY(), BulletTest::testY_);
}

TEST_F(BulletTest, MovementTest) {

}
