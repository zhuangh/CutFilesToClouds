/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TrustedBridge_TYPES_H
#define TrustedBridge_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace TrustedBridge {

struct TBStatus {
  enum type {
    OK = 1,
    EFILENOTFOUND = 2,
    EFILEEXISTS = 3,
    INTERNAL_FAILURE = 4,
    NOT_IMPLEMENTED = 5
  };
};

extern const std::map<int, const char*> _TBStatus_VALUES_TO_NAMES;

typedef struct _GetListResponse__isset {
  _GetListResponse__isset() : status(false), values(false) {}
  bool status;
  bool values;
} _GetListResponse__isset;

class GetListResponse {
 public:

  static const char* ascii_fingerprint; // = "A22BE3E84688C9DA4E00CC902B4EE818";
  static const uint8_t binary_fingerprint[16]; // = {0xA2,0x2B,0xE3,0xE8,0x46,0x88,0xC9,0xDA,0x4E,0x00,0xCC,0x90,0x2B,0x4E,0xE8,0x18};

  GetListResponse() : status((TBStatus::type)0) {
  }

  virtual ~GetListResponse() throw() {}

  TBStatus::type status;
  std::vector<std::string>  values;

  _GetListResponse__isset __isset;

  void __set_status(const TBStatus::type val) {
    status = val;
  }

  void __set_values(const std::vector<std::string> & val) {
    values = val;
  }

  bool operator == (const GetListResponse & rhs) const
  {
    if (!(status == rhs.status))
      return false;
    if (!(values == rhs.values))
      return false;
    return true;
  }
  bool operator != (const GetListResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GetListResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(GetListResponse &a, GetListResponse &b);

typedef struct _DownloadResponse__isset {
  _DownloadResponse__isset() : status(false), filename(false), file(false) {}
  bool status;
  bool filename;
  bool file;
} _DownloadResponse__isset;

class DownloadResponse {
 public:

  static const char* ascii_fingerprint; // = "38C252E94E93B69D04EB3A6EE2F9EDFB";
  static const uint8_t binary_fingerprint[16]; // = {0x38,0xC2,0x52,0xE9,0x4E,0x93,0xB6,0x9D,0x04,0xEB,0x3A,0x6E,0xE2,0xF9,0xED,0xFB};

  DownloadResponse() : status((TBStatus::type)0), filename(), file() {
  }

  virtual ~DownloadResponse() throw() {}

  TBStatus::type status;
  std::string filename;
  std::string file;

  _DownloadResponse__isset __isset;

  void __set_status(const TBStatus::type val) {
    status = val;
  }

  void __set_filename(const std::string& val) {
    filename = val;
  }

  void __set_file(const std::string& val) {
    file = val;
  }

  bool operator == (const DownloadResponse & rhs) const
  {
    if (!(status == rhs.status))
      return false;
    if (!(filename == rhs.filename))
      return false;
    if (!(file == rhs.file))
      return false;
    return true;
  }
  bool operator != (const DownloadResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DownloadResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(DownloadResponse &a, DownloadResponse &b);

} // namespace

#endif