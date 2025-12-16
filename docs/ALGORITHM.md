# Control Algorithm Description

## Vehicle Density Evaluation
Vehicle density is estimated using a YOLO-based object detection model. Each detected vehicle contributes to the lane density score.

## Timing Computation Logic
Green signal duration is calculated using:

Green_Time = Base_Time + (Vehicle_Count × Scaling_Factor)

Constraints:
- Minimum and maximum green time limits are enforced
- Only one direction receives GREEN at a time
- All transitions include a YELLOW safety phase

## Synchronization Strategy
The master controller broadcasts the current signal state to all slave controllers. Slaves update their state immediately upon receiving the signal, ensuring deterministic synchronization and preventing conflicting outputs. 
