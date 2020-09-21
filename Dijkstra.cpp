#include <bits/stdc++.h>
using namespace std;

/*
输入节点数量N，路径数量M
输入M行，包含起点，终点，权重（距离）,起点从1开始计数
输入起点位置坐标ST

输出起点到各个节点的距离，路径，所经过的站点
*/

#define OFFSET 1 //节点计数起点与数组下标计数点的补偿
#define INFINITY 100000000

typedef struct {
	bool visited = false;
	int distance = 0;
	int stations = 1;
	vector<int> path;
}NODE;

//返回还未被访问的节点数量
int Count(vector<NODE> VN) {
	return count_if(VN.begin(), VN.end(), [](NODE A) {return A.visited == false; });
}

int main() {
	int N, M, ST;
	cout << "Input Node Number and paths Number" << endl;
	while (cin >> N >> M) {
		vector<vector<int>> graph(N, vector<int>(N, 0));
		cout << "Input " << M << " paths:" << endl;
		for (; M--;) {
			int temp_start, temp_end, temp_dist;
			cin >> temp_start >> temp_end >> temp_dist;
			graph[temp_start - OFFSET][temp_end - OFFSET] = temp_dist;
		}
		vector<NODE> VN(N);
		cout << "Input a start position:" << endl;
		cin >> ST;
		VN[ST - OFFSET].visited = true;
		for (int i = 0; i < N; i++) {//节点第一次更新
			if (VN[i].visited == false && graph[ST - OFFSET][i]) {
				VN[i].path.push_back(ST);
				VN[i].path.push_back(i + 1);
				VN[i].stations++;
				VN[i].distance = graph[ST - OFFSET][i];
			}
		}
		//当未访问的节点数量超过2个时，遍历节点，找出起点与剩余点中距离最短的当前点；
		while (count_if(VN.begin(), VN.end(), [](NODE A) {return A.visited == false; }) > 1) {
			int temp_node = -1;//要处理的节点
			int CSD = INFINITY;//current shortest distance
			for (int i = 0; i < N; i++) {
				if (VN[i].visited == false && graph[ST - OFFSET][i]) {
					//寻找最小节点
					if (CSD > graph[ST - OFFSET][i]) {
						CSD = graph[ST - OFFSET][i];
						temp_node = i;
					}
				}
			}
			//此时已经获得了这一轮中的目标点未temp_node，通过该点更新列表
			if (temp_node == -1)
				break;
			VN[temp_node].visited = true;
			for (int i = 0; i < N; i++) {
				if (VN[i].visited == false && graph[temp_node][i]) {
					if (graph[temp_node][i] + VN[temp_node].distance < VN[i].distance || VN[i].distance == 0) {
						//起点到中间点距离+中间点到目标点距离 < 起点到目标点距离或者起点与目标点之间暂无通路 -> 更新列表
						VN[i].path = VN[temp_node].path;
						VN[i].path.push_back(i + 1);
						VN[i].stations = VN[temp_node].stations + 1;
						VN[i].distance = VN[temp_node].distance + graph[temp_node][i];
						graph[ST - OFFSET][i] = VN[i].distance;
					}
				}
			}
		}
		cout << "起始点为：" << ST << endl;
		for (int i = 0; i < N; i++) {
			if (i != ST - OFFSET) {
				if (VN[i].stations == 1) {
					cout << "目标点：" << i + 1 << endl;
					cout << "无法抵达" << endl;
					cout << endl;
					continue;
				}
				cout << "目标点：" << i + 1 << endl;
				cout << "最短距离为：" << VN[i].distance << endl;
				cout << "最短距离经过的站点数量为：" << VN[i].stations << endl;
				cout << "最短距离的路径为：" ;
				for (int j = 0; j < VN[i].path.size(); j++)
					cout << " -> " << VN[i].path[j];
				cout << endl;
			}
			cout << endl;
		}
	}
	return 0;
}

/*
例程
7 10
1 2 8
1 3 5
1 4 3
2 5 3
3 2 2
3 6 5
3 7 2
6 4 9
7 5 6
7 6 2
1
*/

