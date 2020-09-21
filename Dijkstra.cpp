#include <bits/stdc++.h>
using namespace std;

/*
����ڵ�����N��·������M
����M�У�������㣬�յ㣬Ȩ�أ����룩,����1��ʼ����
�������λ������ST

�����㵽�����ڵ�ľ��룬·������������վ��
*/

#define OFFSET 1 //�ڵ��������������±������Ĳ���
#define INFINITY 100000000

typedef struct {
	bool visited = false;
	int distance = 0;
	int stations = 1;
	vector<int> path;
}NODE;

//���ػ�δ�����ʵĽڵ�����
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
		for (int i = 0; i < N; i++) {//�ڵ��һ�θ���
			if (VN[i].visited == false && graph[ST - OFFSET][i]) {
				VN[i].path.push_back(ST);
				VN[i].path.push_back(i + 1);
				VN[i].stations++;
				VN[i].distance = graph[ST - OFFSET][i];
			}
		}
		//��δ���ʵĽڵ���������2��ʱ�������ڵ㣬�ҳ������ʣ����о�����̵ĵ�ǰ�㣻
		while (count_if(VN.begin(), VN.end(), [](NODE A) {return A.visited == false; }) > 1) {
			int temp_node = -1;//Ҫ����Ľڵ�
			int CSD = INFINITY;//current shortest distance
			for (int i = 0; i < N; i++) {
				if (VN[i].visited == false && graph[ST - OFFSET][i]) {
					//Ѱ����С�ڵ�
					if (CSD > graph[ST - OFFSET][i]) {
						CSD = graph[ST - OFFSET][i];
						temp_node = i;
					}
				}
			}
			//��ʱ�Ѿ��������һ���е�Ŀ���δtemp_node��ͨ���õ�����б�
			if (temp_node == -1)
				break;
			VN[temp_node].visited = true;
			for (int i = 0; i < N; i++) {
				if (VN[i].visited == false && graph[temp_node][i]) {
					if (graph[temp_node][i] + VN[temp_node].distance < VN[i].distance || VN[i].distance == 0) {
						//��㵽�м�����+�м�㵽Ŀ������ < ��㵽Ŀ��������������Ŀ���֮������ͨ· -> �����б�
						VN[i].path = VN[temp_node].path;
						VN[i].path.push_back(i + 1);
						VN[i].stations = VN[temp_node].stations + 1;
						VN[i].distance = VN[temp_node].distance + graph[temp_node][i];
						graph[ST - OFFSET][i] = VN[i].distance;
					}
				}
			}
		}
		cout << "��ʼ��Ϊ��" << ST << endl;
		for (int i = 0; i < N; i++) {
			if (i != ST - OFFSET) {
				if (VN[i].stations == 1) {
					cout << "Ŀ��㣺" << i + 1 << endl;
					cout << "�޷��ִ�" << endl;
					cout << endl;
					continue;
				}
				cout << "Ŀ��㣺" << i + 1 << endl;
				cout << "��̾���Ϊ��" << VN[i].distance << endl;
				cout << "��̾��뾭����վ������Ϊ��" << VN[i].stations << endl;
				cout << "��̾����·��Ϊ��" ;
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
����
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

