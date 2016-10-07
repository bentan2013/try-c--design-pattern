// Bridge.cpp : Defines the entry point for the console application.
//

// �龰����
// һ����Ⱦ���棬֧��D3D��OpenGL�� ��Ҫ�ṩһϵ�нӿڣ����ڻ��Ʋ�ͬ����
// �������������

// ��򵥵�ʵ���ǣ��ĸ�������2 * 2�����ǵ���һ�����壬��Ҫ�������������
// �ؼ����޸ĵĲ�λ�ȽϿ��ײ㡣

// ʹ���Ž�ģʽ�Ļ������֧����չ

#include "stdafx.h"


class ObjRenderInfo;

class Object
{
public:
	virtual ObjRenderInfo* GetObjInfor() = 0;
};

class Teapot : public Object
{
public:
	ObjRenderInfo* GetObjInfor(){ return NULL; }
};

class Cube : public Object
{
public:
	ObjRenderInfo* GetObjInfor(){ return NULL; }
};

class ObjRender
{
public:
	void SetObj(Object * obj)
	{
		m_object = obj;
	}
	virtual void Render() = 0;
protected:
	Object *m_object;
};

class D3DRender : public ObjRender
{
public:
	void Render()
	{
		if (m_object)
		{
			ObjRenderInfo *pInfo = m_object->GetObjInfor();
			// ʹ��D3d�ĺ���������屾�����Ⱦ��Ϣ���缸���壬���������Ⱦ
			D3dRenderFunction(pInfo);
		}
	}
private:
	void D3dRenderFunction(ObjRenderInfo *){ ; }
};

class OpenGLRender : public ObjRender
{
public:
	void Render()
	{
		if (m_object)
		{
			ObjRenderInfo *pInfo = m_object->GetObjInfor();
			// ʹ��OpenGL�ĺ���������屾�����Ⱦ��Ϣ���缸���壬���������Ⱦ
			OpenGLRenderFunction(pInfo);
		}
	}
private:
	void OpenGLRenderFunction(ObjRenderInfo *){ ; }
};


// ���Ҫ�ٻ��Ʋ豭�������һ���豭���OK�ˡ�
int _tmain(int argc, _TCHAR* argv[])
{
	ObjRender *pD3dRender = new D3DRender;
	Object *pObj = new Teapot;
	pD3dRender->SetObj(pObj);
	pD3dRender->Render();
	if (pD3dRender)
	{
		delete pD3dRender;
		pD3dRender = NULL;
	}
	if (pObj)
	{
		delete pObj;
		pObj = NULL;
	}
	return 0;
}
