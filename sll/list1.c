#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NAME_LEN 20
#define TEL_LEN 20
#define ADDR_LEN 70

typedef struct Person
{
   char name[NAME_LEN];
   char number[TEL_LEN];
   char address[ADDR_LEN];

   struct Person *next;
}Person;

Person *head = NULL;
Person *tail = NULL;

void InsertDB();
void DeleteDB();
void SearchDB();
void PrintDB();
void ExitDB();
void save();
void load();
int PrintMenu();

void InsertDB()
{
  Person *temp = (Person*)malloc(sizeof(Person));

  printf("[ INSERT ]\n");

  printf("Input Name : ");
  getchar();
  scanf("%[^\n]s\n", temp->name);

  printf("Input Tel Number : ");
  getchar();
  scanf("%[^\n]s\n", temp->number);

  printf("Input Address : ");
  getchar();
  scanf("%[^\n]s\n", temp->address);

  // while (head->next != NULL)
  //   head = head->next;
  // head->next = temp;
  // temp->next = NULL;

  tail->next = temp;
  tail = temp;
  temp->next = NULL;

  printf("등록 되었습니다.\n");
  save();
}

void DeleteDB()
{
  char input[NAME_LEN];
  Person *temp = head;
  Person *prev = NULL;

  printf("[ Remove ]\n");
  printf("Input Name for Removing : ");
  getchar();
  scanf("%[^\n]s", input);

  while (temp != NULL)
  {
    if (strcmp(input, temp->name) == 0)
    {
      if (prev == NULL)
        head = temp->next;
      else
        prev->next = temp->next;
      free(temp);
      printf("삭제되었습니다\n");
    }
    prev = temp;
    temp = temp->next;
  }
  save();
}

void SearchDB()
{
  int choice;
  Person *temp = head;

  printf("[ Search ]\n");
  printf("검색할 방법을 선택해 주십시오: 1.이름 2.번호 3.주소\n");
  scanf("%d", &choice);

  if (choice == 1)
  {
    char nameInput[NAME_LEN];
    printf("검색하실 이름을 입력하여 주십시오 : ");
    getchar();
    scanf("%[^\n]s", nameInput);

    while (temp != NULL)
    {
      if (strcmp(nameInput, temp->name) == 0)
        printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", temp->name, temp->number, temp->address);
      temp = temp->next;
    }
  }

  else if (choice == 2)
  {
    char telInput[TEL_LEN];
    char tempTel[TEL_LEN];
    printf("검색하실 번호 뒷 4자리를 입력하여 주십시오 : ");
    getchar();
    scanf("%[^\n]s", telInput);

    while (temp != NULL)
    {
      strcpy(tempTel, temp->number);

      char *poi = strtok(tempTel, "-");
      char *tmp = NULL;

      while (poi != NULL)
      {
         tmp = poi;
         poi = strtok(NULL, "-");
      }

      if (!strcmp(tmp, telInput))
        printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", temp->name, temp->number, temp->address);
      temp = temp->next;
    }
  }

  else if (choice == 3)
  {
    char addrInput[ADDR_LEN];
    char tempAddr[ADDR_LEN];
    printf("검색하실 주소의 (시or동)을 입력하여 주십시오 : ");
    getchar();
    scanf("%[^\n]s", addrInput);

    while (temp != NULL)
    {
      strcpy(tempAddr, temp->address);
      char *poi = strtok(tempAddr, " ");

      while (poi != NULL)
      {
        if (!strcmp(poi, addrInput))
          printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", temp->name, temp->number, temp->address);
        poi = strtok(NULL, " ");
      }
      temp = temp->next;
    }
  }
}

void PrintDB()
{
  Person *temp = head;

  printf("[ Print All Data ]\n");

  temp = temp->next;
  while (temp != NULL)
  {
    printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", temp->name, temp->number, temp->address);
    temp = temp->next;
  }
}

void ExitDB() {
   printf("종료 메뉴를 선택했습니다.\n");
}


void save()
{
   FILE *fp = fopen("C:\\Users\\djwls\\Desktop\\c언어 전공과제\\Tel_DB.txt", "a+");

   Person *temp = head;
   temp = temp->next;
   while (temp != NULL)
   {
      fprintf(fp, "Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", temp->name, temp->number, temp->address);
      temp = temp->next;
   }
   fclose(fp);
}

void load()
{
   FILE *fp = fopen("C:\\Users\\djwls\\Desktop\\c언어 전공과제\\Tel_DB.txt", "r+");

   Person *temp = head;
   temp = temp->next;
   while (temp != NULL)
   {
      fscanf(fp, "Name : %s\t/\tTel : %s\t/\tAddress : %s\n", temp->name, temp->number, temp->address);
      temp = temp->next;
   }
   fclose(fp);
}

int PrintMenu()
{
   int num = 0;

   printf("--------Menu--------\n");
   printf("1. 등록<Insert>\n");
   printf("2. 삭제<Delete>\n");
   printf("3. 검색<Search>\n");
   printf("4. 출력<Print>\n");
   printf("5. 종료<Exit>\n");
   printf("--------------------\n");

   printf("메뉴를 선택하세요[1~5] : ");
   if (scanf("%d", &num))
      return num;
}


int main()
{
   // load();

   head = (Person*)malloc(sizeof(Person));
   tail = head;

   while (1)
   {
      int num = 0;
      num = PrintMenu();

      switch (num)
      {
      case 1:
         InsertDB();
         break;
      case 2:
         DeleteDB();
         break;
      case 3:
         SearchDB();
         break;
      case 4:
         PrintDB();
         break;
      case 5:
         ExitDB();
         return 0;
         break;
      default:
         printf("다시 입력하세요.[1~5]\n");
         break;
      }
   }
   free(head);
}
