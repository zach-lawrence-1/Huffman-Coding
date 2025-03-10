# Huffman Coding Implementation
## Description
With this mini project/exercise, I am teaching myself how huffman encoding works by implementing the algorithm. It is one of the many steps of jpeg image compression and decompression which I would like to maybe try implementing at some point since it is interesting to me.
## How To Run
### Downloading The Code
Download the code and make file as follows
Git:
1. ```git clone https://github.com/zach-lawrence-1/Huffman-Coding.git c```
   - c can be any local directory you want.
2. ```cd c```

OR

Just download zip from github and unzip where you want
### Windows
On windows, as long as you have MSYS2 setup with g++ and you can run make files then you should be able to run the main program clock_ND.cpp as follows:
1. Download code and make file.
2. Open a terminal in the same directory as the code and make file.
3. Type in ```make```
4. run ```./huffman.exe``` or ```./huffman```
### Linux
As long as you have g++ and make installed and running on your linux box, you should be able to run the main program as follows:
1. Open a terminal in the same directory as the code and make file or just navigate there via cd commands.
2. Type in ```make```
3. run ```./huffman```

## Time Complexity Analysis
HuffmanCoding class:

```void encode(Node* root, string text)``` **O(n)**  
Since the length of the input string is of size n and we traverse that many times in our huffman tree.

```void printCodes()``` **O(n)**

```void printFrequency()``` **O(n)**

```string getEncodedString(string text)``` **O(n)**

```void printEncodedString(string text)``` **O(n)**  
Since getEncodedString(string text) is called.

```string decode(string text)``` **O(n)**

```void printDecodedString(string text)``` **O(n)**  
Since decode(string text) is called.

```void buildTree(string text)``` **O(nlog(n))**  
Since we are inserting n elements into a min heap based priority queue.

```void clear()``` **O(n)**
