#include "CServer.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"
CServer::CServer(boost::asio::io_context& ioc, short port) 
	:_ioc(ioc),_acceptor(ioc, tcp::endpoint(tcp::v4(), port)) {

}
void CServer::Start() {
	auto self = shared_from_this();
	auto& io_context = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<HttpConnection> new_con = std::make_shared<HttpConnection>(io_context);
	_acceptor.async_accept(new_con->GetSocket(), [self, new_con](beast::error_code ec) {
		try {
			//出错放弃链接，继续监听其他链接
			if (ec) {
				self->Start();
				return;
			}
			//创建新链接，并且创建HttpConnection类管理该链接
			new_con->Start();
			//继续监听
			self->Start();
		}
		catch (std::exception& exp) {
			std::cout << "exception is" << exp.what() << std::endl;
			self->Start();
		}
		});
}
