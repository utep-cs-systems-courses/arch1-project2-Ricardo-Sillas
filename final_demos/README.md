## Lab Two: Blinky Buzzy Toy

Description
===========

For this lab, given three differnet type of demos for the msp430, One for the
buttons, another for the sound, and the last one was for the led, we were
supposed to make a toy utilizing these three demos, somehow implementing a way
to switch lights, dim the lights, and playing some kind of sound. 

Button One:
===========

For my first button, I had it coded in a way where if you were to press the
button, then it would follow a binary pattern, where it would first display
the green led, then the red led, then both leds, then turn both leds, off. For
it to continue, you must press the button rather than holding it down.

Button Two:
===========

For my second button, similar to the first button, uses the leds once
again. The difference is that the patter for this button is it first displays
the red led, then turns on the green led, then turns off the red led, and
finally turns off the green led. Another difference is that for this sequence
to continue, you must hold the button down. Also, this button also has a reset
led function, where if you were to press the button, it would automatically
turn both leds off, given that either one of them were on.

Button Three:
=============

For my third button, I had it so that any time you were to hold down the
button, it would dim the light that is already on. It only works if you were
to use it with the first button lights.

Button Four:
============

For my fourth button, I had it playing a song. In order to continue the song
<<<<<<< HEAD
all the way, you would have to hold down the button. I had a bug with this
section, which was figuring out how to turn off the song once you let go of
the button, but to reset the song you would just have to hold down any other
button and it would reset the song.
=======
all the way, you would have to hold down the button. I had a couple of bugs
with this section, like how to turn off the song once you let go of the
button, or how to play the same not twice instead of making it a single long
note, but if you would like to reset the song, then you would just hold down
any other button and it would reset the song.

Assembly Code:
==============

I ended up changing button one code into assemby, where it would just do a 
binary sequence everytime you pressed the button.
>>>>>>> 0f8fe1121210b1977e0e59a21db492ee8a5a6112
