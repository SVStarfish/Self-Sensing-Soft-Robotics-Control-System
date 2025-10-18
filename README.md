# Self-Sensing Soft Robotics Control System 

An Arduino-based soft robotic gripper capable of sensing contact through pressure and a custom-built flexible resistance sensor.  
This project characterizes the **sensor–actuator response curve** (ΔR/R vs. pressure) and **lays the foundation for future slip detection and adaptive gripping control**.


---

## Features
- Custom-built pneumatic actuation system with flexible resistance sensor  
- Real-time acquisition of pressure and ΔR/R signals  
- Characterization of sensor–actuator dynamic response curves  
- Planned: slip detection and adaptive pressure control


---

## Hardware Components

- Soft Robot,Microcontroller,Pressure Sensor,Flexible Sensor,Solenoid Valve,Relay,Air Pump<br>
<p align="center">
 <img src="docs/experiment platform.png" alt="Experiment platform" width="60%">
</p>



## Experimental Procedure
### 1. Molding
<p align="center">
  <img src="docs/molding.png" alt="Molding" width="60%">
</p>

### 2. Testing
<p align="center">
  <img src="docs/image1.png" alt="Inflating1" width="20%">
  <img src="docs/image2.png" alt="Inflating2" width="20%">
  <img src="docs/image3.png" alt="Inflating3" width="20%">
</p>

### 3. Flexible Sensor Integration
<p align="center">
  <img src="docs/integrated.png" alt="Sensor integrated" width="60%">
</p>

### 4. Data Collection
<p align="center">
  <img src="docs/raw data1.png" alt="Raw data 1" width="60%">
  <img src="docs/raw data2.png" alt="Raw data 2" width="60%">
</p>

### 5. Visualization
<p align="center">
  <img src="docs/visualization.png" alt="Visualization" width="60%">
</p>

### 6. Curve Fitting
<p align="center">
  <img src="docs/fitting.png" alt="Fitting" width="60%">
</p>

**Model**:  
\[
f(x) = 1.049*exp(0.0002777*x)
\]

*(95% confidence bounds: a = 0.7021–1.397, b = 0.0002507–0.0003046)*


## Future Work
- Implement real-time slip detection  
- Add adaptive pressure control loop  
- Improve filtering and stability for longer runs  
- Integrate multiple fingers for full soft robotic hand

