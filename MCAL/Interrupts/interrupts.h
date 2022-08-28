/*
 * interrupts.h
 *
 * Created: 8/22/2022 11:26:05 AM
 *  Author: user
 */ 

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_


#define ISR(INT_VECT) void INT_VECT() __attribute__ ((signal,used));    \
void INT_VECT()

#define EXT_INT0 __vector_1

void INT0_init();


#endif /* INTERRUPTS_H_ */