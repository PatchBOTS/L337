
[![L337](https://i.imgur.com/zFueaPk.jpg)](https://www.youtube.com/watch?v=H4KK212-Jss)
# L3-37 Voice Assistant
### Please Read Before Downloading 3D File

## Overview

## CODE
# Amazon Voice Services Code 
My friend @henrymendez is helping me with this section.  There may be a video tutorial down the line, but at the very least Henry will be writing a super awesome script to speed up the install process.  Check back. 

# Arduino Code
Very simple code. My goal is to eliminate the Arduino altogether, but for now this operates the servo and the neopixels. 

## 3D Files
The 3D files are free for download.  There will be some updates in the near future to a couple of the main parts.  If you see a "-CS" attached to any of the files, that means it is "changing soon,"  print those last. 

I'm happy to distribute these files for free but they are not guaranteed to work.  I am very big on the "print quick and dirty and fix later" philosophy, so there may be some physical editing to the parts needed which I did not document. 

## Changes coming in V2
### Physical
At the moment L3's head lists a little to the left. This is because of my 'smart' idea to only attach via the servo spline. I'm going to modify the top of the neck piece to add in a small axle to support the load.  Also, I'm going to expand the top of the neck piece to hold some of the components (of which there will hopefully be fewer of) to take some weight off the perimeter. 
### Electrical
There is a slight hum to the amplifier. I'm going to do more research on power de-coupling and ground loops to see if I can eliminate it. I have a feeling if I get rid of hte arduino circuit that will help.  Also, I'm hoping to be able to eliminate the SBEC which I'm sure isn't helping anything. 
### Components
As mentioned above I'm going to try to eliminate the arduino and circuit board all together. This will make the entire project less complicated and less noisy in the wires. 
I used a MEGA Scale Servo because I happened to have one on hand.  L3's head came in surprisingly light, so I think if I add in the axle to support more of the weight (which will also be moved off the head) I can use a much less powerful servo which doesn't require the SBEC.  
At the moment I'm using a cheap buck converter chip to step down the voltage. I'm going to upgrade this to a board with better voltage stability to hopefully help the amplifier hum. 
### Coding
I'm going to try to figure out more about coding the pinouts on the Pi.  If I can get two pinouts with one running a software PWM, I can eliminate the Arduino altogether.  I think this is the key to V2. 
