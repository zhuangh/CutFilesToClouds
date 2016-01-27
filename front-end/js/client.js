

console.log("load testServer");

function testServer() {
    try {
        console.log("testServer");
        var transport = new Thrift.Transport("http://sysnet91.sysnet.ucsd.edu:12345");
        var protocol  = new Thrift.Protocol(transport);
        var client = new TrustedBridgeClient(protocol);

        client.Remove("filename");
        client.GetFileList("earlyshen");

    } catch(e) {
        console.log(e.message);
    }
}