/***********************
 @date :	2015.4.4
 @function :	实现mini板最多的pwm输出
 @hardware :mini引出io脚有PA0-15
			              PB0-15
						  PC0-13
						  PD2
case1(使用定时器输出pwm波）
			PA0/TIM5_CH1-----done		/TIM2_CH1_ETR---->PA15-----done
			PA1/TIM5_CH2-----done   	/TIM2_CH2-------->PB3------done			
			PA2/TIM5_CH3-----done		/TIM2_CH3-------->PB10-----done							
			PA3/TIM5_CH4-----done		/TIM2_CH4-------->PB11-----done		
			
			PA6/TIM3_CH1-----done					
			PA7/TIM8_CHIN----done<-------TIM3_CH2----/--->PC7(used)
			PB0/TIM8_CH2N----done<-------TIM3_CH3----/--->PC8(used)
			PB1/TIM8_CH3N----done<-------TIM3_CH4----/--->PC9(used)
			
			PB9/TIM4_CH4-----done			PC9/TIM8_CH4-----done
			PB8/TIM4_CH3-----done			PC8/TIM8_CH3-----done
			PB7/TIM4_CH2-----done			PC7/TIM8_CH2-----done
			PB6/TIM4_CH1-----done			PC6/TIM8_CH1-----done
			
			PA11/TIM1_CH4----done
			PA10/TIM1_CH3----done
			PA9/TIM1_CH2-----done
			PA8/TIM1_CH1-----done
			PB15/TIM1_CH3N
			PB14/TIM1_CH2N
			PB13/TIM1_CH1N
			




case2(重定向功能)
			(CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)FullRemaping完全重定向TIM2
			(CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)FullRemaping完全重定向TIM3:(好像不行
case3(利用其他方式手工输出pwm)
			暂不考虑 可行性未知
************************/