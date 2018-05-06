#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<openssl/md5.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void getMDS(const char* str, char* result)
{
	MD5_CTX ctx;

	MDS_Init(&ctx);

	MDS_Updat(&ctx, str, strlen(str));

	unsigned char md[16] = { 0 };
	MDS_Final(md, &ctx);
	for (int i = 0; i < 16; i++)
	{
		sprintf(&result[i * 2], "%02x", md[i]);
	}
}
int main()
{
	char result[33] = { 0 };
	grtMDS("hello,mds", result);
	printf("mds value: %s\n", result);

	system("pause");
	return EXIT_SUCCESS;
}
