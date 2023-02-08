# Image Encryption using Huffman Encoding
University: Ghulam Ishaq Khan Institute of Engineering Sciences and Technology\
Course: Data Structures and Algorithms (Lab)\
Course Instructor: Usama Arshad Janjua\
Group Members: Tahir Muzaffar (2021665), Sarim Ahmad (2021572), Shehryar Ahmad (2021598)

## Instructions on how to run the program:-
First install or fork the complete program from the **master** branch
### On Linux:
1. Install SFML by typing "sudo apt-get install libsfml-dev"
2. In your root of the directory containing the program, run
```
g++ -c <filename>.cpp
```
3. Now run
```
g++ <filename>.o -o app -lsfml-graphics -lsfml-window -lsfml-system
```
4. Run
```
./app
```

### On Windows:
1. Install SFML by clicking [here](https://www.sfml-dev.org/download/sfml/2.5.1/). Let it install at the default location.
2. Copy the .dll files from the bin folder from the path where SFML is installed to the root of thefolder containing your program.
3. In your root of the directory containing the program, run
```
g++ -c <filename>.cpp -I<path where SFML is installed>/include
```
4. Run
```
g++ <filename>.o -o app -L<path where SFML is installed>/lib -l sfml-graphics -l sfml-window -l sfml-system
```
5. Run
```
./app
```

## Libraries used
>Simple and Fast Multimedia Library (SFML) used for graphics.

## Data Structures used in this project

>Hashing\
Binary Tree\
Minimum Queue\
Linked List

## Description
>This is an image compressor, that uses Huffman encoding to compress images. The program is purely written in C++ and requires the SFML library to compile the program.\
We use the basic principle of reading pixel values from an image and storing them in a matrix. Then, counting the frequency of every reoccurring RGB value and storing it. We, then, use those pixel values and their frequencies in a priority queue. The priority queue is used to output those values into a binary tree and this binary tree is then traversed while adding a ‘1’ when it goes to the right node and a ‘0’ while going to the left node to return a binary tree at each leaf node.\
This binary code becomes the code for that respective RGB value, which is stored in the compressed file.
