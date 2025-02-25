#include "huffman.h"

int main()
{
    HuffmanCoding h = HuffmanCoding();
    string text = "testing of huffman coding 0099100000";
    
    cout << "original text: " << endl << text << endl;

    //run required huffman tree functions
    h.buildTree(text);
    h.printFrequency();
    h.printCodes();
    h.printEncodedString(text);
    
    string encodedText = h.getEncodedString(text);
    h.printDecodedString(encodedText);
}
