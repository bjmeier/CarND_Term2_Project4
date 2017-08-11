# CarND_Term2_Project4
PID Control

---

### Project Summary

This project utilizes the Udacity Simulator to control the path of a car. The path is controlled by the use of a Proportional-Integral-Derivative Controller. The input for the controller is the cross track error, CTE. The output of the controller is the steering angle/ maximum steering angle, SA.

---

### Equations

- Proportional Error, P_error = Kp x CTE[k]
- Integral Error, I_error = Ki x sum(CTE[i]|i = 1 to k)
- Derivative Error, D_error = Kd x (CTE[k] - CTE[k-1])
- SA = - Kp x CTE[k] - Ki x sum(CTE[i]|i = 1 to k) - Kd x (CTE[k] - CTE[k-1])

---

### Effect of Modifying Parameters, Kp, Ki and Kd

- As the Kp term increases, so does response to the CTE error.  In this application and absent Ki or Kd terms, this causes an increase in the the oscillation frequency.
- As the Ki term increases, the longer CTE error occurs, the stronger the response. It is often used to remove steady-state error.  In this application, integral windup makes this term undesirable. As vehicle makes a turn, the Ierror increases and causes oscillations upon the exit of the turn.
- As the Kd term increases, control resists changes in errors.  In this application, an increase in Kd term first damps oscillations and then causes chatter.
- Given the nature of the steering control, this behavior is as expected.

---

### Tuning Method

To achieve the goal of safely maximizing the top speed, the model was manually tuned.
- First Kp was selected. 0.0625 was found to be a good value.  Lower values had difficulty keeping the car on the track.  Higher values caused more turning which slowed the vehicle.
- Second, Kd was selected. Initially a good value of 1.0 was found.  Lower values caused more oscillations.  Higher values caused chatter.
- Third, Ki was tried.  Due to integral windup, this value was set to zero.
- The throttle values were increased.  At 0.6, it was found that slight increases to Kd increased the path smoothness.

---

### Summary of Final Model 

- Kp = 0.0625
- Ki = 0.0
- Kd = 1.3
- Throttle = 0.66
- Top Speed = 73 mph
