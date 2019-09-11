# Charlieplex
Arduino charlieplexing example (4 pins, 12 LEDs)

## Original Arduino code from Chuckplex has been heavily modified
I couldn't get the original code to work- the pin numbers seemed to be corrupted (non-sensical at least) when writing outputs to pins, trying to address pin 24652 for example.

So I macerated the original Chuckplex library, and made the class a rather clumsily-hacked bit of code for controlling 12 LEDs with 4 pins. 
It has been made less generalised- no class (haha) and fairly 4-pin specific, though I hope to fix this eventually.

## Longer term project
A wordy clock for my wife...
My arduino nano does not have enough outputs for all LEDs independantly, so charlieplexing is the easy way out.
And no- I do not want to use neopixel LEDs- I want to power it with a battery, not from the mains.

### Small python script to make the pin-outs clear.
This displays the (zero-ordered) pin numbers supplying each node (LED).
The original Chuckplex code does a good job of ordering the wiring by pins, rather than node (LED), and I borrowed the nice method of generating the wiring.
