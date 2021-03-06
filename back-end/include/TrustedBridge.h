/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TrustedBridge_H
#define TrustedBridge_H

#include <thrift/TDispatchProcessor.h>
#include "TrustedBridge_types.h"

namespace TrustedBridge {

class TrustedBridgeIf {
 public:
  virtual ~TrustedBridgeIf() {}
  virtual TBStatus::type AddUser(const std::string& username) = 0;
  virtual void GetFileList(GetListResponse& _return, const std::string& username) = 0;
  virtual TBStatus::type Remove(const std::string& username, const std::string& filename) = 0;
  virtual void DownloadFromExt(DownloadResponse& _return, const std::string& username, const std::string& filename) = 0;
  virtual void DownloadFromServer(DownloadResponse& _return, const std::string& username, const std::string& filename) = 0;
  virtual TBStatus::type UploadToExt(const std::string& username, const std::string& filename, const std::string& file) = 0;
  virtual TBStatus::type UploadToServer(const std::string& username, const std::string& filename, const std::string& file) = 0;
};

class TrustedBridgeIfFactory {
 public:
  typedef TrustedBridgeIf Handler;

  virtual ~TrustedBridgeIfFactory() {}

  virtual TrustedBridgeIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TrustedBridgeIf* /* handler */) = 0;
};

class TrustedBridgeIfSingletonFactory : virtual public TrustedBridgeIfFactory {
 public:
  TrustedBridgeIfSingletonFactory(const boost::shared_ptr<TrustedBridgeIf>& iface) : iface_(iface) {}
  virtual ~TrustedBridgeIfSingletonFactory() {}

  virtual TrustedBridgeIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TrustedBridgeIf* /* handler */) {}

 protected:
  boost::shared_ptr<TrustedBridgeIf> iface_;
};

class TrustedBridgeNull : virtual public TrustedBridgeIf {
 public:
  virtual ~TrustedBridgeNull() {}
  TBStatus::type AddUser(const std::string& /* username */) {
    TBStatus::type _return = (TBStatus::type)0;
    return _return;
  }
  void GetFileList(GetListResponse& /* _return */, const std::string& /* username */) {
    return;
  }
  TBStatus::type Remove(const std::string& /* username */, const std::string& /* filename */) {
    TBStatus::type _return = (TBStatus::type)0;
    return _return;
  }
  void DownloadFromExt(DownloadResponse& /* _return */, const std::string& /* username */, const std::string& /* filename */) {
    return;
  }
  void DownloadFromServer(DownloadResponse& /* _return */, const std::string& /* username */, const std::string& /* filename */) {
    return;
  }
  TBStatus::type UploadToExt(const std::string& /* username */, const std::string& /* filename */, const std::string& /* file */) {
    TBStatus::type _return = (TBStatus::type)0;
    return _return;
  }
  TBStatus::type UploadToServer(const std::string& /* username */, const std::string& /* filename */, const std::string& /* file */) {
    TBStatus::type _return = (TBStatus::type)0;
    return _return;
  }
};

typedef struct _TrustedBridge_AddUser_args__isset {
  _TrustedBridge_AddUser_args__isset() : username(false) {}
  bool username;
} _TrustedBridge_AddUser_args__isset;

class TrustedBridge_AddUser_args {
 public:

  TrustedBridge_AddUser_args() : username() {
  }

  virtual ~TrustedBridge_AddUser_args() throw() {}

  std::string username;

