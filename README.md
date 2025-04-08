## R_Chat
###Discription
####A chat software based on distributed system 
The front-end implements the chat interface based on Qt, and uses the network module in QT to encapsulate the HTTP and TCP services. It supports functions such as adding friends, chatting with friends, and displaying chat records.

The back-end adopts a distributed design, which is divided into a gateway service, multiple chat services, a status service, and a verification service. The services communicate with each other through gRPC and support disconnection reconnection.

The gateway uses an HTTP service externally and is responsible for handling user login and registration functions. The chat service uses asio to implement reliable TCP long connection asynchronous communication and forwarding, and encapsulates an iocontext pool in a multi-threaded mode to improve concurrent performance.

For data storage, an MySQL service is used, and a connection pool is encapsulated based on the mysqlconnector library. At the same time, a Redis connection pool is encapsulated to handle cached data, and a gRPC connection pool is used to ensure concurrent access to multiple services. 

**asio-1.30.2**
**jsoncpp-0.5.0**
**grpc-**
**protobuf-**
**mysql-connector**
**redis-3.0**
**boost_1_86**
