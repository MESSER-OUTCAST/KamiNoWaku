# **KAMI NO WAKU C Framework**
    +-----------------------------------------+
    |⠄⣾⣿⡇⢸⣿⣿⣿⠄⠈⣿⣿⣿⣿⠈⣿⡇⢹⣿⣿⣿⡇⡇⢸⣿⣿⡇⣿⣿⣿|
    |⢠⣿⣿⡇⢸⣿⣿⣿⡇⠄⢹⣿⣿⣿⡀⣿⣧⢸⣿⣿⣿⠁⡇⢸⣿⣿⠁⣿⣿⣿|
    |⢸⣿⣿⡇⠸⣿⣿⣿⣿⡄⠈⢿⣿⣿⡇⢸⣿⡀⣿⣿⡿⠸⡇⣸⣿⣿⠄⣿⣿⣿|
    |⢸⣿⡿⠷⠄⠿⠿⠿⠟⠓⠰⠘⠿⣿⣿⡈⣿⡇⢹⡟⠰⠦⠁⠈⠉⠋⠄⠻⢿⣿|
    |⢨⡑⠶⡏⠛⠐⠋⠓⠲⠶⣭⣤⣴⣦⣭⣥⣮⣾⣬⣴⡮⠝⠒⠂⠂⠘⠉⠿⠖⣬|
    |⠈⠉⠄⡀⠄⣀⣀⣀⣀⠈⢛⣿⣿⣿⣿⣿⣿⣿⣿⣟⠁⣀⣤⣤⣠⡀⠄⡀⠈⠁|
    |⠄⠠⣾⡀⣾⣿⣧⣼⣿⡿⢠⣿⣿⣿⣿⣿⣿⣿⣿⣧⣼⣿⣧⣼⣿⣿⢀⣿⡇⠄|
    |⡀⠄⠻⣷⡘⢿⣿⣿⡿⢣⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣜⢿⣿⣿⡿⢃⣾⠟⢁⠈|
    |⢃⢻⣶⣬⣿⣶⣬⣥⣶⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣷⣶⣶⣾⣿⣷⣾⣾⢣|
    +-----------------------------------------+
    Demo Banner source: https://emojicombos.com/

## About:

    This framework is intended to be a one stop shop for command line programs written in C.

## Features:

    Continuous refresh with user definable banner, prefabricated text coloring, tutorial commentary, and easy logging integration.

## Author Notes:

* I do not claim to be an expert in control flow but this is how I like to craft most of my projects now and I would like to share it with you.

* The principle design is based on "context switching" with static outputs.

* Static output is derived from the terminal refreshing after every I/O sequence.

* A context switch in the case of this framework is a subroutine where command and control is handled deterministically by user defined function codes.

* These function codes are specified as jump locations in an anti-duff device.

* This allows intuitive command line processing where methods/functions/subroutines called from user input can be self contained in a discrete manner.

* It also reduces developer overhead where one can find themselves adding memcmp() and strcmp() at various locations within other software non-uniformly.

* Read the developer notes throughout the source code thoroughly if you are interested in incorporating this framework in your next project.
----------
Lastly, understand that persistent and/or stateful data in this software is intended to be carried throughout the entire program. This does not include any temporary memory which would otherwise be allocated for looping or string checking. I strongly adhere to this principle because it makes overall control flow extremely easy to understand while effortlessly incorporating global data into a uniform structure accessible anywhere in the code. If you think my anti-duff device for command line interaction is dumb and take nothing else, this technique will elevate your C programming skill.
