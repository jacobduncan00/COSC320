#include <iostream>
#include <math.h>
#define ROWS 50
#define COLS 50
#define RESET "\033[0m"
#define WHITE "\033[37m" 
#define PURPLE "\033[35m"
#define RED "\033[31m" 

void genGrid(int arr[ROWS][COLS]){
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
        int random = (rand()%101);
        if(random < 25){
            arr[i][j] = 1;
        }
        else{
            arr[i][j] = 0;
        }
        }
    }
}

struct Node{
    Node* parent;
    Node* next;
    Node* prev;
    float getG();
    float getH();
    float getF();
    void setG(float);
    void setH(float);
    void setF(float);
    int x,y;
    float g,h,f;
    bool solid;
    bool currpos;

};

Node Start, Goal;
float Node::getG(){
    float Gxy = parent -> g+1;
    return Gxy;
}

float Node::getH(){
    float Hx,Hy;
    Hx = (x-Goal.x) * (x-Goal.x);
    Hy = (y-Goal.y) * (y-Goal.y);
    return sqrt(Hx+Hy)*10;
}

float Node::getF(){
    return g+h;
}

void Node::setG(float G){
    g = G;
}

void Node::setH(float H){
    h = H;
}

void Node::setF(float F){
    f = F;
}
static Node GRID[50][50];
class listType{
    public:
        listType();
        Node* first;
        Node* last;
        bool isEmpty();
        void pushNode(Node*);
        bool has(Node*);
        Node* getFirst();
        void popNode(Node*);
};

listType::listType(){
    first = NULL;
    last = NULL;
}

bool listType::isEmpty(){
    if(first == NULL){
        return true;
    }
    else{
        return false;
    }
}
void listType::pushNode(Node* nptr){
    Node* curr;
    if(first == NULL){
        first = nptr;
        last = nptr;
    }
    else{
        for(curr = first; curr != NULL; curr = curr -> next){
            if(nptr -> f < curr -> f){
                break;
            }
        }
        if(curr == NULL){
            curr = last;
            curr -> next = nptr;
            nptr -> prev = curr;
            last = nptr;
        }
        else if(curr == first){
            nptr -> next = curr;
            curr -> prev = nptr;
            first = nptr;
        }
        else{
            nptr -> next = curr;
            nptr -> prev = curr -> prev;
            curr -> prev -> next = nptr;
            curr -> prev = nptr;
        }
    }
}

void listType::popNode(Node* nptr){
    if(first != nptr){
		if(last != nptr){
			nptr -> prev -> next = nptr -> next;
			nptr -> next -> prev = nptr -> prev;
		}
	}else if((last == nptr) && (first == nptr)){
			first = NULL;
			last = NULL;
	}else if((last == nptr) && (first != nptr)){
		last = nptr -> prev;
		nptr -> prev -> next = NULL;
	}else if((last != nptr) && (first == nptr)){
		first = nptr -> next;
		nptr -> next -> prev = NULL;
	}
	nptr -> next = NULL;
	nptr -> prev = NULL;
}

Node* listType::getFirst(){
    return first;
}

bool listType::has(Node* nptr){
    for(Node* curr = first; curr != NULL; curr = curr -> next){
        if((curr -> x == nptr -> x) && (curr -> y == nptr -> y)){
            return true;
        }
    }
    return false;
}

class nodeType{
    public:
        nodeType(Node, Node);
        listType closedList;
        listType openList;
        void move();
        void findGoal(int arr[ROWS][COLS]);
        float getDist();
        void printPath();
        void getSides();
        Node* on;
        Node* adj[4];
};

nodeType::nodeType(Node start, Node end){
    openList.pushNode(&start);
}

void nodeType::getSides(){
    int xx = on -> x;
    int yy = on -> y;
    std::cout << "On: " << xx << yy << std::endl;
    Node* South = &GRID[xx+1][yy];
    adj[0] = South;
    Node* West = &GRID[xx][yy-1];
    adj[1] = West;
    Node* North = &GRID[xx-1][yy];
    adj[2] = North;
    Node* East = &GRID[xx][yy+1];
    adj[3] = East;
}

