# Problem Statement: 
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file
    o longest compounded word
    o second longest compounded word
    o time taken to process the input file
Note: A compounded word is one that can be constructed by combining (concatenating) shorter words
also found in the same file.



# Steps to Run the Code: 
(1) Make sure you have CodeBlocks installed on your system along with environment setup for C++.
(2) Clone the Repository and open the respective Folder (with main.cpp, Input_1.txt,Input_02.txt file) in code editor.
(3) In CodeBlocks, press F9 or click on the "Build and Run" button.
(4) You can prefer any other code editor according to your choice.


# Approach and Algorthim used : 

(1) Read each word from the selected file and construct a trie data structure.
(2) Afetr building the trie,create a queue containing pairs of the form <word, suffix> in cases where a valid word exists previously in the trie.
(3) Set up variables longest, second_longest.
(4) Main Loop:
    Continue the following steps until the queue is empty:
    -> Processing Pairs:
       Pop a <word, suffix> pair from the queue.

    -> If the suffix of the word contains a valid prefix from the trie 
            -> If the length of the word exceeds the current maximum length (max_length), update second_longest = longest, longest = word.
            -> If it doesn't exceed the current word length , then we break the current suffix into a prefix and new_suffix and push new pair 
            <word,new_suffix> in queue.

    ->If the suffix of the word doesn't contain a valid prefix, this means that the word is not a coumpounded word and thus we break from the loop.

# Time Complexity:
Time complexity of this algorithm is O(kN) , where N is total number of words in the INPUT.txt file .
For each word in the input file we process the word by breaking it into k words.





