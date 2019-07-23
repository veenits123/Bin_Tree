#include <bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node *left,*right;
		
		node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};

//build from unsorted array
node *insert(node *root,int val){
	if (root==NULL){
		return new node(val);
	}
	if (val<root->data){
		root->left=insert(root->left,val);
	}
	else{
		root->right=insert(root->right,val);
	}
	return root;
}

// 3 2 4 1 5 -1
node *build(){
	node *root=NULL;
	while(true){
		int x;
		cin>>x;
		if (x==-1){
			break;
		}
		root=insert(root,x);		
	}
	return root;
}

//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
node *build_t(){
	//node *root=NULL;
	int x;
	cin>>x;
	node *root=new node(x);
	string s;
	cin>>s;
	if (s=="true"){
		root->left=build_t();
	}
	string t;
	cin>>t;
	if (t=="true"){
		root->right=build_t();
	}
	return root;
}

//bst from sorted array
node *build_arr(int a[],int start,int end){

	if (start>end){
		return NULL;
	}
	int mid=(start+end)/2;
	
	node *root=new node(a[mid]);
	
	root->left=build_arr(a,start,mid-1);
	root->right=build_arr(a,mid+1,end);
	return root;

}

//build level order
node *build_l(){
	int x;
	cin>>x;
	if (x==-1){
		return NULL;
	}
	node *root=new node(x);
	queue <node*> q;
	q.push(root);
	while (!q.empty()){
		node *cur=q.front();
		q.pop();
		int l,r;
		cin>>l>>r;
		if (l!=-1){
			cur->left=new node(l);
			q.push(cur->left);
		}
		if (r!=-1){
			cur->right=new node(r);
			q.push(cur->right);
		}
	}
	return root;
	
}

//getting index
int get(int a[],int val){
	for (int i=0;i<sizeof(a);i++){
		if (a[i]==val){
			return i;
		}
	}
}

//build tree from given preorder and inorder traversals
node *make(int i[],int p[],int s,int e){
	static int x=0;
	if (s>e){
		return NULL;
	}
	
	node *root=new node(p[x++]);
	if (s==e){
		return root;
	}
	int index=get(i,root->data);
	root->left=make(i,p,s,index-1);
	root->right=make(i,p,index+1,e);
	return root;		
}

void print(node *root){
	if (root==NULL){
		return ;
	}
	if (root->left){
		cout<<root->left->data<<" ";
	}
	else{
		cout<<"END ";
	}
	cout<<"=>";
	cout<<" "<<root->data<<" ";
	cout<<"<=";
	if (root->right){
		cout<<" "<<root->right->data;
	}
	else{
		cout<<" END";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
	return ;
}

void dfs(node *root){
	if (root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	dfs(root->left);
	dfs(root->right);
	return ;
}

void print_at_k(node *root,int k){
	if (root==NULL){
		return ;
	}
	if (k==0){
		cout<<root->data<<" ";
	}
	print_at_k(root->left,k-1);
	print_at_k(root->right,k-1);
	return ;
}

void left_view(node *root){
	if (root==NULL){
		return ;
	}
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		
		for (int i=1;i<=n;i++){
			//cout<<"i"<<i<<endl;
			node *cur=q.front();
			q.pop();
			if (i==1){
				cout<<cur->data<<" ";
			}
			if (cur->left){
				q.push(cur->left);
			}
			if (cur->right){
				q.push(cur->right);
			}
			//cout<<cur->data<<" vee"<<endl;
		}
		
	}
	
}

//right view
void right_view(node *root){
	if (root==NULL){
		return ;
	}
	queue <node*> q;
	q.push(root);
	while (!q.empty()){
		int n=q.size();
		
		for (int i=0;i<n;i++){
			node *cur=q.front();
			q.pop();
			if (i==n-1){
				cout<<cur->data<<" ";
			}
			if (cur->left){
				q.push(cur->left);
			}
			if (cur->right){
				q.push(cur->right);
			}
		}
	}
	
}
int main(){
	int n;cin>>n;int a[n];for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int m;cin>>m;int b[n];for (int i=0;i<m;i++){
		cin>>b[i];
	}
	node *root=NULL;
	root=make(b,a,0,m-1);
	//root=build_arr(a,0,n-1);
	//root=build_l();
//	int n;
//	cin>>n;
//	int x;
//	for (int i=0;i<n;i++){
//		cin>>x;
//		root=insert(root,x);
//	}
	//root=build_arr(a,0,n-1);
	print(root);
	//dfs(root);
	//cout<<endl;
	//right_view(root);
	//print_at_k(root,2);
}
