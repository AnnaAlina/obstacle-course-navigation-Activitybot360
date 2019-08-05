# obstacle-course-navigation-Activitybot360
Closed loop obstacle course navigation using the Parallax ActivityBot 32600.


Three of the proximity sensors were used on the robot; one on the front, left and right each. Once the front proximity sensor would detect an obstacle, the robot would turn to the left, which is towards the direction of the exit at the end of the track. Once the car turned 90° to the left, the right prox sensor would trigger. The robot continues to hug the obstacle until the right proximity sensor no longer detects on obstacle, in which case it turns to face the direction of the exit, or until an obstacle is detected at the front face of the robot, in which case the robot turns 180°. If the robot turns 180°, it will repeat the same obstacle hugging process, this time waiting for the left proximity sensor to trigger. Logically, this will guide the robot to the exit, preventing it from taking any unnecessary steps or turning back towards the start line.
