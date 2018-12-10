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
struct Person e[MAX];
int count = 0;

int PrintMenu();
void InsertDB();
void DeleteDB();
void SearchDB();
void PrintDB();
void ExitDB();
void save();
void load();
Person *New_Node(void);
Person *head, *tail, *New_Person;

int main()
{
   head = New_Node();
   tail = head;

   load();

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

void InsertDB() {
   New_Person = New_Node();
   printf("[ INSERT ]\n");

   printf("Input Name : ");
   getchar();
   scanf("%[^\n]s\n", New_Person->name);


   printf("Input Tel Number : ");
   getchar();
   scanf("%[^\n]s\n", New_Person->number);

   printf("Input Address : ");
   getchar();
   scanf("%[^\n]s\n", New_Person->address);

   tail->next = New_Person;
   tail = New_Person;
   tail->next = NULL;

   printf("등록 되었습니다.\n");
}

void DeleteDB() {
   char input[NAME_LEN];

   printf("[ Remove ]\n");
   printf("Input Name for Removing : ");
   scanf("%[^\n]s", input);

   New_Person = head;
   while (New_Person != NULL)
   {
      if (New_Person->name == input)
      {

      }
      New_Person = New_Person->next;
   }

   printf("삭제되었습니다\n");
   count -= 1;
   save();
}

void SearchDB() {
   int choice;

   printf("[ Search ]\n");
   printf("검색할 방법을 선택해 주십시오: 1.이름 2.번호 3.주소\n");
   scanf("%d", &choice);


   if (choice == 1)
   {
      char input[NAME_LEN];
      char *result;

      printf("검색하실 이름을 입력하여 주십시오:");
      getchar();
      scanf("%[^\n]s", input);

      for (int i = 0; i < count; i++)
      {
         result = strstr(e[i].name, input);

         if (result != 0)
            printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", e[i].name, e[i].number, e[i].address);
      }
   }
   else if (choice == 2)
   {
      char input[TEL_LEN], number1[MAX][TEL_LEN] = { 0 };

      printf("검색하실 번호 뒷 4자리를 입력하여 주십시오:");
      scanf("%s", input);

      for (int i = 0; i < count; i++)
      {
         strcpy(number1[i], e[i].number);

         char *poi = strtok(number1[i], "-");
         char *tmp = NULL;

         while (poi != NULL)
         {
            tmp = poi;
            poi = strtok(NULL, "-");
         }
         if (!strcmp(tmp, input))
            printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", e[i].name, e[i].number, e[i].address);
      }
   }
   else
   {
      char input[ADDR_LEN], address1[MAX][ADDR_LEN] = { 0 };

      printf("검색하실 주소의 (시or동)을 입력하여 주십시오:");
      getchar();
      scanf("%[^\n]s", input);

      for (int i = 0; i < count; i++)
      {
         strcpy(address1[i], e[i].address);

         char *poi = strtok(address1[i], " ");

         while (poi != NULL)
         {
            if (!strcmp(poi, input))
               printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", e[i].name, e[i].number, e[i].address);
            poi = strtok(NULL, " ");
         }

      }
   }
}

void PrintDB() {
   printf("[ Print All Data ]\n");
   New_Person = head;
   while (New_Person != NULL)
   {
      printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", New_Person->name, New_Person->number, New_Person->address);
      New_Person = New_Person->next;
   }
}

void ExitDB() {
   printf("종료 메뉴를 선택했습니다.\n");
}

void save()
{
   FILE *fp = fopen("C:\\Users\\djwls\\Desktop\\c언어 전공과제\\Tel_DB.txt", "w");

   New_Person = head;
   while (New_Person != NULL)
   {
      fprintf(fp, "Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", New_Person->name, New_Person->number, New_Person->address);
      New_Person = New_Person->next;
   }
   fclose(fp);
}

void load()
{
   FILE *fp = fopen("C:\\Users\\djwls\\Desktop\\c언어 전공과제\\Tel_DB.txt", "a+");
   count = 0;
   New_Person = head;
   while (New_Person != NULL)
   {
      fscanf(fp, "Name : %s\t/\tTel : %s\t/\tAddress : %s\n", New_Person->name, New_Person->number, New_Person->address);
      New_Person = New_Person->next;
      count++;
   }
   fclose(fp);
}

Person *New_Node(void)
{
   return (Person*)malloc(sizeof(Person));
}
