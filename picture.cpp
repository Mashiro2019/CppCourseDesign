#include"func.h"

void Main_interface()
{
	initgraph(1000, 620);
	loadimage(NULL, _T("TUST.png"));
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	setbkmode(TRANSPARENT);                //�������屳��Ϊ͸��
	settextcolor(BLACK);                   //����������ɫ
	outtextxy(200, 100, _T("TUST�ɼ�����ϵͳ"));
	settextcolor(WHITE);
	settextstyle(32, 0, _T("����"));
	outtextxy(650, 160, _T("1.����ѧ����Ϣ"));
	outtextxy(650, 200, _T("2.��ʾѧ����Ϣ"));
	outtextxy(650, 240, _T("3.��ʾѧ���ɼ�����"));
	outtextxy(650, 280, _T("4.����ѧ��"));
	outtextxy(650, 320, _T("5.�޸�ѧ���ɼ�"));
	outtextxy(650, 360, _T("6.ɾ��ѧ����Ϣ"));
	outtextxy(650, 400, _T("7.����������"));
	outtextxy(650, 440, _T("8.�˳�ϵͳ"));
}

char* GetOptions() {
	char ch[100];
	int num = MultiByteToWideChar(0, 0, ch, -1, NULL, 0);
	wchar_t* wide = new wchar_t[num];
	MultiByteToWideChar(0, 0, ch, -1, wide, num);
	InputBox(wide, 100, _T("��������Ҫѡ��Ĺ��ܣ�"));
	int _num = WideCharToMultiByte(CP_OEMCP, NULL, wide, -1, NULL, 0, NULL, FALSE);
	char* pchar = new char[_num];
	WideCharToMultiByte(CP_OEMCP, NULL, wide, -1, pchar, _num, NULL, FALSE);
	return pchar;
}

void Ranking_interface()
{
	initgraph(1000, 620);
	loadimage(NULL, _T("TUST.png"));
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	settextstyle(48, 0, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	setbkmode(TRANSPARENT);                //�������屳��Ϊ͸��
	settextcolor(BLACK);                   //����������ɫ
	outtextxy(200, 100, _T("��ѡ�����������ʽ"));
	settextcolor(WHITE);
	settextstyle(32, 0, _T("����"));
	outtextxy(650, 160, _T("1.ƽ���ֽ���"));
	outtextxy(650, 200, _T("2.��ѧ�ɼ�����"));
	outtextxy(650, 240, _T("3.Ӣ��ɼ�����"));
	outtextxy(650, 280, _T("4.�����ɼ�����"));
	outtextxy(650, 320, _T("5.ƽ��������"));
	outtextxy(650, 360, _T("6.��ѧ�ɼ�����"));
	outtextxy(650, 400, _T("7.Ӣ��ɼ�����"));
	outtextxy(650, 440, _T("8.�����ɼ�����"));
}

void Find_interface()
{
	initgraph(1000, 620);
	loadimage(NULL, _T("Lab.png"));
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	settextstyle(48, 0, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	setbkmode(TRANSPARENT);                //�������屳��Ϊ͸��
	settextcolor(BLACK);                   //����������ɫ
	outtextxy(200, 100, _T("��ѡ����Ĳ��ҷ�ʽ"));
	settextcolor(WHITE);
	settextstyle(32, 0, _T("����"));
	outtextxy(650, 160, _T("1.ͨ��ѧ�Ų�ѯ"));
	outtextxy(650, 200, _T("2.ͨ�����ֲ�ѯ"));
	outtextxy(650, 240, _T("3.ͨ���༶��ѯ"));
	outtextxy(650, 280, _T("7.����������"));
}