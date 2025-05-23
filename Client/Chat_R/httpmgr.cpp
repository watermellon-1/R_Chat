#include "httpmgr.h"
HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr()
{
    //连接http请求和完成信号，信号槽机制保证队列消费
    connect(this, &HttpMgr::sig_http_finish, this, &HttpMgr::slot_http_finish);
}

void HttpMgr::PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod)
{
    QByteArray data = QJsonDocument(json).toJson();
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(data.length()));
    auto self = shared_from_this();
    QNetworkReply * reply = _manager.post(request, data);
    QObject::connect(reply, &QNetworkReply::finished, [self, reply, req_id, mod](){
         //处理错误情况
        if(reply->error() != QNetworkReply::NoError){
             qDebug() << reply->errorString();
            //发送信号通知完成
             emit self->sig_http_finish(req_id,"", ErrorCodes::ERR_NETWORK,mod);
             reply->deleteLater();
             return;
        }
        //无错误
        QString res = reply->readAll();
        //通知其它界面，发送完成信号
        emit self->sig_http_finish(req_id, res, ErrorCodes::SUCCESS, mod);
        reply->deleteLater();
        return;
    });

}

void HttpMgr::slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod)
{
    if(mod == Modules::REGISTERMOD){
        //发送信号通知指定模块的http响应结束了
        emit sig_reg_mod_finish(id, res, err);
    }
    if(mod == Modules::RESETMOD){
        //发送信号通知指定模块的http响应结束了
        emit sig_reset_mod_finish(id, res, err);
    }
    if(mod == Modules::LOGINMOD){
        //发送信号通知指定模块的http响应结束了
        emit sig_login_mod_finish(id, res, err);
    }
}
