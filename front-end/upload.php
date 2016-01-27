<?php
namespace TrustedBridge;

error_reporting(E_ALL);


$filename = $_FILES["files"]["name"][0];
$server_ip = $_POST["server_ip"];
$server_port = intval($_POST["server_port"]);

if ($server_ip == "") $server_ip = "sysnet91.sysnet.ucsd.edu";
if ($server_port == 0) $server_port = 10030;

//echo $filename; 

$extension = end(explode(".", $filename));

echo "Upload: " . $filename . "<br>";
echo "Type: " . $_FILES["files"]["type"][0] . "<br>";
echo "Size: " . ($_FILES["files"]["size"][0] / 1024) . " kB<br>";
echo "Temp file: " . $_FILES["files"]["tmp_name"][0] . "<br>";

if (file_exists("upload/" . $filename)){
  echo $filename . " already exists. " . "<br>";
}
else{
  move_uploaded_file($_FILES["files"]["tmp_name"][0], "../upload/" . $filename);
  echo "Stored in: " . "upload/" . $filename . "<br>";
}

require_once 'Thrift/ClassLoader/ThriftClassLoader.php';
require_once 'TrustedBridge/Types.php';
require_once 'TrustedBridge/TrustedBridge.php';

use Thrift\ClassLoader\ThriftClassLoader;

$GEN_DIR = realpath(dirname(__FILE__).'/..').'/gen-php';

$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', '.');
$loader->registerDefinition('TrustedBridge', '.');
$loader->register();

use Thrift\Protocol\TBinaryProtocol;
use Thrift\Transport\TSocket;
use Thrift\Transport\THttpClient;
use Thrift\Transport\TPhpStream;
use Thrift\Transport\TBufferedTransport;
use Thrift\Exception\TException;

try {
  echo "Connecting " . $server_ip . ":" . $server_port . "<br>";
  $socket = new TSocket($server_ip, $server_port);
  $transport = new TBufferedTransport($socket, 1024, 1024);
  //$transport = new TBufferedTransport(new TPhpStream(TPhpStream::MODE_R | TPhpStream::MODE_W));;
  $protocol = new TBinaryProtocol($transport);
  $client = new \TrustedBridge\TrustedBridgeClient($protocol);

  $transport->open();

  //$file = fopen("login.html", "rb");
  $file = file_get_contents("../upload/".$filename, FILE_USE_INCLUDE_PATH);

  $response = $client->UploadToServer($filename,"test_user",$file);

  print_r($response);

  $transport->close();

} catch (TException $tx) {
  print 'TException: '.$tx->getMessage()."\n";
}

?>
