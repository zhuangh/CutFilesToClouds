#include "./cryptopp/sha.h"
#include "./cryptopp/hex.h"
#include "./cryptopp/base64.h"
#include "./cryptopp/files.h"
#include <string>
#include <iostream>

#if 1
void DumpHash_SingleStep(CryptoPP::HashTransformation& hash,
                         char const* szModuleName,
                         std::string const& strData){

    using namespace std;
    using namespace CryptoPP;

    SecByteBlock sbbDigest(hash.DigestSize());

    hash.CalculateDigest(
        sbbDigest.begin(),
        (byte const*) strData.data(),
        strData.size());

    cout << szModuleName << " SS: ";

    HexEncoder encoder(new FileSink(cout));
    encoder.Put(sbbDigest.begin(), sbbDigest.size());
    cout << endl;        
}
#endif

int main(){

    CryptoPP::SHA256 hash;
    byte digest[CryptoPP::SHA256::DIGESTSIZE];

    std::string message = "UCSD";
    hash.CalculateDigest(digest, (byte* const)message.c_str(), message.length());

    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach(new CryptoPP::StringSink(output));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    std::cout<<output<<std::endl;
   return 0;
}

