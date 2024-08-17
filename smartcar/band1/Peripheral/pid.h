#ifndef PID_H
#define PID_H
typedef struct{
    //所需要调节的参数
    float Kp;
    float Ki;
    float Kd;
    
    float tau;//积分所用到的低通滤波时间常数
    float limMin;//out输出限制幅度
    float limMax;

    float limMinInt;//积分项限制幅度
    float limMaxInt;

    float T;//采样速率
    float integrator;//积分项
    float prevError;//上一次的误差
    float differentiator;//微分项
    float prevMeasurement;//上一次的测量值
    float out;//输出
} PIDController;

float PID_update(PIDController *pid, float setpoint, float measurement);

#endif /* PID_H */