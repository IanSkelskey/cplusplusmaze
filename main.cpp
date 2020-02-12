#include <iostream>
using namespace std;

class MazeNode{
public:
  MazeNode(){
    N = this;
    S = this;
    E = this;
    W = this;
  }
  void setDir(MazeNode * North, MazeNode * South, MazeNode * East, MazeNode * West){
    N = North;
    S = South;
    E = East;
    W = West;
  }
  MazeNode * getN(){return N;}
  MazeNode * getS(){return S;}
  MazeNode * getE(){return E;}
  MazeNode * getW(){return W;}

  string canGo(){
    string s = "";
      int dirs = 0;

      if(getN() != this){
        s = "North";
      }
      if(getS() != this){
        s += s == "" ? "South" : ", South";
      }
      if(getE() != this){
        s += s == "" ? "East" : ", East";
      }
      if(getW() != this){
        s += s == "" ? "West" : ", West";
      }
      return s;
  }

  ~MazeNode(){
    delete N;
    delete S;
    delete E;
    delete W;
  }

private:
  MazeNode * N;
  MazeNode * S;
  MazeNode * E;
  MazeNode * W;  
};

int main() {
  MazeNode * Maze[12];
  for(int i = 0; i < 12; i++){
    Maze[i] = new MazeNode;
  }

  Maze[0]->setDir(Maze[0], Maze[4], Maze[1], Maze[0]);
  Maze[1]->setDir(Maze[1], Maze[5], Maze[1], Maze[0]);
  Maze[2]->setDir(Maze[2], Maze[6], Maze[3], Maze[2]);
  Maze[3]->setDir(Maze[3], Maze[3], Maze[3], Maze[2]);
  Maze[4]->setDir(Maze[0], Maze[8], Maze[4], Maze[4]);
  Maze[5]->setDir(Maze[1], Maze[5], Maze[6], Maze[5]);
  Maze[6]->setDir(Maze[2], Maze[10], Maze[7], Maze[5]);
  Maze[7]->setDir(Maze[7], Maze[11], Maze[7], Maze[6]);
  Maze[8]->setDir(Maze[4], Maze[8], Maze[9], Maze[8]);
  Maze[9]->setDir(Maze[9], Maze[9], Maze[9], Maze[8]);
  Maze[10]->setDir(Maze[6], Maze[10], Maze[10], Maze[10]);
  Maze[11]->setDir(Maze[7], Maze[11], Maze[11], Maze[11]); 

  MazeNode * currNode = Maze[0];

  char ch;
  bool valid;

  do{
    cout << "You can go: " << currNode->canGo() << endl;

    do{
      valid = true;
      cout << "Choose a direction (N, S, E, or W): ";
      cin >> ch;

      switch (ch){
        case 'n' :
        case 'N' : currNode = currNode->getN(); break;
        case 's' :
        case 'S' : currNode = currNode->getS(); break;
        case 'e' :
        case 'E' : currNode = currNode->getE(); break;
        case 'w' :
        case 'W' : currNode = currNode->getW(); break;
        default : valid = false;
      }
    }while(!valid);
  }while (currNode != Maze[11]);

  cout << "You are outside." << endl;

  return 0;
}