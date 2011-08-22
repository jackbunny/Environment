#include "ship.h"
#include "mocks/mockscenemanager.h"
#include "gtest/gtest.h"

class ShipTest : public ::testing::Test {
   protected:
      ShipTest() : ship_(testX_, testY_, testAccel_, testMaxSpeed_, testRotationSpeed_) {}
      
      virtual void SetUp() {
         elapsedMilliseconds_ = 1000.0f;
      }

      static const float testX_;
      static const float testY_;
      static const float testAccel_;
      static const float testMaxSpeed_;
      static const float testRotationSpeed_;
      float elapsedMilliseconds_;
      Ship ship_;
};

const float ShipTest::testX_ = 100.0f;
const float ShipTest::testY_ = 100.0f;
const float ShipTest::testAccel_ = 2.0f;
const float ShipTest::testMaxSpeed_ = 10.0f;
const float ShipTest::testRotationSpeed_ = 5.0f;

float GetAbsolute(float val) {
   if ( val < 0 ) {
      return val * -1;
   } else {
      return val;
   }
}

TEST_F(ShipTest, ConstructorWorks) {
   EXPECT_EQ(ShipTest::testX_, ship_.GetX());
   EXPECT_EQ(ShipTest::testY_, ship_.GetY());
}

TEST_F(ShipTest, ThrustOnMovesShip) {
   float initX = ship_.GetX();
   float initY = ship_.GetY();
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_);
   bool result = (ship_.GetX() != initX)
              || (ship_.GetY() != initY);
   EXPECT_TRUE(result);
}

TEST_F(ShipTest, ThrustOffWorks) {
   float initX = ship_.GetX();
   float initY = ship_.GetY();
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_);
   float secondX = ship_.GetX();
   float secondY = ship_.GetY();
   float dX = secondX - initX;
   float dY = secondY - initY;
   ship_.ThrustOff();
   ship_.Update(elapsedMilliseconds_);
   EXPECT_EQ(ship_.GetX() - secondX, dX);
   EXPECT_EQ(ship_.GetY() - secondY, dY);
}

TEST_F(ShipTest, ThrustScalesWithTime) { 
   float initX = ship_.GetX();
   float initY = ship_.GetY();
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_);
   float secondX = ship_.GetX();
   float secondY = ship_.GetY();
   float dX = secondX - initX;
   float dY = secondY - initY;
   Ship ship2(testX_, testY_, testAccel_, testMaxSpeed_, testRotationSpeed_);
   float initX2 = ship2.GetX();
   float initY2 = ship2.GetY();
   ship2.ThrustOn();
   ship2.Update(elapsedMilliseconds_ * 2);
   float secondX2 = ship2.GetX();
   float secondY2 = ship2.GetY();
   float dX2 = secondX2 - initX2;
   float dY2 = secondY2 - initY2; 
   dX = GetAbsolute(dX);
   dY = GetAbsolute(dY);
   dX2 = GetAbsolute(dX2);
   dY2 = GetAbsolute(dY2);
   bool result = (dX2 > dX) || (dY2 > dY);
   EXPECT_TRUE(result);
}

TEST_F(ShipTest, RotatesChangeDirection) {
   float initialRotation = ship_.GetRotation();
   ship_.RotateLeftOn();
   ship_.Update(elapsedMilliseconds_);
   float secondRotation = ship_.GetRotation();
   ship_.RotateRightOn();
   ship_.Update(elapsedMilliseconds_);
   float thirdRotation  = ship_.GetRotation();
   EXPECT_NE(initialRotation, secondRotation);
   EXPECT_NE(secondRotation, thirdRotation);
}

TEST_F(ShipTest, RotationIsInRange) {
   float initialRotation = ship_.GetRotation();
   float rotation = initialRotation + 1;
   bool pastZero = 0;
   ship_.RotateRightOn();
   while (!pastZero && (rotation > initialRotation)) {
      ASSERT_GE(rotation, 0);
      ASSERT_LT(rotation, 360);
      ship_.Update(elapsedMilliseconds_);
      float lastRotation = rotation;
      rotation = ship_.GetRotation();
      if ( rotation < lastRotation ) {
         pastZero = 1;
      }
   }
}

