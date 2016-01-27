import com.dropbox.client2.exception.DropboxException;
import com.dropbox.client2.exception.DropboxServerException;
import com.dropbox.client2.session.*;
import com.dropbox.client2.DropboxAPI;
import com.dropbox.client2.DropboxAPI.*;
import com.dropbox.client2.jsonextract.*;
import com.dropbox.client2.ProgressListener;

import java.io.IOException;
import java.io.PrintStream;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Dropbox{

	//public enum Action { UPLOAD, DOWNLOAD, STATUS };
	public enum Response { OK, IO_FAILURE, DROPBOX_FAILURE, FILE_NOTEXIST };

	final static private String UPLOAD_DIR = "./upload/";
	final static private String DOWNLOAD_DIR = "./download/";

   	final static private String APP_KEY = "xzr8dz43fp0nlly";
	final static private String APP_SECRET = "bo84gfy370e8siy";
	final static private Session.AccessType ACCESS_TYPE = Session.AccessType.APP_FOLDER;

	final static private AppKeyPair appKey = new AppKeyPair(APP_KEY, APP_SECRET);
	//final static private AccessTokenPair access = new AccessTokenPair("sldeu2jzxv2v8sa", "8lk5tjgmwgc9o9w");
	// Test account: q07wm2q8ckfvbo8 u2l544wj6i1va0m

	// Usage: UploadDropbox filename token1 token2
    public static void main(String []args) throws DropboxException{
       	//System.out.println("Dropbox");

       	if (args.length != 4) {
            printUsage(System.out);
            return;
        }
        
        String action   = args[0];
        String filename = args[1];
        String token1   = args[2];
		String token2   = args[3];

		AccessTokenPair access = new AccessTokenPair(token1, token2);

		WebAuthSession session = new WebAuthSession(appKey, ACCESS_TYPE, access);
		DropboxAPI<?> mDBApi = new DropboxAPI<WebAuthSession>(session);
		
		if (action.equals("upload")){
			try	{
				File file = new File(UPLOAD_DIR + filename);
				FileInputStream inputStream = new FileInputStream(file);
				Entry response = mDBApi.putFile("/"+filename, inputStream, file.length(), null, null);
				/*
				Entry response = mDBApi.putFile("/"+filename, inputStream, file.length(), null, 
					new ProgressListener() {

	            	@Override
	            	public void onProgress(long bytes, long total) {
	                // TODO Auto-generated method stub
	                	System.out.println(String.valueOf(bytes) + "/" + String.valueOf(total));
	            	}
	        	});
	        	*/
				System.out.print(Response.OK.ordinal());
			}
			catch(IOException e) {
				System.out.print(Response.IO_FAILURE.ordinal());
			}
			catch(DropboxException e){
				System.out.print(Response.DROPBOX_FAILURE.ordinal());
			}
			finally{
				System.exit(0);
			}
		}
		else if (action.equals("download")){
			try	{
				File file = new File(DOWNLOAD_DIR + filename);
				FileOutputStream outputStream = new FileOutputStream(file);
				DropboxFileInfo info = mDBApi.getFile("/"+filename, null, outputStream, null);

			/*
				Entry response = mDBApi.putFile("/"+filename, inputStream, file.length(), null, 
					new ProgressListener() {

	            	@Override
	            	public void onProgress(long bytes, long total) {
	                // TODO Auto-generated method stub
	                	System.out.println(String.valueOf(bytes) + "/" + String.valueOf(total));
	            	}
	        	});
	        	*/
				System.out.print(Response.OK.ordinal());
			}
			catch(IOException e) {
				System.out.print(Response.IO_FAILURE.ordinal());
			}
			catch(DropboxServerException e){
				if (e.error == DropboxServerException._404_NOT_FOUND){
					System.out.print(Response.FILE_NOTEXIST.ordinal());
				} else {
					System.out.print(Response.DROPBOX_FAILURE.ordinal());
				}

			}
			catch(DropboxException e){
				System.out.print(Response.DROPBOX_FAILURE.ordinal());
			}
			finally{
				System.exit(0);
			}

		}
		else if(action.equals("status")){
			try{
				Entry existingEntry = mDBApi.metadata("/"+filename, 1, null, false, null);
				//System.out.println(existingEntry);
				
				if (existingEntry.isDeleted){
					System.out.print(Response.FILE_NOTEXIST.ordinal());
				}
				else {
					System.out.print(Response.OK.ordinal());
				}
			}
			catch(DropboxException e){
				System.out.print(Response.FILE_NOTEXIST.ordinal());
			}
			finally{
				System.exit(0);
			}
		}
		
    }

    private static void printUsage(PrintStream out)
    {
        out.println("Usage:");
        out.println("    ./run Dropbox <action> <filename> <token1> <token2>");
    }
} 
