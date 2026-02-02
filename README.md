# Plant Disease Detection Rover

## Project Overview
This rover autonomously navigates using IMU for orientation, captures images with a Logitech USB webcam, and detects diseases via an Edge Impulse "MobileNetV2" model on the Arduino Uno Q board. Developed for Qualcomm's "AI For All" event, it targets potato plant diseases but supports expansion to other crops through model retraining. The dual-core Arduino Uno Q handles real-time motor control on its ARM Cortex-M4 and AI inference on the ARM Cortex-A7 Linux side. [arduino](https://www.arduino.cc/product-uno-q)

## Hardware Components
- **Arduino Uno Q Board**: Dual-core (Cortex-M4 @120MHz for RT, Cortex-A7 @1GHz for Linux/AI), 512MB RAM, 4GB storage, USB-C, WiFi/BT.
- **DC Motors + L298N Driver**: Two motors for differential drive; L298N handles direction/speed (up to 46V, PWM via Arduino pins).
- **IMU Sensor**: 6-9 axis (e.g., BMI270/BMM150 or QMI8658) for navigation, yaw/pitch/roll via I2C. 
- **Logitech USB Webcam** (e.g., C270/C920): Connected via USB hub for live image capture in Linux mode.

## Software Architecture
The system runs in Arduino Uno Q's SCP (Linux) mode via Arduino App Lab IDE, integrated with Edge Impulse. IMU/motors use Arduino RT firmware (C++ libs); camera/AI use Linux. Edge Impulse model (MobileNetV2) classifies potato diseases from webcam frames.

## Edge Impulse Model
1. Collect potato leaf images (healthy, early/late blight, etc.) via public datasets or field capture.
2. Train object detection block for disease spotting; optimize for edge (quantize to int8). 
3. Deploy as Linux C++ or Python library for Arduino App Lab; handles USB camera input. 


## Setup Instructions
1. **Board Setup**: Flash Arduino Uno Q to SBC mode; install Arduino App Lab (browser-based IDE).
2. **Libraries**: RT side - Wire, motor libs; Linux - Edge Impulse SDK, OpenCV, V4L2 for webcam.
3. **Deploy Model**: From Edge Impulse, download Linux library; integrate into App Lab app.
4. **Power On**: Connect hub/webcam/HDMI (optional); boot to Linux; run app via browser. 
5. **Calibrate**: Zero IMU; test motors; verify camera feed.

## Future Expansions
- Multi-crop models via Edge Impulse retrain.
- GPS/encoder fusion for better nav.
- Twilio SMS alerts (user pref).
- Farm21 integration for IoT dashboard.
