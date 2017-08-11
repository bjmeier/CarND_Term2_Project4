# CarND_Term2_Project4
PID Control

---

### Project Summary

This project utilizes the Udacity Simulator to control the path of a car. The path is controlled by the use of a Proportional-Integral-Derivative Controller. The input for the controller is the cross track error, CTE. The output of the controller is the steering angle/ maximum steering angle, SA.

---

### Equations

Proportional Error, Perror = Kp x CTE[k]
Integral Error, Ierror = Ki x sum(CTE[i]|i = 1 to k
Derivative Error, Derror = Kd x (CTE[k] - CTE[k-1])
SA = - Kp x CTE[k] - (Ki x sum(CTE[i]|i = 1 to k) - Kd x (CTE[k] - CTE[k-1])

---

### Effect of Modifying Parameters, Kp, Ki and Kd

- As the Kp term increases, so does response to the CTE error.  In this application and absent Ki or Kd terms, this causes an increase in the the oscillation frequency.
- As the Ki term increases, the longer CTE error occurs, the stronger the response. It is often used to remove steady-state error.  In this application, integral windup makes this term undesirable. As vehicle makes a turn, the Ierror increases and causes oscillations upon the exit of the turn.
- As the Kd term increases, control resists changes in errors.  In this application, an increase in Kd term first damps oscillations and then causes chatter.

---

### Tuning Method

The model was manually tuned with the goal of going as fast as possible without crashing.
- First Kp was selected. 0.0625 was found to be a good low value that could keep the car on the track.  Higher values caused more turning which slowed down the vehicle at higher speeds.
- Second, Kd was selected. Initially a good value of 1.0 was found.  Lower caused more oscillations.  Double caused chatter.
- Third, Ki was tried.  Due to integral windup, this value was set to zero.
- The throttle values were increased.  At 0.6, it was found that a bump in Kd to 1.2 or 1.4 would be increase path smoothness.

---

### Summary of Final Model 

Kp = 0.0625

Ki = 0.0

Kd = 1.3

Throttle = 0.66

Top Speed = 73 mph
