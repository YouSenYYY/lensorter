#include "StdAfx.h"
#include "gtscontrol.h"

using namespace MC;

#pragma region �״�
const char* GTSControl::StringToChars(String ^s)
{
    std::string s1 = marshal_as<std::string>(s); // OK
    const char* str = marshal_as<std::string>(s).c_str(); // FAIL !!!
    return str;
}
#pragma endregion

int GTSControl::StringToInt(String ^s)
{
    // marshal_as�����صĶ�����Ҫ��ʽ�ڴ�����ʱ������Ҫ����marshal_context�����ĵķ�����
    marshal_context ^mc = gcnew marshal_context();
    const char* str = mc->marshal_as<const char*>(s);
    int value = _ttoi(str);
    delete mc;  // ��marshal_contextɾ�����κ��ڷ��͵����ڼ������ڴ涼�����ͷ�
    return value;
}

double GTSControl::StringToDouble(String ^s)
{
    IntPtr ip = Marshal::StringToHGlobalAnsi(s); // תΪ���й��ڴ�
    const char* str = static_cast<const char*>(ip.ToPointer());
    double value = _ttof(str);
    Marshal::FreeHGlobal(ip); // �ͷ��ڴ�
    return value;
}
