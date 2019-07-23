#include <bits/stdc++.h>
using namespace std;

int x=0;
class node{
	public:
		int data;
		node *right,*left;
		node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};

node *build(node *root){
	if (x==0){
		int n;
		cin>>n;
		x++;
		root=new node(n);
		root->left=build(root->left);
		root->right=build(root->right);
		return root;
	
	}	
	string s="veenit";
	cin>>s;
	if (s!="veenit"){
		if (s=="true"){
			int i;
			cin>>i;
			node *nw=new node(i);
			nw->left=build(nw->left);
			nw->right=build(nw->right);
			return nw;
		}
		else{
			return root;
		}
	}
	return root;	
}
void zigzag(node *root){
	queue <node*> q;
	stack <node*> s;
	int level=1;
	q.push(root);
	q.push(NULL);
	while (!q.empty()){
		node *cur=q.front();
		q.pop();
		if (cur==NULL){
			level++;
			while (!s.empty()){
				cout<<s.top()->data<<" ";
				s.pop();
			}
			if (!q.empty()){
				q.push(NULL);
			}
		}
		else{
			if (cur->left){
				q.push(cur->left);
			}
			if (cur->right){
				q.push(cur->right);
			}
			if (level%2==0){
				s.push(cur);
			}
			else{
				cout<<cur->data<<" ";
			}
		}
	}
}
void dfs(node *root){
	if (root == NULL){
		return ;
	}
	cout<<root->data<<" ";
	dfs(root->left);
	dfs(root->right);
	return ;
}
int main(){
	node *root;
	root=build(root);
	dfs(root);
	cout<<endl;
	zigzag(root);
	
	return 0;
}
