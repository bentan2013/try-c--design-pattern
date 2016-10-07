// ������ģʽ��Builder������һ�����Ӷ���Ĺ��������ı�ʾ���룬
// ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ


// ��ž��ǰ�һ������ṹ�ļ������ܱ仯�Ĳ��ֲ�Ϊ�����ĺ���
// Ȼ��������������ʵ�ֵķ�ʽ

// ��ҪӦ���������б仯�Ĳ�����
// ����������״̬��Ҫ��Ȼ������״̬ģʽ��
// ����������̿�����ְ����ģʽ

// ���״̬���ã���͵����ֱ���á������ģʽ��Java���룬����ΪC++��


// �龰��������
// ������� ͷ �� �� ����
// ���������� ���Ӻ�����
// ���ݵ�������Ҫ���ڶ��Ӳ�ͬ��

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;


class PersonBuilder
{
public:
	PersonBuilder(const string & strGrap, const string & strPen)
	{
		m_strGraphics = strGrap;
		m_strPen = strPen;
	}
	virtual ~PersonBuilder()
	{

	}
	virtual void BuildHead() = 0;
	virtual void BuildBody() = 0;
	virtual void BuildLeg() = 0;

protected:
	string	m_strGraphics;
	string  m_strPen;

private:
};

class PersonThinBuilder : public PersonBuilder
{
public:
	PersonThinBuilder(const string & strGrap, const string & strPen)
		: PersonBuilder(strGrap, strPen)
	{

	}
	void BuildHead()
	{
		cout << "With " << m_strPen.c_str() << endl;
		printf("Draw normal head\n");
		cout << "On" << m_strGraphics.c_str() << endl;

	}
	void BuildBody()
	{
		cout << "With " << m_strPen.c_str() << endl;
		printf("Draw thin body\n");
		cout << "On" << m_strGraphics.c_str() << endl;

	}
	void BuildLeg()
	{
		cout << "With " << m_strPen.c_str() << endl;
		printf("Draw normal leg\n");
		cout << "On" << m_strGraphics.c_str() << endl;

	}

protected:
private:
};


class PersonFatBuilder : public PersonBuilder
{
public:
	PersonFatBuilder(const string & strGrap, const string & strPen)
		: PersonBuilder(strGrap, strPen)
	{

	}
	void BuildHead()
	{
		cout << "With " << m_strPen.c_str() << endl;
		printf("Draw normal head\n");
		cout << "On" << m_strGraphics.c_str() << endl;
	}
	void BuildBody()
	{
		cout << "With " << m_strPen.c_str() << endl;
		printf("Draw Fat body\n");
		cout << "On" << m_strGraphics.c_str() << endl;
	}
	void BuildLeg()
	{
		cout << "With " << m_strPen.c_str() << endl;
		printf("Draw normal leg\n");
		cout << "On" << m_strGraphics.c_str() << endl;
	}

protected:
private:
};


class PersonDirector
{
public:

	void SetPersonBuilder(PersonBuilder * pb)
	{
		m_pPbuilder = pb;
	}

	void CreatePerson()
	{
		m_pPbuilder->BuildHead();
		m_pPbuilder->BuildBody();
		m_pPbuilder->BuildLeg();
	}
protected:
private:
	PersonBuilder * m_pPbuilder;

};

int _tmain(int argc, _TCHAR* argv[])
{
	PersonBuilder *pThinBuilder = new PersonThinBuilder("Screen", "YellowPen");
	PersonBuilder *pFatBuilder = new PersonFatBuilder("Screen", "WhitePen");
	PersonDirector pd;
	pd.SetPersonBuilder(pThinBuilder);
	pd.CreatePerson();
	pd.SetPersonBuilder(pFatBuilder);
	pd.CreatePerson();

	if (pThinBuilder)
	{
		delete pThinBuilder;
		pThinBuilder = NULL;
	}
	if (pFatBuilder)
	{
		delete pFatBuilder;
		pFatBuilder = NULL;
	}
	return 0;
}


//������
//With YellowPen
//Draw normal head
//OnScreen
//With YellowPen
//Draw thin body
//OnScreen
//With YellowPen
//Draw normal leg
//OnScreen
//With WhitePen
//Draw normal head
//OnScreen
//With WhitePen
//Draw Fat body
//OnScreen
//With WhitePen
//Draw normal leg
//OnScreen
//�밴���������. . .