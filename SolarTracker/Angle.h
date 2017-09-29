#ifndef _ANGLE_h
#define _ANGLE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "MPU6050.h"
#else
#include "WProgram.h"
#endif
class Angle
{
public:
  Angle();
  ~Angle();
  void Angle::Setup();
  double Angle::GetAngle();

private:
  void Angle::ReadMpu6050Data();
  int gyro_x, gyro_y, gyro_z;
  long gyro_x_cal, gyro_y_cal, gyro_z_cal;
  boolean set_gyro_angles;

  long acc_x, acc_y, acc_z, acc_total_vector;
  float angle_roll_acc, angle_pitch_acc;

  float angle_pitch, angle_roll;
  int angle_pitch_buffer, angle_roll_buffer;
  float angle_pitch_output, angle_roll_output;

  long loop_timer;
  int temp;
};
#endif
