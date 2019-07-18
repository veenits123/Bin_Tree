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

//1 2 -1 -1 4 5 -1 3 -1 -1 -1 
//1 3 9 -1 -1 11 19 -1 -1 -1 7 15 -1 -1 -1
node *make_tree(){
	int n;
	cin>>n;
	if (n==-1){
		return NULL;
	}
	node *temp=new node(n);
	temp->left=make_tree();
	temp->right=make_tree();
	return temp;
}


//build level order
node *build_level_order(){
	int first;
	cin>>first;
	if (first==-1){
		return NULL;
	}
	node *root=new node(first);
	queue <node*> q;
	q.push(root);
	while (!q.empty()){
		node *cur=q.front();
		q.pop();
		int lf_child,rt_child;
		cin>>lf_child>>rt_child;
		if (lf_child!=-1){
			cur->left=new node(lf_child);
			q.push(cur->left);		
		}
		if (rt_child!=-1){
			cur->right=new node(rt_child);
			q.push(cur->right);
		}
	}
	return root;
	
}

//depth first search
void dfs(node *root){
	if (root==NULL){
		return ;
	}
	cout<<root->data<<endl;
	//cout<<&root<<"curr"<<endl;
	dfs(root->left);
	//cout<<root->left<<"left"<<endl;
	dfs(root->right);
	//cout<<root->right<<"right"<<endl;
	return ;
}

//breadth first search
void bfs(node *root){
	queue <node*> Q;
	Q.push(root);
	while (!Q.empty()){
		node *cur=Q.front();
		Q.pop();
		cout<<cur->data<<endl;
		//cout<<cur->left<<"left"<<endl;
		//cout<<cur->right<<"right"<<endl;
		
		if (cur->left!=NULL){
			Q.push(cur->left);
		}
		if (cur->right!=NULL){
			Q.push(cur->right);
		}
	}
	return ;
}

//Root, left, right
void preorder(node *cur){
	if (cur==NULL){
		return ;
	}
	cout<<cur->data<<endl;
	preorder(cur->left);
	preorder(cur->right);
	return ;
}

//left, Root, right
void inorder(node *cur){
	if (cur==NULL){
		return ;
	}	
	inorder(cur->left);
	cout<<cur->data<<endl;
	inorder(cur->right);
	//cout<<cur->left<<"left"<<endl;
	//cout<<cur->right<<"right"<<endl;
	return ;
}

//left, right, Root
void postorder(node *cur){
	if (cur==NULL){
		return ;
	}
	postorder(cur->left);
	postorder(cur->right);
	cout<<cur->data<<endl;
	return ;	
}

//count size of tree
int count_size(node *cur){
	if (cur==NULL){
		return 0;
	}
	int size_left=count_size(cur->left);
	int size_right=count_size(cur->right);
	//cout<<cur->data<<"   "<<size_left+size_right+1<<endl;
	return size_left+size_right+1;
	
}

//height of tree
int height(node *cur){
	if (cur==NULL){
		return -1;
	}
	int left_h=height(cur->left);
	int right_h=height(cur->right);
	//cout<<cur->data<<"  "<<max(left_h,right_h)+1<<endl;
	return max(left_h,right_h)+1;
}

//sum of tree
int sum_tree(node *cur){
	if (cur==NULL){
		return 0;
	}
	int sum_left=sum_tree(cur->left);
	int sum_right=sum_tree(cur->right);
	//cout<<cur->data<<"    "<<sum_left+sum_right+cur->data<<endl;
	return sum_left+sum_right+cur->data;
}


//finding sum at level k
int find_sum_k(node *root, int depth){
	int sum=0;
	queue <pair<node*,int> > q;
	q.push({root,0});
	while(!q.empty()){
		node *cur=q.front().first;
		int cur_depth=q.front().second;
		q.pop();
		if (cur_depth==depth){
			sum+=cur->data;
		}
		if (cur->left){
			q.push({cur->left,cur_depth+1});
		}
		if (cur->right){
			q.push({cur->right,cur_depth+1});
		}
	}
	return sum;
	
}

