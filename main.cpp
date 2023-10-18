#include<bits/stdc++.h>
#include<fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

struct Node {
	Node *child[26];
	bool isword= false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (child[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		child[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return child[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		isword = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return isword;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}

	vector<int> getsuffices(string s)
	{
	    vector<int>res;
	    Node *node=root;
	    for(int i=0;i<s.size();i++)
	    {
	        if(!node->containKey(s[i]))
	        return res;

	        node=node->get(s[i]);
	        if(node->isEnd())
	        res.push_back(i+1);
	    }

	    return res;
	}
};

int main()
{
    auto start= chrono::steady_clock::now();
    vector<string> vec;
    ifstream inputFile("Input_02.txt");

     if (!inputFile.is_open()) {
        cout<< "Could not open the file.\n";
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    Trie trie;
    for(int i=0;i<vec.size();i++)
    {
        trie.insert(vec[i]);
    }

       queue<pair<string,string>> q;
      for(int i=0;i<vec.size();i++)
      {
          string word=vec[i];
          vector<int> suffix=trie.getsuffices(word);

          for(auto j:suffix)
          {
              if(j>=word.size())
              break;

              string temp=word.substr(j);
              q.push({word,temp});
          }
      }

      int max_len=0;
      string longest="";
      string sec_longest="";



      while(!q.empty())
      {
          auto it=q.front();
          q.pop();
          string original=it.first;
          string suff=it.second;

          vector<int>index=trie.getsuffices(suff);

          if(index.size()==0)
          continue;

          for(auto j:index)
          {
              if(j>suff.size())
              break;

              if(j==suff.size())
              {
                  if(original.size()>max_len)
                  {
                      max_len=original.size();
                      sec_longest=longest;
                      longest=original;
                  }
              }

              else
              {
                   string temp=suff.substr(j);
                   q.push({original,temp});
              }
          }
      }

      auto end= chrono::steady_clock::now();
      auto duration = duration_cast<milliseconds>(end-start);
      cout<<"Longest Compound Word "<<longest<<endl;
      cout<<"Second Longest Compound Word "<<sec_longest<<endl;
      cout<<"Time taken to process file Input_02.txt "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" milliseconds";

    return 0;
}
