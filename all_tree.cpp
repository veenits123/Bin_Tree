#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

class node{
public:
	int data;
	node *left;
	node *right;
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

node *build(){
	int x;cin>>x;
	if (x==-1){
		return NULL;
	}
	node *root=new node(x);
	root->left=build();
	root->right=build();
	
	return root;
}
//root left right
void preorder(node *root){
	if (root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	return ;
}
//left root right
void inorder(node *root){
	if (root==NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return ;
}
//left right root
void postorder(node *root){
	if (root==NULL){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	return ;
}

//height of the tree
int height(node *root){
	if (root==NULL){
		return 0;
	}
	int lh=height(root->left);
	int rh=height(root->right);
	return max(lh,rh)+1;
}
//print kth level
void kth_level(node *root,int k){
	if (root==NULL){
		return ;
	}
	if (k==1){
		cout<<root->data<<" ";
		return ;
	}
	kth_level(root->left,k-1);
	kth_level(root->right,k-1);
	return ;
}
//print level order recursion
void print_level(node *root){
	if (root==NULL){
		return ;
	}
	for (int i=1;i<=height(root);i++){
		kth_level(root,i);
		cout<<endl;
	}
	return ;
}
//print level order iteration(bfs)
void bfs(node *root){
	if (root==NULL){
		return ;
	}
	queue <node*> q;
	q.push(root);
	while (!q.empty()){
		int sz=q.size();
		while (sz>0){
			node *cur = q.front();
			q.pop();
			cout<<cur->data<<" ";

			if (cur->left!=NULL){
				q.push(cur->left);
			}
			if (cur->right!=NULL){
				q.push(cur->right);
			}
			sz--;
		}
		cout<<endl;

	}
	return ;
}
//count number of nodes 
int count(node *root){
	if (root==NULL){
		return 0;
	}
	int lc=count(root->left);
	int rc=count(root->right);

	return lc+rc+1;
}
//sum of element of tree
int total_sum(node *root){
	if (root==NULL){
		return 0;
	}
	int lsum=total_sum(root->left);
	int rsum=total_sum(root->right);

	return lsum+rsum+root->data;
}
//diameter of the tree O(n^2)
int diameter(node *root){
	if (root==NULL){
		return 0;
	}
	int lfd=height(root->left);
	int rtd=height(root->right);

	int only_left=diameter(root->left);
	int only_right=diameter(root->right);
	int passing_th_root=lfd+rtd;

	return max({only_left,only_right,passing_th_root});
}
//diameter in O(n) time
// first elem. is diameter second elem. is height
pair <int,int> diameter_(node *root){
	if (root==NULL){
		return {0,0};
	}
	pair <int,int> lpart=diameter_(root->left);
	pair <int,int> rpart=diameter_(root->right);

	int lh=lpart.S;
	int rh=rpart.S;
	int cur_height=max(lh,rh)+1;

	int dia=max({lpart.F,rpart.F,lh+rh});

	return {dia,cur_height};
}
//replace root by sum of its child
int replace(node *root){
	if (root==NULL){
		return 0;
	}
	// if (root->left==NULL and root->right==NULL){
	// 	return root->data;
	// }
	int temp=root->data;
	
	int lsum=replace(root->left);
	int rsum=replace(root->right);

	root->data=lsum+rsum;
	
	return root->data+temp;
}
//Is height balanced ??
pair <int,bool> balanced(node *root){
	if (root==NULL){
		return {0,true};
	}

	pair <int,bool> lpart=balanced(root->left);
	pair <int,bool> rpart=balanced(root->right);

	int lh=lpart.F;
	int rh=rpart.F;

	if (abs(lh-rh)<=1 and lpart.S and rpart.S){
		return {max(lh,rh)+1,true};
	}
	else {
		return {max(lh,rh)+1,false};
	}
}
//build Tree from array
node *build_array(int a[],int st,int end){
	if (st>end){
		return NULL;
	}
	int mid=(st+end)/2;
	node *root=new node(a[mid]);
	
	root->left=build_array(a,st,mid-1);
	root->right=build_array(a,mid+1,end);
	
	return root;
}
//getting index of preoder element in inorder element
int get_index(int in[],int n,int val){
	for (int i=0;i<n;i++){
		if (in[i]==val){
			return i;
		}
	}
}
int x=0;
//build tree from inorder and preorder
node *build_pre_in(int pre[],int in[],int n,int st,int end){
	if (st>end){
		return NULL;
	}

	//we can also declare it globally
	//static int x=0;//because we are going at a node only one time
	node *root=new node(pre[x]);
	x++;

	if (st==end){
		return root;
	}
	

	int i=get_index(in,n,root->data);

	root->left=build_pre_in(pre,in,n,st,i-1);
	root->right=build_pre_in(pre,in,n,i+1,end);

	//return root;
}
//build tree from preorder and postorder
// node *build_pre_post(int pre[],int post[],int n,int st,int end){
// 	if (st>end){
// 		return NULL;
// 	}
// 	node *root=new node(pre[x]);
// 	x++;
	
// 	int i=get_index(post,n,root->data);

// 	root->left=build_pre_post(pre,post,n,st+1,i);
// 	root->right=build_pre_post(pre,post,n,i+1,end-1);

// 	return root;
// }

int32_t main(){
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//code starts
	//1 3 9  -1 -1 11 19 -1 -1 -1 7 15 -1 -1 -1

	//node *root=build();
	//preorder(root);
	//inorder(root);
	//postorder(root);
	//cout<<height(root);
	//kth_level(root,2);
	//print_level(root);
	//bfs(root);
	//cout<<count(root);
	//cout<<total_sum(root);
	//cout<<diameter(root);
	//cout<<diameter_(root).F<<" "<<diameter_(root).S;
	//replace(root);
	//preorder(root);
	//cout<<balanced(root).F<<" "<<balanced(root).S;
	//int a[]={1,2,3,4,5,6};
	//node *root=build_array(a,0,5);
	//int pre[]={1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[]= {8, 9, 4, 5, 2, 6, 7, 3, 1};
	int pre[]={5,3,7,1,6,4,8};
   	int in[]={1,3,4,5,6,7,8};
	node *root=build_pre_in(pre,in,7,0,6);
	preorder(root);



	return 0;
}
