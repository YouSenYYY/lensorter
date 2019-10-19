#pragma once

#include "gtsmotionproxy.h"

namespace MC {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// iocontrol ժҪ
    /// </summary>
    public ref class IOControl : public System::Windows::Forms::Form
    {
    public:
        IOControl(void)
        {
            InitializeComponent();
            //
            //TODO: �ڴ˴���ӹ��캯������
            //
            InitControl(this->gbxInput, "lblInput");
            InitControl(this->gbxOutput, "lblOutput");

            selectedCard = selectedMdl = 0;
            this->cbxSelectCard->SelectedIndex = 0;
            this->cbxSelectMdl->SelectedIndex = 0;

            gts400 = gcnew GTSMotionProxy(0, 4, 4);
            gts800 = gcnew GTSMotionProxy(1, 8, 0);
        }

    protected:
        /// <summary>
        /// ������������ʹ�õ���Դ��
        /// </summary>
        ~IOControl()
        {
            if (components)
            {
                delete components;
            }
        }

    protected:
        int getMdl();
        void ResetMdl();
        void RefreshInput();
        void RefreshOutput();
        int StringToInt(String ^s);
        GTSMotionProxy^ gtsControl();

    private:
        void InitControl(System::Windows::Forms::GroupBox^ gbx, String^ iotype);
        System::Void lblIO_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void cbxSelectCard_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void cbxSelectMdl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void timerRefresh_Tick(System::Object^ sender, System::EventArgs^ e);

        GTSMotionProxy^ gts400;
        GTSMotionProxy^ gts800;
        int selectedCard;
        int selectedMdl;

    private:
        /// <summary>
        /// ����������������
        /// </summary>
        System::ComponentModel::IContainer^  components;
        System::Windows::Forms::GroupBox^  gbxOutput;
        System::Windows::Forms::GroupBox^  gbxInput;
        System::Windows::Forms::Label^  label1;
        System::Windows::Forms::Label^  label2;
        System::Windows::Forms::ComboBox^  cbxSelectCard;
        System::Windows::Forms::ComboBox^  cbxSelectMdl;
        System::Windows::Forms::Button^  btnClose;
        System::Windows::Forms::Button^  btnOpen;
        System::Windows::Forms::Timer^  timerRefresh;
             

#pragma region Windows Form Designer generated code
        /// <summary>
        /// �����֧������ķ��� - ��Ҫ
        /// ʹ�ô���༭���޸Ĵ˷��������ݡ�
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->gbxInput = (gcnew System::Windows::Forms::GroupBox());
            this->gbxOutput = (gcnew System::Windows::Forms::GroupBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->cbxSelectCard = (gcnew System::Windows::Forms::ComboBox());
            this->cbxSelectMdl = (gcnew System::Windows::Forms::ComboBox());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->btnOpen = (gcnew System::Windows::Forms::Button());
            this->timerRefresh = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // gbxInput
            // 
            this->gbxInput->Location = System::Drawing::Point(26, 103);
            this->gbxInput->Name = L"gbxInput";
            this->gbxInput->Size = System::Drawing::Size(352, 114);
            this->gbxInput->TabIndex = 0;
            this->gbxInput->TabStop = false;
            this->gbxInput->Text = L"����";
            // 
            // gbxOutput
            // 
            this->gbxOutput->Location = System::Drawing::Point(26, 227);
            this->gbxOutput->Name = L"gbxOutput";
            this->gbxOutput->Size = System::Drawing::Size(352, 114);
            this->gbxOutput->TabIndex = 1;
            this->gbxOutput->TabStop = false;
            this->gbxOutput->Text = L"���";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(34, 25);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(22, 15);
            this->label1->TabIndex = 33;
            this->label1->Text = L"��";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(33, 63);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(31, 15);
            this->label2->TabIndex = 35;
            this->label2->Text = L"mdl";
            // 
            // cbxSelectCard
            // 
            this->cbxSelectCard->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbxSelectCard->FormattingEnabled = true;
            this->cbxSelectCard->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"GTS-400", L"GTS-800"});
            this->cbxSelectCard->Location = System::Drawing::Point(83, 21);
            this->cbxSelectCard->Name = L"cbxSelectCard";
            this->cbxSelectCard->Size = System::Drawing::Size(121, 23);
            this->cbxSelectCard->TabIndex = 32;
            this->cbxSelectCard->SelectedIndexChanged += gcnew System::EventHandler(this, &IOControl::cbxSelectCard_SelectedIndexChanged);
            // 
            // cbxSelectMdl
            // 
            this->cbxSelectMdl->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbxSelectMdl->FormattingEnabled = true;
            this->cbxSelectMdl->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"��", L"0", L"1", L"2", L"3"});
            this->cbxSelectMdl->Location = System::Drawing::Point(83, 60);
            this->cbxSelectMdl->Name = L"cbxSelectMdl";
            this->cbxSelectMdl->Size = System::Drawing::Size(121, 23);
            this->cbxSelectMdl->TabIndex = 34;
            this->cbxSelectMdl->SelectedIndexChanged += gcnew System::EventHandler(this, &IOControl::cbxSelectMdl_SelectedIndexChanged);
            // 
            // btnClose
            // 
            this->btnClose->Location = System::Drawing::Point(319, 33);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(62, 35);
            this->btnClose->TabIndex = 45;
            this->btnClose->Text = L"�ر�";
            this->btnClose->UseVisualStyleBackColor = true;
            this->btnClose->Click += gcnew System::EventHandler(this, &IOControl::btnClose_Click);
            // 
            // btnOpen
            // 
            this->btnOpen->Location = System::Drawing::Point(240, 33);
            this->btnOpen->Name = L"btnOpen";
            this->btnOpen->Size = System::Drawing::Size(62, 35);
            this->btnOpen->TabIndex = 44;
            this->btnOpen->Text = L"��";
            this->btnOpen->UseVisualStyleBackColor = true;
            this->btnOpen->Click += gcnew System::EventHandler(this, &IOControl::btnOpen_Click);
            // 
            // timerRefresh
            // 
            this->timerRefresh->Interval = 500;
            this->timerRefresh->Tick += gcnew System::EventHandler(this, &IOControl::timerRefresh_Tick);
            // 
            // IOControl
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
            ////this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(403, 364);
            this->Controls->Add(this->btnClose);
            this->Controls->Add(this->btnOpen);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->cbxSelectMdl);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->cbxSelectCard);
            this->Controls->Add(this->gbxOutput);
            this->Controls->Add(this->gbxInput);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
            this->Name = L"IOControl";
            this->Text = L"IO����";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
};
}
