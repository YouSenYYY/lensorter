#pragma once

#using "..\bin\Debug\\CCL.dll"

namespace MotionControl {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace CCL;

	/// <summary>
	/// Form1 ժҪ
	/// </summary>
	public ref class ParaInfo : public System::Windows::Forms::Form
	{
	public:
		ParaInfo(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~ParaInfo()
		{
			if (components)
			{
				delete components;
			}
        }
    private: CCL::RowMergeView^  dataGridView1;

    protected: 

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
            this->SuspendLayout();
            // 
            // ParaInfo
            // 
            this->ClientSize = System::Drawing::Size(282, 255);
            this->Name = L"ParaInfo";
            this->ResumeLayout(false);

        }
#pragma endregion

    };
}

