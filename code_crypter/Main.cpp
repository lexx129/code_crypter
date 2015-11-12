#include <cstdio>
#include <fstream>
#include <Windows.h>

using namespace std;

void printText(char *text){
	printf("%s\n", *text);	
}

void printTextStub(){
}

void crypt(DWORD startAddress, DWORD length){
	char buff[1000];
	FILE *f;
	f = fopen("C:\\Users\\admin\\Documents\\Visual Studio 2010\\Projects\\code_crypter\\Release\\code_crypter.exe", "wb");
	fseek(f, 1024, SEEK_SET);
	//int n = (unsigned int) startAddress;
	for (int i = startAddress; i < startAddress + length; i++) {
      //xor operation on i's address with 0x5A
		fputc((int)buff[i] ^ 0x5A, f);
	}
	fclose(f);
}

int main(){
	DWORD printFunctionSize = 0, oldProtect;
	DWORD *fA = NULL, *fB = NULL;

	fA = (DWORD *)&printText;
	fB = (DWORD *)&printTextStub;
	printFunctionSize = fB - fA;
	VirtualProtect(fA, printFunctionSize, PAGE_EXECUTE_READWRITE, &oldProtect);
	crypt((DWORD)fA, printFunctionSize);
	//printf("Hello, world \n");
	system("PAUSE");
	return 0;
}