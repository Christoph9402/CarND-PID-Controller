# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program


The goal of the project is to implement a PID controller in C++ that steers a vehicle around a track inside the simulator. Criteria for passing are the error-free compilation of the code and the fine tuning of the hyperparameters. The vehicle has to drive successfully one lap around the track in the simulator and must not leave the road or drive over other surfaces. The fundamental structure is based on the procedure implemented in python during the exercises.
To implement the code, the Init() function with hyperparameters must first be called in the Main.cpp file, which initiates the parameters Kp, Ki and Kd, and sets the values p_error, i_error and d_error to 0. After reading the cte and speed values, the double variable "steering_value" must be calculated. For this, two functions are used, which are written in the PID.cpp file.
The first function is the "UpdateError" function, which uses the cte value as an input. In this function the variables "d_error", "p_error" and "i_error", which were previously initiated with the value of 0, are calculated. As described in lesson 12.8, the "d_error" must be calculated by subtracting the value of the previous cte from the cte. I have subtracted the value of p_error here, because it has the value 0 and therefore is omitted at the start. In all subsequent calculations p_error is however equal to cte of the previous step. This is the case because I decided to calculate p_error not until after d_error. P_error is equal to the cte. Finally, i_error must be calculated. This is calculated by adding the cte to i_error. These 3 error components are needed for the calculation of the total error and were presented in lesson 12.12. This is calculated in a further function "TotalError". Within this function the error values updated from the previous function are used and calculated together with the coefficients that had to be initiated at the beginning. The total error can be calculated using the formula:  
error_t=-K_p*p_error-K_d*d_error-K_i*i_error  
This formula was presented in lesson 12.12 and takes into account the proportional error, the derivative error and the integral error. In the main.cpp file I called these functions. First the UpdateError function must be called with the read cte. Here the errors are updated. Afterwards I set the variable steer_Value equal to the function call "totalError", which returns the result of the above mentioned formula. Subsequently, it must be taken into account that the steering_value must not be greater than 1 or less than -1. This is done with a simple if statement. This statement checks if the steering_value is greater than 1 - in which case the steering value is set to 1 - and then with an else if statement if it is less than -1, in which case it is set to -1.  
This completes the implementation of the PID controller. In the following it will be explained which impact a change of the coefficients has on the driving behaviour of the vehicle. For this purpose I first set the hyper parameters Kd, Ki and Kp to 0.0. This results in a total error of 0 and the vehicle does not steer. It drives straight ahead and leaves the track. This can be seen in video 1.  
Video 2 shows the driving behaviour with Kp set to 1.0 and the remaining parameters set to 0.0. Here you can see that the vehicle is driving in a wavy line. The reason for this is that the use of the proportional element alone leads to a steering angle that is proportional to the crosstrackerror. However, this causes the problem that the vehicle will never drive exactly in the middle, but will rather shoot beyond the center.  
Video 3 shows the usage of only the differential part. Because the d_error is calculated as the difference between the current cte and the cte from the previous step, and the cte is very small, the steering angle changes very little and the vehicle does not steer enough, but drives to the road's boundary. Since Kp=0 was set, the driven lane does not adapt to the middle of the lane.  
The fourth video shows the vehicle when only the integral part is set to 1. Here it can be seen that the vehicle turns further with increasing distance and leaves the road. This is describable because the cte is added to the i_error each time. Again no P component is implemented so the vehicle does not turn back to the middle of the lane but the cte increases permanently and the vehicle leaves the lane.  
Videos 5 and 6 show combinations of the previously individually tested components. In video 5, Kp is set to 0.5, Ki to 0.001 and Kd to 1.0. As you can see, the car steers too much and doesn't drive steadily straight. Video 6 shows the result when Kp is reduced to 0.25. Here the result is already quite good.  
After further testing I came to the result, that the values Kp=0.15, Ki=0.001 and Kd=1.5 lead to a satisfying result for me. I came to the conclusion by following the procedure suggested in the Udacity Knowledge base (https://knowledge.udacity.com/questions/297913). At first, I only varied the Kp value. Then I increased Kd and Ki in a slow manner. Finally, I reduced the Kp value again because I felt that the vehicle was driving too much in a snakelike way. As can be seen in the "Final", the car drives around the course without any problems and does not leave the track. But the selection of the parameters took some time manually. A more efficient way would be to use the Twiddle algorithm shown in the exercises, where the hyper parameters are tweaked automatically. However, since my manual trying also led to a solution, I decided not to implement it.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

