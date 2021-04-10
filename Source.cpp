#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#define THREAD_AMOUNT 30
typedef struct _DATA
{
	char str[32];
	int value;
}	DATA, * LPDATA;


DWORD WINAPI ThreadfFunc(LPVOID lpParam)
{
	LPDATA pData = (LPDATA)lpParam;
	for (int i = 0; i < 10; i++)
	{
		printf("%s,%d\n", pData->str, pData->value++);

	}
	return TRUE;
}

int main(void)
{
	HANDLE hThread[THREAD_AMOUNT];
	DATA data[THREAD_AMOUNT];

	for (int i = 0; i < THREAD_AMOUNT; i++)
	{
		data[i] = { 0 };
		sprintf(data[i].str, "str-> %d", 'A' + i);
		data[i].value = 0;
	}
	for (int i = 0; i < THREAD_AMOUNT; i++)
	{
		hThread[i] = CreateThread(NULL, 0, ThreadfFunc, &data[i], NULL, NULL);
	}
	WaitForMultipleObjects(THREAD_AMOUNT, hThread, TRUE, INFINITE);
	for (int i = 0; i < THREAD_AMOUNT; i++)
	{
		CloseHandle(hThread[i]);
	}
	return 0;
}
















