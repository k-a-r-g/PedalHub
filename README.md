# PedalHub

Hi Pete,

Assemble the circuit, edit the preferences (i.e. number of pedals you implemented) flash the firmware and open a serial console.
So far the code does not send any MIDI messages, but is for first confirming the wiring.
Therefore, it will print all readings to the serial console.

Format is: first all connected momentary pedals, then the continuous one.

I implemented TRS connections for all pedals (for the momentary pedals TS is enough, so change it to your likings).
Of course there are no real standards for the wiring of expression pedals, so we need to try and error how yours are built. It maybe that tip and sleeve needs to be swapped.

Also I added capacitors to filter noise that might get picked up by long cables...
