# Die

An Arduino project. It's pretty simple. I've got a single LED digit and a
single button. When the button is pressed, it will cycle through random numbers
for a (configurable) number of times, then settle on a particular digit.
Malcolm, my son, suggested the project so that we could play Ludo this
afternoon.

I'm reasonably pleased with it. It works, which is the main thing. I also had
fun implementing it by hacking and around, getting it to work, then
refactoring. The refactoring bit was a) lots of fun; and b) a reminder that my
C++ is pretty rusty.

## Hardware Required

* An Arduino. I've been using an Arduino Uno.

* An LED digit with discrete pins for each segment. (This is around the point
  where I feel the words I'm using show me off as being a n00b!)

* A pile of resistors. I know enough to know that I need to stick some value of
  resistor in front of an LED, so I bunged a 1K ohm resistor in front of each
  of the segment's pins. I suspect I could have used a single resistor on the
  common power line instead, but I didn't feel like accidentally destroying any
  hardware today. :)

* A push-button.

The actual pins used on the Arduino aren't important - there's a mapping up the
top of the sketch file for deciding which pins map to which segment/button.

I should find some handy web app for drawing simple circuit diagrams sometime
to include a diagram, too.

## Building

I've been using [Ino](http://inotool.org/) to build and upload Arduino projects
from the comfort of the command line. You'll need to have:

* The [Arduino IDE](http://arduino.cc/en/Main/Software) installed in the
  standard location where ino can find it.

* For serial communications (not used in this project) you'll need to have
  [picocom](https://code.google.com/p/picocom/) installed. For me, that was
  `brew install picocom`.

* ino itself installed. If you've already got a sensible Python install, it's
  just a case of `pip install ino`.

To build the project, from the project root, run:

    ino build

And to upload it to the board, run:

    ino upload

That should be it.

## Comments

Any comments, (say, for example, constructive feedback!) feel free to get in
touch. I'm Graeme Mathieson <mathie@woss.name> and I'm
[@mathie](https://twitter.com/mathie) on Twitter.

## License

It's only right that all software, no matter how trivial, has a license so that
you're clear on nicking any bits of it. :) This code is under the terms of the
MIT license:

Copyright (c) 2013 Graeme Mathieson <mathie@woss.name>.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
