# RPC Interface between Web UI and Working server

namespace cpp TrustedBridge
namespace java TrustedBridge
namespace php TrustedBridge

enum TBStatus {
    OK = 1,
    EFILENOTFOUND = 2, // Try to remove a non-exist file
    EFILEEXISTS = 3,   // Duplicate file name
    INTERNAL_FAILURE = 4,
    NOT_IMPLEMENTED = 5
}

struct GetListResponse {
    1: TBStatus status,
    2: list<string> values
}

struct DownloadResponse {
    1: TBStatus status,
    2: string filename
    3: binary file
}

service TrustedBridge {
    
    TBStatus AddUser(1:string username),
    GetListResponse GetFileList(1:string username),
    #DownloadResponse Download(1:string filename),
    #TBStatus Upload(1:string username, 2:string filename, 3:binary file),
    TBStatus Remove(1:string username, 2:string filename), 

    #Download the segments from external cloud storage
    DownloadResponse DownloadFromExt (1:string username, 2:string filename), 
    #Download the file that has been resembled with the corresponding segments from server
    DownloadResponse DownloadFromServer (1:string username, 2:string filename) 

    #Upload the segment to the external cloud storage
    TBStatus UploadToExt(1:string username, 2:string filename, 3:binary file),
    #Upload the file to our server
    TBStatus UploadToServer(1:string username, 2:string filename, 3:binary file)
       
}
