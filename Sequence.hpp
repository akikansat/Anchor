/**
 * @file sequence.cpp
 * @brief シークエンス確認用コード
 * @details 本番でも使えると分かりやすいけど電池の容量次第では余裕ないかも
 * @author M.Kato
 * @date 2019.7.24
 * @version 1.0
 * @note 
 * @todo 電池の耐久時間への影響の検討 
 */

#ifndef   SEQUENCE_HPP
#define   SEQUENCE_HPP

#include "mbed.h"

extern DigitalOut l1;
extern DigitalOut l2;
extern DigitalOut l3;
extern DigitalOut l4;

void setSeequence(int num);

#endif