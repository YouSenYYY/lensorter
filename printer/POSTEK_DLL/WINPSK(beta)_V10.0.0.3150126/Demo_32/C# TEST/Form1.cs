using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace CSHARP_POSTEK_PRINT
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            PrintLab.OpenPort("POSTEK G-2108");//打开打印机端口
            PrintLab.PTK_ClearBuffer();           //清空缓冲区
            PrintLab.PTK_SetPrintSpeed(4);        //设置打印速度
            PrintLab.PTK_SetDarkness(10);         //设置打印黑度
            PrintLab.PTK_SetLabelHeight(600, 16,0,false); //设置标签的高度和定位间隙\黑线\穿孔的高度
            PrintLab.PTK_SetLabelWidth(800);      //设置标签的宽度

            for (int i = 1; i <= 1; i++)
            {
                // 画矩形
                PrintLab.PTK_DrawRectangle(58, 15, 3, 558, 312);
                

                // 打印PCX图片 方式一
                PrintLab.PTK_PcxGraphicsDel("PCX");
                PrintLab.PTK_PcxGraphicsDownload("PCX", "logo.pcx");
                PrintLab.PTK_DrawPcxGraphics(80, 20, "PCX");
                
                // 打印PCX图片 方式二
                // PTK_PrintPCX(80,30,pchar('logo.pcx'));

                // 打印一个条码;
                PrintLab.PTK_DrawBarcode(300, 23, 0, "1", 2, 2, 50, 'B', "123456789");              

                // 画表格分割线
                PrintLab.PTK_DrawLineOr(58, 100, 500, 3);               

                // 打印一行TrueTypeFont文字;
                PrintLab.PTK_DrawTextTrueTypeW(80, 120, 40, 0, "Arial", 1, 400, false, false, false, "A1", "TrueTypeFont");                

                // 打印一行文本文字(内置字体或软字体);
                PrintLab.PTK_DrawText(80, 168, 0, 3, 1, 1, 'N', "Internal Soft Font");
                
                // 打印PDF417码
                PrintLab.PTK_DrawBar2D_Pdf417(80, 210, 400, 300, 0, 0, 3, 7, 10, 2, 0, 0, "123456789");//PDF417码
                
                // 打印QR码
                PrintLab.PTK_DrawBar2D_QR(420, 120, 180, 180, 0, 3, 2, 0, 0, "Postek Electronics Co., Ltd.");
                

                // 打印一行TrueTypeFont文字旋转;
                PrintLab.PTK_DrawTextTrueTypeW(520, 102, 22, 0, "Arial", 2, 400, false, false, false, "A2", "www.postek.com.cn");
                PrintLab.PTK_DrawTextTrueTypeW(80, 260, 19, 0, "Arial", 1, 700, false, false, false, "A3", "Use different ID_NAME for different Truetype font objects");
                

                // 命令打印机执行打印工作
                PrintLab.PTK_PrintLabel(1, 1);
              
            }
            PrintLab.ClosePort();//关闭打印机端口
            
        }
    }
}
public class PrintLab
{
    [DllImport("WINPSK.dll")]
    public static extern int OpenPort(string printname);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_SetPrintSpeed(uint px);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_SetDarkness(uint id);
    [DllImport("WINPSK.dll")]
    public static extern int ClosePort();
    [DllImport("WINPSK.dll")]
    public static extern int PTK_PrintLabel(uint number, uint cpnumber);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawTextTrueTypeW
                                        (int x, int y, int FHeight,
                                        int FWidth, string FType,
                                        int Fspin, int FWeight,
                                        bool FItalic, bool FUnline,
                                        bool FStrikeOut,
                                        string id_name,
                                        string data);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawBarcode(uint px,
                                    uint py,
                                    uint pdirec,
                                    string pCode,
                                    uint pHorizontal,
                                    uint pVertical,
                                    uint pbright,
                                    char ptext,
                                    string pstr);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_SetLabelHeight(uint lheight, uint gapH, int gapOffset, bool bFlag);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_SetLabelWidth(uint lwidth);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_ClearBuffer();
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawRectangle(uint px, uint py, uint thickness, uint pEx, uint pEy);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawLineOr(uint px, uint py, uint pLength, uint pH);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawBar2D_QR( uint x,uint y, uint w,  uint v,uint o,  uint r,uint m,  uint g,uint s,string pstr);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawBar2D_Pdf417(uint x, uint  y,uint w, uint v,uint s, uint c,uint px, uint  py,uint r, uint l,uint t, uint o,string pstr);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_PcxGraphicsDel(string pid);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_PcxGraphicsDownload(string pcxname, string pcxpath);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawPcxGraphics(uint px, uint py, string gname);
    [DllImport("WINPSK.dll")]
    public static extern int PTK_DrawText(uint px,uint  py,uint  pdirec,uint pFont,uint  pHorizontal, uint pVertical,char ptext, string pstr);

    
}