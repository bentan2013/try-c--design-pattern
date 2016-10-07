// AdapterMode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// ������ģʽ��Adapter������һ����Ľ��ת���ɿͻ���ϣ��
// ������һ����ڣ�������ģʽʹ��ԭ�����ڽ�ڲ����ݶ�����
// һ��������Щ�����һ����


// ˵���ˣ����Ǹ���

// �龰���裺һ��������������������ֺ����ֱַ�д
// ���ֵ������п�����Щ����

class MathAdd
{
public:
	virtual int Add(int a, int b) = 0;
protected:
private:
};

// ������ôд
class MathAdd_Veteran : public MathAdd
{
public:
	int Add(int a, int b)
	{
		return a + b;
	}
};

// ������ôд
class MathAdd_Novice
{
public:
	int jiafa(int a, int b)
	{
		return a + b;
	}
protected:
private:
};

// �ðɣ�Ϊ��������������У�ʹ�������ֵĴ���
// ����Ҫ��ô���ˡ���

class MathAdd_Helper : public MathAdd
{
public:
	int Add(int a, int b)
	{
		return m_Mn.jiafa(a, b);
	}
private:
	MathAdd_Novice m_Mn;
};

// �涨����ʹ�õĺ����ӿ�
int Add(MathAdd* pMa, int a, int b)
{
	return pMa->Add(a, b);
}

int _tmain(int argc, _TCHAR* argv[])
{
	MathAdd *pMv = (MathAdd*) new MathAdd_Veteran;
	int r = Add(pMv, 100, -20);

	// �ðɣ�Ψһ���ź��ǣ����ֵ�����û���ڿͻ���չʾ
	// ����ʵ���ϵ��õ���������Ŷ
	// ˭���㲻���ӿڱ�̵ģ�
	MathAdd *pMh = (MathAdd*) new MathAdd_Helper;
	r = Add(pMh, 1, 2);
	return 0;
}
