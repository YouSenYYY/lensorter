// MC.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "gtscontrol.h"
#include "iocontrol.h"

using namespace MC;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    // �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false); 

    // ���������ڲ�������
    Application::Run(gcnew IOControl());
    return 0;
}
