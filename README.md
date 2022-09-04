# sdc-control
Control and trajectory tracking project for the Self Driving Car Udacity nanodegree.

## Images & plots

![Alt test](https://github.com/GabrielMaguire/sdc-control/blob/main/images/p1.png)
Sceenshot after building the PID controller object. Shows simulation vehicle stopped.

![Alt test](https://github.com/GabrielMaguire/sdc-control/blob/main/images/steer_error.png)
This plot shows the steering error, measured as the desired vs actual steering angle, during a driving simulation event. The error appears to oscilate as the the vehicle continuously overcorrects for the current steering error. The simulation vehicle reaches the end of the track at iteration ~90. The data from beyond this iteration count should be disregarded as there was no planned path for this section.

![Alt test](https://github.com/GabrielMaguire/sdc-control/blob/main/images/throttle_error.png)
This plot shows the throttle error, measured as the desired vs actual velocity, and corresponding throttle and break output. While initially oscilating dramatically, the throttle output settles to a near constant as expected. Only until iteration ~90 does the throttle and break output vary as the simulation vehicle approaches the end of the intended track. As mentioned in the steering error, iterations after iteration ~90 should be ignored because the car is going past the final stop sign on the intended course.

## Effects of the PID controls

The goal of the PID controls is to reduce error in our measured parameters such as desired steering angle and desired velocity.
* P: The proportional component of the controls provides an error parameter linearly proportional to a measurement such as the cross-track error. The larger the cross-track error the more the steering wheel should turn to reduce the error. For example, in the steering output plot the proportional component was likely too high due to the oscilations caused by the vehicle continuously overshooting its target cross-track error.
* I: The integral component of the controls provides an error parameter denoting the sum of error over the entire driving cycle. If the total sum of the error continues to increase there is likely a systematic bias which can be accounted for using this component. In the steering error plot the integral component appears to be calibrated correctly as the steering error is centered around zero.
* D: The differential component of the controls provides an error parameter that reflects the rate of change of a measurement such as the cross-track error. This parameter attemps to smooth out the aggressive output from the proportional component of the equation. In the steering output plot it is clear that the differential component is likely too low allowing for oscilations in the steering output.

## Automatic tuning of the PID parameters

As discussed in the lectures, the twiddle algorithm can be implemented to systematically adjust the PID coefficients to arrive at a local optimum.

## Pros and cons of a model-free controller

The PID controller (model-free) is given minimum information necessary to control the movement of the vehicle. With a minimum amount of complexity, the equation becomes more efficient and easier to troubleshoot. The PID controller is also highly flexible and can be applied to many different control scenarios. However, since the PID controller does not use a complete model of the vehicle it does not have knowledge of parameters other than the few (or one) it is given. This can cause a problem if there are additional unanticipated measurements that have an impact on the controls.