#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100
#define NAME_LEN 20
#define TEL_LEN 20
#define ADDR_LEN 70

struct Person
{
   char name[NAME_LEN];
   char number[TEL_LEN];
   char address[ADDR_LEN];
};
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

int main()
{
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
   printf("[ INSERT ]\n");

   printf("Input Name : ");
   for (int n = count; n < MAX; n++) {
      getchar();
      scanf("%[^\n]s", e[n].name);
      break;
   }

   printf("Input Tel Number : ");
   for (int t = count; t < MAX; t++) {
      getchar();
      scanf("%[^\n]s", e[t].number);
      break;
   }

   printf("Input Address : ");
   for (int a = count; a < MAX; a++) {
      getchar();
      scanf("%[^\n]s", e[a].address);
      break;
   }
   printf("등록 되었습니다.\n");
   count += 1;
   save();
}

void DeleteDB() {
   int i;
   char input[NAME_LEN];

   printf("[ Remove ]\n");
   printf("Input Name for Removing : ");
   getchar();
   scanf("%[^\n]s", input);

   for (i = 0; i < MAX; i++)
   {
      if (!strcmp(e[i].name, input))
      {
         for (; i < count; i++)
         {
            strcpy(e[i].name, e[i + 1].name);
            strcpy(e[i].number, e[i + 1].number);
            strcpy(e[i].address, e[i + 1].address);
         }
      }
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

   for (int i = 0; i < count; i++) {
      printf("Name : %-10s\t/\tTel : %-10s\t/\tAddress : %-10s\n", e[i].name, e[i].number, e[i].address);
   }
}

void ExitDB() {
   printf("종료 메뉴를 선택했습니다.\n");
}

void save()
{
   FILE *fp = fopen("c:\\temp\\data.txt", "w");
   int i;
   for (i = 0; i < count; i++)//배열을 차례대로
      fprintf(fp, "%s %s\n", e[i].name, e[i].number);//파일에 저장

   fclose(fp);
}

void load()
{
   FILE *fp = fopen("c:\\temp\\data.txt", "a+");  //오픈할 파일의 포인터를 할당
   count= 0; //파일에서 한줄 읽어올때마나 값을 증가시켜 총 레코드 갯수를 확인할 목적으로 사용되는변수
   while (1) //일단 무한루프로 만들고
   {
      if (fscanf(fp, "%s %s\n", e[count].name, e[count].number) == EOF)
         break;//파일에서 읽어 옵니다. //if문에서 지정한 파일에서 값을 읽어오다가 화일의 끝(EOF)가되면 break문에 의해 while루프를 탈출
      count++;//데이타 갯수를 카운트
   }
   fclose(fp);  //사용할 파일을 오픈했으면 반드시 사용후에 닫아주어야 함
}
