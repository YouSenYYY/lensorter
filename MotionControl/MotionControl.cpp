// MotionControl.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "test.h"

using namespace MotionControl;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    // �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false); 

    // ���������ڲ�������
    Application::Run(gcnew Test());
    return 0;
}
