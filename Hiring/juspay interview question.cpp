
#include<bits/stdc++.h>

using namespace std;

void setBit(char* p,int n, int i){
	
	int k = i/8;
	int m = i % 8;
	if(m == 0) k--;
	m = 8;
	char* temp = p;
	temp = temp + k;
	*temp = *temp | (1 << (8-m));
}


bool validate(Node* root,int ms){
	if(root == NULL) {
		return true;
	} 
	bool f = false;
	if(root->left){
		if(root->left->val > ms) return false;
		f = validate(root->left,root->left->val);
	}
	if(root->right){
		if(root->right->val < ms) return false;
		f = validate(root->right,root->right->val);
	}
	if(!f) return false;
	return true;
}


int main(){
	string a = "hdllo";
	char* f = &a[0];
	setBit(f,5,16);
	cout << a <<" ";
}