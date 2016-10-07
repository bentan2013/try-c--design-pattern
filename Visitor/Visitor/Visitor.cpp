// Visitor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"



// ������ģʽ(vistor), ��ʾһ��������ĳ����ṹ�еĸ�Ԫ�صĲ�����
// ��ʹ������ڲ��ı��Ԫ�����ǰ���¶�����������ЩԪ�صĲ���

// ����һ�����������ֻ�ܹ����������������͵�ͼ��
// ����ÿ��ͼ�ζ��ж��ַ����������������άģʽ���ȵȵȵȣ�



// ���Ʒ�ʽ

// ���Ʒ�ʽ������񣩿���������ӣ���DrawAction����������
// ÿ���������ж������ضԡ��ߡ��͡��桿�Ļ���
// ���ص��ǣ����Ʒ��ͨ��ָ�봫�ݸ����ƶ����࣬���ƶ����������Լ���ָ��
// ���û��Ʒ����������ƶ�������һ�֣�Ȼ���ɻ��Ʒ����������ʵ�ֻ��Ʒ�ʽ


class DrawAction
{
public:
	virtual void DrawLine() = 0;
	virtual void DrawPolygon() = 0;
};

class DrawWithTexture : public DrawAction
{
public:
	void DrawLine()			{ printf("�������������\n"); }
	void DrawPolygon()		{ printf("����������Ķ����\n"); }
};

class DrawWithOutTexture : public DrawAction
{
public:
	void DrawLine()			{ printf("�������������\n"); }
	void DrawPolygon()		{ printf("����������Ķ����\n"); }

};

class DrawIn3DModel : public DrawAction
{
public:
	void DrawLine()			{ printf("����3Dģʽ�µ���\n"); }
	void DrawPolygon()		{ printf("����3Dģʽ�µĶ����\n"); }
};


class Element
{
public:
	virtual void Draw(DrawAction *visitor) = 0;
};


class Line : public Element
{
public:
	void Draw(DrawAction *visitor)
	{
		visitor->DrawLine();
	}
};


class Polygon : public Element
{
public:
	void Draw(DrawAction *visitor)
	{
		visitor->DrawPolygon();
	}
};



// һ��������ǣ������ƶ����װ��������Element��ֻ��һ��Draw���麯�����Լ�һ��SetDrawStyle(...)
// ������ͨ��SetStyle��������ý�����Ȼ�����������Draw��������switch case����
// ��ps.�������ڵ�ϵͳ��������д�ģ����ðɣ��Ƚ�ֱ�ۣ����ܱ�����Ʒ���أ�

// ����vistor����һ��˫ѡ��ģʽ
// ���Ƶ�ʱ����Ҫ֪�����ƶ�������࣬�ͻ��Ʒ�������
// �������ƶ���Ĳ���״̬��ö�٣�����һ����ָ��
// ��Ϊ���ݵ�����ָ�룬���Կɽ��ж�̬�󶨣�ͨ�������ָ�������û��ƺ���

int _tmain(int argc, _TCHAR* argv[])
{
	Element *pLine = new Line;
	Element *pPoly = new Polygon;

	DrawAction *pHTex = new DrawWithTexture;
	DrawAction *p3DM = new DrawIn3DModel;


	// ��������  ��
	pLine->Draw(pHTex);
	pPoly->Draw(p3DM);

	return 0;
}
