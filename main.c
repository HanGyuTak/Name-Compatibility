#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

const char *kor = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎㅏㅑㅓㅕㅗㅛㅜㅠㅡㅣ";
int kc[29] = { 2,4,2,3,6,5,4,4,8,2,4,1,3,6,4,3,4,4,3,2,3,2,3,2,3,2,3,1,1};

typedef struct Person 
{
	char name[3][11];
	int c[3][5];
	int total[3];
}Pe;
//사람 구조체

int writecount(char* scan)
{
	for (int i = 0; i < 59; i += 2)
	{
		if (strncmp(scan, kor+i, 2) == 0) return kc[i / 2];
	}
}
//획수 찾아주는 함수

int percent(int* n)
{
	for (int i = 0; i < 6; i++) printf("%d ", n[i]);
	printf("\n");
	for (int i = 6; i > 2; i--)
	{
		for (int j = 0; j < i-1; j++)
		{
			//printf("%d ", n[j]);
			n[j] = (n[j] + n[j + 1]) % 10;
			printf("%d ", n[j]);
		}
		printf("\n");
	}
	return n[0] * 10 + n[1];
}
//확률 계산 함수

int main()
{
	Pe p1, p2;
	char sc[2] = { NULL };
	int nu[6];
	printf("****************************************************\n당신과 상대방의 이름 궁합을 봐드립니다.\n");
	printf("당신의 이름은 무엇입니까? (입력예시 : 한 -> ㅎㅏㄴ)\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 글자 : ", i + 1); gets_s(p1.name[i],sizeof(p1.name[i]));		
		for (int j = 0; p1.name[i][j] != '\0'; j += 2)
		{
			p1.c[i][j / 2] = writecount(&(p1.name[i][j]));
		}
	}
	//자기 이름 입력
	printf("\n상대방의 이름은 무엇입니까?\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 글자 : ", i + 1); gets_s(p2.name[i], sizeof(p2.name[i]));
		for (int j = 0; p2.name[i][j] != '\0'; j += 2)
		{
			p2.c[i][j / 2] = writecount(&(p2.name[i][j]));
		}
	}
	//상대 이름 입력

	for (int i = 0; i < 3; i++)
	{
		p1.total[i] = 0; p2.total[i] = 0;
		for (int j = 0; p1.c[i][j] > 0 && p1.c[i][j] < 10; j++) p1.total[i] += p1.c[i][j];
		for (int j = 0; p2.c[i][j] > 0 && p2.c[i][j] < 10; j++) p2.total[i] += p2.c[i][j];
	}
	//글자당 횟수를 저장
	
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0) nu[i] = p1.total[i / 2];
		else nu[i] = p2.total[i / 2];
	}
	//6개의 배열에 저장

	printf("\n.\n.\n.\n.\n");
	printf("당신과 상대의 궁합은 %d%%입니다.\n\n\n끝\n\n", percent(nu));

	return 0;
}