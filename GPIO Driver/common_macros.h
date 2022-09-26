/*
 * common_macros.h
 * Created on: Sep 26, 2022
 * Author: Yousef_Osama
 * Description:includes the common macros used in the drivers
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
/*to set a certain bit inside a register*/
#define SET_BIT(REG,BIT_NUM) (REG|=(1<<BIT_NUM))
/*to clear a certain bit inside a register*/
#define CLEAR_BIT(REG,BIT_NUM) (REG&=~(1<<BIT_NUM))
/*to toggle a certain bit inside a register*/
#define TOGGLE_BIT(REG,BIT_NUM) (REG^=(1<<BIT_NUM))
/*to check if a certain bit inside a register is set*/
#define BIT_IS_SET(REG,BIT_NUM) (REG & (1<<BIT_NUM))
/*to check if a certain bit inside a register is clear*/
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG & (1<<BIT_NUM)))
/*to rotate certain bits inside a register right*/
#define ROR(REG,BIT_NUM) ((REG<<BIT_NUM)|(REG>>(8-BIT_NUM)))
/*to rotate certain bits inside a register left*/
#define ROL(REG,BIT_NUM) ((REG>>BIT_NUM)|(REG<<(8-BIT_NUM)))
#endif /* COMMON_MACROS_H_ */
