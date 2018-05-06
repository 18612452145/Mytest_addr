#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<openssl/md5.h>
#include<time.h>
void getMD5(const char* str, char* result)
{
	MD5_CTX ctx;

	MD5_Init(&ctx);

	MD5_Update(&ctx, str, strlen(str));

	unsigned char md[16] = { 0 };
	MD5_Final(md, &ctx);
	for (int i = 0; i < 16; i++)
	{
		sprintf(&result[i * 2], "%02x", md[i]);
	}
}
int main()
{
	char result[33] = { 0 };
	getMD5("hello,mds", result);
	printf("mds value: %s\n", result);

	system("pause");
	return EXIT_SUCCESS;
}