//print what is at Kth level
void print_at_k(node *cur,int depth,int k){
	if (cur==NULL){
		return ;
	}
	if (depth==k){
		cout<<cur->data<<" ";
		return ;
	}
	print_at_k(cur->left,depth+1,k);
	print_at_k(cur->right,depth+1,k);
	return ;
}


//left view of tree
void left_view(node *root){
	if (root==NULL){
		return ;
	}
	queue <node*> q;
	q.push(root);
	
	while (!q.empty()){
		int n=q.size();
		for (int i=1;i<=n;i++){
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
		}
	}
	
}
//right view of tree
void right_view(node *root){
	if (root==NULL){
		return ;
	}
	queue <node*> q;
	q.push(root);
	
	while (!q.empty()){
		int n=q.size();
		for (int i=1;i<=n;i++){
			node *cur=q.front();
			q.pop();
			
			if (i==n){
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

//mirror tree
node *mirror_view(node *root){
	if (root==NULL){
		return root;
	}
	swap(root->left,root->right);
	mirror_view(root->left);
	mirror_view(root->right);
	return root;
	
}

// check if trees are identical ??
bool is_identical(node *root1,node *root2){
	if (root1==NULL and root2==NULL){
		return true;
	}
	else if ((root1==NULL and root2!=NULL) or (root1!=NULL and root2==NULL)){
		return false;
	}
	else{
		bool left_part=is_identical(root1->left,root2->left);
		bool right_part=is_identical(root1->right,root2->right);
		bool values=(root1->data==root2->data ?true :false);
		
		return left_part and right_part and values;
	}
}

//is tree balnced ??
pair<int,bool> is_balanced(node *root){
	if (root==NULL){
		return {0,true};
	}
	pair<int,bool> left_part=is_balanced(root->left);
	pair<int,bool> right_part=is_balanced(root->right);
	
	int cur_height=max(left_part.first, right_part.first) + 1;
	
	if (abs(left_part.first-right_part.first)<=1 and left_part.second and right_part.second){
		return {cur_height,true};
	}
	else{
		return {cur_height,false};
	}
	
}
//comparator
bool comp(int a, int b){
	return (a < b);	
}
     
//Diameter-The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
pair<int,int> diameter(node *root){
	if (root==NULL){
		return {0,0};
	}
	pair<int,int> lf_d=diameter(root->left);
	pair<int,int> rt_d=diameter(root->right);
	
	int height_lf=lf_d.second;
	int height_rt=rt_d.second;
	
	int cur_height=max(height_lf,height_rt)+1;
	
	int cur_diameter=std::max({lf_d.first,rt_d.first,height_lf+height_rt},comp);
	
	return {cur_diameter,cur_height};
	
	
	
}





//build level order recursively




int main(){
	node *root,*root1,*root2;
	//root=make_tree();
	//root1=build_level_order();
	//root2=build_level_order();
	root=build_level_order();
	//root=build_level();
	//bfs(root);
	//dfs(root);
	//preorder(root);
	//inorder(root);
	//postorder(root);
	//cout<<count_size(root);
	//cout<<height(root1);
	//cout<<sum_tree(root);
//1 3 9 -1 -1 11 19 -1 -1 -1 7 15 -1 -1 -1
	//cout<<find_sum_k(root,1);
	//right_view(root);
	//left_view(root);
	//cout<<check(root1,root2);
	//cout<<is_balnced(root);
	//cout<<check(root1,root2);
	//print_at_k(root1,0,2);
	//root=mirror_view(root);
	//dfs(root);
	//right_view(root);
	//cout<<height(root);
	//cout<<is_identical(root1,root2);
	//pair<int,bool> ans=is_balanced(root);
	//cout<<ans.second;
	pair<int,int> ans=diameter(root);
	cout<<ans.first<<" "<<ans.second;
	
	
	
	
}
