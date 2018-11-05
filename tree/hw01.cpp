#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct node
{
  int data;
  struct node* left;
  struct node* right;
}node;

node* insertBST(node* root, int data); // 이진검색트리 노드 추가
node* deleteBST(node* root, int data); // 이진검색트리 노드 삭제
int height(node* root); // 트리의 높이 세기
node* maxNode(node* root); // 최댓값노드 찾기
node* minNode(node* root); // 최솟값노드 찾기
int noNodes(node* root); // 노드의 수 세기
void InOrder(node* root); // InOrder 수행
node* searchParentBST(node* root, int data, node* q, node* p); // 부모 노드 찾기

node* insertBST(node* root, int data)
{
  node* p = NULL;
  node* q = NULL;
  q = searchParentBST(root, data, q, p);

  node* n = NULL;

  n = (node*)malloc(sizeof(node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;

  if (root == NULL)
    root = n;
  else if (data < q->data)
    q->left = n;
  else
    q->right = n;

  return root;
}

node* deleteBST(node* root, int data)
{
  node* p = NULL; // 삭제할 노드
  node* q = NULL; // 삭제할 노드의 부모 노드

  string flag = "";

  q = searchParentBST(root, data, q, p);

  if (data < q->data)
    p = q->left;
  else if (data > q->data)
    p = q->right;
  else
    p = q;

  if (p == NULL)
    return NULL;

  if (q == NULL)
  {
    free(root);
    root = NULL;
    return NULL;
  }

  if (p->left == NULL && p->right == NULL)
    // 삭제할 노드의 차수가 0인 경우 (리프 노드)
  {
    if (p->data == q->data)
      p = NULL;
    else
    {
      if (q->left == p)
        q->left = NULL;
      else
        q->right = NULL;
      p = NULL;
    }
  }

  else if ((p->right != NULL && p->left == NULL) || (p->left != NULL && p->right == NULL))
    // 삭제할 노드의 차수가 1인 경우
  {
    if (p->left != NULL && p->right == NULL)
    {
      if (q->left == p)
        q->left = p->left;
      else
        q->right = p->left;
      p = NULL;
    }

    else
    {
      if (q->left == p)
        q->left = p->right;
      else
        q->right = p->right;
      p = NULL;
    }
  }

  else
    // 삭제할 노드의 차수가 2인 경우
  {
    node* r = NULL; // 최대, 최소 저장 노드

    if (height(p->left) > height(p->right))
      // 왼쪽 서브트리의 높이가 더 큰 경우
    {
      r = maxNode(p->left);
      flag = "LEFT";
    }
    else if (height(p->left) < height(p->right))
      // 오른쪽 서브트리의 높이가 더 큰 경우
    {
      r = minNode(p->right);
      flag = "RIGHT";
    }
    else if (height(p->left) == height(p->right))
      // 왼쪽, 오른쪽 서브트리의 높이가 같은 경우
    {
      if (noNodes(p->left) >= noNodes(p->right))
        // 왼쪽 서브트리의 노드 갯수가 더 많거나 같은 경우
      {
        r = maxNode(p->left);
        flag = "LEFT";
      }
      else if (noNodes(p->left) < noNodes(p->right))
        // 오른쪽 서브트리의 노드 갯수가 더 많은 경우
      {
        r = minNode(p->right);
        flag = "RIGHT";
      }
    }

    p->data = r->data;

    if (flag == "LEFT")
      deleteBST(p->left, r->data);
    else if (flag == "RIGHT")
      deleteBST(p->right, r->data);
  }
  return q;
}

node* searchParentBST(node* root, int data, node* q, node* p)
{
  p = root;
  q = p;

  while (p != NULL)
  {
    if (data == p->data)
    {
      return q;
    }
    else if (data < p->data)
    {
      q = p;
      p = p->left;
    }
    else
    {
      q = p;
      p = p->right;
    }
  }
  return q;
}

int height(node* root)
{
	if (root == NULL)
		return 0;
	int h_left = height(root->left);
	int h_right = height(root->right);

	return 1 + (h_left > h_right ? h_left : h_right);
}

node* maxNode(node* root)
{
  if (root == NULL)
    return NULL;
  else if (root->right == NULL)
    return root;
  else
    return maxNode(root->right);
}

node* minNode(node* root)
{
  if (root == NULL)
    return NULL;
  else if (root->left == NULL)
    return root;
  else
    return minNode(root->left);
}

int noNodes(node* root)
{
  if (root == NULL)
  {
    return 0;
  }
	return 1 + noNodes(root->left) + noNodes(root->right);
}

void InOrder(node* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
}

int main()
{
  node* root = NULL;
  int data = 0;

  root = insertBST(root, 8); InOrder(root); cout << endl;
  insertBST(root, 18); InOrder(root); cout << endl;
  insertBST(root, 11); InOrder(root); cout << endl;
  insertBST(root, 5); InOrder(root); cout << endl;
  insertBST(root, 15); InOrder(root); cout << endl;
  insertBST(root, 4); InOrder(root); cout << endl;
  insertBST(root, 9); InOrder(root); cout << endl;
  insertBST(root, 1); InOrder(root); cout << endl;
  insertBST(root, 7); InOrder(root); cout << endl;
  insertBST(root, 17); InOrder(root); cout << endl;
  insertBST(root, 6); InOrder(root); cout << endl;
  insertBST(root, 14); InOrder(root); cout << endl;
  insertBST(root, 10); InOrder(root); cout << endl;
  insertBST(root, 3); InOrder(root); cout << endl;
  insertBST(root, 19); InOrder(root); cout << endl;
  insertBST(root, 20); InOrder(root); cout << endl;
  deleteBST(root, 8); InOrder(root); cout << endl;
  deleteBST(root, 18); InOrder(root); cout << endl;
  deleteBST(root, 11); InOrder(root); cout << endl;
  deleteBST(root, 5); InOrder(root); cout << endl;
  deleteBST(root, 15); InOrder(root); cout << endl;
  deleteBST(root, 4); InOrder(root); cout << endl;
  deleteBST(root, 9); InOrder(root); cout << endl;
  deleteBST(root, 1); InOrder(root); cout << endl;
  deleteBST(root, 7); InOrder(root); cout << endl;
  deleteBST(root, 17); InOrder(root); cout << endl;
  deleteBST(root, 6); InOrder(root); cout << endl;
  deleteBST(root, 14); InOrder(root); cout << endl;
  deleteBST(root, 10); InOrder(root); cout << endl;
  deleteBST(root, 3); InOrder(root); cout << endl;
  deleteBST(root, 19); InOrder(root); cout << endl;
  deleteBST(root, 20); InOrder(root); cout << endl;

  free(root);
  root = NULL;

  root = insertBST(root, 8); InOrder(root); cout << endl;
  insertBST(root, 18); InOrder(root); cout << endl;
  insertBST(root, 11); InOrder(root); cout << endl;
  insertBST(root, 5); InOrder(root); cout << endl;
  insertBST(root, 15); InOrder(root); cout << endl;
  insertBST(root, 4); InOrder(root); cout << endl;
  insertBST(root, 9); InOrder(root); cout << endl;
  insertBST(root, 1); InOrder(root); cout << endl;
  insertBST(root, 7); InOrder(root); cout << endl;
  insertBST(root, 17); InOrder(root); cout << endl;
  insertBST(root, 6); InOrder(root); cout << endl;
  insertBST(root, 14); InOrder(root); cout << endl;
  insertBST(root, 10); InOrder(root); cout << endl;
  insertBST(root, 3); InOrder(root); cout << endl;
  insertBST(root, 19); InOrder(root); cout << endl;
  insertBST(root, 20); InOrder(root); cout << endl;
  deleteBST(root, 20); InOrder(root); cout << endl;
  deleteBST(root, 19); InOrder(root); cout << endl;
  deleteBST(root, 3); InOrder(root); cout << endl;
  deleteBST(root, 10); InOrder(root); cout << endl;
  deleteBST(root, 14); InOrder(root); cout << endl;
  deleteBST(root, 6); InOrder(root); cout << endl;
  deleteBST(root, 17); InOrder(root); cout << endl;
  deleteBST(root, 7); InOrder(root); cout << endl;
  deleteBST(root, 1); InOrder(root); cout << endl;
  deleteBST(root, 9); InOrder(root); cout << endl;
  deleteBST(root, 4); InOrder(root); cout << endl;
  deleteBST(root, 15); InOrder(root); cout << endl;
  deleteBST(root, 5); InOrder(root); cout << endl;
  deleteBST(root, 11); InOrder(root); cout << endl;
  deleteBST(root, 18); InOrder(root); cout << endl;
  deleteBST(root, 8); InOrder(root); cout << endl;

  return 0;
}
