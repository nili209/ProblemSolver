# ex4
### Introduction:   
The program opens a server on a port that is given as input,  and waits to receive clients.  
The clients who connect to the server can send a problem that they want the program to solve.  
The program can solve two types of problems:   
1. String inversion problem - given a string, the program returns the inverted string.  
2. Finding the cheapest route on the graph - the program reads a row of comma-separated values and returns a string with the directions in which they should go in order to get from the start point to the end point at the lowest cost.
#### Highlights: 
The values can be positive numbers, or a -1, which represent a wall, which means that it is impossible to pass through such a vertex.

### Behind the Scenes: 
The program has a cache.  
Given a problem, it first checks if it already exists in the cache. If not, it checks to see if it is in the files.  
If the solution is already in the cache or the files, we will select it in O(1) and return it to the client.  
Otherwise, we will solve the problem, save it in cache and files, and return it to the client.  
The program can work in two ways: 
1. Serial server: The program serially handles clients.  
2. Parallel servers: The program handles clients in parallel (can handle up to 10 customers at once).   
  
The server has a limited time of about 2 minutes to wait for the client to send the problem.  
After that time, the program prints a timeout message on the screen, and the customer will need to
reconnect if he wants to send more issues.  

### How to run the code: 
All code files must be placed in the same folder, then you need to open the terminal in the folder location
and write the following command in the terminal to compile the code:   
_g ++ -std = c ++ 14 * .cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread_

Then, to run the code, write:  
./a.out _port_  
Where _port_ is the port number on which the program should open the server.  
When "server is now listening" is printed, the user has to log in as a client and send problems as explained above.  
You can run an example of a python script named auto_client.py, which sends a problem from a txt file called matrix_test.txt.
(Also provided as an example). To run auto_client.py, you must put the auto_client.py and matrix_test.txt files in a folder in the code
files folder and open the terminal from that folder and type the following line:  
_python3 auto_client.py -vv_

#### Versioning  
We used [Github](https://github.com/shiraz318/ex4) for version control

#### Authors:   
Shiraz and Nili