  _TrustedBridge_AddUser_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  bool operator == (const TrustedBridge_AddUser_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_AddUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_AddUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_AddUser_pargs {
 public:


  virtual ~TrustedBridge_AddUser_pargs() throw() {}

  const std::string* username;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_AddUser_result__isset {
  _TrustedBridge_AddUser_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_AddUser_result__isset;

class TrustedBridge_AddUser_result {
 public:

  TrustedBridge_AddUser_result() : success((TBStatus::type)0) {
  }

  virtual ~TrustedBridge_AddUser_result() throw() {}

  TBStatus::type success;

  _TrustedBridge_AddUser_result__isset __isset;

  void __set_success(const TBStatus::type val) {
    success = val;
  }

  bool operator == (const TrustedBridge_AddUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_AddUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_AddUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_AddUser_presult__isset {
  _TrustedBridge_AddUser_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_AddUser_presult__isset;

class TrustedBridge_AddUser_presult {
 public:


  virtual ~TrustedBridge_AddUser_presult() throw() {}

  TBStatus::type* success;

  _TrustedBridge_AddUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TrustedBridge_GetFileList_args__isset {
  _TrustedBridge_GetFileList_args__isset() : username(false) {}
  bool username;
} _TrustedBridge_GetFileList_args__isset;

class TrustedBridge_GetFileList_args {
 public:

  TrustedBridge_GetFileList_args() : username() {
  }

  virtual ~TrustedBridge_GetFileList_args() throw() {}

  std::string username;

  _TrustedBridge_GetFileList_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  bool operator == (const TrustedBridge_GetFileList_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_GetFileList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_GetFileList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_GetFileList_pargs {
 public:


  virtual ~TrustedBridge_GetFileList_pargs() throw() {}

  const std::string* username;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_GetFileList_result__isset {
  _TrustedBridge_GetFileList_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_GetFileList_result__isset;

class TrustedBridge_GetFileList_result {
 public:

  TrustedBridge_GetFileList_result() {
  }

  virtual ~TrustedBridge_GetFileList_result() throw() {}

  GetListResponse success;

  _TrustedBridge_GetFileList_result__isset __isset;

  void __set_success(const GetListResponse& val) {
    success = val;
  }

  bool operator == (const TrustedBridge_GetFileList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_GetFileList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_GetFileList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_GetFileList_presult__isset {
  _TrustedBridge_GetFileList_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_GetFileList_presult__isset;

class TrustedBridge_GetFileList_presult {
 public:


  virtual ~TrustedBridge_GetFileList_presult() throw() {}

  GetListResponse* success;

  _TrustedBridge_GetFileList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TrustedBridge_Remove_args__isset {
  _TrustedBridge_Remove_args__isset() : username(false), filename(false) {}
  bool username;
  bool filename;
} _TrustedBridge_Remove_args__isset;

class TrustedBridge_Remove_args {
 public:

  TrustedBridge_Remove_args() : username(), filename() {
  }

  virtual ~TrustedBridge_Remove_args() throw() {}

  std::string username;
  std::string filename;

  _TrustedBridge_Remove_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  void __set_filename(const std::string& val) {
    filename = val;
  }

  bool operator == (const TrustedBridge_Remove_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(filename == rhs.filename))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_Remove_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_Remove_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_Remove_pargs {
 public:


  virtual ~TrustedBridge_Remove_pargs() throw() {}

  const std::string* username;
  const std::string* filename;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_Remove_result__isset {
  _TrustedBridge_Remove_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_Remove_result__isset;

class TrustedBridge_Remove_result {
 public:

  TrustedBridge_Remove_result() : success((TBStatus::type)0) {
  }

  virtual ~TrustedBridge_Remove_result() throw() {}

  TBStatus::type success;

  _TrustedBridge_Remove_result__isset __isset;

  void __set_success(const TBStatus::type val) {
    success = val;
  }

  bool operator == (const TrustedBridge_Remove_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_Remove_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_Remove_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_Remove_presult__isset {
  _TrustedBridge_Remove_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_Remove_presult__isset;

class TrustedBridge_Remove_presult {
 public:


  virtual ~TrustedBridge_Remove_presult() throw() {}

  TBStatus::type* success;

  _TrustedBridge_Remove_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TrustedBridge_DownloadFromExt_args__isset {
  _TrustedBridge_DownloadFromExt_args__isset() : username(false), filename(false) {}
  bool username;
  bool filename;
} _TrustedBridge_DownloadFromExt_args__isset;

class TrustedBridge_DownloadFromExt_args {
 public:

  TrustedBridge_DownloadFromExt_args() : username(), filename() {
  }

  virtual ~TrustedBridge_DownloadFromExt_args() throw() {}

  std::string username;
  std::string filename;

  _TrustedBridge_DownloadFromExt_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  void __set_filename(const std::string& val) {
    filename = val;
  }

  bool operator == (const TrustedBridge_DownloadFromExt_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(filename == rhs.filename))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_DownloadFromExt_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_DownloadFromExt_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_DownloadFromExt_pargs {
 public:


  virtual ~TrustedBridge_DownloadFromExt_pargs() throw() {}

  const std::string* username;
  const std::string* filename;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_DownloadFromExt_result__isset {
  _TrustedBridge_DownloadFromExt_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_DownloadFromExt_result__isset;

class TrustedBridge_DownloadFromExt_result {
 public:

  TrustedBridge_DownloadFromExt_result() {
  }

  virtual ~TrustedBridge_DownloadFromExt_result() throw() {}

  DownloadResponse success;

  _TrustedBridge_DownloadFromExt_result__isset __isset;

  void __set_success(const DownloadResponse& val) {
    success = val;
  }

  bool operator == (const TrustedBridge_DownloadFromExt_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_DownloadFromExt_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_DownloadFromExt_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_DownloadFromExt_presult__isset {
  _TrustedBridge_DownloadFromExt_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_DownloadFromExt_presult__isset;

class TrustedBridge_DownloadFromExt_presult {
 public:


  virtual ~TrustedBridge_DownloadFromExt_presult() throw() {}

  DownloadResponse* success;

  _TrustedBridge_DownloadFromExt_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TrustedBridge_DownloadFromServer_args__isset {
  _TrustedBridge_DownloadFromServer_args__isset() : username(false), filename(false) {}
  bool username;
  bool filename;
} _TrustedBridge_DownloadFromServer_args__isset;

class TrustedBridge_DownloadFromServer_args {
 public:

  TrustedBridge_DownloadFromServer_args() : username(), filename() {
  }

  virtual ~TrustedBridge_DownloadFromServer_args() throw() {}

  std::string username;
  std::string filename;

  _TrustedBridge_DownloadFromServer_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  void __set_filename(const std::string& val) {
    filename = val;
  }

  bool operator == (const TrustedBridge_DownloadFromServer_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(filename == rhs.filename))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_DownloadFromServer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_DownloadFromServer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_DownloadFromServer_pargs {
 public:


  virtual ~TrustedBridge_DownloadFromServer_pargs() throw() {}

  const std::string* username;
  const std::string* filename;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_DownloadFromServer_result__isset {
  _TrustedBridge_DownloadFromServer_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_DownloadFromServer_result__isset;

class TrustedBridge_DownloadFromServer_result {
 public:

  TrustedBridge_DownloadFromServer_result() {
  }

  virtual ~TrustedBridge_DownloadFromServer_result() throw() {}

  DownloadResponse success;

  _TrustedBridge_DownloadFromServer_result__isset __isset;

  void __set_success(const DownloadResponse& val) {
    success = val;
  }

  bool operator == (const TrustedBridge_DownloadFromServer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_DownloadFromServer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_DownloadFromServer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_DownloadFromServer_presult__isset {
  _TrustedBridge_DownloadFromServer_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_DownloadFromServer_presult__isset;

class TrustedBridge_DownloadFromServer_presult {
 public:


  virtual ~TrustedBridge_DownloadFromServer_presult() throw() {}

  DownloadResponse* success;

  _TrustedBridge_DownloadFromServer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TrustedBridge_UploadToExt_args__isset {
  _TrustedBridge_UploadToExt_args__isset() : username(false), filename(false), file(false) {}
  bool username;
  bool filename;
  bool file;
} _TrustedBridge_UploadToExt_args__isset;

class TrustedBridge_UploadToExt_args {
 public:

  TrustedBridge_UploadToExt_args() : username(), filename(), file() {
  }

  virtual ~TrustedBridge_UploadToExt_args() throw() {}

  std::string username;
  std::string filename;
  std::string file;

  _TrustedBridge_UploadToExt_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  void __set_filename(const std::string& val) {
    filename = val;
  }

  void __set_file(const std::string& val) {
    file = val;
  }

  bool operator == (const TrustedBridge_UploadToExt_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(filename == rhs.filename))
      return false;
    if (!(file == rhs.file))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_UploadToExt_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_UploadToExt_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_UploadToExt_pargs {
 public:


  virtual ~TrustedBridge_UploadToExt_pargs() throw() {}

  const std::string* username;
  const std::string* filename;
  const std::string* file;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_UploadToExt_result__isset {
  _TrustedBridge_UploadToExt_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_UploadToExt_result__isset;

class TrustedBridge_UploadToExt_result {
 public:

  TrustedBridge_UploadToExt_result() : success((TBStatus::type)0) {
  }

  virtual ~TrustedBridge_UploadToExt_result() throw() {}

  TBStatus::type success;

  _TrustedBridge_UploadToExt_result__isset __isset;

  void __set_success(const TBStatus::type val) {
    success = val;
  }

  bool operator == (const TrustedBridge_UploadToExt_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_UploadToExt_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_UploadToExt_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_UploadToExt_presult__isset {
  _TrustedBridge_UploadToExt_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_UploadToExt_presult__isset;

class TrustedBridge_UploadToExt_presult {
 public:


  virtual ~TrustedBridge_UploadToExt_presult() throw() {}

  TBStatus::type* success;

  _TrustedBridge_UploadToExt_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TrustedBridge_UploadToServer_args__isset {
  _TrustedBridge_UploadToServer_args__isset() : username(false), filename(false), file(false) {}
  bool username;
  bool filename;
  bool file;
} _TrustedBridge_UploadToServer_args__isset;

class TrustedBridge_UploadToServer_args {
 public:

  TrustedBridge_UploadToServer_args() : username(), filename(), file() {
  }

  virtual ~TrustedBridge_UploadToServer_args() throw() {}

  std::string username;
  std::string filename;
  std::string file;

  _TrustedBridge_UploadToServer_args__isset __isset;

  void __set_username(const std::string& val) {
    username = val;
  }

  void __set_filename(const std::string& val) {
    filename = val;
  }

  void __set_file(const std::string& val) {
    file = val;
  }

  bool operator == (const TrustedBridge_UploadToServer_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(filename == rhs.filename))
      return false;
    if (!(file == rhs.file))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_UploadToServer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_UploadToServer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TrustedBridge_UploadToServer_pargs {
 public:


  virtual ~TrustedBridge_UploadToServer_pargs() throw() {}

  const std::string* username;
  const std::string* filename;
  const std::string* file;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_UploadToServer_result__isset {
  _TrustedBridge_UploadToServer_result__isset() : success(false) {}
  bool success;
} _TrustedBridge_UploadToServer_result__isset;

class TrustedBridge_UploadToServer_result {
 public:

  TrustedBridge_UploadToServer_result() : success((TBStatus::type)0) {
  }

  virtual ~TrustedBridge_UploadToServer_result() throw() {}

  TBStatus::type success;

  _TrustedBridge_UploadToServer_result__isset __isset;

  void __set_success(const TBStatus::type val) {
    success = val;
  }

  bool operator == (const TrustedBridge_UploadToServer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TrustedBridge_UploadToServer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TrustedBridge_UploadToServer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TrustedBridge_UploadToServer_presult__isset {
  _TrustedBridge_UploadToServer_presult__isset() : success(false) {}
  bool success;
} _TrustedBridge_UploadToServer_presult__isset;

class TrustedBridge_UploadToServer_presult {
 public:


  virtual ~TrustedBridge_UploadToServer_presult() throw() {}

  TBStatus::type* success;

  _TrustedBridge_UploadToServer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class TrustedBridgeClient : virtual public TrustedBridgeIf {
 public:
  TrustedBridgeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  TrustedBridgeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  TBStatus::type AddUser(const std::string& username);
  void send_AddUser(const std::string& username);
  TBStatus::type recv_AddUser();
  void GetFileList(GetListResponse& _return, const std::string& username);
  void send_GetFileList(const std::string& username);
  void recv_GetFileList(GetListResponse& _return);
  TBStatus::type Remove(const std::string& username, const std::string& filename);
  void send_Remove(const std::string& username, const std::string& filename);
  TBStatus::type recv_Remove();
  void DownloadFromExt(DownloadResponse& _return, const std::string& username, const std::string& filename);
  void send_DownloadFromExt(const std::string& username, const std::string& filename);
  void recv_DownloadFromExt(DownloadResponse& _return);
  void DownloadFromServer(DownloadResponse& _return, const std::string& username, const std::string& filename);
  void send_DownloadFromServer(const std::string& username, const std::string& filename);
  void recv_DownloadFromServer(DownloadResponse& _return);
  TBStatus::type UploadToExt(const std::string& username, const std::string& filename, const std::string& file);
  void send_UploadToExt(const std::string& username, const std::string& filename, const std::string& file);
  TBStatus::type recv_UploadToExt();
  TBStatus::type UploadToServer(const std::string& username, const std::string& filename, const std::string& file);
  void send_UploadToServer(const std::string& username, const std::string& filename, const std::string& file);
  TBStatus::type recv_UploadToServer();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class TrustedBridgeProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<TrustedBridgeIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TrustedBridgeProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_AddUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetFileList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Remove(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_DownloadFromExt(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_DownloadFromServer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_UploadToExt(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_UploadToServer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TrustedBridgeProcessor(boost::shared_ptr<TrustedBridgeIf> iface) :
    iface_(iface) {
    processMap_["AddUser"] = &TrustedBridgeProcessor::process_AddUser;
    processMap_["GetFileList"] = &TrustedBridgeProcessor::process_GetFileList;
    processMap_["Remove"] = &TrustedBridgeProcessor::process_Remove;
    processMap_["DownloadFromExt"] = &TrustedBridgeProcessor::process_DownloadFromExt;
    processMap_["DownloadFromServer"] = &TrustedBridgeProcessor::process_DownloadFromServer;
    processMap_["UploadToExt"] = &TrustedBridgeProcessor::process_UploadToExt;
    processMap_["UploadToServer"] = &TrustedBridgeProcessor::process_UploadToServer;
  }

  virtual ~TrustedBridgeProcessor() {}
};

class TrustedBridgeProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TrustedBridgeProcessorFactory(const ::boost::shared_ptr< TrustedBridgeIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< TrustedBridgeIfFactory > handlerFactory_;
};

class TrustedBridgeMultiface : virtual public TrustedBridgeIf {
 public:
  TrustedBridgeMultiface(std::vector<boost::shared_ptr<TrustedBridgeIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~TrustedBridgeMultiface() {}
 protected:
  std::vector<boost::shared_ptr<TrustedBridgeIf> > ifaces_;
  TrustedBridgeMultiface() {}
  void add(boost::shared_ptr<TrustedBridgeIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  TBStatus::type AddUser(const std::string& username) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->AddUser(username);
    }
    return ifaces_[i]->AddUser(username);
  }

  void GetFileList(GetListResponse& _return, const std::string& username) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetFileList(_return, username);
    }
    ifaces_[i]->GetFileList(_return, username);
    return;
  }

  TBStatus::type Remove(const std::string& username, const std::string& filename) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Remove(username, filename);
    }
    return ifaces_[i]->Remove(username, filename);
  }

  void DownloadFromExt(DownloadResponse& _return, const std::string& username, const std::string& filename) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->DownloadFromExt(_return, username, filename);
    }
    ifaces_[i]->DownloadFromExt(_return, username, filename);
    return;
  }

  void DownloadFromServer(DownloadResponse& _return, const std::string& username, const std::string& filename) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->DownloadFromServer(_return, username, filename);
    }
    ifaces_[i]->DownloadFromServer(_return, username, filename);
    return;
  }

  TBStatus::type UploadToExt(const std::string& username, const std::string& filename, const std::string& file) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UploadToExt(username, filename, file);
    }
    return ifaces_[i]->UploadToExt(username, filename, file);
  }

  TBStatus::type UploadToServer(const std::string& username, const std::string& filename, const std::string& file) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UploadToServer(username, filename, file);
    }
    return ifaces_[i]->UploadToServer(username, filename, file);
  }

};

} // namespace

#endif
