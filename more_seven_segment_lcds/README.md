# More 7-segment LED displays

This time I've got a four-digit, seven segment LED display, where
they're all wired up in a matrix, with each segment being the anode
and each digit pin being the cathode.

It took me a while to wrap my head around it, but what's happening
here is that it's constantly refreshing, and that's how the right
segments appear to be lit. Here's what's happening:

Repeat forever:
  For each segment:
    Switch the segment pin on.

    For each digit:
      If the segment for this digit should be lit:
        switch the digit pin on.

    For each digit:
      Switch the digit pin off.

    Switch the segment pin off.

And that gives us the illusion of the right segments being lit on
each digit.

Inside that loop, there are two identical loops for iterating through
the digits; one to switch the appropriate digits on and one to switch
all the digits off. It's possible to combine the two, but the display
is dimmer, because it's being flashed on for less time! I tried
playing around with collapsing the loops and inserting a `delay(1)`
instead, but that gave me a (barely discernable, to be fair) flicker.
It looks like the delay caused by the pair of for loops is just
enough to be right!

That's enough for tonight; tomorrow I shall attempt to tidy it up
into a reusable library...
