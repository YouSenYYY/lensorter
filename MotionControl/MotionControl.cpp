// MotionControl.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "gtsmotionclass.h"

int _tmain(int argc, _TCHAR* argv[])
{
    GTSMotionClass gmc;
    printf("Open: %d\n", gmc.OpenCard());

    system("pause");
	return 0;
}

