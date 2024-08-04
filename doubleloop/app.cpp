#include "app.h"
#include "util.h"

#include "AreaControl.h"
// #include "MotorControl.h"
// #include "ColorSensorControl.h"
#include "Clock.h"
// #include "Detection.h"
#include "Color.h"
#include "Angle.h"

using namespace ev3api;

// Detection detection_;
AreaControl areaCtrl_;
static void wait_start();     /* 動作開始待ち（シミュレータ：自動で開始, 実機：BlueToothボタンで開始） */
static void init();           /* 区画生成 */
void wait_msec(int32_t msec); /* タスク停止関数（ミリ秒） */
static void port_config();    /* ポート初期設定 */

/**
 * メインタスク
 */
void main_task(intptr_t unused)
{

  port_config();
  wait_start();
  init();

  printf("[Main Task] Aggregate Start\n");
  /* 集計タスク起動 */
  sta_cyc(AGGREGATE_TASK_CYC);

  printf("[Main Task] Trace Start\n");
  /* 走行タスク起動 */
  //sta_cyc(TRACER_TASK_CYC);

  // MotorControl leftWheel(PORT_C);
  // MotorControl rightWheel(PORT_B);
  // ColorSensorControl colorsensor(PORT_2);
  Clock clock;

#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 6;
#else
  const int8_t pwm = 60;
#endif

  const uint32_t duration = 2000 * 1000; // <1>

  init_f(__FILE__);
  while (1)
  {
    areaCtrl_.run();
    //clock.sleep(duration);
    //printf("Forwarding...\n");
    //leftWheel.setPWM(pwm);
    //rightWheel.setPWM(pwm);
    //clock.sleep(duration); // <1>

    //printf("Backwarding...\n");
    //leftWheel.setPWM(-pwm);
    //rightWheel.setPWM(-pwm);
    //clock.sleep(duration);

    // 左ボタンを長押し、それを捕捉する
    if (ev3_button_is_pressed(LEFT_BUTTON))
    {
      break;
    }
  }
  stp_cyc(TRACER_TASK_CYC);
  stp_cyc(AGGREGATE_TASK_CYC);

  msg_f("Stopped.", 1);
  //leftWheel.stop();
  //rightWheel.stop();
  while (ev3_button_is_pressed(LEFT_BUTTON))
  {
    ;
  }

  // タスク終了
  ext_tsk();
}

void init()
{
  // 区画の生成
  areaCtrl_.addArea(0, 100);
}

void tracer_task(intptr_t unused)
{
  areaCtrl_.run();
  ext_tsk();
}

void aggregate_task(intptr_t unused)
{
  printf("aggregate_task\n");
  Color::setColor();
  Angle::aggregateAngle();
  ext_tsk(); /* タスク終了 */
}

/* ポート初期設定 */
static void port_config()
{
  /* センサー入力ポートの設定 */
  ev3_sensor_config(touch_sensor, TOUCH_SENSOR);
  ev3_sensor_config(color_sensor, COLOR_SENSOR);
  ev3_sensor_config(sonar_sensor, ULTRASONIC_SENSOR);
  ev3_sensor_config(gyro_sensor, GYRO_SENSOR);
  /* モーター出力ポートの設定 */
  // ev3_motor_config(arm_motor     ,LARGE_MOTOR);
  ev3_motor_config(left_motor, MEDIUM_MOTOR);
  ev3_motor_config(right_motor, MEDIUM_MOTOR);
}

/* 動作開始待ち（シミュレータ：自動で開始, 実機：BlueToothボタンで開始） */
static void wait_start()
{
  while (true)
  {
    bool_t pressed_flg;
    pressed_flg = ev3_touch_sensor_is_pressed(touch_sensor);
    if (pressed_flg)
    {
      printf("[Main Task] Simulator is ready\n");
      break;
    }
    wait_msec(50);
  }
}

/* タスク停止関数（ミリ秒） */
void wait_msec(int32_t msec)
{
  dly_tsk(msec * 1000 / 0.6);
}
