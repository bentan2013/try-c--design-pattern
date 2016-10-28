#include <cassert>  


// һ������ģʽ��ģ����  
template<typename T>
class SingleTon
{
public:
  static T* ms_SingleTon;

  SingleTon()
  {
    assert(!ms_SingleTon);
    int offset = (int)(T*)1 -
      (int)(SingleTon<T>*)(T*)1;
    ms_SingleTon = (T*)((int)this + offset);
  }
  ~SingleTon()
  {
    assert(ms_SingleTon);
    ms_SingleTon = 0;
  }

  static T& GetSingleTon()
  {
    assert(ms_SingleTon);
    return *ms_SingleTon;
  }

  static T* GetSingleTonPtr()
  {
    return ms_SingleTon;
  }
};

// ��ʼ��  
template<typename T> T* SingleTon<T>::ms_SingleTon = 0;


// ���������ĵ�����  
class Texture
{
public:
  char* m_name;
};

class TextureMgr : public SingleTon<TextureMgr>
{
public:
  Texture *GetTexture(const char *pName)
  {
    // for_each( i in texture_array)
    // find the one
    return NULL;
  }
protected:
private:
};

#define g_TextureMgr TextureMgr::GetSingleTon()  
