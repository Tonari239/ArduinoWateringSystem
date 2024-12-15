# Arduino watering system 2024

# Project overview
 This project is a simple watering system made for the Arduino coruse at Sofia University. It was made using Arduino UNO, sensors, hoses and a pump. 
 
 Schematics were made using Fritzing.

### Used components:

* x1 Arduino UNO
* x1 Water pump Arduino Clone, 3-6V 
* x1 Soil moisture sensors Arduino Clone 
* x1 OLED I2c Display 
* x1 Piezo
* x1 LED
* x1 Humidity Sensor DHT22
* x1 Breadboard
* x1 TIP 41c Transistor
* x1 360 ohm resistor
* x1 1.8k ohm resistor
* (Optional) x1 Power Supply module


## Project idea
The arduino gets regular updates from the air humidity and soil moisture sensors. In case the environment is not optimal for growth, the pump will be activated and water is going to pour. When the water supply reaches half of its reserved, an LED is going to light up to indicate that water is going to run out soon. When the water supply completely runs out of water, a piezo is going to start buzzing to alert the outside world that the water needs refilling.

## Images

![A plastic box filled with soil, used as the testing ground of the project. The two sensors are attached to one of the inside walls. A coutout of the bottom part of a  water bottle is attached to the outside of the opposite wall, which will serve as the water source. Inside it, there is a pump with a hose attached to it. The hose has tiny holes pierced at intervals and makes a full circle inside the box, to make sure every part of the soil will be watered. The rest of the components are positioned outside the box](/realization.jpg "A picture showcasing how I arranged my components in the realziation of the schematics.")
![A breadboard schematic of the project](/schematicBreadboard.png)
![A circuit schematic of the project](/schematicCircuit.png)

## TODO
The functionality of the piezo and LED trigger are not implemented yet.

## Future ideas for improvement
 I want to transform this from a watering system to a plant incubator used mainly to get baby plants going, as they are more sensitive to environmental changes :) . There are a few considerations that need to be taking into account for this to happen:
1. Besides water, plants also need light to survive and thrive. I wanted to attach a growth light to the lid of my box, so I can then put it on and forget about the incubator until I need to refill the water tank. Unfortunately, currently I am too much of a coward to work with 220V on this beginner project.
2. Currently, nothing is being done to influence the air humidity. I wanted to create an automated sprayer, which triggers when the air humidity drops below a certain percentage. I was thinking of using a regular spray bottle and a servo motor with an attached string, that pulls the trigger on the spraying bottle, but I feel there should be a smarter way to implement this, such as a spraying module
## Tutorials used

[Using the pump with the transistor](https://blog.zerokol.com/2013/03/water-pump-with-arduino.html)

[Using the OLED display](https://www.instructables.com/Monochrome-096-i2c-OLED-display-with-arduino-SSD13/)

