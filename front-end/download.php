
<?

$filename = $_GET['file'];


$filepath = str_replace('\\', '/', realpath("./download_temp/" . $filename));
$filesize = filesize($filepath);
$filename = substr(strrchr('/'.$filepath, '/'), 1);
$extension = strtolower(substr(strrchr($filepath, '.'), 1));


// use this unless you want to find the mime type based on extension
$mime = array('application/octet-stream');

header('Content-Type: '.$mime);
header('Content-Disposition: attachment; filename="'.$filename.'"');
header('Content-Transfer-Encoding: binary');
header('Content-Length: '.sprintf('%d', $filesize));
header('Expires: 0');

/*
// check for IE only headers
if (isset($_SERVER['HTTP_USER_AGENT']) && (strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE') !== false))) {
  header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
  header('Pragma: public');
} else {
  header('Pragma: no-cache');
}
*/
header('Pragma: no-cache');


$handle = fopen($filepath, 'rb');
fpassthru($handle);
fclose($handle);

?>