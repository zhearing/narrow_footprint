#ifndef __PWM_H
#define __PWM_H
#include "sys.h"
void TIM4_PWM_Init(u16 arr,u16 psc);
										void TIM4_OC3(u16 pul);
										void TIM4_OC4(u16 pul);
void TIM5_PWM_Init(u16 arr,u16 psc);
										void TIM5_OC1(u16 pul);
										void TIM5_OC2(u16 pul);
										void TIM5_OC3(u16 pul);
										void TIM5_OC4(u16 pul);



#endif
