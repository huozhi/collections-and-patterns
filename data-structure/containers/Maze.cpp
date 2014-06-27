/*
+-----------------------------------------------------------------------+
| C++ Code Maze                                                         |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
using namespace std;

class step;
class offset;
class unit;
class maze;

enum Direction { N, NE, E, SE, S, SW, W, NW } dir;

class offset {
public:
	offset(): x(0), y(0) {}
	offset(int _x, int _y): x(_x), y(_y) {}
public:
	int x;
	int y;
};

offset move[8] = {
	offset(-1, 0), offset(-1, 1), offset(0, 1),
	offset(1, 1), offset(1, 0), offset(1, -1),
	offset(0, -1), offset(-1, -1)
};


class step {
public:
	int x, y, dir;

public:
	step(): x(0), y(0), dir(0) {}
	step(int _x, int _y, int _dir):
		x(_x), y(_y), dir(_dir) {}
	friend ostream &operator <<(ostream &os, const step &s) {
		string dir_name[8] = {
			"N", "NE", "E", "SE", "S", "SW", "W", "NW"
		};
		os << s.x << " " << s.y << " " << dir_name[s.dir] << endl;
		return os;
	}
};



class unit {
public:
	bool is_mark;
	bool is_maze;
public:
	unit(): is_maze(true), is_mark(false) {}
	unit(const bool maze_bool_val, const bool mark_bool_val):
		is_maze(maze_bool_val), is_mark(mark_bool_val) {}
};

class maze {
private:
	int width;
	int height;
	int EXIT_X;
	int EXIT_Y;
	stack<step> path;
	unit **m_maze;

public:
	void maze_set(int _width, int _height) {
		width = _width;
		height = _height;
		EXIT_X = 0;
		EXIT_Y = 0;
		m_maze = new unit*[height];
		for (int i = 0; i < height; i++) {
			m_maze[i] = new unit[width];
			for (int j = 0; j < width; j++)
				m_maze[i][j].is_mark = false;
		}
		m_maze[0][0].is_maze = true;
		path = stack<step>();
	}

	maze(int _width, int _height, int EX, int EY) {
		 	maze_set(_width, _height);
			EXIT_X = EX;
			EXIT_Y = EY;
	}

public:
	void setMaze() {
		cout << "setting maze..." << endl;
		int x, y;
		while (cin >> x >> y) {
			m_maze[x][y].is_maze = true;
		}
		cout << "end setting..." << endl;
	}

	void printPath() {
		stack<step> temp(path);
		while (!temp.empty()) {
			cout << temp.top() << " ";
			temp.pop();
		}
		cout << endl;
		cout << "EXIT: " << EXIT_X << " " << EXIT_Y << endl;
	}

	void findPath() {
		cout << "finding path..." << endl;
		// find step
		step current(0, 0, E);
		path.push(current);
		while (!path.empty()) {
			int i, j, dir;
			i = current.x, j = current.y, dir = current.dir;
			while (dir < 8) {
				int next_x = i + move[dir].x;
				int next_y = j + move[dir].y;
				if ((next_x == EXIT_X) && (next_y == EXIT_Y)) {
					printPath();
					return;
				}
				if (!m_maze[next_x][next_y].is_mark && m_maze[next_x][next_y].is_maze) {
					m_maze[next_x][next_y].is_mark = true;
					current.x = i;
					current.y = j;
					// if get back, pop stack and get the next direction try
					current.dir = dir + 1;
					path.push(current);
					i = next_x;
					i = next_y;
					dir = N; // the 0 direction
							 // zero_dir + __x = dir
				}
				else
					++dir;
			}
		}
		cout << "No path" << endl;
	}
};




int main() {
	maze m_Maze(9, 9, 8, 8);
	m_Maze.setMaze();
	m_Maze.findPath();
	m_Maze.printPath();
	return 0;
}