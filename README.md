# SysTick
---
** About SysTick ** 
we can Initialize Systick with many kind way:
1. use of it register( notice to that , it is for own ARM core , and maybe it Register don't exist in your manual )
2. use of ` SysTick_Config ` function , it exist in ** core_cm3.h **( for stm32f10x )
3. use of ` SysTick_CLKSourceConfig ` , that exist in ** msic.h ** ( for stm32f10x )
4...
---
# how use of it ?
just change ` LED_PORT ` and ` LED_PIN ` to your LED address. 
