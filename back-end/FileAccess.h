
#include <iostream>     // std::cout
#include <fstream>
#include <streambuf>
#include <string>
#include <utility>      // std::pair

#include <transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "KeyValueStore.h"

using namespace std;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using boost::shared_ptr;

using namespace KeyValueStore;

class FileAccess{
	
public:
	enum CloudType { DROPBOX = 0, 
					 GOOGLE_DRIVE };

	enum Response { OK = 0, 
					IO_FAILURE, 
					DROPBOX_FAILURE,
					FILE_NOTEXIST };

	typedef struct {
		bool success;
		enum CloudType cloud;
		string token1;
		string token2;
	} AccessToken;

	FileAccess(const string& storageServer, int storageServerPort);

	void KVStoreInit();

	// Upload <filename> to cloud <cloud> with the account <username>
	bool Upload(string username, string filename, int cloudId);

	// Download <filename> from cloud <cloud> with the account <username>
	bool Download(string username, string filename, int cloudId);

	// IsFileAlive <filename> from cloud <cloud> with the account <username>
	bool IsFileAlive(string username, string filename, int cloudId); 

private:

	AccessToken GetUserToken(const string& username, int cloudId);

	string Exec(const char* cmd);

	string _storageServer;
	int _storageServerPort;

	KeyValueStore::GetResponse Get(std::string key){
		KeyValueStore::GetResponse response;
		boost::shared_ptr<TSocket> socket(new TSocket(_storageServer, _storageServerPort));
		boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
		boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
		KeyValueStoreClient kv_client(protocol);
		transport->open();
		kv_client.Get(response, key);
		transport->close();
		return response;  
	}

	KVStoreStatus::type Put(std::string key, std::string value){
		boost::shared_ptr<TSocket> socket(new TSocket(_storageServer, _storageServerPort));
		boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
		boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
		KeyValueStoreClient kv_client(protocol);
		KVStoreStatus::type st;
		transport->open();
		st = kv_client.Put(key, value, "client");
		transport->close();
		return st;  
	}
	
	KVStoreStatus::type AddToList(std::string key, std::string value){
		boost::shared_ptr<TSocket> socket(new TSocket(_storageServer, _storageServerPort));
		boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
		boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
		KeyValueStoreClient kv_client(protocol);
		KVStoreStatus::type st;
		transport->open();
		st = kv_client.AddToList(key, value, "client");
		transport->close();
		return st;  
	}
	
};