void nodeType::move(){
    on = openList.getFirst();
    on -> currpos = true;
}

void nodeType::findGoal(int arr[ROWS][COLS]){
    float ff, gg, hh;
    std::cout << "Starting position chosen!" << std::endl;
    while(openList.first != NULL){
        move();
        std::cout << std::endl;
        arr[on -> x][on -> y] = 8;
        if((on -> x == Goal.x) && (on -> y == Goal.y)){
            std::cout << "Destination Found!" << std::endl;
            printPath();
            break;
        }
        getSides();
        for(int k=0;k<4;++k){//evaluate all nodes in that list
			gg=on->g+1;
			hh=adj[k]->getH();
			ff=gg+hh;
			if(adj[k]->solid==true){//if node is a wall do nothing
				std::cout << "Cannot move to this position!" << adj[k] -> x << ',' << adj[k] ->y << std::endl;
			}
			else if(closedList.has(adj[k])){
				if(adj[k] -> g > gg){
					adj[k] -> g = gg;
					adj[k] -> f= ff;
					adj[k] -> parent = on;
				}


			}else if(openList.has(adj[k])){
				if(adj[k] -> g > gg){
					adj[k] -> g = gg;
					adj[k] -> f = ff;
					adj[k] -> parent = on;
					openList.popNode(adj[k]);
					closedList.pushNode(adj[k]);
				}

			}else{
				std::cout << "Have not checked this location yet" << adj[k] -> x << ',' << adj[k] -> y << std::endl;
				//unchecked node set parent to current and get fcost
				adj[k] -> parent = on;
				
				//cout<<"check";
				std::cout << "g:" << gg << ' ';
				
				std::cout << "h:" << hh << ' ';
				
				std::cout << "f:" << ff << std::endl;
				adj[k] -> setG(gg);
				adj[k] -> setH(hh);
				adj[k] -> setF(ff);
				openList.pushNode(adj[k]);
			}
			
		}
		if((on->x == Goal.x) && (on -> y == Goal.y)){
			break;
		}
		openList.popNode(on);
		closedList.pushNode(on);
		on -> currpos = false;
    }
}

void nodeType::printPath(){ // TODO

}

float nodeType::getDist(){ // TODO
    return 0;
}

void setStartFinish(int startX, int startY, int endX, int endY, int arr[ROWS][COLS]){
    Start = GRID[startX][startY];
    Goal = GRID[endX][endY];
    arr[startX][startY] = 8;
    arr[endX][endY] = 9;
}

void printBoard(int arr[ROWS][COLS]){
    int space;
    std::cout << "-----------------------------------------------------------" << std::endl;
    for(int i = 0; i < ROWS; ++i){
        std::cout << "|";
        for(int j = 0; j < COLS; ++j){
            space = arr[i][j];
            switch(space){
                case 0:
                    std::cout << 0 << WHITE;
                    break;

                case 1:
                    std::cout << 1 << RED;
                    break;

                case 8:
                    std::cout << 8 << PURPLE;
                    break;

                case 9:
                    std::cout << 9 << PURPLE;
                    break;
                
                default:
                    break;
            }  
            std::cout << '.' << space << '.' << RESET;
        }
        std::cout << "|";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main(){
    int arr[ROWS][COLS];
    genGrid(arr);
    printBoard(arr);
    int xStart, yStart, xEnd, yEnd;
    std::cout << "Please choose a starting point (x,y): ";
    std::cin >> xStart >> yStart;
    std::cout << "Please choose a destination point (x,y): ";
    std::cin >> xEnd >> yEnd;
    setStartFinish(xStart, yStart, xEnd, yEnd, arr);
    nodeType N(Start, Goal);
    std::cout << "Creating Node..........Complete\n";
    std::cout << "Starting search for shortest path to destination!" << std::endl;
    printBoard(arr);
    N.findGoal(arr);
    printBoard(arr);
    return 0;
}
