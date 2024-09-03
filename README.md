# PingPong
Pong game with C++ 



Pong defines the collision fundamentals and helps in implementing the idea into a test within a simulated environment. The primary region of interest is understanding how the objects, in this case the **ball** and the **bat** interacts with each other and the environment it is being played in. 

![pong](https://github.com/user-attachments/assets/383ee662-2b31-4fba-a5fc-38fc19d2ecd4)
*Fig: Ping Pong gameplay sample*


### Bat movement
The primary goal of the bat is to move left and right and making sure to hit the ball before it hits the ground. The speed can be estimated based on the window resolution and some estimated window sizes for better player experience. Play around with the bat speed in `Bat.h` to see how it affects the overall gameplay.

### Ball movement
Ball appears at the top of the screen and moves towards the bottom with a constant speed. Speed is defined on `Ball.h` and changing that can enable different experience for the player.

**Collision**\
Upon hitting the sides, the ball rebounds at the same angle as the angle of incidence. Incident angle and Rebound angle are kept equal by inverting the *horizontal* component of the ball i.e inverting the *x-axis* component and keeping the *y-axis* component as constant. Similarly, when the ball hits the bat or top it inverts the *vertical* component i.e the *y-axis* and keeps the horizontal or *x-axis* component const. 

The **AABB or Axis Aligned Bounding Box** collision technique is implemented here to detect collision of the ball with the bat and window sides. If the top of the ball is greater than the height of the window, it is considered as out of screen and thus the ball *rebound* function is called. The ball reappears at the top of the screen and the **lives** is decremented.

```python
ball.top > window.bottom # hits bottom 
ball.top < window.top # hits top
```

Similarly, when the left end of ball is less than the left side of window and right end of the ball is greater than the right side of window, it is considered as a collision and thus *rebound* function is called and the ball direction is reversed.

```python
ball.left < window.left_edge # hits left
ball.right > window.right_edge# hits right
```



### Points and Lives
Upon hitting the top of the screen the **score** is incremented and added to the total score. When the ball misses the bat the **lives** value is decremented and the ball resets at the top of the screen. 





## Getting started

Build and run the game. Make sure to install the `SFML` library before compiling.
```bash
g++ src/*.cpp -o bin/game.app -lsfml-graphics -lsfml-window -lsfml-system
./bin/game.app
```
