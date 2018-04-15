# homework1

# Cyberfisic course
- Author: Moreno Bragaglio
- Date: 15/04/2018

# Execution
The execution of the program takes place through the use of a launch file located in "launch/homework1.launch". To run it, just run the command "roslaunch <package_name> homework1.launch" from the terminal. 

This launcher takes care of tackling all the necessary nodes.

# Planning
Three nodes (server1, server2, client) have been implemented. The server1 and server2 nodes communicate with the client node which in turn displays the result of the program.

# server1.cpp
Node that publishes a message (fields: name, age, course of studies) at the frequency of 1Hz on the topic "server1Topic". This message is located at the "msg/messaggio.msg" path.

# server2.cpp
Node that publishes (at the frequency of 1Hz) on the topic "server2Topic" a message composed of a character. This character, typed by user, can be:


	a - Print all message


	c - Print course of study


	e - Print age


	n - Print name	


	q - Exit
 
# client.cpp 
Node that:


	- Listens the topic "server1Topic" from which it receives a complete string. 


	- Listens the topic "server2Topic" from which it receives a character used to select a part (complete or not) of the string read from "server1Topic". 


	- Print the result at the frequency of 1Hz.
