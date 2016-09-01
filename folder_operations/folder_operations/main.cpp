//使用多字节字符集
//关于文件夹操作 应该可以全部用 shfileoperation 来解决
//FO_COPY FO_DELETE FO_MOVE FO_RENAME

#ifdef WIN32
	#include <windows.h>
	#include <shellapi.h>  //
#endif

#include <string>

bool CreateDirectoryFunc(std::string dir)
{
#ifdef WIN32
	return CreateDirectory(dir.c_str(), NULL);
#endif
}

bool DeleteDirectoryFunc(std::string dir)
{
#ifdef WIN32
	return RemoveDirectory(dir.c_str());
#endif
}

bool CopyDirectoryFunc(std::string destDir, std::string srcDir)
//bool CopyDirectoryFunc(std::string srcDir, std::string destDir) //not working?
{
#ifdef WIN32
	//return RemoveDirectory(dir.c_str());
	SHFILEOPSTRUCT fop;
	ZeroMemory(&fop, sizeof fop);
	fop.wFunc = FO_COPY; //FO_COPY FO_DELETE FO_MOVE FO_RENAME
	fop.pFrom = srcDir.c_str();// "c:\\a\0";
	fop.pTo = destDir.c_str();// "c:\\b\0";

	bool succes = !SHFileOperation(&fop);
	return succes;
#endif
}

int main()
{
	CreateDirectoryFunc("C:\\test");
	DeleteDirectoryFunc("C:\\test");
	CreateDirectoryFunc("C:\\test1");
	CreateDirectoryFunc("C:\\test2");
	CopyDirectoryFunc("c:\\test1", "c:\\test2");
	return 0;
}