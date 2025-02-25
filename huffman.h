#pragma once

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

using std::string;
using std::unordered_map;
using std::queue;
using std::priority_queue;
using std::vector;
using std::cout, std::endl;

/*
huffman algo:
1. get frequencies of all chars in string
2. create a node which has a unique character from the string with its frequency and add to min priority queue
3. make tree where the nodes from pq are leafs and we make nodes where the top two elements of pq are its children
and its frequency is the sum of the childrens frequencies and then pop top two elements
4. after making node push it to pq and repeat until pq only has the final node which is our root
5. make huffman codes for each character based on tree
*/

class Node
{
    private:
        char character;
        int frequency;
        Node* leftNode;
        Node* rightNode;

    public:
        //constructor
        Node(char ch, int freq, Node* left, Node* right)
            : character(ch), frequency(freq), leftNode(left), rightNode(right) {}

        //getters
        char getCharacter()
        {
            return character;
        }

        int getFrequency()
        {
            return frequency;
        }

        Node* getLeftNode()
        {
            return leftNode;
        }

        Node* getRightNode()
        {
            return rightNode;
        }
};

//comparator functor used to make min priority queue
class comparator
{
    public:
        bool operator() (Node* left, Node* right)
        {
            return left->getFrequency() > right->getFrequency();
        }
};

class HuffmanCoding
{
    private:
        unordered_map<char, int> charFreq;
        unordered_map<char, string> charCodes;
        Node* root;

    public:
        //constructor
        HuffmanCoding() : root(nullptr) {}

        //go through the huffman tree and store huffman codes into charCodes
        void encode(Node* root, string text)
        {
            if (root == nullptr)
                return;
            
            if (root->getCharacter() != '\0')
            {
                charCodes[root->getCharacter()] = text;
                return;
            }
            
            encode(root->getLeftNode(), text + "0");
            encode(root->getRightNode(), text + "1");
        }

        //prints stored huffman codes
        void printCodes()
        {
            cout << "Huffman Codes:" << endl;
            
            for (auto iter = charCodes.begin(); iter != charCodes.end(); iter++)
            {
                cout << (*iter).first << ": " << (*iter).second << endl;
            }
        }

        //prints frequencies for each char
        void printFrequency()
        {
            cout << "Frequency Table:" << endl;
            
            for (auto iter = this->charFreq.begin(); iter != this->charFreq.end(); iter++)
            {
                cout << (*iter).first << ": " << (*iter).second << endl;
            }
        }
        
        //returns encoded string from original text in case you want to use it
        string getEncodedString(string text)
        {
            string encodedText = "";
            
            for (char character : text)
            {
                encodedText += this->charCodes[character];
            }
            
            return encodedText;
        }

        //given text that has all characters existing in the charCodes hashmap, print encoded version of it
        void printEncodedString(string text)
        {
            cout << "Encoded String:" << endl;
            cout << getEncodedString(text) << endl;
        }

        //go through huffman tree and decodes encoded string
        string decode(string text)
        {
            string decodedText = "";
            Node* traversalNode = this->root;
            
            for (size_t i = 0; i < text.size(); i++)
            {
                if (text[i] == '0')
                {
                    traversalNode = traversalNode->getLeftNode();
                }
                else
                {
                    traversalNode = traversalNode->getRightNode();
                }

                if (traversalNode->getCharacter() != '\0')
                {
                    decodedText += traversalNode->getCharacter();
                    traversalNode = this->root;
                }
            }
            
            return decodedText;
        }

        //given encoded text print decoded version of it
        void printDecodedString(string text)
        {
            cout << "Decoded String:" << endl;
            cout << decode(text) << endl;
        }

        //builds huffman tree from text
        void buildTree(string text)
        {
            //get frequency of characters
            for (char character : text)
            {
                this->charFreq[character]++;
            }

            priority_queue<Node*, vector<Node*>, comparator> pq;

            //make and add nodes to min priority queue
            for (auto iter = this->charFreq.begin(); iter != this->charFreq.end(); iter++)
            {
                Node* node = new Node((*iter).first, (*iter).second, nullptr, nullptr);
                pq.push(node);
            }

            //make nodes into a tree until only the root remains in the priority queue
            while (pq.size() > 1)
            {
                Node* left = pq.top();
                pq.pop();
                Node* right = pq.top();
                pq.pop();
                this->root = new Node('\0', left->getFrequency() + right->getFrequency(), left, right);
                pq.push(this->root);
            }
            
            text = "";
            encode(this->root, text);
        }

        //deletes huffman tree
        void clear(Node* root)
        {
            if (root == nullptr)
                return;
            
            clear(root->getLeftNode());
            clear(root->getRightNode());
            delete root;
        }

        //destructor
        ~HuffmanCoding()
        {
            clear(this->root);
        }
};
