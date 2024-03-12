#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type

unordered_map<string, vector<string> > nbrs; // Map to store neighboring nodes

unordered_map<string, bool> visited; // Map to track visited nodes

unordered_map<string, int> d; // Map to store distance

unordered_map<string, string> predecessor; // Map to store predecessors

//Implement breadth-first search, refer to Lab 10
int findPath(string, string, vector<string> &); 
void buildGraph();

void wordLadder(string s, string t, int &steps, vector<string> &p) {
    buildGraph();              // Build the graph
    queue<string> toVisit;     // Queue to perform BFS
    toVisit.push(s);           // Push source to queue
    visited[s] = true;         // Mark word as visited
    d[s] = 0;                  // Set distance from source to itself to 0

    while (!toVisit.empty()) {
        string currentNode = toVisit.front();           // Get front element of queue
        toVisit.pop();                                  // Remove front element of queue
        for (string neighbor : nbrs[currentNode]) {
            if (!visited[neighbor]) {
                predecessor[neighbor] = currentNode;    // Set predecessor for neighbor
                d[neighbor] = 1 + d[currentNode];       // Set distance for neighbor
                visited[neighbor] = true;               // Mark neighbor as visited
                toVisit.push(neighbor);                 // Push neighbor onto queue
            }
        }
    }

    steps = findPath(s, t, p);      // Find and store the path
}

// Helper function to find path using predecessor map
int findPath(string start, string end, vector<string> &path) {
    if (predecessor.find(end) == predecessor.end())
        return 0; // If end node has no predecessor

    if (start.compare(end) != 0) {
        int step = 1 + findPath(start, predecessor[end], path);
        path.push_back(end);  // Add the current word to path
        return step;          // Total steps in path
    } else {
        path.push_back(end);  // Add current word to path
        return 0;             // Start and end words are same
    }
}

// Helper function to build graph from file
void buildGraph(void) {
    ifstream wordFile("wordlist05.txt");
    string currentWord;

    while (wordFile >> currentWord)
        V.push_back(currentWord);

    // Make neighboring nodes for each word
    for (auto word : V) {
        for (int place = 0; place < word.length(); place++) {
            for (char letter = 'a'; letter <= 'z'; letter++) {
                if (letter == word.at(place))
                    continue; // Letter is the same as current letter

                string current = word;
                current.at(place) = letter;
                nbrs[word].push_back(current); // Add neighboring nodes to map
            }
        }
    }
}

/*int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}*/
