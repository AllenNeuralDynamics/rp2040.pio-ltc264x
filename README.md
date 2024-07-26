Driver for producing DAC output values from the LTC2641 and LTC2642.

This library uses a PIO program to send analog values from memory to the LTC2641.

## Examples
To see this driver in action, have a look at the [examples](./examples) folder.
Additionally here is a project that use this driver in the wild:
* [Harp.Device.Treadmill](https://github.com/AllenNeuralDynamics/harp.device.treadmill)

## Requirements
This program assumes:
* 125MHz pio clock source

This program consumes:
* 1 PIO state machine
* 9 state machine instructions
