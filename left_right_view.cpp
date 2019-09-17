//right view
void right(node *root){
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
//left view
void left(node *root){
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