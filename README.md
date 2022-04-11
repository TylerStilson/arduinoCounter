# arduinoCounter

In this project I worked with firmware for the first time. I connected a bread board to the Arduino Uno. I placed a Ultra Sonic Range Finder in the bread board
and connected it to the right inputs and outputs of the arduino. I then programed the Arduino to grab the output of the duration between signals of the ultra sonic 
range finder, do a bunch of math and spit out a distance that the wave lenght went. With that distance we can tell if someone walked by.

Then I have a running number of how many people have walked by. Every minute or 5 minites it can write that number down and reset itself. With the arduino connected
to a raspberry pie, we are able to them send that number to a server that can send that number to the database. 

![Uno pic](/images/IMG_3498.jpg "arduino pic")
