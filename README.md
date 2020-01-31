# DK-Redshift
Redshift is a simple MIDI controller with an endless rotary encoder that sends program change messages to MIDI instruments. An indicator light changes color when sending data.

![Redshift MIDI Controller](/images/redshift_demo.jpg)

## About
This was a client request for a simple MIDI program change controller. It met their needs nicely and is available in my
[Etsy Store: Circuits & Sawdust](https://www.etsy.com/listing/520197772/redshift-handmade-usb-midi-program).

## How it works
This is a [Teensy LC](https://www.pjrc.com/teensy/) based USB MIDI controller with a quadrature rotary encoder, and an RGB LED. The detented encoder values and the encoder button could be used to set any stepwise MIDI value where smooth analog values are not wanted.

This is programmed within Arduino, using PJRC's excellent [Encoder library](https://github.com/PaulStoffregen/Encoder).