// ���ģʽ��Facade����Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��棬��ģʽ
// ������һ���߳̽ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á�


// �龰����
// ĳһ���������ʱ��Ҫ�������ݿ⣬��ȡ�����ı�������Ϊtxt�ı�
// ���ݿ���Oracle�������ݿ���ȡ�����Ǽ��ܹ����ļ�
// ������ϵͳ��decryption������֮����һ��rar����Ҫ��ѹ
// ��ѹ��ϵͳ��rar
// ���ڴ���һ��facade�ڸǴ˹��̣������û���һ�����룬���ܵõ������


// ������ӱȽϼ򵥣���Ϊ���Ƿ�װ�½ӿڣ�����Ҫ�õ���̬֮���
// ����ÿ�����ֻ����һ�����󼴿�

// �����û�֪����ϸ��Խ��Խ�ã������ط���

#include "stdafx.h"
#include <Windows.h>

//���ݿ���ϵͳ
class OracleDB
{
public:
	bool GetDataFromDB(long id, byte* &pBuf)
	{
		printf("Connect to oracle now!\n");
		printf("Get data from Oracle now!\n");
		return true;
	}
protected:
private:
};

//������ϵͳ
class Decryption
{
public:
	bool Decrypt(byte* &pBuf)
	{
		byte *pDecryption = NULL;
		pBuf = pDecryption;
		printf("Sucessful Decrypt!\n");
		return true;
	}
protected:
private:
};

//��ѹ����ϵͳ
class RARSys
{
public:
	bool UnCompress(byte* &pBuf, char* pPath)
	{
		byte* pUncompress = NULL;
		pBuf = pUncompress;
		printf("Sucessful Uncompress!\n");
		if (WriteData(pPath))
		{
			return true;
		}

	}
protected:
private:
	bool WriteData(char* pPath)
	{
		printf("Txt is put in this path:\n");
		printf(pPath);
		printf("\n");
		return true;
	}
};


//�����
class Facade
{
public:
	bool GetTxt(long id, char *pPath)
	{
		OracleDB	db;
		Decryption	dp;
		RARSys		rs;
		byte *pBuf;
		db.GetDataFromDB(id, pBuf);
		dp.Decrypt(pBuf);
		rs.UnCompress(pBuf, pPath);
		return true;
	}
protected:
private:
};


int _tmain(int argc, _TCHAR* argv[])
{
	Facade fd;
	fd.GetTxt(100, "D:\\temp.txt");
	return 0;
}


//��������
//Connect to oracle now!
//Get data from Oracle now!
//Sucessful Decrypt!
//Sucessful Uncompress!
//Txt is put in this path:
//D:\temp.txt
//�밴���������. . .