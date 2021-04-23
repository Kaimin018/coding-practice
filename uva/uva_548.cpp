// uva-548
// #include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<climits>
using namespace std;

map <int, int> inorderMapIndex;
int postordernodes[10001];
int inordernodes[10001];
int ans;
int ans_sums;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(){};
	
	TreeNode(int initVal){
		val = initVal;
		left = NULL;
		right = NULL;
	}
};

TreeNode *ParseNodes(int L1, int R1, int L2, int R2){
	if (L1 > R1) return NULL;
	
	int inorderIndex = inorderMapIndex[postordernodes[R2]];
	int leftCounts = inorderIndex - L1;
	TreeNode *curParent = new TreeNode(postordernodes[R2]);
	curParent->left = ParseNodes(L1, inorderIndex-1, L2, L2+leftCounts-1);
	curParent->right = ParseNodes(inorderIndex+1, R1, L2+leftCounts, R2-1);
	
	return curParent;
}

void findLestVal(TreeNode* node, int sum){
	
	if (node == NULL) return;
	
	sum += node->val;
	
	findLestVal(node->left, sum);
	findLestVal(node->right, sum);
	
	if (node->left == NULL && node->right == NULL){
		if (sum < ans_sums || (sum == ans_sums && node->val < ans)){
			ans = node->val;
			ans_sums = sum;
		}
	}
}

int main()
{
	string s;
	while(getline(cin, s)){
		inorderMapIndex.clear();
		int curVal;
		int total_length = 0;
		
		stringstream ss1(s);
		while(ss1 >> curVal){
			inorderMapIndex[curVal] = total_length;
			inordernodes[total_length] = curVal;
			total_length++;
		}
		
		total_length = 0;
		getline(cin, s);
		stringstream ss2(s);
		
		while(ss2 >> curVal){
			postordernodes[total_length] = curVal;
			total_length++;
		}
		
		TreeNode *root = ParseNodes(0, total_length-1, 0, total_length-1);
		ans_sums = INT_MAX;
		findLestVal(root, 0);
		
		cout << ans << endl;
	}
	return 0;
}
