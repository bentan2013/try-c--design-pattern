// ģ�巽��ģʽ�� ����һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������С�
// ģ�巽��ʹ��������Բ��ı�һ���㷨�Ľṹ�ȿɳ嶨����㷨��ĳЩ�ض����衣


// ��1���ͷ��ͱ������
// ��2���о��ò���ģʽҲ���԰���

// ��1�����ͱ�̸ı�����������ͣ�ģ�巽��һ���ı�����Զ����ʵ��ϸ�ڡ�
// ��2��ģ�巽��ģʽ����һ�㣬Ϊ�㷨��ʵ��ϸ�ڣ�������ģʽ����Լ����㷨��

#include "stdafx.h"


// ����ģ��
template<typename T>
int Compare(const T &v1, const T &v2)
{
	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 > v2)
	{
		return 1;
	}
	else
		return 0;
}


// ��ģ��
template<class Type>
class CCompare
{
public:
	CCompare(const Type & v1, const Type & v2)
	{
		m_tFirst = v1;
		m_tSecond = v2;
	}
	~CCompare(){ ; }

	//template<class Type>
	int Compare()
	{
		if (m_tFirst < m_tSecond)
		{
			return -1;
		}
		else if (m_tFirst > m_tSecond)
		{
			return 1;
		}
		else
			return 0;
	}
private:
	Type  m_tFirst;
	Type  m_tSecond;
};

//ģ�巽��
class Bill
{
public:
	virtual void AddCondition() = 0;
	void Pay()
	{
		AddCondition();
		printf("You need pay $100!\n");
	}
protected:
private:
};

class MaleBill : public Bill
{
public:
	void AddCondition()
	{
		printf("Sir!\n");
	}
protected:
private:
};

class FemaleBill : public Bill
{
public:
	void AddCondition()
	{
		printf("Lady!\n");
	}
protected:
private:
};



// ���Ժ���
void TestTemplateFunc()
{
	int result;
	result = Compare(2.3, 3.1);
	result = Compare(1, 2);
}

void TestTemplateClass()
{
	int result;
	CCompare<double> cp(2.3, 3.1);
	result = cp.Compare();

	CCompare<int> cp1(1, 2);
	result = cp1.Compare();
}

void TestTemplateMethod()
{
	Bill *pMale = new MaleBill;
	pMale->Pay();
	Bill *pFemale = new FemaleBill;
	pFemale->Pay();

	if (pMale)
	{
		delete pMale;
		pMale = NULL;
	}
	if (pFemale)
	{
		delete pFemale;
		pFemale = NULL;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	//����ģ�庯��
	TestTemplateFunc();
	//����ģ����
	TestTemplateClass();
	//����ģ�巽��
	TestTemplateMethod();

	return 0;
}