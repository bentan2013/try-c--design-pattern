// ������Ҫд���ģʽ�ģ��ִ�д����Ű�
// ��дһ����ά�е���ͨ�����Ͳü�
// ��������һ��������֯
// �����ӽڵ㣬ÿ�����ڵ�Ҳ��ģ�ͽڵ�

// ���дд�ģ�û�����У�Ҳû�вο������в�������ָ��

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;

struct Point3d
{
	double x;
	double y;
	double z;
};

class SpatialObject
{
public:
	SpatialObject(){ ; }
	virtual ~SpatialObject()
	{
		;
	}
	virtual void Cull() = 0;
protected:
	virtual bool IsInFrustum(){ return true; }
	Point3d m_Center;
	double	m_dRadius;
};

class SpatialMode : public SpatialObject
{
public:
	~SpatialMode()
	{
		;
	}
	void Draw(){ ; }
	void Cull()
	{
		if (IsInFrustum())
		{
			Draw();
		}
	}
};

class SpatialNode : public SpatialObject
{
public:
	~SpatialNode()
	{
		// ɾ���ڵ��е�ģ��
		vector<SpatialMode*>::iterator modeIter = m_SubMode.begin();
		for (; modeIter != m_SubMode.end(); ++modeIter)
		{
			SpatialMode *pMode = static_cast<SpatialMode*>(*modeIter);
			if (pMode)
			{
				delete pMode;
				pMode = NULL;
			}
		}
		m_SubMode.clear();

		// ɾ���ӽڵ�
		vector<SpatialNode*>::iterator nodeIter = m_SubNode.begin();
		for (; nodeIter != m_SubNode.end(); ++nodeIter)
		{
			SpatialNode* pNode = static_cast<SpatialNode*>(*nodeIter);
			if (pNode)
			{
				delete pNode;
				pNode = NULL;
			}
		}
		m_SubNode.clear();
	}
	void Cull()
	{
		vector<SpatialMode*>::iterator modeIter = m_SubMode.begin();
		for (; modeIter != m_SubMode.end(); ++modeIter)
		{
			SpatialMode *pMode = static_cast<SpatialMode*>(*modeIter);
			pMode->Cull();
		}
		vector<SpatialNode*>::iterator nodeIter = m_SubNode.begin();
		for (; nodeIter != m_SubNode.end(); ++nodeIter)
		{
			SpatialNode* pNode = static_cast<SpatialNode*>(*nodeIter);
			pNode->Cull();
		}
	}
	void AddSubNode(SpatialNode*){ ; }
	void AddSubMode(SpatialMode*){ ; }
	void RemoveSubNode(SpatialNode*){ ; }
	void RemoveSubMode(SpatialMode*){ ; }
protected:
	vector<SpatialNode*>		m_SubNode;
	vector<SpatialMode*>		m_SubMode;
};

void ReadFile(IN const wstring& wstrFile, OUT SpatialMode* &pMode)
{
	// ���ļ��й���ģ��
	;
}
void BuildTree(IN const vector<SpatialMode*>&, OUT SpatialNode* pRootNode)
{
	// ����ģ�ͼ��Ϲ�����
	// �м��new SpatialNode
	;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int k = 2;
	vector<SpatialMode*> modeVec;
	for (int i = 0; i < k; i++)
	{
		SpatialMode *pMode = new SpatialMode;
		ReadFile(L"filePath i", pMode);
		modeVec.push_back(pMode);
	}
	SpatialObject* pRootNode = new SpatialNode();
	BuildTree(modeVec, dynamic_cast<SpatialNode*>(pRootNode));

	// ������Ⱦһǧ֡��
	int frame = 0;
	while (frame == 1000)
	{
		pRootNode->Cull();
		frame++;
	}

	// ����
	// �������������������������
	if (pRootNode)
	{
		delete pRootNode;
		pRootNode = NULL;
	}
	return 0;
}
