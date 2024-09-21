#include "pid.h"
PIDController motor_pid;// create a PIDController object for motorspeed control

void PID_init(void)
{
    motor_pid.Kd=0;
    motor_pid.Ki=0.7;
    motor_pid.Kp=570;
    motor_pid.limMax=700;
    motor_pid.limMin=200;
  //  motor_pid.integrator=0;
    motor_pid.limMaxInt=100;
    motor_pid.limMinInt=0;
    motor_pid.differentiator=0;
    motor_pid.T=0.002;
}
float PID_update(PIDController *pid, float setpoint, float measurement) {

	/*
	* Error signal
	*/
    float error = setpoint - measurement;


	/*
	* Proportional
	*/
    float proportional = pid->Kp * error;


	/*
	* Integral
	*/
    pid->integrator = pid->integrator + 0.5f * pid->Ki * pid->T * (error + pid->prevError);

	/* Anti-wind-up via integrator clamping */
    if (pid->integrator > pid->limMaxInt) {

        pid->integrator = pid->limMaxInt;

    } else if (pid->integrator < pid->limMinInt) {

        pid->integrator = pid->limMinInt;

    }


	/*
	* Derivative (band-limited differentiator)
	*/
		
   // pid->differentiator = -(2.0f * pid->Kd * (measurement - pid->prevMeasurement)	/* Note: derivative on measurement, therefore minus sign in front of equation! */
                       // + (2.0f * pid->tau - pid->T) * pid->differentiator)
    //                    / (2.0f * pid->tau + pid->T);


	/*
	* Compute output and apply limits
	*/
    pid->out = proportional + pid->integrator + pid->differentiator;

    if (pid->out > pid->limMax) {

        pid->out = pid->limMax;

    } else if (pid->out < pid->limMin) {

        pid->out = pid->limMin;

    }

	/* Store error and measurement for later use */
    pid->prevError       = error;
    pid->prevMeasurement = measurement;

	/* Return controller output */
    return pid->out;

}