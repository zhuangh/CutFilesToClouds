<?php

namespace TrustedBridge;

error_reporting(E_ALL | E_STRICT);

define("DEBUG", false);

define("USER", "test");
define("PATH", "/classes/cse223b/sp13/eshen/cse-223b-projcet/front-end/");
define("DIR_UPLOAD", PATH . "upload_temp/");
define("DIR_DOWNLOAD", PATH . "download_temp/");
define("HTTP_URL", "http://sysnet91.sysnet.ucsd.edu/TrustedBridge/");

//print_r($_GET);

if (!isset($_GET['action'])){
  error("No such action!");
}
$action = $_GET['action'];

if ($action == "check"){
  if (is_file(DIR_DOWNLOAD . $_GET['filename'])){
    $ready['ready'] = true;
  }
  else{
    $ready['ready'] = false;
  }
  echo json_encode($ready);
  die();
}

function error($msg){
  $error['error'] = $msg;
  echo json_encode($error);
  //exit();
}

function upload($tbClient, $username, $filename){

  
  if (file_exists(DIR_UPLOAD . $filename)){
    //error($filename . " already exists in upload_temp");
    //return;
  }
  else{
    move_uploaded_file($_FILES["files"]["tmp_name"][0], DIR_UPLOAD . $filename);
  }
  

  $file = "";
  $rp = $tbClient->UploadToServer($username, $filename, $file);
  switch ($rp) {
    case TBStatus::OK:
      // Remove local temp file
      //unlink(DIR_UPLOAD . $filename);
      break;
    default:
      error("Upload failed.");
      break;
  }
  
}

function download($tbClient, $username, $filename){
  $rp = new \TrustedBridge\DownloadResponse();
  $rp = $tbClient->DownloadFromServer($username, $filename);
  switch ($rp->status) {
    case TBStatus::OK:
      $file['link'] = HTTP_URL . "download.php?file=" . $filename;
      break;
    default:
      $file['link'] = HTTP_URL . "download.php?file=1.pdf";
      //error("Download failed.");
      break;
  }
/*
  if (!file_exists(DIR_DOWNLOAD . $filename)){
    error($filename . " not exists in download_temp ");
  }
*/
  echo json_encode($file);
  
}

function getlist($tbClient, $username){
  global $DEBUG;

  $rp = new \TrustedBridge\GetListResponse();
  $rp = $tbClient->GetFileList($username);
  switch ($rp->status) {
    case TBStatus::OK:
      $files['files'] = $rp->values;
      echo json_encode($files);
      break;
    case TBStatus::EFILENOTFOUND:
      $files['files'] = "";
      echo json_encode($files);
      break;
    default:
      error("getlist unexpected response: {$rp->status}");
      break;
  };
  
}


$server_ip = isset($_GET['server_ip']) ? $_GET['server_ip'] : "sysnet91.sysnet.ucsd.edu";
$server_port = isset($_GET['server_port']) ? intval($_GET['server_port']) : 10030;

require_once 'Thrift/ClassLoader/ThriftClassLoader.php';
require_once 'TrustedBridge/Types.php';
require_once 'TrustedBridge/TrustedBridge.php';

use Thrift\ClassLoader\ThriftClassLoader;

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

//echo "Connecting " . $server_ip . ":" . $server_port . "<br>";

try {
  if (DEBUG) echo "Connecting " . $server_ip . ":" . $server_port . "<br>";
  
  $socket = new TSocket($server_ip, $server_port);
  $transport = new TBufferedTransport($socket, 1024, 1024);
  //$transport = new TBufferedTransport(new TPhpStream(TPhpStream::MODE_R | TPhpStream::MODE_W));;
  $protocol = new TBinaryProtocol($transport);

  $client = new \TrustedBridge\TrustedBridgeClient($protocol);

  $transport->open();

  switch ($action) {
    case 'getlist':
      getlist($client, USER);
      break;
    case 'download':
      download($client, USER, $_GET['filename']);
      break;
    case 'upload':
      upload($client, USER, $_FILES["files"]["name"][0]);
      break;
    default:
      error("Action not yet defined");
      break;
  }
  $transport->close();

} catch (TException $tx) {
  //echo tx;
  //error('TException: '.$tx->getMessage());
  $transport->close();
}


?>