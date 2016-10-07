// ���󹤳�ģʽ��Abstract Factory�����ṩһ������
// һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ������

// �龰����
// ����һ��������ձ���Ĺ����ļ��������汾
// Ҫ���ܹ������������汾������
// Ҫ���ܹ��޸��������汾������

// �ŵ�����ֻ��Ҫ�޸ľ���Ĺ�������ʵϰ��ͬ����Ĳ���
// ���ҿͻ�Ҳ����֪���汾����ľ������ƣ�ֻ��Ҫ������ȷ��
// ���������ɼ��ɣ����÷��㡣
// ��Ȼ�����˾��ù�����Ҳ����ʵ���������ݣ�����Switch Case

#include "stdafx.h"

// ����������
class BaseParse
{
public:
	virtual void Show() = 0;
protected:
private:
};

// �汾һ������
class VesionOneParse : BaseParse
{
public:
	void Show()
	{
		printf("Now, Use VesionOneParse.\n");
	}
protected:
private:
};

// �汾��������
class VesionTwoParse : BaseParse
{
public:
	void Show()
	{
		printf("Now, Use VesionTwoParse.\n");
	}
protected:
private:
};

// ����İ汾������
class AbstractVesionFactory
{
public:
	virtual BaseParse* CreateParse() = 0;
protected:
private:
};

// ��Ӧ�汾һ�Ĺ����ļ��Ĵ�����
class VesionOneFactory : public AbstractVesionFactory
{
public:
	BaseParse * CreateParse()
	{
		return (BaseParse*)new VesionOneParse;
	}
protected:
private:
};

// ��Ӧ�汾���Ĺ����ļ��Ĵ�����
class VesionTwoFactory : public AbstractVesionFactory
{
public:
	BaseParse * CreateParse()
	{
		return (BaseParse*)new VesionTwoParse;
	}
protected:
private:
};






int _tmain(int argc, _TCHAR* argv[])
{
	AbstractVesionFactory *pFactory
		= new VesionOneFactory;
	// �Ժ�Ҫ��Ϊ�汾���Ľ������Ļ������޸�Ϊ = new VesionTwoFactory;
	// ֻ��Ҫ�޸�һ���ط�����
	// �Ժ�Ҫ����һ����Ӧ�汾���޸���VesionModify�Ļ�
	// ���ڸ�������д��Ӧ��CreateModify
	// ��Ȼ����������ü򵥹���ʵ��
	BaseParse *pParse = pFactory->CreateParse();
	pParse->Show();

	if (pFactory)
	{
		delete pFactory;
		pFactory = NULL;
	}
	if (pParse)
	{
		delete pParse;
		pParse = NULL;
	}
	return 0;
}