TEST_F(ShipTest, RotationOffWorks) {
   float firstRotation = ship_.GetRotation();
   ship_.RotateLeftOn();
   ship_.Update(elapsedMilliseconds_);
   float secondRotation = ship_.GetRotation();
   ship_.RotateOff();
   ship_.Update(elapsedMilliseconds_);
   float thirdRotation = ship_.GetRotation();

   EXPECT_NE(firstRotation, secondRotation);
   EXPECT_EQ(secondRotation, thirdRotation);
}

TEST_F(ShipTest, RotationGoesCorrectDirection) {
   float first = ship_.GetRotation();
   ship_.RotateLeftOn();
   ship_.Update(elapsedMilliseconds_);
   float second = ship_.GetRotation();
   ship_.RotateRightOn();
   ship_.Update(elapsedMilliseconds_);
   float third = ship_.GetRotation();

   EXPECT_EQ(second - first, testRotationSpeed_);
   EXPECT_EQ(first, third);
}

TEST_F(ShipTest, RotationScalesWithTime) {
   float firstRotation = ship_.GetRotation();
   ship_.RotateLeftOn();
   ship_.Update(elapsedMilliseconds_);
   float secondRotation = ship_.GetRotation();
   ship_.Update(elapsedMilliseconds_ * 2);
   float thirdRotation = ship_.GetRotation();

   EXPECT_LT(secondRotation - firstRotation, thirdRotation - secondRotation);
}


TEST_F(ShipTest, ShipMovesInCorrectDirection) {
   float x1 = ship_.GetX();
   float y1 = ship_.GetY();
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_);
   float x2 = ship_.GetX();
   float y2 = ship_.GetY();
   //Rotate 180
   ship_.ThrustOff();
   ship_.RotateLeftOn();
   ship_.Update( (180.0f / testRotationSpeed_) * 1000.0f);
   ship_.RotateOff();
   //Thrust till stop
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_); 
   float x3 = ship_.GetX();
   float y3 = ship_.GetY(); 
   //Check velocity
   ship_.ThrustOff();
   ship_.Update(elapsedMilliseconds_);
   float x4 = ship_.GetX();
   float y4 = ship_.GetY();
   //rotate 90
   ship_.RotateRightOn();
   ship_.Update( (90.0f / testRotationSpeed_) * 1000.0f);
   ship_.RotateOff();
   //fly up
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_);
   float x5 = ship_.GetX();
   float y5 = ship_.GetY();
   //Rotate 180
   ship_.ThrustOff();
   ship_.RotateLeftOn();
   ship_.Update( (180.0f / testRotationSpeed_) * 1000.0f);
   ship_.RotateOff();
   ship_.ThrustOn();
   ship_.Update(elapsedMilliseconds_);
   float x6 = ship_.GetX();
   float y6 = ship_.GetY();
   ship_.ThrustOff();
   ship_.Update(elapsedMilliseconds_);
   float x7 = ship_.GetX();
   float y7 = ship_.GetY();

   ASSERT_LT(x1, x2); 
   EXPECT_EQ(y1, y2);
   ASSERT_EQ(x4, x3);
   EXPECT_EQ(y4, y3);
   EXPECT_EQ(x4, x5);
   EXPECT_LT(y4, y5);
   EXPECT_EQ(x6, x7);
   EXPECT_EQ(y6, y7);
}

TEST_F(ShipTest, TestFireWeapon) {
   MockSceneManager sceneManager;

   ship_.Fire(&sceneManager);
   EXPECT_TRUE(sceneManager.ObjectWasAdded());
   EXPECT_STREQ(((Bullet*)sceneManager.GetLastObjectAdded())->GetClass(), "BULLET");
}
