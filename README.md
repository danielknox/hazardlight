# Hazard Light Library
A easy to use L298N library to create a hazard light with Arduino.

## NOTICE
L298N modules have the ability to drive upto 4 DC devices at once from 2 channels. However, each channel should only drive a compatible 'pair' of devices; for example, a headlight may have main and dipped modes. In this scenario you don't want both lights on at the same time, so a single channel is suitable to drive both, as it enforces that only one light can be on at any one time. On the other hand, if I wanted to drive headlights and a hazard light I should put the hazards on one channel and the headlight on the other.

This library is intended to pilot only a single channel. So if you need to drive more lights (e.g. headlights), you either need another instance of this library or (more likely) the headlight library.

## INSTALL THE LIBRARY
Download this repository as a .zip file and from the Arduino IDE go to *Sketch -> Include library -> Add .ZIP Library*

## IMPORT
You can import the library in your code using the Arduino IDE going to *Sketch -> Include library -> hazardlight*
or directly writing the include statement in your code:

```
#include <hazardLight.h>
```
## INSTANCE THE MODULE
To drive a device the first thing is to create an instance of the library.
```
Hazardlight myHazard(IN1, IN2);
```
* IN1 and IN2 are two digital pin connected to IN1 and IN2 (or IN3 and IN4) of the module

## Methods
| Method | Params | Description
| :----- | :---------- | :------
|**on**|uint8_t mode| Turn on hazard light. 
|**off**|none| Turn off the hazard light.
|**startFlashing**|unsigned long rate| Flash hazard light for at a specified flash rate (use in main loop to create fake non-blocking multi-tasking -- uses millis).
|**stopFlashing**|none| Stop a flashing hazard light.
|**flashFor**|unsigned long delay, unsigned long rate| Flash hazard light for a time specified by delay and flash rate (use in main loop to create fake non-blocking multi-tasking -- uses millis).
|**flashFor**|unsigned long delay, unsigned long rate, CallBackFunction callback| Flash hazard light for a time specified by delay and flash rate, after flash execute the callback function.
|**reset**|none| Used to re-enable hazard light after the use of flashFor or startFlashing method.
|**isOn**|none| Returns a boolean indicating if hazard light is on or not.
