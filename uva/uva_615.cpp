// uva-615
#include <bits/stdc++.h>
using namespace std;

int used[100001];
int sets[100001];
 
int set_root(int a)
{
	if (a != sets[a])
		sets[a] = set_root(sets[a]);
	return sets[a];
}
 
int main()
{
	int a,b,t = 1;
	while (~scanf("%d%d",&a,&b) && a >= 0 && b >= 0) {
		for (int i = 0 ; i < 100000 ; ++ i) {
			sets[i] = i;
			used[i] = 0;
		}
		int flag = 1;
		while (a||b) {
			if (set_root(a) == set_root(b))
				flag = 0;
			if (flag) {
				used[a] = used[b] = 1;
				sets[set_root(b)] = set_root(a);
			}
			scanf("%d%d",&a,&b);
		}
		
		if (flag == 1) {
			int count = 0;
			for (int i = 0 ; i < 100000 ; ++ i)
				if (used[i] && set_root(i) == i)
					if (count ++) {
						flag = 0;
						break;
					}
		}
		
		if (flag == 0)
			printf("Case %d is not a tree.\n",t ++);
		else printf("Case %d is a tree.\n",t ++);
	}	
	return 0;
}