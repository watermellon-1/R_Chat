#include "VerifyGrpcClient.h"
#include "ConfigMgr.h"
VerifyGrpcClient::VerifyGrpcClient() {
	auto& gCfMgr = ConfigMgr::Inst();
	std::string host = gCfMgr["VarifyServer"]["Host"];
	std::string port = gCfMgr["VarifyServer"]["Port"];
	pool_.reset(new RPConPool(5, host, port));
	
}
