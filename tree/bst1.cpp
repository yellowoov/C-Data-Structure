#include <cstdlib>
#include <iostream>
using namespace std;

//이진검색트리노드
typedef struct treenode {
	int data;
	struct treenode* left;
	struct treenode* right;
}treenode;

treenode* insertnode(treenode* root, int data); //이진 검색 트리 노드추가
treenode* search(treenode* root, int data); //이진 검색 트리 노드 검색
void deletenode(treenode* root, int data); //이진검색트리 삭제
void drawBSTree(treenode* root, int level); //이진검색트리 그리기

//이진검색트리 검색
treenode* search(treenode* root, int data)
{
	while (root->data != data)
	{
		if (data < root->data) //root노드보다 작은 수인경우
			root = root->left; //왼쪽 자식으로 이동
		else if (data > root->data) //root노드보다 큰 수인경우
			root = root->right; //오른쪽 자식으로 이동
		if (root == NULL)
			return NULL;
	}
	return root;
}

//이진검색트리 삭제
void deletenode(treenode* root, int data)
{
	treenode* p = NULL; //삭제 노드
	treenode* pp = NULL; //삭제 노드의 부모 노드
	treenode* sp; //왼쪽 서브트리 중 가장 큰 노드
	treenode* psp; //sp 부모 노드
  treenode* c; // 자식 노드

  int prev = 0; // 1 - 왼쪽자식 2 - 오른쪽자식

  p = root;

  while (1)
  {
    if (data == p->data)
    {
      break;
    }
    else if (data < p -> data)
    {
      if (p->left != NULL)
      {
        pp = p;
        p = p->left;
        prev = 1;
      }
    }
    else
    {
      if (p->right != NULL)
      {
        pp = p;
        p = p->right;
        prev = 2;
      }
    }
  }

  if (p->left == NULL && p->right == NULL) //삭제노드가 단노드
  {
    if (pp != NULL)
    {
      if (pp->left == p)
      {
        pp->left = NULL;
      }
      else
      {
        pp->right = NULL;
      }
    }
    else
    {
      root = NULL;
    }
  }

  else if (p->left != NULL && p->right != NULL) //삭제노드의 자식노드가 2개
  {
    psp = p;
    sp = p->left;

    while (sp->right != NULL)
    {
      psp = sp;
      sp = sp->right;
    }

    if (psp->right == sp)
    {
      psp->right = NULL;
      sp->left = p->left;
      sp->right = p->right;
    }

    else //삭제노드의 자식노드가 1개
    {
      sp->right = p->right;
    }

    if (pp != NULL)
    {
      if (prev == 1)
      {
        pp->left = sp;
      }
      else
      {
        pp->right = sp;
      }
    }
    if (p == root)
    {
      root = sp;
    }
  }

  else
  {
    c = (p->left != NULL) ? p->left : p->right;

    if (pp != NULL)
    {
      if (pp->left == p)
      {
        pp->left = c;
      }
      else
      {
        pp->right = c;
      }
    }
    else
    {
      root = c;
    }
  }
  free(p);
}

//이진트리 노드추가
treenode* insertnode(treenode* root, int data)
{
	treenode* n;
	if (root == NULL) { //트리 처음 생성하는 경우
		n = (treenode*)malloc(sizeof(treenode));
		n->data = data;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	else if (data < root->data) //root노드보다 작은 수인경우
		root->left = insertnode(root->left, data); //왼쪽 자식으로 이동
	else if (data > root->data) //root노드보다 큰 수인경우
		root->right = insertnode(root->right, data); //오른쪽 자식으로 이동
	else //data와 같은 노드인 경우
    cout << "이미 존재하는 노드입니다." << endl;

	return root;
}

void drawBSTree(treenode* root, int level)
{
  if (root != 0 && level <= 7)
  {
    drawBSTree(root->right, level + 1);
    for (int i = 1; i <= (level - 1); i++)
    {
      cout << " ";
    }
    cout << root->data;
    if (root->left != 0 && root->right != 0)
    {
      cout << "<" << endl;
    }
    else if (root->right != 0)
    {
      cout << "/" << endl;
    }
    else if (root->left != 0)
    {
      cout << "\\" << endl;
    }
    else
    {
      cout << endl;
    }
    drawBSTree(root->left, level + 1);
  }
}

int main()
{
	int data = 0;
	treenode* root = NULL;
	treenode* find = NULL;

	cout << "==이진 탐색 트리==" << endl;
	cout << "루트 데이터 입력 : ";
	cin >> data;
	root = insertnode(root, data);

	while (1)
	{
		cout << "추가 노드 데이터 입력(종료 시 -1입력) : ";
		cin >> data;
		if (data == -1)
			break;
		insertnode(root, data);
	}
  drawBSTree(root, 1);

  cout << "삭제하고자 하는 노드 데이터 : ";
  cin >> data;
  deletenode(root, data);
  drawBSTree(root, 1);

  cout << "삭제하고자 하는 노드 데이터 : ";
  cin >> data;
  deletenode(root, data);
  drawBSTree(root, 1);

  cout << "삭제하고자 하는 노드 데이터 : ";
  cin >> data;
  deletenode(root, data);
  drawBSTree(root, 1);

  cout << "검색하고자 하는 노드 데이터 : ";
	cin >> data;
  find = search(root, data);
  if (find == NULL)
    cout << "존재하지 않는 노드입니다." << endl;
  else
    cout << "존재하는 노드입니다." << endl;

	return 0;
}
