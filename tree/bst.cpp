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
	treenode* del = NULL; //삭제 노드
	treenode* p = NULL; //삭제 노드의 부모 노드

	treenode* max_right = NULL; //왼쪽 서브트리 중 가장 큰 노드
	treenode* p_max_right = NULL; //max_left 부모 노드

	while (1)
	{
		if (root == NULL) //NULL인 경우-삭제 노드 못 찾은 경우
		{
      cout << "삭제 노드를 찾지 못 했습니다." << endl;
			return;
		}
		else if (root->left != NULL&&root->left->data == data)
			//왼쪽 자식이 삭제 노드일 경우
		{
			del = root->left;
			p = root;
			break;
		}
		else if (root->right != NULL&&root->right->data == data)
			//오른쪽 자식이 삭제 노드일 경우
		{
			del = root->right;
			p = root;
			break;
		}
		if (data < root->data) //root노드보다 작은 수인경우
			root = root->left; //왼쪽 자식으로 이동
		else if (data > root->data) //root노드보다 큰 수인경우
			root = root->right; //오른쪽 자식으로 이동
	}

	//====================후속 처리 시작===========================
	if (del->right == NULL && del->left == NULL) //삭제 노드가 단노드일 경우
	{
		if (p->right != NULL && p->right == del) //오른쪽 자식노드가 삭제 노드인 경우
			p->right = NULL; //삭제 노드의 부모 노드 오른쪽 연결 해제
		else//왼쪽 자식 노드가 삭제 노드일 경우
			p->left = NULL; //삭제 노드의 부모 노드 왼쪽 연결 해제
	}

	else if ((del->right == NULL && del->left != NULL) || (del->right != NULL && del->left == NULL))
		//삭제하고자 하는 노드의 자식노드가 한개인 경우
	{
		if (del->right != NULL) //오른쪽 자식이 존재하는 경우
		{
			if (p->right == del) //오른쪽 자식노드가 삭제 노드인 경우
				p->right = del->right; //삭제 노드 대신 삭제 노드의 자식 노드 연결
			else //왼쪽 자식노드가 삭제 노드인 경우
				p->left = del->right; //삭제 노드 대신 삭제 노드의 자식 노드 연결
		}
		else //왼쪽 자식이 존재하는 경우
		{
			if (p->right == del) //오른쪽 자식노드가 삭제 노드인 경우
				p->right = del->left; //삭제 노드 대신 삭제 노드의 자식 노드 연결
			else //왼쪽 자식노드가 삭제 노드인 경우
				p->left = del->left; //삭제 노드 대신 삭제 노드의 자식 노드 연결
		}
	}

	else //삭제 노드의 자식노드가 두 개인 경우
	{
		//오른쪽 자식 노드 중 최대 값 노드 대입 방법으로 구현함
		//삭제 노드의 오른쪽 자식이 오른쪽 서브트리의 제일 큰 노드라고 가정
		max_right = del->right;
		p_max_right = del;

		while (max_right->left != NULL)	//max_right의 왼쪽 자식이 존재하는 경우 반복
										//오른쪽 서브트리의 가장 큰 노드 찾는 과정
		{
			p_max_right = max_right;
			max_right = max_right->left;
		}

		if (del->right == max_right)
			//삭제 노드의 오른쪽 자식이 오른쪽 서브트리의 최대 값일 경우
		{
			max_right->left = del->left;
			//최대 노드의 왼쪽 자식에 삭제 노드의 왼쪽 자식 연결
		}

		else
			//삭제 노드의 오른쪽 자식이 오른쪽 서브트리의 최대 값이 아닌 경우
		{
			p_max_right->left = max_right->right;
			//최대값 노드와 부모 노드 연결 해제
			max_right->right = del->right;
			max_right->left = del->left;
			//최대값 노드 삭제 노드 위치에 삽입
		}

		if (p->left == del) //왼쪽 자식이 삭제 노드일 경우
			p->left = max_right; //부모노드에 새로 삽입한 노드 연결
		else //오른쪽 자식이 삭제 노드일 경우
			p->right = max_right;//부모노드에 새로 삽입한 노드 연결

	}
	//============================================================

	free(del); //노드 삭제
  cout << "노드가 삭제되었습니다." << endl;
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
