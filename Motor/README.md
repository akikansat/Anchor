# Motordriver class

## main.cpp

- TA7291Pを使ったテストコード
- [このサイト](http://lumenbolk.com/?p=1274)を参考に作成

## motordriver.h/.cpp

- motordriver(TA2791P)を動かすクラス．[Motordriver.cpp](https://os.mbed.com/users/farbodjam/code/Motordriver/file/541fb1742c8b/motordriver.cpp/)および[Motordriver.h](https://os.mbed.com/users/farbodjam/code/Motordriver/docs/tip/motordriver_8h_source.html)から引用

### Usage

- 宣言

>Motor motor1(p21, p24, p25, 0); // pwm, fwd, rev, can brake 

pwmはPwmOut， fwd, revはDigitalOut

- 前/後ろに動かす

> motor1.speed(0.5);

speed>0なら後ろに，speed<0なら前に動く

- 止める

>motor1.stop()

can brake = 1ならブレーキがかかる．0ならブレーキかけずに停止のみする

## Sequence.hpp/.cpp

- setSequence(int num)
  - プログラムの状態をLEDで示す関数

### Usage

- LEDを光らせる

>setSequence(1)