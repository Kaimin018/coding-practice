// uva-352
#include <bits/stdc++.h>
using namespace std;

void marked(char map[30][30], bool isVisited[30][30], int i, int j){
	if (map[i][j] != '1' || isVisited[i][j] ) return;
	
	const static int direction[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
	
	isVisited[i][j] = true;
	
	for (int d=0; d<8; d++){
		marked(map, isVisited, i + direction[d][0], j + direction[d][1]);
	}
}

int main()
{
	int a;
	int imageNumber = 0;
	while(cin >> a){
		char map[30][30] = {0};
		for (int i=1; i<=a; i++){
			scanf("%s", &map[i][1]);
		}
		
		int eagleCount = 0;
		bool isVisited[30][30] = {false};
		for (int i=1; i<=a; i++){
			for (int j=1; j<=a; j++){
				if (map[i][j] == '1' && !isVisited[i][j]){
					marked(map, isVisited, i, j);
					++eagleCount;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", ++imageNumber, eagleCount);
	}
	return 0;
}