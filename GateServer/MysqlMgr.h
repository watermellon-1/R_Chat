#pragma once
#include "const.h"
#include "MysqlDao.h"


class MysqlMgr : public Singleton<MysqlMgr>
{
	friend class Singleton<MysqlMgr>;
public:
	~MysqlMgr();

	int RegUser(const std::string& name, const std::string& email, const std::string& pwd);
	bool CheckEmail(const std::string& name, const std::string& email);
	bool UpdatePwd(const std::string& name, const std::string& email);
	bool CheckPwd(const std::string& email, const std::string& pwd, UserInfo& userInfo);
	std::string GetNamefromEmail(const std::string email);
	std::string GetEmailfromName(const std::string name);
	//bool TestProcedure(const std::string& email, int& uid, string& name);
private:
	MysqlMgr();
	MysqlDao  _dao;
};


