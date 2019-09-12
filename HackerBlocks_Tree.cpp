#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

class node{
public:
  int data;
  node *right;
  node *left;

  node(int val){
    data=val;
    right=left=NULL;
  }
};

node* insert(node *root,int val){
  if (root==NULL){
    return new node(val);
  }
  if (val<=root->data){
    root->left=insert(root->left,val);
  }
  else{
    root->right=insert(root->right,val);
  }
  return root;
}

node* build(){
  node *root=NULL;
  while(true){
    int x;cin>>x;
    if (x==-1){
      break;
    }
    root=insert(root,x);
}  
  return root;
}

void preorder(node *root){
  if (root==NULL){
    return ;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  return ;
}
void inorder(node *root){
  if (root==NULL){
    return ;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
  return ;
}
int height(node *root){
  if (root==NULL){
    return 0;
  }
  int lh=height(root->left);
  int rh=height(root->right);
  return max(lh,rh)+1;
}

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

bool search(node *root,int val){

  if (root==NULL){
    return false;
  }
  if (root->data==val){
    return true;
  }
 
  if (root->data>=val){
    return search(root->left,val);  
  }
  else {
    return search(root->right,val);
  }
}

node* _delete(node *root,int val){

  if (root==NULL){
    return NULL;
  }

  if (root->data>val){
    root->left=_delete(root->left,val);
    return root;
  }
  if (root->data<val){
    root->right=_delete(root->right,val);
    return root;
  }
  else{
    if (root->left==NULL and root->right==NULL){
      delete root;
      return NULL;
    }
    
    if (root->left==NULL and root->right!=NULL){
      node *temp=root->right;
      delete root;
      return temp;
    }

    if (root->left!=NULL and root->right==NULL){
      node *temp=root->left;
      delete root;
      return temp;
    }
    node *replace=root->right;

    while(replace->left!=NULL){
      replace=replace->left;
    }
    root->data=replace->data;
    root->right=_delete(root->right,replace->data);

    return root;
  }
}


bool is_BST(node *root,int lf_min=INT_MIN,int rt_max=INT_MAX){
  if (root==NULL){
    return true;
  }
  if (root->data>=lf_min and root->data<=rt_max and is_BST(root->left,lf_min,root->data) and is_BST(root->right,root->data,rt_max)){
    return true;
  }
  else{
    return false;
  }
}

//bfs
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


//build tree from given preorder and inorder traversals
node *make(int in[],int p[],int s,int e){
  static int x=0;
  if (s>e){
    return NULL;
  }
  
  node *root=new node(p[x]);
  
  int index=-1;
  for (int i=s;s<=e;i++){
    if (in[i]==p[i]){
      index=i;
      break;
    }

  }
  x++;
  root->left=make(in,p,s,index-1);
  root->right=make(in,p,index+1,e);
  return root;    
}

node *_build(){
  node *root=NULL;
  int n;
  cin>>n;
  root=new node(n);
  string s;
  cin>>s;
  if (s=="true"){
    root->left=_build();
  }
  string p;
  cin>>p;
  if (p=="true"){
    root->right=_build();
  }
  return root;
}

bool is_identical(node *root1,node *root2){
  if (root1==NULL and root2==NULL){
    return true;
  }
  if ((root1==NULL and root2!=NULL) or (root1!=NULL and root2==NULL)){
    return false;
  }
  if (is_identical(root1->left,root2->left) and is_identical(root1->right,root2->right)){
    return true;
  }
  return false;
}

node *barr(int a[],int n,int st,int end){
  if (st>end){
    return NULL;
  }
  int mid=(st+end)/2;
  node *root=new node(a[mid]);

  root->left=barr(a,n,st,mid-1);
  root->right=barr(a,n,mid+1,end);

  return root;
}

int32_t main(){
  
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  //code starts
  
  //root=build();
  //preorder(root);
  //cout<<endl;
  //root=delete_in(root,5);
  //preorder(root);
  //inorder(root);

  //cout<<endl<<height(root)<<endl;
  //kth_level(root,3);
  //cout<<(search(root,8)?"YES":"NO");
  //cout<<(is_bst(root).S);
  //cout<<(is_BST(root)?"YES":"NO");
  // int in[]={3,2,8,4,1,6,7,5};
  // int pre[]={1,2,3,4,8,5,6,7};
  // int n=sizeof(in)/sizeof(int);
  int t;cin>>t;while(t--){
    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
      cin>>a[i];
    }
    node *root=NULL;
  
  root=barr(a,n,0,n-1);
  preorder(root);

  }

  
  // node *root1=NULL;
  // root=_build();
  // root1=_build();  
  // cout<<(is_identical(root,root1)?"true":"false");





  
  return 0;
}