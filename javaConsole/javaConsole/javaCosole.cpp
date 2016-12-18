#include"Common_Console.h"
#include<Turboc.h>
#include <locale.h>

JNIEXPORT void JNICALL Java_Common_Console_gotoXY(JNIEnv *, jclass, jint nX, jint nY)
{
	gotoxy(nX, nY);
}

JNIEXPORT void JNICALL Java_Common_Console_cls(JNIEnv *, jclass)
{
	clrscr();
}

JNIEXPORT void JNICALL Java_Common_Consol_setCursor(JNIEnv *, jclass, jint Type)
{
	setcursortype((CURSOR_TYPE)Type);
}

JNIEXPORT void JNICALL Java_Common_Console_size(JNIEnv *, jclass, jint nX, jint nY)
{
	char strTemp[100] = { 0, };
	sprintf(strTemp, "mode con cols=%d lines=%d", nX, nY);
	system(strTemp);
}

JNIEXPORT jint JNICALL Java_Common_Console_whereX(JNIEnv *, jclass)
{
	return wherex();
}

JNIEXPORT jint JNICALL Java_Common_Console_whereY(JNIEnv *, jclass)
{
	return wherey();
}

static void SetColor(jint nBackgound, jint nFont)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nBackgound | nFont);
}

static jint g_nOldBackgroundColor = 0;
static jint g_nOldFontColor = 0;
JNIEXPORT jint JNICALL Java_Common_Console_backgroundColor(JNIEnv *, jclass, jint nColor)
{
	jint nRetOldColor = g_nOldBackgroundColor;
	g_nOldBackgroundColor = nColor * 16;
	SetColor(g_nOldBackgroundColor, g_nOldFontColor);
	return nRetOldColor;
}

JNIEXPORT jint JNICALL Java_Common_Console_fontColor(JNIEnv *, jclass, jint nColor)
{
	jint nRetOldColor = g_nOldFontColor;
	g_nOldFontColor = nColor;
	SetColor(g_nOldBackgroundColor, g_nOldFontColor);
	return nRetOldColor;
}

JNIEXPORT void JNICALL Java_Common_Console_setTitle(JNIEnv *env, jclass, jstring strTitle)
{
	char strTemp[512] = { 0, };
	const char *str = env->GetStringUTFChars(strTitle, NULL);
	sprintf(strTemp, "%s", str);
	env->ReleaseStringUTFChars(strTitle, str);
	SetConsoleTitleA(strTemp);
	printf("%s", strTemp);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		_wsetlocale(LC_ALL, L"Korean");
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
