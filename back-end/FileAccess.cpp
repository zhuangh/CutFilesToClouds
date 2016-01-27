#include "FileAccess.h"

#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp> 


using namespace std;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using boost::property_tree::ptree;
using boost::property_tree::read_json;


#define DEBUG

//Constructor
FileAccess::FileAccess(const string& storageServer, int storageServerPort){

	_storageServer  = storageServer;
	_storageServerPort = storageServerPort;

	KVStoreInit();

}

void FileAccess::KVStoreInit(){

    std::ifstream t("default.json");
	std::string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
	            std::istreambuf_iterator<char>());

	Put("test_clouds",str);
	t.close();

}

// Upload <filename> to cloud <cloud> with the account <username>
bool FileAccess::Upload(string username, string filename, int cloudId){
	
	AccessToken access = GetUserToken(username, cloudId);
	if (!access.success){
		cout << "[FA] GetUserToken failed" << endl;
		return false;
	}

#ifdef DEBUG
	cout<<"[FA] Uploading " << filename << " by user: " << username << " to " << cloudId << endl; 
#endif
	ostringstream stringStream;
  	stringStream << "./run upload " << filename << " "
  				 << access.token1 << " " << access.token2;

  	string command = stringStream.str();
	
	cout << command << endl;
	string result = Exec(command.c_str());
	//cout << "result: " << endl << result; 
	enum Response response;
	try {
		response = (Response) lexical_cast<int>(result);
	}
	catch(bad_lexical_cast &){
		cout << "[FA] Could not parse response from Dropbox" << endl;
		return false;
	}
	
	switch(response){
		case OK:
			cout << "[FA] Upload success!" << endl;
			return true;
			break;
		case IO_FAILURE:
			cout << "[FA] Read file failed" << endl;
			return true;
		case DROPBOX_FAILURE:
		default:
			cout << "[FA] Unexpected response from Dropbox" << endl;
			return false;
			break;
	}

	return false;
}

// Download <filename> from cloud <cloud> with the account <username>
bool FileAccess::Download(string username, string filename, int cloudId){
	AccessToken access = GetUserToken(username, cloudId);
	if (!access.success){
		cout << "[FA] GetUserToken failed" << endl;
		return false;
	}

	ostringstream stringStream;
  	stringStream << "./run download " << filename << " "
  				 << access.token1 << " " << access.token2;

  	string command = stringStream.str();
	
	cout << command << endl;
	//string result = "ddd";
	string result = Exec(command.c_str());
	//cout << "result: " << endl << result; 
	
	enum Response response;
	try {
		response = (Response) lexical_cast<int>(result);
	}
	catch(bad_lexical_cast &){
		cout << "[FA] Could not parse response from Dropbox" << endl;
		return false;
	}
	
	switch(response){
		case OK:
			cout << "[FA] Download success!" << endl;
			return true;
			break;
		case IO_FAILURE:
			cout << "[FA] Write file failed" << endl;
			return true;
			break;
		case FILE_NOTEXIST:
			cout << "[FA] File not exists!" << endl;
			return true;
			break;
		case DROPBOX_FAILURE:
		default:
			cout << "[FA] Unexpected response from Dropbox" << endl;
			return false;
			break;
	}

	return false;
}

bool FileAccess::IsFileAlive(string username, string filename, int cloudId){
	
	AccessToken access = GetUserToken(username, cloudId);
	if (!access.success){
		cout << "[FA] GetUserToken failed" << endl;
		return false;
	}

	ostringstream stringStream;
  	stringStream << "./run status " << filename << " "
  				 << access.token1 << " " << access.token2;

  	string command = stringStream.str();
	
	cout << command << endl;
	//string result = "ddd";
	string result = Exec(command.c_str());

		enum Response response;
	try {
		response = (Response) lexical_cast<int>(result);
	}
	catch(bad_lexical_cast &){
		cout << "[FA] Could not parse response from Dropbox" << endl;
		return false;
	}

	switch(response){
		case OK:
			cout << "[FA] File exists!" << endl;
			return true;
			break;
		case FILE_NOTEXIST:
			cout << "[FA] File not exists!" << endl;
			return false;
			break;
		case IO_FAILURE:
		case DROPBOX_FAILURE:
		default:
			cout << "[FA] Unexpected response from Dropbox" << endl;
			return false;
			break;
	}

	return false;

}

// Get user token from KV_server
FileAccess::AccessToken FileAccess::GetUserToken(const string& username, int cloudId){
	AccessToken access;

	KeyValueStore::GetResponse rp = Get(username+"_clouds");

	switch(rp.status){
		case KVStoreStatus::OK:
			access.success = true;
			break;
		default:
			access.success = false;
			return access;
			break;
	}

	try{
		stringstream ss;
		ss << rp.value;
        ptree pt;
        read_json(ss, pt);
 
        //cout << pt.get_child("clouds").size() << endl;

        BOOST_FOREACH(ptree::value_type &v, pt.get_child("clouds"))
        {
            assert(v.first.empty()); // array elements have no names
            string id = v.second.get_child("id").data();
            if (lexical_cast<int>(id) == cloudId){
            	string token1 = v.second.get_child("token1").data();
            	string token2 = v.second.get_child("token2").data();
            	access.token1 = token1;
            	access.token2 = token2;
            }
        }
      
    }
    catch (exception const& e)
    {
        std::cerr << e.what() << endl;
        access.success = false;
		return access;
    }

	return access;
}

string FileAccess::Exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[256];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 256, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}
